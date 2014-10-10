#ifndef GMAC_H_
#define GMAC_H_
#include "chip.h"
#include "chip_reg.h"
#include "pre_define.h"
#include "gmac_phyt.h"
#include "gmac_dma.h"

//#define MULT_DESC



enum
{
	gmac_gmii_clock_60_100,
	gmac_gmii_clock_100_150,
	gmac_gmii_clock_20_35,
	gmac_gmii_clock_35_60,
	gmac_gmii_clock_150_250,
	gmac_gmii_clock_250_300
};

enum
{
	gmac_interrupt_all = 0x0001ffff,
	gmac_interrupt_none = 0x0
};






#pragma pack(1)
//gmac would insert preamble, pad bytes, sfd & crc
typedef struct Gmac_Frame
{
	//preamble
	//start frame delimiter
	UINT8 des_address[6];
	UINT8 src_address[6];
	UINT16 length_type;
	UINT8* data;	//pointer to data, 46~1500 bytes
	//padding bytes
	//crc
}Gmac_Frame;
#ifdef MULT_DESC
typedef struct Gmac_Object
{
	UINT8 local_mac_address[6];
	int full_duplex;			//read only
	int speed_100m;				//read only
	volatile Gmac_Rx_DMA_Descriptors* rx_dma_descriptors0;
	volatile Gmac_Rx_DMA_Descriptors* rx_dma_descriptors1;
	volatile Gmac_Tx_DMA_Descriptors* tx_dma_descriptors;
}Gmac_Object;
#else
typedef struct Gmac_Object
{	
	UINT8 local_mac_address[6];
	int full_duplex;			//read only
	int speed_100m;				//read only
	volatile Gmac_Rx_DMA_Descriptors* rx_dma_descriptors;
	volatile Gmac_Tx_DMA_Descriptors* tx_dma_descriptors;
}Gmac_Object;
#endif
#pragma pack()

//Gmac_Frame* frame_array[8];

void GMAC_Init(Gmac_Object* gmac_obj);
//void GMAC_StartReceiving(Gmac_Frame* frame);
void GMAC_SendOneFrame(Gmac_Frame* frame, int size);
void GMAC_ReceiveOneFrame(volatile Gmac_Frame* frame);

#endif /*GMAC_H_*/
