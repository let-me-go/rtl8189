#include "sdc.h"

int SDC_UpdateClockRegister(Sdc_Object* sdc_obj, int div)
{
#if 1
	/* disable clock */
	SET_REG(REG_SDC_CLKENA(sdc_obj->device_id), 200);
	SET_REG(REG_SDC_CLKSRC(sdc_obj->device_id), 0);

	/* inform CIU */
	SET_REG(REG_SDC_CMD(sdc_obj->device_id), (UINT32)1<<31 | (UINT32)1<<21 | 1<<13);
	while(GET_REG(REG_SDC_CMD(sdc_obj->device_id)) & 0x80000000)
	{

	}

	/* set clock to desired speed */
	SET_REG(REG_SDC_CLKDIV(sdc_obj->device_id), div);

	/* inform CIU */
	SET_REG(REG_SDC_CMD(sdc_obj->device_id), (UINT32)1<<31 | (UINT32)1<<21 | 1<<13);
	while(GET_REG(REG_SDC_CMD(sdc_obj->device_id)) & 0x80000000)
	{

	}

	/* enable clock */
	SET_REG(REG_SDC_CLKENA(sdc_obj->device_id), 1);

	/* inform CIU */
	SET_REG(REG_SDC_CMD(sdc_obj->device_id), (UINT32)1<<31 | (UINT32)1<<21 | 1<<13);
	while(GET_REG(REG_SDC_CMD(sdc_obj->device_id)) & 0x80000000)
	{

	}
#else

	//50000000 / 125000 / 2
	SET_REG(REG_SDC_CLKDIV(sdc_obj->device_id), div / 2);
	SET_REG(REG_SDC_CLKENA(sdc_obj->device_id), 1);
	SET_REG(REG_SDC_CMDARG(sdc_obj->device_id), 0);
	
	//update clock setting to card
	//SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_sdcard_all);
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_all);

	SET_REG(REG_SDC_CMD(sdc_obj->device_id), (UINT32)1<<31 | (UINT32)1<<21 | 1<<13);
	
	while(GET_REG(REG_SDC_CMD(sdc_obj->device_id)) & 0x80000000)
	{

	}
#endif
	return 0;
}

int SDC_SendCommand(Sdc_Object* sdc_obj, int cmdIndex, UINT32 argument, int responseType, int readWrite, int waitPrvData, int stopCmd)
{
	//SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_sdcard_all);
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_all);

	SET_REG(REG_SDC_CMDARG(sdc_obj->device_id), argument);

	SET_REG(REG_SDC_CMD(sdc_obj->device_id), (UINT32)1<<31 | (UINT32)1<<29 | stopCmd<<14 | waitPrvData<<13 | ( (readWrite >> 1) & 0x1 )<<10 \
			| (readWrite & 0x1)<<9 | ( (responseType >> 1) & 0x1 )<<7 | (responseType & 0x1)<<6 | cmdIndex);
	
	while((GET_REG(REG_SDC_CMD(sdc_obj->device_id)) & 0x80000000) || !(GET_REG(REG_SDC_RINTSTS(sdc_obj->device_id)) & 0x4))
	{

	}

	return 0;
	
}

int SDC_SendAppCommand(Sdc_Object* sdc_obj, int cmdIndex, UINT32 argument, int responseType, int readWrite, int waitPrvData, int stopCmd)
{
	SDC_SendCommand(sdc_obj, 55, sdc_obj->card_rca << 16, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
	SDC_SendCommand(sdc_obj, cmdIndex, argument, responseType, readWrite, waitPrvData, stopCmd);
	
	return 0;
}

UINT32 SDC_Cmd52Read(Sdc_Object* sdc_obj, UINT32 address, int funcNum)
{
	Reg_Sdio_IORW_Cmd sdio_iorw_cmd = {0};
	sdio_iorw_cmd.bit.register_addr = address;
	sdio_iorw_cmd.bit.func_num = funcNum;
	
	SDC_SendCommand(sdc_obj, 52, sdio_iorw_cmd.dw, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
	Reg_Sdio_IORW_Resp sdio_iorw_resp = {0};
	sdio_iorw_resp.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	
	//while(sdio_iorw_resp.bit.crc_error || sdio_iorw_resp.bit.error || sdio_iorw_resp.bit.illegal_cmd || sdio_iorw_resp.bit.out_of_range)
	while(sdio_iorw_resp.bit.error)
	{
		
	}
	
	return sdio_iorw_resp.bit.data;
}

void SDC_Cmd52Write(Sdc_Object* sdc_obj, UINT32 address, int funcNum, UINT32 data)
{
	Reg_Sdio_IORW_Cmd sdio_iorw_cmd = {0};
	sdio_iorw_cmd.bit.rw_flag = 1;
	sdio_iorw_cmd.bit.raw_flag = 1;
	sdio_iorw_cmd.bit.write_data = data;
	sdio_iorw_cmd.bit.register_addr = address;
	sdio_iorw_cmd.bit.func_num = funcNum;
	
	SDC_SendCommand(sdc_obj, 52, sdio_iorw_cmd.dw, sdc_response_type_short, sdc_data_transfer_none, FALSE, FALSE);
	
	Reg_Sdio_IORW_Resp sdio_iorw_resp = {0};
	sdio_iorw_resp.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	
	//while(sdio_iorw_resp.bit.crc_error || sdio_iorw_resp.bit.error || sdio_iorw_resp.bit.illegal_cmd || sdio_iorw_resp.bit.out_of_range)
	while(sdio_iorw_resp.bit.error)
	{
		
	}
}

void SDC_Cmd53Read(Sdc_Object* sdc_obj, UINT32 cardAddress, int blockCount)
{
	Reg_Sdio_IORW_Extended sdio_iorw_extended = {0};
	sdio_iorw_extended.bit.rw_flag = 0;
	sdio_iorw_extended.bit.block_mode = 1;
	sdio_iorw_extended.bit.data_count = blockCount;
	sdio_iorw_extended.bit.register_addr = cardAddress;
	sdio_iorw_extended.bit.func_num = 1;
	SDC_SendCommand(sdc_obj, 53, sdio_iorw_extended.dw, sdc_response_type_short, sdc_data_transfer_read, TRUE, FALSE);
	
	Reg_Sdio_IORW_Resp sdio_iorw_resp = {0};
	sdio_iorw_resp.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	
	//while(sdio_iorw_resp.bit.crc_error || sdio_iorw_resp.bit.error || sdio_iorw_resp.bit.illegal_cmd || sdio_iorw_resp.bit.out_of_range)
	while(sdio_iorw_resp.bit.error)
	{
		
	}
}

void SDC_Cmd53Write(Sdc_Object* sdc_obj, UINT32 cardAddress, int blockCount)
{
	Reg_Sdio_IORW_Extended sdio_iorw_extended = {0};
	sdio_iorw_extended.bit.rw_flag = 1;
	sdio_iorw_extended.bit.block_mode = 1;
	sdio_iorw_extended.bit.data_count = blockCount;
	sdio_iorw_extended.bit.register_addr = cardAddress;
	sdio_iorw_extended.bit.func_num = 1;
	SDC_SendCommand(sdc_obj, 53, sdio_iorw_extended.dw, sdc_response_type_short, sdc_data_transfer_write, TRUE, FALSE);
	
	Reg_Sdio_IORW_Resp sdio_iorw_resp = {0};
	sdio_iorw_resp.dw = GET_REG(REG_SDC_RESP0(sdc_obj->device_id));
	
	//while(sdio_iorw_resp.bit.crc_error || sdio_iorw_resp.bit.error || sdio_iorw_resp.bit.illegal_cmd || sdio_iorw_resp.bit.out_of_range)
	while(sdio_iorw_resp.bit.error)
	{
		
	}
}

void SDC_DmaDescriptorInit(Sdc_Object* sdc_obj)
{
	sdc_obj->dma_descriptors->desc0.dw = 0;
	sdc_obj->dma_descriptors->desc1.dw = 0;
	sdc_obj->dma_descriptors->desc2.dw = 0;
	sdc_obj->dma_descriptors->desc3.dw = 0;
	sdc_obj->dma_descriptors->desc0.bit.sencond_address_chained = 1;
	sdc_obj->dma_descriptors->desc0.bit.first_descriptor = 1;
	sdc_obj->dma_descriptors->desc0.bit.last_descriptor = 1;
	sdc_obj->dma_descriptors->desc0.bit.end_of_ring = 1;
	sdc_obj->dma_descriptors->desc3.dw = (UINT32)sdc_obj->dma_descriptors;
}

void SDC_Init(Sdc_Object* sdc_obj)
{
	sdc_obj->card_rca = 0;
	sdc_obj->is_high_capacity = 0;
	
	//sdc_obj->sdc_module = (volatile Sdc_Module*)(REG_SDC_CTRL(sdc_obj->device_id));
	
	//sdc_obj->fifo_address = REG_SDC_FIFO(sdc_obj->device_id);
	
	
	//reset controller
	//controller_reset
	//fifo_reset
	//dma_reset
	SET_REG(REG_SDC_CTRL(sdc_obj->device_id), 1<<2 | 1<<1 | 1);

	//use_internal_dmac
	//SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<25, 1<<25);

	//sw_reset
	SET_REG(REG_SDC_BMOD(sdc_obj->device_id), 1);
	
	//init idma
	//SDC_DmaDescriptorInit(sdc_obj);
	SET_REG(REG_SDC_DBADDR(sdc_obj->device_id), (UINT32)sdc_obj->dma_descriptors);
	
	//clear interrupt
	SET_REG(REG_SDC_RINTSTS(sdc_obj->device_id), sdc_interrupt_all);

	//int enbale 
	SET_REG_M(REG_SDC_CTRL(sdc_obj->device_id), 1<<4, 1<<4);
	
	//mask all int
	SET_REG(REG_SDC_INTMASK(sdc_obj->device_id), sdc_interrupt_none);
	
	//set data and response timeout to maximum value
	SET_REG(REG_SDC_TMOUT(sdc_obj->device_id), 0xffffffff);

	//card detect debunce
	SET_REG(REG_SDC_DEBNCE(sdc_obj->device_id), 0xfffff);
	
	//set fifo watermarks
	//rx_wmark = 0x7
	//tx_wmark = 0x8
	//dw_dma_mutiple_transaction_size
	UINT32 fifo_size;
	fifo_size = GET_REG(REG_SDC_FIFOTH(sdc_obj->device_id));
	fifo_size = (fifo_size >> 16) & 0x7ff;

	fifo_size = ((0x2 << 28) | ((fifo_size/2 - 1) << 16) |
			((fifo_size/2) << 0));

	SET_REG(REG_SDC_FIFOTH(sdc_obj->device_id), fifo_size);

	//SET_REG(REG_SDC_FIFOTH(sdc_obj->device_id), sdc_obj->dma_brust_size<<28 | 0x7<<16 | 0x8);
	
	//Card width
	//SET_REG_M(REG_SDC_CTYPE(sdc_obj->device_id), sdc_obj->card_width, 0x1);
	
	SET_REG(REG_SDC_BLKSIZ(sdc_obj->device_id), sdc_obj->block_size);
	SET_REG(REG_SDC_BYTCNT(sdc_obj->device_id), sdc_obj->block_size);
	
}

