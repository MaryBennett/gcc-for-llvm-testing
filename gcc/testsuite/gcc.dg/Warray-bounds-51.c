/* PR middle-end/92333 - missing variable name referencing VLA in warnings
   PR middle-end/82608 - missing -Warray-bounds on an out-of-bounds VLA index
   { dg-do compile }
   { dg-options "-O2 -Wall" }
   { dg-additional-options "-mtune=generic" { target { i?86-*-* x86_64-*-* } } } */
/* { dg-require-effective-target vla_in_struct } */

void sink (void*);

void test_char_vla_location (void)
{
  unsigned nelts = 7;

  char vla[nelts];    // { dg-message "declared here|while referencing" }

  vla[0] = __LINE__;
  vla[nelts] = 0;     // { dg-warning "\\\[-Warray-bounds" }

  sink (vla);
}

void test_int_vla_location (void)
{
  unsigned nelts = 7;

  int vla[nelts];     // { dg-message "declared here|while referencing" }

  vla[0] = __LINE__;
  vla[nelts] = 1;     // { dg-warning "\\\[-Warray-bounds" }

  sink (vla);
}

void test_struct_char_vla_location (void)
{
  unsigned nelts = 7;

  struct {
    char cvla[nelts]; // { dg-message "declared here|while referencing" }
  } s;

  s.cvla[0] = __LINE__;
  s.cvla[nelts - 1] = 0; // { dg-warning "\\\[-Wstringop-overflow" "pr102706" { target { vect_slp_v2qi_store_align } } }
  s.cvla[nelts] = 0;  // { dg-warning "\\\[-Warray-bounds" }

  sink (&s);
}


void test_struct_int_vla_location (void)
{
  unsigned nelts = 7;

  struct {
    int ivla[nelts];  // { dg-message "declared here|while referencing" }
  } s;

  s.ivla[0] = __LINE__;
  s.ivla[nelts - 1] = 0;
  s.ivla[nelts] = 0;  // { dg-warning "\\\[-Warray-bounds" }

  sink (&s);
}
