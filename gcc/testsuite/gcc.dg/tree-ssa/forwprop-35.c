/* { dg-do compile } */
/* { dg-require-effective-target return_vector } */
/* { dg-options "-O -fdump-tree-cddce1 -Wno-psabi" } */
/* { dg-additional-options "-msse2" { target { i?86-*-* x86_64-*-* } } } */
/* { dg-require-effective-target gcc_frontend } */

typedef int v4si __attribute__((vector_size(16)));
typedef float v4sf __attribute__((vector_size(16)));

v4sf vec_cast(v4si f)
{
  return (v4sf){f[0], f[1], f[2], f[3]};
}

v4sf vec_cast_perm(v4si f)
{
  return (v4sf){f[1], f[1], f[2], f[3]};
}

/* { dg-final { scan-tree-dump-times "VEC_PERM_EXPR" 1 "cddce1" { target { i?86-*-* x86_64-*-* } } } } */
/* Catch (v4sf) and (vector(4) float).  */
/* { dg-final { scan-tree-dump-times " = \\\(v" 2 "cddce1" { target { i?86-*-* x86_64-*-* } } } } */
