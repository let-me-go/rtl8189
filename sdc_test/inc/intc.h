#ifndef INTC_H_
#define INTC_H_
#include "pre_define.h"

#define		INTC_REG_BASE			(0xE0200000)
#define		INTC_IRQ_BASE			(INTC_REG_BASE + 0x0)
#define		INTC_FIQ_BASE			(INTC_REG_BASE + 0x2c0)

typedef union
{
	struct
	{
		UINT32	pae					:1; //0
		UINT32	vpu					:1; //1
		UINT32	ipf					:1; //2
		UINT32	ipb					:1; //3
		UINT32	vou					:1; //4
		UINT32	jpeg				:1; //5
		UINT32	reserved_7_6		:2; //6~7
		UINT32	ddrc				:1; //8
		UINT32	dmac				:1; //9
		UINT32	aes					:1; //10
		UINT32	mipic				:1; //11
		UINT32	mipi_wrap			:1; //12
		UINT32	pmu					:1; //13
		UINT32	gmac				:1; //14
		UINT32	reserved_23_15		:9; //15~23
		UINT32	sdc0				:1; //24
		UINT32	sdc1				:1; //25
		UINT32	acw					:1; //26
		UINT32	wdt					:1; //27
		UINT32	spi0				:1; //28
		UINT32	spi1				:1; //29
		UINT32	uart0				:1; //30
		UINT32	uart1				:1; //31

	}bit;
	UINT32 dw;
}INTC_INT_LOW_S;

typedef union
{
	struct
	{
		UINT32	i2s0				:1; //0
		UINT32	reserved_1			:1; //1
		UINT32	rtc					:1; //2
		UINT32	reserved_3			:1; //3
		UINT32	tmr0				:1; //4
		UINT32	tmr1				:1; //5
		UINT32	reserved_7_6		:2; //6~7
		UINT32	gpio0				:1; //8
		UINT32	gpio1				:1; //9
		UINT32	i2c0				:1; //10
		UINT32	i2c1				:1; //11
		UINT32	gpio2				:1; //12
		UINT32	gpio3				:1; //13
		UINT32	gpio4				:1; //14
		UINT32	gpio5				:1; //15
		UINT32	intc0				:1; //16
		UINT32	intc1				:1; //17
		UINT32	intc2				:1; //18
		UINT32	intc3				:1; //19
		UINT32	reserved_31_20		:12;//20~31

	}bit;
	UINT32 dw;
}INTC_INT_HIGH_S;



typedef union
{
	struct
	{
		UINT32	reserved_31_0			:32; //0~31
	}bit;
	UINT32 dw;
}INTC_RESERVED_S;



typedef struct
{
	INTC_INT_LOW_S inten_low;								//0x0000
	INTC_INT_HIGH_S inten_high;							//0x0004
	INTC_INT_LOW_S intmask_low;							//0x0008
	INTC_INT_HIGH_S intmask_high;							//0x000c
	INTC_INT_LOW_S intforce_low;							//0x0010
	INTC_INT_HIGH_S intforce_high;						//0x0014
	INTC_INT_LOW_S rawstatus_low;							//0x0018
	INTC_INT_HIGH_S rawstatus_high;						//0x001c
	INTC_INT_LOW_S status_low;							//0x0020
	INTC_INT_HIGH_S status_high;							//0x0024
	INTC_INT_LOW_S maskstatus_low;						//0x0028
	INTC_INT_HIGH_S maskstatus_high;						//0x002c
	INTC_INT_LOW_S finalstatus_low;						//0x0030
	INTC_INT_HIGH_S finalstatus_high;						//0x0034

}INTC_IRQ_MODULE_S;

typedef struct
{
	INTC_INT_LOW_S inten_low;								//0x02c0
	INTC_INT_HIGH_S inten_high;							//0x02c4
	INTC_INT_LOW_S intmask_low;							//0x02c8
	INTC_INT_HIGH_S intmask_high;							//0x02cc
	INTC_INT_LOW_S intforce_low;							//0x02d0
	INTC_INT_HIGH_S intforce_high;						//0x02d4
	INTC_INT_LOW_S rawstatus_low;							//0x02d8
	INTC_INT_HIGH_S rawstatus_high;						//0x02dc
	INTC_INT_LOW_S status_low;							//0x02e0
	INTC_INT_HIGH_S status_high;							//0x02e4
	INTC_INT_LOW_S finalstatus_low;						//0x02e8
	INTC_INT_HIGH_S finalstatus_high;						//0x02ec
	
}INTC_FIQ_MODULE_S;

typedef void (Intc_InterruptFunction) ();

extern Intc_InterruptFunction* IntrFunc[64];

void Intc_Init();

#endif /*INTC_H_*/
