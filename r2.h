/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/
/*-------------------------------------------------------------------------
 * ordered pair (x,y) on R^2
 *-------------------------------------------------------------------------*/
class opair {
  private:
    double x,y;
  public:
    opair(double u, double v){x=u;y=v;}      //constructor using 2 long float arguments
    opair(double u){x=u;y=u;}                //constructor using 1 long float argument
    opair(void){x=0; y=0;}                   //constructor using no arguments (set to 0,0)
    void clear(void){x=0; y=0;} //set (x,y)=(u,v)
    void   put(double u,double v){x=u; y=v;} //set (x,y)=(u,v)
    opair get(void){opair p(getx(),gety()); return p;}
    double getx(void){return x;}            //get component x
    double gety(void){return y;}            //get component y
    void  list(const char* str1, const char *str2, FILE *ptr);
    void  list(const char* str1, const char *str2){list(str1,str2,NULL);}
    void  list(FILE *fptr){list("","",fptr);} //list contents of sequence
    void  list(void){list("","",NULL);}    //list contents of sequence
  };

/*-------------------------------------------------------------------------
 * vector | x | over R^2
 *        | y |
 * vectors on R^2 are ordered pairs 
 * (and hence inherit all the properties of class opair)
 * but also have additional linear space (vector space) properties
 *-------------------------------------------------------------------------*/
class vectR2: public opair {
  public:
    vectR2(double u, double v) : opair(u,v){};      //constructor using 2 long float arguments
    vectR2(double u) : opair(u){};                //constructor using 1 long float argument
    vectR2(void) : opair(){};                   //constructor using no arguments (set to 0,0)
    double mag(void){return sqrt(getx()*getx()+gety()*gety());}
    double norm(void){return mag();}
    double theta(void);                      //polar rotation coordinate of opair in R^2
    void polartoxy(double r, double theta){put(r*cos(theta),r*sin(theta));}
    void   add(double u, double v){put(getx()+u, gety()+v);} //p=p+q
    void   operator+=(vectR2 q){put(getx()+q.getx(), gety()+q.gety());} //p=p+q
    void   operator-=(vectR2 q){put(getx()-q.getx(), gety()-q.gety());} //p=p-q
    void   operator&=(double phi);     //rotate p by <phi> radians in R^2 plane
    void   operator*=(double a){put(a*getx(), a*gety());}
    vectR2 operator* (double a){vectR2 u(a*getx(), a*gety()); return u;}
  };

vectR2  operator-(vectR2 p);               // -p
vectR2  operator+(vectR2 p, vectR2 q);  // p+q
vectR2  operator-(vectR2 p, vectR2 q);  // p-q
vectR2  operator&(vectR2 p,double phi);    // <p> rotated counter-clockwise by <phi>
double  operator^(vectR2 p,vectR2 q){return p.getx()*q.getx() + p.gety()*q.gety();}   // "dot product" of p and q

/*-------------------------------------------------------------------------
 * class of sequences over R^2
 *-------------------------------------------------------------------------*/
class seqR2 {
  private:
    long N;
    vectR2 *xy;
  public:
    seqR2(long M);             //constructor
    seqR2(long M, double u);   //constructor
    void   clear(void);               //fill seqR1 with the value 0
    void   fill(double u);            //fill seqR1 with the value <u>
    void   inc(double x0, double y0,double dx, double dy);
    int    put(long n, vectR2 xy);     //put a value <u> at location n in seq.
    int    put(long n, double u, double v);
    vectR2 get(long n);               //get a value from x at location n
    double getx(long n);             //get a value from x at location n
    double gety(long n);             //get a value from x at location n
    long   getN(void){return N;}      //get N
    double norm(long n);             //norm of element x_n
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
    void   list1(void);               //list contents of seq. using 1 space each
    void   list1(long start, long end);//
    void   test(void);
    vectR2 max(int verbose);        
    vectR2 max(void){return max(0);}   //max mode=0=no print        
  };

/*=====================================
 * functions
 *=====================================*/
extern double pqtheta(const vectR2 p, const vectR2 q); //return radians between vectors induced by p and q in R^2
double chordlength(vectR2 p, vectR2 q){
  vectR2  pqd=p-q; // differnce of p and q
  return pqd.norm(); // "length" of difference
  }