/* { dg-do compile } */
/* { dg-options "-w -O1 -fdump-tree-gimple" } */
/* { dg-require-effective-target builtin_shuffle } */
/* { dg-require-effective-target return_vector } */
/* { dg-require-effective-target gcc_frontend } */

typedef int SItype __attribute__ ((mode (SI)));
typedef SItype v4si __attribute__ ((vector_size (16)));

v4si vs (v4si a, v4si b)
{
  return __builtin_shuffle (a, b, (v4si) {0, 4, 1, 5});
}

/* The compound literal should be placed directly in the vec_perm.  */
/* Test is xfailed on 32-bit hppa*-*-* because target-callee-copies.  */
/* { dg-final { scan-tree-dump-times "VEC_PERM_EXPR <a, b, { 0, 4, 1, 5 }>;" 1 "gimple" { target { ! mmix-knuth-mmixware } xfail { hppa*-*-* && { ! lp64 } } } } } */
/* { dg-final { scan-tree-dump-times "VEC_PERM_EXPR <a::., b::., { 0, 4, 1, 5 }>;" 1 "gimple" { target mmix-knuth-mmixware } } } */

