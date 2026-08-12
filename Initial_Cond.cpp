void Initial_Cond()
{
	for(j=0;j<NJ;j++)
	{
		for (i=0;i<NI;i++)
		{
			U[j][i]=0;
			V[j][i]=0;
			P[j][i]=0;
		}
	}

	for(j=0;j<NJ;j++)
	{
		for (i=0;i<NI;i++)
		{
                       Radius1 = 0.15;
                       x1 = 0.5;
                       yy1 = 0.3425;
                       
                       db2p1[j][i]= sqrt(pow((var_coor[0][j][i]-x1),2)+pow((var_coor[1][j][i]-yy1),2));
                       
                       if(db2p1[j][i] < Radius1)
			{
				PHI_CC[0][j][i]=-1*fabs(Radius1 - db2p1[j][i]);
			}else
			{
				PHI_CC[0][j][i]=fabs(Radius1 - db2p1[j][i]);
			}  
			
			
                       Radius2 = 0.075;
                       x2 = 0.5;
                       y2 = 0.5825;
                       
                       db2p2[j][i]= sqrt(pow((var_coor[0][j][i]-x2),2)+pow((var_coor[1][j][i]-y2),2));
                       
                       if(db2p2[j][i] < Radius2)
			{
				PHI_CC[1][j][i]=-1*fabs(Radius2 - db2p2[j][i]);
			}else
			{
				PHI_CC[1][j][i]=fabs(Radius2 - db2p2[j][i]);
			} 
			
			PHI_MAIN[j][i] =  min(PHI_CC[0][j][i],PHI_CC[1][j][i]);	 
   		}
	}
} 
         
                      
                   
