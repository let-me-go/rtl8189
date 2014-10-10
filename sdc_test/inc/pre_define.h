#ifndef TYPE_FUNC_H_
#define TYPE_FUNC_H_

typedef unsigned char		UINT8;
typedef unsigned short		UINT16;
typedef unsigned int		UINT32;
typedef unsigned int		uint32;
typedef unsigned long long	UINT64;

typedef char				SINT8;
typedef short				SINT16;
typedef int					SINT32;
typedef long long			SINT64;


typedef void (*FPVV)();			//function pointer return void input void
typedef int (*FPIV)();		//function pointer return INT32 input void
typedef void (*FPVI)(int data);	//function pointer return void input INT32
typedef int (*FPII)(int data);	//function pointer return INT32 input INT32

#define FALSE 				(0)
#define TRUE 				(!FALSE)

#define LOW 				(0)
#define HIGH 				(1)

#ifndef NULL
#define NULL 				(0)
#endif

#define FAILED				(0)
#define OK					(!FAILED)


#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define CLIP(x,min,max) MAX((min),MIN((x),(max)))

#define reg_read(addr) (*((volatile UINT32 *)(addr)))
#define reg_write(addr,value) (*(volatile UINT32 *)(addr)=(value))

#define GET_REG(addr) reg_read(addr)
#define SET_REG(addr,value) reg_write(addr,value)
#define SET_REG_M(addr,value,mask) reg_write(addr,(reg_read(addr)&(~(mask)))|((value)&(mask)))
#define SET_REG_B(addr,element,highbit,lowbit) SET_REG_M((addr),((element)<<(lowbit)),(((1<<((highbit)-(lowbit)+1))-1)<<(lowbit)))

#define GET_REG8(addr) (*((volatile UINT8 *)(addr)))
#define SET_REG8(addr,value) (*(volatile UINT8 *)(addr)=(value))

#define LD8(addr) 			(*((volatile u8 *)(addr)))
#define ST8(addr,value)		(*(volatile u8 *)(addr)=(value))
#define LD16(addr) 			(*((volatile u16 *)(addr)))
#define ST16(addr,value)	(*(volatile u16 *)(addr)=(value))
#define LD32(addr)			(*((volatile u32 *)(addr)))
#define ST32(addr,value)	(*(volatile u32 *)(addr)=(value))
#define read_reg(addr)  (*((volatile uint32 *)(addr)))
#define read_reg(addr)  (*((volatile uint32 *)(addr)))
#define write_reg(addr, reg)  (*((volatile uint32 *)(addr))) = (uint32)(reg)
#define DELAY(times)  do{\
	int i=0;\
	for(i=0;i<times;i++){}\
}while(0)


#define lift_shift_bit_num(bit_num)			(1<<bit_num)
#endif /*TYPE_FUNC_H_*/
