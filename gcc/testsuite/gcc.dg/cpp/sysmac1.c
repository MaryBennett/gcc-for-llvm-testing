/* Copyright (C) 2001-2017 Free Software Foundation, Inc.  */

/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99 -pedantic -Wtraditional -ftrack-macro-expansion=0" } */

/* Tests diagnostics are suppressed for some macros defined in system
   headers.  */

/* Source: Neil Booth, 15 Jan 2001.  */

#include "syshdr.h"

#define uint 1U
#define str(x) x
#define foo(x, y...) bar(x, ##y) /* { dg-warning "named variadic macros" } */

#if uint			/* { dg-warning "traditional C rejects" } */
#endif
#if sys_uint			/* { dg-bogus "traditional C rejects" } */
#endif

(str);				/* { dg-warning "used with arguments" } */
(sys_str);			/* { dg-bogus "used with arguments" } */

foo (one_arg);			/* { dg-bogus "requires at least one" } */
sys_foo (one_arg);		/* { dg-bogus "requires at least one" } */
