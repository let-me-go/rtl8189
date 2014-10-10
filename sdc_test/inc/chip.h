/*****************************************************************************
*
*                                  chip.h
*
*	Copyright (c) 2010 Shanghai Fullhan Microelectronics Co., Ltd.
*						All Rights Reserved. Confidential.
*
*	File Description:
*		Chip definition. Include the base address of each module, memory
*		address, memory size
*
*	Modification History:
*
******************************************************************************/
#ifndef _CHIP_H_
#define _CHIP_H_

/* Includes -----------------------------------------------------------------*/
/* Public typedef -----------------------------------------------------------*/

/* Public define ------------------------------------------------------------*/
// memory base address: <memName>_BASE
#define		RAM_BASE			(0x9A700000)
#define		TAE_SDRAM_BASE		(0x9B800000)
#define		SDRAM_BASE			(0x9C800000)
#define		DCCM_BASE			(0x40000000)
#define		ICCM_BASE			(0x00000000)

// module register base address: <moduleName>_REG_BASE
#define		INTC_REG_BASE		(0xE0200000)
#define 	GMAC_REG_BASE		(0xEF000000)
#define		AHBC_REG_BASE		(0x9A000000)
#define		AIF_REG_BASE		(0x9A100000)
#define		DMAC_REG_BASE		(0xee000000)
#define		ISP_REG_BASE		(0x9A600000)
#define		TAE_REG_BASE		(0x9B000000)

#define		SDC0_REG_BASE		(0xe2000000)
#define		SDC1_REG_BASE		(0xe2100000)
#define		JPEG_REG_BASE		(0x9A800000)

#define		PMU_REG_BASE		(0x98000000)
#define		WDT_REG_BASE		(0xf0d00000)
#define		TMR_REG_BASE		(0x98400000)
#define		GPIO_REG_BASE		(0xf0300000)
#define		I2C_REG_BASE		(0xf0200000)
#define		UART0_REG_BASE		(0x98700000)
#define		UART1_REG_BASE		(0x98800000)
#define		I2S_REG_BASE		(0x99000000)
#define		SPI0_REG_BASE		(0x99100000)
#define		SPI1_REG_BASE		(0x99200000)
#define		SPI2_REG_BASE		(0x99300000)
#define		PWM_REG_BASE		(0x99400000)
#define		RTC_REG_BASE		(0x99500000)

//@to do:从FH52移植过来，需要对照FH61的ISP修改
#define 	IPB_REG_BASE			(0x91280000)
#define 	IPF_REG_BASE			(0x91200000)
//移植自FH61
#define 	DMA_REG_BASE				(0x9a400000)
#define 	SDRAM_REG_BASE 				(0x9B800000)
/* Public function ----------------------------------------------------------*/

#endif
