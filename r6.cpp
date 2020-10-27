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
#include<r6.h>

/*=====================================
 * osix
 *=====================================*/
/*-------------------------------------------------------------------------
 * osix constructors
 *-------------------------------------------------------------------------*/
osix::osix(void){
  int i; 
  for(i=0;i<6;i++)x[i]=0;
  }

osix::osix(double u0, double u1, double u2, double u3, double u4, double u5){
  x[0]=u0;x[1]=u1;x[2]=u2;x[3]=u3;x[4]=u4;x[5]=u5;
  }
   
osix::osix(double u){
  int i; 
  for(i=0;i<6;i++)x[i]=u;
  }


/*-------------------------------------------------------------------------
 * osix put member functions
 *-------------------------------------------------------------------------*/
void osix::put(double u){
  int i; 
  for(i=0;i<6;i++)x[i]=u;
  }

void osix::put(osix u){
  int i; 
  for(i=0;i<6;i++)x[i]=u.get(i);
  } 

/*-------------------------------------------------------------------------
 * return the 6-tuple value
 *-------------------------------------------------------------------------*/
osix osix::get(void){
  osix u;
  int i;
  for(i=0;i<6;i++)u.put(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * return the minimum element of the 6 tupple
 *-------------------------------------------------------------------------*/
double osix::min(void){
  int i;
  double u,min;
  min=fabs(x[0]);
  for(i=1;i<6;i++){
    u=fabs(x[i]);
    if(u<min) min=u;
    }
  return min;
  }

/*-------------------------------------------------------------------------
 * return the maximum element of the 6 tupple
 *-------------------------------------------------------------------------*/
double osix::max(void){
  int i;
  double u,max;
  max=fabs(x[0]);
  for(i=1;i<6;i++){
    u=fabs(x[i]);
    if(u>max) max=u;
    }
  return max;
  }

/*-------------------------------------------------------------------------
 * print the tuple
 *-------------------------------------------------------------------------*/
void osix::list(const char *str1, const char *str2){
  int i;
  if(strlen(str1)!=0)printf("%s",str1);
  putchar('(');
  for(i=0;i<5;i++)printf("%9.6lf,",get(i));
  printf("%9.6lf)",get(5));
  if(strlen(str2)!=0)printf("%s",str2);
  }


/*=====================================
 * vectR6 functions
 *=====================================*/
/*-------------------------------------------------------------------------
 * return the 6-tuple value
 *-------------------------------------------------------------------------*/
vectR6 vectR6::get(void){
  vectR6 u;
  int i;
  for(i=0;i<6;i++)u.put(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * magnitude
 *-------------------------------------------------------------------------*/
double vectR6::mag(void){
  int i;
  double u;
  double sum=0;
  for(i=0;i<6;i++){
    u=get(i);
    sum += u*u;
    }
  return sqrt(sum);
  }

/*-------------------------------------------------------------------------
 * add a scalar
 *-------------------------------------------------------------------------*/
vectR6 vectR6::mpy(double a){
  int i;
  vectR6 y;
  for(i=0;i<6;i++)y.put(get(i)*a);
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: +=
 *-------------------------------------------------------------------------*/
void vectR6::operator+=(vectR6 q){
  vectR6  p=get();
  p = p+q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectR6::operator-=(vectR6 q){
  vectR6  p=get();
  p = p-q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectR6::operator*=(double a){
  vectR6  p=get();
  p = a*p;
  put(p);
  }


/*-------------------------------------------------------------------------
 * operator: a*y
 *-------------------------------------------------------------------------*/
vectR6 operator*(const double a, const vectR6 y){
  vectR6 p;
  int i;
  for(i=0;i<6;i++)p.put(i,a*y.get(i));
  return p;
  }

/*-------------------------------------------------------------------------
 * operator: dot product of p and q
 *-------------------------------------------------------------------------*/
double operator^(vectR6 p,vectR6 q){
  double sum=0;
  int i;
  for(i=0;i<6;i++)sum += p.get(i)*q.get(i);
  return sum;
  }


/*=====================================
 * seqR6
 *=====================================*/
/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to 0
 *-------------------------------------------------------------------------*/
seqR6::seqR6(long M){
  long n;
  N=M;
  x = (vectR6 *)malloc(N*sizeof(vectR6));
  for(n=0; n<N; n++)x[n].clear();
  }

/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to <u>
 *-------------------------------------------------------------------------*/
seqR6::seqR6(long M,double u){
  long n;
  N=M;
  x = (vectR6 *)malloc(N*sizeof(vectR6));
  for(n=0; n<N; n++)x[n].put(u);
  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with a value <u>
 *-------------------------------------------------------------------------*/
void seqR6::fill(double u){
  long n;
  for(n=0; n<N; n++)x[n].put(u);
  }

/*-------------------------------------------------------------------------
 * put a single value u=(u1,u2,u3,u4,u5,u6) into the seqR1 x at location n
 *-------------------------------------------------------------------------*/
int seqR6::put(long n, double u1,double u2,double u3,double u4,double u5,double u6){
  int retval=0;
  if(n<N)x[n].put(u1,u2,u3,u4,u5,u6);
  else{
    fprintf(stderr,"n=%ld larger than seqR1 size N=%ld\n",n,N);
    retval=-1;
    }
  return retval;
  }

int seqR6::put(long n, vectR6 u){
  int retval=0;
  if(n<N)x[n].put(u);
  else{   
    fprintf(stderr,"n=%ld larger than seqR6 size N=%ld\n",n,N);
    retval=-1;
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * list contents of sequence
 *-------------------------------------------------------------------------*/
void seqR6::list(const long start, const long end, const char* str1, const char *str2, FILE *ptr){
  long n,m;
  vectR6 p;
  if(ptr!=NULL){
    if(strlen(str1)>0)fprintf(ptr,"%s",str1);
    for(n=start,m=1; n<=end; n++,m++){
      p=x[n];
      fprintf(ptr,"(%5.2lf,%5.2lf,%5.2lf,%5.2lf,%5.2lf,%5.2lf) ",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6());
      if(m%2==0)fprintf(ptr,"\n");
      }
    if(strlen(str2)>0)fprintf(ptr,"%s",str2);
    }
  }

/*-------------------------------------------------------------------------
 * list contents of seqR1 using 1 digit per element
 *-------------------------------------------------------------------------*/
void seqR6::list1(const long start, const long end, const char *str1, const char *str2,FILE *ptr){
  long n,m;
  vectR6 p;
  if(ptr!=NULL){
    if(strlen(str1)>0)fprintf(ptr,"%s",str1);
    for(n=start,m=1; n<=end; n++,m++){
      p=x[n];
      fprintf(ptr," %1.0lf%1.0lf%1.0lf%1.0lf%1.0lf%1.0lf",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6());
      if(m%10==0)fprintf(ptr,"\n");
      }
    if(strlen(str2)>0)fprintf(ptr,"%s",str2);
    }
  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * operator: return p+q
 *-------------------------------------------------------------------------*/
vectR6 operator+(vectR6 p, vectR6 q){
  int i;
  vectR6 y;
  for(i=0;i<6;i++)y.put(i,p.get(i)+q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return p-q
 *-------------------------------------------------------------------------*/
vectR6 operator-(vectR6 p, vectR6 q){
  int i;
  vectR6 y;
  for(i=0;i<6;i++)y.put(i,p.get(i)-q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return -p
 *-------------------------------------------------------------------------*/
vectR6 operator-(vectR6 p){
  vectR6 q;
  int i;
  for(i=0;i<6;i++)q.put(i,-p.get(i));
  return q;
  }

/*-------------------------------------------------------------------------
 * return the angle theta in radians between the two vectors induced by 
 * the points <p> and <q> in the space R^6.
 * on SUCCESS return theta in the closed interval [0:PI]
 * on ERROR   return negative value or exit with value EXIT_FAILURE
 *-------------------------------------------------------------------------*/
double pqtheta(const vectR6 p, const vectR6 q){
  const double rp=p.r(), rq=q.r();
  double y,theta;
  if(rp==0) return -1;
  if(rq==0) return -2;
  y = (p^q)/(rp*rq);
  if(y>+1)  {fprintf(stderr,"\nERROR using pqtheta(vectR6 p, vectR6 q): (p^q)/(rp*rq)=%lf>+1\n",y); exit(EXIT_FAILURE);}
  if(y<-1)  {fprintf(stderr,"\nERROR using pqtheta(vectR6 p, vectR6 q): (p^q)/(rp*rq)=%lf<-1\n",y); exit(EXIT_FAILURE);}
  theta = acos(y);
  return theta;
  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * compute magnitude of R^1 sequence
 *-------------------------------------------------------------------------*/
int mag(seqR6 *xR6, seqR1 *ymag){
  const long Nx=xR6->getN();
  const long Ny=ymag->getN();
  long n;
  int retval=0;
  vectR6 u;
  ymag->clear();
  if(Nx!=Ny){
    fprintf(stderr,"\nERROR using y=mag(xR6): lengths of xR6 (%ld) and ymag (%ld) differ.\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<Nx;n++){
    u=xR6->get(n);
    ymag->put(n,u.mag());
    }
  return retval;
  }

