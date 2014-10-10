/*****************************************************************************
*
*                                  chip_reg.h
*
*   Copyright (c) 2010 Shanghai Fullhan Microelectronics Co., Ltd.
*                       All Rights Reserved. Confidential.
*
*   File Description:
*       Chip register definition of the whole chip.
*       Include the address of each hardware register
*
*   Modification History:
*
******************************************************************************/
#ifndef _CHIP_REG_H_
#define _CHIP_REG_H_

/* Includes -----------------------------------------------------------------*/
#include "chip.h"

/* Public typedef -----------------------------------------------------------*/
/* Public define ------------------------------------------------------------*/
//AHBC
//AIF
#define 	ACW_INTERVAL									0x0 

#define		REG_ACW_CTRL_OFFSET						(0x0000)
#define 	REG_ACW_TXFIFO_CTRL_OFFSET		(0x0004)
#define		REG_ACW_RXFIFO_CTRL_OFFSET		(0x0008)
#define		REG_ACW_CODEC_CTRL_OFFSET			(0x000C)
#define 	REG_ACW_STA_OFFSET 						(0x0010)
#define		REG_ACW_TXFIFO_ADDR_OFFSET		(0x0100)
#define 	REG_ACW_RXFIFO_ADDR_OFFSET		(0x0200)


#define		REG_ACW_CTRL(n)						(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_CTRL_OFFSET)
#define 	REG_ACW_TXFIFO_CTRL(n)		(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_TXFIFO_CTRL_OFFSET)
#define		REG_ACW_RXFIFO_CTRL(n)		(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_RXFIFO_CTRL_OFFSET)
#define		REG_ACW_CODEC_CTRL(n)			(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_CODEC_CTRL_OFFSET)
#define 	REG_ACW_STA(n) 						(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_STA_OFFSET)
#define		REG_ACW_TXFIFO_ADDR(n)		(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_TXFIFO_ADDR_OFFSET)
#define 	REG_ACW_RXFIFO_ADDR(n)		(AIF_REG_BASE + ((n) * ACW_INTERVAL) + REG_ACW_RXFIFO_ADDR_OFFSET)
//gpio
#define		REG_GPIO_SWPORTA_DR			(GPIO_REG_BASE + 0x0000)
#define		REG_GPIO_SWPORTA_DDR		(GPIO_REG_BASE + 0x0004)
#define		REG_GPIO_PORTA_CTL			(GPIO_REG_BASE + 0x0008)
#define		REG_GPIO_INTEN				(GPIO_REG_BASE + 0x0030)
#define		REG_GPIO_INTMASK			(GPIO_REG_BASE + 0x0034)
#define		REG_GPIO_INTTYPE_LEVEL		(GPIO_REG_BASE + 0x0038)
#define		REG_GPIO_INT_POLARITY		(GPIO_REG_BASE + 0x003C)
#define		REG_GPIO_INTSTATUS			(GPIO_REG_BASE + 0x0040)
#define		REG_GPIO_RAWINTSTATUS		(GPIO_REG_BASE + 0x0044)
#define		REG_GPIO_DEBOUNCE			(GPIO_REG_BASE + 0x0048)
#define		REG_GPIO_PORTA_EOI			(GPIO_REG_BASE + 0x004C)
#define		REG_GPIO_EXT_PORTA			(GPIO_REG_BASE + 0x0050)

#define		REG_IRQ_EN_LOW				(INTC_REG_BASE + 0x0000)
#define		REG_IRQ_EN_HIGH				(INTC_REG_BASE + 0x0004)
#define		REG_IRQ_IRQMASK_LOW			(INTC_REG_BASE + 0x0008)
#define		REG_IRQ_IRQMASK_HIGH		(INTC_REG_BASE + 0x000C)
#define		REG_IRQ_IRQFORCE_LOW		(INTC_REG_BASE + 0x0010)
#define		REG_IRQ_IRQFORCE_HIGH		(INTC_REG_BASE + 0x0014)
#define		REG_IRQ_RAWSTATUS_LOW		(INTC_REG_BASE + 0x0018)
#define		REG_IRQ_RAWSTATUS_HIGH		(INTC_REG_BASE + 0x001C)
#define		REG_IRQ_STATUS_LOW			(INTC_REG_BASE + 0x0020)
#define		REG_IRQ_STATUS_HIGH			(INTC_REG_BASE + 0x0024)
#define		REG_IRQ_MASKSTATUS_LOW		(INTC_REG_BASE + 0x0028)
#define		REG_IRQ_MASKSTATUS_HIGH		(INTC_REG_BASE + 0x002C)
#define		REG_IRQ_FINSTATUS_LOW		(INTC_REG_BASE + 0x0030)
#define		REG_IRQ_FINSTATUS_HIGH		(INTC_REG_BASE + 0x0034)

#define		REG_FIQ_EN_LOW				(INTC_REG_BASE + 0x02C0)
#define		REG_FIQ_EN_HIGH				(INTC_REG_BASE + 0x02C4)
#define		REG_FIQ_FIQMASK_LOW			(INTC_REG_BASE + 0x02C8)
#define		REG_FIQ_FIQMASK_HIGH		(INTC_REG_BASE + 0x02CC)
#define		REG_FIQ_FIQFORCE_LOW		(INTC_REG_BASE + 0x02D0)
#define		REG_FIQ_FIQFORCE_HIGH		(INTC_REG_BASE + 0x02D4)
#define		REG_FIQ_RAWSTATUS_LOW		(INTC_REG_BASE + 0x02D8)
#define		REG_FIQ_RAWSTATUS_HIGH		(INTC_REG_BASE + 0x02DC)
#define		REG_FIQ_STATUS_LOW			(INTC_REG_BASE + 0x02E0)
#define		REG_FIQ_STATUS_HIGH			(INTC_REG_BASE + 0x02E4)
#define		REG_FIQ_FINSTATUS_LOW		(INTC_REG_BASE + 0x02E8)
#define		REG_FIQ_FINSTATUS_HIGH		(INTC_REG_BASE + 0x02EC)

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


//ISP
#define     REG_ISP_IP_VER_INFO         (ISP_REG_BASE + 0x0000)
#define     REG_ISP_INT_STATUS          (ISP_REG_BASE + 0x0004)
#define     REG_ISP_INT_EN              (ISP_REG_BASE + 0x0008)
#define     REG_ISP_PROC_STATUS         (ISP_REG_BASE + 0x000C)
#define     REG_ISP_PKG_CFG             (ISP_REG_BASE + 0x0010)
#define     REG_ISP_PKG_ADDR            (ISP_REG_BASE + 0x0014)
#define     REG_ISP_PKG_ID              (ISP_REG_BASE + 0x0018)
#define     REG_ISP_RD_BUFF_CFG0        (ISP_REG_BASE + 0x001C)
#define     REG_ISP_RD_BUFF_CFG1        (ISP_REG_BASE + 0x0020)
#define     REG_ISP_WR_BUFF_CFG0        (ISP_REG_BASE + 0x0024)
#define     REG_ISP_PIC_IN_INFO         (ISP_REG_BASE + 0x0028)
#define     REG_ISP_ENABLE_CFG          (ISP_REG_BASE + 0x002C)
#define     REG_ISP_CLP_CFG             (ISP_REG_BASE + 0x0030)
#define     REG_ISP_CLP_PIC_INFO        (ISP_REG_BASE + 0x0034)
#define     REG_ISP_GAIN_INFO0          (ISP_REG_BASE + 0x0038)
#define     REG_ISP_GAIN_INFO1          (ISP_REG_BASE + 0x003C)
#define     REG_ISP_BL_COMP_INFO0       (ISP_REG_BASE + 0x0040)
#define     REG_ISP_BL_COMP_INFO1       (ISP_REG_BASE + 0x0044)
#define     REG_ISP_NR_CFG0             (ISP_REG_BASE + 0x0048)
#define     REG_ISP_NR_CFG1             (ISP_REG_BASE + 0x004C)
#define     REG_ISP_NR_WEIGHT           (ISP_REG_BASE + 0x0050)
#define     REG_ISP_NR_COEFF_ADDR       (ISP_REG_BASE + 0x0070)
#define     REG_ISP_NR_COEFF_SIZE       (ISP_REG_BASE + 0x0074)
#define     REG_ISP_NR_FRAME_ADDR       (ISP_REG_BASE + 0x0078)
#define     REG_ISP_NR_FRAME_SIZE       (ISP_REG_BASE + 0x007C)
#define     REG_ISP_NR_DPC_INFO         (ISP_REG_BASE + 0x0080)
#define     REG_ISP_NR_CFG2             (ISP_REG_BASE + 0x0084)
#define     REG_ISP_NR_INFO0            (ISP_REG_BASE + 0x0088)
#define     REG_ISP_NR_INFO1            (ISP_REG_BASE + 0x008C)
#define     REG_ISP_NR_INFO2            (ISP_REG_BASE + 0x0090)
#define     REG_ISP_NR_INFO3            (ISP_REG_BASE + 0x0094)
#define     REG_ISP_NR3D_INFO0          (ISP_REG_BASE + 0x0098)
#define     REG_ISP_CFA_CFG             (ISP_REG_BASE + 0x009C)
#define     REG_ISP_WB_GAIN_INFO0       (ISP_REG_BASE + 0x00A0)
#define     REG_ISP_WB_GAIN_INFO1       (ISP_REG_BASE + 0x00A4)
#define     REG_ISP_WB_OFFSET_INFO0     (ISP_REG_BASE + 0x00A8)
#define     REG_ISP_WB_OFFSET_INFO1     (ISP_REG_BASE + 0x00AC)
#define     REG_ISP_RGBB_INFO0          (ISP_REG_BASE + 0x00B0)
#define     REG_ISP_RGBB_INFO1          (ISP_REG_BASE + 0x00B4)
#define     REG_ISP_RGBB_INFO2          (ISP_REG_BASE + 0x00B8)
#define     REG_ISP_RGBB_INFO3          (ISP_REG_BASE + 0x00BC)
#define     REG_ISP_RGBB_INFO4          (ISP_REG_BASE + 0x00C0)
#define     REG_ISP_RGBB_INFO5          (ISP_REG_BASE + 0x00C4)
#define     REG_ISP_YC_INFO0            (ISP_REG_BASE + 0x00C8)
#define     REG_ISP_YC_INFO1            (ISP_REG_BASE + 0x00CC)
#define     REG_ISP_YC_INFO2            (ISP_REG_BASE + 0x00D0)
#define     REG_ISP_YC_INFO3            (ISP_REG_BASE + 0x00D4)
#define     REG_ISP_YC_INFO4            (ISP_REG_BASE + 0x00D8)
#define     REG_ISP_YC_INFO5            (ISP_REG_BASE + 0x00DC)
#define     REG_ISP_YC_FILTER_CFG       (ISP_REG_BASE + 0x00E0)
#define     REG_ISP_STAT_WIN_INFO0      (ISP_REG_BASE + 0x00E4)
#define     REG_ISP_STAT_WIN_INFO1      (ISP_REG_BASE + 0x00E8)
#define     REG_ISP_STAT_SAMPLE_INFO    (ISP_REG_BASE + 0x00EC)
#define     REG_ISP_STAT_SUM_CFG        (ISP_REG_BASE + 0x00F0)
#define     REG_ISP_VI_MODE             (ISP_REG_BASE + 0x00F4)
#define     REG_ISP_VI_PORT_MAP_H       (ISP_REG_BASE + 0x00F8)
#define     REG_ISP_VI_PORT_MAP_L       (ISP_REG_BASE + 0x00FC)
#define     REG_ISP_VI_PICCNT           (ISP_REG_BASE + 0x0100)
#define     REG_ISP_SCALER_CFG          (ISP_REG_BASE + 0x0104)
#define     REG_ISP_HSCALER_INFO0       (ISP_REG_BASE + 0x0108)
#define     REG_ISP_HSCALER_INFO1       (ISP_REG_BASE + 0x010C)
#define     REG_ISP_VSCALER_INFO0       (ISP_REG_BASE + 0x0110)
#define     REG_ISP_VSCALER_INFO1       (ISP_REG_BASE + 0x0114)
#define     REG_ISP_SCALER_PIC_INFO0    (ISP_REG_BASE + 0x0118)
#define     REG_ISP_SCALER_PIC_INFO1    (ISP_REG_BASE + 0x011C)
#define     REG_ISP_SCALER_PIC_INFO2    (ISP_REG_BASE + 0x0120)
#define     REG_ISP_SCALER_INIT_PHASE0  (ISP_REG_BASE + 0x0124)
#define     REG_ISP_SCALER_INIT_PHASE1  (ISP_REG_BASE + 0x0128)
#define     REG_ISP_IE_SHARP_P0         (ISP_REG_BASE + 0x012C)
#define     REG_ISP_IE_SHARP_P1         (ISP_REG_BASE + 0x0130)
#define     REG_ISP_IE_SHARP_P2         (ISP_REG_BASE + 0x0134)
#define     REG_ISP_YE_PARA0            (ISP_REG_BASE + 0x0138)
#define     REG_ISP_YE_PARA1            (ISP_REG_BASE + 0x013C)
#define     REG_ISP_CE_SATHUE           (ISP_REG_BASE + 0x0140)
#define     REG_ISP_IE_APC_PARA0        (ISP_REG_BASE + 0x0144)
#define     REG_ISP_IE_APC_PARA1        (ISP_REG_BASE + 0x0148)
#define     REG_ISP_IE_APC_GAIN         (ISP_REG_BASE + 0x014C)
#define     REG_ISP_IE_HAPC_SLICE       (ISP_REG_BASE + 0x0150)
#define     REG_ISP_IE_APC_ESLICE       (ISP_REG_BASE + 0x0154)
#define     REG_ISP_IE_APC_SLICE        (ISP_REG_BASE + 0x0158)
#define     REG_ISP_CMAP_PARA0          (ISP_REG_BASE + 0x015C)
#define     REG_ISP_CMAP_PARA1          (ISP_REG_BASE + 0x0160)
#define     REG_ISP_PM_CFG              (ISP_REG_BASE + 0x0164)
#define     REG_ISP_PM_H                (ISP_REG_BASE + 0x0168)
#define     REG_ISP_PM_V                (ISP_REG_BASE + 0x0178)
#define     REG_ISP_OSD_CFG             (ISP_REG_BASE + 0x0188)
#define     REG_ISP_OSD_CHAR0           (ISP_REG_BASE + 0x018C)
#define     REG_ISP_OSD_STARTPOS        (ISP_REG_BASE + 0x0190)
#define     REG_ISP_OSD_HLPOS0          (ISP_REG_BASE + 0x0194)
#define     REG_ISP_OSD_HLPOS1          (ISP_REG_BASE + 0x0198)
#define     REG_ISP_OSD_COLOR0          (ISP_REG_BASE + 0x019C)
#define     REG_ISP_OSD_COLOR1          (ISP_REG_BASE + 0x01A0)
#define     REG_ISP_OSD_COLOR2          (ISP_REG_BASE + 0x01A4)
#define     REG_ISP_OSD_COLOR3          (ISP_REG_BASE + 0x01A8)
#define     REG_ISP_OSD_TXT             (ISP_REG_BASE + 0x01AC)
#define     REG_ISP_OSD_FNT0            (ISP_REG_BASE + 0x01B0)
#define     REG_ISP_OSD_FNT1            (ISP_REG_BASE + 0x01B4)
#define     REG_ISP_OUT_CFG             (ISP_REG_BASE + 0x01B8)
#define     REG_ISP_DBG_PTS_VI_00       (ISP_REG_BASE + 0x01C0)
#define     REG_ISP_DBG_PTS_VI_01       (ISP_REG_BASE + 0x01C4)
#define     REG_ISP_DBG_PTS_VO_00       (ISP_REG_BASE + 0x01C8)
#define     REG_ISP_DBG_PTS_CNT         (ISP_REG_BASE + 0x01CC)
#define     REG_ISP_DBG_CNT_VI_00       (ISP_REG_BASE + 0x01D0)
#define     REG_ISP_DBG_CNT_VI_01       (ISP_REG_BASE + 0x01D4)
#define     REG_ISP_DBG_CNT_VI_02       (ISP_REG_BASE + 0x01D8)
#define     REG_ISP_DBG_CNT_VI_03       (ISP_REG_BASE + 0x01DC)
#define     REG_ISP_VI_RAWGEN           (ISP_REG_BASE + 0x01E0)
#define     REG_ISP_CGAMMA_INFO         (ISP_REG_BASE + 0x0A00)
#define     REG_ISP_CMAP_INFO           (ISP_REG_BASE + 0x0B00)
#define     REG_ISP_YGAMMA_INFO         (ISP_REG_BASE + 0x0D00)
#define     REG_ISP_YHIST_INFO          (ISP_REG_BASE + 0x0E00)
#define     REG_ISP_STAT_SUM_INFO       (ISP_REG_BASE + 0x1000)
#define     REG_ISP_STAT_MINMAX_INFO    (ISP_REG_BASE + 0x1400)
#define     REG_ISP_SCALER_COEFF_HY     (ISP_REG_BASE + 0x1800)
#define     REG_ISP_SCALER_COEFF_HC     (ISP_REG_BASE + 0x1A00)
#define     REG_ISP_SCALER_COEFF_VY     (ISP_REG_BASE + 0x1C00)
#define     REG_ISP_SCALER_COEFF_VC     (ISP_REG_BASE + 0x1E00)
#define     REG_ISP_STAT_FPN_INFO       (ISP_REG_BASE + 0x2000)
#define     REG_ISP_CLP_FPN_INFO        (ISP_REG_BASE + 0x3000)

//TAE
#define     REG_TAE_VER_INFO            (TAE_REG_BASE + 0x0000)
#define     REG_TAE_INT_STATUS          (TAE_REG_BASE + 0x0004)
#define     REG_TAE_INT_EN              (TAE_REG_BASE + 0x0008)
#define     REG_TAE_ENC_CFG0            (TAE_REG_BASE + 0x000C)
#define     REG_TAE_ENC_CFG1            (TAE_REG_BASE + 0x0010)
#define     REG_TAE_ENC_CFG2            (TAE_REG_BASE + 0x0014)
#define     REG_TAE_ENC_CFG3            (TAE_REG_BASE + 0x0018)
#define     REG_TAE_MIF_CFG0            (TAE_REG_BASE + 0x001C)
#define     REG_TAE_MIF_CFG1            (TAE_REG_BASE + 0x0020)
#define     REG_TAE_MIF_CFG2            (TAE_REG_BASE + 0x0024)
#define     REG_TAE_MIF_CFG3            (TAE_REG_BASE + 0x0028)
#define     REG_TAE_MIF_CFG4            (TAE_REG_BASE + 0x002C)
#define     REG_TAE_STRM_CFG0           (TAE_REG_BASE + 0x0030)
#define     REG_TAE_STRM_CFG1           (TAE_REG_BASE + 0x0034)
#define     REG_TAE_STRM_CFG2           (TAE_REG_BASE + 0x0038)
#define     REG_TAE_STRM_CFG3           (TAE_REG_BASE + 0x003C)
#define     REG_TAE_RC_CFG0             (TAE_REG_BASE + 0x0040)
#define     REG_TAE_RC_CFG1             (TAE_REG_BASE + 0x0044)
#define     REG_TAE_RC_CFG2             (TAE_REG_BASE + 0x0048)
#define     REG_TAE_LAMBDA0_CFG0        (TAE_REG_BASE + 0x004C)
#define     REG_TAE_LAMBDA0_CFG1        (TAE_REG_BASE + 0x0050)
#define     REG_TAE_LAMBDA1_CFG0        (TAE_REG_BASE + 0x0054)
#define     REG_TAE_LAMBDA1_CFG1        (TAE_REG_BASE + 0x0058)
#define     REG_TAE_LAMBDA1_CFG2        (TAE_REG_BASE + 0x005C)
#define     REG_TAE_LAMBDA1_CFG3        (TAE_REG_BASE + 0x0060)
#define     REG_TAE_VIF_CFG0            (TAE_REG_BASE + 0x0064)
#define     REG_TAE_VIF_CFG1            (TAE_REG_BASE + 0x0068)
#define     REG_TAE_ENC_CMD             (TAE_REG_BASE + 0x0080)
#define     REG_TAE_PK_CODE             (TAE_REG_BASE + 0x0084)
#define     REG_TAE_STATUS_REG0         (TAE_REG_BASE + 0x0090)
#define     REG_TAE_STATUS_REG1         (TAE_REG_BASE + 0x0094)
#define     REG_TAE_STATUS_REG2         (TAE_REG_BASE + 0x0098)
#define     REG_TAE_STATUS_REG3         (TAE_REG_BASE + 0x009C)
#define     REG_TAE_STATUS_REG4         (TAE_REG_BASE + 0x00A0)
#define     REG_TAE_STATUS_REG5         (TAE_REG_BASE + 0x00A4)
#define     REG_TAE_STATUS_REG6         (TAE_REG_BASE + 0x00A8)
#define     REG_TAE_STATUS_REG7         (TAE_REG_BASE + 0x00AC)
#define     REG_TAE_DBG0                (TAE_REG_BASE + 0x00B0)
#define     REG_TAE_DBG1                (TAE_REG_BASE + 0x00B4)
#define     REG_TAE_DBG2                (TAE_REG_BASE + 0x00B8)


//SDRA
//SDC0
//SDC1
#define		SDC_INTERVAL			(0x100000)
#define		REG_SDC_CTRL(n)			(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0000)
#define		REG_SDC_PWREN(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0004)
#define		REG_SDC_CLKDIV(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0008)
#define		REG_SDC_CLKSRC(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x000C)
#define		REG_SDC_CLKENA(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0010)
#define		REG_SDC_TMOUT(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0014)
#define		REG_SDC_CTYPE(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0018)
#define		REG_SDC_BLKSIZ(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x001C)
#define		REG_SDC_BYTCNT(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0020)
#define		REG_SDC_INTMASK(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0024)
#define		REG_SDC_CMDARG(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0028)
#define		REG_SDC_CMD(n)			(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x002C)
#define		REG_SDC_RESP0(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0030)
#define		REG_SDC_RESP1(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0034)
#define		REG_SDC_RESP2(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0038)
#define		REG_SDC_RESP3(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x003C)
#define		REG_SDC_MINTSTS(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0040)
#define		REG_SDC_RINTSTS(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0044)
#define		REG_SDC_STATUS(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0048)
#define		REG_SDC_FIFOTH(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x004C)
#define		REG_SDC_CDETECT(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0050)
#define		REG_SDC_WRTPRT(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0054)
#define		REG_SDC_GPIO(n)			(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0058)
#define		REG_SDC_TCBCNT(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x005C)
#define		REG_SDC_TBBCNT(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0060)
#define		REG_SDC_DEBNCE(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0064)
#define		REG_SDC_USRID(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0068)
#define		REG_SDC_VERID(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x006C)
#define		REG_SDC_HCON(n)			(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0070)
#define		REG_SDC_UHS_REG(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0074)
#define		REG_SDC_RST_N(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0078)
#define		REG_SDC_BMOD(n)			(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0080)
#define		REG_SDC_PLDMND(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0084)
#define		REG_SDC_DBADDR(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0088)
#define		REG_SDC_IDSTS(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x008C)
#define		REG_SDC_IDINTEN(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0090)
#define		REG_SDC_DSCADDR(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0094)
#define		REG_SDC_BUFADDR(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0098)
#define		REG_SDC_CARDTHRCTL(n)	(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0100)
#define		REG_SDC_BACK_END_POWER(n)		(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0104)
#define		REG_SDC_FIFO(n)			(SDC0_REG_BASE + ((n) * SDC_INTERVAL) + 0x0200)


//JPEG
#define     REG_JPEG_IP_VER_INFO        (JPEG_REG_BASE + 0x0000)
#define     REG_JPEG_INT_STATUS         (JPEG_REG_BASE + 0x0004)
#define     REG_JPEG_INT_EN             (JPEG_REG_BASE + 0x0008)
#define     REG_JPEG_PROC_STATUS        (JPEG_REG_BASE + 0x000C)
#define     REG_JPEG_JPG_REG0           (JPEG_REG_BASE + 0x0010)
#define     REG_JPEG_JPG_REG1           (JPEG_REG_BASE + 0x0014)
#define     REG_JPEG_JPG_REG2           (JPEG_REG_BASE + 0x0018)
#define     REG_JPEG_JPG_REG3           (JPEG_REG_BASE + 0x001C)
#define     REG_JPEG_JPG_REG4           (JPEG_REG_BASE + 0x0020)
#define     REG_JPEG_JPG_REG5           (JPEG_REG_BASE + 0x0024)
#define     REG_JPEG_JPG_REG6           (JPEG_REG_BASE + 0x0028)
#define     REG_JPEG_JPG_REG7           (JPEG_REG_BASE + 0x002C)
#define     REG_JPEG_STM_INFO           (JPEG_REG_BASE + 0x0030)
#define     REG_JPEG_STM_ADDR0          (JPEG_REG_BASE + 0x0034)
#define     REG_JPEG_STM_ADDR1          (JPEG_REG_BASE + 0x0038)
#define     REG_JPEG_QMem               (JPEG_REG_BASE + 0x0080)
#define     REG_JPEG_HuffEnc            (JPEG_REG_BASE + 0x0100)
#define     REG_JPEG_DHTMem             (JPEG_REG_BASE + 0x0400)

//PMU
#define     REG_PMU_CHIP_ID             (PMU_REG_BASE + 0x000)
#define     REG_PMU_IP_VER              (PMU_REG_BASE + 0x004)
#define     REG_PMU_FW_VER              (PMU_REG_BASE + 0x008)
#define     REG_PMU_PLL0_CTRL           (PMU_REG_BASE + 0x020)
#define     REG_PMU_PLL1_CTRL           (PMU_REG_BASE + 0x024)
#define     REG_PMU_CLK_SEL             (PMU_REG_BASE + 0x030)
#define     REG_PMU_CLK_DIV0            (PMU_REG_BASE + 0x040)
#define     REG_PMU_CLK_DIV1            (PMU_REG_BASE + 0x044)
#define     REG_PMU_CLK_DIV2            (PMU_REG_BASE + 0x048)
#define     REG_PMU_CLK_DIV3            (PMU_REG_BASE + 0x04c)
#define     REG_PMU_CLK_DIV4            (PMU_REG_BASE + 0x050)
#define     REG_PMU_CLK_DIV5            (PMU_REG_BASE + 0x054)
#define     REG_PMU_AHBCLK_GATE         (PMU_REG_BASE + 0x060)
#define     REG_PMU_APBCLK_GATE         (PMU_REG_BASE + 0x070)
#define     REG_PMU_CLK_GATE            (PMU_REG_BASE + 0x080)
#define     REG_PMU_SWRST_AHB_CTRL      (PMU_REG_BASE + 0x100)
#define     REG_PMU_SWRST_APB_CTRL      (PMU_REG_BASE + 0x104)
#define     REG_PMU_IO_MUX_SEL0         (PMU_REG_BASE + 0x120)
#define     REG_PMU_IO_MUX_SEL1         (PMU_REG_BASE + 0x124)
// add sadc reg by yu.zhang
#define     REG_PMU_SADC_CTRL           (PMU_REG_BASE + 0x140)
#define     REG_PMU_SADC_STATUS         (PMU_REG_BASE + 0x144)

#define     REG_PMU_RESERVED0           (PMU_REG_BASE + 0x200)
#define     REG_PMU_RESERVED1           (PMU_REG_BASE + 0x204)
#define     REG_PMU_RESERVED2           (PMU_REG_BASE + 0x208)
#define     REG_PMU_RESERVED3           (PMU_REG_BASE + 0x20c)
#define     REG_PMU_RESERVED4           (PMU_REG_BASE + 0x210)

//WDT
#define     REG_WDT_CR                  (WDT_REG_BASE+0x0)
#define     REG_WDT_TORR                (WDT_REG_BASE+0x4)
#define     REG_WDT_CRR                 (WDT_REG_BASE+0xc)




//TMR

#define TIMER_LOADCNT_OFFSET            			(0x00)
#define TIMER_CUR_VAL_OFFSET            			(0x04)
#define TIMER_CTRL_REG_OFFSET               		(0x08)
#define TIMER_EOI_REG_OFFSET            			(0x0c)
#define TIMER_INTSTATUS_OFFSET              		(0x10)
#define TIMER_ALL_INTSTATUS_OFFSET              	(0xa0)

#define TIMER_INTERVAL                  	    	0x14

#define REG_TIMER_LOADCNT(n)    (TMR_REG_BASE + ((n) * TIMER_INTERVAL) + TIMER_LOADCNT_OFFSET)
#define REG_TIMER_CUR_VAL(n)    (TMR_REG_BASE + ((n) * TIMER_INTERVAL) + TIMER_CUR_VAL_OFFSET)
#define REG_TIMER_CTRLR(n)      (TMR_REG_BASE + ((n) * TIMER_INTERVAL) + TIMER_CTRL_REG_OFFSET)
#define REG_TIMER_EOI(n)        (TMR_REG_BASE + ((n) * TIMER_INTERVAL) + TIMER_EOI_REG_OFFSET)
#define REG_TIMER_INTSTATUS(n)  (TMR_REG_BASE + ((n) * TIMER_INTERVAL) + TIMER_INTSTATUS_OFFSET)


#define REG_TIMER_ALL_INT_STATUS                    (TMR_REG_BASE + TIMER_ALL_INTSTATUS_OFFSET)
//GPIO
//I2C
#define     REG_I2C_CON             (I2C_REG_BASE + 0x0000)
#define     REG_I2C_TAR             (I2C_REG_BASE + 0x0004)
#define     REG_I2C_SAR             (I2C_REG_BASE + 0x0008)
#define     REG_I2C_HS_MADDR        (I2C_REG_BASE + 0x000C)
#define     REG_I2C_DATA_CMD        (I2C_REG_BASE + 0x0010)
#define     REG_I2C_SS_SCL_HCNT     (I2C_REG_BASE + 0x0014)
#define     REG_I2C_SS_SCL_LCNT     (I2C_REG_BASE + 0x0018)
#define     REG_I2C_FS_SCL_HCNT     (I2C_REG_BASE + 0x001C)
#define     REG_I2C_FS_SCL_LCNT     (I2C_REG_BASE + 0x0020)
#define     REG_I2C_HS_SCL_HCNT     (I2C_REG_BASE + 0x0024)
#define     REG_I2C_HS_SCL_LCNT     (I2C_REG_BASE + 0x0028)
#define     REG_I2C_INTR_STAT       (I2C_REG_BASE + 0x002c)
#define     REG_I2C_INTR_MASK       (I2C_REG_BASE + 0x0030)
#define     REG_I2C_RAW_INTR_STAT   (I2C_REG_BASE + 0x0034)
#define     REG_I2C_RX_TL           (I2C_REG_BASE + 0x0038)
#define     REG_I2C_TX_TL           (I2C_REG_BASE + 0x003c)
#define     REG_I2C_CLR_INTR        (I2C_REG_BASE + 0x0040)
#define     REG_I2C_ENABLE          (I2C_REG_BASE + 0x006c)
#define     REG_I2C_STATUS          (I2C_REG_BASE + 0x0070)
#define     REG_I2C_TXFLR           (I2C_REG_BASE + 0x0074)
#define     REG_I2C_RXFLR           (I2C_REG_BASE + 0x0078)
#define     REG_I2C_DMA_CR          (I2C_REG_BASE + 0x0088)
#define     REG_I2C_DMA_TDLR        (I2C_REG_BASE + 0x008c)
#define     REG_I2C_DMA_RDLR        (I2C_REG_BASE + 0x0090)

//UART

#define     UART_RBR_OFFSET         	(0x0000)
#define     UART_THR_OFFSET         	(0x0000)
#define     UART_DLL_OFFSET         	(0x0000)
#define     UART_DLH_OFFSET         	(0x0004)
#define     UART_IER_OFFSET         	(0x0004)
#define     UART_IIR_OFFSET         	(0x0008)
#define     UART_FCR_OFFSET         	(0x0008)
#define     UART_LCR_OFFSET         	(0x000c)
#define     UART_MCR_OFFSET         	(0x0010)
#define     UART_LSR_OFFSET         	(0x0014)
#define     UART_MSR_OFFSET         	(0x0018)
#define     UART_SCR_OFFSET         	(0x001c)
#define     UART_FAR_OFFSET         	(0x0070)
#define     UART_TFR_OFFSET         	(0x0074)
#define     UART_RFW_OFFSET         	(0x0078)
#define     UART_USR_OFFSET         	(0x007c)
#define     UART_TFL_OFFSET         	(0x0080)
#define     UART_RFL_OFFSET         	(0x0084)
#define     UART_SRR_OFFSET         	(0x0088)
#define     UART_SFE_OFFSET         	(0x0098)
#define     UART_SRT_OFFSET         	(0x009c)
#define     UART_STET_OFFSET        	(0x00a0)
#define     UART_HTX_OFFSET         	(0x00a4)
#define     UART_DMASA_OFFSET           (0x00a8)
#define     UART_CPR_OFFSET         	(0x00f4)
#define     UART_UCV_OFFSET         	(0x00f8)
#define     UART_CTR_OFFSET         	(0x00fc)

#define     UART_INTERVAL               			0x100000 

#define     REG_UART_RBR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_RBR_OFFSET)
#define     REG_UART_THR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_THR_OFFSET)

#define     REG_UART_DLL(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_DLL_OFFSET)

#define     REG_UART_DLH(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_DLH_OFFSET)

#define     REG_UART_IER(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_IER_OFFSET)

#define     REG_UART_IIR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_IIR_OFFSET)

#define     REG_UART_FCR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_FCR_OFFSET)

#define     REG_UART_LCR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_LCR_OFFSET)

#define     REG_UART_MCR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_MCR_OFFSET)

#define     REG_UART_LSR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_LSR_OFFSET)

#define     REG_UART_MSR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_MSR_OFFSET)

#define     REG_UART_SCR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_SCR_OFFSET)

#define     REG_UART_FAR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_FAR_OFFSET)

#define     REG_UART_TFR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_TFR_OFFSET)

#define     REG_UART_RFW(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_RFW_OFFSET)

#define     REG_UART_USR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_USR_OFFSET)

#define     REG_UART_TFL(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_TFL_OFFSET)

#define     REG_UART_RFL(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_RFL_OFFSET)

#define     REG_UART_SRR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_SRR_OFFSET)

#define     REG_UART_SFE(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_SFE_OFFSET)

#define     REG_UART_SRT(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_SRT_OFFSET)

#define     REG_UART_STET(n)                (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_STET_OFFSET)

#define     REG_UART_HTX(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_HTX_OFFSET)

#define     REG_UART_DMASA(n)               (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_DMASA_OFFSET)

#define     REG_UART_CPR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_CPR_OFFSET)

#define     REG_UART_UCV(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_UCV_OFFSET)

#define     REG_UART_CTR(n)                 (UART0_REG_BASE + ((n) * UART_INTERVAL) + UART_CTR_OFFSET)



//I2S
#define     REG_I2S_IER         (I2S_REG_BASE + 0x0000)  //i2s enable reg
#define     REG_I2S_IRER        (I2S_REG_BASE + 0x0004)  //i2s receiver block enable
#define     REG_I2S_ITER        (I2S_REG_BASE + 0x0008)  //i2s transmitter block
#define     REG_I2S_CER         (I2S_REG_BASE + 0x000c) //clk en
#define     REG_I2S_CCR         (I2S_REG_BASE + 0x0010) //clk cfg reg
#define     REG_I2S_RXFFR       (I2S_REG_BASE + 0x0014) //reset rx fifo reg
#define     REG_I2S_TXFFR       (I2S_REG_BASE + 0x0018) //reset tx fifo reg
#define     REG_I2S_LRBR0       (I2S_REG_BASE + 0x0020) //left rx/tx buf reg for channel 0
#define     REG_I2S_LRBR1       (I2S_REG_BASE + 0x0060) //left rx /txbuf reg for channel 1
#define     REG_I2S_LRBR2       (I2S_REG_BASE + 0x00A0) //chan 2
#define     REG_I2S_LRBR3       (I2S_REG_BASE + 0x00E0) //chan 3
#define     REG_I2S_RRBR0       (I2S_REG_BASE + 0x0024) //right rx/tx buf reg for chn 0
#define     REG_I2S_RRBR1       (I2S_REG_BASE + 0x0064) //chn 1 rx/tx
#define     REG_I2S_RRBR2       (I2S_REG_BASE + 0x00A4)  //chn2
#define     REG_I2S_RRBR3       (I2S_REG_BASE + 0x00E4)  //chn3
#define     REG_I2S_RER0        (I2S_REG_BASE + 0x0028)  //rx en register for channel 0
#define     REG_I2S_RER1        (I2S_REG_BASE + 0x0068)  //rx en chan 1
#define     REG_I2S_RER2        (I2S_REG_BASE + 0x00A8)  //rx en chan 2
#define     REG_I2S_RER3        (I2S_REG_BASE + 0x00E8)  //rx en chan 3
#define     REG_I2S_TER0        (I2S_REG_BASE + 0x002C)  //tx en chan 0
#define     REG_I2S_TER1        (I2S_REG_BASE + 0x006C)  //tx en chan 1
#define     REG_I2S_TER2        (I2S_REG_BASE + 0x00AC)  //tx en chan 2
#define     REG_I2S_TER3        (I2S_REG_BASE + 0x00EC)  //tx en chan 3
#define     REG_I2S_RCR0        (I2S_REG_BASE + 0x0030)  //rx config chan 0
#define     REG_I2S_RCR1        (I2S_REG_BASE + 0x0070)  //rx config chan 1
#define     REG_I2S_RCR2        (I2S_REG_BASE + 0x00B0)  //rx config chan 2
#define     REG_I2S_RCR3        (I2S_REG_BASE + 0x00F0)  //rx config chan 3
#define     REG_I2S_TCR0        (I2S_REG_BASE + 0x0034) //tx config chan 0
#define     REG_I2S_TCR1        (I2S_REG_BASE + 0x0074) //tx config chan1
#define     REG_I2S_TCR2        (I2S_REG_BASE + 0x00B4) //tx config chan2
#define     REG_I2S_TCR3        (I2S_REG_BASE + 0x00F4) //tx config chan3
#define     REG_I2S_ISR0        (I2S_REG_BASE + 0x0038) //intt status reg chan 0
#define     REG_I2S_ISR1        (I2S_REG_BASE + 0x0078) //intt status reg chan 1
#define     REG_I2S_ISR2        (I2S_REG_BASE + 0x00B8) //intt status reg chan 2
#define     REG_I2S_ISR3        (I2S_REG_BASE + 0x00F8) //intt status reg chan 3
#define     REG_I2S_IMR0        (I2S_REG_BASE + 0x003C) //intt mask reg chan 0
#define     REG_I2S_IMR1        (I2S_REG_BASE + 0x007C) //intt mask reg chan 1
#define     REG_I2S_IMR2        (I2S_REG_BASE + 0x00BC) //intt mask reg chan 2
#define     REG_I2S_IMR3        (I2S_REG_BASE + 0x00FC) //intt mask reg chan 3
#define     REG_I2S_ROR0        (I2S_REG_BASE + 0x0040)  //rx overrun reg chan 0
#define     REG_I2S_ROR1        (I2S_REG_BASE + 0x0080)  //rx overrun reg chan 1
#define     REG_I2S_ROR2        (I2S_REG_BASE + 0x00C0)  //rx overrun reg chan 2
#define     REG_I2S_ROR3        (I2S_REG_BASE + 0x0100)  //rx overrun reg chan 3
#define     REG_I2S_TOR0        (I2S_REG_BASE + 0x0044)  //tx overrun reg chan 0
#define     REG_I2S_TOR1        (I2S_REG_BASE + 0x0084)  //tx overrun reg chan 1
#define     REG_I2S_TOR2        (I2S_REG_BASE + 0x00C4)  //tx overrun reg chan 2
#define     REG_I2S_TOR3        (I2S_REG_BASE + 0x0104)  //tx overrun reg chan 3
#define     REG_I2S_RFCR0       (I2S_REG_BASE + 0x0048)  //rx fifo config reg for chan 0
#define     REG_I2S_RFCR1       (I2S_REG_BASE + 0x0088)  // chan 1
#define     REG_I2S_RFCR2       (I2S_REG_BASE + 0x00C8)  //rx fifo config reg for chan 2
#define     REG_I2S_RFCR3       (I2S_REG_BASE + 0x0108)  //rx fifo config reg for chan 3
#define     REG_I2S_TFCR0       (I2S_REG_BASE + 0x004C)  //tx fifo config reg for chan 0
#define     REG_I2S_TFCR1       (I2S_REG_BASE + 0x008C)  //tx fifo config reg for chan 1
#define     REG_I2S_TFCR2       (I2S_REG_BASE + 0x00CC)  //tx fifo config reg for chan 2
#define     REG_I2S_TFCR3       (I2S_REG_BASE + 0x010C)  //tx fifo config reg for chan 3
#define     REG_I2S_RFF0        (I2S_REG_BASE + 0x0050)  //rx fifo flush reg for chan 0
#define     REG_I2S_RFF1        (I2S_REG_BASE + 0x0090)  //rx fifo flush reg for chan 1
#define     REG_I2S_RFF2        (I2S_REG_BASE + 0x00D4)  //rx fifo flush reg for chan 2
#define     REG_I2S_RFF3        (I2S_REG_BASE + 0x0110)  //rx fifo flush reg for chan 3
#define     REG_I2S_TFF0        (I2S_REG_BASE + 0x0054)  //tx fifo flush reg for chan 0
#define     REG_I2S_TFF1        (I2S_REG_BASE + 0x0094)  //tx fifo flush reg for chan 1
#define     REG_I2S_TFF2        (I2S_REG_BASE + 0x00D4)  //tx fifo flush reg for chan 2
#define     REG_I2S_TFF3        (I2S_REG_BASE + 0x0114)  //tx fifo flush reg for chan 3
#define     REG_I2S_RXDMA       (I2S_REG_BASE + 0x01C0)  //rx dma reg
#define     REG_I2S_RRXDMA      (I2S_REG_BASE + 0x01C4) //reset rx dma reg
#define     REG_I2S_TXDMA       (I2S_REG_BASE + 0x01C8) //tx dma reg
#define     REG_I2S_RTXDMA      (I2S_REG_BASE + 0x01CC) //reset tx dma reg

//SPI0
//SPI1
//SPI2
#define SPI_CTRL0_OFFSET            			(0x00)
#define SPI_CTRL1_OFFSET            			(0x04)
#define SPI_SSIENR_OFFSET               		(0x08)
#define SPI_MWCR_OFFSET             			(0x0c)
#define SPI_SER_OFFSET              			(0x10)
#define SPI_BAUD_OFFSET             			(0x14)
#define SPI_TXFTL_OFFSET            			(0x18)
#define SPI_RXFTL_OFFSET            			(0x1c)
#define SPI_TXFL_OFFSET             			(0x20)
#define SPI_RXFL_OFFSET             			(0x24)
#define SPI_STATUS_OFFSET               		(0x28)
#define SPI_IMR_OFFSET              			(0x2c)
#define SPI_ISR_OFFSET              			(0x30)
#define SPI_RISR_OFFSET             			(0x34)
#define SPI_TXOIC_OFFSET            			(0x38)
#define SPI_RXOIC_OFFSET            			(0x3c)
#define SPI_RXUIC_OFFSET            			(0x40)
#define SPI_MSTIC_OFFSET            			(0x44)
#define SPI_INTCLR_OFFSET               		(0x48)
#define SPI_DMACTRL_OFFSET              		(0x4c)
#define SPI_DMATDL_OFFSET               		(0x50)
#define SPI_DMARDL_OFFSET               		(0x54)
#define SPI_IDR_OFFSET              			(0x58)
#define SPI_SSI_COMPVER_OFFSET              	(0x5c)
#define SPI_DATA_OFFSET             			(0x60)

#define SPI_INTERVAL                			0x100000 

#define     REG_SPI_CTRLR0(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_CTRL0_OFFSET)
                                                			/*  0:3  DFS : Data Frame Size
                                        						4:5  FRF : Frame Format
                                                				6    SCPH : Serial Clock PHase
                                            					7    SCPOL: Serial POLarity
                                            					8:9  TMOD : Transfer MODe
                                                				10   SLV_OE: SLaVe Output Enable
                                                    			11   SRL : Shift Register Loop
                                                        		12:15   CFS : Control Frame Size 		*/
#define     REG_SPI_CTRLR1(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_CTRL1_OFFSET)
                                                            /* only for dw_apb_ssi is configured as a master and 
                                                             * set the number of data frames to be received
                                        					   by the dw_apb_ssi */
#define     REG_SPI_SSIENR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_SSIENR_OFFSET)
                                                            /* ENable and disable all dw_apb_SSI operations .  SSI ENable*/
#define     REG_SPI_MWCR(n)                     (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_MWCR_OFFSET)
#define     REG_SPI_SER(n)                      (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_SER_OFFSET)
                                                            /* Slave Enable Register ,select slave select line 
                                                			 * to communication the slave  */
#define     REG_SPI_BAUDR(n)                    (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_BAUD_OFFSET)
                                                            /* only for dw_aph_ssi is configured as a master ,
                                                             * enables the individual slave select output lines from dw_apb_ssi master */
#define     REG_SPI_TXFTLR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_TXFTL_OFFSET)
                                                            /* control the threshold value for the transmit  FIFO memory */
#define     REG_SPI_RXFTLR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_RXFTL_OFFSET)
                                                            /* Receive fifo Overflow Interrupt Clear Register */
#define     REG_SPI_TXFLR(n)                    (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_TXFL_OFFSET)
                                                            /* contains the number of valid data entries */
#define     REG_SPI_RXFLR(n)                    (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_RXFL_OFFSET)
#define     REG_SPI_SR(n)                       (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_STATUS_OFFSET)
#define     REG_SPI_IMR(n)                      (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_IMR_OFFSET)
#define     REG_SPI_ISR(n)                      (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_ISR_OFFSET)
#define     REG_SPI_RISR(n)                     (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_RISR_OFFSET)
#define     REG_SPI_TXOICR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_TXOIC_OFFSET)
#define     REG_SPI_RXOICR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_RXOIC_OFFSET)
#define     REG_SPI_RXUICR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_RXUIC_OFFSET)
#define     REG_SPI_MSTICR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_MSTIC_OFFSET)
#define     REG_SPI_ICR(n)                      (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_INTCLR_OFFSET)
#define     REG_SPI_DMACR(n)                    (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_DMACTRL_OFFSET)
#define     REG_SPI_DMATDLR(n)                  (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_DMATDL_OFFSET)
#define     REG_SPI_DMARDLR(n)                  (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_DMARDL_OFFSET)
#define     REG_SPI_IDR(n)                      (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_IDR_OFFSET)
#define     REG_SPI_SSI_COMP_VERSION(n)         (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_SSI_COMPVER_OFFSET)
#define     REG_SPI_SSI_DR(n)                   (SPI0_REG_BASE + ((n) * SPI_INTERVAL) + SPI_DATA_OFFSET)
//PWM
//RTC
#define  REG_RTC_COUNTER             (RTC_REG_BASE+0x0)
#define  REG_RTC_OFFSET              (RTC_REG_BASE+0x4)
#define  REG_RTC_POWER_FAIL          (RTC_REG_BASE+0x8)
#define  REG_RTC_ALARM_COUNTER       (RTC_REG_BASE+0xC)
#define  REG_RTC_INT_STAT            (RTC_REG_BASE+0x10)
#define  REG_RTC_INT_EN              (RTC_REG_BASE+0x14)
#define  REG_RTC_SYNC                (RTC_REG_BASE+0x18)
#define  REG_RTC_DEBUG               (RTC_REG_BASE+0x1C)

#define     REG_DMAC_SAR_OFFSET     (0x0)
#define     REG_DMAC_DAR_OFFSET     (0x8)
#define     REG_DMAC_LLP_OFFSET     (0x10)
#define     REG_DMAC_CTX_OFFSET     (0x18)
#define     REG_DMAC_SSTAT_OFFSET       (0x20)
#define     REG_DMAC_DSTAT_OFFSET       (0x28)
#define     REG_DMAC_SSTATAR_OFFSET (0x30)
#define     REG_DMAC_DSTATAR_OFFSET (0x38)
#define     REG_DMAC_CFG_OFFSET     (0x40)
#define     REG_DMAC_SGR_OFFSET     (0x48)
#define     REG_DMAC_DSR_OFFSET     (0x50)
#define     REG_DMAC_SARi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_SAR_OFFSET)
#define     REG_DMAC_DARi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_DAR_OFFSET)
#define     REG_DMAC_LLPi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_LLP_OFFSET)
#define     REG_DMAC_CTXi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_CTX_OFFSET)
#define     REG_DMAC_SSTATi(n)          (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_SSTAT_OFFSET)
#define     REG_DMAC_DSTATi(n)          (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_DSTAT_OFFSET)
#define     REG_DMAC_SSTATARi(n)        (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_SSTATAR_OFFSET)
#define     REG_DMAC_DSTATARi(n)        (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_DSTATAR_OFFSET)
#define     REG_DMAC_CFGi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_CFG_OFFSET)
#define     REG_DMAC_SGRi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_SGR_OFFSET)
#define     REG_DMAC_DSRi(n)            (DMAC_REG_BASE + (n) * 0x58 + REG_DMAC_DSR_OFFSETR)

#define     REG_DMAC_INTRAWTFR          (DMAC_REG_BASE + 0x2c0)
#define     REG_DMAC_INTRAWBLK          (DMAC_REG_BASE + 0x2c8)
#define     REG_DMAC_INTRAWSRCTXR       (DMAC_REG_BASE + 0x2d0)
#define     REG_DMAC_INTRAWDSTTXR       (DMAC_REG_BASE + 0x2d8)
#define     REG_DMAC_INTRAWERR          (DMAC_REG_BASE + 0x2e0)
#define     REG_DMAC_INTSTAT_TFR        (DMAC_REG_BASE + 0x2e8)
#define     REG_DMAC_INTSTAT_BLK        (DMAC_REG_BASE + 0x2f0)
#define     REG_DMAC_INTSTAT_SRCTXR     (DMAC_REG_BASE + 0x2f8)
#define     REG_DMAC_INTSTAT_DSTTXR     (DMAC_REG_BASE + 0x300)
#define     REG_DMAC_INTSTAT_ERR        (DMAC_REG_BASE + 0x308)
#define     REG_DMAC_INTMSK_TFR         (DMAC_REG_BASE + 0x310)
#define     REG_DMAC_INTMSK_BLK         (DMAC_REG_BASE + 0x318)
#define     REG_DMAC_INTMSK_SRCTXR      (DMAC_REG_BASE + 0x320)
#define     REG_DMAC_INTMSK_DSTTXR      (DMAC_REG_BASE + 0x328)
#define     REG_DMAC_INTMSK_ERR         (DMAC_REG_BASE + 0x330)
#define     REG_DMAC_INTCLR_TFR         (DMAC_REG_BASE + 0x338)
#define     REG_DMAC_INTCLR_BLK         (DMAC_REG_BASE + 0x340)
#define     REG_DMAC_INTCLR_SRCTXR      (DMAC_REG_BASE + 0x348)
#define     REG_DMAC_INTCLR_DSTTXR      (DMAC_REG_BASE + 0x350)
#define     REG_DMAC_INTCLR_ERR         (DMAC_REG_BASE + 0x358)
#define     REG_DMAC_INT_STATUS_ALL     (DMAC_REG_BASE + 0x360)

#define     REG_DMAC_REQSRC             (DMAC_REG_BASE + 0x368)
#define     REG_DMAC_REQDST             (DMAC_REG_BASE + 0x370)
#define     REG_DMAC_SGLREQSRC          (DMAC_REG_BASE + 0x378)
#define     REG_DMAC_SGLREQDST          (DMAC_REG_BASE + 0x380)
#define     REG_DMAC_LSTSRC             (DMAC_REG_BASE + 0x388)
#define     REG_DMAC_LSTDST             (DMAC_REG_BASE + 0x390)
#define     REG_DMAC_CFG_REG            (DMAC_REG_BASE + 0x398)
#define     REG_DMAC_CHAN_EN            (DMAC_REG_BASE + 0x3a0)
#define     REG_DMAC_IDREG              (DMAC_REG_BASE + 0x3a8)
#define     REG_DMAC_TESTREG            (DMAC_REG_BASE + 0x3b0)
#define     REG_DMAC_COMPARAMS_6        (DMAC_REG_BASE + 0x3c8)
#define     REG_DMAC_COMPARAMS_5        (DMAC_REG_BASE + 0x3d0)
#define     REG_DMAC_COMPARAMS_4        (DMAC_REG_BASE + 0x3d8)
#define     REG_DMAC_COMPARAMS_3        (DMAC_REG_BASE + 0x3e0)
#define     REG_DMAC_COMPARAMS_2        (DMAC_REG_BASE + 0x3e8)
#define     REG_DMAC_COMPARAMS_1        (DMAC_REG_BASE + 0x3f0)
#define     REG_DMAC_COMP_IDREG         (DMAC_REG_BASE + 0x3f8)
/* Public function ----------------------------------------------------------*/


#endif
