/* PR tree-optimization/68714 */
/* { dg-do compile } */
/* { dg-require-effective-target return_vector } */
/* { dg-options "-O2 -fdump-tree-reassoc1 -w -Wno-psabi" } */
/* { dg-require-effective-target gcc_frontend } */

typedef int vec __attribute__((vector_size(16)));
vec f(vec x,vec y){
  return x<y|x==y;
}

/* { dg-final { scan-tree-dump-times " <= " 1 "reassoc1" } } */
