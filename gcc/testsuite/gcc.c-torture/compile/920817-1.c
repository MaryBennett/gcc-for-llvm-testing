/* { dg-additional-options "-Wno-return-type" } */
int v;static inline f(){return 0;}g(){return f();}void h(){return v++;}
