/* { dg-do compile } */
/* { dg-options "-fno-tree-dce -ftree-vectorize" } */
/* { dg-require-effective-target gcc_internals } */

extern short X[];

int foo (int len)
{
  int i;
  int s = 0;
  for (i = 0; i < len; i++)
    s += X[i] * X[i];
  return s;
}
