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
#include<r6.h>
#include<c1.h>
#include<c6.h>

/*=====================================
 * csix
 *=====================================*/
/*-------------------------------------------------------------------------
 * csix constructors
 *-------------------------------------------------------------------------*/
csix::csix(void){
  int i; 
  complex p(0,0);
  for(i=0;i<6;i++)z[i]=p;
  }

//csix::csix(double u0, double u1, double u2, double u3, double u4, double u5){
//  z[0]=u0;z[1]=u1;z[2]=u2;z[3]=u3;z[4]=u4;z[5]=u5;
//  }
   
csix::csix(double ur,double ui){
  int i; 
  complex p(ur,ui);
  for(i=0;i<6;i++)z[i]=p;
  }


/*-------------------------------------------------------------------------
 * csix put member functions
 *-------------------------------------------------------------------------*/
void csix::put(double ur, double ui){
  int i; 
  complex p(ur,ui);
  for(i=0;i<6;i++)z[i]=p;
  }

void csix::put(csix u){
  int i; 
  for(i=0;i<6;i++)z[i]=u.get(i);
  } 

/*-------------------------------------------------------------------------
 * return the 6-tuple value
 *-------------------------------------------------------------------------*/
csix csix::get(void){
  csix u;
  int i;
  for(i=0;i<6;i++)u.puti(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * print the tuple
 *-------------------------------------------------------------------------*/
void csix::list(const char *str1, const char *str2){
  int i;
  if(strlen(str1)!=0)printf("%s",str1);
  putchar('(');
  for(i=0;i<5;i++)printf("%+.6lf%+.6lfi,",get(i).real(),get(i).imag());
  printf("%+.6lf%+.6lfi)",get(5).real(),get(5).imag());
  if(strlen(str2)!=0)printf("%s",str2);
  }


/*=====================================
 * vectC6 functions
 *=====================================*/
/*-------------------------------------------------------------------------
 * return the 6-tuple value
 *-------------------------------------------------------------------------*/
vectC6 vectC6::get(void){
  vectC6 u;
  int i;
  for(i=0;i<6;i++)u.puti(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * conjugate
 *-------------------------------------------------------------------------*/
vectC6 vectC6::conj(void){
  complex z,zc;
  vectC6 u;
  int i;
  for(i=0;i<6;i++){
    z=get(i);
    zc=z.conj();
    u.puti(i,zc);
    }
  return u;
  }

/*-------------------------------------------------------------------------
 * magnitude
 *-------------------------------------------------------------------------*/
double vectC6::mag(void){
  int i;
  complex u;
  double sum=0;
  for(i=0;i<6;i++){
    u=get(i);
    sum += u.magsq();
    }
  return sqrt(sum);
  }

/*-------------------------------------------------------------------------
 * operator: +=
 *-------------------------------------------------------------------------*/
void vectC6::operator+=(vectC6 q){
  vectC6  p=get();
  p = p+q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectC6::operator-=(vectC6 q){
  vectC6  p=get();
  p = p-q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectC6::operator*=(double a){
  vectC6  p=get();
  p = a*p;
  put(p);
  }


/*-------------------------------------------------------------------------
 * operator: a*y
 *-------------------------------------------------------------------------*/
vectC6 operator*(const double a, const vectC6 y){
  vectC6 p;
  int i;
  for(i=0;i<6;i++)p.puti(i,a*y.get(i));
  return p;
  }

/*-------------------------------------------------------------------------
 * operator: z*y
 *-------------------------------------------------------------------------*/
vectC6 operator*(const complex z, const vectR6 x){
  vectC6 y;
  double xe;
  complex xez;
  int i;
  for(i=0;i<6;i++){
    xe=x.get(i);
    xez=xe*z;
    y.puti(i,xez);
    }
  return y;
  }

//vectC6 operator*(const complex z, const vectR6 x){
//  vectC6 y(
//z*(x.get1()),
//z*(x.get2()),
//z*(x.get3()),
//z*(x.get4()),
//z*(x.get5()),
//z*(x.get6())); 
//return y;
//}


/*-------------------------------------------------------------------------
 * operator: dot product of p and q
 *-------------------------------------------------------------------------*/
double operator^(vectC6 p,vectC6 q){
  complex sum(0,0);
  complex pp,qq,qqc;
  int i;
  for(i=0;i<6;i++){
    pp = p.get(i);
    qq = q.get(i);
    qqc= qq.conj();
    sum += (pp*(~qq));
    }
  return sum.mag();
  }


/*=====================================
 * seqC6
 *=====================================*/
/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to 0
 *-------------------------------------------------------------------------*/
seqC6::seqC6(long M){
  long n;
  N=M;
  x = (vectC6 *)malloc(N*sizeof(vectC6));
  for(n=0; n<N; n++)x[n].clear();
  }

/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to <u>
 *-------------------------------------------------------------------------*/
//seqC6::seqC6(long M,double ur,double ui){
//  long n;
//  N=M;
//  x = (vectC6 *)malloc(N*sizeof(vectC6));
//  for(n=0; n<N; n++)x[n].put(ur,ui);
//  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with a value <u>
 *-------------------------------------------------------------------------*/
void seqC6::fill(double ur,double ui){
  long n;
  for(n=0; n<N; n++)x[n].put(ur,ui);
  }

/*-------------------------------------------------------------------------
 * put a single value u=(u1,u2,u3,u4,u5,u6) into the seqR1 x at location n
 *-------------------------------------------------------------------------*/
//int seqC6::put(long n, double u1,double u2,double u3,double u4,double u5,double u6){
//  int retval=0;
//  if(n<N)z[n].put(u1,u2,u3,u4,u5,u6);
//  else{
//    fprintf(stderr,"n=%ld larger than seqR1 size N=%ld\n",n,N);
//    retval=-1;
//    }
//  return retval;
//  }

int seqC6::put(long n, vectC6 u){
  int retval=0;
  if(n<N)x[n].put(u);
  else{   
    fprintf(stderr,"n=%ld larger than seqC6 size N=%ld\n",n,N);
    retval=-1;
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * list contents of sequence
 *-------------------------------------------------------------------------*/
void seqC6::list(const long start, const long end, const char* str1, const char *str2, FILE *ptr){
  int i;
  long n,m;
  complex z;
  vectC6 p;
  if(ptr!=NULL){
    if(strlen(str1)>0)fprintf(ptr,"%s",str1);
    for(n=start,m=1; n<=end; n++,m++){
      p=x[n];
      fprintf(ptr,"%6ld: (",n);
      for(i=0;i<6;i++){
        z=p.get(i);
        z.list(ptr);
        if     (i==2)fprintf(ptr,",\n         ");
        else if(i==5)fprintf(ptr,")\n");
        else         fprintf(ptr,",");
        }
      }
    if(strlen(str2)>0)fprintf(ptr,"%s",str2);
    }
  }

/*-------------------------------------------------------------------------
 * list contents of seqR1 using 1 digit per element
 *-------------------------------------------------------------------------*/
//void seqC6::list1(long start, long end){
//  long n,m;
//  vectC6 p;
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
vectC6 operator+(vectC6 p, vectC6 q){
  int i;
  vectC6 y;
  for(i=0;i<6;i++)y.puti(i,p.get(i)+q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return p-q
 *-------------------------------------------------------------------------*/
vectC6 operator-(vectC6 p, vectC6 q){
  int i;
  vectC6 y;
  for(i=0;i<6;i++)y.puti(i,p.get(i)-q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return -p
 *-------------------------------------------------------------------------*/
vectC6 operator-(vectC6 p){
  vectC6 q;
  int i;
  for(i=0;i<6;i++)q.puti(i,-p.get(i));
  return q;
  }

/*-------------------------------------------------------------------------
 * return the angle theta in radians between the two vectors induced by 
 * the points <p> and <q> in the space R^6.
 * on SUCCESS return theta in the half open interval [0:PI)
 * on ERROR   return negative integer
 *-------------------------------------------------------------------------*/
double pqtheta(vectC6 p, vectC6 q){
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
int mag(seqC6 *xC6, seqR1 *ymag){
  long Nx=xC6->getN();
  long Ny=ymag->getN();
  long N=(Nx<Ny)?Nx:Ny;
  long n;
  vectC6  v;
  int retval=0;
  double u;
  double vmag;
  ymag->clear();
  if(Nx!=Ny){
    fprintf(stderr,"WARNING using y=mag(seqC6): lengths of seqC6 (%ld) and y (%ld) differ.\n",Nx,Ny);
    retval=-1;
    }
  else for(n=0;n<N;n++){
    v=xC6->get(n);
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
//seqC6 operator*(seqC6 xx,seqR1 y){
//  long n,m,nm;
//  long Nx=xx.getN();
//  long Ny=y.getN();
//  long N=Nx+Ny-1;
//  seqC6 z(N);
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

