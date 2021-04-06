#ifndef ULRALRAHO_KS3TO2_H
#define ULRALRAHO_KS3TO2_H

#include "ulralraho.h"

typedef enum KS3to2_Flags_e
{
  KS3to2_Flag_Cho,
  KS3to2_Flag_Giyeok,
  KS3to2_Flag_Digeut,
  KS3to2_Flag_Bieub,
  KS3to2_Flag_Siot,
  KS3to2_Flag_Jieut,
  KS3to2_Flag_Jung_O,
  KS3to2_Flag_Jung_EU,
  KS3to2_Flag_Jung_U,
  KS3to2_Flag_Tieut,
  NbrOfKS3to2_Flags
} KS3to2_Flags_t;

typedef struct ks3to2_s
{
  yes_t flags[NbrOfKS3to2_Flags];
} ks3to2_t;

yes_t ks3to2_process_record(ks3to2_t * this, u16_t keycode, const keyrecord_t *record);

#endif // ULRALRAHO_KS3TO2_H
