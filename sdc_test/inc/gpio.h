#ifndef GPIO_H_
#define GPIO_H_
#include "pre_define.h"
//uint32 GpioInit(void);
//uint32 GetGpioData(void);

typedef enum{
	GPIO_NOR_MODE,
	GPIO_INT_MODE
}Gpio_Mode;
typedef enum
{   
	GPIO_LEVEL_LOW,
	GPIO_LEVEL_HIGH ,
	
}Gpio_Level;


typedef enum
{
	GPIO_DIR_IN,
	GPIO_DIR_OUT
	
}Gpio_Direction;
typedef enum{
	GPIO_INT_YYPE_LEVEL,
	GPIO_INT_YYPE_EDGE
	
}Gpio_Int_Pol;

typedef enum{
	
	GPIO_INT_POL_FALL,
	GPIO_INT_POL_RISK 
}Gpio_Int_Sens;

typedef enum
{
	GPIO_INT_UNTRIGGERED,
	GPIO_INT_TRIGGERED
}Gpio_Int_Status;

enum
{
	GPIO_EVENT_DOWN,
	GPIO_EVENT_UP,
	GPIO_EVENT_NONE = 9999
};

enum
{
	GPIO_BUTTON_UP = 15,
	GPIO_BUTTON_LEFT = 16,
	GPIO_BUTTON_DOWN = 17,
	GPIO_BUTTON_RIGHT = 18,
	GPIO_BUTTON_MENU = 19,
	GPIO_BUTTON_NONE = 999
};

#define		GPIO_REG_BASE			(0xf0300000)

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




#define TB_OPEN			0
#define ISP_OPEN 		1
#define CFG_OPEN		0
#define TAE_SIMULATION 	0
#define SENSOR_OPEN	    1
#define OPEN_3DNR		0
#define BANDWIDTHTEST	0

typedef struct tag_GPIO_EVENT //
{
	unsigned short sbutton;								// left/right/up/down/menu
	unsigned short sEvent __attribute__((packed));		// up/down
	unsigned int   iTime;
}GPIO_EVENT;

UINT32 Gpio_Init(UINT32 LEVEL,UINT32 POLARITY);

UINT32 Gpio_GetPortX(UINT32 idx);
UINT32 Gpio_GetPort(void);
void Gpio_SetPortX(UINT32 idx, UINT32 val);
void Gpio_SetPort(UINT32 val);
void Gpio_SetDirectionX(UINT32 idx, UINT32 val);
void Gpio_SetDirection(UINT32 val);
UINT32 Gpio_GetDirectionX(UINT32 idx);
UINT32 Gpio_GetDirection(void);
void Gpio_EnableIntX(UINT32 idx);
void Gpio_EnableInt(UINT32 val);
void Gpio_DisableIntX(UINT32 idx);
void Gpio_DisableInt(UINT32 val);
void Gpio_SetIntTypeX(UINT32 idx, UINT32 val);
void Gpio_SetIntType(UINT32 val);
void Gpio_SetIntPolX(UINT32 idx, UINT32 val);
void Gpio_SetIntPol(UINT32 val);
void Gpio_ClrIntX(UINT32 idx);
void Gpio_ClrInt(UINT32 val);
UINT32 Gpio_GetIntX(UINT32 idx);
UINT32 Gpio_GetInt(void);
#endif /*GPIO_H_*/
