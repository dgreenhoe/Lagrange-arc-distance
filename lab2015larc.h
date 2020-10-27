/*============================================================================
 * Daniel J. Greenhoe
 *============================================================================*/
extern int lab_larc_distances_R2(const char *basefilename);
extern int lab_larc_distances_R3(const char *basefilename);
//extern int lab_larc_ball_R2(const double px, const double py, const double r, const char *basefilename);
extern int lab_larc_ball_R2(const double px, const double py, const double r, const double rmin, const double rmax, const double maxerror, const long Nsearch, const long Nplot, const char *basefilename);
extern int lab_larc_ball_R3(const double px, const double py, const double pz, const double r, const char *basefilename);
