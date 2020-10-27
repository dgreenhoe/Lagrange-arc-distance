/*============================================================================
 * Daniel J. Greenhoe
 * normed linear space R^2
 *============================================================================*/
/*=====================================
 * headers
 *=====================================*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<main.h>
#include<r1.h>
#include<r2.h>
#include<r2op.h>
#include<c1.h>

/*-------------------------------------------------------------------------
 * list value of opair
 *-------------------------------------------------------------------------*/
void complex::list(const char *str1, const char *str2, FILE *ptr){
  if(ptr!=NULL){
    if(strlen(str1)>0)fprintf(ptr,"%s",str1);
    fprintf(ptr,"%+10.6lf%+10.6lfi",getx(),gety());
    if(strlen(str2)>0)fprintf(ptr,"%s",str2);
    }
  }

/*=====================================
 * external operations
 *=====================================*/
///*-------------------------------------------------------------------------
// * compute magnitude of C^1 sequence
// *-------------------------------------------------------------------------*/
//int mag(seqC1 *xC1, seqR1 *ymag){
//  long Nx=xC1->getN();
//  long Ny=ymag->getN();
//  long N=(Nx<Ny)?Nx:Ny;
//  long n;
//  int retval=0;
//  double u;
//  ymag->clear();
//  if(Nx!=Ny){
//    fprintf(stderr,"WARNING using y=mag(xR2): lengths of xR2 (%ld) and ymag (%ld) differ.\n",Nx,Ny);
//    retval=-1;
//    }
//  for(n=0;n<N;n++){
//    u=xC1->norm(n);
//    ymag->put(n,u);
//    }
//  return retval;
//  }
//
///*-------------------------------------------------------------------------
// * operator: return <p> rotated counter-clockwise by <phi> radians
// *-------------------------------------------------------------------------*/
//complex operator&(complex p,double phi){
//  double c,s;
//  complex q;
//  complex Rr; // C->R mapping to compute real      part of rotation
//  complex Rc; // C->R mapping to compute imaginary part of rotation
//
//  if(phi==0){c=1;        s=0;}
//  else      {c=cos(phi); s=sin(phi);}
//  Rr.put(c,-s);
//  Rc.put(s, c);
//  q.put(Rr^p, Rc^p);
//  return q;
//  }
//
///*-------------------------------------------------------------------------
// * return the angle theta in radians between the two vectors induced by 
// * the points <p> and <q> in the plane R^2
// * on SUCCESS return theta in the half open interval [0:PI)
// * on ERROR   return negative integer
// *-------------------------------------------------------------------------*/
//double pqtheta(complex p, complex q){
//  double rp=p.mag(), rq=q.mag();
//  double theta,y;
//  if (rp==0) return -1;
//  if (rq==0) return -2;
//  y = (p^q)/(rp*rq);
//  if (y>+1)  return -3;
//  if (y<-1)  return -4;
//  theta = acos(y);
//  return theta;
//  }

