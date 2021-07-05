/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
/* { dg-require-effective-target gcc_frontend } */

void f()
{
  asm ("foo%%bar");
}

/* { dg-final { scan-assembler "foo%%bar" } } */
