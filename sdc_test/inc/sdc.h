#ifndef SDC_N_H_
#define SDC_N_H_

#include "pre_define.h"
#include "chip_reg.h"

#define SDC_CLOCK_IN 50000000
#define UNSTUFF_BITS(resp,start,size)					\
	({								\
		const int __size = size;				\
		const UINT32 __mask = (__size < 32 ? 1 << __size : 0) - 1;	\
		const int __off = 3 - ((start) / 32);			\
		const int __shft = (start) & 31;			\
		UINT32 __res;						\
									\
		__res = resp[__off] >> __shft;				\
		if (__size + __shft > 32)				\
			__res |= resp[__off-1] << ((32 - __shft) % 32);	\
		__res & __mask;						\
	})
enum
{
	sdc_card_status_idel,
	sdc_card_status_ready,
	sdc_card_status_ident,
	sdc_card_status_stby,
	sdc_card_status_tran,
	sdc_card_status_data,
	sdc_card_status_rcv,
	sdc_card_status_prg,
	sdc_card_status_dis
};

enum
{
	sdc_data_transfer_none = 0,
	sdc_data_transfer_read = 1,
	sdc_data_transfer_write = 3,
};

enum
{
	sdc_response_type_none = 0,
	sdc_response_type_short = 1,
	sdc_response_type_long = 3,
};


enum
{
	sdc_status_cmdIsTakenByCIU = 1
};


enum
{
	sdc_cardWidth_1bit = 0x0,
	sdc_cardWidth_4bit = 0x1,
	sdc_cardWidth_8bit = 0x10000
};

enum
{
	sdc_interrupt_cardDetect = 0x1,
	sdc_interrupt_responseError = 0x1 << 1,
	sdc_interrupt_commandDone = 0x1 << 2,
	sdc_interrupt_dataTransferOver = 0x1 << 3,
	sdc_interrupt_transmitFIFODataRequest = 0x1 << 4,
	sdc_interrupt_receiveFIFODataRequest = 0x1 << 5,
	sdc_interrupt_responseCRCError = 0x1 << 6,
	sdc_interrupt_dataCRCError = 0x1 << 7,
	sdc_interrupt_responseTimeout = 0x1 << 8,
	sdc_interrupt_dataReadTimeout = 0x1 << 9,
	sdc_interrupt_dataStarvationByHostTimeout = 0x1 << 10,
	sdc_interrupt_fifoUnderrunOverrunError = 0x1 << 11,
	sdc_interrupt_hardwareLockedWriteError = 0x1 << 12,
	sdc_interrupt_startBitError = 0x1 << 13,
	sdc_interrupt_autoCommandDone = 0x1 << 14,
	sdc_interrupt_endBitErrorOrWriteNoCRC = 0x1 << 15,
	sdc_interrupt_card0 = 0x1 << 16,
	sdc_interrupt_sdcard_all = 0xfffe,
	sdc_interrupt_sdio = 0xffff<<16,
	sdc_interrupt_all = 0xffffffff,
	sdc_interrupt_none = 0x0
};



enum
{
	sdc_idmac_interrupt_transmit = 0x1,
	sdc_idmac_interrupt_receive = 0x1 << 1,
	sdc_idmac_interrupt_fatalBusError = 0x1 << 2,
	sdc_idmac_interrupt_descriptorUnavailable = 0x1 << 4,
	sdc_idmac_interrupt_cardErrorSummary = 0x1 << 5,
	sdc_idmac_interrupt_normalInterruptSummary = 0x1 << 8,
	sdc_idmac_interrupt_abnormalInterruptSummary = 0x1 << 9,
	sdc_idmac_interrupt_all = 0xffff
};

enum
{
	sdc_idmac_burst_size_1transfer,
	sdc_idmac_burst_size_4transfers,
	sdc_idmac_burst_size_8transfers,
	sdc_idmac_burst_size_16transfers,
	sdc_idmac_burst_size_32transfers,
	sdc_idmac_burst_size_64transfers,
	sdc_idmac_burst_size_128transfers,
	sdc_idmac_burst_size_256transfers
	
};


enum
{
	sdio_cccr_revision = 0x0,
	sdio_sd_spec_revision = 0x1,
	sdio_io_enable = 0x2,
	sdio_io_ready = 0x3,
	sdio_interrupt_enable = 0x4,
	sdio_interrupt_pending = 0x5,
	sdio_io_abort = 0x6,
	sdio_bus_interface_ctrl = 0x7,
	sdio_card_capability = 0x8,
	sdio_common_cis_pointer = 0x9,
	sdio_bus_suspend = 0xc,
	sdio_function_select = 0xd,
	sdio_exec_flags = 0xe,
	sdio_ready_flags = 0xf,
	sdio_fn0_block_size = 0x10,
	sdio_power_control = 0x12,
	sdio_bus_speed_select = 0x13,
	sdio_uhsi_support = 0x14,
	sdio_driver_strength = 0x15,
	sdio_interrupt_extension = 0x16
};


typedef union
{
	struct
	{
		UINT32	reserved							:1; //0~15
		UINT32	disable_interrupt_on_completion		:1; //16~31
		UINT32	last_descriptor						:1; //0~15
		UINT32	first_descriptor					:1; //16~31
		UINT32	sencond_address_chained				:1; //0~15
		UINT32	end_of_ring							:1; //16~31
		UINT32	reserved_29_6						:24; //0~15
		UINT32	card_error_summary					:1; //16~31
		UINT32	own									:1; //16~31
	}bit;
	UINT32 dw;
}Reg_Sdc_Descriptor0;

typedef union
{
	struct
	{
		UINT32	buffer1_size						:13; //0~15
		UINT32	buffer2_size						:13; //16~31
		UINT32	reserved_26_31						:6; //0~15
	}bit;
	UINT32 dw;
}Reg_Sdc_Descriptor1;

typedef union
{
	struct
	{
		UINT32	buffer_address_pointer1						:32; //0~15
	}bit;
	UINT32 dw;
}Reg_Sdc_Descriptor2;

typedef union
{
	struct
	{
		UINT32	buffer_address_pointer2						:32; //0~15
	}bit;
	UINT32 dw;
}Reg_Sdc_Descriptor3;

typedef struct
{
	Reg_Sdc_Descriptor0 desc0;   	 /* control and status information of descriptor */
	Reg_Sdc_Descriptor1 desc1;   	 /* buffer sizes                                 */
	Reg_Sdc_Descriptor2 desc2;   	 /* physical address of the buffer 1             */
	Reg_Sdc_Descriptor3 desc3;    	 /* physical address of the buffer 2             */
}Sdc_Internal_DMA_Descriptors;



typedef union
{
	struct
	{
		UINT32	reserved_14_0					:15;//0~14
		UINT32	voltage_range_27_28				:1;	//15
		UINT32	voltage_range_28_29				:1;	//16
		UINT32	voltage_range_29_30				:1;	//17
		UINT32	voltage_range_30_31				:1;	//18
		UINT32	voltage_range_31_32				:1;	//19
		UINT32	voltage_range_32_33				:1;	//20
		UINT32	voltage_range_33_34				:1;	//21
		UINT32	voltage_range_34_35				:1;	//22
		UINT32	voltage_range_35_36				:1;	//23
		UINT32	reserved_29_24					:6; //24~29
		UINT32	card_capacity_status			:1;	//30
		UINT32	card_power_up_status			:1; //31
	}bit;
	UINT32 dw;
}Reg_Sdc_Ocr;

typedef union
{
	struct
	{
		UINT32	reserved_2_0				:3;//0~2
		UINT32	ake_seq_error				:1;	//3
		UINT32	reserved					:1;	//4
		UINT32	app_cmd						:1;	//5
		UINT32	reserved_7_6				:2;	//6~7
		UINT32	ready_for_data				:1;	//8
		UINT32	current_state				:4;	//9~12
		UINT32	error						:1;	//13
		UINT32	illegal_command				:1;	//14
		UINT32	com_crc_error				:1;	//15
		UINT32	relative_card_addr			:16; //16~31

	}bit;
	UINT32 dw;
}Reg_Sdc_Rca;

typedef union
{
	struct
	{
		UINT32	reserved_15_0			:16;//0~15
		UINT32	sd_bus_width			:4; //16~19
		UINT32	sd_security				:3; //20~22
		UINT32	data_stat_after_erase	:1; //23
		UINT32	sd_spec					:4; //24~27
		UINT32	scr_structure			:4; //28~31
	}bit;
	UINT32 dw;
}Reg_Sdc_Scr;

typedef union
{
	struct
	{
		UINT32	write_data			:8;
		UINT32	reserved_8			:1;
		UINT32	register_addr		:17;
		UINT32	reserved_26			:1;
		UINT32	raw_flag			:1;
		UINT32	func_num			:3;
		UINT32	rw_flag				:1;
	}bit;
	UINT32 dw;
}Reg_Sdio_IORW_Cmd;

typedef union
{
	struct
	{
		UINT32	data_count			:9;
		UINT32	register_addr		:17;
		UINT32	op_code				:1;
		UINT32	block_mode			:1;
		UINT32	func_num			:3;
		UINT32	rw_flag				:1;
	}bit;
	UINT32 dw;
}Reg_Sdio_IORW_Extended;

typedef union
{
	struct
	{
		UINT32	data				:8;
		UINT32	out_of_range		:1;
		UINT32	func_num_error		:1;
		UINT32	reserved_18			:1;
		UINT32	error				:1;
		UINT32	io_current_state	:2;
		UINT32	illegal_cmd			:1;
		UINT32	crc_error			:1;
		UINT32	reserved_31_16		:16;

	}bit;
	UINT32 dw;
}Reg_Sdio_IORW_Resp;

struct Sdc_Object;

typedef struct Sdc_Object
{
	int device_id;
	int is_high_capacity;	//read only
	int card_rca;
	int card_width;
	int clock_feq;
	int dma_brust_size;
	int block_size;

	volatile Sdc_Internal_DMA_Descriptors* dma_descriptors;

}Sdc_Object;


void SDC_Init(Sdc_Object* sdc_obj);
void SDC_DmaDescriptorInit(Sdc_Object* sdc_obj);
int SDC_UpdateClockRegister(Sdc_Object* sdc_obj, int clock);
int SDC_SendAppCommand(Sdc_Object* sdc_obj, int cmdIndex, UINT32 argument, int responseType, int readWrite, int waitPrvData, int stopCmd);
int SDC_SendCommand(Sdc_Object* sdc_obj, int cmdIndex, UINT32 argument, int responseType, int readWrite, int waitPrvData, int stopCmd);
UINT32 SDC_SDIO_Cmd52_Read(Sdc_Object* sdc_obj, UINT32 address, int funcNum);
void SDC_Cmd52Write(Sdc_Object* sdc_obj, UINT32 address, int funcNum, UINT32 data);
UINT32 SDC_Cmd52Read(Sdc_Object* sdc_obj, UINT32 address, int funcNum);
void SDC_Cmd53Write(Sdc_Object* sdc_obj, UINT32 cardAddress, int blockCount);
void SDC_Cmd53Write_byte(Sdc_Object* sdc_obj, UINT32 cardAddress, int b_size);
void SDC_Cmd53Read(Sdc_Object* sdc_obj, UINT32 cardAddress, int blockCount);
#endif /*SDC_N_H_*/
