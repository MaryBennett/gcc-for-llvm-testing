/* I accidentally broke this while developing a patch for PR 13000,
   and didn't notice since the testsuite didn't catch it -- ian  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void foo()
{
  return;
  break;	/* { dg-error "break statement not within" } */
}
