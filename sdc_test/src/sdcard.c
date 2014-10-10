#include "sdc.h"
#include "sdcard.h"
#define CHECK_SPEED
void SDCard_ResetCard(Sdc_Object* sdc_obj)
{
	//set slower clock for reset card
	SDC_UpdateClockRegister(sdc_obj, 30);
	
	SDC_SendCommand(sdc_obj, 0, 0, sdc_response_type_none, sdc_data_transfer_none, TRUE, FALSE);

	SDC_SendCommand(sdc_obj, 8, 0x1aa, sdc_response_type_short, sdc_data_transfer_none, TRUE, FALSE);
	
	if(GET_REG(REG_SDC_RESP0(sdc_obj->device_id)) == 0x1a5)
	{
		//sd2.0
	}
	
	Reg_Sdc_Ocr sdc_ocr = {0};
	
	while(!sdc_ocr.bit.card_power_up_status)
	{
		sdc_ocr.bit.card_capacity_status = 1;
		SDC_SendAppCommand(sdc_obj, 41, sdc_ocr.dw/*0x40ff8000*/, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
		sdc_ocr.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	}
	
	sdc_obj->is_high_capacity = sdc_ocr.bit.card_capacity_status;
	
	SDC_SendCommand(sdc_obj, 2, 0, sdc_response_type_long, sdc_data_transfer_none, FALSE, FALSE);
	
	//SDC_SendCommand(sdc_obj, 3, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
	Reg_Sdc_Rca sdc_rca = {0};
	sdc_rca.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	
	while(sdc_rca.bit.current_state != sdc_card_status_stby)
	{
		//return;
		SDC_SendCommand(sdc_obj, 3, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
		sdc_rca.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	}

	sdc_obj->card_rca = sdc_rca.bit.relative_card_addr;
	
	SDC_SendCommand(sdc_obj, 9, sdc_obj->card_rca << 16, sdc_response_type_long, sdc_data_transfer_none, FALSE, FALSE);
	
	SDC_SendCommand(sdc_obj, 7, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
//	SET_REG(REG_SDC_BLKSIZ(sdc_obj->device_id), 0x8);
//	SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), 0x8);
//	UINT32 data, reserved;
//	SDC_SendAppCommand(sdc_obj, 51, 0, sdc_response_type_short, sdc_data_transfer_read, TRUE, FALSE);
//	data = GET_REG(REG_SDC_FIFO(sdc_obj->device_id));
//	reserved = GET_REG(REG_SDC_FIFO(sdc_obj->device_id));
//	SET_REG(0x100000a0,data);
//	SET_REG(0x100000a4,reserved);

	#ifdef CHECK_SPEED

	unsigned int data_count,num;
	for(num=0;num<0x50;num++)
		SET_REG(0xa0200000+num*4,0);
	for(num=0;num<0x50;num++)
			SET_REG(0xa0300000+num*4,0);
	//check card status

	SET_REG(REG_SDC_BLKSIZ(sdc_obj->device_id), 0x40);
		SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), 0x40);
		UINT32 data, reserved;
		SDC_SendAppCommand(sdc_obj, 13, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_read, TRUE, FALSE);
		for(data_count=0;data_count<0x10;data_count++)
		{

			while(GET_REG(REG_SDC_STATUS(sdc_obj->device_id))&0x4)
			{
			}

			num = GET_REG(REG_SDC_FIFO(sdc_obj->device_id));
			SET_REG(0xa0200000+data_count*4,num);

		}
		UINT32 *ssr;
		ssr = (UINT32 *)0xa0200000;
		int es,et,eo,type,speed_class,pfe_mv;
		type = UNSTUFF_BITS(ssr, 495 - 480, 16);
		es = UNSTUFF_BITS(ssr, 408 - 384, 16);
		et = UNSTUFF_BITS(ssr, 402 - 384, 6);
		eo = UNSTUFF_BITS(ssr, 400 - 384, 2);
		speed_class = UNSTUFF_BITS(ssr, 447 - 440, 8);
		pfe_mv= UNSTUFF_BITS(ssr, 439 - 432, 8);
		SET_REG(0xa0300000,es);
		SET_REG(0xa0300004,et);
		SET_REG(0xa0300008,eo);
		SET_REG(0xa030000c,type);
		SET_REG(0xa0300010,speed_class);
		SET_REG(0xa0300014,pfe_mv);
	//check speed mod


//mode 0

		SET_REG(REG_SDC_BLKSIZ(sdc_obj->device_id), 0x40);

		SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), 0x40);

		SDC_SendCommand(sdc_obj, 6,0x00fffff1 , sdc_response_type_short,sdc_data_transfer_read, TRUE, FALSE);


		for(data_count=0;data_count<0x10;data_count++)
		{

			while(GET_REG(REG_SDC_STATUS(sdc_obj->device_id))&0x4)
			{
			}

			num = GET_REG(REG_SDC_FIFO(sdc_obj->device_id));
			SET_REG(0xa0200000+data_count*4,num);

		}
//mode 1
		SET_REG(REG_SDC_BLKSIZ(sdc_obj->device_id), 0x40);

		SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), 0x40);

		SDC_SendCommand(sdc_obj, 6,0x80fffff1 , sdc_response_type_short,sdc_data_transfer_read, TRUE, FALSE);


		for(data_count=0;data_count<0x10;data_count++)
		{

			while(GET_REG(REG_SDC_STATUS(sdc_obj->device_id))&0x4)
			{
			}

			num = GET_REG(REG_SDC_FIFO(sdc_obj->device_id));
			SET_REG(0xa0200060+data_count*4,num);

		}


	//	SDC_SendCommand(sdc_obj, 7, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	//	SDC_SendCommand(sdc_obj, 9, sdc_obj->card_rca << 16, sdc_response_type_long, sdc_data_transfer_none, FALSE, FALSE);
#endif
	SET_REG(REG_SDC_BLKSIZ(sdc_obj->device_id), sdc_obj->block_size);
	SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), sdc_obj->block_size);

	SDC_SendCommand(sdc_obj, 16, sdc_obj->block_size, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	SET_REG_M(REG_SDC_CTYPE(sdc_obj->device_id), sdc_obj->card_width, 0x1);
	if(sdc_obj->card_width == sdc_cardWidth_1bit)
	{
		SDC_SendAppCommand(sdc_obj, 6, 0, sdc_response_type_short, sdc_data_transfer_none, TRUE, FALSE);
	}
	else if(sdc_obj->card_width == sdc_cardWidth_4bit)
	{
		SDC_SendAppCommand(sdc_obj, 6, 2, sdc_response_type_short, sdc_data_transfer_none, TRUE, FALSE);
	}



	SDC_UpdateClockRegister(sdc_obj, 0);

	//deselsect card
	//SDC_SendCommand(sdc_obj, 7, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
}

#if 0
void SDCard_WriteBlocks(Sdc_Object* sdc_obj, UINT32* srcAddress, UINT32 desAddress, UINT32 blockCount)
{
	//clear interrupt
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_all);
	//select card
	//SDC_SendCommand(sdc_obj, 7, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
	//fifo reset
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<1, 1<<1);

	UINT32 i;
	UINT32 toWhichBlock = 0;
	
	for(i=0; i<blockCount; i++)
	{

		if(!sdc_obj->is_high_capacity)
		{
			toWhichBlock = desAddress + 512 * i;
		}
		else
		{
			toWhichBlock = desAddress / 512 + i;
		}
		
		//DELAY(20000);
		//SDC_DmaDescriptorInit(sdc_obj);

//		init idmac descriptor
		sdc_obj->dma_descriptors->desc1.bit.buffer1_size = sdc_obj->block_size;
		sdc_obj->dma_descriptors->desc2.dw = (UINT32)srcAddress + i * sdc_obj->block_size;
		SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), sdc_obj->block_size);
		sdc_obj->dma_descriptors->desc0.bit.own = 1;

		//idmac enable
		SET_REG_M(REG_SDC_BMOD(sdc_obj->device_id), (1<<7 | 1<<1), (1<<7 | 1<<1));
		
		SET_REG(REG_SDC_PLDMND(sdc_obj->device_id), 1);

		SDC_SendCommand(sdc_obj, 24, toWhichBlock, sdc_response_type_short, sdc_data_transfer_write, TRUE, FALSE);

		while(!( GET_REG(REG_SDC_RINTSTS(sdc_obj->device_id)) & 0x8 ))
		{

		}

		//SDC_SendCommand(sdc_obj, 12, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, TRUE);
		DELAY(20000);
	}
	//deselsect card
	//SDC_SendCommand(sdc_obj, 7, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
}
#else
void SDCard_WriteBlocks(Sdc_Object* sdc_obj, UINT32* srcAddress, UINT32 desAddress, UINT32 blockCount)
{
	//select card
	//SDC_SendCommand(sdc_obj, 7, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);

	//fifo reset
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<1, 1<<1);
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<25, 1<<25);
	UINT32 toWhichBlock = 0;

	if(!sdc_obj->is_high_capacity)
	{
		toWhichBlock = desAddress;
	}
	else
	{
		toWhichBlock = (desAddress >> 8);
	}



	//init idmac descriptor
	SDC_DmaDescriptorInit(sdc_obj);
	sdc_obj->dma_descriptors->desc0.bit.own = 1;
	sdc_obj->dma_descriptors->desc1.bit.buffer1_size = sdc_obj->block_size*blockCount;
	sdc_obj->dma_descriptors->desc2.dw = (UINT32)srcAddress;
	SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), sdc_obj->block_size*blockCount);

	//idmac enable
	SET_REG_M(REG_SDC_BMOD(sdc_obj->device_id), 1<<7, 1<<7);

	SDC_SendCommand(sdc_obj, 25, toWhichBlock, sdc_response_type_short, sdc_data_transfer_write, TRUE, FALSE);

	UINT32 rintStatus = 0;

	while(!( rintStatus & 0x8 ))
	{
		rintStatus = GET_REG(REG_SDC_RINTSTS(sdc_obj->device_id));
	}
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id),0x8);
	SDC_SendCommand(sdc_obj, 12, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, TRUE);

	//deselsect card
	//SDC_SendCommand(sdc_obj, 7, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
}
#endif


#if 0
void SDCard_ReadBlocks(Sdc_Object* sdc_obj, UINT32 srcAddress, UINT32* desAddress, UINT32 blockCount)
{

	//clear interrupt
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_all);

	//select card
	//SDC_SendCommand(sdc_obj, 7, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
	//fifo reset
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<1, 1<<1);

	UINT32 i;
	UINT32 fromWhichBlock = 0;
	
	for(i=0; i<blockCount; i++)
	{
		
		if(!sdc_obj->is_high_capacity)
		{
			fromWhichBlock = srcAddress + i * 512;
		}
		else
		{
			fromWhichBlock = srcAddress / 512 + i;
		}
		
		//DELAY(20000);
		//SDC_DmaDescriptorInit(sdc_obj);
		
		sdc_obj->dma_descriptors->desc1.bit.buffer1_size = sdc_obj->block_size;
		sdc_obj->dma_descriptors->desc2.dw = (UINT32)desAddress + i * sdc_obj->block_size;
		SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), sdc_obj->block_size);
		sdc_obj->dma_descriptors->desc0.bit.own = 1;
		
		//idmac enable
		SET_REG_M(REG_SDC_BMOD(sdc_obj->device_id), (1<<7 | 1<<1), (1<<7 | 1<<1));
		
		SET_REG(REG_SDC_PLDMND(sdc_obj->device_id), 1);

		SDC_SendCommand(sdc_obj, 17, fromWhichBlock, sdc_response_type_short, sdc_data_transfer_read, TRUE, FALSE);

		while(!( GET_REG(REG_SDC_RINTSTS(sdc_obj->device_id)) & 0x8 ))
		{

		}

		//SDC_SendCommand(sdc_obj, 12, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, TRUE);
		DELAY(20000);
	}
	
	//deselsect card
	//SDC_SendCommand(sdc_obj, 7, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
}
#else
void SDCard_ReadBlocks(Sdc_Object* sdc_obj, UINT32 srcAddress, UINT32* desAddress, UINT32 blockCount)
{

	//clear interrupt
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_all);

	//select card
	//SDC_SendCommand(sdc_obj, 7, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<25, 1<<25);
	//fifo reset
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<1, 1<<1);

	UINT32 fromWhichBlock = 0;

	if(!sdc_obj->is_high_capacity)
	{
		fromWhichBlock = srcAddress;
	}
	else
	{
		fromWhichBlock = (srcAddress >> 8);
	}

	sdc_obj->dma_descriptors->desc1.bit.buffer1_size = sdc_obj->block_size * blockCount;
	sdc_obj->dma_descriptors->desc2.dw = (UINT32)desAddress;
	SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), sdc_obj->block_size * blockCount);
	sdc_obj->dma_descriptors->desc0.bit.own = 1;

	//idmac enable
	SET_REG_M(REG_SDC_BMOD(sdc_obj->device_id), 1<<7, 1<<7);

	SDC_SendCommand(sdc_obj, 18, fromWhichBlock, sdc_response_type_short, sdc_data_transfer_read, TRUE, FALSE);

	while(!( GET_REG(REG_SDC_RINTSTS(sdc_obj->device_id)) & 0x8 ))
	{

	}
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id),0x8);
	SDC_SendCommand(sdc_obj, 12, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, TRUE);


	//deselsect card
	//SDC_SendCommand(sdc_obj, 7, 0, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
}
#endif
