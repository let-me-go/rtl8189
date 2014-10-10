/**
* @file			
* @brief  
* @version 
* @author		xuww
* @date			
* @note
*      
*      
* @copy
*
* 此代码为上海富瀚微电子有限公司项目代码，任何人及公司未经许可不得复制传播，或用于
* 本公司以外的项目。本司保留一切追究权利。
*
* <h1><center>&copy; COPYRIGHT 2013 fullhan</center></h1>
*/
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

#include "pre_define.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



/*******************************************************************************
* Function Name  : Gpio_GetPortX
* Description    : get the 0 based GPIO port value.
* Input          : idx : 0 based port number.
* Output         : None
* Return         : 0 		: un-signed.   other 	: signed.
* 		                                      
 *******************************************************************************/


UINT32 Gpio_GetPortX(UINT32 idx)
{
	UINT32 gpio;

	gpio = GET_REG(REG_GPIO_EXT_PORTA);

	//return (gpio >> idx) & 1;
	if( gpio & ( 1 << idx ) )
		return GPIO_LEVEL_HIGH;
	else
		return GPIO_LEVEL_LOW;
//	return gpio & ( 1 << idx );
}
/*******************************************************************************
* Function Name  : Gpio_GetPort
* Description    : get the port-a GPIO value.
* Input          : None
* Output         : None
* Return         : 0 		: un-signed.   other 	: signed.
* 		                                      
 *******************************************************************************/

UINT32 Gpio_GetPort(void)
{
	return GET_REG(REG_GPIO_EXT_PORTA);
}
/*******************************************************************************
* Function Name  : Gpio_SetPortX
* Description    : Set the 0-based GPIO port to value val.
* Input          : idx : the 0-based GPIO port number
*                  val : 0 to clear the given port
* 			             1 to set the given port.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetPortX(UINT32 idx, UINT32 val)
{
	UINT32 gpio = Gpio_GetPort();
	if( val ==GPIO_LEVEL_HIGH)
	{
		gpio |= 1 << idx;
	}
	else
	{
		gpio &= ~( 1 << idx );
	}
	Gpio_SetPort( gpio );
}
/*******************************************************************************
* Function Name  : Gpio_SetPort
* Description    : Set the GPIO to a given value.
* Input          : val : the value to be set to the GPIO.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetPort(UINT32 val)
{
	SET_REG(REG_GPIO_SWPORTA_DR, val);
}
/*******************************************************************************
* Function Name  : Gpio_SetDirectionX
* Description    : Set the 0-based GPIO port direction(IN/OUT)
* Input          : idx : the 0-based GPIO port number
*  		           val : GPIO_DDR_IN  to set the GPIO Input,
* 			             GPIO_DDR_OUT to set the GPIO Output.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetDirectionX(UINT32 idx, UINT32 val)
{
	UINT32 gpio = Gpio_GetDirection();
	if( val==GPIO_DIR_OUT )
	{
		gpio |= 1 << idx;
	}
	else
	{
		gpio &= ~(1 << idx);
	}
	Gpio_SetDirection( gpio );
}
/*******************************************************************************
* Function Name  : Gpio_SetDirection
* Description    : Set GPIO Port Direction
* Input          : al : the GPIO Port Direction Settings. each bit set to 1 will set the port Output
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetDirection(UINT32 val)
{
	SET_REG(REG_GPIO_SWPORTA_DDR, val);
}
/*******************************************************************************
* Function Name  : Gpio_SetDirectionX
* Description    : Get the 0-based GPIO Port Direction Setting.
* Input          : idx : the 0-based GPIO Port number
* Output         : None
* Return         : GPIO_DIR_IN:  the given port is set Input
* 		           GPIO_DIR_OUT: the given port is set Output.
* 		                                      
 *******************************************************************************/

UINT32 Gpio_GetDirectionX(UINT32 idx)
{
	UINT32 gpio = Gpio_GetDirection();

	if( gpio & ( 1 << idx ) )
		return GPIO_DIR_OUT;
	else
		return GPIO_DIR_IN;
}
/*******************************************************************************
* Function Name  : Gpio_GetDirection
* Description    : Get the GPIO Port Direction Settings.
* Input          : None
* Output         : None
* Return         : the GPIO Port Direction Settings, each bit set to 1 means that port is used as OUTPUT.
* 		           otherwise, that port is used as INPUT
* 		                                      
 *******************************************************************************/

UINT32 Gpio_GetDirection()
{
	return GET_REG(REG_GPIO_SWPORTA_DDR);
}
/*******************************************************************************
* Function Name  : Gpio_EnableIntX
* Description    : enable the 0-based GPIO port to generate Interrupt
* Input          : idx : the 0-based GPIO port number
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_EnableIntX(UINT32 idx)
{
	UINT32 gpio = GET_REG(REG_GPIO_INTEN);
	gpio |= 1 << idx;
	Gpio_EnableInt( gpio );
}
/*******************************************************************************
* Function Name  : Gpio_EnableInt
* Description    : Set the GPIO Interrupt config.
* Input          : val : the Inerrupt config, each bit set to 1 to make the corresponding port to generate interrupt.
*                  else, the corresponding port is discouraged to generate interrupt
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_EnableInt(UINT32 val)
{
	SET_REG(REG_GPIO_INTEN, val);
}
/*******************************************************************************
* Function Name  : Gpio_DisableIntX
* Description    : Disable the 0-based GPIO port interrupt.
* Input          : idx : the 0-based GPIO port number.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_DisableIntX(UINT32 idx)
{
	UINT32 gpio = GET_REG(REG_GPIO_INTEN);
	gpio &= ~(1 << idx);
	Gpio_DisableInt( gpio );
}
/*******************************************************************************
* Function Name  : Gpio_DisableInt
* Description    : Disable the GPIO config.
* Input          : val : the GPIO config to disable interrupt. each set to 1 will mask the port to generate interrupt.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_DisableInt(UINT32 val)
{
	SET_REG(REG_GPIO_INTEN, ~val);
}
/*******************************************************************************
* Function Name  : Gpio_SetIntTypeX
* Description    : Set the 0-based GPIO Port Interrupt Type
* Input          : idx : the 0-based GPIO port number
*                  GPIO_INT_EDGE  to set the interrupt edge-triggererd.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetIntTypeX(UINT32 idx, UINT32 val)
{
	UINT32 gpio;

	gpio = GET_REG(REG_GPIO_INTTYPE_LEVEL);
	if( GPIO_INT_YYPE_EDGE == val )
	{
		gpio |= 1 << idx;
	}
	else
	{
		gpio &= ~(1 << idx);
	}
	SET_REG(REG_GPIO_INTTYPE_LEVEL, gpio );
}
/*******************************************************************************
* Function Name  : Gpio_SetIntType
* Description    : Set the GPIO Interrupt trigger type
* Input          : val : the GPIO interrupt trigger type config. each bit set to 1 will set the port edge-triggered.
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetIntType(UINT32 val)
{
	SET_REG(REG_GPIO_INTTYPE_LEVEL, val );
}
/*******************************************************************************
* Function Name  : Gpio_SetIntPolX
* Description    : Set the GPIO Interrupt polarity
* Input          : idx : the 0-based GPIO port number
* 		           val : GPIO_POL_LOW to set the GPIO active low to generate interrupt(or down for edge-trigger)
* 			             GPIO_POL_HIGH to set the GPIO active high to generate interrupt or up for edge-trigger)
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetIntPolX(UINT32 idx, UINT32 val)
{
	UINT32 gpio = GET_REG(REG_GPIO_INT_POLARITY);
	if( val == GPIO_INT_POL_RISK)
	{
		gpio |= 1 << idx;
	}
	else
	{
		gpio &= ~( 1 << idx );
	}
	Gpio_SetIntPol( gpio );
}
/*******************************************************************************
* Function Name  : Gpio_SetIntPol
* Description    : Set the GPIO Interrupt polarity.
* Input          : val : the GPIO Interrupt polarity config, each bit set to 1 will set the port active high to gen interrupt.
* 		           
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_SetIntPol(UINT32 val)
{
	SET_REG( REG_GPIO_INT_POLARITY, val );
}
/*******************************************************************************
* Function Name  : Gpio_ClrIntX
* Description    : Clear the 0-based GPIO port's interrupt.
* Input          : idx : the 0-based GPIO Port number.           
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_ClrIntX(UINT32 idx)
{
	SET_REG( REG_GPIO_PORTA_EOI, 1 << idx );
}
/*******************************************************************************
* Function Name  : Gpio_ClrInt
* Description    : Clear all the GPIO Interrupt.
* Input          : val : the interrupts to be cleared. each bit set to 1 will clear the corresponding port's interrupt.           
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

void Gpio_ClrInt(UINT32 val)
{
	SET_REG( REG_GPIO_PORTA_EOI, val );
}
/*******************************************************************************
* Function Name  : Gpio_GetIntX
* Description    : Get the 0-based GPIO port Interrupt status.
* Input          : idx : the 0-based GPIO port number.           
* Output         : None
* Return         : GPIO_INT_UNTRIGGERED, the port has no interrupt generated.
* 		           GPIO_INT_TRIGGERED,   the port has triggered an interrupt.
* 		                                      
 *******************************************************************************/

UINT32 Gpio_GetIntX(UINT32 idx)
{
	UINT32 gpio = GET_REG(REG_GPIO_INTSTATUS);
	if( gpio & ( 1 << idx ) )
		return GPIO_INT_UNTRIGGERED;
	else
		return GPIO_INT_TRIGGERED;
}
/*******************************************************************************
* Function Name  : Gpio_GetInt
* Description    : Get the GPIO Interrupt status.
* Input          : None           
* Output         : None
* Return         : the GPIO Interrupt status(masked, not RAW).
* 		                                      
 *******************************************************************************/

UINT32 Gpio_GetInt()
{
	return GET_REG(REG_GPIO_INTSTATUS);
}
/*******************************************************************************
* Function Name  : Gpio_Init
* Description    : GPIO init
* Input          : LEVEL: INT EDGE OR LEVEL SENSITIVE    
*                  POLARITY: TRIGGER SENSITIVE           
* Output         : None
* Return         : None
* 		                                      
 *******************************************************************************/

UINT32 Gpio_Init(UINT32 LEVEL,UINT32 POLARITY)
{
	
	Gpio_SetDirection(0x180080);//1 output 0 input 
	SET_REG(REG_GPIO_INTTYPE_LEVEL,	0x00000);	//INT Edge Sensitive  1 level  0 edge
	SET_REG(REG_GPIO_INT_POLARITY, 	0xfffff);	//TRIGGER FOR both edge  1 high   0 low
	SET_REG(REG_GPIO_INTEN,			0x40040);   // 1  int  0 normol


	
	return 0;
}



