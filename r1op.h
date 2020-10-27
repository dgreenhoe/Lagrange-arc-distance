/*============================================================================
 * Daniel J. Greenhoe
 * header file for routines for seqR1 operations
 *============================================================================*/
/*=====================================
 * operator overloading
 *=====================================*/
seqR1 operator-(seqR1 x);              // -x
seqR1 operator+(seqR1 x, seqR1 y);  // x+y
seqR1 operator-(seqR1 x, seqR1 y);  // x-y
//seqR1 operator*(seqR1 x,seqR1 y);   // convolution of sequences x and y

/*=====================================
 * functions
 *=====================================*/
extern int mag(seqR1 *xR1, seqR1 *ymag);
extern double rms(seqR1 *x, long start, long end);
extern double rms(seqR1 *x){return rms(x,0,x->getN()-1);}
extern void convolve(seqR1 *x, seqR1 *y, seqR1 *z, int showcount);
extern void convolve(seqR1 *x, seqR1 *y, seqR1 *z){convolve(x,y,z,1);}
extern int sin(seqR1 *x,seqR1 *y);
extern int sin(double u, seqR1 *y);
extern int cos(seqR1 *x,seqR1 *y);
extern int cos(double u, seqR1 *y);
extern void copy(const long start, const long end, const seqR1 *x, const seqR1 *y);
extern int downsample(const long M, const seqR1 *x,const seqR1 *y);


