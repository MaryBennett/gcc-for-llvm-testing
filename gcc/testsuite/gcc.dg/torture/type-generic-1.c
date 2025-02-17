/* Do the type-generic tests.  Unlike pr28796-2.c, we test these
   without any fast-math flags.  */

/* { dg-do run } */
/* { dg-require-effective-target inf } */
/* { dg-skip-if "No subnormal support" { csky-*-* } { "-mhard-float" } } */
/* { dg-options "-DUNSAFE" { target tic6x*-*-* visium-*-* nvptx-*-* } } */
/* { dg-add-options ieee } */
/* { dg-require-effective-target builtin_isnan } */
/* { dg-require-effective-target builtin_isinf } */
/* { dg-require-effective-target builtin_finite } */

#include "../tg-tests.h"

int main(void)
{
  return main_tests ();
}
