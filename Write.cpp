void Write_Mesh()
{
	ofstream file1;
	file1.open("Mesh/Mesh.dat");
	file1<<"VARIABLES = "<<"X"<<" "<<"Y"<<endl;
	file1<<"ZONE"<<" "<<"I = "<<NI<<","<<" J = "<<NJ<<","<<" F = POINT"<<endl;

	for(j=0;j<NJ;j++)
	{
	   for(i=0;i<NI;i++)
	     {
		file1<<var_coor[0][j][i]<<" "<<var_coor[1][j][i]<<endl;
	     }
	}
	file1.close();
	
	cout<<"Mesh Generation is Completed"<<endl;
}


void Write_File()
{
	int aa;
	char ch[20];

	char str_interface[80];

	aa = sprintf (ch, "%d",N_iter/Save_Interval);
			
	strcpy (str_interface,"FRAME/P");
	strcat (str_interface,ch);
	strcat (str_interface,".dat");

	ofstream file1(str_interface); 
	file1<<"VARIABLES = "<<"X"<<" "<<"Y"<<" "<<"P"<<" "<<"U"<<" "<<"V"<<" "<<"PHI_CC1"<<" "<<"PHI_CC2"<<" "<<"PHI_MAIN"<<endl;
	file1<<"ZONE"<<" "<<"I = "<<NI<<","<<" J = "<<NJ<<","<<" F = POINT"<<endl;

	for(j=0;j<NJ;j++)
	{
		for(i=0;i<NI;i++) 
		{
		file1<<var_coor[0][j][i]<<" "<<var_coor[1][j][i]<<" "<<P[j][i]<<" "<<U[j][i]<<" "<<V[j][i]<<" "<<PHI_CC[0][j][i]<<" "<<PHI_CC[1][j][i]<<" "<<PHI_MAIN[j][i]<<endl;
		}
	}

	file1.close();
	
}


void Write_Mass_Error()
{
		ofstream file2;
		if(times==0)
		{
			file2.open("MassError/ME.dat");
			file2<<"Time"<<"\t"<<"MassError %"<<endl;
		}
		else
		{
			file2.open("MassError/ME.dat",ios::app);
		}	
   
	        file2<<times<<"\t"<<MassError<<endl;
	        
              	file2.close();
}






