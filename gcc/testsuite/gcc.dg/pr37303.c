/* { dg-do compile { target *-*-elf* *-*-gnu* } } */
/* { dg-options "-std=c99" } */
/* { dg-final { scan-assembler "rdata|rodata" } } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

struct S { const int *x; } s = { (const int[]){1, 2, 3} };
