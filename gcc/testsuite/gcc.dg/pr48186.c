/* PR tree-optimization/48186 */
/* { dg-do compile } */
/* { dg-options "-O --param hot-bb-frequency-fraction=0" } */
/* { dg-additional-options "-Wno-unused-command-line-argument" } */

void foo (void) { }
