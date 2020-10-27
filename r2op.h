/*============================================================================
 * Daniel J. Greenhoe
 * matrix operations on R^2
 *                 _     _  
 * 2x2 matrix A = |  a b  | 
 *                |_ c d _| 

 *============================================================================*/
/*-------------------------------------------------------------------------
 * 2x2 matrix A 
 *-------------------------------------------------------------------------*/
class mat2x2 {
  private:
    double a,b,c,d;
  public:
    mat2x2(double w, double x, double y, double z){a=w;b=x;c=y;d=z;} //constructor
    mat2x2(void){a=0;b=0;c=0;d=0;}                                   //constructor
  //void set(double w,double x,double y,double z){a=w;b=x;c=y;d=z;}; 
    void put(double w,double x,double y,double z){a=w;b=x;c=y;d=z;}; 
    double getAa(void){return a;};            //get element a of matrix 
    double getAb(void){return b;};            //get element b of matrix 
    double getAc(void){return c;};            //get element c of matrix 
    double getAd(void){return d;};            //get element d of matrix 
    double det(void) {return a*d-b*c;};       //determinate of matrix
    opair  row1(void){opair q(a,b); return q;}//get row1 of matrix
    opair  row2(void){opair q(c,d); return q;}//get row2 of matrix
    vectR2 rov1(void){vectR2 q(a,b); return q;}//get row1 of matrix
    vectR2 rov2(void){vectR2 q(c,d); return q;}//get row2 of matrix
    void  mat2x2::operator+=(mat2x2 B);       //matrix=matrix+B
    void  mat2x2::operator-=(mat2x2 B);       //matrix=matrix-B
  };


/*=====================================
 * operations
 *=====================================*/
extern void mag(seqR2 *x, seqR1 *y);
extern void convolve(seqR2 *x, seqR1 *y, seqR2 *z, int showcount);
extern void convolve(seqR2 *x, seqR1 *y, seqR2 *z){convolve(x,y,z,1);}

/*=====================================
 * symbolic operators
 *=====================================*/
mat2x2 operator-(mat2x2 A);          // -A
mat2x2 operator+(mat2x2 A, mat2x2 B);// A+B
mat2x2 operator-(mat2x2 A, mat2x2 B);// A-B
opair  operator*(mat2x2 A, opair p); // Ap
vectR2 operator*(mat2x2 A, vectR2 p); // Ap

