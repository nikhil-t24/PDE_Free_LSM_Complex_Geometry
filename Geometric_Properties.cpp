void Geometric_Properties()
{
// Corners of CV
 for(j=0;j<NJ-1;j++)
 {
   for(i=0;i<NI-1;i++)
     {
	CV_corner_coor[0][j][i] = x[j][i];
	CV_corner_coor[1][j][i] = y[j][i];
     }
 }

// ******************************* 
 
// write_Mesh();
 
// *******************************

// Centroid of CV
 for(j=1;j<NJ-1;j++)
 {
   for(i=1;i<NI-1;i++)
     {
	var_coor[0][j][i] = 0.25 * ( CV_corner_coor[0][j][i] + CV_corner_coor[0][j-1][i] + CV_corner_coor[0][j][i-1] + CV_corner_coor[0][j-1][i-1] );
	var_coor[1][j][i] = 0.25 * ( CV_corner_coor[1][j][i] + CV_corner_coor[1][j-1][i] + CV_corner_coor[1][j][i-1] + CV_corner_coor[1][j-1][i-1] );
     }
 }

//Defining coordinates of the boundary grid point
	for (j=1;j<=(NJ-2);j++)
	{
		//west boundary
		var_coor[0][j][0] = 0.5 * ( CV_corner_coor[0][j][0] + CV_corner_coor[0][j-1][0] );
		var_coor[1][j][0] = 0.5 * ( CV_corner_coor[1][j][0] + CV_corner_coor[1][j-1][0] );
		
		//east boundary
		var_coor[0][j][NI-1] = 0.5 * ( CV_corner_coor[0][j][NI-2] + CV_corner_coor[0][j-1][NI-2] );
		var_coor[1][j][NI-1] = 0.5 * ( CV_corner_coor[1][j][NI-2] + CV_corner_coor[1][j-1][NI-2] );		
	}

	for (i = 1; i <=(NI-2); i++)
	{
		//north boundary
		var_coor[0][NJ-1][i] = 0.5 * ( CV_corner_coor[0][NJ-2][i] + CV_corner_coor[0][NJ-2][i-1] );
		var_coor[1][NJ-1][i] = 0.5 * ( CV_corner_coor[1][NJ-2][i] + CV_corner_coor[1][NJ-2][i-1] );
				
		//south boundary
		var_coor[0][0][i] = 0.5 * ( CV_corner_coor[0][0][i] + CV_corner_coor[0][0][i-1] );
		var_coor[1][0][i] = 0.5 * ( CV_corner_coor[1][0][i] + CV_corner_coor[1][0][i-1] );		
	}

	var_coor[0][0][0] = CV_corner_coor[0][0][0];
	var_coor[1][0][0] = CV_corner_coor[1][0][0];

	var_coor[0][0][NI-1] = CV_corner_coor[0][0][NI-2];
	var_coor[1][0][NI-1] = CV_corner_coor[1][0][NI-2];

	var_coor[0][NJ-1][0] = CV_corner_coor[0][NJ-2][0];
	var_coor[1][NJ-1][0] = CV_corner_coor[1][NJ-2][0];

	var_coor[0][NJ-1][NI-1] = CV_corner_coor[0][NJ-2][NI-2];
	var_coor[1][NJ-1][NI-1] = CV_corner_coor[1][NJ-2][NI-2];

// ******************************* 
 
 Write_Mesh();
 
// *******************************
 
// Distance of sides of CV
 for(j=1;j<NJ-1;j++)
 {
   for(i=1;i<NI-1;i++)
     {
     dist_corner[0][j][i] = sqrt( pow((CV_corner_coor[0][j][i-1]-CV_corner_coor[0][j-1][i-1]),2) + pow((CV_corner_coor[1][j][i-1]-CV_corner_coor[1][j-1][i-1]),2) );
     dist_corner[1][j][i] = sqrt( pow((CV_corner_coor[0][j-1][i]-CV_corner_coor[0][j-1][i-1]),2) + pow((CV_corner_coor[1][j-1][i]-CV_corner_coor[1][j-1][i-1]),2) );
	
     dist_corner[2][j][i] = sqrt( pow((CV_corner_coor[0][j][i]-CV_corner_coor[0][j-1][i]),2) + pow((CV_corner_coor[1][j][i]-CV_corner_coor[1][j-1][i]),2) );
     dist_corner[3][j][i] = sqrt( pow((CV_corner_coor[0][j][i]-CV_corner_coor[0][j][i-1]),2) + pow((CV_corner_coor[1][j][i]-CV_corner_coor[1][j][i-1]),2) );
     }
 }


// Distance between grid points of neighbouring CV
 for(j=1;j<NJ-1;j++)
 {
   for(i=1;i<NI-1;i++)
     {
	dist_GP[0][j][i] = sqrt( pow((var_coor[0][j][i]-var_coor[0][j][i-1]),2) + pow((var_coor[1][j][i]-var_coor[1][j][i-1]),2) );
	dist_GP[1][j][i] = sqrt( pow((var_coor[0][j][i]-var_coor[0][j-1][i]),2) + pow((var_coor[1][j][i]-var_coor[1][j-1][i]),2) );
	
	dist_GP[2][j][i] = sqrt( pow((var_coor[0][j][i]-var_coor[0][j][i+1]),2) + pow((var_coor[1][j][i]-var_coor[1][j][i+1]),2) );
	dist_GP[3][j][i] = sqrt( pow((var_coor[0][j][i]-var_coor[0][j+1][i]),2) + pow((var_coor[1][j][i]-var_coor[1][j+1][i]),2) );
     }
 }


// Surface Area Calculation
 for(j=1;j<NJ-1;j++)
 {
   for(i=1;i<NI-1;i++)
     {
	  delS_xe[j][i] = CV_corner_coor[1][j][i] - CV_corner_coor[1][j-1][i] ;
	  delS_ye[j][i] = CV_corner_coor[0][j-1][i] - CV_corner_coor[0][j][i] ; 
	  
	  delS_xn[j][i] = -1*(CV_corner_coor[1][j][i] - CV_corner_coor[1][j][i-1]); 	  
	  delS_yn[j][i] = CV_corner_coor[0][j][i] - CV_corner_coor[0][j][i-1] ;
	  
	  delS_xw[j][i] = CV_corner_coor[1][j][i-1] - CV_corner_coor[1][j-1][i-1] ;	  
	  delS_yw[j][i] = -1*(CV_corner_coor[0][j][i-1] - CV_corner_coor[0][j-1][i-1]);  
	  
	  delS_xs[j][i] = CV_corner_coor[1][j-1][i-1] - CV_corner_coor[1][j-1][i] ;
	  delS_ys[j][i] = CV_corner_coor[0][j-1][i] - CV_corner_coor[0][j-1][i-1] ;
	  
// East	  
	  C_theta_sx = ( var_coor[0][j][i+1] - var_coor[0][j][i] )/dist_GP[2][j][i];
	  C_theta_sy = ( var_coor[1][j][i+1] - var_coor[1][j][i] )/dist_GP[2][j][i];
	  C_theta_tx = ( CV_corner_coor[0][j][i] - CV_corner_coor[0][j-1][i] )/dist_corner[2][j][i];
	  C_theta_ty = ( CV_corner_coor[1][j][i] - CV_corner_coor[1][j-1][i] )/dist_corner[2][j][i]; 
	  
	  delS_se[j][i]= ( delS_xe[j][i]*C_theta_ty - delS_ye[j][i]*C_theta_tx )/( C_theta_sx*C_theta_ty - C_theta_sy*C_theta_tx );
	  delS_te[j][i]= -1*( delS_xe[j][i]*C_theta_sy - delS_ye[j][i]*C_theta_sx )/( C_theta_sx*C_theta_ty - C_theta_sy*C_theta_tx );
	  	  
// North	  
	  C_theta_sx = ( var_coor[0][j+1][i] - var_coor[0][j][i] )/dist_GP[3][j][i];
	  C_theta_sy = ( var_coor[1][j+1][i] - var_coor[1][j][i] )/dist_GP[3][j][i];
	  C_theta_tx = ( CV_corner_coor[0][j][i] - CV_corner_coor[0][j][i-1] )/dist_corner[3][j][i];
	  C_theta_ty = ( CV_corner_coor[1][j][i] - CV_corner_coor[1][j][i-1] )/dist_corner[3][j][i];

	  delS_sn[j][i] = ( delS_xn[j][i]*C_theta_ty - delS_yn[j][i]*C_theta_tx )/( C_theta_sx*C_theta_ty - C_theta_sy*C_theta_tx );
	  delS_tn[j][i] = -1*( delS_xn[j][i]*C_theta_sy - delS_yn[j][i]*C_theta_sx )/( C_theta_sx*C_theta_ty - C_theta_sy*C_theta_tx ); 



	   if(i>1)
	   {
	    delS_sw[j][i]=delS_se[j][i-1];
	    delS_tw[j][i]=delS_te[j][i-1];
	   }
	   if(i==1)
	   {
	    delS_sw[j][i]=delS_se[j][i];
	    delS_tw[j][i]=delS_te[j][i];
	   } 
	   

	   if(j>1)
	   {
	    delS_ss[j][i]=delS_sn[j-1][i];
	    delS_ts[j][i]=delS_tn[j-1][i];
	   }
	   if(j==1)
	   {
	    delS_ss[j][i]=delS_sn[j][i];
	    delS_ts[j][i]=delS_tn[j][i];
	   }

	  surf_area[0][j][i] = -1*sqrt( pow(delS_sw[j][i],2) + pow(delS_tw[j][i],2) );
	  surf_area[1][j][i] = -1*sqrt( pow(delS_ss[j][i],2) + pow(delS_ts[j][i],2) );
	  surf_area[2][j][i] = sqrt( pow(delS_se[j][i],2) + pow(delS_te[j][i],2) );
	  surf_area[3][j][i] = sqrt( pow(delS_sn[j][i],2) + pow(delS_tn[j][i],2) );
     
    }
 }

// Volume of CV
 for(j=1;j<NJ-1;j++)
 {
   for(i=1;i<NI-1;i++)
     {
           
      diagonal1[j][i] = sqrt( pow((CV_corner_coor[0][j][i]-CV_corner_coor[0][j-1][i-1]),2) + pow((CV_corner_coor[1][j][i]-CV_corner_coor[1][j-1][i-1]),2) );
      diagonal2[j][i] = sqrt( pow((CV_corner_coor[0][j][i-1]-CV_corner_coor[0][j-1][i]),2) + pow((CV_corner_coor[1][j][i-1]-CV_corner_coor[1][j-1][i]),2) );
    
      secondterm[j][i] =  ( pow(dist_corner[2][j][i],2) + pow(dist_corner[0][j][i],2) - pow(dist_corner[3][j][i],2) - pow(dist_corner[1][j][i],2) ); 

      VOL[j][i] = 0.25 * sqrt(  ( 4*pow(diagonal1[j][i],2)*pow(diagonal2[j][i],2) ) - pow(secondterm[j][i],2) ); 
          
     }
 }
 
 
 
} 
