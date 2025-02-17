/* { dg-do compile } */
/* { dg-require-effective-target c99_runtime } */
/* { dg-options "-O2 -ffast-math -fdump-tree-forwprop-details" } */
/* { dg-require-effective-target gcc_frontend } */

#include <math.h>

float f1(float x)
{
  float t1 = fabsf (x);
  float t2 = x / t1;
  return t2;
}
 
/* { dg-final { scan-tree-dump "__builtin_copysignf" "forwprop1" } } */
