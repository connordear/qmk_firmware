#include QMK_KEYBOARD_H

enum layer_names {
    _DEFAULT = 0,
    _MAC,
    _ENTHIUM,
    _QWERTY,
    _NUMBER,
    _SYMBOL,
    _NAVIGATION,
    _MOUSE,
    _MEDIA,
    _FUNCTION,
};


// LINUX / WINDOWS MODS (Default)
#define L_GUI_A LGUI_T(KC_A)  // Pinky: Super/Win (Window Mgr)
#define L_ALT_R LALT_T(KC_R)  // Ring: Alt
#define L_CTL_S LCTL_T(KC_S)  // Middle: Ctrl (Neovim Heavy Lifting!)
#define L_SFT_T LSFT_T(KC_T)  // Index: Shift (Strongest Finger)

#define R_SFT_N RSFT_T(KC_N)
#define R_CTL_E RCTL_T(KC_E)
#define R_ALT_I LALT_T(KC_I)
#define R_GUI_O RGUI_T(KC_O)

// MAC MODS
#define M_CTL_A LCTL_T(KC_A)  // Pinky: Ctrl (Terminal SIGINT)
#define M_ALT_R LALT_T(KC_R)  // Ring: Option
#define M_GUI_S LGUI_T(KC_S)  // Middle: Cmd (Copy/Paste)
#define M_SFT_T LSFT_T(KC_T)  // Index: Shift

#define M_SFT_N RSFT_T(KC_N)
#define M_GUI_E RGUI_T(KC_E)
#define M_ALT_I LALT_T(KC_I)
#define M_CTL_O RCTL_T(KC_O)


// Left-hand home row mods (old)
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HYPR_D HYPR_T(KC_D)

// Right-hand home row mods (old)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)
#define HYPR_H HYPR_T(KC_H)

#define ESC_MSE LT(_MOUSE, KC_ESC)
#define SPC_NAV LT(_NAVIGATION, KC_SPC)
#define TAB_NUM LT(_NUMBER, KC_TAB)

#define ENT_MED LT(_MEDIA, KC_ENT)
#define BSP_SYM LT(_SYMBOL, KC_BSPC)
#define DEL_FUN LT(_FUNCTION, KC_DEL)


// Enthium Layer Thumbs
// Left Hand: w C(Ctrl) I(Alt) A(Gui) E(Sft) ;
#define ENTH_C LCTL_T(KC_C)
#define ENTH_I LALT_T(KC_I)
#define ENTH_A LGUI_T(KC_A)
#define ENTH_E LSFT_T(KC_E)

// Right Hand: k H(Sft) T(Gui) N(Alt) S(Ctrl) f
#define ENTH_H RSFT_T(KC_H)
#define ENTH_T RGUI_T(KC_T)
#define ENTH_N LALT_T(KC_N)
#define ENTH_S RCTL_T(KC_S)

#define R_SYM   LT(_SYMBOL, KC_R)
#define BSP_FUN LT(_FUNCTION, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  COLEMAK-DH Layer (with home-row mod taps: GACS | SCAG)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │HYP│ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │HYP│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Esc├───┐           ┌───┤Del│
      *               └───┤Spc├───┐   ┌───┤Bsp├───┘
      *                 # └───┤Tab│   │Ent├───┘ F
      *                     N └───┘   └───┘ $
      *                         M       ⏵
      */
    [_DEFAULT] = LAYOUT_split_3x6_3(
        _______,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, _______,
        _______, L_GUI_A, L_ALT_R, L_CTL_S, L_SFT_T, KC_G,                            KC_M,    R_SFT_N, R_CTL_E, R_ALT_I, R_GUI_O, _______,
        _______, KC_Z,    KC_X,    KC_C,    HYPR_D,  KC_V,                            KC_K,    HYPR_H,  KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            ESC_MSE,  SPC_NAV, TAB_NUM,      ENT_MED, BSP_SYM, DEL_FUN
    ),

    // Mods: Ctrl | Alt | Gui | Shift
    [_MAC] = LAYOUT_split_3x6_3(
        _______,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, _______,
        _______, M_CTL_A, M_ALT_R, M_GUI_S, M_SFT_T, KC_G,                            KC_M,    M_SFT_N, M_GUI_E, M_ALT_I, M_CTL_O, _______,
        _______, KC_Z,    KC_X,    KC_C,    HYPR_D,  KC_V,                            KC_K,    HYPR_H,  KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            ESC_MSE,  SPC_NAV, TAB_NUM,      ENT_MED, BSP_SYM, DEL_FUN
    ),


    /* ENTHIUM LAYER
     * Layout:
     * L:  _  z  y  o  u  =      |   R:  q  l  d  p  x  _
     * L:  w  c  i  a  e  ;      |   R:  k  h  t  n  s  f
     * L:  _  '  -  ,  .  /      |   R:  j  m  g  b  v  _
     * Thumbs: R on Right Middle, Backspace on Right Outer
     */
    [_ENTHIUM] = LAYOUT_split_3x6_3(
        _______,  KC_Z,    KC_Y,    KC_O,    KC_U,    KC_EQL,                          KC_Q,    KC_L,    KC_D,    KC_P,    KC_X,    _______,
        KC_W,    ENTH_C,  ENTH_I,  ENTH_A,  ENTH_E,  KC_SCLN,                          KC_K,    ENTH_H,  ENTH_T,  ENTH_N,  ENTH_S,  KC_F,
        _______, KC_QUOT, KC_MINS, KC_COMM, KC_DOT,  KC_SLSH,                          KC_J,    KC_M,    KC_G,    KC_B,    KC_V,    _______,
                                            ESC_MSE,  SPC_NAV, TAB_NUM,            ENT_MED, R_SYM,   BSP_FUN
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
     [_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TG(_DEFAULT),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LGUI, KC_SPC, KC_BSPC,          KC_ENT, KC_SPC, LT(_FUNCTION, KC_RALT)
         ),



    /* NUMBER LAYER (TODO: can remove symbols)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │ 7 │ 8 │ 9 │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │ 4 │ 5 │ 6 │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │ 1 │ 2 │ 3 │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤ 0 ├───┘
      *                   └───┤   │   │ . ├───┘
      *                       └───┘   └───┘
      */

    [_NUMBER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            _______,     KC_7,    KC_8,    KC_9, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______,     KC_4,    KC_5,    KC_6, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______,     KC_1,    KC_2,    KC_3, _______, _______,
                                            _______, _______, _______,           KC_DOT,    KC_0,  _______
    ),





     /* SYMBOL LAYER (yoink & twisted from https://getreuer.info/posts/keyboards/symbol-layer/index.html)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ ` │ < │ > │ " │ . │       │ & │ ; │ [ │ ] │ % │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ! │ - │ + │ = │ # │       │ | │ : │ ( │ ) │ ? │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ^ │ / │ * │ \ │ _ │       │ ~ │ $ │ { │ } │ @ │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */

    [_SYMBOL] = LAYOUT_split_3x6_3(
        _______,  KC_GRV, KC_LABK,  KC_RABK, KC_DQT,   KC_DOT,                            KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC, _______,
        _______, KC_EXLM, KC_MINUS, KC_PLUS, KC_EQL,  KC_HASH,                            KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
        _______, KC_CIRC, KC_SLSH,  KC_ASTR, KC_BSLS, KC_UNDS,                            KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR,   KC_AT, _______,
                                             _______, _______, _______,          _______, _______, _______
    ),






    /* NAVIGATION LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │RDO│PST│CPY│CUT│UDO│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │ ⯇ │ ⯆ │ ⯅ │ ⯈ │CAP│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │INS│HOM│PGD│PGU│END│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
        _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______,
        _______, _______, _______, _______, _______, _______,                             KC_INS,  KC_HOME,KC_PGDN, KC_PGUP,  KC_END, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),






    // do mouse next so it falls on top of nav to keep copy/paste
    //
     /* MOUSE LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │SP2│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │C_L│C_D│C_U│C_R│BCK│SP1│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │S_L│S_D│S_U│S_R│FWD│SP0│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤ M │
      *               └───┤   ├───┐   ┌───┤ L ├───┘
      *                   └───┤   │   │ R ├───┘
      *                       └───┘   └───┘
      */
    [_MOUSE] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            KC_BTN2, _______, _______, _______, _______, KC_ACL2,
        _______, _______, _______, _______, _______, _______,                            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WBAK, KC_ACL1,
        _______, _______, _______, _______, _______, _______,                            KC_WH_R, KC_WH_D, KC_WH_U, KC_WH_L, KC_WFWD, KC_ACL0,
                                            _______, _______, _______,          KC_BTN4, KC_BTN1, KC_BTN5
    ),






     /* MEDIA LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │BDN│BUP│   │       │   │VDN│VUP│MUT│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤NXT│
      *               └───┤   ├───┐   ┌───┤BK ├───┘
      *                   └───┤   │   │PLY├───┘
      *                       └───┘   └───┘
      */
    [_MEDIA] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BRID, KC_BRIU, _______,                            KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
                                            _______, _______, _______,          KC_MPLY, KC_MPRV, KC_MNXT
    ),





     /* FUNCTION LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │BTL│   │F_7│F_8│F_9│   │       │   │   │   │   │   │BTL│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │F_4│F_5│F_6│   │       │   │   │   │   │   │QWR│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │F_1│F_2│F_3│   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │F10├───┐           ┌───┤   │
      *               └───┤F11├───┐   ┌───┤   ├───┘
      *                   └───┤F12│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_FUNCTION] = LAYOUT_split_3x6_3(
        QK_BOOT, _______,   KC_F7,  KC_F8,   KC_F9, _______,                            _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______,   KC_F4,  KC_F5,   KC_F6, _______,                            DF(_MAC), DF(_DEFAULT), DF(_ENTHIUM), _______, _______, TG(_QWERTY),
        _______, _______,   KC_F1,  KC_F2,   KC_F3, _______,                            _______, _______, _______, _______, _______, _______,
                                            KC_F10,  KC_F11, KC_F12,          _______, _______, _______
    ),
};


     /* ______ LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │BTL│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
//    [_] = LAYOUT_split_3x6_3(
//        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//                                            _______, _______, _______,          _______, _______, _______
//    )
//
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
   // [0] = LAYOUT_split_3x6_3(
   //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   //     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   //     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
   //                                         KC_LGUI, KC_SPC, KC_BSPC,          KC_ENT, KC_SPC, KC_RALT
   //     ),
