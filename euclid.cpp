/*============================================================================
 * Daniel J. Greenhoe
 * alpha-scaled Euclidean metric routines
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
#include<r6.h>
#include<euclid.h>

/*-------------------------------------------------------------------------
 * alpha-scaled Euclidean metric from <p> to <q>
 *-------------------------------------------------------------------------*/
double ae_metric(double alpha, vectR2 p, vectR2 q){
  vectR2 pq=p-q;
  double d=pq.mag();
  double ds=d*alpha;
  return ds;
  }
double ae_metric(double alpha, vectR3 p, vectR3 q){
  vectR3 pq=p-q;
  double d=pq.mag();
  double ds=d*alpha;
  return ds;
  }
double ae_metric(double alpha, vectR6 p, vectR6 q){
  vectR6 pq=p-q;
  double d=pq.mag();
  double ds=d*alpha;
  return ds;
  }

/*-------------------------------------------------------------------------
 * Find the polar length of a point q with radial measure tq that is a 
 * distance <d> from the point <p> with polar coordinates (rp,tp)
 * using search resolution <N>
 *-------------------------------------------------------------------------*/
vectR3 ae_findq(double alpha, vectR3 p, double theta, double phi, double d, long int N){
  double smallesterror=100000,rq,dd,errord;
  vectR3 bestq;
  vectR3 q;

  for(rq=0; rq<=5; rq+=5.0/N){
    q.polartoxyz(rq,theta,phi);
    dd=ae_metric(alpha,p,q);
    errord=fabs(d-dd);
    if(errord<smallesterror){
      bestq=q;
      smallesterror=errord;
      }
    }
  return bestq;
  }





