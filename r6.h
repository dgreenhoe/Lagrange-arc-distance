/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/
/*-------------------------------------------------------------------------
 * ordered pair (x,y)
 *-------------------------------------------------------------------------*/
class osix {
  private:
    double x[6];
  public:
    osix(void);
    osix(double u0, double u1, double u2, double u3, double u4, double u5);
    osix(double u);
    osix   get(void);
    void   list(const char *str1, const char *str2);
    void   list(void){list("","");}
    void   list(const char *str){list(str,"\n");}
    void   listn(void){list("","\n");}
    double get(int n){return x[n];}
    double get1(void){return x[0];};                      //get component x1
    double get2(void){return x[1];};                      //get component x2
    double get3(void){return x[2];};                      //get component x3
    double get4(void){return x[3];};                      //get component x4
    double get5(void){return x[4];};                      //get component x5
    double get6(void){return x[5];};                      //get component x6
    void put(double u0, double u1, double u2, double u3, double u4, double u5){x[0]=u0;x[1]=u1;x[2]=u2;x[3]=u3;x[4]=u4;x[5]=u5;}
    void put(int n,double u){x[n]=u;}
    void put(double u);
    void put(osix u);
    double max(void);
    double min(void);
    void clear(void){put(0);}
  };

/*-------------------------------------------------------------------------
 *        | x1 |
 *        | x2 |
 * vector | x3 | over R^6
 *        | x4 |
 *        | x5 |
 *        | x6 |
 * vectors on R^6 are 6-tuples
 * (and hence inherit all the properties of class osix)
 * but also have additional linear space (vector space) properties
 *-------------------------------------------------------------------------*/
class vectR6: public osix {
  public:
    vectR6(double u1,double u2,double u3,double u4,double u5,double u6) : osix(u1,u2,u3,u4,u5,u6){};
    vectR6(double u) : osix(u){};
    vectR6(void) : osix(){}; 
    vectR6 get(void);
    double get(int i){return osix::get(i);}
    double mag(void);
    double norm(void){return mag();}
    double r(void)   {return mag();}
    vectR6 mpy       (double a);
   //vectR6 operator* (double a){return mpy(a);}
    void   operator+=(vectR6 q); //{put(get1()+q.get1(),get2()+q.get2(),get3()+q.get3(),get4()+q.get4(),get5()+q.get5(),get6()+q.get6());} //p=p+q
    void   operator-=(vectR6 q); //{put(get1()-q.get1(),get2()-q.get2(),get3()-q.get3(),get4()-q.get4(),get5()-q.get5(),get6()-q.get6());} //p=p-q
    void   operator*=(double a);
  };

class seqR6 {
  private:
    long N;
    vectR6 *x;
  public:
    seqR6(long M);               //constructor
    seqR6(long M, double u);     //constructor
    void fill(double u);              //fill seqR1 with the value <u>
    void clear(void){fill(0);}        //fill seqR1 with the value 0
    int  put(long n, vectR6 xyz);       //put a value <u> at location n in seq.
    int  put(long n, double u1,double u2,double u3,double u4,double u5,double u6);
    vectR6 get (long n){return x[n].get();}   //get a value from x at location n
    double get1(long n){return x[n].get1();}  //get a value from x1 at location n
    double get2(long n){return x[n].get2();}  //get a value from x2 at location n
    double get3(long n){return x[n].get3();}  //get a value from x3 at location n
    double get4(long n){return x[n].get4();}  //get a value from x4 at location n
    double get5(long n){return x[n].get5();}  //get a value from x5 at location n
    double get6(long n){return x[n].get6();}  //get a value from x6 at location n
    long   getN(void){return N;}      //get N
    void list(const long start, const long end, const char *str1, const char *str2, FILE *ptr);
    void list(const long start, const long end, const char *str1, const char *str2, int display, FILE *fptr){
         if(display)   list(start,end,str1,str2,stdout);
                       list(start,end,str1,str2,fptr);
         }
    void list(const char* str1, const char *str2,int display,FILE *fptr){
         if(display)   list(0,N-1,str1,str2,stdout);
                       list(0,N-1,str1,str2,fptr);
         }
    void list(const long start, const long end){list(start,end,"","",stdout);}
    void list(void){list(0,N-1,"","",stdout);}
    void list1(const long start, const long end, const char *str1, const char *str2, FILE *ptr);
    void list1(const long start, const long end, const char *str1, const char *str2, int display, FILE *fptr){
         if(display)   list1(start,end,str1,str2,stdout);
                       list1(start,end,str1,str2,fptr);
         }
    void list1(const char* str1, const char *str2,int display,FILE *fptr){
         if(display)   list1(0,N-1,str1,str2,stdout);
                       list1(0,N-1,str1,str2,fptr);
         }
    void list1(const long start, const long end){list1(start,end,"","",stdout);}
    void list1(void){list1(0,N-1,"","",stdout);}
    void   test(void);
  };

/*=====================================
 * operator overloading
 *=====================================*/
vectR6 operator-(vectR6 p);            // -p
vectR6 operator+(vectR6 p, vectR6 q);  // p+q
vectR6 operator-(vectR6 p, vectR6 q);  // p-q
vectR6 operator*(const double a, const vectR6 y);
vectR6 operator*(const vectR6 y, const double a){return a*y;}
double operator^(vectR6 p,vectR6 q);   // "dot product" of p and q

/*=====================================
 * functions
 *=====================================*/
extern double pqtheta(const vectR6 p, const vectR6 q); //return radians between vectors induced by p and q in R^6




