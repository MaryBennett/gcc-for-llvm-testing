/* PR middle-end/36902 Array bound warning with dead code after optimization */
/* { dg-do compile } */
/* { dg-options "-O2 -Warray-bounds -Wall -Wextra" } */
/* { dg-require-effective-target gcc_frontend } */
typedef unsigned char __u8;
typedef unsigned short __u16;

static inline unsigned char *
foo(unsigned char * to, const unsigned char * from, int n)
{
  switch ( n )
    {
    case 3:
      *to = *from;
      break;
    case 5:
      to[4] = from [4];
      break;
    }
  return to;
}

struct {
  int    size_of_select;
  unsigned char pcr_select[4];
} sel;

unsigned char buf[64];
int bar(void)
{
  sel.size_of_select = 3;
  foo(buf, sel.pcr_select, sel.size_of_select);

  return 1;
}


static inline unsigned char *
foo2(unsigned char * to, const unsigned char * from, int n)
{
  switch ( n )
    {
    case 3:
      *to = *from;
      break;
    case 5:
      to[4] = from [4]; /* { dg-warning "\\\[-Warray-bounds" } */
      break;
    }
  return to;
}

int baz(void)
{
  sel.size_of_select = 5;
  foo2(buf, sel.pcr_select, sel.size_of_select);

  return 1;
}
