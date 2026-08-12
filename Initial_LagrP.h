#ifndef Initial_LagrP_H
#define Initial_LagrP_H

double X_lagr[2][100000],Y_lagr[2][100000];
double X_ordered_lagr[2][100000],Y_ordered_lagr[2][100000];

double X_unique_lagr[2][100000],Y_unique_lagr[2][100000];

//int MM;
int lmax,l;
int Total_points;

double X_new_lagr[2][100000],Y_new_lagr[2][100000];

//int lmax,l;
int MM;
double dist[100000][NJ][NI];
double minValue;

double xi,yi;

int llmaxx[100000];

int iface;

void Write_Ordered_Lagr_Points();
void Write_Unique_Lagr_Points();
void Write_Unique_Lagr_Points2();

void Write_Lagr_Points();
void Initial_Lagr_Points();


void  Write_New_Lagr_Points();

double X_ordered_lagr_3[100000],Y_ordered_lagr_3[100000];

void increasePoints();


void Cubic_Spline_Coeff_X(double [100000], double [100000], double [100000], double [100000], double [100000], double [100000], int ); 
void Cubic_Spline_Coeff_Y(double [100000], double [100000], double [100000], double [100000], double [100000], double [100000], int ); 
    

double Cubic_Spline_Interpolation_X(double [100000], double [100000], double [100000], double [100000], double [100000], double , int ); 
double Cubic_Spline_Interpolation_Y(double [100000], double [100000], double [100000], double [100000], double [100000], double , int );


int uniquePoints(double [2][100000], double [2][100000], double [2][100000], double [2][100000], int );

void arrangePoints(double [2][100000], double [2][100000], double [2][100000], double [2][100000], int );
int findNearestPoint(double [2][100000], double [2][100000], int [100000], int , int ); 
double calculateDistance(double, double, double, double); 

#endif
