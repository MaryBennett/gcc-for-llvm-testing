/* PR34985: Warning "defined but not used" despite __attribute__((__used__)) */
/* { dg-do compile } */
/* { dg-options "-Wall -Wextra -O2" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
static void xxyyzz (void);
static void __attribute__((__used__)) xxyyzz(void)
{
}

/* { dg-final { scan-assembler "xxyyzz" } } */
