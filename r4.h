/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/
/*-------------------------------------------------------------------------
 * ordered pair (x,y)
 *-------------------------------------------------------------------------*/
class oquad {
  private:
    double x[4];
  public:
    oquad(void);
    oquad(double u0, double u1, double u2, double u3);
    oquad(double u);
    oquad   get(void);
    void   list(const char *str1, const char *str2);
    void   list(void){list("","");}
    void   list(const char *str){list(str,"\n");}
    void   listn(void){list("","\n");}
    double get(int n){return x[n];}
    double get1(void){return x[0];};                      //get component x1
    double get2(void){return x[1];};                      //get component x2
    double get3(void){return x[2];};                      //get component x3
    double get4(void){return x[3];};                      //get component x4
    void put(double u0, double u1, double u2, double u3){x[0]=u0;x[1]=u1;x[2]=u2;x[3]=u3;}
    void put(int n,double u){x[n]=u;}
    void put(double u);
    void put(oquad u);
    double max(void);
    double min(void);
    void clear(void){put(0);}
  };

/*-------------------------------------------------------------------------
 *        | x1 |
 *        | x2 |
 * vector | x3 | over R^4
 *        | x4 |
 * vectors on R^4 are 4-tuples
 * (and hence inherit all the properties of class oquad)
 * but also have additional linear space (vector space) properties
 *-------------------------------------------------------------------------*/
class vectR4: public oquad {
  public:
    vectR4(double u1,double u2,double u3,double u4) : oquad(u1,u2,u3,u4){};
    vectR4(double u) : oquad(u){};
    vectR4(void) : oquad(){}; 
    vectR4 get(void);
    double get(int i){return oquad::get(i);}
    double mag(void);
    double norm(void){return mag();}
    double r(void)   {return mag();}
    void   operator+=(vectR4 q); 
    void   operator-=(vectR4 q); 
    void   operator*=(double a);
    vectR4 operator* (double a){vectR4 u(a*get1(),a*get2(),a*get3(),a*get4()); return u;}
  };

class seqR4 {
  private:
    long N;
    vectR4 *x;
  public:
    seqR4(long M);               //constructor
    seqR4(long M, double u);     //constructor
    void fill(double u);              //fill seqR1 with the value <u>
    void clear(void){fill(0);}        //fill seqR1 with the value 0
    int  put(long n, vectR4 xyz);       //put a value <u> at location n in seq.
    int  put(long n, double u1,double u2,double u3,double u4);
    vectR4 get (long n){return x[n].get();}   //get a value from x at location n
    double get1(long n){return x[n].get1();}  //get a value from x1 at location n
    double get2(long n){return x[n].get2();}  //get a value from x2 at location n
    double get3(long n){return x[n].get3();}  //get a value from x3 at location n
    double get4(long n){return x[n].get4();}  //get a value from x4 at location n
    long   getN(void){return N;}      //get N
    void   list(const long start, const long end, const char* str1, const char *str2, FILE *fptr);
    void   list(const char *str1, const char *str2, FILE *fptr){list(0,N-1,str1,str2,NULL);} //list contents of sequence
    void   list(const long start, const long end){list(start,end,"","",NULL);} //list contents of sequence
    void   list(void){list(0,N-1,"","",NULL);}    //list contents of sequence
    void   list(const long start){list(start,N-1,"","",NULL);} //list contents of sequence
    void   list1(const long start, const long end, const char *str1, const char *str2,FILE *lptr);
    void   list1(const long start, const long end, const char *str1, const char *str2){list1(start,end,str1,str2,NULL);}
    void   list1(const long start, const long end){list1(start,end,"","",NULL);}//
    void   list1(void){list1(0,N-1);}  //list contents of seq. using 1 space each
    void   test(void);
  };

/*=====================================
 * operator overloading
 *=====================================*/
vectR4 operator-(vectR4 p);            // -p
vectR4 operator+(vectR4 p, vectR4 q);  // p+q
vectR4 operator-(vectR4 p, vectR4 q);  // p-q
vectR4 operator*(const double a, const vectR4 y);
double operator^(vectR4 p,vectR4 q);   // "dot product" of p and q
seqR4  operator*(seqR4 xx,seqR1 y);

/*=====================================
 * functions
 *=====================================*/
extern double pqtheta(const vectR4 p, const vectR4 q); //return radians between vectors induced by p and q in R^4




