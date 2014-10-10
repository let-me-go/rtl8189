#ifndef _DDRC_H_
#define _DDRC_H_

#define BASEADDR_DDRC_REG			(0xED000000)
#define BASEADDR_DDRC               (0xA0000000)

void denali_ddrc_init(void);
void denali_ddrc_test(void);

#endif

