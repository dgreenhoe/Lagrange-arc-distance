/*============================================================================
 * Daniel J. Greenhoe
 * operations on sequences over R^3
 *============================================================================*/
/*=====================================
 * operations
 *=====================================*/
extern int min(seqR3 *xR3, seqR1 *ymin);
extern int max(seqR3 *xR3, seqR1 *ymax);
extern void mag(seqR3 *x, seqR1 *y);
extern void convolve(seqR3 *x, seqR1 *y, seqR3 *z, int showcount);
extern void convolve(seqR3 *x, seqR1 *y, seqR3 *z){convolve(x,y,z,1);}

