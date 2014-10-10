OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
/*OUTPUT_FORMAT("elf32-arm", "elf32-arm", "elf32-arm")*/
/*ָ�������ִ���ļ���elf��ʽ,32λARMָ��,С��*/
OUTPUT_ARCH(arm)

ENTRY(start)
SECTIONS {
     . = 0x10000000;
     .text :   { *(.text) }
     .rodata ALIGN(4) : {*(.rodata)}  
       
     .data ALIGN(4) : { *(.data) }
     .bss ALIGN(4)  : { *(.bss)  *(COMMON) }
} 