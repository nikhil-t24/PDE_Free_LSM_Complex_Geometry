#ifndef Auxillary_H
#define Auxillary_H

double PHI_MAIN_face[4][NJ][NI];
double HoriX[NJ][NI],VertiY[NJ][NI],DELXX[NJ][NI];
double ETA,maxElement;

double density[NJ][NI],viscosity[NJ][NI];

double DDF[NJ][NI],HSF[NJ][NI];

void Calc_ETA();


#endif







