/* { dg-require-effective-target noclone } */
/* PR tree-optimization/54200 */
/* { dg-do run } */
/* { dg-options "-g -fno-var-tracking-assignments -fno-tree-coalesce-vars" } */
/* { dg-require-effective-target gcc_frontend } */

int o __attribute__((used));

void bar (void) { o = 2; }

int __attribute__((noinline,noclone))
foo (int z, int x, int b)
{
  if (x == 1)
    {
      bar ();
      return z;
    }
  else
    {
      int a = (x + z) + b;
      return a; /* { dg-final { gdb-test . "z" "3" { xfail { aarch64*-*-* && { no-opts "-O0" "-Og" } } } } } */
    }
}

int main ()
{
  foo (3, 2, 1);
  return 0;
}
