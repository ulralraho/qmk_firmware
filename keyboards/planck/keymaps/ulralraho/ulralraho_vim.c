#include "ulralraho_vim.h"

static yes_t process_repeat(vim_t *vim, u32_t value, const keyrecord_t *record);
static v00_t reset_repeat(vim_t *vim);
static yes_t process_cancel(vim_t *vim, const keyrecord_t *record);
static v00_t cancel_reg(vim_reg_t *reg);
static yes_t process_move(vim_t *vim, u16_t keycode, const keyrecord_t *record);
static v00_t move_cursor(vim_t *vim, u16_t keycode);
static yes_t process_yank(vim_t *vim, const keyrecord_t *record);
static v00_t copy_line(vim_t *vim);
static yes_t process_del(vim_t *vim, const keyrecord_t *record);
static v00_t del_line(vim_t *vim);
static yes_t process_visual(vim_t *vim, const keyrecord_t *record);
static yes_t process_paste(vim_t *vim, const keyrecord_t *record);
static yes_t process_backspace(vim_t *vim, const keyrecord_t *record);
static yes_t process_delete(vim_t *vim, const keyrecord_t *record);


void vim_config(vim_t *vim, yes_t isMac, yes_t isRedo_Y)
{
  vim->isMac       = isMac;
  if (isMac == yes)
  {
    vim->keyWord     = LALT(KC_RIGHT);
    vim->keyBack     = LALT(KC_LEFT);
    vim->keyUndo     = LCMD(KC_Z);
    vim->keyCut      = LCMD(KC_X);
    vim->keyCopy     = LCMD(KC_C);
    vim->keyPaste    = LCMD(KC_V);
    if (isRedo_Y)
    {
      vim->keyRedo    = LCMD(KC_Y);
    }
    else
    {
      vim->keyRedo    = SCMD(KC_Z);
    }
  }
  else
  {
    vim->keyWord     = LCTL(KC_RIGHT);
    vim->keyBack     = LCTL(KC_LEFT);
    vim->keyUndo     = LCTL(KC_Z);
    vim->keyCut      = LCTL(KC_X);
    vim->keyCopy     = LCTL(KC_C);
    vim->keyPaste    = LCTL(KC_V);
    if (isRedo_Y)
    {
      vim->keyRedo    = LCTL(KC_Y);
    }
    else
    {
      vim->keyRedo    = LCTL(LSFT(KC_Z));
    }
  }
}

v00_t vim_config_Redo_Y(vim_t *vim, yes_t isRedo_Y)
{
  if (vim->isMac == yes)
  {
    if (isRedo_Y)
    {
      vim->keyRedo    = LCMD(KC_Y);
    }
    else
    {
      vim->keyRedo    = SCMD(KC_Z);
    }
  }
  else
  {
    if (isRedo_Y)
    {
      vim->keyRedo    = LCTL(KC_Y);
    }
    else
    {
      vim->keyRedo    = LCTL(LSFT(KC_Z));
    }
  }
}

void vim_set_isCtrlCmd(vim_t *vim, yes_t isCtrlCmd)
{
  vim->reg.isCtrlCmd = isCtrlCmd;
}

void vim_set_isCmdCtrl(vim_t *vim, yes_t isCmdCtrl)
{
  vim->reg.isCmdCtrl = isCmdCtrl;
}

void vim_set_isCtrlAlt(vim_t *vim, yes_t isCtrlAlt)
{
  vim->reg.isCtrlAlt = isCtrlAlt;
}

void vim_set_isShift(vim_t *vim, yes_t isShift)
{
  vim->reg.isShift = isShift;
}

void vim_set_isAlt(vim_t *vim, yes_t isAlt)
{
  vim->reg.isAlt = isAlt;
}

yes_t vim_process_record(vim_t *vim, u16_t keycode, const keyrecord_t *record)
{
  yes_t retval = no;

  switch (keycode)
  {
    case vim0 ... vim9:
      retval = process_repeat(vim, (u32_t)keycode, record);
      break;

    case vimESC:
      retval = process_cancel(vim, record);
      break;

    case vimH:
      retval = process_move(vim, KC_LEFT, record);
      break;

    case vimJ:
      retval = process_move(vim, KC_DOWN, record);
      break;

    case vimK:
      retval = process_move(vim, KC_UP, record);
      break;

    case vimL:
      retval = process_move(vim, KC_RIGHT, record);
      break;

    case vimHOME:
      retval = process_move(vim, KC_HOME, record);
      break;

    case vimEND:
      retval = process_move(vim, KC_END, record);
      break;

    case vimW:
      retval = process_move(vim, vim->keyWord, record);
      break;

    case vimB:
      retval = process_move(vim, vim->keyBack, record);
      break;

    case vimY:
      retval = process_yank(vim, record);
      break;

    case vimD:
      retval = process_del(vim, record);
      break;

    case vimV:
      retval = process_visual(vim, record);
      break;

    case vimP:
      retval = process_paste(vim, record);
      break;

    case vimBSPC:
      retval = process_backspace(vim, record);
      break;

    case vimDEL:
      retval = process_delete(vim, record);
      break;

    default:
        /* */
      break;
  }

  return retval;
}

static yes_t process_repeat(vim_t *vim, u32_t value, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    vim->reg.number *= 10;
    vim->reg.number += value;
//  printf("vimNumber = %d\n", vim->reg.number);
  }

  return no;
}

static void reset_repeat(vim_t *vim)
{
  vim->reg.number = 0;
  vim->reg.repeat = 0;
  print("vimRepeat Cleared\n");
}

static yes_t process_cancel(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    cancel_reg(&vim->reg);
    tap_code16(KC_ESC);
  }
  return no;
}

static void cancel_reg(vim_reg_t *reg)
{
  reg->number = 0;
  reg->repeat = 0;
  reg->isYank = no;
  reg->isVisual = no;
  unregister_code16(KC_LSFT);
  reg->isDelete = no;
  print("vimRegister Canceled\n");
}

static yes_t process_move(vim_t *vim, u16_t keycode, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if ((vim->reg.isYank == yes) || (vim->reg.isDelete == yes))
    {
      register_code16(KC_LSFT);
      move_cursor(vim, keycode);
      unregister_code16(KC_LSFT);
      if (vim->reg.isYank == true)
      {
        tap_code16(vim->keyCopy);
        vim->reg.isYank = no;
      }
      else
      {
        tap_code16(vim->keyCut);
        vim->reg.isDelete = no;
      }
      reset_repeat(vim);
//    tap_code16(KC_ESC);
      return no;
    }
    else if (vim->reg.number != 0)
    {
      return no;
    }
    else
    {
      if (vim->reg.isVisual == yes)
      {
        register_code16(KC_LSFT);
      }
      register_code16(keycode);
    }
  }
  else
  {
    if (vim->reg.number != 0)
    {
      if (vim->reg.isVisual == yes)
      {
        register_code16(KC_LSFT);
      }
      move_cursor(vim, keycode);
      unregister_code16(KC_LSFT);
      reset_repeat(vim);
      return no;
    }
    else
    {
      if (vim->reg.isVisual == yes)
      {
        unregister_code16(KC_LSFT);
      }
      unregister_code16(keycode);
    }
  }
  return yes;
}

static void move_cursor(vim_t *vim, u16_t keycode)
{
  vim->reg.repeat += vim->reg.number;
  vim->reg.number = 0;

  if (vim->reg.repeat == 0)
  {
    vim->reg.repeat = 1;
  }

  for (u32_t i = 0; i < vim->reg.repeat; i++)
  {
    tap_code16(keycode);
  }
}

static yes_t process_yank(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (vim->reg.isYank)
    {
      copy_line(vim);
      vim->reg.isYank = no;
//    tap_code16(KC_ESC);
    }
    else if (vim->reg.isDelete)
    {
      reset_repeat(vim);
      vim->reg.isDelete = no;
    }
    else if (vim->reg.isVisual)
    {
      tap_code16(vim->keyCopy);
      reset_repeat(vim);
      vim->reg.isVisual = no;
//    tap_code16(KC_ESC);
    }
    else
    {
      vim->reg.isYank = yes;
      vim->reg.repeat += vim->reg.number;
      vim->reg.number = 0;
    }
  }
  return no;
}

static void copy_line(vim_t *vim)
{
  tap_code16(KC_HOME);
  tap_code16(KC_HOME);
  register_code16(KC_LSFT);
  move_cursor(vim, KC_DOWN);
  unregister_code16(KC_LSFT);
  tap_code16(vim->keyCopy);
  reset_repeat(vim);
}

static yes_t process_del(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (vim->reg.isYank)
    {
      reset_repeat(vim);
      vim->reg.isYank = no;
    }
    else if (vim->reg.isDelete)
    {
      del_line(vim);
      vim->reg.isDelete = no;
//    tap_code16(KC_ESC);
    }
    else if (vim->reg.isVisual)
    {
      tap_code16(vim->keyCut);
      reset_repeat(vim);
      vim->reg.isVisual = no;
//    tap_code16(KC_ESC);
    }
    else
    {
      vim->reg.isDelete = yes;
      vim->reg.repeat += vim->reg.number;
      vim->reg.number = 0;
    }
  }
  return no;
}

static void del_line(vim_t *vim)
{
  tap_code16(KC_HOME);
  tap_code16(KC_HOME);
  register_code16(KC_LSFT);
  move_cursor(vim, KC_DOWN);
  unregister_code16(KC_LSFT);
  tap_code16(vim->keyCut);
  reset_repeat(vim);
}

static yes_t process_visual(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (vim->reg.isVisual)
    {
      unregister_code16(KC_LSFT);
      vim->reg.isVisual = no;
//    tap_code16(KC_ESC);
    }
    else
    {
      if (vim->reg.isShift)
      {
        unregister_code16(KC_LSFT);
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
      }
      vim->reg.isVisual = yes;
    }
  }
  return no;
}

static yes_t process_paste(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (vim->reg.isVisual)
    {
      unregister_code16(KC_LSFT);
      vim->reg.isVisual = no;
    }
    move_cursor(vim, vim->keyPaste);
  }
  return no;
}

static yes_t process_backspace(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (vim->reg.isVisual)
    {
      unregister_code16(KC_LSFT);
      vim->reg.isVisual = no;
    }
    register_code16(KC_BSPC);
  }
  else
  {
    unregister_code16(KC_BSPC);
  }
  return yes;
}

static yes_t process_delete(vim_t *vim, const keyrecord_t *record)
{
  if (record->event.pressed)
  {
    if (vim->reg.isVisual)
    {
      unregister_code16(KC_LSFT);
      vim->reg.isVisual = no;
    }
    register_code16(KC_DEL);
  }
  else
  {
    unregister_code16(KC_DEL);
  }
  return yes;
}
