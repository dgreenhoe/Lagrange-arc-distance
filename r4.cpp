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
#include<r4.h>

/*=====================================
 * oquad
 *=====================================*/
/*-------------------------------------------------------------------------
 * oquad constructors
 *-------------------------------------------------------------------------*/
oquad::oquad(void){
  int i; 
  for(i=0;i<4;i++)x[i]=0;
  }

oquad::oquad(double u0, double u1, double u2, double u3){
  x[0]=u0;x[1]=u1;x[2]=u2;x[3]=u3;
  }
   
oquad::oquad(double u){
  int i; 
  for(i=0;i<4;i++)x[i]=u;
  }


/*-------------------------------------------------------------------------
 * oquad put member functions
 *-------------------------------------------------------------------------*/
void oquad::put(double u){
  int i; 
  for(i=0;i<4;i++)x[i]=u;
  }

void oquad::put(oquad u){
  int i; 
  for(i=0;i<4;i++)x[i]=u.get(i);
  } 

/*-------------------------------------------------------------------------
 * return the 4-tuple value
 *-------------------------------------------------------------------------*/
oquad oquad::get(void){
  oquad u;
  int i;
  for(i=0;i<4;i++)u.put(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * return the minimum element of the 4 tupple
 *-------------------------------------------------------------------------*/
double oquad::min(void){
  int i;
  double u,min;
  min=fabs(x[0]);
  for(i=1;i<4;i++){
    u=fabs(x[i]);
    if(u<min) min=u;
    }
  return min;
  }

/*-------------------------------------------------------------------------
 * return the maximum element of the 4 tupple
 *-------------------------------------------------------------------------*/
double oquad::max(void){
  int i;
  double u,max;
  max=fabs(x[0]);
  for(i=1;i<4;i++){
    u=fabs(x[i]);
    if(u>max) max=u;
    }
  return max;
  }

/*-------------------------------------------------------------------------
 * print the tuple
 *-------------------------------------------------------------------------*/
void oquad::list(const char *str1, const char *str2){
  int i;
  if(strlen(str1)!=0)printf("%s",str1);
  putchar('(');
  for(i=0;i<5;i++)printf("%9.6lf,",get(i));
  printf("%9.6lf)",get(5));
  if(strlen(str2)!=0)printf("%s",str2);
  }


/*=====================================
 * vectR4 functions
 *=====================================*/
/*-------------------------------------------------------------------------
 * return the 4-tuple value
 *-------------------------------------------------------------------------*/
vectR4 vectR4::get(void){
  vectR4 u;
  int i;
  for(i=0;i<4;i++)u.put(i,get(i));
  return u;
  }

/*-------------------------------------------------------------------------
 * magnitude
 *-------------------------------------------------------------------------*/
double vectR4::mag(void){
  int i;
  double u;
  double sum=0;
  for(i=0;i<4;i++){
    u=get(i);
    sum += u*u;
    }
  return sqrt(sum);
  }

/*-------------------------------------------------------------------------
 * operator: +=
 *-------------------------------------------------------------------------*/
void vectR4::operator+=(vectR4 q){
  vectR4  p=get();
  p = p+q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectR4::operator-=(vectR4 q){
  vectR4  p=get();
  p = p-q;
  put(p);
  }

/*-------------------------------------------------------------------------
 * operator: -=
 *-------------------------------------------------------------------------*/
void vectR4::operator*=(double a){
  vectR4  p=get();
  p = a*p;
  put(p);
  }


/*-------------------------------------------------------------------------
 * operator: a*y
 *-------------------------------------------------------------------------*/
vectR4 operator*(const double a, const vectR4 y){
  vectR4 p;
  int i;
  for(i=0;i<4;i++)p.put(i,a*y.get(i));
  return p;
  }

/*-------------------------------------------------------------------------
 * operator: dot product of p and q
 *-------------------------------------------------------------------------*/
double operator^(vectR4 p,vectR4 q){
  double sum=0;
  int i;
  for(i=0;i<4;i++)sum += p.get(i)*q.get(i);
  return sum;
  }


/*=====================================
 * seqR4
 *=====================================*/
/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to 0
 *-------------------------------------------------------------------------*/
seqR4::seqR4(long M){
  long n;
  N=M;
  x = (vectR4 *)malloc(N*sizeof(vectR4));
  for(n=0; n<N; n++)x[n].clear();
  }

/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to <u>
 *-------------------------------------------------------------------------*/
seqR4::seqR4(long M,double u){
  long n;
  N=M;
  x = (vectR4 *)malloc(N*sizeof(vectR4));
  for(n=0; n<N; n++)x[n].put(u);
  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with a value <u>
 *-------------------------------------------------------------------------*/
void seqR4::fill(double u){
  long n;
  for(n=0; n<N; n++)x[n].put(u);
  }

/*-------------------------------------------------------------------------
 * put a single value u=(u1,u2,u3,u4) into the seqR1 x at location n
 *-------------------------------------------------------------------------*/
int seqR4::put(long n, double u1,double u2,double u3,double u4){
  int retval=0;
  if(n<N)x[n].put(u1,u2,u3,u4);
  else{
    fprintf(stderr,"n=%ld larger than seqR1 size N=%ld\n",n,N);
    retval=-1;
    }
  return retval;
  }

int seqR4::put(long n, vectR4 u){
  int retval=0;
  if(n<N)x[n].put(u);
  else{   
    fprintf(stderr,"n=%ld larger than seqR4 size N=%ld\n",n,N);
    retval=-1;
    }
  return retval;
  }

/*-------------------------------------------------------------------------
 * list contents of sequence
 *-------------------------------------------------------------------------*/
void seqR4::list(const long start, const long end, const char* str1, const char *str2, FILE *fptr){
  long n,m;
  vectR4 p;
  if(strlen(str1)>0){
    printf("%s",str1);
    if(fptr!=NULL)fprintf(fptr,"%s",str1);
    }
  for(n=start,m=1; n<=end; n++,m++){
    p=x[n];
    printf("(%5.2lf,%5.2lf,%5.2lf,%5.2lf) ",p.get1(),p.get2(),p.get3(),p.get4());
    if(m%2==0)printf("\n");
    if(fptr!=NULL){
      fprintf(fptr,"(%5.2lf,%5.2lf,%5.2lf,%5.2lf) ",p.get1(),p.get2(),p.get3(),p.get4());
      if(m%2==0)fprintf(fptr,"\n");
      }
    }
  if(strlen(str2)>0){
    printf("%s",str2);
    if(fptr!=NULL)fprintf(fptr,"%s",str2);
    }
  }

/*-------------------------------------------------------------------------
 * list contents of seqR1 using 1 digit per element
 *-------------------------------------------------------------------------*/
void seqR4::list1(const long start, const long end, const char *str1, const char *str2,FILE *fptr){
  long n,m;
  vectR4 p;
  if(strlen(str1)>0){
    printf("%s",str1);
    if(fptr!=NULL)fprintf(fptr,"%s",str1);
    }
  for(n=start,m=1; n<=end; n++,m++){
    p=x[n];
    printf(" %1.0lf%1.0lf%1.0lf%1.0lf",p.get1(),p.get2(),p.get3(),p.get4());
    if(fptr!=NULL)fprintf(fptr," %1.0lf%1.0lf%1.0lf%1.0lf",p.get1(),p.get2(),p.get3(),p.get4());
    if(m%10==0)printf("\n");
    if(fptr!=NULL)if(m%10==0)fprintf(fptr,"\n");
    }
  if(strlen(str2)>0){
    printf("%s",str2);
    if(fptr!=NULL)fprintf(fptr,"%s",str2);
    }
  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * operator: return p+q
 *-------------------------------------------------------------------------*/
vectR4 operator+(vectR4 p, vectR4 q){
  int i;
  vectR4 y;
  for(i=0;i<4;i++)y.put(i,p.get(i)+q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return p-q
 *-------------------------------------------------------------------------*/
vectR4 operator-(vectR4 p, vectR4 q){
  int i;
  vectR4 y;
  for(i=0;i<4;i++)y.put(i,p.get(i)-q.get(i));
  return y;
  }

/*-------------------------------------------------------------------------
 * operator: return -p
 *-------------------------------------------------------------------------*/
vectR4 operator-(vectR4 p){
  vectR4 q;
  int i;
  for(i=0;i<4;i++)q.put(i,-p.get(i));
  return q;
  }

/*-------------------------------------------------------------------------
 * return the angle theta in radians between the two vectors induced by 
 * the points <p> and <q> in the space R^4.
 * on SUCCESS return theta in the closed interval [0:PI]
 * on ERROR   return negative value or exit with value EXIT_FAILURE
 *-------------------------------------------------------------------------*/
double pqtheta(const vectR4 p, const vectR4 q){
  const double rp=p.r(), rq=q.r();
  double y,theta;
  if(rp==0) return -1;
  if(rq==0) return -2;
  y = (p^q)/(rp*rq);
  if(y>+1)  {fprintf(stderr,"\nERROR using pqtheta(vectR4 p, vectR4 q): (p^q)/(rp*rq)=%lf>+1\n",y); exit(EXIT_FAILURE);}
  if(y<-1)  {fprintf(stderr,"\nERROR using pqtheta(vectR4 p, vectR4 q): (p^q)/(rp*rq)=%lf<-1\n",y); exit(EXIT_FAILURE);}
  theta = acos(y);
  return theta;
  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * compute magnitude of R^1 sequence
 *-------------------------------------------------------------------------*/
int mag(seqR4 *xR4, seqR1 *ymag){
  const long Nx=xR4->getN();
  const long Ny=ymag->getN();
  long n;
  int retval=0;
  vectR4 u;
  ymag->clear();
  if(Nx!=Ny){
    fprintf(stderr,"ERROR using y=mag(xR4): lengths of xR4 (%ld) and ymag (%ld) differ.\n",Nx,Ny);
    exit(EXIT_FAILURE);
    }
  for(n=0;n<Nx;n++){
    u=xR4->get(n);
    ymag->put(n,u.mag());
    }
  return retval;
  }

