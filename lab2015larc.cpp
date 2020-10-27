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
#include<r3op.h>
#include<r4op.h>
#include<r6op.h>
#include<larc.h>
#include<euclid.h>
#include<print.h>
#include<lab2015larc.h>

/*-------------------------------------------------------------------------
 * generate larc distance data in R^2
 *-------------------------------------------------------------------------*/
int lab_larc_distances_R2(const char *basefilename){
  time_t time1; time(&time1);   //starting time stamp (passed to plotting routine)
  double seconds;
  vectR2 p,q;
  double d,dN;
  int fails=0;
  char comment[1024];          //comment to be passed to plotting function
  char buf[1024];          //general purpose buffer
  long n;
  char filename[1024];
  FILE *lptr; // pointer to log  file

  //----------------------------------------------
  //open log file
  //----------------------------------------------
  printf(         "----------------------------------------------------------------\n");
  sprintf(comment,"Experiment: calculate distances in R^2 using Lagrange arc distance function"); printf("%s\n",comment);
  printf(         "----------------------------------------------------------------\n");
  sprintf(filename,"%s",basefilename);
  lptr=log_open (filename,time1,comment);

  //----------------------------------------------
  //sprintf(buf,"Generate fair die sequence...");printofe(lptr,buf,time1);
  //----------------------------------------------
  printof(lptr,"Theorem 3.9 (1): triangle inequality fails\n");
  p.put(1,0);                   q.put(-0.5,0);                 d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(1,0);                   q.put(-0.5,0.2);               d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(-0.5,0.2);              q.put(-0.5,0);                 d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  printof(lptr,"Theorem 3.9 (2): translation invariance fails\n");
  p.put(1,0.5);                 q.put(0.5,1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(0.5,0);                 q.put(0,0.5);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  printof(lptr,"Theorem 3.9 (5): balls are not convex\n");
  p.put(0,1);                   q.put(-0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  q.put(0,1);                   p.put(-0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(0,1);                   q.put( 0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  q.put(0,1);                   p.put( 0.70,-1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(0,1);                   q.put( 0,   -1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  q.put(0,1);                   p.put( 0,   -1.12);            d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  printof(lptr,"Theorem 3.10: Lagrange arc distance versus Euclidean metric\n");
  p.put(1,0);                   q.put(-0.50,0);                d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  q.put(1,0);                   p.put(-0.50,0);                d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(1,0);                   q.put(-0.50,0.75);             d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  q.put(1,0);                   p.put(-0.50,0.75);             d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  printof(lptr,"Example 3.12: Lagrange arc distance in R^2\n");
  p.put( 0,1);                  q.put( 1, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 0,1);                  q.put(-1, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 0,1);                  q.put( 0,-1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 1,0);                  q.put( 0,-1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 1,0);                  q.put(-1, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put(-1,0);                  q.put( 0,-1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 0,1);                  q.put( 2, 0);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 0,1);                  q.put( 0,-2);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  p.put( 0,1);                  q.put(-2, 1);                  d=larc_metric(p,q);  dN=larc_metric(p,q,1000);  sprintf(buf,"d((%6.3lf,%6.3lf),(%6.3lf,%6.3lf))=%13.10lf ~= %13.10lf  ",p.getx(),p.gety(),q.getx(),q.gety(),d,dN);printof(lptr,buf);if(dN<d*0.999||dN>d*1.001){printof(lptr,"FAIL\n");fails++;}else printof(lptr,"ok\n");
  sprintf(buf,"number of fails = %d\n",fails); printof(lptr,buf);

  //----------------------------------------------
  // close log file
  //----------------------------------------------
  sprintf(buf,"lab_larc_distances_R2 experiment complete"); printofe(lptr,buf,time1);
  plot_close(lptr,time1);
  return 0;
  }

/*-------------------------------------------------------------------------
 * generate larc R^3 distance data
 *-------------------------------------------------------------------------*/
int lab_larc_distances_R3(const char *basefilename){
  time_t time1; time(&time1);   //starting time stamp (passed to plotting routine)
  double seconds;
  vectR3 p,q;
  double d,de,s=1.0/PI;
  char comment[1024];          //comment to be passed to plotting function
  char buf[1024];          //general purpose buffer
  long n;
  char filename[1024];
  FILE *lptr; // pointer to log  file

  //----------------------------------------------
  //open log file
  //----------------------------------------------
  printf(         "----------------------------------------------------------------\n");
  sprintf(comment,"Experiment: calculate distances in R^3 using Lagrange arc distance function"); printf("%s\n",comment);
  printf(         "----------------------------------------------------------------\n");
  sprintf(filename,"%s",basefilename);
  lptr=log_open (filename,time1,comment);

  //----------------------------------------------
  printof(lptr,"Example 3.13: Lagrange arc distance in R^3\n");
  //----------------------------------------------
  p.put( 0, 1, 0);   q.put( 2, 0, 0);     d=larc_metric(p,q); de=ae_metric(s,p,q); sprintf(buf,"d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de); printof(lptr,buf);
  p.put( 0, 1, 0);   q.put( 0,-2, 0);     d=larc_metric(p,q); de=ae_metric(s,p,q); sprintf(buf,"d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de); printof(lptr,buf);
  p.put( 0, 1, 0);   q.put(-2, 1, 0);     d=larc_metric(p,q); de=ae_metric(s,p,q); sprintf(buf,"d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de); printof(lptr,buf);
  p.put( 0, 1, 0);   q.put(-1, 0,-1);     d=larc_metric(p,q); de=ae_metric(s,p,q); sprintf(buf,"d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de); printof(lptr,buf);
  p.put( 1, 1, 1);   q.put(-0.5,0.25,-2); d=larc_metric(p,q); de=ae_metric(s,p,q); sprintf(buf,"d((%6.3lf,%6.3lf,%6.3lf),(%6.3lf,%6.3lf,%6.3lf))=%12.9lf ae=%12.9lf\n",p.getx(),p.gety(),p.getz(),q.getx(),q.gety(),q.getz(),d,de); printof(lptr,buf);

  //----------------------------------------------
  // close log file
  //----------------------------------------------
  sprintf(buf,"lab_larc_distances_R3 experiment complete"); printofe(lptr,buf,time1);
  plot_close(lptr,time1);
  return 0;
  }


/*-------------------------------------------------------------------------
 * compute Lebesgue arc metric ball in R^2 with center <p> and radius <r> 
 * using Lebesgue arc metric 
 *-------------------------------------------------------------------------*/
int lab_larc_ball_R2(const double px, const double py, const double r, const double rmin, const double rmax, const double maxerror, const long Nsearch, const long Nplot, const char *basefilename){
  time_t time1,time2; time(&time1);   //starting time stamp (passed to plotting routine)
  struct tm *gmt;
  double seconds;
  double a,b,t,theta,err;
  double x,y,d;
  vectR2 p(px,py);
  vectR2 q;
  char comment[1024];          //comment to be passed to plotting function
  char buf[1024];          //general purpose buffer
  long n;
  char filename[1024];
  FILE *lptr; // pointer to log  file
  FILE *fptr; // pointer to data  file
  gmt = gmtime(&time1);

  //----------------------------------------------
  //open log file
  //----------------------------------------------
  printf(         "----------------------------------------------------------------\n");
  sprintf(comment,"Experiment: plot ball centered at (%lf,%lf) in R^2 using Lagrange arc distance function",p.getx(),p.gety()); printf("%s\n",comment);
  printf(         "----------------------------------------------------------------\n");
  sprintf(filename,"%s",basefilename);
  lptr=log_open (filename,time1,comment);

  //----------------------------------------------
  //open data file
  //----------------------------------------------
  sprintf(filename,"%s.dat",basefilename);
  sprintf(comment,"open \"%s\" to plot ball centered at (%lf,%lf) in R^2 using Lagrange arc distance function...",filename,p.getx(),p.gety()); 
  printof(lptr,comment);
  fptr=fopen(filename,"w");
  if(fptr==NULL){
    fprintf(stderr,"ERROR attempting to open experiment log file %s\n",filename);
    exit(EXIT_FAILURE);
    }
  printof(lptr,"success.\n");

  fprintf(fptr,"%%========================================================================\n");
  fprintf(fptr,"%% Daniel J. Greenhoe \n");
  fprintf(fptr,"%% data file for plotting Lebesgue Arc metric ball\n");
  fprintf(fptr,"%% The command \\fileplot{<filename>} may be used in a LaTeX environment\n");
  fprintf(fptr,"%% for plotting data.\n");
  fprintf(fptr,"%% \\fileplot is available in the LaTeX PSTricks package.\n");
  fprintf(fptr,"%% Reference: http://www.ctan.org/pkg/pstricks-base\n");
  fprintf(fptr,"%% GMT %s",asctime(gmt));
  fprintf(fptr,"%%========================================================================\n");
  fprintf(fptr,"[\n");

  printf("\ntheta = %4.2lf PI",0);
  for(theta=0;theta<(2*PI);theta+=(2*PI/Nplot)){
    //q.put(x,y);
    if(larc_findq(p, theta, r, rmin, rmax, maxerror, Nsearch, &q))
      fprintf(fptr,"(%9.6lf,%9.6lf) %%=(x,y); p=(%9.6lf,%9.6lf) d(p,q)=%9.6lf\n",q.getx(),q.gety(),p.getx(),p.gety(),d);
    printf("\b\b\b\b\b\b\b%4.2lf PI",theta/PI);
    }

  printf("\ndone.\n");
  fprintf(fptr,"]\n");
  time(&time2);
  gmt = gmtime(&time2);
  seconds = difftime(time2,time1);
  fprintf(fptr,"%%========================================================================\n");
  fprintf(fptr,"%% end data \n");
  fprintf(fptr,"%% GMT %s",asctime(gmt));
  fprintf(fptr,"%% (%.0lf seconds ellapsed)\n",seconds);
  fprintf(fptr,"%%========================================================================\n");

  //----------------------------------------------
  // close log file
  //----------------------------------------------
  fclose(fptr);
  sprintf(buf,"lab_larc_ball_R2 experiment complete"); printofe(lptr,buf,time1);
  plot_close(lptr,time1);
  return 0;
}

/*-------------------------------------------------------------------------
 * compute Lebesgue arc metric ball in R^3 with center <p> and radius <r> 
 * using Lebesgue arc metric 
 *-------------------------------------------------------------------------*/
int lab_larc_ball_R3(const double px, const double py, const double pz, const double r, const char *basefilename){
  time_t time1,time2; time(&time1);   //starting time stamp (passed to plotting routine)
  struct tm *gmt;
  double seconds;
  double a,b,t,theta,phi,err;
  double x,y,d;
  vectR3 p(px,py,pz);
  vectR3 q;
  char comment[1024];          //comment to be passed to plotting function
  char buf[1024];          //general purpose buffer
  long n;
  int row,col;
  const long N=1000;
  char filename[1024];
  FILE *lptr; // pointer to log  file
  FILE *fptr; // pointer to data  file
  gmt = gmtime(&time1);

  //----------------------------------------------
  //open log file
  //----------------------------------------------
  printf(         "----------------------------------------------------------------\n");
  sprintf(comment,"Experiment: plot ball centered at (%lf,%lf,%lf) in R^3 using Lagrange arc distance function",p.getx(),p.gety(),p.getz()); 
  printf("%s\n",comment);
  printf(         "----------------------------------------------------------------\n");
  sprintf(filename,"%s",basefilename);
  lptr=log_open (filename,time1,comment);

  //----------------------------------------------
  //open data file
  //----------------------------------------------
  sprintf(filename,"%s.dat",basefilename);
  sprintf(comment,"open \"%s\" to plot ball centered at (%lf,%lf,%lf) in R^3 using Lagrange arc distance function...",filename,p.getx(),p.gety(),p.getz()); 
  printof(lptr,comment);
  fptr=fopen(filename,"w");
  if(fptr==NULL){
    fprintf(stderr,"ERROR attempting to open experiment log file %s\n",filename);
    exit(EXIT_FAILURE);
    }
  printof(lptr,"success.\n");

  fprintf(fptr,"%%========================================================================\n");
  fprintf(fptr,"%% Daniel J. Greenhoe \n");
  fprintf(fptr,"%% data file for plotting Lebesgue arc distance ball in R^3\n");
  fprintf(fptr,"%%  with radius %lf and centered at p=(%lf,%lf,%lf).\n",r,px,py,pz);
  fprintf(fptr,"%% The tikzpicture environment may be used in LaTeX\n");
  fprintf(fptr,"%% for plotting data.\n");
  fprintf(fptr,"%% tikzpicture is available in the LaTeX pgfplots package.\n");
  fprintf(fptr,"%% Reference:\n");
  fprintf(fptr,"%% ftp://ftp.ccu.edu.tw/pub/tex/graphics/pgf/contrib/pgfplots/doc/pgfplots.pdf\n");
  fprintf(fptr,"%% GMT %s",asctime(gmt));
  fprintf(fptr,"%%========================================================================\n");
  //fprintf(fptr,"[\n");

//  for(phi=PI/2; phi>=-PI/2; phi-=PI/18){
  for(phi=-PI/2+PI/64,row=1; phi<=(PI/2-PI/64); phi+=PI/32,row++){
    for(theta=0,col=1; theta<=2*PI; theta+=2*PI/32,col++){
      q=larc_findq(p,theta,phi,r, 0.1, 10, 0.001, 10000);
      fprintf(fptr,"%9.6lf %9.6lf %9.6lf %%=q; row=%3d col=%3d phi=%.3lf PI theta=%.3lf PI\n",q.getx(),q.gety(),q.getz(),row,col,phi/PI,theta/PI);
      }
    q=larc_findq(p,0,phi,r, 0.1, 10, 0.001, 10000);
    fprintf(fptr,"%9.6lf %9.6lf %9.6lf %%=q; row=%3d col=%3d phi=%.3lf PI theta=%.3lf PI\n",q.getx(),q.gety(),q.getz(),row,col,phi/PI,theta/PI);
    fprintf(fptr,"\n");
    printf(":");
    }
  phi=PI/2-PI/64;
  for(theta=0,col=1; theta<=2*PI; theta+=2*PI/32,col++){
    q=larc_findq(p,theta,phi,r, 0.1, 10, 0.001, 10000);
      fprintf(fptr,"%9.6lf %9.6lf %9.6lf %%=q; row=%3d col=%3d phi=%.3lf PI theta=%.3lf PI\n",q.getx(),q.gety(),q.getz(),row,col,phi/PI,theta/PI);
    }
  row++;
  q=larc_findq(p,0,phi,r, 0.1, 10, 0.001, 10000);
  fprintf(fptr,"%9.6lf %9.6lf %9.6lf %%=q; row=%3d col=%3d phi=%.3lf PI theta=%.3lf PI\n",q.getx(),q.gety(),q.getz(), row,col,phi/PI,theta/PI);
  fprintf(fptr,"\n");
  printf(":");
  time(&time2);
  gmt = gmtime(&time2);
  seconds = difftime(time2,time1);
  fprintf(fptr,"%%========================================================================\n");
  fprintf(fptr,"%% end data \n");
  fprintf(fptr,"%% GMT %s",asctime(gmt));
  fprintf(fptr,"%% (%.0lf seconds ellapsed)\n",seconds);
  fprintf(fptr,"%%========================================================================\n");
  return 0;
}

