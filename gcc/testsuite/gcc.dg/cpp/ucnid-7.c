/* { dg-do compile } */
/* { dg-options "-std=c99" } */
/* { dg-additional-options "-Wno-unicode" } */
#define a b(
#define b(x) q
int a\U0000000z );
