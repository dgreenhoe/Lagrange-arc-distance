/*============================================================================
 * Daniel J. Greenhoe
 * operations on sequences over R^4
 *============================================================================*/
/*=====================================
 * operations on R^4 sequences
 *=====================================*/
extern int min(seqR4 *xR4, seqR1 *ymin);
extern int max(seqR4 *xR4, seqR1 *ymax);
extern void mag(seqR4 *x, seqR1 *y);
extern void convolve(seqR4 *x, seqR1 *y, seqR4 *z, int showcount);
extern void convolve(seqR4 *x, seqR1 *y, seqR4 *z){convolve(x,y,z,1);}

