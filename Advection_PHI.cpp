void Advect_PHI() 
{
   
   for(j=1;j<(NJ-1);j++)
   {
      for(i=1;i<(NI-1);i++)
      {   
	       Y_ne[j][i] = CV_corner_coor[1][j][i]; 
	       Y_nw[j][i] = CV_corner_coor[1][j][i-1]; 
	       Y_se[j][i] = CV_corner_coor[1][j-1][i]; 
	       Y_sw[j][i] = CV_corner_coor[1][j-1][i-1]; 
	   
	       X_ne[j][i] = CV_corner_coor[0][j][i]; 
	       X_nw[j][i] = CV_corner_coor[0][j][i-1]; 
	       X_se[j][i] = CV_corner_coor[0][j-1][i]; 
	       X_sw[j][i] = CV_corner_coor[0][j-1][i-1];
	       
	       
	       Y_min_temp1 = min(Y_ne[j][i],Y_nw[j][i]);
	       Y_min_temp2 = min(Y_se[j][i],Y_sw[j][i]);
	       Y_min[j][i] = min(Y_min_temp1,Y_min_temp2);
	       
	       Y_max_temp1 = max(Y_ne[j][i],Y_nw[j][i]);
	       Y_max_temp2 = max(Y_se[j][i],Y_sw[j][i]);	       
	       Y_max[j][i] = max(Y_max_temp1,Y_max_temp2); 
	       
	       X_min_temp1 = min(X_ne[j][i],X_nw[j][i]);
	       X_min_temp2 = min(X_se[j][i],X_sw[j][i]);
	       X_min[j][i] = min(X_min_temp1,X_min_temp2);
	       
	       X_max_temp1 = max(X_ne[j][i],X_nw[j][i]);
	       X_max_temp2 = max(X_se[j][i],X_sw[j][i]);	       
	       X_max[j][i] = max(X_max_temp1,X_max_temp2);	          
      }
   }
   
   Calc_Corner_UV();   
   
   //iface=1;
   for(iface=0;iface<2;iface++)
   {	
	      lmax = 0;
	      lmax = llmaxx[iface];  
	     
	      for(l=0;l<lmax;l++)
	      {
		   for(j=1;j<(NJ-1);j++)
		   {
		      for(i=1;i<(NI-1);i++)
		      {   
			   if(X_min[j][i] <= X_ordered_lagr[iface][l] && X_max[j][i] >= X_ordered_lagr[iface][l] &&
			      Y_min[j][i] <= Y_ordered_lagr[iface][l] && Y_max[j][i] >= Y_ordered_lagr[iface][l])      //  Bounding Box 
			    { 
			      
			      // Triangle 1 : sw,se,ne
			      
			      T1l1 = ( (Y_se[j][i] - Y_ne[j][i])*(X_ordered_lagr[iface][l] - X_ne[j][i]) + (X_ne[j][i] - X_se[j][i])*(Y_ordered_lagr[iface][l] - Y_ne[j][i]) )
			      	     /( (Y_se[j][i] - Y_ne[j][i])*(X_sw[j][i] - X_ne[j][i]) + (X_ne[j][i] - X_se[j][i])*(Y_sw[j][i] - Y_ne[j][i]) ); 
			      	     
			      T1l2 = ( (Y_ne[j][i] - Y_sw[j][i])*(X_ordered_lagr[iface][l] - X_ne[j][i]) + (X_sw[j][i] - X_ne[j][i])*(Y_ordered_lagr[iface][l] - Y_ne[j][i]) )
			      	     /( (Y_se[j][i] - Y_ne[j][i])*(X_sw[j][i] - X_ne[j][i]) + (X_ne[j][i] - X_se[j][i])*(Y_sw[j][i] - Y_ne[j][i]) );
			      	     
			      T1l3 = 1 - T1l1 - T1l2;	
			      
			      // Triangle 2 : sw,ne,nw
			      
			      T2l1 = ( (Y_ne[j][i] - Y_nw[j][i])*(X_ordered_lagr[iface][l] - X_nw[j][i]) + (X_nw[j][i] - X_ne[j][i])*(Y_ordered_lagr[iface][l] - Y_nw[j][i]) )
			      	     /( (Y_ne[j][i] - Y_nw[j][i])*(X_sw[j][i] - X_nw[j][i]) + (X_nw[j][i] - X_ne[j][i])*(Y_sw[j][i] - Y_nw[j][i]) ); 
			      	     
			      T2l2 = ( (Y_nw[j][i] - Y_sw[j][i])*(X_ordered_lagr[iface][l] - X_nw[j][i]) + (X_sw[j][i] - X_nw[j][i])*(Y_ordered_lagr[iface][l] - Y_nw[j][i]) )
			      	     /( (Y_ne[j][i] - Y_nw[j][i])*(X_sw[j][i] - X_nw[j][i]) + (X_nw[j][i] - X_ne[j][i])*(Y_sw[j][i] - Y_nw[j][i]) );
			      	     
			      T2l3 = 1 - T2l1 - T2l2;
			      
			      
			      T1l_min_temp1 = min(T1l1,T1l2);
			      T1l_min = min(T1l_min_temp1,T1l3);
			      
			      T1l_max_temp1 = max(T1l1,T1l2);
			      T1l_max = max(T1l_max_temp1,T1l3);
			      
			      T2l_min_temp1 = min(T2l1,T2l2);
			      T2l_min = min(T2l_min_temp1,T2l3);
			      
			      T2l_max_temp1 = max(T2l1,T2l2);
			      T2l_max = max(T2l_max_temp1,T2l3);		      	       
			      
			      if( (T1l_min >= 0 && T1l_max <= 1) || (T2l_min >= 0 && T2l_max <= 1) )
			      {
				    // Bilinear Interpolation
				    // Initial guess for (mapX, mapY) in a mapped 1 by 1 grid.
				     mapX = 0.5;
				     mapY = 0.5;

				    double tol = 1e-6;
				    int iter,maxIter = 100;

				    for (iter=0;iter<maxIter;iter++) 
				    {
					// Calculate the X_ordered_lagr[iface][l] and Y_ordered_lagr[iface][l] from current (mapX, mapY)
					fx = (1 - mapX)*(1 - mapY)*X_sw[j][i] + mapX*(1 - mapY)*X_se[j][i] + mapX*mapY*X_ne[j][i] 
						+ (1 - mapX)*mapY*X_nw[j][i] - X_ordered_lagr[iface][l];
					fy = (1 - mapX)*(1 - mapY)*Y_sw[j][i] + mapX*(1 - mapY)*Y_se[j][i] + mapX*mapY*Y_ne[j][i] 
						+ (1 - mapX)*mapY*Y_nw[j][i] - Y_ordered_lagr[iface][l];

					if (fabs(fx) < tol && fabs(fy) < tol) 
					{
					    break;
					}

					// Derivatives
					dfx_dmapX = (1 - mapY)*(X_se[j][i] - X_sw[j][i]) + mapY*(X_ne[j][i] - X_nw[j][i]);
					dfx_dmapY = (1 - mapX)*(X_nw[j][i] - X_sw[j][i]) + mapX*(X_ne[j][i] - X_se[j][i]);
					dfy_dmapX = (1 - mapY)*(Y_se[j][i] - Y_sw[j][i]) + mapY*(Y_ne[j][i] - Y_nw[j][i]);
					dfy_dmapY = (1 - mapX)*(Y_nw[j][i] - Y_sw[j][i]) + mapX*(Y_ne[j][i] - Y_se[j][i]);

					det = dfx_dmapX*dfy_dmapY - dfx_dmapY*dfy_dmapX;

					// Update mapX and mapY
					mapX_new = mapX - (fx*dfy_dmapY - fy*dfx_dmapY)/det;
					mapY_new = mapY - (fy*dfx_dmapX - fx*dfy_dmapX)/det;

					mapX = mapX_new;
					mapY = mapY_new;
				    }

				    // Interpolate the velocity components
				    U_ordered_lagr[iface][l] = (1 - mapX)*(1 - mapY)*U_sw[j][i] + mapX*(1 - mapY)*U_se[j][i] + mapX*mapY*U_ne[j][i] + (1 - mapX)*mapY*U_nw[j][i];
				    V_ordered_lagr[iface][l] = (1 - mapX)*(1 - mapY)*V_sw[j][i] + mapX*(1 - mapY)*V_se[j][i] + mapX*mapY*V_ne[j][i] + (1 - mapX)*mapY*V_nw[j][i];
			      }
			      
			    }  
		      }
		   } 
	       }   
	   
	       for(l=0;l<lmax;l++)
	       {
		   X_ordered_lagr[iface][l] = X_ordered_lagr[iface][l] + DELT*U_ordered_lagr[iface][l];
		   Y_ordered_lagr[iface][l] = Y_ordered_lagr[iface][l] + DELT*V_ordered_lagr[iface][l];  
	       }	       


	       Reinitialization();
   
   }	   
   
	
    for(j=0;j<NJ;j++)
    {
	  for(i=0;i<NI;i++)
	  {		
		PHI_MAIN[j][i] =  min(PHI_CC[0][j][i],PHI_CC[1][j][i]);		
   	  }
    }


}


void Calc_Corner_UV()
{
	
// NE Corner Velocity
	for(j=1;j<NJ-2;j++)
	{
	  for(i=1;i<NI-2;i++)
	   {	     
		U_ne[j][i] = ( ( VOL[j+1][i+1]*U[j][i] + VOL[j][i]*U[j+1][i+1] + VOL[j+1][i]*U[j][i+1] + VOL[j][i+1]*U[j+1][i] ) / 
				( VOL[j+1][i+1] + VOL[j][i] + VOL[j][i+1] + VOL[j+1][i] ) );
				
		V_ne[j][i] = ( ( VOL[j+1][i+1]*V[j][i] + VOL[j][i]*V[j+1][i+1] + VOL[j+1][i]*V[j][i+1] + VOL[j][i+1]*V[j+1][i] ) / 
				( VOL[j+1][i+1] + VOL[j][i] + VOL[j][i+1] + VOL[j+1][i] ) );								
	   }
	}
	
	for(j=1;j<NJ-2;j++)
	{
	        i = NI-2;
	        U_ne[j][i] = 0.5*(U[j+1][i+1] + U[j][i+1]); 
	        V_ne[j][i] = 0.5*(V[j+1][i+1] + V[j][i+1]);   
	}

	for(i=1;i<NI-2;i++)
	{	     
	        j = NJ-2;
	        U_ne[j][i] = 0.5*(U[j+1][i+1] + U[j+1][i]);
	        V_ne[j][i] = 0.5*(V[j+1][i+1] + V[j+1][i]);
	}
	   
	        U_ne[NJ-2][NI-2] = U[NJ-1][NI-1];
	        V_ne[NJ-2][NI-2] = V[NJ-1][NI-1];	

        			
// ******************************************************		        			
// ******************************************************	
	
// SE Corner Velocity
	for(j=2;j<NJ-1;j++)
	{
	  for(i=1;i<NI-2;i++)
	   {	     
		U_se[j][i] = ( ( VOL[j-1][i+1]*U[j][i] + VOL[j][i]*U[j-1][i+1] + VOL[j-1][i]*U[j][i+1] + VOL[j][i+1]*U[j-1][i] ) / 
				( VOL[j-1][i+1] + VOL[j-1][i] + VOL[j][i] + VOL[j][i+1] ) );
				
		V_se[j][i] = ( ( VOL[j-1][i+1]*V[j][i] + VOL[j][i]*V[j-1][i+1] + VOL[j-1][i]*V[j][i+1] + VOL[j][i+1]*V[j-1][i] ) / 
				( VOL[j-1][i+1] + VOL[j-1][i] + VOL[j][i] + VOL[j][i+1] ) );					
	   }
	}
	
	for(j=2;j<NJ-1;j++)
	{
	        i = NI-2;
	        U_se[j][i] = 0.5*(U[j][i+1] + U[j-1][i+1]);
	        V_se[j][i] = 0.5*(V[j][i+1] + V[j-1][i+1]);    
	}

	for(i=1;i<NI-2;i++)
	{	     
	        j = 1;
	        U_se[j][i] = 0.5*(U[j-1][i] + U[j-1][i+1]);
	        V_se[j][i] = 0.5*(V[j-1][i] + V[j-1][i+1]);
	}
	   
	        U_se[1][NI-2] = U[0][NI-1];
	        V_se[1][NI-2] = V[0][NI-1];	
	
// ******************************************************	
// ******************************************************
			
// NW Corner Velocity
	for(j=1;j<NJ-2;j++)
	{
	  for(i=2;i<NI-1;i++)
	   {	     
		U_nw[j][i] = ( ( VOL[j+1][i-1]*U[j][i] + VOL[j][i]*U[j+1][i-1] + VOL[j+1][i]*U[j][i-1] + VOL[j][i-1]*U[j+1][i] ) / 
				( VOL[j+1][i-1] + VOL[j+1][i] + VOL[j][i] + VOL[j][i-1] ) );	
				
		V_nw[j][i] = ( ( VOL[j+1][i-1]*V[j][i] + VOL[j][i]*V[j+1][i-1] + VOL[j+1][i]*V[j][i-1] + VOL[j][i-1]*V[j+1][i] ) / 
				( VOL[j+1][i-1] + VOL[j+1][i] + VOL[j][i] + VOL[j][i-1] ) );				
	   }
	}
	
	for(j=1;j<NJ-2;j++)
	{
	        i = 1;
	        U_nw[j][i] = 0.5*(U[j+1][i-1] + U[j][i-1]);
	        V_nw[j][i] = 0.5*(V[j+1][i-1] + V[j][i-1]);   
	}

	for(i=2;i<NI-1;i++)
	{	     
	        j = NJ-2;
	        U_nw[j][i] = 0.5*(U[j+1][i] + U[j+1][i-1]);
	        V_nw[j][i] = 0.5*(V[j+1][i] + V[j+1][i-1]);
	}
	   
	        U_nw[NJ-2][1] = U[NJ-1][0];
	        V_nw[NJ-2][1] = V[NJ-1][0];	      
	        	        
// ******************************************************				        		        
// ******************************************************
				        	
// SW Corner Velocity
	for(j=2;j<NJ-1;j++)
	{
	  for(i=2;i<NI-1;i++)
	   {	     
		U_sw[j][i] = ( ( VOL[j-1][i-1]*U[j][i] + VOL[j][i]*U[j-1][i-1] + VOL[j-1][i]*U[j][i-1] + VOL[j][i-1]*U[j-1][i] ) / 
				( VOL[j-1][i-1] + VOL[j-1][i] + VOL[j][i] + VOL[j][i-1] ) );	
				
		V_sw[j][i] = ( ( VOL[j-1][i-1]*V[j][i] + VOL[j][i]*V[j-1][i-1] + VOL[j-1][i]*V[j][i-1] + VOL[j][i-1]*V[j-1][i] ) / 
				( VOL[j-1][i-1] + VOL[j-1][i] + VOL[j][i] + VOL[j][i-1] ) );					
	   }
	}		

	for(j=2;j<NJ-1;j++)
	{
	        i = 1;
	        U_sw[j][i] = 0.5*(U[j][i-1] + U[j-1][i-1]); 
	        V_sw[j][i] = 0.5*(V[j][i-1] + V[j-1][i-1]); 	         
	}

	for(i=2;i<NI-1;i++)
	{	     
	        j = 1;
	        U_sw[j][i] = 0.5*(U[j-1][i] + U[j-1][i-1]);
	        V_sw[j][i] = 0.5*(V[j-1][i] + V[j-1][i-1]);	        
	}
	   
	        U_sw[1][1] = U[0][0];
	        V_sw[1][1] = V[0][0];
	        
// ******************************************************				        		        
// ******************************************************		       				        		        
	        	
}






