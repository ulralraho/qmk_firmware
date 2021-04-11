#ifndef ULRALRAHO_H
#define ULRALRAHO_H

#include QMK_KEYBOARD_H

typedef                 void                v00_t;
typedef                 uint8_t             u08_t;
typedef         const   uint8_t             cu08_t;
typedef                 uint16_t            u16_t;
typedef         const   uint16_t            cu16_t;
typedef                 uint32_t            u32_t;
typedef         const   uint32_t            cu32_t;
typedef                 bool                yes_t;

#define yes true
#define no  false

#define forPREONIC yes

typedef struct ulralraho_s
{
  /** 컨트롤키. Win에서는 컨트롤키, Mac에서는 커맨드키가 됨. */
  u16_t     ctrl_cmd;
  /** 컨트롤키가 커맨드키인지 여부. Mac에서는 yes, Win에서는 no */
  yes_t     isCtrlCmd;
  /** 커맨드키. Win에서는 윈도우키, Mac에서는 컨트롤키가 됨. */
  u16_t     cmd_ctrl;
  yes_t     isCmdCtrl;
  u16_t     ctrl_alt;
  yes_t     isCtrlAlt;
  yes_t     isShift;
  yes_t     isAlt;
  u16_t     keyHanEng;
  u16_t     keyUndo;
  u16_t     keyCut;
  u16_t     keyCopy;
  u16_t     keyPaste;
  u16_t     keyRedo;
  u16_t     isRedo_Y;
}ulralraho_t;

/** \brief 레이어들 */
enum ulralraho_layers
{
  /** Qwerty Layer */
  LayerQWERTY,

  /** Korean Shin 3-set P2 to 2-set convert Layer */
  LayerKS3to2,

  /** Edit and Punctuation Layer */
  LayerEDITOR,

  /** Symbol Layer */
  LayerSYMBOL,

  /** Numpad Layer */
  LayerNUMPAD,

  /** MOUSE Layer */
  LayerMOUSEW,

  /** Function Keys and etc Layer */
  LayerFUNCTN,

  /** Plover Layer */
  LayerPLOVER,

};

/** \brief 사용자 정의 키코드 */
enum ulralraho_keycodes
{
  /** QWERTY 레이어로 변경 */
  toQWERTY  = SAFE_RANGE,

  /** NUMPAD 레이어로 변경 */
  toNUMPAD,

  /** EDITOR 레이어로 변경 */
  toEDITOR,

  /** FUNCTN 레이어로 변경 */
  toFUNCTN,

  /** PLOVER 레이어로 변경 */
  toPLOVER,

  /** PLOVER 레이어에서 탈출 */
  exitPLVR,

  /** 신세벌시P2 레이어로 변경 */
  toKS3to2,

  /** 키보드환경이 Machintosh or Windows 인지 여부 */
  swMacWin,

  /** REDO시 */
  swREDO_Y,
  CTLorCMD,
  CMDorCTL,
  CTLorALT,
  KC_LSDQT,
  UNDO, CUT, COPY, PASTE, REDO,
  vim0, vim1, vim2, vim3, vim4, vim5, vim6, vim7, vim8, vim9, vimESC,
  vimH, vimJ, vimK, vimL, vimW, vimB, vimY, vimD, vimU, vimP, vimV,
  vimHOME, vimEND, vimBSPC, vimDEL,
           KS3_Q, KS3_W, KS3_E, KS3_R, KS3_T, KS3_Y, KS3_U, KS3_I, KS3_O, KS3_P,    KS3_BSPC,
  KS3_NBSP,KS3_A, KS3_S, KS3_D, KS3_F, KS3_G, KS3_H, KS3_J, KS3_K, KS3_L, KS3_SCLN, KS3_ENT,
           KS3_Z, KS3_X, KS3_C, KS3_V, KS3_B, KS3_N, KS3_M, KS3_COMM,     KS3_SLSH, KS3_QUOT,
           KS3_ESC,             KS3_NSPC,KS3_FSPC,KS3_SSPC,KS3_SPC,KS3_ESPC,
  /** macro Point to Member = -> */
  mcPTMEM,
  /** macro Block Comment */
  mcBLCMT,
  /** macro Doxygen Block Comment */
  mcDBLCMT,
  /** macro String = "\n" */
  mcDQLFDQ,

  ULRALRAHO_RANGE
};

#define NUMPAD  MO(LayerNUMPAD)
#define TG_NUM  TG(LayerNUMPAD)
#define SYMPAD  MO(LayerSYMBOL)
#define LS_NUM  LM(LayerNUMPAD, MOD_LSFT)
#define EDITOR  MO(LayerEDITOR)
#define FUNCTN  MO(LayerFUNCTN)
#define KS3to2  TG(LayerKS3to2)
#define TG_MOU  TG(LayerMOUSEW)

#define MOU_ESC  LT(LayerMOUSEW, KC_ESC)    /* 홀드: 마우스레이어, 탭: ESC */
#define MOU_TAB  LT(LayerMOUSEW, KC_TAB)    /* 홀드: 마우스레이어, 탭: TAB */
#define MOU_Q    LT(LayerMOUSEW, KC_Q)      /* 홀드: 마우스레이어, 탭: Q */

#define NUM_ESC  LT(LayerNUMPAD, KC_ESC)    /* 홀드: 숫자레이어, 탭: ESC */
#define NUM_SPC  LT(LayerNUMPAD, KC_SPC)    /* 홀드: 숫자레이어, 탭: SPACE */
#define NUM_BSP  LT(LayerNUMPAD, KC_BSPC)   /* 홀드: 숫자레이어, 탭: BackSPACE */
#define NUM_HAN  LT(LayerNUMPAD, KC_HAEN)   /* 홀드: 숫자레이어, 탭: 한영 */
#define NUM_Z    LT(LayerNUMPAD, KC_Z)      /* 홀드: 숫자레이어, 탭: Z     */
#define NUM_A    LT(LayerNUMPAD, KC_A)      /* 홀드: 숫자레이어, 탭: A     */
//#define NUM_SLSH LT(LayerNUMPAD, KC_SLSH)   /* 홀드: 숫자레이어, 탭: Slash     */
//#define NUM_ENT  LT(LayerNUMPAD, KC_ENT)    /* 홀드: 숫자레이어, 탭: ENTER */

#define LS_TAB   LSFT_T(KC_TAB)             /* 홀드: 좌쉬프트키, 탭: TAB   */
#define LS_ESC   LSFT_T(KC_ESC)             /* 홀드: 좌쉬프트키, 탭: ESC   */
#define LS_BSPC  LSFT_T(KC_BSPC)            /* 홀드: 좌쉬프트키, 탭: BackSPACE */
#define LS_BSP   LSFT_T(KC_BSPC)            /* 홀드: 좌쉬프트키, 탭: BackSPACE */
#define LS_BSLS  LSFT_T(KC_BSLS)            /* 홀드: 좌쉬프트키, 탭: BackSlash */
#define LS_Z     LSFT_T(KC_Z)               /* 홀드: 좌쉬프트키, 탭: Z     */
#define LS_F     LSFT_T(KC_F)               /* 홀드: 좌쉬프트키, 탭: F     */
#define LS_A     LSFT_T(KC_A)               /* 홀드: 좌쉬프트키, 탭: A     */
#define LS_SPC   LSFT_T(KC_SPC)             /* 홀드: 좌쉬프트키, 탭: SPACE */
#define LS_HAN   LSFT_T(KC_HAEN)            /* 홀드: 좌쉬프트키, 탭: 한영 */

#define RS_QUOT  RSFT_T(KC_QUOT)            /* 홀드: 우쉬프트키, 탭: Quotation */
#define RS_SLSH  RSFT_T(KC_SLSH)            /* 홀드: 우쉬프트키, 탭: Slash     */
#define RS_BSLS  RSFT_T(KC_BSLS)            /* 홀드: 우쉬프트키, 탭: BackSlash */
#define RS_J     RSFT_T(KC_J)               /* 홀드: 우쉬프트키, 탭: J     */
#define RS_SCLN  RSFT_T(KC_SCLN)            /* 홀드: 우쉬프트키, 탭: SemiColon */
#define RS_ENT   RSFT_T(KC_ENT)             /* 홀드: 우쉬프트키, 탭: ENTER */
//#define RS_SPC   RSFT_T(KC_SPC)             /* 홀드: 우쉬프트키, 탭: SPACE */

#define EDI_SPC  LT(LayerEDITOR, KC_SPC)    /* 홀드: 편집레이어, 탭: SPACE */
#define EDI_ENT  LT(LayerEDITOR, KC_ENT)    /* 홀드: 편집레이어, 탭: ENTER */
#define EDI_HAN  LT(LayerEDITOR, KC_HAEN)   /* 홀드: 편집레이어, 탭: 한영  */
//#define EDI_BKS  LT(LayerEDITOR, KC_BSPC)   /* 홀드: 편집레이어, 탭: BackSPACE */

#define SYM_SPC  LT(LayerSYMBOL, KC_SPC)    /* 홀드: 심볼레이어, 탭: SPACE */
#define SYM_BSP  LT(LayerSYMBOL, KC_BSPC)   /* 홀드: 심볼레이어, 탭: BackSPACE */
#define SYM_Z    LT(LayerSYMBOL, KC_Z)      /* 홀드: 심볼레이어, 탭: Z */

#define FNC_SPC  LT(LayerFUNCTN, KC_SPC)    /* 홀드: 기능레이어, 탭: SPACE */
#define FNC_QUT  LT(LayerFUNCTN, KC_QUOT)   /* 홀드: 기능레이어, 탭: Quotation */
#define FUN_GRV  LT(LayerFUNCTN, KC_GRV)    /* 홀드: 기능레이어, 탭: ` */
#define CTL_BSP  LCTL_T(KC_BSPC)            /* 홀드: 좌컨트롤키, 탭: BackSPACE */

#define CTL_Z    LCTL(KC_Z)
#define CTL_X    LCTL(KC_X)
#define CTL_C    LCTL(KC_C)
#define CTL_V    LCTL(KC_V)
#define CTL_Y    LCTL(KC_Y)

#define CAP_A    LSFT(KC_A)
#define CAP_B    LSFT(KC_B)
#define CAP_C    LSFT(KC_C)
#define CAP_D    LSFT(KC_D)
#define CAP_E    LSFT(KC_E)
#define CAP_F    LSFT(KC_F)

#endif // ULRALRAHO_H
