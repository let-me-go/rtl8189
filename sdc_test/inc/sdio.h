#ifndef SDIO_H_
#define SDIO_H_
#include "sdc.h"

void SDIO_ResetCard(Sdc_Object* sdc_obj);
void SDIO_ReadBlocks(Sdc_Object* sdc_obj, UINT32 srcAddress, UINT32* desAddress, UINT32 blockCount);
void SDIO_ReadBlocksUsingDMA(Sdc_Object* sdc_obj, UINT32 srcAddress, UINT32* desAddress, UINT32 blockCount);
void SDIO_WriteBlocks(Sdc_Object* sdc_obj, UINT32* srcAddress, UINT32 desAddress, UINT32 blockCount);
void SDIO_WriteBlocksUsingDMA(Sdc_Object* sdc_obj, UINT32* srcAddress, UINT32 desAddress, UINT32 blockCount);
void SDIO_WriteByteUsingDMA(Sdc_Object* sdc_obj, UINT32* srcAddress, UINT32 desAddress, UINT32 blockCount);
#endif /*SDIO_H_*/