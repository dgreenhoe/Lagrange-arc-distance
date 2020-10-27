/*============================================================================
 * Daniel J. Greenhoe
 * operations on sequences over R^6
 *============================================================================*/
/*=====================================
 * operations
 *=====================================*/
extern int min(seqR6 *xR6, seqR1 *ymin);
extern int max(seqR6 *xR6, seqR1 *ymax);
extern void mag(seqR6 *x, seqR1 *y);
extern void convolve(seqR6 *x, seqR1 *y, seqR6 *z, int showcount);
extern void convolve(seqR6 *x, seqR1 *y, seqR6 *z){convolve(x,y,z,1);}

