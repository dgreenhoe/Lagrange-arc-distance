/*============================================================================
 * Daniel J. Greenhoe
 * header file for routines for seqR1 operations
 *============================================================================*/
/*=====================================
 * class definition
 *=====================================*/
class seqR1 {
  //friend class seqR3;
  private:
    long N;    //number of elements in sequence
    double *x; // pointer to sequence
  public:
    seqR1(long M);                    //constructor
    seqR1(long M, double u);          //constructor
    seqR1(long M, double *list);      //constructor
    void   clear(void);                  //fill seqR1 with the value 0
    void   fill(double u);               //fill seqR1 with the value <u>
    void   hanning(void);                //fill seqR1 with Hanning filter window
    void   lptohp(void);                 //convert low pass filter to high pass filter
    void   truncate(long n){N=n;}        //truncate sequence to first <n> elements
    int    put(long n, double u);        //put a value <u> at location n in seq.
    int    put(const long start, const long end, const double u);//put a value <u> at locations start to end
    int    add(long n, double u);        //add a value <u> at location n in seq.
    int    add(double u);                //add a value <u> to every element in sequence
    void   shiftL(long n);               //shift seqR1 n elements to the left
    void   shiftR(long n);               //shift seqR1 n elements to the right
    void   randomize(unsigned seed);     //
    void   randomize(unsigned seed, int min, int max); //
    double get(long n);                  //get a value from x at location x
    long   getN(void){return N;}         //get N
    double first(void){return x[0];}     //get the first value of the sequence
    double last(void){return x[N-1];}    //get the last value of the sequence
    double max(const long start,const long end); //maximum value of sequence
    double max(void){return max(0,N-1);}         //maximum value of sequence
    double max(int mode);                //return max absolute value in sequence
    double min(const long start,const long end); //minimum value of sequence
    double min(void){return min(0,N-1);}         //minimum value of sequence
//    long   gte(const double threshold,const long start, const long end, const char *str1, const char *str2, FILE *fptr);
//    long   gte(double threshold){return gte(threshold,0,N-1,"","",NULL);} //
//    long   gte(double threshold, FILE *fptr){return gte(threshold,0,N-1,"","",fptr);} //
//
    long   gt(const double threshold,const long start, const long end, const char *str1, const char *str2, FILE *fptr);     //list pairs >= to u
    long   gt(const double threshold,const long start, const long end, const char *str1, const char *str2, int display, FILE *fptr){
             if(display)return gt(threshold,start,end,str1,str2,stdout);
                        return gt(threshold,start,end,str1,str2,fptr);
             }
    long   gt(const double threshold,const long start, const long end){return gt(threshold,start,end,"","",NULL);}
    long   gt(double threshold){return gt(threshold,0,N-1,"","",NULL);} //
    long   gt(double threshold, FILE *fptr){return gt(threshold,0,N-1,"","",fptr);} //

    long   gte(const double threshold,const long start, const long end, const char *str1, const char *str2, FILE *fptr);     //list pairs >= to u
    long   gte(const double threshold,const long start, const long end, const char *str1, const char *str2, int display, FILE *fptr){
            // if(display)return gte(threshold,start,end,str1,str2,stdout);
                        return gte(threshold,start,end,str1,str2,fptr);
             }
    long   gte(const double threshold,const long start, const long end){return gte(threshold,start,end,"","",NULL);}
    long   gte(double threshold){return gte(threshold,0,N-1,"","",NULL);} //
    long   gte(double threshold, FILE *fptr){return gte(threshold,0,N-1,"","",fptr);} //

    long   argmax(void);                 //return the first argument n yielding the maximum value x_n of the seqR1 x
    long   argmin(void);                 //return the first argument n yielding the minimum value x_n of the seqR1 x
    double norm(double r);               //lp norm of sequence
    double norm(void);                   //Euclidean norm of seqR1 = norm(2)
    double normalize(void);              //normalize for filtering
    double supnorm(void);                //supremum norm = norm(+infty)
    double infnorm(void);                //infinimum norm = norm(-infty)
    void   increment(long n);            //increment element n in sequence
    void   round(void);                  //round each element to nearest element
    void   listL(void);                  //list contents of seqR1 in long format
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
    void   list1(long start, long end);  //list contents of seq. using 1 space each
    void   list1(void){list1(0,N-1);}    //list contents of seq. using 1 space each
    void   listi(long start, long end);  //list contents of seq. using integer format
    void   listi(void){listi(0,N-1);}    //list contents of seq. using integer format
    void   listx(long start, long end);  //list contents of seqR1 for LaTeX
    void   listx(void){listx(0,N-1);}    //list contents of seqR1 for LaTeX
    void   test(void);                   //
    void   operator=(seqR1 y);        //x=y
    void   operator=(const double p);    //each element in x=p
    void   operator+=(seqR1 x);       //x=x+y
    void   operator-=(seqR1 y);       //x=x-y
    void   operator*=(double alpha);     //x=a*x
    void   operator>>=(long n){shiftR(n);} //shift seqR1 n elements to the right
    void   operator<<=(long n){shiftL(n);} //shift seqR1 n elements to the left
  };

