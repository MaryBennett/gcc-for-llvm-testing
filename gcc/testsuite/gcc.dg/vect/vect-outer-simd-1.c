/* { dg-require-effective-target noclone } */
/* { dg-require-effective-target vect_simd_clones } */
/* { dg-additional-options "-fopenmp-simd -ffast-math" } */
#include <stdlib.h>
#include "tree-vect.h"
#define N 64

float *px, *py;
float *tx, *ty;
float *x1, *z1, *t1, *t2;

static void inline bar(const float cx, float cy,
                         float *vx, float *vy)
{
  int j;
    for (j = 0; j < N; ++j)
    {
        const float dx  = cx - px[j];
        const float dy  = cy - py[j];
        *vx               -= dx * tx[j];
        *vy               -= dy * ty[j];
    }
}

__attribute__((noinline, noclone)) void foo1 ()
{
  int i;
#pragma omp simd
  for (i=0; i<N; i++)
    bar(px[i], py[i], x1+i, z1+i);
}

__attribute__((noinline, noclone)) void foo2 ()
{
  volatile int i;
  for (i=0; i<N; i++)
    bar(px[i], py[i], x1+i, z1+i);
}


int main()
{
  float *X = (float*)malloc(N * 8 * sizeof (float));
  int i;
  check_vect ();
  px = &X[0];
  py = &X[N * 1];
  tx = &X[N * 2];
  ty = &X[N * 3];
  x1 = &X[N * 4];
  z1 = &X[N * 5];
  t1 = &X[N * 6];
  t2 = &X[N * 7];

  for (i=0; i<N; i++)
    {
      px[i] = (float) (i+2);
      tx[i] = (float) (i+1);
      py[i] = (float) (i+4);
      ty[i] = (float) (i+3);
      x1[i] = z1[i] = 1.0f;
    }
  foo1 ();  /* vector variant.  */
  for (i=0; i<N;i++)
    {
      t1[i] = x1[i]; x1[i] = 1.0f;
      t2[i] = z1[i]; z1[i] = 1.0f;
    }
  foo2 ();  /* scalar variant.  */
  for (i=0; i<N; i++)
    if (x1[i] != t1[i] || z1[i] != t2[i])
      abort ();	
  return 0;
} 
/* { dg-final { scan-tree-dump "OUTER LOOP VECTORIZED" "vect" } } */
