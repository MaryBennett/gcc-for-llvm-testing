/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-lower" } */
/* { dg-require-effective-target-flag { -fdump-tree-lower } } */

unsigned a(unsigned x, int n)
{
  return x >> (n % 32);
}

unsigned b(unsigned x, int n)
{
  return x << (n % 32);
}

/* { dg-final { scan-tree-dump-not " % " "lower" } } */
