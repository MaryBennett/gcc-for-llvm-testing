/* { dg-do compile } */
/* { dg-additional-options "-Wno-return-type" } */

extern int var;

int foo1(void)
{
  extern int var;

  var += 1;
}

int foo2(void)
{
  var += 1;
}
