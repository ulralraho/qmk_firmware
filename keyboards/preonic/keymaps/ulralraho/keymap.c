/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

#include "ulralraho.h"
#include "ulralraho_vim.h"
#include "ulralraho_ks3to2.h"

// extern keymap_config_t keymap_config;

enum
{
  CT_COMM_QUOT,
  CT_MINS_EQL,
  CT_UNDS_PLUS,
  CT_QUOT_BSLS,
  CT_DQUT_PIPE,
  CT_LPRN_RPRN,
  CT_LBRC_RBRC,
  CT_LCBR_RCBR,
  CT_LCBR_LBRC,
  CT_RCBR_RBRC,
  CT_SCLN_QUOT,
  CT_COLN_DQUO,
};

qk_tap_dance_action_t tap_dance_actions[] =
{
  [CT_COMM_QUOT]   = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_QUOT),
  [CT_MINS_EQL]    = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [CT_UNDS_PLUS]   = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_PLUS),
  [CT_QUOT_BSLS]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_BSLS),
  [CT_DQUT_PIPE]   = ACTION_TAP_DANCE_DOUBLE(KC_DQUO, KC_PIPE),
  [CT_LPRN_RPRN]   = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [CT_LBRC_RBRC]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [CT_LCBR_RCBR]   = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [CT_LCBR_LBRC]   = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
  [CT_RCBR_RBRC]   = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC),
  [CT_SCLN_QUOT]   = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [CT_COLN_DQUO]   = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_DQUO),
};

#define TD_CMQT   TD(CT_COMM_QUOT)
#define TD_MNEQ   TD(CT_MINS_EQL)
#define TD_UNPL   TD(CT_UNDS_PLUS)
#define TD_QTBL   TD(CT_QUOT_BSLS)
#define TD_DQPP   TD(CT_DQUT_PIPE)
#define TD_PRN    TD(CT_LPRN_RPRN)
#define TD_BRC    TD(CT_LBRC_RBRC)
#define TD_CBR    TD(CT_LCBR_RCBR)
#define TD_LCBR   TD(CT_LCBR_LBRC)
#define TD_RCBR   TD(CT_RCBR_RBRC)
#define TD_SCQT   TD(CT_SCLN_QUOT)
#define TD_CNDQ   TD(CT_COLN_DQUO)

#if forPREONIC == yes
    #define LAYOUT_grid     LAYOUT_preonic_grid
#else
    #define LAYOUT_grid     LAYOUT_planck_grid
#endif

const u16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
/* LayerQWERTY
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |= + - _ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |     TAB|MOU q Q |    w W |    e E |    r R |    t T |    y Y |    u U |    i I |    o O |    p P |     BSP|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |LSF  ESC|    a A |    s S |    d D |    f F |    g G |    h H |    j J |    k K |    l L |    ; : |RSF  ENT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영|    z Z |    x X |    c C |    v V |    b B |    n N |    m M |    , < |    . > |    / ? |    ' " |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |FN      |GUI     |Alt     |CTL     |SYM  SPC|FN   SPC|FN   SPC|EDI  SPC|  Left  |  Down  |   UP   | Right  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerQWERTY] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MNEQ,
#endif
    KC_TAB,  MOU_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LS_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RS_ENT,
    NUM_HAN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    FUNCTN,  KC_LGUI, KC_LALT, KC_LCTL, SYM_SPC, FNC_SPC, FNC_SPC, EDI_SPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

/* Korean Sin 3 beol to 2 beol
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |= + - _ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |     TAB|    q Q |    w W |    e E |    r R |    t T |    y Y |    u U |    i I |    o O |    p P |     BSP|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |LSF  ESC|    a A |    s S |    d D |    f F |    g G |    h H |    j J |    k K |    l L |    ; : |RSF  ENT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영|    z Z |    x X |    c C |    v V |    b B |    n N |    m M |    , < |    . > |    / ? |    ' " |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |FN      |GUI     |Alt     |CTL     |NUM     |FN   SPC|FN   SPC|EDI  SPC|  Left  |  Down  |   UP   | Right  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerKS3to2] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_TRNS,
#endif
    KC_TAB,  KS3_Q,   KS3_W,   KS3_E,   KS3_R,   KS3_T,   KS3_Y,   KS3_U,   KS3_I,   KS3_O,   KS3_P,    KS3_BSPC,
    KS3_ESC, KS3_A,   KS3_S,   KS3_D,   KS3_F,   KS3_G,   KS3_H,   KS3_J,   KS3_K,   KS3_L,   KS3_SCLN, KS3_ENT,
    KC_TRNS, KS3_Z,   KS3_X,   KS3_C,   KS3_V,   KS3_B,   KS3_N,   KS3_M,   KS3_COMM,KC_DOT,  KS3_SLSH, KS3_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KS3_NSPC,KS3_FSPC,KS3_FSPC,KS3_ESPC,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
  ),

/* LayerEDITOR
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |= + - _ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |     TAB|   vESC |    TAB |        |        |   PGUP |   vY   |  UNDO  |  vHOME |   vV   |   vP   |  vBSPC |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   vESC |   LSFT |  vBSPC |        |        |   PGDN |   vH   |   vJ   |   vK   |   vL   |   LSFT |RSF  ENT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영|  CTL+Z |  CTL+X |  CTL+C |  CTL+V |  CTL+Y |   vD   |   vEND |   vB   |   vW   |  vDEL  | Insert |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |FN      |GUI     |Alt     |CTL     |NUM  SPC|FN   SPC|FN   SPC|EDI  SPC|        | MACWIN | REDO_Y |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerEDITOR] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, TD_MNEQ,
#endif
    KC_TAB,  vimESC,  KC_TAB,  KC_NO,   KC_NO,   KC_PGUP, vimY,    UNDO,    vimHOME, vimV,    vimP,    vimBSPC,
    vimESC,  KC_LSFT, vimBSPC, KC_NO,   KC_NO,   KC_PGDN, vimH,    vimJ,    vimK,    vimL,    KC_LSFT, RS_ENT,
    KC_TRNS, CTL_Z,   CTL_X,   CTL_C,   CTL_V,   CTL_Y,   vimD,    vimEND,  vimB,    vimW,    vimDEL,  KC_INS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   swMacWin,swREDO_Y,KC_NO
  ),

/* LayerSYMBOL
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |= + - _ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |    ` ~ |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    [ { |    ] } |     BSP|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |LSF  ESC|   LSFT | NUMPAD |    {   |    }   |    |   |    _   |    (   |    )   |    - _ |    :   |RSF  ENT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영|        |    ~   |    <   |    >   |        |    \ | |    = + |    , < |    . > |    / ? |     "  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |FN      |GUI     |Alt     |CTL     |NUM  SPC|FN   SPC|FN   SPC|EDI  SPC|  Home  |  PGDN  |  PGUP  |  End   |
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerSYMBOL] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MNEQ,
#endif
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_TRNS, KC_LSFT, NUMPAD,  KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, RS_ENT,
    KC_TRNS, KC_NO,   KC_TILD, KC_LT,   KC_GT,   KC_NO,   KC_BSLS, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_DQUO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

/* LayerNUMPAD
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |= + - _ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |     TAB|        |        |        |        |        |    *   |    7 & |    8 * |    9 ( |    , < |     BSP|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |LSF  ESC|   LSFT | NUMPAD |        |        |        |    -   |    4 $ |    5 % |    6 ^ |    . > |RSF  ENT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영|        |        |        |        |        |    +   |    1 ! |    2 @ |    3 # |    / ? |    "   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |FN      |GUI     |Alt     |CTL     |NUM  SPC|FN   SPC|FN   SPC|    0 ) |    , < |    . > | NUMLCK |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerNUMPAD] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MNEQ,
#endif
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PAST, KC_7,    KC_8,    KC_9,    KC_COMM, KC_BSPC,
    KC_TRNS, KC_LSFT, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PDOT, RS_ENT,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PPLS, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_DQUO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_COMM, KC_PDOT, KC_NLCK, KC_NO
  ),

/* LayerMOUSEW
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |     TAB| MOUSEW |        |        |        |        |        |  WH U  |  MS U  |  WH D  |  PGUP  |     BSP|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |LSF  ESC|  LSFT  |        |        |        |        |        |  MS L  |  MS D  |  MS R  |  PGDN  |RSF  ENT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영|  LCTL  |        |        |        |        |        |  WH L  |  Btn3  |  WH R  | Insert |    ' " |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |FN      |GUI     |Alt     |CTL     |SYM  SPC|  Btn1  |  Btn1  |  Btn2  |  Left  |  Down  |   UP   | Right  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerMOUSEW] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
#endif
    KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_U, KC_MS_U, KC_WH_D, KC_PGUP, KC_BSPC,
    KC_TRNS, KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_L, KC_BTN3, KC_WH_R, KC_INS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* LayerFUNCTN
 * ,-----------------------------------------------------------------------------------------------------------.
 * |     `  |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |   F10  |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   CAPS |   F11  |   F12  |  PSCR  |  SLCK  |  PAUSE |  한자  | NUMLCK |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |NUM 한영| AU ON  | AU OFF | CK ON  | CK OFF | MU ON  | MU OFF | MUV_DE | MUV_IN |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | FUNCTN |GUI     |Alt     |CTL     |NUM  SPC|FN   SPC|FN   SPC|EDI  SPC|toQWERTY|toKS3to2|toPLOVER|toNUMPAD|
 * `-----------------------------------------------------------------------------------------------------------'
 */
  [LayerFUNCTN] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
#endif
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    KC_CAPS, KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, KC_HANJ, KC_NLCK, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, AU_ON,   AU_OFF,  CK_ON,   CK_OFF,  MU_ON,   MU_OFF,  MUV_DE,  MUV_IN,  KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, toQWERTY,toKS3to2,toPLOVER,toNUMPAD
  ),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [LayerPLOVER] = LAYOUT_grid
  (
#if forPREONIC == yes
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
#endif
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    exitPLVR,XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
  ),

};

#ifdef AUDIO_ENABLE
#define ENGLISH_SOUND       E__NOTE(_C5), E__NOTE(_D5), E__NOTE(_E5), E__NOTE(_F6), E__NOTE(_G5), E__NOTE(_A5), E__NOTE(_B5), E__NOTE(_C6),
#define KOREAN_SOUND        Q__NOTE(_C6), Q__NOTE(_G5), Q__NOTE(_E5), Q__NOTE(_C5),
#define NUMPAD_SOUND        W__NOTE(_C5),
#define SYMPAD_SOUND        W__NOTE(_G5), W__NOTE(_G5),
#define toEDIT_SOUND        W__NOTE(_C6),
float tone_eng[][2]         = SONG(ENGLISH_SOUND);
float tone_kor[][2]         = SONG(KOREAN_SOUND);
float tone_num[][2]         = SONG(NUMPAD_SOUND);
float tone_sym[][2]         = SONG(SYMPAD_SOUND);
float tone_edi[][2]         = SONG(toEDIT_SOUND);
float qwerty_song[][2]     = SONG(QWERTY_SOUND);
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float tone_mac[][2]        = SONG(ROCK_A_BYE_BABY);
float chromatic_song[][2]  = SONG(CHROMATIC_SOUND);
float guitar_song[][2]     = SONG(GUITAR_SOUND);
float violin_song[][2]     = SONG(VIOLIN_SOUND);
float campanella_song[][2] = SONG(CAMPANELLA);
float fantasie_song[][2]   = SONG(FANTASIE_IMPROMPTU);
// float tone_startup[][2]         = SONG(STARTUP_SOUND);
// float tone_goodbye[][2]         = SONG(GOODBYE_SOUND);
// float tone_colemak[][2]         = SONG(COLEMAK_SOUND);
// float tone_capslock_on[][2]     = SONG(CAPS_LOCK_ON_SOUND);
// float tone_capslock_off[][2]    = SONG(CAPS_LOCK_OFF_SOUND);
// float tone_ctrl_mod[][2]        = SONG(COIN_SOUND);
// float tone_copy[][2]            = SONG(SCROLL_LOCK_ON_SOUND);
// float tone_paste[][2]           = SONG(SCROLL_LOCK_OFF_SOUND);
float uniwin[][2]               = SONG(UNICODE_WINDOWS);
float unilin[][2]               = SONG(UNICODE_LINUX);
#endif

static ulralraho_t      ulralraho =
{
  .ctrl_cmd     = KC_LCTRL,
  .isCtrlCmd    = no,
  .cmd_ctrl     = KC_LGUI,
  .isCmdCtrl    = no,
  .ctrl_alt     = KC_LALT,
  .isCtrlAlt    = no,
  .isShift      = no,
  .isAlt        = no,
  .keyHanEng    = KC_HAEN,
  .keyUndo      = LCTL(KC_Z),
  .keyCut       = LCTL(KC_X),
  .keyCopy      = LCTL(KC_C),
  .keyPaste     = LCTL(KC_V),
  .keyRedo      = LCTL(LSFT(KC_Z)),
  .isRedo_Y     = no,
};

static vim_t        vim =
{
  .isMac      = no,
  .keyWord    = LCTL(KC_RIGHT),
  .keyBack    = LCTL(KC_LEFT),
  .keyUndo    = LCTL(KC_Z),
  .keyCut     = LCTL(KC_X),
  .keyCopy    = LCTL(KC_C),
  .keyPaste   = LCTL(KC_V),
  .keyRedo    = LCTL(LSFT(KC_Z)),
};

static ks3to2_t     ks3to2 =
{
  .flags[KS3to2_Flag_Cho]       = no,
  .flags[KS3to2_Flag_Giyeok]    = no,
  .flags[KS3to2_Flag_Digeut]    = no,
  .flags[KS3to2_Flag_Bieub]     = no,
  .flags[KS3to2_Flag_Siot]      = no,
  .flags[KS3to2_Flag_Jieut]     = no,
  .flags[KS3to2_Flag_Jung_O]    = no,
  .flags[KS3to2_Flag_Jung_EU]   = no,
  .flags[KS3to2_Flag_Jung_U]    = no,
  .flags[KS3to2_Flag_Tieut]     = no,
};

static yes_t process_record_shift(keyrecord_t *record);
static yes_t process_record_alt(keyrecord_t *record);
//static yes_t process_record_HANENG(keyrecord_t *record);
static yes_t process_record_MACWIN(keyrecord_t *record);
static yes_t process_record_CTLCMD(keyrecord_t *record);
static yes_t process_record_CMDCTL(keyrecord_t *record);
static yes_t process_record_CTLALT(keyrecord_t *record);
static yes_t process_record_REDO_Y(keyrecord_t *record);
static yes_t process_record_PTMEM(keyrecord_t *record);
static yes_t process_record_BLCMT(keyrecord_t *record);
static yes_t process_record_DBLCMT(keyrecord_t *record);
static yes_t process_record_DQLFDQ(keyrecord_t *record);

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case SYM_SPC:
          return true;
        default:
          return false;
    }
}

bool process_record_user(u16_t keycode, keyrecord_t *record)
{
  yes_t retval = yes;

//    printf("keycode = %d\n", keycode);
  switch (keycode)
  {
    case toQWERTY:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_eng);
        #endif
        set_single_persistent_default_layer(LayerQWERTY);
        layer_off(LayerNUMPAD);
        layer_off(LayerEDITOR);
        layer_off(LayerFUNCTN);
        layer_off(LayerKS3to2);
        layer_on(LayerQWERTY);
      }
      retval = no;
      break;

    case toNUMPAD:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_sym);
        #endif
        layer_off(LayerQWERTY);
        layer_off(LayerEDITOR);
        layer_off(LayerFUNCTN);
        layer_off(LayerKS3to2);
        layer_on(LayerNUMPAD);
      }
      retval = no;
      break;

    case toEDITOR:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_edi);
        #endif
        layer_off(LayerQWERTY);
        layer_off(LayerNUMPAD);
        layer_off(LayerFUNCTN);
        layer_off(LayerKS3to2);
        layer_on(LayerEDITOR);
      }
      retval = no;
      break;

    case toFUNCTN:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_edi);
        #endif
        layer_off(LayerQWERTY);
        layer_off(LayerNUMPAD);
        layer_off(LayerEDITOR);
        layer_off(LayerKS3to2);
        layer_on(LayerFUNCTN);
      }
      retval = no;
      break;

    case toPLOVER:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        stop_all_notes();
        PLAY_SONG(plover_song);
        #endif
        layer_off(LayerQWERTY);
        layer_off(LayerNUMPAD);
        layer_off(LayerEDITOR);
        layer_off(LayerFUNCTN);
        layer_off(LayerKS3to2);
        layer_on(LayerPLOVER);
        if (!eeconfig_is_enabled())
        {
          eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      retval = no;
      break;

    case exitPLVR:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(plover_gb_song);
        #endif
        layer_off(LayerPLOVER);
      }
      retval = no;
      break;

    case toKS3to2:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_edi);
        #endif
        layer_off(LayerQWERTY);
        layer_off(LayerNUMPAD);
        layer_off(LayerEDITOR);
        layer_off(LayerFUNCTN);
        layer_on(LayerKS3to2);
      }
      retval = no;
      break;

    case KC_LSHIFT:
    case KC_RSHIFT:
      retval = process_record_shift(record);
      break;

    case KC_LALT:
    case KC_RALT:
      retval = process_record_alt(record);
      break;

    case KC_HAEN:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_eng);
        #endif
      }
      break;

    case swMacWin:
      retval = process_record_MACWIN(record);
      break;

    case swREDO_Y:
      retval = process_record_REDO_Y(record);
      break;

    case CTLorCMD:
      retval = process_record_CTLCMD(record);
      break;

    case CMDorCTL:
      retval = process_record_CMDCTL(record);
      break;

    case CTLorALT:
      retval = process_record_CTLALT(record);
      break;

    case KC_LSDQT:
      perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_LSFT, KC_QUOT);
      retval = no;
      break;

    case UNDO:
      if (record->event.pressed)
      {
        tap_code16(ulralraho.keyUndo);
      }
      retval = no;
      break;

    case CUT:
      if (record->event.pressed)
      {
        tap_code16(ulralraho.keyCut);
      }
      retval = no;
      break;

    case COPY:
      if (record->event.pressed)
      {
          tap_code16(ulralraho.keyCopy);
      }
      retval = no;
      break;

    case PASTE:
      if (record->event.pressed)
      {
        tap_code16(ulralraho.keyPaste);
      }
      retval = no;
      break;

    case REDO:
      if (record->event.pressed)
      {
          tap_code16(ulralraho.keyRedo);
      }
      retval = no;
      break;

    case vim0 ... vimDEL:
      retval = vim_process_record(&vim, keycode, (const keyrecord_t *)record);
      break;

    case mcPTMEM:
      retval = process_record_PTMEM(record);
      break;

    case mcBLCMT:
      retval = process_record_BLCMT(record);
      break;

    case mcDBLCMT:
      retval = process_record_DBLCMT(record);
      break;

    case mcDQLFDQ:
      retval = process_record_DQLFDQ(record);
      break;

    case KS3_Q ... KS3_ESPC:
      retval = ks3to2_process_record(&ks3to2, keycode, (const keyrecord_t *)record);
      break;

  }
  return retval;
}

static yes_t process_record_shift(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    ulralraho.isShift = yes;
    vim_set_isShift(&vim, ulralraho.isShift);
  }
  else
  {
    ulralraho.isShift = no;
    vim_set_isShift(&vim, ulralraho.isShift);
  }
  return yes;
}

static yes_t process_record_alt(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    ulralraho.isAlt = yes;
    vim_set_isAlt(&vim, ulralraho.isAlt);
  }
  else
  {
    ulralraho.isAlt = no;
    vim_set_isAlt(&vim, ulralraho.isAlt);
  }
  return yes;
}

static yes_t process_record_MACWIN(keyrecord_t *record)
{
  static yes_t isMac = no;

  if (record->event.pressed)
  {
    if (isMac == no)
    {
      #ifdef AUDIO_ENABLE
      PLAY_SONG(tone_mac);
      #endif
      isMac               = yes;
      ulralraho.ctrl_cmd  = KC_LCMD;
      ulralraho.cmd_ctrl  = KC_LCTL;
      ulralraho.ctrl_alt  = KC_LALT;
      ulralraho.keyHanEng = KC_CAPS;
      ulralraho.keyUndo   = LCMD(KC_Z);
      ulralraho.keyCut    = LCMD(KC_X);
      ulralraho.keyCopy   = LCMD(KC_C);
      ulralraho.keyPaste  = LCMD(KC_V);
      if (ulralraho.isRedo_Y)
      {
        ulralraho.keyRedo = LCMD(KC_Y);
      }
      else
      {
        ulralraho.keyRedo = SCMD(KC_Z);
      }
      vim_config(&vim, isMac, ulralraho.isRedo_Y);
      print("isMac ON\n");
    }
    else
    {
      #ifdef AUDIO_ENABLE
      PLAY_SONG(uniwin);
      #endif
      isMac               = no;
      ulralraho.ctrl_cmd  = KC_LCTL;
      ulralraho.cmd_ctrl  = KC_LCMD;
      ulralraho.ctrl_alt  = KC_LCTL;
      ulralraho.keyHanEng = KC_HAEN;
      ulralraho.keyUndo   = LCTL(KC_Z);
      ulralraho.keyCut    = LCTL(KC_X);
      ulralraho.keyCopy   = LCTL(KC_C);
      ulralraho.keyPaste  = LCTL(KC_V);
      if (ulralraho.isRedo_Y)
      {
        ulralraho.keyRedo = LCTL(KC_Y);
      }
      else
      {
        ulralraho.keyRedo = LCTL(LSFT(KC_Z));
      }
      vim_config(&vim, isMac, ulralraho.isRedo_Y);
      print("isMac OFF\n");
    }
  }

  return no;
}

static yes_t process_record_REDO_Y(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (ulralraho.isRedo_Y == yes)
    {
      ulralraho.isRedo_Y = no;
      vim_config_Redo_Y(&vim, ulralraho.isRedo_Y);
      print("REDO Key is Shift + Z\n");
    }
    else
    {
      ulralraho.isRedo_Y = yes;
      vim_config_Redo_Y(&vim, ulralraho.isRedo_Y);
      print("REDO key is Y\n");
    }
  }
  return no;
}

static yes_t process_record_CTLCMD(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    register_code16(ulralraho.ctrl_cmd);
    ulralraho.isCtrlCmd = yes;
    vim_set_isCtrlCmd(&vim, ulralraho.isCtrlCmd);
  }
  else
  {
    unregister_code16(ulralraho.ctrl_cmd);
    ulralraho.isCtrlCmd = no;
    vim_set_isCtrlCmd(&vim, ulralraho.isCtrlCmd);
  }
  return yes;
}

static yes_t process_record_CMDCTL(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    register_code16(ulralraho.cmd_ctrl);
    ulralraho.isCmdCtrl = yes;
    vim_set_isCmdCtrl(&vim, ulralraho.isCmdCtrl);
  }
  else
  {
    unregister_code16(ulralraho.cmd_ctrl);
    ulralraho.isCmdCtrl = no;
    vim_set_isCmdCtrl(&vim, ulralraho.isCmdCtrl);
  }
  return yes;
}

static yes_t process_record_CTLALT(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    register_code16(ulralraho.ctrl_alt);
    ulralraho.isCtrlAlt = yes;
    vim_set_isCtrlAlt(&vim, ulralraho.isCtrlAlt);
  }
  else
  {
    unregister_code16(ulralraho.ctrl_alt);
    ulralraho.isCtrlAlt = no;
    vim_set_isCtrlAlt(&vim, ulralraho.isCtrlAlt);
  }
  return yes;
}

static yes_t process_record_PTMEM(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    tap_code16(KC_MINS);
    tap_code16(KC_GT);
  }
  return no;
}

static yes_t process_record_BLCMT(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    tap_code16(KC_SLSH);
    tap_code16(KC_ASTR);
    tap_code16(KC_SPC);
    tap_code16(KC_SPC);
    tap_code16(KC_ASTR);
    tap_code16(KC_SLSH);
    tap_code16(KC_LEFT);
    tap_code16(KC_LEFT);
    tap_code16(KC_LEFT);
  }
  return no;
}

static yes_t process_record_DBLCMT(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    tap_code16(KC_SLSH);
    tap_code16(KC_ASTR);
    tap_code16(KC_ASTR);
    tap_code16(KC_SPC);
    tap_code16(KC_SPC);
    tap_code16(KC_ASTR);
    tap_code16(KC_SLSH);
    tap_code16(KC_LEFT);
    tap_code16(KC_LEFT);
    tap_code16(KC_LEFT);
  }
  return no;
}

static yes_t process_record_DQLFDQ(keyrecord_t *record)
{
  if (record->event.pressed)
  {
    tap_code16(KC_DQUO);
    tap_code16(KC_BSLS);
    tap_code16(KC_N);
    tap_code16(KC_DQUO);
  }
  return no;
}


//#define SYMBOL  MO(_SYMBOL)
//#define LTSTAB  LT(_SYMBOL, KC_TAB)
// #define LTNTAB  LT(_NUMBER, KC_TAB)
// #define SF_NUMS LM(_NUMBER,MOD_LSFT)
// #define LS_ESC  LSFT_T(KC_ESC)
// #define LC_TAB  LCTL_T(KC_TAB)
// #define LG_TAB  LGUI_T(KC_TAB)
// #define LS_EQL  LSFT_T(KC_EQL)
// #define LS_TAB  LSFT_T(KC_TAB)
// #define RS_QUOT RSFT_T(KC_QUOT)
// #define RS_BSLS RSFT_T(KC_BSLS)
// #define LC_ESC  LCTL_T(KC_ESC)
// #define LG_ESC  LGUI_T(KC_ESC)
// #define LS_SPC  LSFT_T(KC_SPC)
// #define RS_SPC  RSFT_T(KC_SPC)
// #define RS_ENT  RSFT_T(KC_ENT)
// #define RS_HAEN RSFT_T(KC_HAEN)
// #define cUNDO   LCTL(KC_Z)
// #define cCUT    LCTL(KC_X)
// #define cCOPY   LCTL(KC_C)
// #define cPASTE  LCTL(KC_V)
// #define cREDO   LCTL(KC_Y)

// [_QWERTY] = LAYOUT_planck_grid(
//     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

// /* Colemak
//  * ,-----------------------------------------------------------------------------------.
//  * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_COLEMAK] = LAYOUT_planck_grid(
//     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
//     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

// /* Dvorak
//  * ,-----------------------------------------------------------------------------------.
//  * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_DVORAK] = LAYOUT_planck_grid(
//     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
//     KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
//     KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

// /* Lower
//  * ,-----------------------------------------------------------------------------------.
//  * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_LOWER] = LAYOUT_planck_grid(
//     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
//     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
//     _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
// ),

// /* Raise
//  * ,-----------------------------------------------------------------------------------.
//  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_RAISE] = LAYOUT_planck_grid(
//     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
// ),
// /* Adjust (Lower + Raise)
//  *                      v------------------------RGB CONTROL--------------------v
//  * ,-----------------------------------------------------------------------------------
//  * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |             |      |      |      |      |      |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_ADJUST] = LAYOUT_planck_grid(
//     _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
//     _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  CG_NORM,  CG_SWAP, PLOVER,  _______,
//     _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
// )

// /* Korean
//  * ,-----------------------------------------------------------------------------------.
//  * | TAB  | q Q  | w W  | e E  | r R  | t T  | y Y  | u U  | i I  | o O  | p P  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | ESC  | a A  | s S  | d D  | f F  | g G  | h H  | j J  | k K  | l L  | ; :  | ; "  |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |Shift | z Z  | x X  | c C  | v V  | b B  | n N  | m M  | , <  | . >  | / ?  | Shift|
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |CTLCMD|CMDCTL|Alt   |MOUSEM|NUMBER|    Space    |EDITOR| 한영 | = +  |FUNCTN| Enter|
//  * `-----------------------------------------------------------------------------------'
//  */
// [_KOREAN] = LAYOUT_planck_grid(
//   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
//   CTLCMD,  CMDCTL,  KC_LALT, MOUSEM,  NUMBER,  KC_SPC,  KC_SPC,  EDITOR,  HANENG,  TD_EQPL, FUNCTN,  KC_ENT
// ),

// /* Number PAD
//  * ,-----------------------------------------------------------------------------------.
//  * | ` ~  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  | 6 ^  | 7 &  | 8 *  | 9 (  | - _  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |NUMPAD|Shift |      |      |      |      | *    | 4 $  | 5 %  | 6 ^  | +    | = +  |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |Shift |Shift |      |      |      |      | /    | 1 !  | 2 @  | 3 #  |SEnter|SYMPAD|
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |CTLCMD|CMDCTL|Alt   |      |SYMSpc| Space|Space | 0 )  | , <  | . >  |NUMPAD|FUNCTN|
//  * `-----------------------------------------------------------------------------------'
//  */
// [_NUMPAD] = LAYOUT_planck_grid(
//   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS, KC_BSPC,
//   KC_TRNS, KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_EQL,
//   KC_LSFT, KC_LSFT, KC_X,    KC_NO,   KC_NO,   KC_NO,   KC_SLSH, KC_1,    KC_2,    KC_3,    RS_ENT,  KC_TRNS,
//   CTLCMD,  CMDCTL,  KC_LALT, KC_NO,   KC_TRNS, KC_SPC,  KC_SPC,  KC_0,    KC_COMM, KC_DOT,  KC_TRNS, FUNCTN
// ),


//   bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
//                  (keyboard_report->mods & MOD_BIT(KC_RSFT));
//   if (SHIFTED) print("Shifted\n");
//   bool CONTROLED = (keyboard_report->mods & MOD_BIT(KC_LCTL)) |
//                  (keyboard_report->mods & MOD_BIT(KC_RCTL));
//   if (CONTROLED) print("Ctrl\n");

    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    //   break;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
    //   return false;
    //   break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE &= ~(1<<6);
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE |= (1<<6);
    //     #endif
    //   }
    //   return false;
    //   break;

// enum {
//   CT_Q_EXLM = 0,
//   CT_X_ASTR,
//   CT_Y_RPRN,
//   CT_H_EQL,
//   CT_J_MINS,
//   CT_QUOT_BSLS,
//   CT_COMM_LPRN,
//   CT_LBRC_RBRC,
//   CT_MINS_LBRC,
//   CT_EQL_RBRC,
//   CT_ESC_HAEN,

//   CT_BSLS_PIPE,
//   CT_EQL_PLUS,
//   CT_MINS_UNDS,
//   CT_LBRC_LCBR,
//   CT_RBRC_RCBR,
// };

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [CT_Q_EXLM]     = ACTION_TAP_DANCE_DOUBLE(KC_Q,    KC_EXLM),
//   [CT_X_ASTR]     = ACTION_TAP_DANCE_DOUBLE(KC_X,    KC_ASTR),
//   [CT_Y_RPRN]     = ACTION_TAP_DANCE_DOUBLE(KC_Y,    KC_RPRN),
//   [CT_H_EQL]      = ACTION_TAP_DANCE_DOUBLE(KC_H,    KC_EQL),
//   [CT_J_MINS]     = ACTION_TAP_DANCE_DOUBLE(KC_J,    KC_MINS),
//   [CT_QUOT_BSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_BSLS),
//   [CT_COMM_LPRN]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_LPRN),
//   [CT_LBRC_RBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
//   [CT_MINS_LBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_LBRC),
//   [CT_EQL_RBRC]   = ACTION_TAP_DANCE_DOUBLE(KC_EQL,  KC_RBRC),
//   [CT_ESC_HAEN]   = ACTION_TAP_DANCE_DOUBLE(KC_HAEN, KC_ESC),

//   [CT_BSLS_PIPE]  = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
//   [CT_EQL_PLUS]   = ACTION_TAP_DANCE_DOUBLE(KC_EQL,  KC_PLUS),
//   [CT_MINS_UNDS]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
//   [CT_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
//   [CT_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
// };

// #define TD_Q_EX         TD(CT_Q_EXLM)
// #define TD_X_AS         TD(CT_X_ASTR)
// #define TD_Y_RP         TD(CT_Y_RPRN)
// #define TD_H_EQ         TD(CT_H_EQL)
// #define TD_J_MN         TD(CT_J_MINS)
// #define TD_QUBS         TD(CT_QUOT_BSLS)
// #define TD_CMLP         TD(CT_COMM_LPRN)
// #define TD_LRBC         TD(CT_LBRC_RBRC)
// #define TD_MNLB         TD(CT_MINS_LBRC)
// #define TD_EQRB         TD(CT_EQL_RBRC)
// #define TD_ESC          TD(CT_ESC_HAEN)

// #define TD_BSPP         TD(CT_BSLS_PIPE)
// #define TD_EQPL         TD(CT_EQL_PLUS)
// #define TD_MNUD         TD(CT_MINS_UNDS)
// #define TD_LBRC         TD(CT_LBRC_LCBR)
// #define TD_RBRC         TD(CT_RBRC_RCBR)


// static uint16_t _keyTimer;

            // if (record->event.pressed) {
            //     _keyTimer = timer_read();
            //     layer_off(_QWERTY);
            //     layer_off(_KS3to2);
            //     layer_off(_EDITOR);
            //     layer_off(_MOUSEM);
            //     layer_off(_FUNCTN);
            //     layer_on(_NUMPAD);
            // } else {
            //     layer_off(_QWERTY);
            //     layer_off(_NUMPAD);
            //     layer_off(_EDITOR);
            //     layer_off(_MOUSEM);
            //     layer_off(_FUNCTN);
            //     layer_on(_KS3to2);
            //     if (timer_elapsed(_keyTimer) < 300) {
            //         _isGiyeok = false;
            //         _isDigeut = false;
            //         _isBieub = false;
            //         _isSiot = false;
            //         _isJieut = false;
            //         _isJung_EU = false;
            //         _isJung_U = false;
            //         if (_isCho == true) {
            //             _isCho = false;
            //             _isJung_O = true;
            //             tap_code16(KC_H);
            //         } else {
            //             /* 초성 등록 */
            //             _isCho = true;
            //             tap_code16(KC_Z);
            //         }
            //     }
            // }
            // retval = false;


/*

*/
