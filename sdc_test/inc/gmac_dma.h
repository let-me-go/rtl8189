#ifndef GMAC_DMA_H_
#define GMAC_DMA_H_
/*
enum
{
	gmac_error_underflow_error,
	gmac_error_excessive_deferral,
	gmac_error_excessive_collision,
	gmac_error_late_collision,
	gmac_error_no_carrier,
	gmac_error_carrier_loss,
	gmac_error_payload_checksum_error,
	gmac_error_frame_flush,
	gmac_error_jabber_timeout,
	gmac_error_ip_header_error
	
};
*/
typedef union 
{
	struct 
	{
		UINT32	deferred						:1; //0~31
		UINT32	underflow_error					:1;	
		UINT32	excessive_deferral				:1;	
		UINT32	collision_count					:4;	
		UINT32	vlan_frame						:1;	
		UINT32	excessive_collision				:1;	
		UINT32	late_collision					:1;	
		UINT32	no_carrier						:1;	
		UINT32	loss_of_carrier					:1;	
		UINT32	payload_checksum_error			:1;	
		UINT32	frame_flushed					:1;
		UINT32	jabber_timeout					:1;
		UINT32	error_summary					:1;
		UINT32	ip_header_error					:1;
		UINT32	tx_timestamp_status				:1;	
		UINT32	reserved_30_18					:13;	
		UINT32	own								:1;
	}bit;
	UINT32 dw;
}Gmac_Tx_Descriptor0;

typedef union 
{
	struct 
	{
		UINT32	buffer1_size					:11; //0~31
		UINT32	buffer2_size					:11;	
		UINT32	timestamp_enable				:1;	
		UINT32	disable_padding					:1;	
		UINT32	second_address_chained			:1;	
		UINT32	end_of_ring						:1;	
		UINT32	disable_crc						:1;	
		UINT32	checksum_insertion_ctrl			:2;	
		UINT32	first_segment					:1;	
		UINT32	last_segment					:1;	
		UINT32	disable_intr_on_completion		:1;
	}bit;
	UINT32 dw;
}Gmac_Tx_Descriptor1;

typedef union 
{
	struct 
	{
		UINT32	buffer_address_pointer					:32; //0~31
	}bit;
	UINT32 dw;
}Gmac_Tx_Descriptor2;

typedef union 
{
	struct 
	{
		UINT32	buffer_address_pointer					:32; //0~31
	}bit;
	UINT32 dw;
}Gmac_Tx_Descriptor3;

typedef union 
{
	struct 
	{
		UINT32	mac_addr_payload_chksum_error	:1; //0
		UINT32	crc_error						:1;	//1
		UINT32	dribble_error					:1;	//2
		UINT32	receive_error					:1;	//3
		UINT32	watchdog_timeout				:1;	//4
		UINT32	frame_type						:1;	//5
		UINT32	late_collision					:1;	//6
		UINT32	ipc_chksum_error_giant_frame	:1;	//7
		UINT32	last_descriptor					:1;	//8
		UINT32	first_descriptor				:1;	//9
		UINT32	vlan_tag						:1; //10
		UINT32	overflow_error					:1; //11
		UINT32	length_error					:1; //12
		UINT32	sa_filter_fail					:1; //13
		UINT32	descriptor_error				:1; //14
		UINT32	error_summary					:1;	//15
		UINT32	frame_length					:14;//16~29
		UINT32	da_filter_fail					:1;	//30
		UINT32	own								:1; //31
	}bit;
	UINT32 dw;
}Gmac_Rx_Descriptor0;

typedef union 
{
	struct 
	{
		UINT32	buffer1_size					:11; //0~10
		UINT32	buffer2_size					:11; //11~21
		UINT32	reserved_23_22					:2;  //22~23
		UINT32	second_address_chained			:1;	 //24
		UINT32	end_of_ring						:1;	 //25
		UINT32	reserved_30_26					:5;	 //26~30
		UINT32	disable_intr_on_completion		:1;  //31
	}bit;
	UINT32 dw;
}Gmac_Rx_Descriptor1;

typedef union 
{
	struct 
	{
		UINT32	buffer_address_pointer					:32; //0~31
	}bit;
	UINT32 dw;
}Gmac_Rx_Descriptor2;

typedef union 
{
	struct 
	{
		UINT32	buffer_address_pointer					:32; //0~31
	}bit;
	UINT32 dw;
}Gmac_Rx_Descriptor3;

typedef struct
{
	Gmac_Tx_Descriptor0 desc0;   	 /* control and status information of descriptor */
	Gmac_Tx_Descriptor1 desc1;   	 /* buffer sizes                                 */
	Gmac_Tx_Descriptor2 desc2;   	 /* physical address of the buffer 1             */
	Gmac_Tx_Descriptor3 desc3;    	 /* physical address of the buffer 2             */
}Gmac_Tx_DMA_Descriptors;

typedef struct
{
	Gmac_Rx_Descriptor0 desc0;   	 /* control and status information of descriptor */
	Gmac_Rx_Descriptor1 desc1;   	 /* buffer sizes                                 */
	Gmac_Rx_Descriptor2 desc2;   	 /* physical address of the buffer 1             */
	Gmac_Rx_Descriptor3 desc3;    	 /* physical address of the buffer 2             */
}Gmac_Rx_DMA_Descriptors;





#endif /*GMAC_DMA_H_*/
