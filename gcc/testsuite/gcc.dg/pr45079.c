/* PR c/45079 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void
foo (const char *p, int cond, int a, int b)
{
  p[cond ? a : b] = '\0';	/* { dg-error "assignment of read-only location" } */
}

/* { dg-bogus "not supported by" "" { target *-*-* } 0 } */
