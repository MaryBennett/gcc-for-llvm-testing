/* PR middle-end/37858 */
/* ??? With -dv removed, this test is a bit silly.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-ipa-build_ssa_passes" } */
/* { dg-require-effective-target gcc_internals } */

int
main (void)
{
  return 0;
}

