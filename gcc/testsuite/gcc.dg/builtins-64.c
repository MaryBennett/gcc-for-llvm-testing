/* { dg-do run } */
/* { dg-require-effective-target alloca } */
/* { dg-require-effective-target gcc_frontend } */

int main ()
{
  char *mem = __builtin_alloca (40);
  __builtin___clear_cache (mem, mem + 40);
  return 0;
}
