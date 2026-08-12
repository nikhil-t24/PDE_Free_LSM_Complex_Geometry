#ifndef Mesh_Generation_H
#define Mesh_Generation_H

double Height,Length, Dip;

double LX,LY;
int  i,j,k;
double del_eta,del_zeta,L_eta,L_zeta,H;
double maxerror;	
double x[NJ][NI],y[NJ][NI],x_old[NJ][NI],y_old[NJ][NI],eta[NJ][NI],zeta[NJ][NI];
double dt_e[NJ][NI],dt_w[NJ][NI],dt_n[NJ][NI],dt_s[NJ][NI],ds_e[NJ][NI],ds_w[NJ][NI],ds_n[NJ][NI],ds_s[NJ][NI];

double Inner_radius,Outer_radius; 

void Mesh_Generation(int,int,int,int);
void Mesh_Mapping();
void write_Mesh();

#endif
