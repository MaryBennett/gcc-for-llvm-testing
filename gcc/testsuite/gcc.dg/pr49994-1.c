/* { dg-do compile } */
/* { dg-options "-Os -fsched2-use-superblocks -g" } */
/* { dg-require-effective-target nonlocal_goto } */
/* { dg-require-effective-target scheduling } */
/* { dg-require-effective-target gcc_internals } */

void x (int a)
{
  __label__ xlab;
  void y (int b)
  {
    switch (b)
      {
      case 1:
	goto xlab;
      case 2:
	goto xlab;
      }
  }
  y (a);
xlab:;
}
