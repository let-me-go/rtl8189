#include "chip.h"
#include "chip_reg.h"
#include "gmac.h"
#include "intc.h"
//#define MULT_DESC
//#define USE_INTERRUPT
//GMAC-MAC
#define		REG_GMAC_CONFIG				(GMAC_REG_BASE + 0x0000)
#define		REG_GMAC_FRAME_FILTER		(GMAC_REG_BASE + 0x0004)
#define		REG_GMAC_GMII_ADDRESS		(GMAC_REG_BASE + 0x0010)
#define		REG_GMAC_GMII_DATA			(GMAC_REG_BASE + 0x0014)
#define		REG_GMAC_DEBUG				(GMAC_REG_BASE + 0x0024)
#define		REG_GMAC_MAC_HIGH 			(GMAC_REG_BASE + 0x0040)
#define		REG_GMAC_MAC_LOW 			(GMAC_REG_BASE + 0x0044)

//GMAC-DMA
#define		REG_GMAC_BUS_MODE			(GMAC_REG_BASE + 0x1000)
#define		REG_GMAC_TX_POLL_DEMAND		(GMAC_REG_BASE + 0x1004)
#define		REG_GMAC_RX_POLL_DEMAND		(GMAC_REG_BASE + 0x1008)
#define		REG_GMAC_RX_DESC_ADDR		(GMAC_REG_BASE + 0x100C)
#define		REG_GMAC_TX_DESC_ADDR		(GMAC_REG_BASE + 0x1010)
#define		REG_GMAC_STATUS				(GMAC_REG_BASE + 0x1014)
#define		REG_GMAC_OP_MODE			(GMAC_REG_BASE + 0x1018)
#define		REG_GMAC_INTR_EN			(GMAC_REG_BASE + 0x101C)
#define		REG_GMAC_ERROR_COUNT		(GMAC_REG_BASE + 0x1020)
#define		REG_GMAC_AXI_BUS_MODE		(GMAC_REG_BASE + 0x1028)
#define		REG_GMAC_AXI_STATUS			(GMAC_REG_BASE + 0x102C)
#define 	REG_GMAC_CURR_TX_DESC		(GMAC_REG_BASE + 0x1048)
#define 	REG_GMAC_CURR_RX_DESC		(GMAC_REG_BASE + 0x104C)



void bigLittleSwap(UINT8* buf, int start)
{
	UINT8 tmp, tmp1;
	tmp = buf[start];
	tmp1 = buf[start+1];
	buf[start] = buf[start+3];
	buf[start+1] = buf[start+2];
	buf[start+2] = tmp1;
	buf[start+3] = tmp;
}

void SwapEndianess(UINT8* buf, int size)
{
	int i;
	for(i=0; i<size/4; i++)
	{
		bigLittleSwap(buf, i*4);
	}
}


Gmac_Object* pGmac;



static void GMAC_SetPhyRegister(int regNum, UINT32 data)
{

	SET_REG(REG_GMAC_GMII_DATA, data);
	
	//gmii_write = 1
	//physical_layer_address = PHYT_ID
	//csr_clock_range = gmac_gmii_clock_100_150
	//gmii_register = regNum
	//gmii_busy = 1
	SET_REG(REG_GMAC_GMII_ADDRESS, 0x1<<1 | PHYT_ID<<11 | gmac_gmii_clock_100_150<<2 | regNum<<6 | 0x1);
	
	while(GET_REG(REG_GMAC_GMII_ADDRESS) & 0x1)
	{

	}
	
}

static UINT32 GMAC_GetPhyRegister(int regNum)
{
	
	//gmii_write = 0
	//physical_layer_address = PHYT_ID
	//csr_clock_range = gmac_gmii_clock_100_150
	//gmii_register = regNum
	//gmii_busy = 1
	SET_REG(REG_GMAC_GMII_ADDRESS, PHYT_ID<<11 | gmac_gmii_clock_100_150<<2 | regNum<<6 | 0x1);
	
	while(GET_REG(REG_GMAC_GMII_ADDRESS) & 0x1)
	{

	}
	
	return GET_REG(REG_GMAC_GMII_DATA);
}

void GMAC_CheckErrors()
{
	UINT32 phySymbolErrorCounter = GMAC_GetPhyRegister(26);
	UINT32 dmaStatus = GET_REG(REG_GMAC_STATUS);
	UINT32 missed = GET_REG(REG_GMAC_ERROR_COUNT);
	if(dmaStatus & 0xa0b2)
	{
		//fatal bus error, read Error Bits status[25:23]
		//or
		//abnormal interrupt
		int a;
		a++;
		return;
	}
	int a;
	a++;
}

static void GMAC_DmaTxDescriptorInit(void)
{
	pGmac->tx_dma_descriptors->desc0.dw = 0;
	pGmac->tx_dma_descriptors->desc1.dw = 0;
	pGmac->tx_dma_descriptors->desc2.dw = 0;
	pGmac->tx_dma_descriptors->desc3.dw = 0;
	pGmac->tx_dma_descriptors->desc1.bit.first_segment = 1;
	pGmac->tx_dma_descriptors->desc1.bit.last_segment = 1;
	pGmac->tx_dma_descriptors->desc1.bit.end_of_ring = 1;
	pGmac->tx_dma_descriptors->desc1.bit.second_address_chained = 1;
	pGmac->tx_dma_descriptors->desc3.bit.buffer_address_pointer = (UINT32)pGmac->tx_dma_descriptors;
}
#ifdef MULT_DESC
static void GMAC_DmaRxDescriptorInit(void)
{
	pGmac->rx_dma_descriptors0->desc0.dw = 0;
	pGmac->rx_dma_descriptors0->desc1.dw = 0;
	pGmac->rx_dma_descriptors0->desc2.dw = 0;
	pGmac->rx_dma_descriptors0->desc3.dw = 0;
	pGmac->rx_dma_descriptors0->desc1.bit.buffer1_size = 2000;
	pGmac->rx_dma_descriptors0->desc1.bit.end_of_ring = 0;
	pGmac->rx_dma_descriptors0->desc1.bit.second_address_chained = 1;
	pGmac->rx_dma_descriptors0->desc3.bit.buffer_address_pointer = (UINT32)pGmac->rx_dma_descriptors1;

	//pGmac->rx_dma_descriptors0->desc0.bit.own = 1;
	//pGmac->rx_dma_descriptors0->desc2.bit.buffer_address_pointer = (UINT32)(0xa0009000);

	pGmac->rx_dma_descriptors1->desc0.dw = 0;
	pGmac->rx_dma_descriptors1->desc1.dw = 0;
	pGmac->rx_dma_descriptors1->desc2.dw = 0;
	pGmac->rx_dma_descriptors1->desc3.dw = 0;
	pGmac->rx_dma_descriptors1->desc1.bit.buffer1_size = 2000;
	pGmac->rx_dma_descriptors1->desc1.bit.end_of_ring = 1;
	pGmac->rx_dma_descriptors1->desc1.bit.second_address_chained = 1;
	pGmac->rx_dma_descriptors1->desc3.bit.buffer_address_pointer = (UINT32)pGmac->rx_dma_descriptors0;

	//pGmac->rx_dma_descriptors1->desc2.bit.buffer_address_pointer = 0xa000a000;
	//pGmac->rx_dma_descriptors1->desc0.bit.own = 1;

}
#else
static void GMAC_DmaRxDescriptorInit(void)
{
	pGmac->rx_dma_descriptors->desc0.dw = 0;
	pGmac->rx_dma_descriptors->desc1.dw = 0;
	pGmac->rx_dma_descriptors->desc2.dw = 0;
	pGmac->rx_dma_descriptors->desc3.dw = 0;
	pGmac->rx_dma_descriptors->desc1.bit.buffer1_size = 2000;
	pGmac->rx_dma_descriptors->desc1.bit.end_of_ring = 1;
	pGmac->rx_dma_descriptors->desc1.bit.second_address_chained = 1;
	pGmac->rx_dma_descriptors->desc3.bit.buffer_address_pointer = (UINT32)pGmac->rx_dma_descriptors;

	/*
	pGmac->rx_dma_descriptors->desc2.bit.buffer_address_pointer = (UINT32)(0xa0009000);
	pGmac->rx_dma_descriptors->desc0.bit.own = 1;
	*/
}
#endif

static void GMAC_GetPhyAutoNegotiationStatus()
{

	if(GMAC_Probe() < 0)
	{
		return;
	}

	Reg_Phyt_Special_Status special_status = {0};
	Reg_Phyt_Basic_Status basic_status = {0};

	while(!special_status.bit.auto_done)
	{
		special_status.dw = GMAC_GetPhyRegister(gmac_phyt_reg_special_status);
	}


	while(!basic_status.bit.link_status)
	{
		basic_status.dw = GMAC_GetPhyRegister(gmac_phyt_reg_basic_status);
	}


	pGmac->full_duplex = special_status.bit.speed_indication >> 2;
	pGmac->speed_100m = (special_status.bit.speed_indication >> 1) & 0x1;


/*
	Reg_Phyt_Special_Status special_status = {0};
	Reg_Phyt_Basic_Status basic_status = {0};

	basic_status.dw = GMAC_GetPhyRegister(gmac_phyt_reg_basic_ctrl);
	special_status.dw = GMAC_GetPhyRegister(gmac_phyt_reg_special_status);

	GMAC_SetPhyRegister(gmac_phyt_reg_basic_ctrl, 0x0);
	GMAC_SetPhyRegister(gmac_phyt_reg_special_status, 0x0);

	special_status.dw = 0;
	basic_status.dw = 0;

	basic_status.dw = GMAC_GetPhyRegister(gmac_phyt_reg_basic_ctrl);
	special_status.dw = GMAC_GetPhyRegister(gmac_phyt_reg_special_status);
*/

/*
	UINT32 ctrl = 0;
	ctrl = GMAC_GetPhyRegister(gmac_phyt_reg_basic_ctrl);
	//GMAC_SetPhyRegister(gmac_phyt_reg_basic_ctrl, 0x7000);
	ctrl = GMAC_GetPhyRegister(gmac_phyt_reg_basic_ctrl);

	pGmac->full_duplex = 1;
	pGmac->speed_100m = 1;
*/

}

int GMAC_Probe(void)
{
	UINT32 phyReg2, phyReg3, ouiVal;
	phyReg2 = GMAC_GetPhyRegister(gmac_phyt_reg_phy_id1);
	phyReg3 = GMAC_GetPhyRegister(gmac_phyt_reg_phy_id2);

	ouiVal = ((phyReg3 & 0xfc00) << 6) | phyReg2;

	if(ouiVal == PHYT_OUI)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void GMAC_DmaInit(void)
{
	SET_REG(0xf0400000, 2);

	//software reset
	SET_REG(REG_GMAC_BUS_MODE, 0x1);


	//wait for reset complete
	while(GET_REG(REG_GMAC_BUS_MODE) & 0x1)
	{

	}
	

	UINT32 axi_status;
	//confirm that all previously initiated (before software-reset) or ongoing AHB or AXI transactions are complete.
	while(GET_REG(REG_GMAC_AXI_STATUS) & 0x3)
	{
		axi_status = GET_REG(REG_GMAC_AXI_STATUS);
	}
	
	//initialize dma bus mode reg0
	//address_aligned_beats
	//fixed_burst
	//burst_length = 32
	SET_REG(REG_GMAC_BUS_MODE, 1<<25 | 1<<16 | 32<<8);
	
	
	//init dma descriptor reg 3 & 4
	GMAC_DmaTxDescriptorInit();
	GMAC_DmaRxDescriptorInit();

#ifdef MULT_DESC
	SET_REG(REG_GMAC_RX_DESC_ADDR, (UINT32)pGmac->rx_dma_descriptors0);
	SET_REG(REG_GMAC_TX_DESC_ADDR, (UINT32)pGmac->tx_dma_descriptors);
#else
	SET_REG(REG_GMAC_RX_DESC_ADDR, (UINT32)pGmac->rx_dma_descriptors);
	SET_REG(REG_GMAC_TX_DESC_ADDR, (UINT32)pGmac->tx_dma_descriptors);
#endif
	
	//op mode, reg 6
	//transmit_store_forward
	//receive_store_forward
	//operate_on_second_frame
	SET_REG(REG_GMAC_OP_MODE, 1<<25 | 1<<21 | 0<<2);

	
	//clear & disable all interrupts
	SET_REG(REG_GMAC_STATUS, 0xffffffff);

	//After a hardware or software reset, all interrupts are disabled
	//normal_interrupt_summary
	//receive_complete
	//SET_REG(REG_GMAC_INTR_EN, 1<<16 | 1<<15 | 1<<7 | 1<<6);
	SET_REG(REG_GMAC_INTR_EN, 0xfffffeff);
	
	//start tx & rx
	//start_stop_receive
	//start_stop_transmission_cmd
	//SET_REG(REG_GMAC_OP_MODE, 1<<13 | 1<<1);

}

void GMAC_SetMacAddress(UINT8* mac)
{

	UINT32 macHigh = mac[5]<<8 | mac[4];
	UINT32 macLow = mac[3]<<24 | mac[2]<<16 | mac[1]<<8 | mac[0];

	SET_REG(REG_GMAC_MAC_HIGH, macHigh);
	SET_REG(REG_GMAC_MAC_LOW, macLow);
}

void GMAC_MacInit(void)
{
	SET_REG(0xf0400000, 3);

	//reset
	//GMAC_SetPhyRegister(gmac_phyt_reg_basic_ctrl, 0x1);

	GMAC_GetPhyAutoNegotiationStatus();

	GMAC_SetMacAddress(pGmac->local_mac_address);

	//receive all frames without any filters
	//SET_REG(REG_GMAC_FRAME_FILTER, 1<<31);
	SET_REG(REG_GMAC_FRAME_FILTER, 1<<5);
	
	//reg6 flow control
	
	//interrupt
	
	//set reg0
	//auto_pad_crc_stripping
	//duplex_mode
	//speed
	//port_select = MII
	//transmitter_enable
	//receiver_enable
	//SET_REG(REG_GMAC_CONFIG, 1<<12 | 1<<15 | pGmac->speed_100m<<14 | pGmac->full_duplex<<11 | 1<<7 | 1<<3 | 1<<2);
	SET_REG(REG_GMAC_CONFIG, 1<<15 | pGmac->speed_100m<<14 | pGmac->full_duplex<<11 | 1<<7 | 1<<3 | 1<<2);
/*
	UINT32 basic = GMAC_GetPhyRegister(0);
	basic = basic | 0x4000;
	GMAC_SetPhyRegister(0, basic);
*/
}

void GMAC_Halt(void)
{
	//reset
	//GMAC_SetPhyRegister(gmac_phyt_reg_basic_ctrl, 0x1);
	//power down
	GMAC_SetPhyRegister(gmac_phyt_reg_basic_ctrl, 0x800);
	//clear & disable interrupts
	SET_REG(REG_GMAC_STATUS, 0xffffffff);
	SET_REG(REG_GMAC_INTR_EN, 0x0);
	//tx & rx disable
	SET_REG(REG_GMAC_CONFIG, 0<<3 | 0<<2);
}

int GMAC_Send(volatile void *packet, int length)
{
	pGmac->tx_dma_descriptors->desc1.bit.buffer1_size = length;

	pGmac->tx_dma_descriptors->desc2.bit.buffer_address_pointer = (UINT32)packet;

	pGmac->tx_dma_descriptors->desc0.bit.own = 1;

	SET_REG_M(REG_GMAC_OP_MODE, 1<<13, 1<<13);

	SET_REG(REG_GMAC_TX_POLL_DEMAND, 0);


	UINT32 status;
	while(pGmac->tx_dma_descriptors->desc0.bit.own)
	{
		status = GET_REG(REG_GMAC_STATUS);
		if(status & 0x20b2)
		{
			//fatal bus error, read Error Bits status[25:23]
			//or
			//abnormal interrupt
			return -1;
		}
	}

	if(pGmac->tx_dma_descriptors->desc0.bit.error_summary)
	{
		return -2;

	}
	SET_REG_M(REG_GMAC_OP_MODE, 0<<13, 1<<13);
	return 0;
}

#ifdef USE_INTERRUPT

void GMAC_StartReceiving(Gmac_Frame* frame)
{
	//start_stop_receive
	pGmac->rx_dma_descriptors->desc2.bit.buffer_address_pointer = (UINT32)(frame);
	pGmac->rx_dma_descriptors->desc0.dw = 0;
	pGmac->rx_dma_descriptors->desc0.bit.own = 1;
	SET_REG_M(REG_GMAC_OP_MODE, 1<<1, 1<<1);
	SET_REG(REG_GMAC_RX_POLL_DEMAND, 0);
}

void GMAC_StopReceiving()
{
	SET_REG_M(REG_GMAC_OP_MODE, 0<<1, 1<<1);
}

void GMAC_InterruptHandler()
{
	UINT32 status = GET_REG(REG_GMAC_STATUS);
	//normal interrupt summary
	if(status & 0x10000)
	{
		if(status & 0x40)
		{
			if(pGmac->rx_dma_descriptors->desc0.bit.error_summary)
			{
				SET_REG(0xa0000100, 0xdddd);
			}

			//not finished yet
			if(!pGmac->rx_dma_descriptors->desc0.bit.last_descriptor)
			{
				SET_REG(0xa0000100, 0xeee);
			}

			if(pGmac->rx_dma_descriptors->desc0.bit.da_filter_fail)
			{
				SET_REG(0xa0000500, 0x99999999);
			}

			if(pGmac->rx_dma_descriptors->desc0.bit.sa_filter_fail)
			{
				SET_REG(0xa0000500, 0x88888888);
			}
/*
			Gmac_Frame* frame = (Gmac_Frame*)( pGmac->rx_dma_descriptors->desc2.bit.buffer_address_pointer );
			frame->length_type = pGmac->rx_dma_descriptors->desc0.bit.frame_length;
			GMAC_SendOneFrame(frame);
*/

			pGmac->rx_dma_descriptors->desc0.bit.own = 1;
			//SET_REG(REG_GMAC_RX_POLL_DEMAND, 0);
			SET_REG_M(REG_GMAC_STATUS, 0x40, 0x40);

			Gmac_Frame* frame = (Gmac_Frame*)( pGmac->rx_dma_descriptors->desc2.bit.buffer_address_pointer );
			//frame->length_type = pGmac->rx_dma_descriptors->desc0.bit.frame_length;
			GMAC_SendOneFrame(frame,pGmac->rx_dma_descriptors->desc0.bit.frame_length);
		}
		SET_REG_M(REG_GMAC_STATUS, 0x10000, 0x10000);
	}
	if(status & 0x8000)
	{
		SET_REG(0xf0400000, 0x0badc0de);
		if(status & 0x80)
		{
			SET_REG_M(REG_GMAC_STATUS, 0x80, 0x80);
		}
		SET_REG_M(REG_GMAC_STATUS, 0x8000, 0x8000);
	}


}

#else

void GMAC_ReceiveOneFrame(volatile Gmac_Frame* frame)
{

#ifdef MULT_DESC

	SET_REG(REG_GMAC_STATUS, 0xffffffff);
	pGmac->rx_dma_descriptors0->desc2.bit.buffer_address_pointer = (UINT32)(frame);
	pGmac->rx_dma_descriptors0->desc0.dw = 0;
	pGmac->rx_dma_descriptors0->desc0.bit.own = 1;
	//SET_REG_M(REG_GMAC_OP_MODE, 1<<1, 1<<1);
	SET_REG(REG_GMAC_RX_POLL_DEMAND, 0);

	//wait for finish
	UINT32 error;
	UINT32 status = 0;
	UINT32 debug;
	while(pGmac->rx_dma_descriptors0->desc0.bit.own)
	{

		status = GET_REG(REG_GMAC_STATUS);
		if(status & 0xa0b2)
		{
			break;
		}
	}

	UINT32 statusa = 0;
	statusa = GET_REG(REG_GMAC_STATUS);
	UINT32 statusb = 0;
	statusb = GET_REG(REG_GMAC_STATUS);
	//SET_REG_M(REG_GMAC_OP_MODE, 0<<1, 1<<1);

	UINT32 statusc = 0;
	statusc = GET_REG(REG_GMAC_STATUS);

	if(statusc & 0xa0b2)
	{
		int a;
		a++;
	}


#else
	SET_REG(REG_GMAC_STATUS, 0xffffffff);
	pGmac->rx_dma_descriptors->desc2.bit.buffer_address_pointer = (UINT32)(frame);
	pGmac->rx_dma_descriptors->desc0.dw = 0;
	pGmac->rx_dma_descriptors->desc0.bit.own = 1;
	//SET_REG_M(REG_GMAC_OP_MODE, 1<<1, 1<<1);
	SET_REG(REG_GMAC_RX_POLL_DEMAND, 0);
	
	//wait for finish
	UINT32 error;
	UINT32 status = 0;
	UINT32 debug;
	while(pGmac->rx_dma_descriptors->desc0.bit.own)
	{

		status = GET_REG(REG_GMAC_STATUS);
		if(status & 0xa0b2)
		{
			//UINT32 missed2 = 0;
			//missed2 = GET_REG(REG_GMAC_ERROR_COUNT);
			//fatal bus error, read Error Bits status[25:23]
			//or
			//abnormal interrupt
			break;
		}
		/*
		SET_REG(0xa0000000, pGmac->rx_dma_descriptors->desc0.dw);

		error = GET_REG(REG_GMAC_ERROR_COUNT);
		status = GET_REG(REG_GMAC_STATUS);
		debug = GET_REG(REG_GMAC_DEBUG);

		SET_REG(0xa0000000, error);
		SET_REG(0xa0000000, 0x44);
		SET_REG(0xa0000000, status);
		SET_REG(0xa0000000, 0x55);
		SET_REG(0xa0000000, debug);
		 */
		//SET_REG(0xf0400000, GET_REG(REG_GMAC_STATUS));
		/*
		 * 0x1014,status,0x678084,running,wait for receive packet
		 * 0x1014,status,0x6f8084,running,transferring the receive packet data from receive buffer to host memory
		 * 0x1014,status,0x6980c4,suspended,receive descriptor unavailable
		 */

	}

/*
	while(status & 0xe0000)
	{
		status = GET_REG(REG_GMAC_STATUS);
	}
*/
	UINT32 statusa = 0;
	statusa = GET_REG(REG_GMAC_STATUS);
/*
	if(pGmac->rx_dma_descriptors->desc0.bit.error_summary)
	{
		//SET_REG(0xa0000100, 0xdddd);
		
	}
*/
	UINT32 statusb = 0;
	statusb = GET_REG(REG_GMAC_STATUS);
	//not finished yet
	if(!pGmac->rx_dma_descriptors->desc0.bit.last_descriptor)
	{
		//SET_REG(0xa0000100, 0xeee);
		//gmac_obj->rx_dma_descriptors->desc2.bit.buffer_address_pointer = (UINT32)buffer;
		//gmac_obj->rx_dma_descriptors->desc0.bit.own = 1;
		//gmac_obj->dma_module->receive_poll_demand.dw = 0;
	}
		
	//frame->length_type = pGmac->rx_dma_descriptors->desc0.bit.frame_length;

	//SET_REG_M(REG_GMAC_OP_MODE, 0<<1, 1<<1);

	UINT32 statusc = 0;
	statusc = GET_REG(REG_GMAC_STATUS);

	//UINT32 missed = 0;
	//missed = GET_REG(REG_GMAC_ERROR_COUNT);
	if(statusc & 0xa0b2)
	{
		int a;
		a++;
	}

	//SwapEndianess((UINT8*)frame, pGmac->rx_dma_descriptors->desc0.bit.frame_length);
#endif
}
#endif

void GMAC_SendOneFrame(Gmac_Frame* frame, int size)
{
	//SET_REG(0xa0000100, 0x5678);


	pGmac->tx_dma_descriptors->desc1.bit.buffer1_size = size;


	//SwapEndianess((UINT8*)frame, pGmac->tx_dma_descriptors->desc1.bit.buffer1_size);

	pGmac->tx_dma_descriptors->desc2.bit.buffer_address_pointer = (UINT32)frame;

	pGmac->tx_dma_descriptors->desc0.bit.own = 1;

	SET_REG_M(REG_GMAC_OP_MODE, 1<<13, 1<<13);

	SET_REG(REG_GMAC_TX_POLL_DEMAND, 0);


	//wait for finish
	UINT32 error;
	UINT32 status;
	UINT32 debug;
	while(pGmac->tx_dma_descriptors->desc0.bit.own)
	{
		SET_REG(0xa0000000, pGmac->tx_dma_descriptors->desc0.dw);

		error = GET_REG(REG_GMAC_ERROR_COUNT);
		status = GET_REG(REG_GMAC_STATUS);
		debug = GET_REG(REG_GMAC_DEBUG);

		SET_REG(0xa0000000, error);
		SET_REG(0xa0000000, 0x44);
		SET_REG(0xa0000000, status);
		SET_REG(0xa0000000, 0x55);
		SET_REG(0xa0000000, debug);
		//SET_REG(0xf0400000, GET_REG(REG_GMAC_STATUS));
		//SET_REG(0xf0400000, pGmac->tx_dma_descriptors->desc0.dw);
	}

	SET_REG(0xf0400000, 0xe2dc0de);

	if(pGmac->tx_dma_descriptors->desc0.bit.error_summary)
	{
		//SET_REG(0xa0000100, 0xdddd);

	}
	SET_REG_M(REG_GMAC_OP_MODE, 0<<13, 1<<13);
	SET_REG(0xf0400000, 0x12344123);
}

void GMAC_Init(Gmac_Object* gmac_obj)
{
	//SET_REG(0xa0000100, 0);
	pGmac = gmac_obj;
	GMAC_DmaInit();
	GMAC_MacInit();


#ifdef USE_INTERRUPT
	IntrFuncLow[17] = GMAC_InterruptHandler;
	SET_REG(0xa0000900, 0x77777777);
	SET_REG(0xa0000900, (UINT32)GMAC_InterruptHandler);
	SET_REG(0xa0000900, (UINT32)IntrFuncLow[17]);
#endif


}

#ifdef MULT_DESC
void GMAC_ReceiveFrames(volatile Gmac_Frame* frame)
{

	SET_REG(REG_GMAC_STATUS, 0xffffffff);
	pGmac->rx_dma_descriptors0->desc2.bit.buffer_address_pointer = (UINT32)(frame);
	pGmac->rx_dma_descriptors0->desc0.dw = 0;
	pGmac->rx_dma_descriptors0->desc0.bit.own = 1;

	pGmac->rx_dma_descriptors1->desc2.bit.buffer_address_pointer = (UINT32)(0xa000a000);
	pGmac->rx_dma_descriptors1->desc0.dw = 0;
	pGmac->rx_dma_descriptors1->desc0.bit.own = 1;
	SET_REG_M(REG_GMAC_OP_MODE, 1<<1, 1<<1);
	SET_REG(REG_GMAC_RX_POLL_DEMAND, 0);

	//wait for finish
	UINT32 error;
	UINT32 status = 0;
	UINT32 debug;
	while(pGmac->rx_dma_descriptors0->desc0.bit.own)
	{

		status = GET_REG(REG_GMAC_STATUS);
		if(status & 0xa0b2)
		{
			break;
		}
	}

	UINT32 statusa = 0;
	statusa = GET_REG(REG_GMAC_STATUS);
	UINT32 statusb = 0;
	statusb = GET_REG(REG_GMAC_STATUS);
	SET_REG_M(REG_GMAC_OP_MODE, 0<<1, 1<<1);

	UINT32 statusc = 0;
	statusc = GET_REG(REG_GMAC_STATUS);

	if(statusc & 0xa0b2)
	{
		int a;
		a++;
	}

}
#endif
