void Boundary_Cond()
{

//Internal Field
	for(j=1;j<(NJ-1);j++)
	 {
	 for(i=1;i<(NI-1);i++)
	   {
		U[j][i]= -1 * sin(2*PI*var_coor[1][j][i]) * sin(PI*var_coor[0][j][i]) * sin(PI*var_coor[0][j][i]) * cos((PI*times)/TMAX);
		V[j][i]= 1 * sin(2*PI*var_coor[0][j][i]) * sin(PI*var_coor[1][j][i]) * sin(PI*var_coor[1][j][i]) * cos((PI*times)/TMAX);
	   }
	 }
	 
//West Boundary
	for(j=1;j<(NJ-1);j++)
	{
		U[j][0]=U[j][1]; //U[j][NI-2];
		V[j][0]=V[j][1]; //V[j][NI-2];
		P[j][0]=P[j][NI-2];
	}

//South boundary
	for(i=1;i<(NI-1);i++)
	{
		U[0][i]=U[1][i]; //U[NJ-2][i];
		V[0][i]=V[1][i]; //V[NJ-2][i];
		P[0][i]=P[NJ-2][i];
	}

//East boundary
	for(j=1;j<(NJ-1);j++)
	{
		U[j][NI-1]=U[j][NI-2]; //U[j][1];//
		V[j][NI-1]=V[j][NI-2]; //V[j][1];//
		P[j][NI-1]=P[j][1];
	}

//North boundary
	for(i=1;i<(NI-1);i++)
	{
		U[NJ-1][i]=U[NJ-2][i]; //U[1][i];//
		V[NJ-1][i]=V[NJ-2][i]; //V[1][i];//
		P[NJ-1][i]=P[1][i];
	}

//South-West corner
	U[0][0]=0.5*(U[0][1]+U[1][0]);
	V[0][0]=0.5*(V[0][1]+V[1][0]);
	P[0][0]=0.5*(P[0][1]+P[1][0]);
	
//South-East corner
	U[0][NI-1]=0.5*(U[0][NI-2]+U[1][NI-1]);
	V[0][NI-1]=0.5*(V[0][NI-2]+V[1][NI-1]);
	P[0][NI-1]=0.5*(P[0][NI-2]+P[1][NI-1]);

//North-East corner
	U[NJ-1][NI-1]=0.5*(U[NJ-2][NI-1]+U[NJ-1][NI-2]);
	V[NJ-1][NI-1]=0.5*(V[NJ-2][NI-1]+V[NJ-1][NI-2]);
	P[NJ-1][NI-1]=0.5*(P[NJ-2][NI-1]+P[NJ-1][NI-2]);

//North-West corner
	U[NJ-1][0]=0.5*(U[NJ-2][0]+U[NJ-1][1]);
	V[NJ-1][0]=0.5*(V[NJ-2][0]+V[NJ-1][1]);
	P[NJ-1][0]=0.5*(P[NJ-2][0]+P[NJ-1][1]);

}


void Boundary_Cond_PHI_MAIN()
{

//West Boundary
	for(j=1;j<(NJ-1);j++)
	{
		PHI_MAIN[j][0]=PHI_MAIN[j][1];
	}

//South boundary
	for(i=1;i<(NI-1);i++)
	{
		PHI_MAIN[0][i]=PHI_MAIN[1][i];
	}

//East boundary
	for(j=1;j<(NJ-1);j++)
	{
		PHI_MAIN[j][NI-1]=PHI_MAIN[j][NI-2];
	}

//North boundary
	for(i=1;i<(NI-1);i++)
	{
		PHI_MAIN[NJ-1][i]=PHI_MAIN[NJ-2][i];
	}

//South-West corner
	PHI_MAIN[0][0]=0.5*(PHI_MAIN[0][1]+PHI_MAIN[1][0]);
	
//South-East corner
	PHI_MAIN[0][NI-1]=0.5*(PHI_MAIN[0][NI-2]+PHI_MAIN[1][NI-1]);

//North-East corner
	PHI_MAIN[NJ-1][NI-1]=0.5*(PHI_MAIN[NJ-2][NI-1]+PHI_MAIN[NJ-1][NI-2]);

//North-West corner
	PHI_MAIN[NJ-1][0]=0.5*(PHI_MAIN[NJ-2][0]+PHI_MAIN[NJ-1][1]);


}
