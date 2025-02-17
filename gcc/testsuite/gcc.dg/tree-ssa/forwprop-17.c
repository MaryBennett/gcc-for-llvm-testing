/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int xx, int xy)
{
  xx &=1;
  xy &=1;
  return xx ^ xy;
}

/* { dg-final { scan-tree-dump-times " & 1" 1 "optimized" } } */
