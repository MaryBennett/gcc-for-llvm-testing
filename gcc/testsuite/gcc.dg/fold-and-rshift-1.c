/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

int f(int x)
{
	return (x >> 2) & 128;
}

int g(int x)
{
	return !!(x & 512) << 7;
}

int h(int x)
{
	return ((x >> 9) & 1) << 7;
}

int i(int x)
{
	return (x & 512) >> 9 << 7;
}

int j(int x)
{
	return ((x >> 9) & 1) ? 128 : 0;
}

int k(int x)
{
	return (x & 512) ? 128 : 0;
}

/* { dg-final { scan-tree-dump-not " \\? " "original" } } */
/* { dg-final { scan-assembler-not "sall" { target i?86-*-* x86_64-*-* } } }" */
