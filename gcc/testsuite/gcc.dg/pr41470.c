/* { dg-do compile } */
/* { dg-options "-fexceptions" } */
/* { dg-require-effective-target alloca } */
/* { dg-require-effective-target exceptions } */
/* { dg-skip-if "" { ! fexceptions } } */

void cf (void *);

void *
af (void *a)
{
  return a;
}
void
bf (void)
{
  void *p;
  {
    int i = 1;
    char v[i];
    p = af (v);
  }
  cf (p);
}
