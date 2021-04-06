#include "ulralraho_ks3to2.h"

static v00_t clear_flags(ks3to2_t * this);
static v00_t clear_flags_except(ks3to2_t * this, KS3to2_Flags_t flag);
static v00_t clear_flags_SSangJaeum(ks3to2_t * this);
static v00_t clear_flags_JungSung(ks3to2_t * this);
static v00_t layerTab_NUMPAD_BSPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record);
static v00_t layerTab_NUMPAD_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record);
static v00_t layerTab_FUNCTN_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record);
static v00_t layerTab_SYMBOL_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record);
static v00_t layerTab_EDITOR_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record);

yes_t ks3to2_process_record(ks3to2_t *this, u16_t keycode, const keyrecord_t *record)
{
  yes_t retval = no;

  switch (keycode)
  {
    /* 초성 ㄱ */
    case KS3_K:
      if (record->event.pressed)
      {
        /* 쌍기역을 제외한 모든 플래그 클리어 */
        clear_flags_except(this, KS3to2_Flag_Giyeok);
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        /* 쌍기역 확인 */
        if (this->flags[KS3to2_Flag_Giyeok] == yes)
        {
          tap_code16(KC_BSPC);
          tap_code16(LSFT(KC_R));
          this->flags[KS3to2_Flag_Giyeok] = no;
        }
        else
        {
          tap_code16(KC_R);
          this->flags[KS3to2_Flag_Giyeok] = yes;
        }
      }
      retval = no;
      break;

    /* 초성 ㄴ */
    case KS3_H:
      if (record->event.pressed)
      {
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        clear_flags_except(this, KS3to2_Flag_Cho);
        tap_code16(KC_S);
      }
      retval = no;
      break;

    /* 초성 ㄷ */
    case KS3_U:
      if (record->event.pressed)
      {
        /* 쌍디귿을 제외한 모든 플래그 클리어 */
        clear_flags_except(this, KS3to2_Flag_Digeut);
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        /* 쌍디귿 확인 */
        if (this->flags[KS3to2_Flag_Digeut] == yes)
        {
          tap_code16(KC_BSPC);
          tap_code16(LSFT(KC_E));
          this->flags[KS3to2_Flag_Digeut] = no;
        }
        else
        {
          tap_code16(KC_E);
          this->flags[KS3to2_Flag_Digeut] = yes;
        }
      }
      retval = no;
      break;

    /* 초성 ㄹ */
    case KS3_Y:
      if (record->event.pressed)
      {
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        clear_flags_except(this, KS3to2_Flag_Cho);
        tap_code16(KC_F);
      }
      retval = no;
      break;

    /* 초성 ㅁ, 중성 결합용 으 */
    case KS3_I:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_EU] = no;
        this->flags[KS3to2_Flag_Jung_U] = no;
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          this->flags[KS3to2_Flag_Jung_EU] = yes;
          tap_code16(KC_M);
        }
        else
        {
          /* 초성 등록 */
          this->flags[KS3to2_Flag_Cho] = yes;
          tap_code16(KC_A);
        }
      }
      retval = no;
      break;

    /* 초성 ㅂ */
    case KS3_SCLN:
      if (record->event.pressed)
      {
        /* 쌍비읍을 제외한 모든 플래그 클리어 */
        clear_flags_except(this, KS3to2_Flag_Bieub);
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        /* 쌍비읍 확인 */
        if (this->flags[KS3to2_Flag_Bieub] == yes)
        {
          tap_code16(KC_BSPC);
          tap_code16(LSFT(KC_Q));
          this->flags[KS3to2_Flag_Bieub] = no;
        }
        else
        {
          tap_code16(KC_Q);
          this->flags[KS3to2_Flag_Bieub] = yes;
        }
      }
      retval = no;
      break;

    /* 초성 ㅅ */
    case KS3_N:
      if (record->event.pressed)
      {
        /* 쌍시옷을 제외한 모든 플래그 클리어 */
        clear_flags_except(this, KS3to2_Flag_Siot);
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        /* 쌍시옷 확인 */
        if (this->flags[KS3to2_Flag_Siot] == yes)
        {
          tap_code16(KC_BSPC);
          tap_code16(LSFT(KC_T));
          this->flags[KS3to2_Flag_Siot] = no;
        }
        else
        {
          tap_code16(KC_T);
          this->flags[KS3to2_Flag_Siot] = yes;
        }
      }
      retval = no;
      break;

    /* 초성 ㅇ */
    case KS3_J:
      if (record->event.pressed)
      {
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        clear_flags_except(this, KS3to2_Flag_Cho);
        tap_code16(KC_D);
      }
      retval = no;
      break;

    /* 초성 ㅈ */
    case KS3_L:
      if (record->event.pressed)
      {
        /* 쌍지읒을 제외한 모든 플래그 클리어 */
        clear_flags_except(this, KS3to2_Flag_Jieut);
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        /* 쌍지읒 확인 */
        if (this->flags[KS3to2_Flag_Jieut] == yes)
        {
          tap_code16(KC_BSPC);
          tap_code16(LSFT(KC_W));
          this->flags[KS3to2_Flag_Jieut] = no;
        }
        else
        {
          tap_code16(KC_W);
          this->flags[KS3to2_Flag_Jieut] = yes;
        }
      }
      retval = no;
      break;

    /* 초성 ㅊ, 중성 결합용 우 */
    case KS3_O:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_O] = no;
        this->flags[KS3to2_Flag_Jung_EU] = no;
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          this->flags[KS3to2_Flag_Jung_U] = yes;
          tap_code16(KC_N);
        }
        else
        {
          /* 초성 등록 */
          this->flags[KS3to2_Flag_Cho] = yes;
          tap_code16(KC_C);
        }
      }
      retval = no;
      break;

    /* 초성 ㅋ, 중성 결합용 오 */
    case KS3_SLSH:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_EU] = no;
        this->flags[KS3to2_Flag_Jung_U] = no;
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          this->flags[KS3to2_Flag_Jung_O] = yes;
          tap_code16(KC_H);
        }
        else
        {
          /* 초성 등록 */
          this->flags[KS3to2_Flag_Cho] = yes;
          tap_code16(KC_Z);
        }
      }
      retval = no;
      break;

    /* 초성 ㅌ */
    case KS3_QUOT:
      if (record->event.pressed)
      {
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        clear_flags_except(this, KS3to2_Flag_Cho);
        tap_code16(KC_X);
      }
      retval = no;
      break;

    /* 초성 ㅌ (탭하면 comma, 두번째 탭하면 comma를 지우고 ㅌ) */
    case KS3_COMM:
      if (record->event.pressed)
      {
        /* 티읕을 제외한 모든 플래그 클리어 */
        clear_flags_except(this, KS3to2_Flag_Tieut);
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        /* 쌍지읒 확인 */
        if (this->flags[KS3to2_Flag_Tieut] == yes)
        {
          tap_code16(KC_BSPC);
          tap_code16(KC_X);
          this->flags[KS3to2_Flag_Tieut] = no;
        }
        else
        {
          tap_code16(KC_COMM);
          this->flags[KS3to2_Flag_Tieut] = yes;
        }
      }
      retval = no;
      break;
    /* 초성 ㅍ */
    case KS3_P:
      if (record->event.pressed)
      {
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        clear_flags_except(this, KS3to2_Flag_Cho);
        tap_code16(KC_V);
      }
      retval = no;
      break;

    /* 초성 ㅎ */
    case KS3_M:
      if (record->event.pressed)
      {
        /* 초성 등록 */
        this->flags[KS3to2_Flag_Cho] = yes;
        clear_flags_except(this, KS3to2_Flag_Cho);
        tap_code16(KC_G);
      }
      retval = no;
      break;

    /* 중성 아, 종성 ㅍ */
    case KS3_F:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_EU] = no;
        this->flags[KS3to2_Flag_Jung_U] = no;
        /* 중성 아 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_K);
        }
        else
        {
          if (this->flags[KS3to2_Flag_Jung_O] == yes)
          {
            this->flags[KS3to2_Flag_Jung_O] = no;
            tap_code16(KC_K);
          }
          else
          {
            tap_code16(KC_V);
          }
        }
      }
      retval = no;
      break;

    /* 중성 애, 종성 ㅂ */
    case KS3_E:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_EU] = no;
        this->flags[KS3to2_Flag_Jung_U] = no;
        /* 중성 아 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_O);
        }
        else
        {
          if (this->flags[KS3to2_Flag_Jung_O] == yes)
          {
            this->flags[KS3to2_Flag_Jung_O] = no;
            tap_code16(KC_O);
          }
          else
          {
            tap_code16(KC_Q);
          }
        }
      }
      retval = no;
      break;

    /* 중성 야, 종성 ㄹ */
    case KS3_W:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 야 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_I);
        }
        else
        {
          tap_code16(KC_F);
        }
      }
      retval = no;
      break;

    /* 중성 얘, 종성 ㅅ */
    case KS3_Q:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 얘 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(LSFT(KC_O));
        }
        else
        {
          tap_code16(KC_T);
        }
      }
      retval = no;
      break;

    /* 중성 어, 종성 ㅌ */
    case KS3_R:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_O] = no;
        this->flags[KS3to2_Flag_Jung_EU] = no;
        /* 중성 어 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_J);
        }
        else
        {
          if (this->flags[KS3to2_Flag_Jung_U] == yes)
          {
            this->flags[KS3to2_Flag_Jung_U] = no;
            tap_code16(KC_J);
          }
          else
          {
            tap_code16(KC_X);
          }
        }
      }
      retval = no;
      break;

    /* 중성 에, 종성 ㄱ */
    case KS3_C:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        this->flags[KS3to2_Flag_Jung_O] = no;
        this->flags[KS3to2_Flag_Jung_EU] = no;
        /* 중성 에 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_P);
        }
        else
        {
          /* 중성 웨 */
          if (this->flags[KS3to2_Flag_Jung_U] == yes)
          {
            this->flags[KS3to2_Flag_Jung_U] = no;
            tap_code16(KC_P);
          }
          else
          {
            tap_code16(KC_R);
          }
        }
      }
      retval = no;
      break;

    /* 중성 여, 종성 ㅋ */
    case KS3_T:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 여 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_U);
        }
        else
        {
          tap_code16(KC_Z);
        }
      }
      retval = no;
      break;

    /* 중성 예, 종성 ㄴ */
    case KS3_S:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 예 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(LSFT(KC_P));
        }
        else
        {
          tap_code16(KC_S);
        }
      }
      retval = no;
      break;

    /* 중성 오, 종성 ㅈ */
    case KS3_V:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 오 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_H);
        }
        else
        {
          tap_code16(KC_W);
        }
      }
      retval = no;
      break;

    /* 중성 요, 종성 ㅆ */
    case KS3_X:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 요 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_Y);
        }
        else
        {
          tap_code16(LSFT(KC_T));
        }
      }
      retval = no;
      break;

    /* 중성 우, 종성 ㅊ */
    case KS3_B:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 오 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_N);
        }
        else
        {
          tap_code16(KC_C);
        }
      }
      retval = no;
      break;

    /* 중성 유, 종성 ㅇ */
    case KS3_A:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 유 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_B);
        }
        else
        {
          tap_code16(KC_D);
        }
      }
      retval = no;
      break;

    /* 중성 으, 종성 ㄷ */
    case KS3_G:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        /* 중성 으 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          tap_code16(KC_M);
        }
        else
        {
          tap_code16(KC_E);
        }
      }
      retval = no;
      break;

    /* 중성 이, 종성 ㅎ */
    case KS3_D:
      if (record->event.pressed)
      {
        clear_flags_SSangJaeum(this);
        /* 중성 이 */
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
          clear_flags_JungSung(this);
          tap_code16(KC_L);
        }
        else
        {
          if ((this->flags[KS3to2_Flag_Jung_O] == yes) ||
              (this->flags[KS3to2_Flag_Jung_EU] == yes) ||
              (this->flags[KS3to2_Flag_Jung_U] == yes))
          {
            clear_flags_JungSung(this);
            tap_code16(KC_L);
          }
          else
          {
            tap_code16(KC_G);
          }
        }
      }
      retval = no;
      break;

    /* 종성 ㅁ */
    case KS3_Z:
      if (record->event.pressed)
      {
        clear_flags_except(this, KS3to2_Flag_Cho);
        if (this->flags[KS3to2_Flag_Cho] == yes)
        {
          this->flags[KS3to2_Flag_Cho] = no;
        }
        tap_code16(KC_A);
      }
      retval = no;
      break;

    /* ESC */
    case KS3_ESC:
      if (record->event.pressed)
      {
        clear_flags(this);
        tap_code16(KC_ESC);
      }
      retval = no;
      break;

    /* 홀드: NUMPAD 레이어, 탭: 백스페이스바 */
    case KS3_NBSP:
      layerTab_NUMPAD_BSPACE(this, KC_BSPC, record);
      retval = no;
      break;

    /* 홀드: NUMPAD 레이어, 탭: 스페이스바 */
    case KS3_NSPC:
      layerTab_NUMPAD_SPACE(this, KC_SPC, record);
      retval = no;
      break;

   /* 홀드: FUNCTN 레이어, 탭: 스페이스바 */
    case KS3_FSPC:
      layerTab_FUNCTN_SPACE(this, KC_SPC, record);
      retval = no;
      break;

    /* 홀드: SYMBOL 레이어, 탭: 스페이스바 */
    case KS3_SSPC:
      layerTab_SYMBOL_SPACE(this, KC_SPC, record);
      retval = no;
      break;

    /* 홀드: EDITOR 레이어, 탭: 스페이스바 */
    case KS3_ESPC:
      layerTab_EDITOR_SPACE(this, KC_SPC, record);
      retval = no;
      break;

    /* 스페이스바 */
    case KS3_SPC:
      if (record->event.pressed)
      {
        clear_flags(this);
        tap_code16(KC_SPC);
      }
      retval = no;
      break;

    /* 백스페이스 */
    case KS3_BSPC:
      if (record->event.pressed)
      {
        clear_flags(this);
        tap_code16(KC_BSPC);
      }
      retval = no;
      break;

    /* 엔터 */
    case KS3_ENT:
      if (record->event.pressed)
      {
        clear_flags(this);
        tap_code16(KC_ENT);
      }
      retval = no;
      break;

    default:
        /* */
      break;
  }

  return retval;
}

static v00_t clear_flags(ks3to2_t * this)
{
  for (u32_t i = 0; i < (u32_t)NbrOfKS3to2_Flags; i++)
  {
    this->flags[i]  = no;
  }
}

static v00_t clear_flags_except(ks3to2_t * this, KS3to2_Flags_t flag)
{
  for (u32_t i = 0; i < (u32_t)NbrOfKS3to2_Flags; i++)
  {
    if (i != (u32_t)flag)
    {
      this->flags[i]  = no;
    }
  }
}

static v00_t clear_flags_SSangJaeum(ks3to2_t * this)
{
  this->flags[KS3to2_Flag_Giyeok]   = no;
  this->flags[KS3to2_Flag_Digeut]   = no;
  this->flags[KS3to2_Flag_Bieub]    = no;
  this->flags[KS3to2_Flag_Siot]     = no;
  this->flags[KS3to2_Flag_Jieut]    = no;
}

static v00_t clear_flags_JungSung(ks3to2_t * this)
{
  this->flags[KS3to2_Flag_Jung_O]   = no;
  this->flags[KS3to2_Flag_Jung_EU]  = no;
  this->flags[KS3to2_Flag_Jung_U]   = no;
}

static v00_t layerTab_NUMPAD_BSPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record)
{
  static u16_t time;

  if (record->event.pressed)
  {
    time = timer_read();
    layer_on(LayerNUMPAD);
  }
  else
  {
    layer_off(LayerNUMPAD);
    if (timer_elapsed(time) < 300)
    {
      clear_flags(this);
      tap_code16(keycode);
    }
  }
}

static v00_t layerTab_NUMPAD_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record)
{
  static u16_t time;

  if (record->event.pressed)
  {
    time = timer_read();
    layer_on(LayerNUMPAD);
  }
  else
  {
    layer_off(LayerNUMPAD);
    if (timer_elapsed(time) < 300)
    {
      clear_flags(this);
      tap_code16(keycode);
    }
  }
}

static v00_t layerTab_FUNCTN_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record)
{
  static u16_t time;

  if (record->event.pressed)
  {
    time = timer_read();
    layer_on(LayerFUNCTN);
  }
  else
  {
    layer_off(LayerFUNCTN);
    if (timer_elapsed(time) < 300)
    {
      clear_flags(this);
      tap_code16(keycode);
    }
  }
}

static v00_t layerTab_SYMBOL_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record)
{
  static u16_t time;

  if (record->event.pressed)
  {
    time = timer_read();
    layer_on(LayerSYMBOL);
  }
  else
  {
    layer_off(LayerSYMBOL);
    if (timer_elapsed(time) < 300)
    {
      clear_flags(this);
      tap_code16(keycode);
    }
  }
}

static v00_t layerTab_EDITOR_SPACE(ks3to2_t *this, u16_t keycode, const keyrecord_t *record)
{
  static u16_t time;

  if (record->event.pressed)
  {
    time = timer_read();
    layer_on(LayerEDITOR);
  }
  else
  {
    layer_off(LayerEDITOR);
    if (timer_elapsed(time) < 300)
    {
      clear_flags(this);
      tap_code16(keycode);
    }
  }
}
