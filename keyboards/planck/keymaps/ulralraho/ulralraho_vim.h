#ifndef ULRALRAHO_VIM_H
#define ULRALRAHO_VIM_H

#include "ulralraho.h"

typedef struct
{
    /* number */
    u32_t       number;
    /* repeat count */
    u32_t       repeat;
    yes_t       isCtrlCmd;
    yes_t       isCmdCtrl;
    yes_t       isCtrlAlt;
    yes_t       isShift;
    yes_t       isAlt;
    u16_t       key;
    yes_t       isYank;
    yes_t       isDelete;
    yes_t       isVisual;
}vim_reg_t;

typedef struct ulralraho_vim
{
    yes_t       isMac;
    u16_t       keyWord;
    u16_t       keyBack;
    u16_t       keyUndo;
    u16_t       keyCut;
    u16_t       keyCopy;
    u16_t       keyPaste;
    u16_t       keyRedo;
    vim_reg_t   reg;
}vim_t;

v00_t vim_config(vim_t *vim, yes_t isMac, yes_t isRedo_Y);
v00_t vim_config_Redo_Y(vim_t *vim, yes_t isRedo_Y);
v00_t vim_set_isCtrlCmd(vim_t *vim, yes_t isCtrlCmd);
v00_t vim_set_isCmdCtrl(vim_t *vim, yes_t isCmdCtrl);
v00_t vim_set_isCtrlAlt(vim_t *vim, yes_t isCtrlAlt);
v00_t vim_set_isShift(vim_t *vim, yes_t isShift);
v00_t vim_set_isAlt(vim_t *vim, yes_t isAlt);
yes_t vim_process_record(vim_t *vim, u16_t keycode, const keyrecord_t *record);

#endif // ULRALRAHO_VIM_H
