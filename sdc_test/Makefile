#CROSS = arm-fullhan-linux-gnueabi-
#CROSS = arm-hik_armv5-linux-uclibcgnueabi-
CROSS = arm-fullhan-linux-uclibcgnueabi-
CC          = $(CROSS)gcc
CXX         = $(CROSS)g++
AS          = $(CROSS)as
LD          = $(CROSS)ld
AR          = $(CROSS)ar
NM          = $(CROSS)nm
STRIP       = $(CROSS)strip
RANLIB      = $(CROSS)ranlib
OBJDUMP     = $(CROSS)objdump
OBJCOPY     = $(CROSS)objcopy
ROOTDIR = $(shell pwd)

CFLAGS = $(DBGFLAGS) $(OPTFLAGS) $(BSPFLGS) -I$(ROOTDIR)/inc \
 			-g -Wall -Wstrict-prototypes -fomit-frame-pointer -ffreestanding \
 			-fno-strict-aliasing -fno-common -fno-builtin  -msoft-float -pipe \
			-nostdinc -isystem $(shell $(CC) -print-file-name=include) 

ASFLAGS		= $(CFLAGS) -D__ASSEMBLY_
BUILD_DIR  ?= debug

START   := start.o 
COBJS   := ddrc.o sdc.o  sdcard.o  
CSRCS   := $(COBJS:.o=.c)
COBJS	:= $(addprefix $(BUILD_DIR)/,$(COBJS) main.o)
START	:= $(addprefix $(BUILD_DIR)/,$(START))
outna   := sdc_test
elf      = $(outna)_elf
bin      = $(outna)_bin
dis      = $(outna)_dis
.PHONY : all clean

all: CHK_BUILD_DIR $(COBJS) $(START)
	$(LD) -Bstatic -Tlink.lds $(START) --start-group $(COBJS) --end-group \
			-L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) \
	        -lgcc -o $(BUILD_DIR)/$(elf) -Map $(BUILD_DIR)/bin_map
	$(OBJCOPY) --gap-fill=0xff -O binary -S $(BUILD_DIR)/$(elf) $(BUILD_DIR)/$(bin)
	$(OBJDUMP) -D -m arm $(BUILD_DIR)/$(elf) > $(BUILD_DIR)/$(dis)
	$(NM)  -n  $(BUILD_DIR)/$(elf) > $(BUILD_DIR)/systemromboot.map

CHK_BUILD_DIR:
	[ -d $(BUILD_DIR) ] || mkdir $(BUILD_DIR) || exit 1
	
$(BUILD_DIR)/%.o: src/%.c
	$(CC) -Os -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/main.o: main.c
	$(CC) -Os -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/start.o: start.s
	$(CC) -Os -c $(CFLAGS) -o $@ $<


clean:
	-rm -rf $(BUILD_DIR) *.o *.bak *.map *.bin *.dis $(elf)
#	rm -rf ./debug
#	rm -f RamBoot.bin RamBoot_elf RamBoot.dis *.o		