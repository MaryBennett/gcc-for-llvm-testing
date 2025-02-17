/* PR rtl-optimization/63637 */
/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

int
foo (void)
{
  int a, b, c;
  asm ("# Magic instruction" : "=r" (a) : : "memory");
  asm ("# Magic instruction" : "=r" (b) : : "memory");
  asm ("# Magic instruction" : "=r" (c) : : "memory");
  return a + b + c;
}

/* { dg-final { scan-assembler-times "# Magic instruction" 3 } } */
