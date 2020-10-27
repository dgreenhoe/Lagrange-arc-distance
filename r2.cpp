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

/*-------------------------------------------------------------------------
 * list value of opair
 *-------------------------------------------------------------------------*/
void opair::list(const char *str1, const char *str2, FILE *ptr){
  if(strlen(str1)>0)fprintf(ptr,"%s",str1);
  fprintf(ptr,"(%9.6lf,%9.6lf)",getx(),gety());
  if(strlen(str2)>0)fprintf(ptr,"%s",str2);
  }

/*-------------------------------------------------------------------------
 * polar rotation coordinate <theta> of opair point (x,y)
 * return value is in the half open interval [0:2pi)
 * return -1 on error
 *-------------------------------------------------------------------------*/
double vectR2::theta(void){
  double x=getx();
  double y=gety();
  if(x==0){
    if(y==0)     return -1;
    else if(y>0) return +PI/2; 
    else         return 3*PI/2;
    }
  if(y==0){
    if(x>0)      return 0; 
    else         return PI;
    }
  if(x>0&&y>0) return      atan( y/x); // 1st quadrant
  if(x>0&&y<0) return 2*PI-atan(-y/x); // 4th quadrant
  if(x<0&&y>0) return   PI-atan(-y/x); // 2nd quadrant
  if(x<0&&y<0) return   PI+atan( y/x); // 3rd quadrant
  else         return -1;
  }

/*-------------------------------------------------------------------------
 * operator: rotate (x,y) counter-clockwise by <phi> radians
 *-------------------------------------------------------------------------*/
void vectR2::operator&=(double phi){
  vectR2  p(getx(),gety());
  p = p & phi;
  put(p.getx(),p.gety());
  }

/*=====================================
 * seqR2
 *=====================================*/
/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to 0
 *-------------------------------------------------------------------------*/
seqR2::seqR2(long M){
  long n;
  N=M;
  xy = (vectR2 *)malloc(N*sizeof(vectR2));
  for(n=0; n<N; n++)xy[n].clear();
  }

/*-------------------------------------------------------------------------
 * constructor initializing seqR1 to <u>
 *-------------------------------------------------------------------------*/
seqR2::seqR2(long M, double u){
  long n;
  N=M;
  xy = (vectR2 *)malloc(N*sizeof(vectR2));
  for(n=0; n<N; n++){
    xy[n].put(u,u);
    }
  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with a value 0
 *-------------------------------------------------------------------------*/
void seqR2::clear(void){
  long n;
  for(n=0; n<N; n++)xy[n].clear();
  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with a value <u>
 *-------------------------------------------------------------------------*/
void seqR2::fill(double u){
  long n;
  for(n=0; n<N; n++)xy[n].put(u,u);
  }

/*-------------------------------------------------------------------------
 * fill the seqR1 with (x_0, x_1, x_2, ...)
 * where x_n = x_{n-1} + (dx,dy)
 *-------------------------------------------------------------------------*/
void seqR2::inc(double x0, double y0,double dx, double dy){ 
  long n;
  for(n=0;n<N;n++){
    xy[n].put(x0,y0);
    x0+=dx;
    y0+=dy;
    }
  }

/*-------------------------------------------------------------------------
 * put a single value <u> into the seqR1 x at location n
 *-------------------------------------------------------------------------*/
int seqR2::put(long n, double u, double v){
  int retval=0;
  if(n>=N){
    fprintf(stderr,"n=%ld larger than seqR1 size N=%ld\n",n,N);
    retval=-1;
    }
  else xy[n].put(u,v);
  return retval;
  }

int seqR2::put(long n, vectR2 xya){
  int retval=0;
  if(n>=N){
    fprintf(stderr,"n=%ld larger than seqR1 size N=%ld\n",n,N);
    retval=-1;
    }
  else xy[n]=xya;
  return retval;
  }

/*-------------------------------------------------------------------------
 * get a single value from the seqR1 x at location n
 *-------------------------------------------------------------------------*/
vectR2 seqR2::get(long n){
  vectR2 xya(0,0);
  if(n<N)xya=xy[n];
  else   fprintf(stderr,"n=%ld larger than seqR1 size N=%ld\n",n,N);
  return xya;
  }

/*-------------------------------------------------------------------------
 * get a single value from the seqR1 x,y, or z at location n
 *-------------------------------------------------------------------------*/
double seqR2::getx(long n){
  double u=0;
  if(n<N)u=xy[n].getx();
  else   fprintf(stderr,"n=%ld larger than x seqR1 size N=%ld\n",n,N);
  return u;
  }
double seqR2::gety(long n){
  double u=0;
  if(n<N)u=xy[n].gety();
  else   fprintf(stderr,"n=%ld larger than y seqR1 size N=%ld\n",n,N);
  return u;
  }

/*-------------------------------------------------------------------------
 * list contents of sequence
 *-------------------------------------------------------------------------*/
void seqR2::list(const long start, const long end, const char *str1, const char *str2, FILE *ptr){
  long n,m;
  vectR2 x;
  if(strlen(str1)>0)fprintf(ptr,"%s",str1);
  for(n=start,m=1; n<=end; n++,m++){
    x=get(n);
    fprintf(ptr,"  ");
    x.list(ptr);
    if(m%3==0)fprintf(ptr,"\n");
    }
  if(strlen(str2)>0)fprintf(ptr,"%s",str2);
  }

/*-------------------------------------------------------------------------
 * list contents of seqC1 using 1 digit per element
 *-------------------------------------------------------------------------*/
void seqR2::list1(void){
  long n,m;
  for(n=0,m=1; n<N; n++,m++){
    printf("(%2.0lf,%2.0lf)   ",getx(n),gety(n));
    if(m%5==0)printf("\n");
    }
  }
void seqR2::list1(long start, long end){
  long n,m;
  for(n=start,m=1; n<=end; n++,m++){
    printf("(%2.0lf,%2.0lf)   ",getx(n),gety(n));
    if(m%50==0)printf("\n");
    else if(m%10==0)printf(" ");
    }
  }


/*-------------------------------------------------------------------------
 * return the largest pair of values in the seqR1 as measured by norm()
 *-------------------------------------------------------------------------*/
double seqR2::norm(long n){
  vectR2 xya=get(n);
  return xya.norm();
  }

/*-------------------------------------------------------------------------
 * return the largest pair of values in the seqR1 as measured by norm()
 *-------------------------------------------------------------------------*/
vectR2 seqR2::max(int verbose){
  long n;
  double maxnorm=0;
  long   maxn=0;
  vectR2  maxpair;
  for(n=0; n<N; n++)if(norm(n)>maxnorm){maxnorm=norm(n); maxn=n;}
  maxpair=get(maxn);
  if(verbose){
    for(n=0; n<N; n++)
      if(norm(n)>=(maxnorm*0.999))
        printf("max=(%lf,%lf) at n=%ld\n",maxpair.getx(),maxpair.gety(),n);
    }
  return maxpair;
  }

/*=====================================
 * external operations
 *=====================================*/
/*-------------------------------------------------------------------------
 * operator: return p+q
 *-------------------------------------------------------------------------*/
vectR2 operator+(vectR2 p, vectR2 q){
  double px=p.getx();
  double py=p.gety();
  double qx=q.getx();
  double qy=q.gety();
  vectR2 r(px+qx,py+qy);
  return r;
  }

/*-------------------------------------------------------------------------
 * operator: return p-q
 *-------------------------------------------------------------------------*/
vectR2 operator-(vectR2 p, vectR2 q){
  double px=p.getx();
  double py=p.gety();
  double qx=q.getx();
  double qy=q.gety();
  vectR2 r(px-qx,py-qy);
  return r;
  }

/*-------------------------------------------------------------------------
 * operator: return p*q
 *-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
 * operator: return -p
 *-------------------------------------------------------------------------*/
vectR2 operator-(vectR2 p){
  double px=p.getx();
  double py=p.gety();
  vectR2  q(-px,-py);
  return q;
  }

/*-------------------------------------------------------------------------
 * operator: return <p> rotated counter-clockwise by <phi> radians
 *-------------------------------------------------------------------------*/
vectR2 operator&(vectR2 p,double phi){
  double c,s;
  vectR2 q;
  mat2x2 R; // rotation matrix

  if(phi==0){c=1;        s=0;}
  else      {c=cos(phi); s=sin(phi);}
  R.put(c,-s,s,c);
  q = R*p;
  return q;
  }

/*-------------------------------------------------------------------------
 * return the angle theta in radians between the two vectors induced by 
 * the points <p> and <q> in the plane R^2
 * on SUCCESS return theta in the closed interval [0:PI]
 * on ERROR   return negative value or exit with value EXIT_FAILURE
 *-------------------------------------------------------------------------*/
double pqtheta(const vectR2 p, const vectR2 q){
  const double rp=p.mag(), rq=q.mag();
  double y,theta;
  if(rp==0) return -1;
  if(rq==0) return -2;
  y = (p^q)/(rp*rq);
  if(y>+1.0)  {
    if(y-1<0.0000000000001)y=1.0;
    else{ 
      fprintf(stderr,"\nERROR using pqtheta(vectR2 p, vectR2 q): (p^q)/(rp*rq)=%.12lf>+1\n",y); 
      exit(EXIT_FAILURE);
      }
    }
  if(y<-1.0) 
    if(y+1>-0.0000000000001)y=-1.0;
    else{ 
      fprintf(stderr,"\nERROR using pqtheta(vectR2 p, vectR2 q): (p^q)/(rp*rq)=%.12lf<-1\n",y); 
      exit(EXIT_FAILURE);
      }
  theta = acos(y);
  return theta;
  }


