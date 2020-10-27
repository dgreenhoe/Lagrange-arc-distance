/*============================================================================
 * Daniel J. Greenhoe
 * header file for routines for Lagrange arcs
 *============================================================================*/
/*-------------------------------------------------------------------------
 * Lagrange arc class
 *-------------------------------------------------------------------------*/
class larcc{
  private:
    vectR2 p,q;
  public:
    larcc(vectR2 pp, vectR2 qq){p=pp; q=qq;}           //constructor 
    larcc(double px, double py, double qx, double qy){p.put(px,py); q.put(qx,qy);} 
    larcc(void){p.put(0,0); q.put(0,0);} 
    void   setp(vectR2 pp){p=pp;} 
    void   setq(vectR2 qq){q=qq;} 
    void   setp(double px, double py){p.put(px,py);} 
    void   setq(double qx, double qy){p.put(qx,qy);} 
    vectR2  getp(void){return p;}
    vectR2  getq(void){return q;}
    double r(double theta);
    vectR2  x(double theta){return r(theta)*cos(theta);}
    vectR2  y(double theta){return r(theta)*sin(theta);}
    vectR2  xy(double theta);
    double indefint(double theta);// indefinite integral of arc length
    double arclength(void);
    double arclength(long int N);
    //double  operator|(double x, double y){double z; if(x==0)return 0; else return x/y;}  // division with 0/y = 0 even when y=0
    //double  operator|(double x, double y){double z; if(x==0)z=0; else z=x/y; return z;}  // division with 0/y = 0 even when y=0
  };

/*======================================
 * prototypes
 *======================================*/
extern double larc_arclength(double rp, double rq, double tdiff);
extern double larc_indefint(double rp, double rq, double thetap, double thetaq, double theta);
extern double larc_metric(const vectR2 p, const vectR2 q);
extern double larc_metric(const vectR2 p, const vectR2 q, long int N);
extern double larc_metric(const vectR3 p, const vectR3 q);
extern double larc_metric(const vectR4 p, const vectR4 q);
extern double larc_metric(const vectR6 p, const vectR6 q);
//extern vectR2 larc_findq(const vectR2 p, const double theta, const double d, const double minrq, const double maxrq, const double maxerror, const long N);
extern int larc_findq(const vectR2 p, const double theta, const double d, const double minrq, const double maxrq, const double maxerror, const long N, vectR2 *q);
extern vectR3 larc_findq(const vectR3 p, const double theta, const double phi, const double d, const double minrq, const double maxrq, const double maxerror, const long N);
//extern vectR3 larc_findq(vectR3 p, double theta, double phi, double d, long int N);

