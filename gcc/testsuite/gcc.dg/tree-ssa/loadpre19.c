/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-pre-stats" } */
/* { dg-require-effective-target gcc_frontend } */
typedef int type[2];
int foo(type *a, int argc)
{
  int d, e;

  /* Should be able to eliminate the second load of *a along the main path. */
  d = (*a)[argc];
  if (!d)
      argc++;
  e = (*a)[argc];
  return e;
}
/* { dg-final { scan-tree-dump-times "Eliminated: 1" 1 "pre"  } } */
