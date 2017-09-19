#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	unsigned char rom[32768];
	char mask[32768];         /* mask[addr]=0 means data, 1 means code. */
	unsigned pc, lrb, usp;
	unsigned char dd;
} dasm_state;

typedef int (*dasmfunc)(dasm_state *, char *buf);

extern dasmfunc dasmtable[];
extern const char *get_rom_label(unsigned addr);
extern const char *get_romtable_label(unsigned addr);
extern const char *get_ram_label(unsigned addr, int digits);
extern void do_vcal(unsigned n);

static int _abs(int x) { return x<0? -x:x; }

#define CODE_OFFSET	0x3c


