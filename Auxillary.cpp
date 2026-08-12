void Calc_ETA()
{

	for(j=1;j<NJ-1;j++)
	{
	  for(i=1;i<NI-1;i++)
	    { 
			HoriX[j][i]=fabs(CV_corner_coor[0][j][i]-CV_corner_coor[0][j][i-1]); 
			VertiY[j][i]=fabs(CV_corner_coor[1][j][i]-CV_corner_coor[1][j][i-1]); 
			
			DELXX[j][i]= sqrt(pow(HoriX[j][i],2) + pow(VertiY[j][i],2)); 			 
	    }
	}	
 	
 	maxElement = 0;
	for(j=1;j<NJ-1;j++)
	{
	  for(i=1;i<NI-1;i++)
	    { 
		 if(DELXX[j][i] > maxElement) 
		  {
                	maxElement = DELXX[j][i];
       	  }	
            }	
        }
        
        ETA = 1.5*maxElement; 
        
        //cout<<"maxElement 1 :"<<maxElement<<endl;
        // cin.get(); 
         			
}


