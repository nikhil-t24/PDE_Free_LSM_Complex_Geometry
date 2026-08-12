void Reinitialization()
{

	       increasePoints();
	       	       
	// ********************************************************************** 
	        double EPS = 1e-12;
	        
		int N_CLS[NJ][NI];
		int N_CLS_x[NJ][NI];
		int N_CLS_y[NJ][NI];
		
		
		for(j=0;j<NJ;j++)
		{
		   for(i=0;i<NI;i++)
		    { 			 
			 
			 N_CLS_x[j][i] = 0;
			 N_CLS_y[j][i] = 0;
			 N_CLS[j][i] = 0;
			 
			  for(l=0;l<(Total_points);l++)
			  {	
				if(X_new_lagr[iface][l] > var_coor[0][j][i] && X_new_lagr[iface][l+1] > var_coor[0][j][i])   
				{
				  if( (Y_new_lagr[iface][l] > var_coor[1][j][i] && Y_new_lagr[iface][l+1] < var_coor[1][j][i]) ||
				      (Y_new_lagr[iface][l] < var_coor[1][j][i] && Y_new_lagr[iface][l+1] > var_coor[1][j][i])    )	 
				  {
				  	N_CLS[j][i] =  N_CLS[j][i] + 1;		     
				  }
				}
			  }			  	
				  	
		     }	
		}
		
		
		ETA = 2*LY;        
		for(j=0;j<NJ;j++)
		{
		   for(i=0;i<NI;i++)
		    { 
			minValue = 10*ETA;
			for(l=0;l<(Total_points);l++) 
			{		       
			   dist[l][j][i] = sqrt( pow((X_new_lagr[iface][l] - var_coor[0][j][i]),2) + pow((Y_new_lagr[iface][l] - var_coor[1][j][i]),2) );
					
			   if(minValue > dist[l][j][i] )   // Smallest element
			   {
				minValue = dist[l][j][i];
				         
				if(N_CLS[j][i]%2 == 1)
				{
				       PHI_CC[iface][j][i] = -1*minValue;
				}
				else 
				{
				       PHI_CC[iface][j][i] = 1*minValue;
				}
				         
			    }
	    
			}
		     }	   
		}  	      	   
	
				
}



