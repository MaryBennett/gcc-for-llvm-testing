/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-original" } */
/* { dg-require-effective-target-flag { -fdump-tree-optimized } } */

unsigned foo (unsigned a, unsigned b)
{
  return a/b * b + a%b;
}

int bar (int a, int b)
{
  return a/b * b + a%b;
}

/* { dg-final { scan-tree-dump-times "return a;" 2 "original" } } */
