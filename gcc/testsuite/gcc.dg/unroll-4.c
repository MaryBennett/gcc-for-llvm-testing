/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-cunrolli-details -fno-peel-loops -fno-tree-vrp -fdisable-tree-cunroll -fenable-tree-cunrolli=foo -fdisable-tree-cunrolli=foo2" } */
/* { dg-require-effective-target gcc_internals } */

unsigned a[100], b[100];
inline void bar()
{
 a[10] = b[10];
}

int foo(void)
{
  int i;
  bar();
  for (i = 0; i < 2; i++)
  {
     a[i]= b[i] + 1;
  }
  return 1;
}

int foo2(void)
{
  int i;
  for (i = 0; i < 2; i++)
  {
     a[i]= b[i] + 1;
  }
  return 1;
}

/* { dg-final { scan-tree-dump-times "loop with 2 iterations completely unrolled" 1 "cunrolli" } } */
