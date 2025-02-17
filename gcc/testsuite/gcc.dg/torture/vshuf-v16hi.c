/* { dg-do run } */
/* { dg-options "-DEXPENSIVE" { target run_expensive_tests } } */
/* { dg-options "-fno-common" { target hppa*-*-hpux* } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "*" } { "-O2" } } */
/* { dg-skip-if "" { ! run_expensive_tests } { "-flto" } { "" } } */
/* { dg-require-effective-target builtin_shuffle } */
/* { dg-require-effective-target noclone } */

typedef unsigned short V __attribute__((vector_size(32)));
typedef V VI;

#include "vshuf-16.inc"
#include "vshuf-main.inc"
