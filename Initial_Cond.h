#ifndef apply_ini_cond_H
#define apply_ini_cond_H

double U[NJ][NI],V[NJ][NI],P[NJ][NI],U_PHI[NJ][NI],V_PHI[NJ][NI],P_PHI[NJ][NI];
double U_OLD[NJ][NI],V_OLD[NJ][NI],P_OLD[NJ][NI];

double PHI[NJ][NI],PHI_OLD[NJ][NI];
double PHI_MAIN[NJ][NI],PHI_MAIN_OLD[NJ][NI];

double PHI_MAIN1[NJ][NI],PHI_MAIN2[NJ][NI];

double db2p1[NJ][NI],db2p2[NJ][NI];
double Radius,xo,yo;

double PHI_CC[2][NJ][NI];

double Radius1,x1,yy1;
double Radius2,x2,y2;

void Initial_Cond();

#endif

