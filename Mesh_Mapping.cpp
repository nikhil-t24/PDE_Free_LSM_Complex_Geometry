void Mesh_Mapping()
{

Dip = 0.12242;
Height = 1.12242 + Dip;
Length = 1;


LY = Height;  
	
	
for(j=0;j<NJ-1;j++)
 {
   for(i=0;i<NI-1;i++)
    {
  	// Coordinates of Computational Domain
  	zeta[j][i] = del_zeta*i;
  	eta[j][i] = del_eta*j;
  	
  	// Coordinates of Physical Domain
  	x[j][i] = Length*zeta[j][i]; // 0;
  	y[j][i] = Height*eta[j][i];  // 0;
    }
  }

		
// Boundary Points for x and y

	// ************************************* 
	for(i=0;i<NI-1;i++)
	{
	  x[0][i] = Length*zeta[0][i];
	  x[NJ-2][i] = Length*zeta[NJ-2][i];

	  y[0][i] = cos(Length*zeta[0][i] -0.5) - 1;
	  y[NJ-2][i] = - cos(Length*zeta[NJ-2][i] -0.5) + 2; 	  
	}	
	

	//**************************************
	
	for(j=0;j<NJ-1;j++)
	{
	  x[j][0] = Length*zeta[j][0];
	  y[j][0] = Height*eta[j][0] - Dip;
	  x[j][NI-2] = Length*zeta[j][NI-2];
	  y[j][NI-2] = Height*eta[j][NI-2] - Dip;
	} 
}


