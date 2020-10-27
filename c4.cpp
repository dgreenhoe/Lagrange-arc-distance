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
#include<r4.h>
#include<c1.h>
#include<c4.h>

/*=====================================
 * cfour
 *=====================================*/
/*-------------------------------------------------------------------------
 * cfour constructors
 *-------------------------------------------------------------------------*/
cfour::cfour(void){
  int i; 
  complex p(0,0);
  for(i=0;i<4;i++)z[i]=p;
  }

//cfour::cfour(double u0, double u1, double u2, double u3, double u4, double u5){
//  z[0]=u0;z[1]=u1;z[2]=u2;z[3]=u3;z[4]=u4;z[5]=u5;
//  }
   
cfour::cfour(double ur,double ui){
  int i; 
  complex p(ur,ui);
  for(i=0;i<4;i++)z[i]=p;
  }


/*-------------------------------------------------------------------------
 * cfour put member functions
 *-------------------------------------------------------------------------*/
void cfour::put(double ur, double ui){
  int i; 
  complex p(ur,ui);
  for(i=0;i<4;i++)z[i]=p;
  }

void cfour::put(cfour u){
  int i; 
  for(i=0;i<4;i++)z[i]=u.get(i);
  } 

/*-------------------------------------------------------------------------
 * return the 4-tuple value
 *-------------------------------------------------------------------------*/
cfour cfour::get(void){
  cfour u;
  int i;
  for(i=0;i<4;i++)u.puti(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * print the tuple
 *-------------------------------------------------------------------------*/
void cfour::list(const char *str1, const char *str2){
  int i;
  if(strlen(str1)!=0)printf("%s",str1);
  putchar('(');
  for(i=0;i<5;i++)printf("%+.6lf%+.6lfi,",get(i).real(),get(i).imag());
  printf("%+.6lf%+.6lfi)",get(5).real(),get(5).imag());
  if(strlen(str2)!=0)printf("%s",str2);
  }


/*=====================================
 * vectC4 functions
 *=====================================*/
/*-------------------------------------------------------------------------
 * return the 4-tuple value
 *-------------------------------------------------------------------------*/
vectC4 vectC4::get(void){
  vectC4 u;
  int i;
  for(i=0;i<4;i++)u.puti(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * conjugate
 *-------------------------------------------------------------------------*/
vectC4 vectC4::conj(void){
  complex z,zc;
  vectC4 u;
  int i;
  for(i=0;i<4;i++){
    z=get(i);
    zc=z.conj();
    u.puti(i,zc);
    }
  return u;
  }

/*-------------------------------------------------------------------------
 * magnitude
 *-------------------------------------------------------------------------*/
double vectC4::mag(void){
  int i;
  complex u;
  double sum=0;
  for(i=0;i<4;i++){
    u=get(i);
    sum += u.magsq();
    }
  return sqrt(sum);
  }

/*-------------------------------------------------------------------------
 * operator: +=
 *-------------------------------------------------------------------------*/
void vectC4::operator+=(vectC4 q){
  vectC4  p=get();
  p = p+q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectC4::operator-=(vectC4 q){
  vectC4  p=get();
  p = p-q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectC4::operator*=(double a){
  vectC4  p=get();
  p = a*p;
  put(p);
  }


/*-------------------------------------------------------------------------
 * operator: a*y
 *-------------------------------------------------------------------------*/
vectC4 operator*(const double a, const vectC4 y){
  vectC4 p;
  int i;
  for(i=0;i<4;i++)p.puti(i,a*y.get(i));
  return p;
  }

/*-------------------------------------------------------------------------
 * operator: z*y
 *-------------------------------------------------------------------------*/
vectC4 operator*(const complex z, const vectR4 x){
  vectC4 y;
  double xe;
  complex xez;
  int i;
  for(i=0;i<4;i++){
    xe=x.get(i);
    xez=xe*z;
    y.puti(i,xez);
    }
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: dot product of p and q
 *-------------------------------------------------------------------------*/
double operator^(vectC4 p,vectC4 q){
  complex sum(0,0);
  complex pp,qq,qqc;
  int i;
  for(i=0;i<4;i++){
    pp = p.get(i);
    qq = q.get(i);
    qqc= qq.conj();
    sum += (pp*(~qq));
    }
  return sum.mag();
  }


/*=====================================
 * seqC4
 *=====================================*/
/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to 0
 *-------------------------------------------------------------------------*/
seqC4::seqC4(long M){
  long n;
  N=M;
  x = (vectC4 *)malloc(N*sizeof(vectC4));
  for(n=0; n<N; n++)x[n].clear();
  }

/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to <u>
 *-------------------------------------------------------------------------*/
//seqC4::seqC4(long M,double ur,double ui){
//  long n;
//  N=M;
//  x = (vectC4 *)malloc(N*sizeof(vectC4));
//  for(n=0; n<N; n++)x[n].put(ur,ui);
//  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with a value <u>
 *-------------------------------------------------------------------------*/
void seqC4::fill(double ur,double ui){
  long n;
  for(n=0; n<N; n++)x[n].put(ur,ui);
  }

/*-------------------------------------------------------------------------
 * put a single value u=(u1,u2,u3,u4) into the seqC4 x at location n
 *-------------------------------------------------------------------------*/
int seqC4::put(long n, vectC4 u){
  int retval=0;
  if(n<N)x[n].put(u);
  else{   
    fprintf(stderr,"n=%ld larger than seqC4 size N=%ld\n",n,N);
    retval=-1;
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * list contents of sequence
 *-------------------------------------------------------------------------*/
void seqC4::list(long start, long end){
  int i;
  long n,m;
  vectC4 p;
  for(n=start,m=1; n<=end; n++,m++){
    p=x[n];
    printf("(");
    for(i=0;i<5;i++){
      (p.get(i)).list();
      printf(",");
      }
    (p.get(5)).list();
    printf(")\n");
    //if(m%2==0)printf("\n");
    }
  }

/*-------------------------------------------------------------------------
 * list contents of seqR1 using 1 digit per element
 *-------------------------------------------------------------------------*/
//void seqC4::list1(long start, long end){
//  long n,m;
//  vectC4 p;
//  for(n=start,m=1; n<=end; n++,m++){
//    p=z[n];
//    printf(" %1.0lf%1.0lf%1.0lf%1.0lf%1.0lf%1.0lf",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6());
//    if(m%10==0)printf("\n");
//    }
//  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * operator: return p+q
 *-------------------------------------------------------------------------*/
vectC4 operator+(vectC4 p, vectC4 q){
  int i;
  vectC4 y;
  for(i=0;i<4;i++)y.puti(i,p.get(i)+q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return p-q
 *-------------------------------------------------------------------------*/
vectC4 operator-(vectC4 p, vectC4 q){
  int i;
  vectC4 y;
  for(i=0;i<4;i++)y.puti(i,p.get(i)-q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return -p
 *-------------------------------------------------------------------------*/
vectC4 operator-(vectC4 p){
  vectC4 q;
  int i;
  for(i=0;i<4;i++)q.puti(i,-p.get(i));
  return q;
  }

/*-------------------------------------------------------------------------
 * return the angle theta in radians between the two vectors induced by 
 * the points <p> and <q> in the space R^4.
 * on SUCCESS return theta in the half open interval [0:PI)
 * on ERROR   return negative integer
 *-------------------------------------------------------------------------*/
double pqtheta(vectC4 p, vectC4 q){
  double rp=p.r(), rq=q.r();
  if(rp==0) return -1;
  if(rq==0) return -2;
  double y = (p^q)/(p.mag()*q.mag());
  if(y>+1)  return -3;
  if(y<-1)  return -4;
  double theta = acos(y);
  return theta;
  }

/*-------------------------------------------------------------------------
 * compute magnitude of C^1 sequence
 *-------------------------------------------------------------------------*/
int mag(seqC4 *xC4, seqR1 *ymag){
  long Nx=xC4->getN();
  long Ny=ymag->getN();
  long N=(Nx<Ny)?Nx:Ny;
  long n;
  vectC4  v;
  int retval=0;
  double u;
  double vmag;
  ymag->clear();
  if(Nx!=Ny){
    fprintf(stderr,"WARNING using y=mag(seqC4): lengths of seqC4 (%ld) and y (%ld) differ.\n",Nx,Ny);
    retval=-1;
    }
  else for(n=0;n<N;n++){
    v=xC4->get(n);
    vmag=v.norm();
    ymag->put(n,vmag);
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * z = x * y where * represents convolution
 * let x be a seqR1 of length M1 and y be a seqR1 of length M2
 * then z is a seqR1 of length N=M1+M2-1
 *
 *                      m=n
 * z[n] = z[n] * y[n] = SUM   z[m]*y[n-m]
 *                      m=0
 *-------------------------------------------------------------------------*/
//seqC4 operator*(seqC4 xx,seqR1 y){
//  long n,m,nm;
//  long Nx=xx.getN();
//  long Ny=y.getN();
//  long N=Nx+Ny-1;
//  seqC4 z(N);
//  double u1,u2,u3,u4,u5,u6;
//  double v;
//  double sum1,sum2,sum3,sum4,sum5,sum6;
//  for(n=0;n<N;n++){
//    sum1=0; sum2=0; sum3=0; sum4=0; sum5=0; sum6=0; 
//    for(m=0;m<=n;m++){
//      nm=n-m;
//      if(m>=Nx){ u1=0;           u2=0;           u3=0;           u3=0;           u4=0;           u5=0;           u6=0;          }
//      else     { u1=xx.get1(m); u2=xx.get2(m); u3=xx.get3(m); u3=xx.get3(m); u4=xx.get4(m); u5=xx.get5(m); u6=xx.get6(m);}
//      if(nm<0 || nm>=Ny)v=0;
//      else              v=y.get(nm);
//      sum1 += u1*v;
//      sum2 += u2*v;
//      sum3 += u3*v;
//      sum4 += u4*v;
//      sum5 += u5*v;
//      sum6 += u6*v;
//      //printf("n=%3ld m=%3ld n-m=%3ld u=%7.3lf v=%7.3lf sum=%7.3lf\n",n,m,nm,u,v,sum);
//      }
//    z.put(n,sum1,sum2,sum3,sum4,sum5,sum6);
//    }
//  return z;
//  }

