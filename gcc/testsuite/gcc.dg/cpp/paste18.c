/* 
   { dg-options "-ftrack-macro-expansion=2" }
   { dg-do compile }
   { dg-require-effective-target gcc_frontend } */

struct x {
  int i;
};
struct x x;

#define TEST(X) x.##X /* { dg-error "pasting\[^\n\r\]*does not give\[^\n\r\]*token" } */

void foo (void)
{
  TEST(i) = 0;
}
