/* PR libstdc++/85466 */
/* { dg-do run } */
/* { dg-options "-O2 -fmath-errno -ftrapping-math -fdump-tree-optimized" } */
/* { dg-add-options ieee } */
/* { dg-final { scan-tree-dump-not "nextafter" "optimized" } } */
/* { dg-final { scan-tree-dump-not "nexttoward" "optimized" } } */
/* { dg-require-effective-target gcc_frontend } */

#define NEED_ERRNO 1
#define NEED_EXC 1
#include "nextafter-1.c"
