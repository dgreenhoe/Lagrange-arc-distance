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
#include<r3.h>


/*=====================================
 * seqR3
 *=====================================*/
/*-------------------------------------------------------------------------
 * constructor initializing seqR3 to 0
 *-------------------------------------------------------------------------*/
seqR3::seqR3(long M){
  long n;
  N=M;
  x = (double *)malloc(N*sizeof(double));
  y = (double *)malloc(N*sizeof(double));
  z = (double *)malloc(N*sizeof(double));
  for(n=0; n<N; n++){
    x[n]=0.0;
    y[n]=0.0;
    z[n]=0.0;
    }
  }

/*-------------------------------------------------------------------------
 * constructor initializing seqR3 to <u>
 *-------------------------------------------------------------------------*/
seqR3::seqR3(long M, double u){
  long n;
  N=M;
  x = (double *)malloc(N*sizeof(double));
  y = (double *)malloc(N*sizeof(double));
  z = (double *)malloc(N*sizeof(double));
  for(n=0; n<N; n++){
    x[n]=u;
    y[n]=u;
    z[n]=u;
    }
  }

/*-------------------------------------------------------------------------
 * fill the seqR3 with a value 0
 *-------------------------------------------------------------------------*/
void seqR3::clear(void){
  long n;
  for(n=0; n<N; n++){
    x[n]=0;
    y[n]=0;
    z[n]=0;
    }
  }

/*-------------------------------------------------------------------------
 * fill the seqR3 with a value <u>
 *-------------------------------------------------------------------------*/
void seqR3::fill(double u){
  long n;
  for(n=0; n<N; n++){
    x[n]=u;
    y[n]=u;
    z[n]=u;
    }
  }

/*-------------------------------------------------------------------------
 * put a single value <u> into the seqR3 x at location n
 *-------------------------------------------------------------------------*/
int seqR3::put(long n, double u, double v, double w){
  if(n<N){
    x[n]=u;
    y[n]=v;
    z[n]=w;
    return 0;
    }
  else{   
    fprintf(stderr,"n=%ld larger than seqR3 size N=%ld\n",n,N);
    return -1;
    }
  }

int seqR3::put(long n, vectR3 xyz){
  if(n<N){
    x[n]=xyz.getx();
    y[n]=xyz.gety();
    z[n]=xyz.getz();
    return 0;
    }
  else{   
    fprintf(stderr,"n=%ld larger than seqR3 size N=%ld\n",n,N);
    return -1;
    }
  }

/*-------------------------------------------------------------------------
 * get a single value from the sequence x at location n
 *-------------------------------------------------------------------------*/
vectR3 seqR3::get(long n){
  vectR3 xyz(0,0,0);
  if(n<N)xyz.put(x[n],y[n],z[n]);
  else   fprintf(stderr,"n=%ld larger than seqR3 size N=%ld\n",n,N);
  return xyz;
  }

/*-------------------------------------------------------------------------
 * get a single value from the sequence x,y, or z at location n
 *-------------------------------------------------------------------------*/
double seqR3::getx(long n){
  double u=0;
  if(n<N)u=x[n];
  else   fprintf(stderr,"n=%ld larger than x seqR3 size N=%ld\n",n,N);
  return u;
  }
double seqR3::gety(long n){
  double u=0;
  if(n<N)u=y[n];
  else   fprintf(stderr,"n=%ld larger than y seqR3 size N=%ld\n",n,N);
  return u;
  }
double seqR3::getz(long n){
  double u=0;
  if(n<N)u=z[n];
  else   fprintf(stderr,"n=%ld larger than z seqR3 size N=%ld\n",n,N);
  return u;
  }

/*-------------------------------------------------------------------------
 * list contents of sequence
 *-------------------------------------------------------------------------*/
void seqR3::list(const long start, const long end, const char *str1, const char *str2, FILE *ptr){
  long n,m;
  if(ptr!=NULL){
    if(strlen(str1)>0) fprintf(ptr,"%s",str1);
    for(n=start,m=1; n<=end; n++,m++){
      fprintf(ptr,"(%6.3lf,%6.3lf,%6.3lf) ",x[n],y[n],z[n]);
      if(m%3==0)fprintf(ptr,"\n");
      }
    if(strlen(str2)>0)fprintf(ptr,"%s",str2);
    }
  }

/*-------------------------------------------------------------------------
 * list contents of seqR3 using 1 digit per element
 *-------------------------------------------------------------------------*/
void seqR3::list1(void){
  long n,m;
  for(n=0,m=1; n<N; n++,m++){
    printf("(%2.0lf,%2.0lf,%2.0lf)   ",x[n],y[n],z[n]);
    if(m%5==0)printf("\n");
    }
  }
void seqR3::list1(long start, long end){
  long n,m;
  for(n=start,m=1; n<=end; n++,m++){
    printf("(%2.0lf,%2.0lf,%2.0lf)   ",x[n],y[n],z[n]);
    if(m%50==0)printf("\n");
    else if(m%10==0)printf(" ");
    }
  }


/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * operator: return p+q
 *-------------------------------------------------------------------------*/
vectR3 operator+(vectR3 p, vectR3 q){
  double px=p.getx();
  double py=p.gety();
  double pz=p.getz();
  double qx=q.getx();
  double qy=q.gety();
  double qz=q.getz();
  vectR3  r(px+qx,py+qy,pz+qz);
  return r;
  }

/*-------------------------------------------------------------------------
 * operator: return p-q
 *-------------------------------------------------------------------------*/
vectR3 operator-(vectR3 p, vectR3 q){
  double px=p.getx();
  double py=p.gety();
  double pz=p.getz();
  double qx=q.getx();
  double qy=q.gety();
  double qz=q.getz();
  vectR3  r(px-qx,py-qy,pz-qz);
  return r;
  }

/*-------------------------------------------------------------------------
 * operator: return -p
 *-------------------------------------------------------------------------*/
vectR3 operator-(vectR3 p){
  double px=p.getx();
  double py=p.gety();
  double pz=p.getz();
  vectR3  q(-px,-py,-pz);
  return q;
  }

/*-------------------------------------------------------------------------
 * return the angle theta in radians between the two vectors induced by 
 * the points <p> and <q> in the space R^3.
 * on SUCCESS return theta in the closed interval [0:PI]
 * on ERROR   return negative value or exit with value EXIT_FAILURE
 *-------------------------------------------------------------------------*/
double pqtheta(const vectR3 p, const vectR3 q){
  const double rp=p.mag(), rq=q.mag();
  double y,theta;
  if(rp==0) return -1;
  if(rq==0) return -2;
  y = (p^q)/(rp*rq);
  if(y>+1)  {fprintf(stderr,"\nERROR using pqtheta(vectR3 p, vectR3 q): (p^q)/(rp*rq)=%lf>+1\n",y); exit(EXIT_FAILURE);}
  if(y<-1)  {fprintf(stderr,"\nERROR using pqtheta(vectR3 p, vectR3 q): (p^q)/(rp*rq)=%lf<-1\n",y); exit(EXIT_FAILURE);}
  theta = acos(y);
  return theta;
  }

/*-------------------------------------------------------------------------
 * return the minimum element of the 6 tupple
 *-------------------------------------------------------------------------*/
double otriple::min(void){
  int i;
  double u,min;
  double x[3];
  x[0]=getx(); x[1]=gety(); x[2]=getz();
  min=fabs(x[0]);
  for(i=1;i<3;i++){
    u=fabs(x[i]);
    if(u<min) min=u;
    }
  return min;
  }

/*-------------------------------------------------------------------------
 * return the maximum element of the 6 tupple
 *-------------------------------------------------------------------------*/
double otriple::max(void){
  int i;
  double u,max;
  double x[3];
  x[0]=getx(); x[1]=gety(); x[2]=getz();
  max=fabs(x[0]);
  for(i=1;i<3;i++){
    u=fabs(x[i]);
    if(u>max) max=u;
    }
  return max;
  }


