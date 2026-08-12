void Initial_Lagr_Points()
{

   
   // Extracting Points
   for(iface=0;iface<2;iface++)
   {	
	// Left
		k = 0;	
		
		for(j=0;j<NJ;j++)
		{
		   for(i=0;i<NI;i++)
		    {
			if( PHI_CC[iface][j][i] < 0 && PHI_CC[iface][j][i] * PHI_CC[iface][j][i-1] < 0 )
			{
			    X_lagr[iface][k] = var_coor[0][j][i] - (var_coor[0][j][i] - var_coor[0][j][i-1])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j][i-1])));
			    Y_lagr[iface][k] = var_coor[1][j][i] - (var_coor[1][j][i] - var_coor[1][j][i-1])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j][i-1])));
			    			
			    k = k+1;
			}    	
		    }		
		}
		            									
	// Right	
		for(j=0;j<NJ;j++)
		{
		   for(i=0;i<NI;i++)
		    {
			if( PHI_CC[iface][j][i] < 0 && PHI_CC[iface][j][i] * PHI_CC[iface][j][i+1] < 0 )
			{
			    X_lagr[iface][k] = var_coor[0][j][i] + (var_coor[0][j][i+1] - var_coor[0][j][i])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j][i+1])));
			    Y_lagr[iface][k] = var_coor[1][j][i] + (var_coor[1][j][i+1] - var_coor[1][j][i])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j][i+1])));
				
			    k = k+1;
			}    	
		    }		
		}
		
	// Bottom
		for(j=0;j<NJ;j++)
		{
		   for(i=0;i<NI;i++)
		    {
			if( PHI_CC[iface][j][i] < 0 && PHI_CC[iface][j][i] * PHI_CC[iface][j-1][i] < 0 )
			{
			    X_lagr[iface][k] = var_coor[0][j][i] - (var_coor[0][j][i] - var_coor[0][j-1][i])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j-1][i])));
			    Y_lagr[iface][k] = var_coor[1][j][i] - (var_coor[1][j][i] - var_coor[1][j-1][i])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j-1][i])));
				
			    k = k+1;
			}    	
		    }		
		}	
		
	// Top
		for(j=0;j<NJ;j++)
		{
		   for(i=0;i<NI;i++)
		    {
			if( PHI_CC[iface][j][i] < 0 && PHI_CC[iface][j][i] * PHI_CC[iface][j+1][i] < 0 )
			{
			    X_lagr[iface][k] = var_coor[0][j][i] + (var_coor[0][j+1][i] - var_coor[0][j][i])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j+1][i])));
			    Y_lagr[iface][k] = var_coor[1][j][i] + (var_coor[1][j+1][i] - var_coor[1][j][i])*(fabs(PHI_CC[iface][j][i])/(fabs(PHI_CC[iface][j][i])+fabs(PHI_CC[iface][j+1][i])));
				
			    k = k+1;
			}    	
		    }		
		}

		
	// **********************************************************************
		        
	       llmaxx[iface] = k; // lmax is total number of points on the interface
	          
    }

   
   
   //iface = 1; 
   for(iface=0;iface<2;iface++)
   {     
	  // Ordering Points     
	       
	       lmax = 0;
	       lmax = llmaxx[iface];  
	       
	       arrangePoints(X_lagr,Y_lagr,X_ordered_lagr,Y_ordered_lagr,lmax); 
		       
	       X_ordered_lagr[iface][lmax] = X_ordered_lagr[iface][0];
	       Y_ordered_lagr[iface][lmax] = Y_ordered_lagr[iface][0];	       
	      	         
	       lmax = llmaxx[iface]+1;

   	// Unique Points

	       
	       int new_lmax[100000];   
	       new_lmax[iface] = uniquePoints(X_ordered_lagr,Y_ordered_lagr,X_unique_lagr,Y_unique_lagr,lmax); 
	       lmax = new_lmax[iface];
	       
	       X_unique_lagr[iface][lmax] = X_unique_lagr[iface][0];
	       Y_unique_lagr[iface][lmax] = Y_unique_lagr[iface][0];	
	       
	       lmax = new_lmax[iface] + 1;
	       

   	// Increasing Points

	      for(l=0;l<lmax;l++)
	      {
	         X_ordered_lagr[iface][l] = X_unique_lagr[iface][l];
	         Y_ordered_lagr[iface][l] = Y_unique_lagr[iface][l];	
	      }
	         
              increasePoints();
              
              
	      //int new_lmax[100000];   
	      new_lmax[iface] = uniquePoints(X_new_lagr,Y_new_lagr,X_unique_lagr,Y_unique_lagr,Total_points); 
	      Total_points = new_lmax[iface];
	       
	      X_unique_lagr[iface][Total_points] = X_unique_lagr[iface][0];
	      Y_unique_lagr[iface][Total_points] = Y_unique_lagr[iface][0];	
	       
	      lmax = new_lmax[iface] + 1;
	       	
		
	      for(l=0;l<lmax;l++)
	      {
	         X_ordered_lagr[iface][l] = X_unique_lagr[iface][l];
	         Y_ordered_lagr[iface][l] = Y_unique_lagr[iface][l];	
	      }
	      
	      llmaxx[iface] = lmax;		
		
    }
    
      
}


    

int uniquePoints(double X_input[][100000], double Y_input[][100000], double X_unique_output[][100000], double Y_unique_output[][100000], int lmax) 
{
	int exist,uniqueCount = 0;
      	double yy,xx;

	    for(i=0;i<lmax;i++) 
	    {
		 xx = X_input[iface][i];
		 yy = Y_input[iface][i];
		 exist = 0;

		// Check if the point already exist in the uniquePoints array
		for(j=0; j<uniqueCount;j++) 
		{	
		    if(X_unique_output[iface][j] >= xx-1e-5 && X_unique_output[iface][j] <= xx+1e-5 && Y_unique_output[iface][j] >= yy-1e-5 && Y_unique_output[iface][j] <= yy+1e-5)
		    {
		        exist = 1;
		        break;
		    }
		}

		// If the point does not exist, add it to the uniquePoints array
		if (exist == 0) 
		{
		    X_unique_output[iface][uniqueCount] = xx;
		    Y_unique_output[iface][uniqueCount] = yy;
		    uniqueCount++;
		}
	    } 
	    
    return uniqueCount;
}


void arrangePoints(double X_input[][100000], double Y_input[][100000], double X_ordered_output[][100000], double Y_ordered_output[][100000], int lmax) 
{
	    int visited[lmax] = {0}; 		// Array to keep track of visited points (0 = not visited, 1 = visited)
	    int currentIndex = 0; 		// Start from the first point

	    X_ordered_output[iface][0] = X_input[iface][currentIndex]; 		// Add the first point to the ordered list
	    Y_ordered_output[iface][0] = Y_input[iface][currentIndex];
	    visited[currentIndex] = 1; 				// Mark the first point as visited

	    // Loop to find and add the rest of the points
	    for(int i=1; i<lmax;++i)
	    {
		currentIndex = findNearestPoint(X_input, Y_input, visited, currentIndex, lmax); // Find the next nearest point
		X_ordered_output[iface][i] = X_input[iface][currentIndex]; // Add the nearest point to the ordered list
		Y_ordered_output[iface][i] = Y_input[iface][currentIndex];
		visited[currentIndex] = 1; // Mark this point as visited
	    }

}


int findNearestPoint(double X_input[][100000], double Y_input[][100000], int visited[], int currentIndex, int lmax) 
{
    int nearestIndex = -1; 			// This will store the index of the nearest point
    double shortestDistance = 1000000; 

    for(int i=0; i<lmax;++i)  // Loop through all the points to find the closest one
    {
        if(visited[i] == 0) 
        {   // Check if this point has not been visited
            double dist = calculateDistance(X_input[iface][currentIndex], Y_input[iface][currentIndex], X_input[iface][i], Y_input[iface][i]);
            if (dist < shortestDistance) 
            { 						// If we find a closer point
                shortestDistance = dist; 		// Update the shortest distance
                nearestIndex = i; 			// Update the index of the nearest point
            }
        }
    }

    return nearestIndex; 
}


double calculateDistance(double x1, double y1, double x2, double y2) 
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );    
}







void increasePoints()
{

	       int Ptaken,Ptaken_ref,num_points, point_density;	
	       
	       double X_coeff_a[lmax], X_coeff_b[lmax], X_coeff_c[lmax], X_coeff_d[lmax];
	       double Y_coeff_a[lmax], Y_coeff_b[lmax], Y_coeff_c[lmax], Y_coeff_d[lmax];

	       double lower_bound,upper_bound;
	       

	       MM = (lmax/3)-1;
	       Ptaken_ref = 4;   	// Indicates number of lagrangian points considered for Cubic Spline Interpolation, irrespective of last set of points.
	       point_density = 5;
	       
	       Total_points = (Ptaken_ref-1)*(MM-1)*point_density + ( (lmax-1) - (Ptaken_ref-1)*(MM-1) )*point_density;   // For Closed Curve
	       //cout<<"Total_points : "<<Total_points<<endl;

	    	for(int I=0; I<MM; I++)
	    	{
			if(I<MM-1)
			{
			    Ptaken = Ptaken_ref;
			    num_points = (Ptaken-1)*point_density;    // Define the number of points to generate
			}
			else
			{
			    Ptaken = lmax - (Ptaken_ref-1)*(MM-1);
			    num_points = (Ptaken-1)*point_density;    // Define the number of points to generate
			}
			
			
			for(int i=0; i<Ptaken; i++) 
			{
			    X_ordered_lagr_3[i] = X_ordered_lagr[iface][(Ptaken_ref-1)*I + i];
			    Y_ordered_lagr_3[i] = Y_ordered_lagr[iface][(Ptaken_ref-1)*I + i];
			}
		
			if( (fabs(X_ordered_lagr_3[0] - X_ordered_lagr_3[Ptaken-1])) >= (fabs(Y_ordered_lagr_3[0] - Y_ordered_lagr_3[Ptaken-1])) )
			{  
			        
			            int flag = 1; // 1 means valid, 0 means invalid
			        
				    for(int i=1; i<Ptaken-1; i++)  
				    {
					if ( !( (X_ordered_lagr_3[i] >= X_ordered_lagr_3[0] && X_ordered_lagr_3[i] <= X_ordered_lagr_3[Ptaken-1]) 
					     || (X_ordered_lagr_3[i] <= X_ordered_lagr_3[0] && X_ordered_lagr_3[i] >= X_ordered_lagr_3[Ptaken-1]) ) ) 
					{
					    flag = 0;
					    break;
					}
				    }

				    if(flag == 1) // All intermediate x-coordinates are within the range of the first and last points.
				    {
						
						// Y = f(X)
						Cubic_Spline_Coeff_X(X_ordered_lagr_3, Y_ordered_lagr_3, X_coeff_a, X_coeff_b, X_coeff_c, X_coeff_d, Ptaken);
					   
						lower_bound = X_ordered_lagr_3[0];
						upper_bound = X_ordered_lagr_3[Ptaken-1];
					       
						double spacing = (upper_bound - lower_bound) / (num_points - 1);   // Compute the spacing between points
					       
					       for (int i=0; i<num_points; ++i) 
					       {
							 xi = lower_bound + i * spacing;
							 yi = Cubic_Spline_Interpolation_X(X_coeff_a, X_coeff_b, X_coeff_c, X_coeff_d, X_ordered_lagr_3, xi, Ptaken);
							 
							 X_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = xi;
							 Y_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = yi;

				       		}
				       								
				    } 
				    else  // At least one intermediate x-coordinate is outside the range
				    {

					       // X = f(Y)
					       Cubic_Spline_Coeff_Y(Y_ordered_lagr_3, X_ordered_lagr_3, Y_coeff_a, Y_coeff_b, Y_coeff_c, Y_coeff_d, Ptaken);
					   
						lower_bound = Y_ordered_lagr_3[0];
						upper_bound = Y_ordered_lagr_3[Ptaken-1];			
					       
						double spacing = (upper_bound - lower_bound) / (num_points - 1);   // Compute the spacing between points

					       for (int i=0; i<num_points; ++i) 
					       {
							 yi = lower_bound + i * spacing;
							 xi = Cubic_Spline_Interpolation_Y(Y_coeff_a, Y_coeff_b, Y_coeff_c, Y_coeff_d, Y_ordered_lagr_3, yi, Ptaken);

							 X_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = xi;
							 Y_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = yi;
				       		}					
					
				    }			        
			        
			}
			else
			{  	

			            int flag = 1; // 1 means valid, 0 means invalid
			        
				    for(int i=1; i<Ptaken-1; i++)  
				    {
					if ( !( (Y_ordered_lagr_3[i] >= Y_ordered_lagr_3[0] && Y_ordered_lagr_3[i] <= Y_ordered_lagr_3[Ptaken-1]) 
					     || (Y_ordered_lagr_3[i] <= Y_ordered_lagr_3[0] && Y_ordered_lagr_3[i] >= Y_ordered_lagr_3[Ptaken-1]) ) ) 
					{
					    flag = 0;
					    break;
					}
				    }					       
					       
				    if(flag == 1) // All intermediate y-coordinates are within the range of the first and last points.
				    {
				  
					       // X = f(Y)
					       Cubic_Spline_Coeff_Y(Y_ordered_lagr_3, X_ordered_lagr_3, Y_coeff_a, Y_coeff_b, Y_coeff_c, Y_coeff_d, Ptaken);
					   
						lower_bound = Y_ordered_lagr_3[0];
						upper_bound = Y_ordered_lagr_3[Ptaken-1];			
					       
						double spacing = (upper_bound - lower_bound) / (num_points - 1);   // Compute the spacing between points

					       for (int i=0; i<num_points; ++i) 
					       {
							 yi = lower_bound + i * spacing;
							 xi = Cubic_Spline_Interpolation_Y(Y_coeff_a, Y_coeff_b, Y_coeff_c, Y_coeff_d, Y_ordered_lagr_3, yi, Ptaken);

							 X_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = xi;
							 Y_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = yi;
							 
				       		}
		       						    
				    }
				    else   // At least one intermediate y-coordinate is outside the range
				    {
				    
						// Y = f(X)
						Cubic_Spline_Coeff_X(X_ordered_lagr_3, Y_ordered_lagr_3, X_coeff_a, X_coeff_b, X_coeff_c, X_coeff_d, Ptaken);
					   
						lower_bound = X_ordered_lagr_3[0];
						upper_bound = X_ordered_lagr_3[Ptaken-1];
					       
						double spacing = (upper_bound - lower_bound) / (num_points - 1);   // Compute the spacing between points
					       
					       for (int i=0; i<num_points; ++i) 
					       {
							 xi = lower_bound + i * spacing;
							 yi = Cubic_Spline_Interpolation_X(X_coeff_a, X_coeff_b, X_coeff_c, X_coeff_d, X_ordered_lagr_3, xi, Ptaken);
							 
							 X_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = xi;
							 Y_new_lagr[iface][I*(Ptaken_ref-1)*point_density + i] = yi;

				       		}
				       						    
				    }					       

			}
	    	} 
		

			
}



// **********************************************************
// **********************************************************
// Function to perform Cubic Spline interpolation


// ********************************************************************************************************************
// ********************************************************************************************************************

// Y = f(X)
void Cubic_Spline_Coeff_X(double X_ordered_lagr_3[], double Y_ordered_lagr_3[], 
			double X_coeff_a[], double X_coeff_b[], double X_coeff_c[], double X_coeff_d[], int Ptaken) 
{
    double h[Ptaken-1], d[Ptaken-1];
    for (int i=0; i<Ptaken-1; ++i) 
    {
        h[i] = X_ordered_lagr_3[i+1] - X_ordered_lagr_3[i];
        d[i] = (Y_ordered_lagr_3[i+1] - Y_ordered_lagr_3[i])/h[i];
    }

    // TriD System Setup
    double u[Ptaken-1], v[Ptaken-1];
    for (int i=1; i<Ptaken-1; ++i) 
    {
        u[i] = 2*(h[i-1] + h[i]);
        v[i] = 6*(d[i] - d[i-1]);
    }

    // Solving TriD System
    double m[Ptaken];
    double l=1, z=0;
    for (int i=1; i<Ptaken-1; ++i) 
    {
        l = 2*( X_ordered_lagr_3[i+1]-X_ordered_lagr_3[i-1] ) - h[i-1]*z;
        z = h[i]/l;
        m[i] = (v[i] - h[i-1]*m[i-1])/l;
    }

    // Coefficients
    for (int i=0; i<Ptaken-1; ++i) 
    {
        X_coeff_a[i] = Y_ordered_lagr_3[i];
        X_coeff_b[i] = d[i] - (h[i]/6)*(2*m[i] + m[i+1]);
        X_coeff_c[i] = m[i]/2;
        X_coeff_d[i] = (m[i+1] - m[i])/(6*h[i]);
    }
    
}


// Interpolation
double Cubic_Spline_Interpolation_X(double X_coeff_a[], double X_coeff_b[], double X_coeff_c[], double X_coeff_d[], 
					double X_ordered_lagr_3[], double xi, int Ptaken) 
{
    for (int i=0; i<Ptaken-1; ++i) 
    {
        if(xi >= X_ordered_lagr_3[i] && xi <= X_ordered_lagr_3[i+1]) 
        {
            double dx = xi - X_ordered_lagr_3[i];
            return X_coeff_a[i] + X_coeff_b[i]*dx + X_coeff_c[i]*dx*dx + X_coeff_d[i]*dx*dx*dx;
        }
        else if(xi <= X_ordered_lagr_3[i] && xi >= X_ordered_lagr_3[i+1]) 
        {
            double dx = xi - X_ordered_lagr_3[i];
            return X_coeff_a[i] + X_coeff_b[i]*dx + X_coeff_c[i]*dx*dx + X_coeff_d[i]*dx*dx*dx;
        }     
    }
    return 0; // Default value if xi is out of range
}


// **********************************************************
// **********************************************************


// X = f(Y)
void Cubic_Spline_Coeff_Y(double Y_ordered_lagr_3[], double X_ordered_lagr_3[], 
			double Y_coeff_a[], double Y_coeff_b[], double Y_coeff_c[], double Y_coeff_d[], int Ptaken) 
{    
    double h[Ptaken-1], d[Ptaken-1];
    for (int i=0; i<Ptaken-1; ++i) 
    {
        h[i] = Y_ordered_lagr_3[i+1] - Y_ordered_lagr_3[i];
        d[i] = (X_ordered_lagr_3[i+1] - X_ordered_lagr_3[i])/h[i];
    }

    // TriD System Setup
    double u[Ptaken-1], v[Ptaken-1];
    for (int i=1; i<Ptaken-1; ++i) 
    {
        u[i] = 2*(h[i-1] + h[i]);
        v[i] = 6*(d[i] - d[i-1]);
    }

    // Solving TriD System
    double m[Ptaken];
    double l=1, z=0;
    for (int i=1; i<Ptaken-1; ++i) 
    {
        l = 2*( Y_ordered_lagr_3[i+1]-Y_ordered_lagr_3[i-1] ) - h[i-1]*z;
        z = h[i]/l;
        m[i] = (v[i] - h[i-1]*m[i-1])/l;
    }

    // Coefficients
    for (int i=0; i<Ptaken-1; ++i) 
    {
        Y_coeff_a[i] = X_ordered_lagr_3[i];
        Y_coeff_b[i] = d[i] - (h[i]/6)*(2*m[i] + m[i+1]);
        Y_coeff_c[i] = m[i]/2;
        Y_coeff_d[i] = (m[i+1] - m[i])/(6*h[i]);
    }
  
}


// Interpolation
double Cubic_Spline_Interpolation_Y(double Y_coeff_a[], double Y_coeff_b[], double Y_coeff_c[], double Y_coeff_d[], 
					double Y_ordered_lagr_3[], double yi, int Ptaken) 
{ 
    for (int i=0; i<Ptaken-1; ++i) 
    {
        if(yi >= Y_ordered_lagr_3[i] && yi <= Y_ordered_lagr_3[i+1]) 
        {
            double dy = yi - Y_ordered_lagr_3[i];
            return Y_coeff_a[i] + Y_coeff_b[i]*dy + Y_coeff_c[i]*dy*dy + Y_coeff_d[i]*dy*dy*dy;
        }
        else if(yi <= Y_ordered_lagr_3[i] && yi >= Y_ordered_lagr_3[i+1]) 
        {
            double dy = yi - Y_ordered_lagr_3[i];
            return Y_coeff_a[i] + Y_coeff_b[i]*dy + Y_coeff_c[i]*dy*dy + Y_coeff_d[i]*dy*dy*dy;
        }
    }
    return 0; // Default value if yi is out of range
}



