/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-ivcanon-scev" } */
/* { dg-require-effective-target gcc_internals } */

struct struct_t
{
  int* data;
};

void foo (struct struct_t* sp, int start, int end)
{
  int i;

  for (i = 0; i+start < end; i++)
    sp->data[i+start] = 0;
}

/* { dg-final { scan-tree-dump-times "Simplify PEELED_CHREC into POLYNOMIAL_CHREC" 1 "ivcanon" } } */
