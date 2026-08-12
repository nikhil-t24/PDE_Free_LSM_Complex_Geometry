#ifndef Advection_PHI_H
#define Advection_PHI_H

double mapX,mapY;
double fx,fy,dfx_dmapX,dfx_dmapY,dfy_dmapX,dfy_dmapY,det;
double mapX_new,mapY_new; 

double U_ne[NJ][NI],U_se[NJ][NI],U_nw[NJ][NI],U_sw[NJ][NI];
double V_ne[NJ][NI],V_se[NJ][NI],V_nw[NJ][NI],V_sw[NJ][NI];
double X_ne[NJ][NI],X_se[NJ][NI],X_nw[NJ][NI],X_sw[NJ][NI];
double Y_ne[NJ][NI],Y_se[NJ][NI],Y_nw[NJ][NI],Y_sw[NJ][NI];

double Y_min[NJ][NI],Y_max[NJ][NI],X_min[NJ][NI],X_max[NJ][NI];
double Y_min_temp1,Y_min_temp2,Y_max_temp1,Y_max_temp2; 
double X_min_temp1,X_min_temp2,X_max_temp1,X_max_temp2; 

double T1l1,T1l2,T1l3,T2l1,T2l2,T2l3;
double T1l_min,T1l_max,T2l_min,T2l_max;

double T1l_min_temp1,T1l_max_temp1,T2l_min_temp1,T2l_max_temp1;

double PHI_advective[NJ][NI];


double U_ordered_lagr[2][100000],V_ordered_lagr[2][100000];

void Calc_Corner_UV();
void Advect_PHI();



#endif
