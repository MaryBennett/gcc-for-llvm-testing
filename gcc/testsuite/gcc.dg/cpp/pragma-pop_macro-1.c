/* PR preprocessor/35061 */
/* Do nothing if there is nothing on the macro stack to pop.  */

/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */

#define X  1
/* # pragma push_macro("X") */
# undef X
# pragma pop_macro("X")
#ifdef X
#error X is defined
#endif
