/*============================================================================
 * Daniel J. Greenhoe
 * operations on R^1 sequences
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
#include<r1op.h>

/*=====================================
 * functionals
 *=====================================*/
/*-------------------------------------------------------------------------
 * compute the root mean square of a sequence
 * [x_n | n=start...n=end]
 *-------------------------------------------------------------------------*/
double rms(seqR1 *x, long start, long end){
  const long Nx = x->getN();
  const long N  = end-start+1;
  long n;
  double xn,sum,avg,rms;
  if(start<0){
    fprintf(stderr,"\nERROR using y=rms(seqR1 *x,start,end): start = %ld < 0\n and ymag (%ld).\n",start);
    exit(EXIT_FAILURE);
    }
  if(end>=Nx){
    fprintf(stderr,"\nERROR using y=rms(seqR1 *x,start,end): end = %ld >= length (%ld) of *x.\n",end,Nx);
    exit(EXIT_FAILURE);
    }
  for(n=start,sum=0;n<=end;n++){
    xn = x->get(n);
    sum += (xn*xn);
    }
  avg = sum/(double)N;
  rms = sqrt(avg);
  return rms;
  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * compute magnitude of R^1 sequence
 *-------------------------------------------------------------------------*/
int mag(seqR1 *xR1, seqR1 *ymag){
  const long Nx=xR1->getN();
  const long Ny=ymag->getN();
  long n;
  int retval=0;
  double u;
  ymag->clear();
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using y=mag(xR2): lengths of xR1 (%ld) and ymag (%ld) differ.\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<Nx;n++){
    u=xR1->get(n);
    ymag->put(n,fabs(u));
    }
  return retval;
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
void convolve(seqR1 *x, seqR1 *y, seqR1 *z, int showcount){
  const long Nx=x->getN();
  const long Ny=y->getN();
  const long Nz=z->getN();
  long n,m,nm;
  double u,sum;
  double v;
  if(Nz!=Nx+Ny-1){//check length of *z
    fprintf(stderr,"\nERROR using using convolve(seqR1 *x, seqR1 *y, seqR1 *z): %ld = Nz != Nx+Ny-1 = %ld+%ld-1 = %ld\n",Nz,Nx,Ny,Nx+Ny-1);
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
 * compute y=sin(x), where x and y are sequences
 * return 0 on success
 *-------------------------------------------------------------------------*/
int sin(seqR1 *x, seqR1 *y){
  const long Nx=x->getN();
  const long Ny=y->getN();
  long n;
  double xx,yy;
  int retval=0;
  y->clear();
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using sin(seqR1 *x, seqR1 *y): length of x (%ld) != length of y(%ld).\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<Nx;n++){
    xx=x->get(n);
    yy=sin(xx);
    y->put(n,yy);
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * copy the sequence <*x> = [x_start ... x_end] 
 * into the sequence <*y> = [y_0     ... y_{N-1}] 
 * where N = end-start+1
 *-------------------------------------------------------------------------*/
void copy(const long start, const long end, const seqR1 *x, const seqR1 *y){
  long Nx=x->getN();
  long Ny=y->getN();
  long n,m;
  double xx;
  y->clear();
  if(end>=Nx){
    fprintf(stderr,"ERROR using copy(start,end,seqR1 *x, seqR1 *y): <end>=%ld is too large.\n",end);
    exit(EXIT_FAILURE);
    }
  if((end-start)!=Ny){
    fprintf(stderr,"ERROR using copy(start,seqR1 *x, seqR1 *y): length of [x_start...x_end] (%ld) != length of y(%ld).\n",Nx-start,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=start;n<=end;n++){
    xx=x->get(n);
    y->put(n,xx);
    }
  }

/*-------------------------------------------------------------------------
 * downsample the sequence <x> by a factor <M> resulting in a sequence <y>
 * return 0 on success
 *-------------------------------------------------------------------------*/
int downsample(const long M, const seqR1 *x, const seqR1 *y){
  long Nx=x->getN();
  long Ny=y->getN();
  long n,m;
  double xx;
  int retval=0;
  y->clear();
  if(Nx/M!=Ny){
    fprintf(stderr,"ERROR using downsample(M,seqR1 *x, seqR1 *y): length of x / %ld (%ld) != length of y(%ld).\n",M,Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0,m=0;n<Nx;n+=M,m++){
    xx=x->get(n);
    y->put(m,xx);
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * compute y=sin(x), where x and y are sequences
 * return 0 on success
 *-------------------------------------------------------------------------*/
int cos(seqR1 *x, seqR1 *y){
  const long Nx=x->getN();
  const long Ny=y->getN();
  long n;
  double xx,yy;
  int retval=0;
  y->clear();
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using cos(seqR1 *x, seqR1 *y): length of x (%ld) != length of y(%ld).\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<Nx;n++){
    xx=x->get(n);
    yy=cos(xx);
    y->put(n,yy);
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * compute y=sin(x), where x and y are sequences and 
 * x is the seqR1 (0u, 1u, 2u, 3u, ..., (N-1)u)
 * return 0 on success
 *-------------------------------------------------------------------------*/
int sin(double u, seqR1 *y){
  long N=y->getN();
  long n;
  double xx,yy;
  int retval=0;
  y->clear();
  for(n=0;n<N;n++){
    xx=(double)n*u;
    yy=sin(xx);
    y->put(n,yy);
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * compute y=cos(x), where x and y are sequences and 
 * x is the seqR1 (0u, 1u, 2u, 3u, ..., (N-1)u)
 * return 0 on success
 *-------------------------------------------------------------------------*/
int cos(double u, seqR1 *y){
  long N=y->getN();
  long n;
  double xx,yy;
  int retval=0;
  y->clear();
  for(n=0;n<N;n++){
    xx=(double)n*u;
    yy=cos(xx);
    y->put(n,yy);
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * negate each element in a seqR1 x
 *-------------------------------------------------------------------------*/
seqR1 operator-(seqR1 x){
  long n;
  double u;
  seqR1 y(x.getN());
  for(n=0;n<x.getN();n++){
    u=-x.get(n);
    y.put(n,u);
    }
  return y;
  }

/*-------------------------------------------------------------------------
 * z = x+y
 *-------------------------------------------------------------------------*/
seqR1 operator+(seqR1 x,seqR1 y){
  long Nx=x.getN();
  long Ny=y.getN();
  long n,N;
  if(Nx<=Ny)N=Nx; else N=Ny;
  seqR1 z(N);
  for(n=0;n<N;n++)z.put(n,x.get(n)+y.get(n));
  return z;
  }

/*-------------------------------------------------------------------------
 * z = x-y
 *-------------------------------------------------------------------------*/
seqR1 operator-(seqR1 x,seqR1 y){
  long Nx=x.getN();
  long Ny=y.getN();
  long n,N;
  if(Nx<=Ny)N=Nx; else N=Ny;
  seqR1 z(N);
  for(n=0;n<N;n++)z.put(n,x.get(n)-y.get(n));
  return z;
  }




