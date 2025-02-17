/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-local-pure-const1" } */
/* { dg-add-options bind_pic_locally } */
/* { dg-require-effective-target gcc_frontend } */

int
t(int a, int b, int c)
{
  int *p;
  if (a)
    p = &a;
  else
    p = &c;
  return *p;
}
/* { dg-final { scan-tree-dump-times "local or readonly memory is OK" 1 "local-pure-const1"} } */
/* { dg-final { scan-tree-dump-times "found to be const" 1 "local-pure-const1"} } */
