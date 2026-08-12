#ifndef Reinitialise_PHI_H
#define Reinitialise_PHI_H


//double X_lagr[100000],Y_lagr[100000];
//double X_ordered_lagr[100000],Y_ordered_lagr[100000];



void Write_File();
void Calc_ETA();

//int NTSTEP;
double m;

void Reinitialization();
void Write_Lagr_Points();
void Write_Ordered_Lagr_Points();




void arrangePoints(double [100000], double [100000], double [100000], double [100000], int );
int findNearestPoint(double [100000], double [100000], int [100000], int , int ); 
double calculateDistance(double, double, double, double); 



#endif
