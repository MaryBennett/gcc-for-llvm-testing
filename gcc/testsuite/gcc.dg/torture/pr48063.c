/* PR tree-optimization/48063 */
/* { dg-do compile } */
/* { dg-options "-fno-early-inlining" } */
/* { dg-require-effective-target gcc_internals } */

extern void abort (void);
static void bar ();

void
foo ()
{
  bar (1);
}

static void
bar (double i)
{
  if (i)
    abort ();
}
