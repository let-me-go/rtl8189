#include "intc.h"
#include "chip.h"
#include "chip_reg.h"

volatile INTC_IRQ_MODULE_S* pstIntcIrqModule;
volatile INTC_FIQ_MODULE_S* pstIntcFiqModule;

Intc_InterruptFunction* IntrFunc[64] = {0};
/*
void Interrupt_PAE()
{
	SET_REG(0xf0400000,0x11111111);
}

void Interrupt_VPU()
{

}

void Interrupt_IPF()
{

}

void Interrupt_IPB()
{

}

void Interrupt_VOU()
{

}

void Interrupt_JPEG()
{

}

void Interrupt_DDRC()
{

}

void Interrupt_DMAC()
{

}

void Interrupt_AES()
{

}

void Interrupt_MIPIC()
{

}

void Interrupt_WRAP()
{

}

void Interrupt_PMU()
{

}

void Interrupt_EMAC()
{

}

void Interrupt_SDC0()
{

}

void Interrupt_SDC1()
{

}

void Interrupt_ACW()
{

}

void Interrupt_WDT()
{

}

void Interrupt_SPI0()
{
	SET_REG(0xf0400000,0x11111111);
}

void Interrupt_SPI1()
{
	while(1)
	{
		SET_REG(0xf0400000,0x33333333);
	}
}

void Interrupt_UART0()
{
	SET_REG(0xf0400000,0x22222222);
}

void Interrupt_UART1()
{

}

void Interrupt_I2S0()
{

}

void Interrupt_I2S1()
{

}

void Interrupt_RTC()
{

}

void Interrupt_TMR0()
{

}

void Interrupt_TMR1()
{

}

void Interrupt_GPIO0()
{

}

void Interrupt_GPIO1()
{

}

void Interrupt_I2C0()
{

}

*/
/*
Intc_InterruptFunction* IntrFunc[] =
{
	Interrupt_PAE,	//0
	Interrupt_VPU,	//1
	Interrupt_IPF,	//2
	Interrupt_IPB,	//3
	Interrupt_VOU,	//4
	Interrupt_JPEG,	//5
	NULL,			//6
	NULL,			//7
	Interrupt_DDRC,	//8
	Interrupt_DMAC,	//9
	Interrupt_AES,	//10
	Interrupt_MIPIC,//11
	Interrupt_WRAP,	//12
	Interrupt_PMU,	//13
	Interrupt_EMAC,	//14
	NULL,			//15
	NULL,			//16
	NULL,			//17
	NULL,			//18
	NULL,			//19
	NULL,			//20
	NULL,			//21
	NULL,			//22
	NULL,			//23
	Interrupt_SDC0,	//24
	Interrupt_SDC1,	//25
	Interrupt_ACW,	//26
	Interrupt_WDT,	//27
	Interrupt_SPI0,	//28
	Interrupt_SPI1,	//29
	Interrupt_UART0,//30
	Interrupt_UART1,//31
	Interrupt_I2S0,	//32
	NULL,			//33
	Interrupt_RTC,	//34
	NULL,			//35
	Interrupt_TMR0,	//36
	Interrupt_TMR1,	//37
	NULL,			//38
	NULL,			//39
	Interrupt_GPIO0,//40
	Interrupt_GPIO1,//41
	Interrupt_I2C0,	//42
};
*/


void Intc_HandleIrq()
{

	int funcNum;
	UINT32 irqLow, irqHigh;
	SET_REG(0xf0400000,0xdeadbeef);
	irqLow = GET_REG(REG_IRQ_FINSTATUS_LOW);
	irqHigh = GET_REG(REG_IRQ_FINSTATUS_HIGH);
	//read irq_plevel, if it is greater than current plevel
	if(irqLow)
	{
		SET_REG(0xf0400000, 0x4444);
		SET_REG(0xf0400000, irqLow);
		funcNum = 31 - __builtin_clz(irqLow);
		SET_REG(0xf0400000, funcNum);
		SET_REG(0xf0400000, (UINT32)IntrFunc[funcNum]);
		IntrFunc[funcNum]();
	}

	else if(irqHigh)
	{
		SET_REG(0xf0400000, 0x654);
		funcNum = 1 + __builtin_clz(irqHigh);
		SET_REG(0xf0400000, funcNum);
		SET_REG(0xf0400000, (UINT32)IntrFunc[funcNum]);
		IntrFunc[funcNum]();
	}

	SET_REG(0xf0400000,0xaaaaaaaa);
}


void Intc_HandleFiq()
{
	int funcNum;
	UINT32 fiqLow, fiqHigh;
	SET_REG(0xf0400000,0xbadc0de);
	fiqLow = GET_REG(REG_FIQ_FINSTATUS_LOW);
	fiqHigh = GET_REG(REG_FIQ_FINSTATUS_HIGH);

	//read irq_plevel, if it is greater than current plevel
	if(fiqLow)
	{
		SET_REG(0xf0400000, 0x321);
		funcNum = 31 - __builtin_clz(fiqLow);
		SET_REG(0xf0400000, funcNum);
		SET_REG(0xf0400000, (UINT32)IntrFunc[funcNum]);
		IntrFunc[funcNum]();
	}

	else if(fiqHigh)
	{
		SET_REG(0xf0400000, 0x543);
		funcNum = 1 + __builtin_clz(fiqHigh);
		SET_REG(0xf0400000, funcNum);
		SET_REG(0xf0400000, (UINT32)IntrFunc[funcNum]);
		IntrFunc[funcNum]();
	}

	SET_REG(0xf0400000,0xbbbbbbbb);
}


/*
void Intc_HandleIrq()
{

	int funcNum;

	SET_REG(0xf0400000,0xdeadbeef);

	//read irq_plevel, if it is greater than current plevel
	//status must not equal to 0, otherwise jump into intrfunc[32]

	if(pstIntcIrqModule->finalstatus_low.dw)
	{
		funcNum = 31 - __builtin_clz(pstIntcIrqModule->finalstatus_low.dw);
		SET_REG(0xa0000900, 0x321);
		SET_REG(0xa0000900, funcNum);
		SET_REG(0xa0000900, (UINT32)IntrFunc[funcNum]);
		IntrFunc[funcNum]();
	}

	else if(pstIntcIrqModule->finalstatus_high.dw)
	{
		funcNum = 1 + __builtin_clz(pstIntcIrqModule->finalstatus_high.dw);
		SET_REG(0xa0000900, 0x654);
		SET_REG(0xa0000900, funcNum);
		IntrFunc[funcNum]();
	}

	SET_REG(0xf0400000,0xaaaaaaaa);
}

void Intc_HandleFiq()
{
	int funcNum;

	SET_REG(0xf0400000,0xbadc0de);

	//read irq_plevel, if it is greater than current plevel
	//status must not equal to 0, otherwise jump into intrfunc[32]
	if(pstIntcFiqModule->finalstatus_low.dw)
	{
		funcNum = 31 - __builtin_clz(pstIntcFiqModule->finalstatus_low.dw);
		IntrFunc[funcNum]();
	}

	else if(pstIntcFiqModule->finalstatus_high.dw)
	{
		funcNum = 1 + __builtin_clz(pstIntcFiqModule->finalstatus_high.dw);
		IntrFunc[funcNum]();
	}

	SET_REG(0xf0400000,0xbbbbbbbb);
}
*/


void Intc_Init()
{

	pstIntcIrqModule = (volatile INTC_IRQ_MODULE_S*)(INTC_IRQ_BASE);
	pstIntcFiqModule = (volatile INTC_FIQ_MODULE_S*)(INTC_FIQ_BASE);


	SET_REG(REG_IRQ_EN_LOW, 0x40000000);
	SET_REG(REG_IRQ_EN_HIGH, 0);

	SET_REG(REG_FIQ_EN_LOW, 0x10000000);
	SET_REG(REG_FIQ_EN_HIGH, 0);

/*
	pstIntcIrqModule->inten_low.dw = 0x40000000;
	pstIntcIrqModule->inten_high.dw = 0x0;

	pstIntcFiqModule->inten_low.dw = 0x10000000;
	pstIntcFiqModule->inten_high.dw = 0x0;
*/

/*
	IntrFunc[31] = Interrupt_PAE;	//0
	IntrFunc[30] = Interrupt_VPU;	//1
	IntrFunc[29] = Interrupt_IPF;	//2
	IntrFunc[28] = Interrupt_IPB;	//3
	IntrFunc[27] = Interrupt_VOU;	//4
	IntrFunc[26] = Interrupt_JPEG;	//5
	IntrFunc[25] = NULL;				//6
	IntrFunc[24] = NULL;				//7
	IntrFunc[23] = Interrupt_DDRC;	//8
	IntrFunc[22] = Interrupt_DMAC;	//9
	IntrFunc[21] = Interrupt_AES;	//10
	IntrFunc[20] = Interrupt_MIPIC;	//11
	IntrFunc[19] = Interrupt_WRAP;	//12
	IntrFunc[18] = Interrupt_PMU;	//13
	IntrFunc[17] = Interrupt_EMAC;	//14
	IntrFunc[16] = NULL;				//15
	IntrFunc[15] = NULL;				//16
	IntrFunc[14] = NULL;				//17
	IntrFunc[13] = NULL;				//18
	IntrFunc[12] = NULL;				//19
	IntrFunc[11] = NULL;				//20
	IntrFunc[10] = NULL;				//21
	IntrFunc[9] = NULL;				//22
	IntrFunc[8] = NULL;				//23
	IntrFunc[7] = Interrupt_SDC0;	//24
	IntrFunc[6] = Interrupt_SDC1;	//25
	IntrFunc[5] = Interrupt_ACW;	//26
	IntrFunc[4] = Interrupt_WDT;	//27
	IntrFunc[3] = Interrupt_SPI0;	//28
	IntrFunc[2] = Interrupt_SPI1;	//29
	IntrFunc[1] = Interrupt_UART0;	//30
	IntrFunc[0] = Interrupt_UART1;	//31
	IntrFunc[0] = Interrupt_I2S0;	//32
	IntrFunc[0] = NULL;				//33
	IntrFunc[0] = Interrupt_RTC;	//34
	IntrFunc[0] = NULL;				//35
	IntrFunc[0] = Interrupt_TMR0;	//36
	IntrFunc[0] = Interrupt_TMR1;	//37
	IntrFunc[0] = NULL;				//38
	IntrFunc[0] = NULL;				//39
	IntrFunc[0] = Interrupt_GPIO0;	//40
	IntrFunc[0] = Interrupt_GPIO1;	//41
	IntrFunc[0] = Interrupt_I2C0;	//42
*/
}
