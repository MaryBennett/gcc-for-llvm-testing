/* { dg-do compile } */
/* { dg-require-effective-target tls } */
/* { dg-require-effective-target gcc_frontend } */

static __thread int fstat ;
static __thread int fstat = 1 ; /* { dg-line fstat_prev } */
static __thread int fstat ;
static __thread int fstat = 2;
/* { dg-error "redefinition of 'fstat'" "" { target *-*-* } .-1 } */
/* { dg-message "note: previous definition of 'fstat'" "note" { target *-*-* } fstat_prev } */
