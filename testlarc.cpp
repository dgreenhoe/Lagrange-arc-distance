/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/
/*=====================================
 * headers
 *=====================================*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<main.h>
#include<r1.h>
#include<r2.h>
#include<r3.h>
#include<r4.h>
#include<r6.h>
#include<c1.h>
#include<c4.h>
#include<c6.h>
#include<r1op.h>
#include<r2op.h>
#include<r6op.h>
#include<larc.h>
#include<euclid.h>
#include<testlarc.h>

/*-------------------------------------------------------------------------
 * test opair operations
 *-------------------------------------------------------------------------*/
int test_opair(void){
  opair ab(3,-4);
  printf("\ntest opair operations:\n");
  printf("----------------------\n");
  printf("ab = (%lf,%lf)\n",ab.getx(),ab.gety());
  ab.clear();
  printf("clear-->(%lf,%lf)\n",ab.getx(),ab.gety());
  return 0;
  }

/*-------------------------------------------------------------------------
 * test vectR2 operations
 *-------------------------------------------------------------------------*/
int test_vectR2(void){
  vectR2 p(3,-4);
  vectR2 q,s;

  printf("\ntest vectR2 operations:\n");
  printf("----------------------\n");
                                   printf("p = (%lf,%lf)\n",p.getx(),p.gety());
                                   printf("norm(%lf,%lf)=%lf\n",p.getx(),p.gety(),p.norm());
  p.put(sqrt(3),1);                printf("theta(%lf,%lf)=%lf degrees\n",p.getx(),p.gety(),p.theta()/PI*180);
  q=-p;                            printf("-(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety());
  p.put(3,-5); q.put(-2,7); s=p+q; printf("(%lf,%lf)+(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety(),s.getx(),s.gety());
  p.put(3,-5); q.put(-2,7); s=p-q; printf("(%lf,%lf)-(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety(),s.getx(),s.gety());
  p.put(2,-3); q.put(-5,7);        printf("(%lf,%lf)*(%lf,%lf)=%lf\n",p.getx(),p.gety(),q.getx(),q.gety(),p^q);
  q=p; q&=(PI/2);                  printf("rotate(%lf,%lf)by 90degrees = (%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety());
  q=p; q&=(PI);                    printf("rotate(%lf,%lf)by 180degrees = (%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety());
  p.clear();                       printf("clear operation--> (%lf,%lf)\n",p.getx(),p.gety(),p.norm());
  return 0;
  }

/*-------------------------------------------------------------------------
 * test complex operations
 *-------------------------------------------------------------------------*/
int test_complex(void){
  complex p(3,-4);
  complex q,s;

  printf("\ntest complex operations:\n");
  printf("-----------------------\n");
                                   printf("p = (%lf,%lf)\n",p.getx(),p.gety());
                                   printf("norm(%lf,%lf)=%lf\n",p.getx(),p.gety(),p.norm());
  p.put(10*sqrt(3),2);                printf("theta(%lf,%lf)=%lf degrees\n",p.getx(),p.gety(),p.theta()/PI*180);
  q=-p;                            printf("-(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety());
  p.put(3,-5); q.put(-2,7); s=p+q; printf("(%lf,%lf)+(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety(),s.getx(),s.gety());
  p.put(3,-5); q.put(-2,7); s=p-q; printf("(%lf,%lf)-(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety(),s.getx(),s.gety());
  p.put(2,-3); q.put(-5,7); s=p*q; printf("(%lf,%lf)*(%lf,%lf)=(%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety(),s.getx(),s.gety());
  q=p; q&=(PI/2);                  printf("rotate(%lf,%lf)by 90degrees = (%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety());
  q=p; q&=(PI);                    printf("rotate(%lf,%lf)by 180degrees = (%lf,%lf)\n",p.getx(),p.gety(),q.getx(),q.gety());
  p.clear();                       printf("clear operation--> (%lf,%lf)\n",p.getx(),p.gety(),p.norm());
  return 0;
  }

/*-------------------------------------------------------------------------
 * test otriple operations
 *-------------------------------------------------------------------------*/
int test_otriple(void){
  otriple abc(3,-4,5);
  printf("\ntest otriple operations:\n");
  printf("---------------------------\n");
  printf("abc = (%lf,%lf,%lf)\n",abc.getx(),abc.gety(),abc.getz());
  abc.clear();
  printf("clear-->(%lf,%lf,%lf)\n",abc.getx(),abc.gety(),abc.getz());
  return 0;
  }

/*-------------------------------------------------------------------------
 * test complex operations
 *-------------------------------------------------------------------------*/
int test_seqR2(void){
  printf("\ntest seqR2 operations:\n");
  printf("-----------------------\n");

  seqR2 x(6);       printf("construct: "); x.list();
  x.fill(2);        printf("\nfill(2): "); x.list();
  x.inc(2,-5,1,-5); printf("\ninc: ");     x.list();
  x.max('p');
  x.clear();        printf("\nclear: ");   x.list();
  return 0;
  }

/*-------------------------------------------------------------------------
 * test osix operations
 *-------------------------------------------------------------------------*/
int test_osix(void){
  osix x(1,-2,3,-5,7,-11);
  osix y,z;
  printf("\ntest osix operations:\n");
  printf("---------------------\n");
  y=x;
  z.put(y);
  //v=z.get();
  printf("x construct:(%lf,%lf,%lf,%lf,%lf,%lf)\n",x.get1(),x.get2(),x.get3(),x.get4(),x.get5(),x.get6());
  printf("y=x:        (%lf,%lf,%lf,%lf,%lf,%lf)\n",y.get1(),y.get2(),y.get3(),y.get4(),y.get5(),y.get6());
  printf("z.put(y):   (%lf,%lf,%lf,%lf,%lf,%lf)\n",z.get1(),z.get2(),z.get3(),z.get4(),z.get5(),z.get6());
  printf("z.put(y):   (%lf,%lf,%lf,%lf,%lf,%lf)\n",z.get(0),z.get(1),z.get(2),z.get(3),z.get(4),z.get(5));
  x.clear();
  //x=(1,2,3,4,5,6);
  printf("clear x:    (%lf,%lf,%lf,%lf,%lf,%lf)\n",x.get1(),x.get2(),x.get3(),x.get4(),x.get5(),x.get6());
  return 0;
  }

/*-------------------------------------------------------------------------
 * test osix operations
 *-------------------------------------------------------------------------*/
int test_vectR6(void){
  vectR6 x(1,-2,3,-5,7,-11);
  vectR6 y,z,v;
  printf("\ntest vectR6 operations:\n");
  printf("-----------------------\n");
             printf("x construct: (%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf)\n",x.get1(),x.get2(),x.get3(),x.get4(),x.get5(),x.get6());
  y=x;       printf("y=x:         (%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf)\n",y.get1(),y.get2(),y.get3(),y.get4(),y.get5(),y.get6());
  z.put(y);  printf("z.put(y):    (%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf)\n",z.get1(),z.get2(),z.get3(),z.get4(),z.get5(),z.get6());
             printf("z.put(y):    (%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf,%9.6lf)\n",z.get(0),z.get(1),z.get(2),z.get(3),z.get(4),z.get(5));
             printf("z.list():    ");z.list();printf("\n");
  x.clear(); printf("clear x:     ");x.list();printf("\n");
  x.put(1,2,3,4,5,6); 
  y.put(1,1./2.,1./3.,1./4.,1./5.,1./6.);
             x.list("x.put(1..6): ","\n");
             y.list("y.put(1/x..):");
  z=x+y;     z.list("z=x+y:       ");
  v=z-y;     v.list("v=z-y:       ");
  v+=y;      v.list("v+=y:        ");
  v-=y;      v.list("v-=y:        ");
  y=2*v;     y.list("y=2*v:       ");
  v*=-3;     v.list("v*=-3:       ");
  printf("x.mag()=%lf  x.r()=%lf   x.norm()=%lf\n",x.mag(),x.r(),x.norm());
  printf("x dot y = %lf\n",x^y);
  return 0;
  }


/*-------------------------------------------------------------------------
 * test Lagrange arc metric in R^2
 *-------------------------------------------------------------------------*/
int test_pqtheta(void){
  vectR2 p,q;
  double tr,td,dc;
  int fails=0;
  printf("\n(p,q) theta tests in R2\n");
  printf("-----------------------\n");
  p.put(0,0);                   q.put(2,0);                    tr=pqtheta(p,q); td=tr*180/PI; dc= -1*180/PI; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td>dc*0.999||td<dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,1);                   q.put(0,0);                    tr=pqtheta(p,q); td=tr*180/PI; dc= -2*180/PI; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td>dc*0.999||td<dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,2);                   q.put(2,0);                    tr=pqtheta(p,q); td=tr*180/PI; dc= 90; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,1);                   q.put(1,0);                    tr=pqtheta(p,q); td=tr*180/PI; dc= 90; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(1,3);                   q.put(-1,-3);                  tr=pqtheta(p,q); td=tr*180/PI; dc=180; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(-2,5);                  q.put(2,-5);                   tr=pqtheta(p,q); td=tr*180/PI; dc=180; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,1);                   q.put( cos(PI/4), sin(PI/4));  tr=pqtheta(p,q); td=tr*180/PI; dc= 45; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,1);                   q.put( cos(PI/4),-sin(PI/4));  tr=pqtheta(p,q); td=tr*180/PI; dc=135; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,1);                   q.put(-cos(PI/4), sin(PI/4));  tr=pqtheta(p,q); td=tr*180/PI; dc= 45; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(0,1);                   q.put(-cos(PI/4),-sin(PI/4));  tr=pqtheta(p,q); td=tr*180/PI; dc=135; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put( 7*cos(PI/4), 7*sin(PI/4)); q.put(0,1);                    tr=pqtheta(p,q); td=tr*180/PI; dc= 45; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put( 7*cos(PI/4),-7*sin(PI/4)); q.put(0,1);                    tr=pqtheta(p,q); td=tr*180/PI; dc=135; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(-7*cos(PI/4), 7*sin(PI/4)); q.put(0,1);                    tr=pqtheta(p,q); td=tr*180/PI; dc= 45; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  p.put(-7*cos(PI/4),-7*sin(PI/4)); q.put(0,1);                    tr=pqtheta(p,q); td=tr*180/PI; dc=135; printf("p=(%6.3lf,%6.3lf) q=(%6.3lf,%6.3lf) theta=%6.2lf radians %6.2lf degrees ",p.getx(),p.gety(),q.getx(),q.gety(),tr,td);if(td<dc*0.999||td>dc*1.001){fails++; printf("FAIL %lf!=%lf\n",td,dc);}else printf("ok\n");
  printf("number of fails = %d\n",fails);
  return fails;
  }

/*-------------------------------------------------------------------------
 * test elliptic normalize
 *-------------------------------------------------------------------------*/
int test_normalize(void){
  vectR2 p,q;
  double phi;
  p.put(0,2); phi=PI/2; q= p & phi;  printf("p=(%lf,%lf) q=(%lf,%lf) phi=%lf\n",p.getx(),p.gety(),q.getx(),q.gety(), phi);
  p.put(0,2); phi=PI/2; q= p & (-phi);  printf("p=(%lf,%lf) q=(%lf,%lf) phi=%lf\n",p.getx(),p.gety(),q.getx(),q.gety(), -phi);
  p.put(2,0); phi=PI/2; q= p & phi;  printf("p=(%lf,%lf) q=(%lf,%lf) phi=%lf\n",p.getx(),p.gety(),q.getx(),q.gety(), phi);
  p.put(2,0); phi=PI/2; q= p & (-phi);  printf("p=(%lf,%lf) q=(%lf,%lf) phi=%lf\n",p.getx(),p.gety(),q.getx(),q.gety(), -phi);
  p.put(2,0); phi=PI/2; p &= phi;  printf("p=(%lf,%lf) phi=%lf\n",p.getx(),p.gety(), phi);
  return 0;
  }

/*-------------------------------------------------------------------------
 * test Lagrange arc metric in R^2
 *-------------------------------------------------------------------------*/
int test_larc_metric_R2(void){
  vectR2 p,q;
  double d,dN;
  int fails=0;
  printf("Lagrange arc metric tests in R2\n");
  printf("--------------------\n");
  p.put(1,0);                   q.put(-1,0);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(1,0);                   p.put(-1,0);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,2);                   q.put(2,0);                    d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put(1,0);                    d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put( cos(PI/4), sin(PI/4));  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put(-cos(PI/4), sin(PI/4));  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put(-cos(PI/4),-sin(PI/4));  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put( cos(PI/4),-sin(PI/4));  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-0.5,-0.5);              d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-2,-2);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(0,2);                    d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( cos(PI/4),-sin(PI/4)); q.put(-2,1);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( cos(PI/4),-sin(PI/4)); q.put(-1.63,1.33);             d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( cos(PI/4), sin(PI/4)); q.put( 1, 1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(2,0);                    d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-1,0);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,1);                   q.put(0,0);                    d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(0,-1);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put(-cos(PI/4), sin(PI/4));  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put( cos(PI/4), sin(PI/4));  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-2,0);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(1,0);                   p.put(-2,0);                   d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-0.5,0);                 d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  printf("Theorem 3.9 (1): triangle inequality fails\n");
  p.put(1,0);                   q.put(-0.5,0);                 d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-0.5,0.2);               d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(-0.5,0.2);              q.put(-0.5,0);                 d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  printf("Theorem 3.9 (2): translation invariance fails\n");
  p.put(1,0.5);                 q.put(0.5,1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0.5,0);                 q.put(0,0.5);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  printf("Theorem 3.9 (5): balls are not convex\n");
  p.put(0,1);                   q.put(-0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(0,1);                   p.put(-0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put( 0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(0,1);                   p.put( 0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(0,1);                   q.put( 0,   -1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(0,1);                   p.put( 0,   -1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  printf("Theorem 3.10: Lagrange arc distance versus Euclidean metric\n");
  p.put(1,0);                   q.put(-0.50,0);                d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(1,0);                   p.put(-0.50,0);                d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(1,0);                   q.put(-0.50,0.75);             d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  q.put(1,0);                   p.put(-0.50,0.75);             d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  printf("Example 3.12: Lagrange arc distance in R^2\n");
  p.put( 0,1);                  q.put( 1, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 0,1);                  q.put(-1, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 0,1);                  q.put( 0,-1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 1,0);                  q.put( 0,-1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 1,0);                  q.put(-1, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put(-1,0);                  q.put( 0,-1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 0,1);                  q.put( 2, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 0,1);                  q.put( 0,-2);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 0,1);                  q.put(-2, 1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  p.put( 0.000001,0);              q.put(PI, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  printf("d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);if(dN<d*0.999||dN>d*1.001){printf("FAIL\n");fails++;}else printf("ok\n");
  printf("number of fails = %d\n",fails);
  return fails;
  }

/*-------------------------------------------------------------------------
 * test Lagrange arc metric in R^3
 *-------------------------------------------------------------------------*/
int test_larc_metric_R3(void){
  vectR3 p,q;
  double d,de,s=1.0/PI;
  printf("Lagrange arc metric tests in R3\n");
  printf("--------------------\n");
  p.put(0,2,0);                   q.put(2,0,0);                    d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put(1,0,0);                    d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put( cos(PI/4), sin(PI/4),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put(-cos(PI/4), sin(PI/4),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put(-cos(PI/4),-sin(PI/4),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put( cos(PI/4),-sin(PI/4),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,0,0);                   q.put(-0.5,-0.5,0);              d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,0,0);                   q.put(-2,-2,0);                  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,0,0);                   q.put(0,2,0);                    d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( cos(PI/4),-sin(PI/4),0); q.put(-2,1,0);                   d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( cos(PI/4),-sin(PI/4),0); q.put(-1.63,1.33,0);             d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( cos(PI/4), sin(PI/4),0); q.put( 1, 1,0);                  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,0,0);                   q.put(2,0,0);                    d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,0,0);                   q.put(-1,0,0);                   d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,1,0);                   q.put(0,0,0);                    d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(1,0,0);                   q.put(0,-1,0);                   d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  printf("\n");
  p.put( 0, 1, 0);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 1, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 0, 1, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 1, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put(-1,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 0,-1,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put(-1, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 1);                q.put(-0.5, 0.25,-2);            d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1,-1,-2);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1,-1,-2);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1,-1,-2);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1,-1,-2);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1,-1,-2);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1,-1,-2);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 0, 0);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 0, 0);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 0, 0);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 0, 0);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 0, 0);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 0, 0);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1,-2);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1,-2);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1,-2);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1,-2);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1,-2);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1,-2);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 0);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 0);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 0);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 0);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 0);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 0);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 2, 2, 0);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 2, 2, 0);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 2, 2, 0);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 2, 2, 0);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 2, 2, 0);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 2, 2, 0);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 2, 1);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 2, 1);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 2, 1);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 2, 1);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 2, 1);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 2, 1);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 3, 1);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 3, 1);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 3, 1);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 3, 1);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 3, 1);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 3, 1);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 2, 0);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1, 2, 1);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1, 2, 1);                q.put( 0, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1, 2, 1);                q.put( 0, 0, 1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1, 2, 1);                q.put( 0, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1, 2, 1);                q.put( 0,-1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1, 2, 1);                q.put(-1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);

  p.put(-1, 0, 0);                q.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1.01, 0, 0);                q.put(0.99, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1.001, 0, 0);                q.put(0.999, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-1.0001, 0, 0);                q.put(0.9999, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);

  q.put(-1, 0, 0);                p.put( 1, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  q.put(-1.01, 0, 0);             p.put(0.99, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  q.put(-1.001, 0, 0);            p.put(0.999, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  q.put(-1.0001, 0, 0);           p.put(0.9999, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);

  p.put(0,1,0);                   q.put( cos(PI/4), sin(PI/4),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put(-cos(PI/4), sin(PI/4),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put( cos(PI/6), sin(PI/6),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(0,1,0);                   q.put(-cos(PI/6), sin(PI/6),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( cos(PI/4), sin(PI/4),0);   q.put( 0.5*cos(PI/8), 0.5*sin(PI/8),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-cos(PI/4), sin(PI/4),0);   q.put(-0.5*cos(3*PI/8), 0.5*sin(3*PI/8),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0.5*cos(PI/4), 0.5*sin(PI/4),0);   q.put( cos(PI/8),   sin(PI/8),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put(-0.5*cos(PI/4), 0.5*sin(PI/4),0);   q.put(-cos(3*PI/8), sin(3*PI/8),0);  d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  printf("Example 3.13: Lagrange arc distance in R^3\n");
  p.put( 0, 1, 0);                q.put( 2, 0, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put( 0,-2, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put(-2, 1, 0);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 0, 1, 0);                q.put(-1, 0,-1);                 d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);
  p.put( 1, 1, 1);                q.put(-0.5,0.25,-2);             d=larc_metric(p,q); de=ae_metric(s,p,q); printf("d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de);

  return 0;
  }

/*-------------------------------------------------------------------------
 * test Lagrange arc metric in R^6
 *-------------------------------------------------------------------------*/
int test_larc_metric_R6(void){
  vectR6 p,q;
  double d;
  printf("Lagrange arc metric tests in R^6\n");
  printf("--------------------------------\n");
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 0, 0, 0, 0, 0, 1); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 1, 0, 0, 0, 0);  q.put( 0, 0, 0, 0, 1, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 1, 0, 0, 0);  q.put( 0, 0, 0, 1, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 0, 1, 0, 0);  q.put( 0, 0, 1, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 0, 0, 1, 0);  q.put( 0, 1, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 0, 0, 0, 1);  q.put( 1, 0, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  putchar('\n');
  p.put( 1, 0, 0, 0, 0, 0);  q.put(-1, 0, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 1, 0, 0, 0, 0);  q.put( 0,-1, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 1, 0, 0, 0);  q.put( 0, 0,-1, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 0, 1, 0, 0);  q.put( 0, 0, 0,-1, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 0, 0, 1, 0);  q.put( 0, 0, 0, 0,-1, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 0, 0, 0, 0, 0, 1);  q.put( 0, 0, 0, 0, 0,-1); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  putchar('\n');
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 0, 0, 0, 0, 0, 1); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 0, 0, 0, 0, 1, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 0, 0, 0, 1, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 0, 0, 1, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 0, 1, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put( 1, 0, 0, 0, 0, 0);  q.put( 1, 0, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  putchar('\n');
  p.put(-1, 2, 1,-1, 2, 1);  q.put( 1, 0, 0, 1, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(-1, 2, 1,-1, 2, 1);  q.put( 0, 1, 0, 0, 1, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(-1, 2, 1,-1, 2, 1);  q.put( 0, 0, 1, 0, 0, 1); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(-1, 2, 1,-1, 2, 1);  q.put( 0, 0,-1, 0, 0,-1); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(-1, 2, 1,-1, 2, 1);  q.put( 0,-1, 0, 0,-1, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(-1, 2, 1,-1, 2, 1);  q.put(-1, 0, 0,-1, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  putchar('\n');
  p.put(0.458,0.022,0.120,0.234,0.167,0.000);  q.put(1, 0, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(0.458,0.022,0.120,0.234,0.167,0.000);  q.put(0, 1, 0, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(0.458,0.022,0.120,0.234,0.167,0.000);  q.put(0, 0, 1, 0, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(0.458,0.022,0.120,0.234,0.167,0.000);  q.put(0, 0, 0, 1, 0, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(0.458,0.022,0.120,0.234,0.167,0.000);  q.put(0, 0, 0, 0, 1, 0); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  p.put(0.458,0.022,0.120,0.234,0.167,0.000);  q.put(0, 0, 0, 0, 0, 1); d=larc_metric(p,q);  printf("d((%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf),(%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf,%3.1lf))=%9.6lf t=%6.2lf\n",p.get1(),p.get2(),p.get3(),p.get4(),p.get5(),p.get6(),q.get1(),q.get2(),q.get3(),q.get4(),q.get5(),q.get6(),d,pqtheta(p,q)*180/PI);
  return 0;
  }

/*-------------------------------------------------------------------------
 * test spinner
 *-------------------------------------------------------------------------*/
int test_conj(void){
  complex z,zc;

  z.put(1.0,1.0);   zc=z.conj();  z.list();  zc.list(); putchar('\n');
  z.put(-3.2,4.7);  zc=z.conj();  z.list();  zc.list(); putchar('\n');
  return 0;
  }


/*-------------------------------------------------------------------------
 * test expi function
 *-------------------------------------------------------------------------*/
int test_expi(void){
  const long N=12;
  long n;
  complex y;
  double theta;
  for(n=0; n<=N; n++){
    theta = 2.0*PI*(double)n/(double)N;
    y = expi(theta);
    printf("n=%2ld, theta=%lf (%3.0lf), expi(theta)=(%+9.6lf,%+9.6lf) mag=%lf\n",n,theta,theta/PI*180,y.real(),y.imag(), y.mag());
    }
  return 0;
  }

