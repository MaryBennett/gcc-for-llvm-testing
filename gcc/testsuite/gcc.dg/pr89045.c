/* PR c/89045 */
/* { dg-do compile } */
/* { dg-require-effective-target alloca } */
/* { dg-options "" } */
/* { dg-require-effective-target nested_func } */

int
foo (int x)
{
  int v[(int){ x }];
  v[0] = 0;
  int bar (int p[(int){ x }])
  {
    return p[0];
  }
  return bar (v);
}
