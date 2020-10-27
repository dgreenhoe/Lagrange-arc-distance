/*============================================================================
 * Daniel J. Greenhoe
 * operations on R^3 sequences
 *============================================================================*/
/*=====================================
 * headers
 *=====================================*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<main.h>
#include<r1.h>
#include<r3.h>
#include<r3op.h>

/*=====================================
 * operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * compute the magnitude of sequence <x> over R^2 
 * yielding the sequence <y> over R^1
 *-------------------------------------------------------------------------*/
void mag(seqR3 *x, seqR1 *y){
  const long Nx=x->getN();
  const long Ny=y->getN();
  long n;
  vectR3 xn;  //nth element of sequence <*x>
  double xnm; //magnitude of xn
  y->clear();//not necessary but may help robustness and/or for debugging
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using mag(seqR3 *x,seqR1 *y): lengths of *x (%ld) and *y (%ld) differ.\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<Nx;n++){
    xn  = x->get(n);
    xnm = xn.mag();
    y->put(n,xnm);
    }
  }

/*-------------------------------------------------------------------------
 * z = x * y where * represents convolution
 * Let  <*x> be a length Nx sequence over R^6 
 * and  <*y> be a length Ny sequence over R^1.
 * Then <*z> is a length Nz=Nx+Ny-1 sequence over R^6
 *                      m=n
 * z[n] = x[n] * y[n] = SUM   x[m]*y[n-m]
 *                      m=0
 *-------------------------------------------------------------------------*/
void convolve(seqR3 *x, seqR1 *y, seqR3 *z, int showcount){
  const long Nx=x->getN();
  const long Ny=y->getN();
  const long Nz=z->getN();
  long n,m,nm;
  vectR3 u,sum;
  double v;
  if(Nz!=Nx+Ny-1){//check length of *z
    fprintf(stderr,"\nERROR using using convolve(seqR6 *x, seqR1 *y, seqR6 *z): %ld = Nz != Nx+Ny-1 = %ld+%ld-1 = %ld\n",Nz,Nx,Ny,Nx+Ny-1);
    exit(EXIT_FAILURE);
    }
  if(showcount)fprintf(stderr,"%10ld  ",0);
  for(n=0;n<Nz;n++){
    if(showcount)fprintf(stderr,"\b\b\b\b\b\b\b\b\b\b\b\b%10ld  ",n);
    sum=0;
    for(m=0;m<=n;m++){
      nm=n-m;
      if(m>=Nx)         u=0;
      else              u=x->get(m);
      if(nm<0 || nm>=Ny)v=0;
      else              v=y->get(nm);
      sum += u*v;
      //printf("n=%3ld m=%3ld n-m=%3ld u=%7.3lf v=%7.3lf sum=%7.3lf\n",n,m,nm,u,v,sum);
      }
    z->put(n,sum);
    }
  }

/*-------------------------------------------------------------------------
 * compute min of R^3 sequence
 *-------------------------------------------------------------------------*/
int min(seqR3 *xR3, seqR1 *ymin){
  long Nx=xR3->getN();
  long Ny=ymin->getN();
  long N=(Nx<Ny)?Nx:Ny;
  long n;
  int retval=0;
  vectR3 u;
  ymin->clear();
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using y=min(xR3): lengths of xR3 (%ld) and ymax (%ld) differ.\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<N;n++){
    u=xR3->get(n);
    ymin->put(n,u.min());
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * compute min of R^3 sequence
 *-------------------------------------------------------------------------*/
int max(seqR3 *xR3, seqR1 *ymax){
  long Nx=xR3->getN();
  long Ny=ymax->getN();
  long N=(Nx<Ny)?Nx:Ny;
  long n;
  int retval=0;
  vectR3 u;
  ymax->clear();
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using y=max(xR3): lengths of xR3 (%ld) and ymax (%ld) differ.\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<N;n++){
    u=xR3->get(n);
    ymax->put(n,u.max());
    }
  return retval;
  }

