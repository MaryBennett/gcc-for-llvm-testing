/* { dg-do preprocess } */
/* { dg-options "-nostdinc -P -dU" } */
/* { dg-options "-nostdinc -P -dU -std=c89" { target *-*-solaris2.* } } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */
/* { dg-final { scan-file cmdlne-dU-17.i "^\n*1\n+#define __STDC__ 1\n*$" } } */
/* { dg-require-effective-target gcc_frontend } */
__STDC__
