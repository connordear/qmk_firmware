# Updating my Cantor firmware

This guide is for the Cantor with Blackpill STM32F401 controllers and the
`connordear` keymap, using Arch Linux in WSL2.

## Build after editing the keymap

The firmware files to edit are in
[`keyboards/cantor/keymaps/connordear/`](keyboards/cantor/keymaps/connordear/).

In WSL:

```sh
cd ~/qmk_firmware
qmk compile -kb cantor -km connordear
```

This creates `cantor_connordear.bin` in the repository root. This keymap was
successfully built on October 20, 2026, with QMK CLI 1.2.0 and ARM GCC 16.2.0.

## Flash each half

1. Unplug USB before disconnecting the cable between the halves. Flash one half
   at a time, with that half connected directly to the computer by USB.
2. Enter the bootloader using either method:
   - Hold the top left key on the left half (or top right key on the right half)
     while plugging in USB, then release it.
   - On the controller, hold **BOOT0**, press and release **NRST**, then release
     **BOOT0**. This also works if the current firmware cannot boot.
3. Attach the **bootloader device** to WSL using the PowerShell instructions
   below. Enter the bootloader before attaching it because its USB identity
   changes when switching from keyboard mode.
4. In WSL, check that the bootloader is detected, then flash:

   ```sh
   cd ~/qmk_firmware
   dfu-util -l
   qmk flash -kb cantor -km connordear
   ```

   `dfu-util -l` should list the STM32 DFU device, typically `0483:df11`.
   `qmk flash` rebuilds the keymap before writing it.
5. Wait for flashing to finish successfully, unplug USB, then repeat for the
   other half with the same keymap. After both halves are flashed, reconnect the
   cable between them while USB is unplugged, then reconnect USB.

## Windows USB passthrough to WSL

Keep a WSL terminal open. If `usbipd` is not installed, run in PowerShell:

```powershell
winget install --interactive --exact dorssel.usbipd-win
```

Open a new **Administrator PowerShell** window. With the half already in its
bootloader, list devices:

```powershell
usbipd list
```

Find the STM32 bootloader and use its bus ID in place of `BUSID` below (for
example, `4-4`). Do this for each half; their bus IDs can differ.

```powershell
usbipd bind --busid BUSID
usbipd attach --wsl --busid BUSID
```

Binding requires administrator privileges and normally only needs to be done
once per device. Attaching can be run without administrator privileges. Repeat
the attachment whenever the device disconnects, including after a bootloader
transition. While attached, the device is controlled by WSL.

If necessary, return it to Windows after flashing:

```powershell
usbipd detach --busid BUSID
```

## Setting up a new Arch WSL environment

The tools and repository were set up on October 20, 2026. For a new environment:

```sh
sudo pacman -Syu --needed qmk dfu-util usbutils arm-none-eabi-gcc arm-none-eabi-binutils arm-none-eabi-newlib python-appdirs
git clone --recurse-submodules https://github.com/connordear/qmk_firmware.git ~/qmk_firmware
cd ~/qmk_firmware
qmk config user.qmk_home="$HOME/qmk_firmware"
qmk doctor
```

For an existing checkout with missing submodules:

```sh
git submodule update --init --recursive
```

## Troubleshooting

- **No DFU device / waiting for a bootloader:** enter the bootloader first,
  check `usbipd list` in Windows, attach that device to WSL, then retry
  `dfu-util -l`. Use a USB cable that supports data.
- **Permission denied opening the DFU device:** install QMK's USB permission
  rules from the repository root:

  ```sh
  sudo install -Dm644 util/udev/50-qmk.rules /etc/udev/rules.d/50-qmk.rules
  sudo udevadm control --reload-rules
  ```

  Then detach and reattach the device. The rules are already installed on the
  current machine, but reloading failed in the setup session because no udev
  daemon was running. If reloading also fails in your normal WSL terminal, ensure
  udev is running before relying on these rules. To confirm a permission issue,
  the already-built binary can be flashed directly with:

  ```sh
  sudo dfu-util -a 0 -d 0483:df11 -s 0x08000000:leave -D cantor_connordear.bin
  ```

  Use this command only for this STM32F401 Cantor and after a successful build.
- **AVR compiler version warning in `qmk doctor`:** the Cantor uses the ARM
  compiler. An AVR-only warning does not prevent this keymap from building.

References: [Cantor bootloader instructions](keyboards/cantor/readme.md#bootloader),
[QMK flashing guide](https://docs.qmk.fm/flashing), and
[Microsoft's WSL USB guide](https://learn.microsoft.com/en-us/windows/wsl/connect-usb).
