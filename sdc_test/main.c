#include "chip.h"
#include "chip_reg.h"
//#include "fh81_predefined.h"
#include "gmac.h"
#include "ddrc.h"
#include "gpio.h"

#include "sdc.h"
#include "sdcard.h"


#define DESC_ZONE 0xa0100000	//start from 1m
#define DATA_ZONE 0xa0200000	//start from 2m



void * memset(void * s,int c,int count)
{
	char *xs = (char *) s;

	while (count--)
		*xs++ = c;

	return s;
}


void memcpy(UINT8 * dst,const UINT8 * src,UINT32 size)
{

	while (size--){
		*(UINT8 *)dst = *(UINT8 *)src;
		dst++;
		src++;
	}
}







void sdcard_test(int num)
{

	Sdc_Object sdCard;
	UINT32 sdc_desc_addr = DESC_ZONE;

	UINT32 sdc_buff_addr1 = DATA_ZONE;
	UINT32 sdc_read_size = 0x200000;
	UINT32 sdc_buff_addr2 = sdc_buff_addr1 + sdc_read_size;
	UINT32 i,j;

	sdCard.device_id = num;
	sdCard.card_width = sdc_cardWidth_1bit;
	sdCard.clock_feq = SDC_CLOCK_IN;
	sdCard.dma_brust_size = sdc_idmac_burst_size_8transfers;
	sdCard.block_size = 512;
	sdCard.dma_descriptors = (volatile Sdc_Internal_DMA_Descriptors*)(sdc_desc_addr);




	SDC_Init(&sdCard);
	SDCard_ResetCard(&sdCard);



//	for(i=0; i<0x100000; i++)
//	{
//		SET_REG(0xa0200000+i*4, 0x12345678);
//	}


		for(i=0; i<0x100000; i++)
		{
			SET_REG(0xa0200000+i*4, 0x12345678);
		}

	for(i=0; i<0x100000; i++)
	{
		SET_REG(0xa0300000+i*4, 0);
	}



	//SDCard_WriteBlocks(&sdCard, (UINT32*)sdc_buff_addr1, 0, 1);
	//SDCard_ReadBlocks(&sdCard, 0, (UINT32*)sdc_buff_addr2, 1);


	//4 * 128 == 512k
//	UINT32 unit = 0x1000;
	while(1)
	{
		UINT32 *buf1, *buf2;
		buf1 = (UINT32*)(0xa0200000 );//+ i*unit);
		buf2 = (UINT32*)(0xa0300000 );//+ i*unit);

//		SDCard_WriteBlocks(&sdCard, buf1, 1, 4);
		 while(( GET_REG(REG_SDC_STATUS(num)) & 0x200 ));


		SDCard_ReadBlocks(&sdCard, 1, buf2, 4);

		for(j=0; j<2048; j++)
		{
			if(*buf1++ != *buf2++)
			{
				*(int *)0xa0400000 = j;
				return;
			}
		}


	}


}






int _main(void)
{

	int slot_id;
	denali_ddrc_init();
	//SET_REG_M(0xf0000030, 0x7, 0xff);

	slot_id = 1;

	sdcard_test(slot_id);
	//gmac_test();

	while(1);

	return 0;
}
