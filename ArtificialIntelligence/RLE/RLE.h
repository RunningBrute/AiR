#ifndef _RLE_H_
#define _RLE_H_

#include <stdio.h>

/* kompresja RLE */
void compress(FILE *in, FILE *out);

/* dekompresja RLE */
void decompress(FILE *in, FILE *out);

#endif
