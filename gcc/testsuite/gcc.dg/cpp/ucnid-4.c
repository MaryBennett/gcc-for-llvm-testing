/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c99" } */

\u00AA
\u00AB /* { dg-error "not valid in an identifier" } */
\u00B6 /* { dg-error "not valid in an identifier" } */
\u00BA
\u00C0
\u00D6
\u0384

\u0669
A\u0669
0\u00BA
0\u0669
\u0E59
A\u0E59
