/* { dg-do compile } */
/* { dg-options "-O2 -flive-patching=inline-only-static -fdump-tree-einline-optimized" } */
/* { dg-require-effective-target-flag { -flive-patching=inline-only-static -fdump-tree-einline-optimized } } */

extern int sum, n, m;

extern inline __attribute__((always_inline)) int foo (int a);
inline __attribute__((always_inline)) int foo (int a)
{
  return a + n;
}

static int bar (int b)
{
  return b * m;
}

int main()
{
  sum = foo (m) + bar (n); 
  return 0;
}

/* { dg-final { scan-tree-dump "Inlining foo/0 into main/2"  "einline" } } */
