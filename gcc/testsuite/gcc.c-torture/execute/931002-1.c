/* { dg-require-effective-target trampolines } */
/* { dg-require-effective-target nested_func } */

f (void (*func) ())
{
  func ();
}

main ()
{
  void t0 ()
    {
    }

  void t1 ()
    {
      f (t0);
    }

  void t2 ()
    {
      t1 ();
    }

  t1 ();
  t1 ();
  t2 ();

  exit (0);
}
