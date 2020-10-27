/*============================================================================
 * Daniel J. Greenhoe
 * operations on R^2 and on R^2 sequences
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
#include<r2op.h>

/*-------------------------------------------------------------------------
 * operator: return A+B 
 * where <A> is the private data of the mat2x2 structure
 * and   <B> is a mat2x2 argument
 *  _  A  _  +  _  B  _  =  _     A'   _     _       _ 
 * |  a b  | + |  w x  | = |  a+w  b+x  | = |  a' b'  |
 * |_ c d _|   |_ y z _|   |_ c+y  d+z _|   |_ c' d' _|
 *-------------------------------------------------------------------------*/
void mat2x2::operator+=(mat2x2 B){
  a+=B.getAa();
  b+=B.getAb();
  c+=B.getAc();
  d+=B.getAd();
  }

/*-------------------------------------------------------------------------
 * operator: return A-B 
 * where <A> is the private data of the mat2x2 structure
 * and   <B> is a mat2x2 argument
 *  _  A  _  -  _  B  _  =  _     A'   _     _       _ 
 * |  a b  | - |  w x  | = |  a-w  b-x  | = |  a' b'  |
 * |_ c d _|   |_ y z _|   |_ c-y  d-z _|   |_ c' d' _|
 *-------------------------------------------------------------------------*/
void mat2x2::operator-=(mat2x2 B){
  a-=B.getAa();
  b-=B.getAb();
  c-=B.getAc();
  d-=B.getAd();
  }

/*=====================================
 * operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * compute the magnitude of sequence <x> over R^2 
 * yielding the sequence <y> over R^1
 *-------------------------------------------------------------------------*/
void mag(seqR2 *x, seqR1 *y){
  const long Nx=x->getN();
  const long Ny=y->getN();
  long n;
  vectR2 xn;  //nth element of sequence <*x>
  double xnm; //magnitude of xn
  y->clear();//not necessary but may help robustness and/or for debugging
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using mag(seqR2 *x,seqR1 *y): lengths of *x (%ld) and *y (%ld) differ.\n",Nx,Ny);
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
void convolve(seqR2 *x, seqR1 *y, seqR2 *z, int showcount){
  const long Nx=x->getN();
  const long Ny=y->getN();
  const long Nz=z->getN();
  long n,m,nm;
  vectR2 u,sum;
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
      }
    z->put(n,sum);
    }
  }



/*=====================================
 * symbolic operators
 *=====================================*/
/*-------------------------------------------------------------------------
 * operator: return A+B where <A> and <B> are 2x2 matrices
 *  _  A  _  +  _  B  _  =  _     C    _ 
 * |  a b  | + |  w x  | = |  a+w  b+x  |
 * |_ c d _|   |_ y z _|   |_ c+y  d+z _|
 *-------------------------------------------------------------------------*/
mat2x2 operator+(mat2x2 A, mat2x2 B){
  double a=A.getAa();
  double b=A.getAb();
  double c=A.getAc();
  double d=A.getAd();
  double w=B.getAa();
  double x=B.getAb();
  double y=B.getAc();
  double z=B.getAd();
  mat2x2 C(a+w,b+x,c+y,d+z);
  return C;
  }

/*-------------------------------------------------------------------------
 * operator: return A+B where <A> and <B> are 2x2 matrices
 *  _  A  _  -  _  B  _  =  _     C    _ 
 * |  a b  | - |  w x  | = |  a-w  b-x  |
 * |_ c d _|   |_ y z _|   |_ c-y  d-z _|
 *-------------------------------------------------------------------------*/
mat2x2 operator-(mat2x2 A, mat2x2 B){
  double a=A.getAa();
  double b=A.getAb();
  double c=A.getAc();
  double d=A.getAd();
  double w=B.getAa();
  double x=B.getAb();
  double y=B.getAc();
  double z=B.getAd();
  mat2x2 C(a-w,b-x,c-y,d-z);
  return C;
  }

/*-------------------------------------------------------------------------
 * operator: return -A where <A> is a 2x2 matrix
 *  _ -A  _  =  _  B   _
 * |  a b  | = | -a -b  |
 * |_ c d _|   |_-c -d _|
 *-------------------------------------------------------------------------*/
mat2x2 operator-(mat2x2 A){
  double a=A.getAa();
  double b=A.getAb();
  double c=A.getAc();
  double d=A.getAd();
  mat2x2  B(-a,-b,-c,-d);
  return B;
  }

/*-------------------------------------------------------------------------
 * operator: return Ap = q
 *  _  A  _   _ p _ =  _  q   _
 * |  a b  | |  x  |= | ax+by  |
 * |_ c d _| |_ y _|  |_cx+dy _|
 *-------------------------------------------------------------------------*/
vectR2 operator*(mat2x2 A,vectR2 p){
  vectR2 q(A.rov1()^p,A.rov2()^p);
  return q;
  }

