/* Test C11 alignment support.  Test reducing alignment (assumes there
   are at least some alignment constraints), case of compound literals.  */
/* { dg-do compile } */
/* { dg-options "-std=c11 -pedantic-errors" } */
/* { dg-require-effective-target gcc_frontend } */

#include <stddef.h>

max_align_t *p = &(_Alignas (_Alignof (char)) max_align_t) { 1 };
/* { dg-error "reduce alignment" "" { target { ! default_packed } } .-1 } */
