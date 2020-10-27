/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/


//extern int plot_header(FILE *fptr, const time_t time1, const char *comment);
//extern int plot_footer(FILE *fptr, const time_t time1);
//extern int plot_log_header(FILE *fptr, const time_t time1, const char *comment);
extern FILE *log_open(const char *basefilename, const time_t time1, const char *comment);
extern FILE *plot_open(const char *basefilename, const time_t time1, const char *comment);
extern int plot_close(FILE *fptr, const time_t time1);
//extern int plot_dna_seq(const unsigned seed, int N, const char *filename);
//extern int plot_ocs_seq(const symseq *x, const long start, const long finish, const time_t time1, const char *ptype, const char *filename, const char *comment,FILE *lptr);
//extern int plot_ocs_histo(const symseq *x, const long start, const long finish, const time_t time1, const char *plottype, const char *filename, const char *comment,FILE *lptr);
//extern int plot_ocs_histo(const symseq *x,                                      const time_t time1, const char *plottype, const char *filename, const char *comment,FILE *lptr){
//    return plot_ocs_histo(              x,                0,       x->getN()-1,              time1,             plottype,             filename,             comment,      lptr);
//    }
//extern int plot_ocs_auto(const seqR1 *Rxx, const long Nhw, const time_t time1, const char *filename, const char *comment,FILE *lptr);
//extern int plot_dft_seq(const seqR1 *x, const long start, const long finish,const double mindB, const double maxdB, const long M, const long hres1,  const long hres2,  const long hres3, const char *filename, const char *comment);
//extern int plot_dft_seq(const seqR1 *x, const long start, const long finish, const double mindB, const double maxdB, const char *filename, const char *comment){
//    return plot_dft_seq(             x,            start,            finish,              mindB,              maxdB, 0,0,0,0,    filename,             comment);
//    }
//extern int plot_R1_seq(const seqR1 *x, const long start, const long finish, const long M, const double min, const double max, const double widthmm, const double heightmm, const char *filename, const char *comment);
//extern int plot_R1_seq(const seqR1 *x, const long start, const long finish,               const double min, const double max, const double widthmm, const double heightmm, const char *filename, const char *comment){
//    return plot_R1_seq(             x,            start,            finish,            1,              min,              max,              widthmm,              heightmm,             filename,             comment);
//    }
//extern int plot_fdie_seq(const unsigned seed, const long start, const long finish, const char *filename);
//extern int plot_dna(const char *fastafilename, const char *basefilename);

/*-------------------------------------------------------------------------
 * print a string <str> to both standard streams and to file pointed to by <fptr>
 *-------------------------------------------------------------------------*/
void printof(FILE *fptr, const char *str){fprintf(stdout,"%s",str);fprintf(fptr,"%s",str);}
void printef(FILE *fptr, const char *str){fprintf(stderr,"%s",str);fprintf(fptr,"%s",str);}
void printoft(FILE *fptr, const char *str);
void printeft(FILE *fptr, const char *str);
void printoft(FILE *fptr, const char *str, const time_t time1);
void printofe(FILE *fptr, const char *str, const time_t time1);
