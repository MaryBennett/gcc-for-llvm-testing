/* PR middle-end/54838 */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-forward-propagate -ftracer" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */
/* { dg-require-effective-target gcc_frontend } */

void bar (void);

void
foo (void *b, int *c)
{
again:
  switch (*c)
    {
    case 1:
      if (!b)
	{
	  bar ();
	  return;
	}
      goto again;
    case 3:
      if (!b)
	goto again;
    }
}
