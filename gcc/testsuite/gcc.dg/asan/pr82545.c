/* PR sanitizer/82545.  */
/* { dg-do compile } */
/* { dg-require-effective-target builtin_setjmp_longjmp } */

extern void c(int);
extern void d(void);

void *buf[5];

void a(void) {
  {
    int b;
    &b;
    __builtin_setjmp(buf);
    c(b);
  }
  d();
}
