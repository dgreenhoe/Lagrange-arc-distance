/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/

/*-------------------------------------------------------------------------
 * complex numbers
 * complex numbers are vectors on R^2
 * (and hence inherit all their properties)
 * but also have a multiplication operation *:C-->C 
 * different from that of vectors on R^2
 *-------------------------------------------------------------------------*/
class complex: public vectR2 {
  public:
    complex(double u, double v) : vectR2(u,v){};  //constructor using 2 long float arguments
    complex(double u) : vectR2(u){};              //constructor using 1 long float argument
    complex(void) : vectR2(){};                   //constructor using no arguments (set to 0,0)
    void put(double ur, double ui){vectR2::put(ur,ui);}
    double real(void){return getx();}
    double imag(void){return gety();}
    complex conj(void){complex u(real(),-imag()); return u;}
    double magsq(void){return real()*real()+imag()*imag();}
    void  list(const char* str1, const char *str2, FILE *ptr);
    void  list(FILE *ptr){list("","",ptr);}
    void  list(const char* str1, const char *str2){list(str1,str2,stdout);}
    void  list(void){list("","",stdout);}    //list contents of sequence
    void  operator=(vectR2 u){put(u.getx(),u.gety());}
  };

inline complex  operator-(complex p){complex q(-p.real(),-p.imag()); return q;}
inline complex  operator~(complex p){complex q(p.real(),-p.imag()); return q;}
inline complex  operator+(complex p, complex q){complex z(p.real()+q.real(),p.imag()+q.imag()); return z;}
inline complex  operator-(complex p, complex q){complex z(p.real()-q.real(),p.imag()-q.imag()); return z;}
inline complex  operator*(double  a, complex p){complex q(a*p.real(),a*p.imag()); return q;}
inline complex  operator*(complex p, complex q){complex r(p.real()*q.real()-p.imag()*q.imag(),p.real()*q.imag()+p.imag()*q.real());return r;}
inline double   operator^(complex p,complex q){return p.getx()*q.getx() + p.gety()*q.gety();}   // "dot product" of p and q

/*-------------------------------------------------------------------------
 * sequence of complex elements
 *-------------------------------------------------------------------------*/
class seqC1: public seqR2 {
//  private:
//    long N;
//    complex *xy;
  public:
    seqC1(long M): seqR2(M){};             //constructor
    seqC1(long M, double u): seqR2(M,u){};   //constructor
    //complex get(long n){complex u; u=seqR2::get(n); return u;}
  };

//class seqC1 {
//  private:
//    long N;
//    complex *xy;
//  public:
//    seqC1(long M);             //constructor
//    seqC1(long M, double u);   //constructor
//    void clear(void);               //fill seqR1 with the value 0
//    void fill(double u);            //fill seqR1 with the value <u>
//    void inc(double x0, double y0,double dx, double dy);
//    int  put(long n, complex xya);   //put a value <u> at location n in seq.
//    int  put(long n, double u, double v);
//    complex get(long n);             //get a value from x at location n
//    double getx(long n);             //get a value from x at location n
//    double gety(long n);             //get a value from x at location n
//    long getN(void){return N;}       //get N
//    double norm(long n);             //norm of element x_n
//    complex max(int verbose);        
//    complex max(void){return max(0);}   //max mode=0=no print        
//    void   list(const long start, const long end, const char* str1, const char *str2, FILE *fptr);
//    void   list(const long start, const long end){list(start,end,"","",NULL);} //list contents of sequence
//    void   list(void){list(0,N-1,"","",NULL);}    //list contents of sequence
//    void   list(const long start){list(start,N-1,"","",NULL);} //list contents of sequence
//    void  list1(void);               //list contents of seq. using 1 space each
//    void  list1(long start, long end);//
//  };

/*=====================================
 * functions
 *=====================================*/
inline complex expi(double x){complex z(cos(x),sin(x)); return z;} // f(x) = e^{ix}
//extern int mag(seqC1 *xC1, seqR1 *ymag);

/*=====================================
 * operator overloading
 *=====================================*/
seqC1  operator*(seqC1 xx,seqR1 y);

/*=====================================
 * functions
 *=====================================*/
extern double pqtheta(complex p, complex q); //return radians between vectors induced by p and q in C
