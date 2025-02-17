/* { dg-do compile } */
/* { dg-options "-O" } */
/* Verify that a cleanup marked "inline" gets inlined.  */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

static inline void xyzzy(void *p __attribute__((unused)))
{
}

void doit(void)
{
  int x __attribute__((cleanup (xyzzy)));
}

/* { dg-final { scan-assembler-not "xyzzy" } } */
