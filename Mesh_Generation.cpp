void Mesh_Generation(int j_start,int j_end,int i_start,int i_end)
{	
	cout<<"Generating Mesh"<<endl;
	
	double a[NJ][NI],b[NJ][NI],c[NJ][NI],d[NJ][NI],e[NJ][NI];
	double  xnew[NJ][NI],ynew[NJ][NI],x_eta,x_zeta,y_zeta,y_eta;

	for(j=j_start;j<=j_end;j++)
	{ 
	 for(i=i_start;i<=i_end;i++)
	  {
	      x_old[j][i]=x[j][i];         
	      y_old[j][i]=y[j][i];
	  }
	}

	// Finding x and y by using Laplacian Equation 
	maxerror=1.0;
	while(maxerror>1e-10)
	{
		maxerror=0.0;
		for(j=j_start+1;j<j_end;j++)
		{
			for(i=i_start+1;i<i_end;i++)
			{
				x_zeta = (x[j][i+1]-x[j][i-1])/(2*del_zeta);
				y_zeta = (y[j][i+1]-y[j][i-1])/(2*del_zeta);
				
				x_eta = (x[j+1][i]-x[j-1][i])/(2*del_eta);
				y_eta = (y[j+1][i]-y[j-1][i])/(2*del_eta);

				a[j][i] = y_eta*y_eta + x_eta*x_eta;
				b[j][i] = (y_zeta*y_eta + x_zeta*x_eta);   
				c[j][i] = x_zeta*x_zeta + y_zeta*y_zeta;
				d[j][i] = 0.0;
				e[j][i] = 0.0;

				xnew[j][i] = ( a[j][i]/pow(del_zeta,2) - d[j][i]/(2.0*del_zeta) ) * x[j][i-1]   +   
					     ( a[j][i]/pow(del_zeta,2) + d[j][i]/(2.0*del_zeta) ) * x[j][i+1]   + 
					     ( c[j][i]/pow(del_eta,2)  - e[j][i]/(2.0*del_eta) )  * x[j-1][i]   + 
					     ( c[j][i]/pow(del_eta,2)  + e[j][i]/(2.0*del_eta) )  * x[j+1][i]   - 
					     ( 0.5*b[j][i]/(del_zeta*del_eta) ) * (x[j+1][i+1]+x[j-1][i-1]-x[j+1][i-1]-x[j-1][i+1]);
			        
			 	xnew[j][i] = xnew[j][i] * ( 0.5/( a[j][i]/pow(del_zeta,2) + c[j][i]/pow(del_eta,2) ) );		     
				
				
				ynew[j][i] = ( a[j][i]/pow(del_zeta,2) - d[j][i]/(2.0*del_zeta) ) * y[j][i-1] + 
					     ( a[j][i]/pow(del_zeta,2) + d[j][i]/(2.0*del_zeta) ) * y[j][i+1] + 
					     ( c[j][i]/pow(del_eta,2) - e[j][i]/(2.0*del_eta) ) * y[j-1][i] + 
					     ( c[j][i]/pow(del_eta,2) + e[j][i]/(2.0*del_eta) ) * y[j+1][i] - 
					     ( 0.5*b[j][i]/(del_zeta*del_eta) ) * (y[j+1][i+1]+y[j-1][i-1]-y[j+1][i-1]-y[j-1][i+1]);

				ynew[j][i] = ynew[j][i] * ( 0.5/( a[j][i]/pow(del_zeta,2) + c[j][i]/pow(del_eta,2) ) );

				if( fabs(xnew[j][i]-x[j][i]) > maxerror)
				  {
					maxerror=fabs(xnew[j][i]-x[j][i]);
					x[j][i]=xnew[j][i];
				  }	

				if( fabs(ynew[j][i]-y[j][i]) > maxerror)
				  {
					maxerror=fabs(ynew[j][i]-y[j][i]);
					y[j][i]=ynew[j][i];
				  }	
			}
		}	
	}
	
  // write_Mesh();
}



