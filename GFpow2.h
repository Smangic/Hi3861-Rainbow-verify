#ifndef GFPOW2_H
#define GFPOW2_H

#include <stdio.h>
#include <stdlib.h>

#define pow 256
#define powm1 (pow - 1)

extern const int lg[pow];
extern const int ex[pow];


typedef struct {
    int val;
} GFpow;

GFpow GFpow_init();
GFpow GFpow_init_with_value(int x);
void GFpow_add(const GFpow *a, const GFpow *b,GFpow *c);
void GFpow_mul(const GFpow *a, const GFpow *b,GFpow *c);
void GFpow_mul_int(const GFpow *a, int b,GFpow *c);
void GFpow_div(const GFpow *a, const GFpow *b,GFpow *c);
void GFpow_int_div(int a, const GFpow *b,GFpow *c);
void GFpow_div_int(const GFpow *a, int b,GFpow *c);

void GFpow_add_equal(GFpow *a, const GFpow *b);

unsigned char GFpow_to_char(const GFpow *v);
int GFpow_equal( GFpow *x, int z);
int GFpow_not_equal( GFpow *x, int z);

#endif /* GFPOW_H */