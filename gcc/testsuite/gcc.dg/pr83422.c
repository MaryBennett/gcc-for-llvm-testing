/* PR debug/83422 */
/* { dg-do compile } */
/* { dg-options "-O -g --param=max-vartrack-size=1" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */

int
foo(int i, int j, int k)
{
   return i + j + k;
}
