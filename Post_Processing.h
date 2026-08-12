#ifndef Post_Processing_H
#define Post_Processing_H


double Area[NJ][NI], HeavySide[NJ][NI];
double InitialMass,FinalMass;
double Hori[NJ][NI], Verti[NJ][NI];

void calc_ETA();
void Calc_Initial_Mass();
void Calc_Final_Mass();

#endif
