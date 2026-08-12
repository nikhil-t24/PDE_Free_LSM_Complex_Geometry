
void Calc_Initial_Mass()
{	
#define pi 3.14159265359

         Calc_ETA();
         double sumMass=0;
           
         for(j=1;j<(NJ-1);j++)
	  {
		for(i=1;i<(NI-1);i++)
		{
	           if (PHI_MAIN[j][i] > ETA)    
	               HeavySide[j][i] = 1;
	           else if (PHI_MAIN[j][i] <= ETA && PHI_MAIN[j][i] >= -ETA)    
	                    HeavySide[j][i] = ((PHI_MAIN[j][i] + ETA)/(2*ETA)) + (1/(2*pi))*sin((180*PHI_MAIN[j][i])/ETA);
	                else
	                    HeavySide[j][i] = 0;   
	                     
	           sumMass = sumMass + VOL[j][i]*HeavySide[j][i];                
		}
	  }
	  InitialMass = sumMass; 
}      
      

void Calc_Final_Mass()
{
         Calc_ETA();
         double sumMass=0;
                  
         for(j=1;j<(NJ-1);j++)
	  {
		for(i=1;i<(NI-1);i++)
		{
	           if (PHI_MAIN[j][i] > ETA)   
	               HeavySide[j][i] = 1;
	           else if (PHI_MAIN[j][i] <= ETA && PHI_MAIN[j][i] >= -ETA)    
	                    HeavySide[j][i] = ((PHI_MAIN[j][i] + ETA)/(2*ETA)) + (1/(2*pi))*sin((180*PHI_MAIN[j][i])/ETA);
	                else
	                    HeavySide[j][i] = 0;  
	                     
	           sumMass = sumMass + VOL[j][i]*HeavySide[j][i];                
		}
	  }	
	  FinalMass = sumMass; 
} 


