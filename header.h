#ifndef __HEADER__H__
#define __HEADER__H__
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define VERBOSE_MODE 0

/* user capacity */
#define NUM_LBNS 3
#define NUM_LPNS (NUM_LBNS * PAGES_PER_BLOCK)

/* nand variables */
#define BLOCKS_PER_NAND (NUM_LBNS + 2)
#define PAGES_PER_BLOCK 4

void nand_page_program(int block_idx, int page_idx, int data_lpn);
int nand_page_read(int block_idx, int page_idx);
void nand_block_erase(int block_idx);
int nand_print_stats(void);

/* ftl operation */
struct ftl_operation {
	/* return read data, usually just lpn number */
	int (*read_op)(int lpn);
	void (*write_op)(int lpn, int data);
	void (*print_stats)(void);
};

/* for page-map ftl */
void pagemap_init(struct ftl_operation *op);

/* for block-map ftl */
void blockmap_init(struct ftl_operation *op);
#endif /* __HEADER__H__ */
