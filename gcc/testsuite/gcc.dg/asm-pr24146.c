/* { dg-do compile } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
/* { dg-require-effective-target gcc_frontend } */

/* Test that asm with no outputs are treated as volatile.  */

void f(int x)
{
  __asm__ ("extended asm not discarded" : : "r" (x));
}

void g (void)
{
  __asm__ ("simple asm not discarded");
}
/* { dg-final { scan-assembler "extended asm not discarded" } } */
/* { dg-final { scan-assembler "simple asm not discarded" } } */

