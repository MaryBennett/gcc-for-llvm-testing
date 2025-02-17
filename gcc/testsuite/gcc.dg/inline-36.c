/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -fdisable-tree-einline -fdisable-ipa-inline -Wno-attributes" } */
/* { dg-require-effective-target gcc_internals } */
int g;
__attribute__((always_inline)) void bar (void)
{
  g++;
}

int foo (void)
{
  bar ();
  return g;
}

int foo2 (void)
{
  bar();
  return g + 1;
}

/* { dg-final { scan-tree-dump-times "bar" 5 "optimized" } } */
