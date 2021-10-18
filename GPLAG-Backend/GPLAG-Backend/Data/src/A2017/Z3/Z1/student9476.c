#include <stdio.h>


int dva_od_tri(int* niz1,int duz1,int* niz2,int duz2,int* niz3,int duz3)
{
	
	int i,j,g,k,ibool=1;  

	int* p1=niz1;	int* p2=niz2;	int* p3=niz3; 
	
	int two_of_three=0; 
	
	//Ako se clan niza1 nalazi u niz2, ali ne u niz3 uvecava brojac.
	for(i=0;i<duz1;i++)
	{
		//Ako se vec javio clan niza1 prije, da ne gleda dva puta isti broj
		for(k=0;k<i;k++)
			if(p1[i]==p1[k] && i!=k ){break;}
		
	   	if(k==i)
	   	{
			for(j=0;j<duz2;j++)
				{
				if(p1[i]==p2[j])
					{
						for(g=0;g<duz3;g++)
						if(p3[g]==p2[j]) break;
						
						if(g==duz3)
						{ 
							two_of_three++;
							break;
							
						}
					}
				}
		}
	}


	for(i=0;i<duz2;i++)
	{
		for(k=0;k<i;k++)
			if(p2[i]==p2[k] && i!=k ){ break;}
		
	   	if(k==i)
	   	{
			for(j=0;j<duz3;j++)
				{
				if(p2[i]==p3[j])
					{
						for(g=0;g<duz1;g++)
						if(p1[g]==p3[j]) break;
						
						if(g==duz1)
						{ 
							two_of_three++;
							break;
							
						}
					}
				}
		}
	}


	
		for(i=0;i<duz3;i++)
	{
		for(k=0;k<i;k++)
			if(p3[i]==p3[k] && i!=k ){break;}
		
	   	if(k==i)
	   	{
			for(j=0;j<duz1;j++)
				{
				if(p3[i]==p1[j])
					{
						for(g=0;g<duz2;g++)
						if(p2[g]==p1[j]) break;
						
						if(g==duz2)
						{ 
							two_of_three++;
							break;
							
						}
					}
				}
		}
	}
	
		return two_of_three;
}


int main() {
	

	return 0;
	
}
