/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */
/* { dg-require-effective-target builtin_free } */
/* { dg-require-effective-target builtin_malloc } */
/* { dg-require-effective-target gcc_frontend } */

void test1(void)
{
  int *p = __builtin_malloc (sizeof (int) * 4);
  *p++ = 4;
  __builtin_free (p);   // { dg-warning "\\\[-Wfree-nonheap-object" }
}

/* Undefined.  We can't do anything here.  */

/* { dg-final { scan-tree-dump-times "free" 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times "malloc" 1 "optimized" } } */
