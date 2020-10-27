/*============================================================================
 * Daniel J. Greenhoe
 * routines for Lagrange arcs
 * Largrange arcs are defined here in a manner analogous to 
 * Lagrange polynomial interpolation. 
 * Langrange polynomial interpolation is typically defined using 
 * Cartesian coordinates in the R^2 plane. 
 * Here, "Lagrange arcs" use basically the same idea, but are defined using
 * polar coordinates in the R^2 plane:
 *         y
 *         |   o p        Let (rp,tp) be the polar location of point p.
 *         |  /           where rp is the Euclidean distance from (0,0) to p 
 *         | /            and tp is radian measure from the x-axis to p.
 *         |/tp           Let (rq,tq) be the polar location of point q.
 * --------|---------- x  The "Lagrange arc" r(theta) is defined here as
 *         |\tq                          theta -tq        theta -tp
 *         | \            r(theta) = rp ----------- + rq -----------
 *         |  o q                          tp-tq            tq-tp
 *         |              
 *============================================================================*/
/*=====================================
 * headers
 *=====================================*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<main.h>
#include<r1.h>
#include<r2.h>
#include<r3.h>
#include<r4.h>
#include<r6.h>
#include<euclid.h>
#include<larc.h>

/*-------------------------------------------------------------------------
 * path length s of Lagrange arc from a point p at polar coordinate (rp,tp)
 *                                   to point q at polar coordinate (rq,tq).
 *            __tq             __tq
 *           |                |              (   dr    )^2
 *    s =    |  ds dtheta =   |   sqrt(r^2 + (-------- )    )  dtheta
 *         __|tp            __|tp            ( dtheta  )
 *
 * reference: Paul Dawkins, 
 *   http://tutorial.math.lamar.edu/Classes/CalcII/PolarArcLength.aspx 
 *   https://books.google.com/books?id=b4ksCQAAQBAJ&pg=PA533
 *-------------------------------------------------------------------------*/
double larc_arclength(double rp, double rq, double tdiff){
  double y;
  const double phi=fabs(tdiff);
  const double rho=rq-rp;
  const double sp=sqrt(rp*rp*phi*phi+rho*rho);
  const double sq=sqrt(rq*rq*phi*phi+rho*rho);
  const double up=rp*rho*phi+fabs(rho)*sp;
  const double uq= rq*rho*phi+fabs(rho)*sq;
  if(rp==0)    {fprintf(stderr,"\nERROR using larc_arclength(rp,rq,tdiff): rp=%lf\n",      rp);    exit(EXIT_FAILURE);}
  if(rq==0)    {fprintf(stderr,"\nERROR using larc_arclength(rp,rq,tdiff): rp=%lf\n",      rq);    exit(EXIT_FAILURE);}
  if(tdiff<=0) {fprintf(stderr,"\nERROR using larc_arclength(rp,rq,tdiff): tdiff=%lf\n",   tdiff); exit(EXIT_FAILURE);}
  if(tdiff>PI) {fprintf(stderr,"\nERROR using larc_arclength(rp,rq,tdiff): tdiff=%lf>PI\n",tdiff); exit(EXIT_FAILURE);}
  //y = (larc_indefint(rp,rq,0,tdiff,tdiff)-larc_indefint(rp,rq,0,tdiff,0))/tdiff;
  //y2 = (rho>=0)? (fabs(rho)/(2*phi))*(log( rq*phi+sq)-log( rp*phi+sp))
  //             : (fabs(rho)/(2*phi))*(log(-rq*phi+sq)-log(-rp*phi+sp));
  if(fabs(rho)<=0.00000000001) y=rp*phi;
  else{
    if(up<=0){fprintf(stderr,"\nERROR using larc_arclength(rp,rq,tdiff): up=%.20lf rp=%lf rho=%lf sp=%lf\n", up,rp,rho,sp);    exit(EXIT_FAILURE);}
    if(uq<=0){fprintf(stderr,"\nERROR using larc_arclength(rp,rq,tdiff): uq=%.20lf rp=%lf rho=%lf sp=%lf\n", uq,rq,rho,sq);    exit(EXIT_FAILURE);}
    y = (rq*sq - rp*sp)/(2*rho) + fabs(rho)*(log(uq)-log(up))/(2*phi);
    }
  return y;
  }

/*-------------------------------------------------------------------------
 * indefinite integral for arc length 
 * reference: http://integral-table.com/
 *            http://integral-table.com/downloads/integral-table.pdf 
 *            indefinite integral (37)
 *            accessed 2015 September 19 12:29PM UTC
 * Note: This function should be viewed as DEPRECATED 
 * (that is, don't use it for general computations),
 * However, this function is still useful for testing and verification of 
 * larc_metric(vectR2 p, vectR2 q).
 *-------------------------------------------------------------------------*/
double larc_indefint(double rp, double rq, double thetap, double thetaq, double theta){
  double ra = (rp-rq);
  double rb = (rq*thetap-rp*thetaq);
  double a  = ra*ra;
  double b  = 2*ra*rb;
  double c  = ra*ra + rb*rb;
  double x  = theta;
  double y  = (b+2*a*x)/(4*a)*sqrt(a*x*x+b*x+c) + (4*a*c-b*b)/(8*a*sqrt(a))*log(2*a*x+b+2*sqrt(a*(a*x*x+b*x+c)));
//double y  = (b+2*a*x)/(4*a)*sqrt(a*x*x+b*x+c) + (4*a*c-b*b)/(8*a*sqrt(a))*log(fabs(2*a*x+b+2*sqrt(a*(a*x*x+b*x+c)))); // note: fabs(...) is an error in (37)
  return y;
  }

/*-------------------------------------------------------------------------
 * Lagrange arc metric from <p> to <q> in R^2
 *-------------------------------------------------------------------------*/
double larc_metric(const vectR2 p, const vectR2 q){
  const double rp=p.mag(), rq=q.mag();
  const double phi = pqtheta(p,q);
  const vectR2  pq=p-q;
  double d;
  if(rp==0 || rq==0 || phi<=0.0000001){//use Euclidean metric
    d = emetric(p,q); 
    //printf("p=(%.2lf,%.2lf) q=(%.3lf,%.3lf) rq=%lf theta=%.12f PI phi=%.12f PI d=%lf ae\n",p.getx(),p.gety(),q.getx(),q.gety(),q.mag(),pqtheta(p,q)/PI, phi/PI,d);
    }
  else{//use Lagrange arc length
    d = larc_arclength(rp, rq, phi);
    //printf("p=(%.2lf,%.2lf) q=(%.3lf,%.3lf) rq=%lf theta=%.12f PI phi=%.12f PI d=%lf larc\n",p.getx(),p.gety(),q.getx(),q.gety(),q.mag(),pqtheta(p,q)/PI, phi/PI,d);
    }
  return d/PI;
  }

/*-------------------------------------------------------------------------
 * Lagrange metric from <p> to <q> computed numerically with resolution <N>.
 * Note: This function should be viewed as DEPRECATED 
 * (that is, don't use it for general computations),
 * but instead it is strongly recommended to use larc_metric(vectR2 p, vectR2 q).
 * The function larc_metric(vectR2 p, vectR2 q) uses a closed form solution 
 * (from an integral lookup table).
 * This function uses a numeric estimation 
 * (by an approximated summation along the arc path).
 * However, this function is still useful for testing and verification of 
 * larc_metric(vectR2 p, vectR2 q).
 *-------------------------------------------------------------------------*/
double larc_metric(const vectR2 p, const vectR2 q, const long int N){
  larcc arc(p,q);
  double d = arc.arclength(N);
  double ds=d/PI;
  return ds;
  }

/*-------------------------------------------------------------------------
 * Lagrange arc metric from <p> to <q> in R^3
 *-------------------------------------------------------------------------*/
double larc_metric(const vectR3 p, const vectR3 q){
  const double rp=p.mag(), rq=q.mag();
  const double tdiff = pqtheta(p,q);
  const vectR3  pq=p-q;
  double d;
  if(rp==0 || rq==0 || tdiff<=0) d = pq.mag();
  else if(rp==rq)                d = rp*tdiff;
  else                           d = larc_arclength(rp, rq, tdiff);
  return d/PI;
  }

/*-------------------------------------------------------------------------
 * Lagrange arc metric from <p> to <q> in R^3
 *-------------------------------------------------------------------------*/
double larc_metric(const vectR4 p, const vectR4 q){
  const double rp=p.mag(), rq=q.mag();
  const double tdiff = pqtheta(p,q);
  const vectR4  pq=p-q;
  double d;
  if(rp==0 || rq==0 || tdiff<=0) d = pq.mag();
  else if(rp==rq)                d = rp*tdiff;
  else                           d = larc_arclength(rp, rq, tdiff);
  return d/PI;
  }

/*-------------------------------------------------------------------------
 * Lagrange arc metric from <p> to <q> in R^6
 *-------------------------------------------------------------------------*/
double larc_metric(const vectR6 p, const vectR6 q){
  const double rp=p.mag(), rq=q.mag();
  const double tdiff = pqtheta(p,q);
  const vectR6  pq=p-q;
  double d;
  if(rp==0 || rq==0 || tdiff<=0) d = pq.mag();
  else if(rp==rq)                d = rp*tdiff;
  else                           d = larc_arclength(rp, rq, tdiff);
  return d/PI;
  }

/*-------------------------------------------------------------------------
 * path length of arc computed using numeric integration
 *-------------------------------------------------------------------------*/
double larcc::arclength(long int N){
  double sum=0;
  double rp=p.mag(),     rq=q.mag();
  double tdiff=pqtheta(p,q);
  double tp=0, tq=tdiff;
  double theta=tp;
  long int n;
  vectR2 p1,p2;
  double delta=tdiff/(double)N;
  vectR2 pq=p-q;
  double d=pq.mag();//Euclidean distance(p,q)
  
  if(rp==0)   return d;
  if(rq==0)   return d;
  if(tdiff==0)return d;
  
  for (n=0; n<N; n++){
    p1 = xy(theta);
    theta += delta;
    p2 = xy(theta);
    sum += chordlength(p1,p2);
    }
  return sum;
  }

/*-------------------------------------------------------------------------
 * find the point (x(t),y(t)) on the Lagrange arc larc(p,q) at parameter <theta>
 *-------------------------------------------------------------------------*/
vectR2  larcc::xy(double theta){
  double rt=r(theta);
  vectR2 pt(rt*cos(theta),rt*sin(theta));
  return pt;
  }

/*-------------------------------------------------------------------------
 * return r(theta) for Lagrange arc(p,q)
 *-------------------------------------------------------------------------*/
double  larcc::r(double theta){
  double rp=p.mag(); 
  double rq=q.mag(); 
  double tdiff=pqtheta(p,q);
  double tp=0, tq=tdiff;
  double r =rp*(theta-tq)/(tp-tq) + rq*(theta-tp)/(tq-tp); // Lagrange polynomial of theta
  return r;
  }

/*-------------------------------------------------------------------------
 * Find a point q in R^2 orientated <phi> with respect to <p> 
 * that is within a <maxerror> distance <d> from the point <p>.
 * Search for this point q using <N> search locations
 * over a radial distance from <p> of <minrq> to <maxrq>. 
 * If a solution is found, place the point q at <*q> and return 1.
 * If a solution is not found and an apparent discontinuity occurred in 
 * in the search, issue a warning and return 0.
 * If a solution is not found and a discontinuity apparently did NOT occur
 * in the search, issue an ERROR message and exit.
 *-------------------------------------------------------------------------*/
int larc_findq(const vectR2 p, const double theta, const double d, const double minrq, const double maxrq, const double maxerror, const long N, vectR2 *q){
  double rq,dd,ddprev,errord,bestrq,bestd,phi,smallesterror,discon1,discon2;
  vectR2 qq,bestq;
  int discontinuity=0,retval=1;

  qq.polartoxy(minrq,theta);//convert polar coor. to rectangular coordinates
  qq+=p;// search "origin" is the point p (not the R^2 origin (0,0))
  ddprev=larc_metric(p,qq);
  smallesterror=fabs(d-ddprev);

  for(rq=minrq; rq<=maxrq; rq+=(maxrq-minrq)/(double)N){
    qq.polartoxy(rq,theta);//convert polar coor. to rectangular coordinates
    qq+=p;// search "origin" is the point p (not the R^2 origin (0,0))
    dd=larc_metric(p,qq);
    if(fabs(dd-ddprev)>(maxerror*100)){
      discontinuity=1;
      retval=0;
      discon1=ddprev;
      discon2=dd;
      }
    ddprev=dd;
    errord=fabs(d-dd);
    if(errord<smallesterror){
      bestq=qq;
      bestrq=rq;
      bestd=dd;
      smallesterror=errord;
      phi = pqtheta(p,qq);
      }
    }
  if(smallesterror>maxerror){
    if(discontinuity){
      fprintf(stderr,"\nWARNING using larc_findq(vectR2 p,...): possible discontinuity,\n");
      fprintf(stderr,"  jumping from d=%lf to d=%lf.\n",discon1,discon2);
      fprintf(stderr,"  smallesterror=%lf > %lf=maxerror smallestd=%lf bestrq=%lf theta=%.12lf PI phi=%.12lf PI\n",smallesterror,maxerror,bestd,bestrq,theta/PI,phi/PI);
      }
    else{
      fprintf(stderr,"\nERROR using larc_findq(vectR2 p,...): no apparent discontinuity but...\n");
      fprintf(stderr,"  smallesterror=%lf > %lf=maxerror smallestd=%lf bestrq=%lf theta=%.12lf PI phi=%.12lf PI\n",smallesterror,maxerror,bestd,bestrq,theta/PI,phi/PI);
      exit(EXIT_FAILURE);
      }
    }
  *q = bestq;
  return retval;
  }

/*-------------------------------------------------------------------------
 * Find the polar length of a point q with radial measure tq that is a 
 * distance <d> from the point <p> with polar coordinates (rp,tp)
 * using search resolution <N>
 *-------------------------------------------------------------------------*/
vectR3 larc_findq(const vectR3 p, const double theta, const double phi, const double d, const double minrq, const double maxrq, const double maxerror, const long int N){
  double rq,dd,errord,bestrq;
  vectR3 bestq(0,0,0);
  vectR3 q(0,0,0);
  double smallesterror=10000;

  for(rq=minrq; rq<=maxrq; rq+=(maxrq-minrq)/(double)N){
    q.polartoxyz(rq,theta,phi);//convert polar coor. to rectangular coordinates
    q+=p;// search "origin" is the point p (not the R^3 origin (0,0,0))
    dd=larc_metric(p,q);
    errord=fabs(d-dd);
    if(errord<smallesterror){
      bestq=q;
      bestrq=rq;
      smallesterror=errord;
      }
    }
  if(smallesterror>maxerror){
    fprintf(stderr,"\nERROR using larc_findq(vectR3 p,...):\n  smallesterror=%lf > %lf=maxerror bestrq=%lf theta=%.2lf PI\n",smallesterror,maxerror,bestrq,theta/PI);
    exit(EXIT_FAILURE);
    }
  return bestq;
  }

