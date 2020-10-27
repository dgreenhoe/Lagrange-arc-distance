/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/
/*-------------------------------------------------------------------------
 * ordered pair (x,y)
 *-------------------------------------------------------------------------*/
class otriple {
  private:
    double x,y,z;
  public:
    otriple(double u, double v, double w){x=u;y=v;z=w;}    //constructor
    otriple(double u){x=u;y=u;z=u;}                        //constructor
    otriple(void){x=0; y=0; z=0;}                          //constructor
    void put(double u,double v,double w){x=u;y=v;z=w;}//(x,y,z)=(u,v,w)
    void clear(void){x=0; y=0; z=0;}
    double getx(void){return x;};                        //get component x
    double gety(void){return y;};                        //get component y
    double getz(void){return z;};                        //get component z
    double max(void);
    double min(void);
  };

/*-------------------------------------------------------------------------
 *        | x |
 * vector | y | over R^3
 *        | z |
 * vectors on R^3 are ordered pairs 
 * (and hence inherit all the properties of class opair)
 * but also have additional linear space (vector space) properties
 *-------------------------------------------------------------------------*/
class vectR3: public otriple {
  public:
    vectR3(double u, double v, double w) : otriple(u,v,w){};      //constructor using 2 long float arguments
    vectR3(double u) : otriple(u){};                //constructor using 1 long float argument
    vectR3(void) : otriple(){};                   //constructor using no arguments (set to 0,0)
    double mag(void){return sqrt(getx()*getx()+gety()*gety()+getz()*getz());};//norm of ordered pair
    double norm(void){return mag();}
    void polartoxyz(double r, double theta,double phi){put(r*cos(phi)*cos(theta),r*cos(phi)*sin(theta),r*sin(phi));}//set (x,y,z) using polar coordinates (r,theta,phi)
    void  operator+=(vectR3 q){put(getx()+q.getx(), gety()+q.gety(), getz()+q.getz());} //p=p+q
    void  operator-=(vectR3 q){put(getx()-q.getx(), gety()-q.gety(), getz()-q.getz());} //p=p-q
  };


class seqR3 {
  private:
    long N;
    double *x,*y,*z;
  public:
    seqR3(long M);               //constructor
    seqR3(long M, double u);     //constructor
    void clear(void);               //fill seqR1 with the value 0
    void fill(double u);            //fill seqR1 with the value <u>
    int  put(long n, vectR3 xyz);  //put a value <u> at location n in seq.
    int  put(long n, double u, double v, double w);
    void randomize(unsigned seed);   //
    void randomize(unsigned seed, int min, int max); //
    vectR3 get(long n);              //get a value from x at location n
    double getx(long n);             //get a value from x at location n
    double gety(long n);             //get a value from x at location n
    double getz(long n);             //get a value from x at location n
    long getN(void){return N;}      //get N
    void list(const long start, const long end, const char *str1, const char *str2, FILE *ptr);
    void list(const long start, const long end, const char *str1, const char *str2, int display, FILE *fptr){
         if(display)   list(start,end,str1,str2,stdout);
                       list(start,end,str1,str2,fptr);
         }
    void list(const long start, const long end){list(start,end,"","",stdout);}
    void list(void){list(0,N-1,"","",stdout);}
    void  list1(void);              //list contents of seq. using 1 space each
    void  list1(long start, long end);//
    void  test(void);
  };

/*=====================================
 * operator overloading
 *=====================================*/
//vectR3  operator-(vectR3 p);               // -p
//vectR3  operator+(vectR3 p, vectR3 q);  // p+q
//vectR3  operator-(vectR3 p, vectR3 q);  // p-q
vectR3  operator-(vectR3 p);               // -p
vectR3  operator+(vectR3 p, vectR3 q);  // p+q
vectR3  operator-(vectR3 p, vectR3 q);  // p-q
vectR3  operator&(vectR3 p,double phi);    // <p> rotated counter-clockwise by <phi>
vectR3  operator*(vectR3 p,double a){vectR3 pa(p.getx()*a,p.gety()*a,p.getz()*a); return pa;}
double  operator^(vectR3 p,vectR3 q){return p.getx()*q.getx() + p.gety()*q.gety() + p.getz()*q.getz();}   // "dot product" of p and q
//double  operator*(vectR3 p,vectR3 q){return p.getx()*q.getx() + p.gety()*q.gety() + p.getz()*q.getz();}   // "dot product" of p and q

/*=====================================
 * functions
 *=====================================*/
extern double pqtheta(const vectR3 p, const vectR3 q); //return radians between vectors induced by p and q in R^3




