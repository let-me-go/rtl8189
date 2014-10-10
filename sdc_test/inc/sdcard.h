#ifndef SDCARD_H_
#define SDCARD_H_
#include "sdc.h"

void SDCard_ResetCard(Sdc_Object* sdc_obj);
void SDCard_WriteBlocks(Sdc_Object* sdc_obj, UINT32* srcAddress, UINT32 desAddress, UINT32 blockCount);
void SDCard_ReadBlocks(Sdc_Object* sdc_obj, UINT32 srcAddress, UINT32* desAddress, UINT32 blockCount);
#endif /*SDCARD_H_*/

