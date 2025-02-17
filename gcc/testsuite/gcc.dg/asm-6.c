/* Check error messages for named asm operands.  */
/* { dg-require-effective-target gcc_frontend } */
void foo ()
{
  int i;
  __asm__ ("" : [data] "=r" (i) : [data] "i" (100)); /* { dg-error "duplicate 'asm' operand" } */
  __asm__ ("%[foo]" :: [bar] "i" (1)); /* { dg-error "undefined named operand" } */
}
