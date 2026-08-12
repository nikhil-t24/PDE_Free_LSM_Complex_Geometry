#ifndef Geometric_Properties_H
#define Geometric_Properties_H

double DELX[NJ][NI],DELY[NJ][NI];

double CV_corner_coor[2][NJ][NI],var_coor[2][NJ][NI];
double dist_corner[4][NJ][NI],dist_GP[4][NJ][NI];

double delS_xe[NJ][NI],delS_ye[NJ][NI],delS_yn[NJ][NI],delS_xn[NJ][NI],delS_yw[NJ][NI],delS_xw[NJ][NI],delS_xs[NJ][NI],delS_ys[NJ][NI];
double C_theta_sx,C_theta_sy,C_theta_tx,C_theta_ty;
double delS_se[NJ][NI],delS_te[NJ][NI],delS_sn[NJ][NI],delS_tn[NJ][NI],delS_sw[NJ][NI],delS_tw[NJ][NI],delS_ss[NJ][NI],delS_ts[NJ][NI]; 

double surf_area[4][NJ][NI];
double diagonal1[NJ][NI],diagonal2[NJ][NI],VOL[NJ][NI],secondterm[NJ][NI];

void Geometric_Properties();
void Write_Mesh();

#endif
