.globl _main
.globl start
start:
	b _reset
_reset:

#----------------------------------------------
#	Set CPU mode, flush caches, etc.
#----------------------------------------------
	#set the cpu to svc32 mode
	#turn off IRQ/FIQ bit of CPU
	mrs	r0,cpsr
	bic	r0,r0,#0x1f
	orr	r0,r0,#0xd3
	msr	cpsr_c,r0

	#vector 0x0
	#enable icaches
	#little endian
	#disable dcaches, mmu
	ldr r0, =0x0000107a
    mcr p15, 0, r0, c1, c0, 0

    ldr r0, =0x00000000
    mcr p15, 0, r0, c8, c7, 0 	@Flush TLB
    mcr p15, 0, r0, c7, c7, 0 	@ Flush Caches
    mcr p15, 0, r0, c7, c10, 4 	@ Flush Write Buffer

    @svc mode
    msr		cpsr_c,#0xd3
	ldr		sp, =0x10003800



@----------------------------------------------
@	jump to main
@----------------------------------------------



    b _main
