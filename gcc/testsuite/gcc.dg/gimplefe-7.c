/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

void __GIMPLE (ssa) foo ()
{
  int a;

__BB(2):
  if (a_5(D) > 4)
    goto __BB3;
  else
    goto __BB4;

__BB(3):
  a_2 = 10;
  goto __BB5;

__BB(4):
  a_3 = 20;
  goto __BB5;

__BB(5):
  a_1 = __PHI (__BB3: a_2, __BB4: a_3);
  a_4 = a_1 + 4;

return;
}

