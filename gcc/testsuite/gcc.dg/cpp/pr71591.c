/* PR rtl-optimization/71591 */
/* { dg-do preprocess } */
/* { dg-options "-fself-test=fake-value" } */
/* { dg-require-effective-target gcc_internals } */

/* { dg-message "self-tests incompatible with '-E'" "" { target *-*-* } 0 } */
