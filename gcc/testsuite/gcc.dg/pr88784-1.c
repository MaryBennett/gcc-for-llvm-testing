/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-ifcombine" } */
/* { dg-require-effective-target-flag { -fdump-tree-ifcombine } } */

#include <limits.h>

_Bool and1(unsigned x, unsigned y)
{
  /* x > y && x != 0 --> x > y */
  return x > y && x != 0;
}

_Bool and2(unsigned x, unsigned y)
{
  /* x < y && x != UINT_MAX --> x < y */
  return x < y && x != UINT_MAX;
}

_Bool and3(signed x, signed y)
{
  /* x > y && x != INT_MIN --> x > y */
  return x > y && x != INT_MIN;
}

_Bool and4(signed x, signed y)
{
  /* x < y && x != INT_MAX --> x < y */
  return x < y && x != INT_MAX;
}

/* { dg-final { scan-tree-dump-not " != " "ifcombine" } } */
