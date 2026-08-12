/*
 * ================================================================
 *  PDE-free Level Set Method: On Lagrangian Advection and Geometric Reinitialization of the Interface in a Complex Geometry.
 *
 *  This code is developed by Nikhil Kumar Tamboli, PhD Research Scholar at Mechanical Engineering Department, Indian Institute of Technology Bombay.
 *
 *  This code is intended for research purposes.
 *  Please cite the associated publication, if this code is used.
 *
 *  The test problem considered here is "Time-reversed single vortex test"
 *
 * ================================================================
 */


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<time.h>
#include<sys/stat.h>
#include<iomanip>
#include<iostream>
#include<cmath>
#include<random>

#define PI 3.141592654
using namespace std;

int N_iter=0;
double times=0;

int iterate=0;


#include "Main.h"

double CompT=0;	


int main()
{
	 time_t timeS;
	 time_t timeE;
	 time(&timeS);	
	 
// ******** Mesh Generation ************
	
	mkdir("Mesh", 0777);

	L_zeta = 1.0; 		 // Computational X Direction
	L_eta = 1.0;	      	 // Computational Y Direction
	
	del_eta = L_eta/(NJ-2.0);
	del_zeta = L_zeta/(NI-2.0);

	Mesh_Mapping();
	Mesh_Generation(0,NJ-2,0,NI-2);
	Geometric_Properties();
	
// ******* Initialization ***************	

        mkdir("FRAME", 0777);
        mkdir("MassError", 0777);
        
        	
	Define_Properties();
	Initial_Cond();
	Initial_Lagr_Points();
	
	for(j=1;j<(NJ-1);j++)
	 {
	 for(i=1;i<(NI-1);i++)
	   {
		U[j][i]= -1 * sin(2*PI*var_coor[1][j][i]) * sin(PI*var_coor[0][j][i]) * sin(PI*var_coor[0][j][i]) * cos((PI*times)/TMAX);
		V[j][i]= 1 * sin(2*PI*var_coor[0][j][i]) * sin(PI*var_coor[1][j][i]) * sin(PI*var_coor[1][j][i]) * cos((PI*times)/TMAX);
	   }
	 }
	 
	Boundary_Cond_PHI_MAIN();
	Boundary_Cond();
	
	Update_PUV(); 

	Write_File();       
	Calc_Initial_Mass();
	Write_Mass_Error();

MAIN_ITERATION:

	times=times+DELT;
	N_iter=N_iter+1;

	Boundary_Cond();
	Update_PUV();  
	Update_PHI_MAIN();
	Boundary_Cond_PHI_MAIN();
	
	Advect_PHI(); 
	Boundary_Cond_PHI_MAIN();

	
	Update_PHI_MAIN();
	Boundary_Cond_PHI_MAIN();
	
	if(times<=TMAX)
	{
		Update_PUV();  
		cout<<"Time step is - "<<times<<"  "<<"N_iter is - "<<N_iter<<endl;

		if(N_iter%Save_Interval==0)
		{
			Write_File();
			
			Calc_Final_Mass();
			MassError = ((InitialMass - FinalMass)/InitialMass)*100;
			cout<<"Mass Error is: "<<MassError<<" %"<<endl;
			
			Write_Mass_Error();
		}
		//cout<<"Nikhil "<<endl;
		goto MAIN_ITERATION;
		
	}

	time(&timeE);
	CompT=difftime(timeE,timeS);
	cout<<"Computational Time is "<<CompT<<"s"<<endl;
	cout<<"Simulation Completed"<<endl;	
	
return 0;
}

