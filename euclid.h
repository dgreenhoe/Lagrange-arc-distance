/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/

extern double ae_metric(double alpha, vectR2 p, vectR2 q);
extern double ae_metric(double alpha, vectR3 p, vectR3 q);
extern double ae_metric(double alpha, vectR6 p, vectR6 q);
extern double emetric(vectR2 p, vectR2 q){return ae_metric(1.0,p,q);}
extern double emetric(vectR3 p, vectR3 q){return ae_metric(1.0,p,q);}
extern double emetric(vectR6 p, vectR6 q){return ae_metric(1.0,p,q);}
extern vectR3 ae_findq(double alpha, vectR3 p, double theta, double phi, double d, long int N);

