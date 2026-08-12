void Update_PUV()
{
	for(j=0;j<NJ;j++)
	{
		for(i=0;i<NI;i++)
		{
			U_OLD[j][i]=U[j][i];
			V_OLD[j][i]=V[j][i];
			P_OLD[j][i]=P[j][i];
		}
	}			
}



void Update_PHI_MAIN()
{
	for(j=0;j<NJ;j++)
	{
		for(i=0;i<NI;i++)
		{
			PHI_MAIN_OLD[j][i]=PHI_MAIN[j][i];
		}
	}
}
