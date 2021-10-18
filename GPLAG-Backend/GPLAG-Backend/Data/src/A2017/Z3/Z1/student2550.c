#include <stdio.h>
#include <math.h>
int dva_od_tri(int niz1[], int x, int niz2[], int y, int niz3[], int z)
	{
		int i,j,k,brojac=0,p=0,b=0;
		for(i=0;i<x;i++)
			{
				
				for(j=0;j<y;j++)
					{
						p=0;
						
						if(niz1[i]==niz2[j])
						{
							p=1;
							b=1;
							
							
						}
						if(niz1[i]!=niz2[j])
							p=0;
						for(k=0;k<z;k++)
							{
								if(niz1[i]==niz3[k] && p==1)
									p=0;
								
								else if(niz1[i]==niz3[k] && p==0)
									p=1;
								if(niz2[j]==niz3[k] && b==1)
									b=0;
							}
							if(p==1)
								brojac++;
					
							if(b==1)
								brojac++;
					}
				
			}
			return brojac;
			
	}
int main() {
int niz1[] = {1, 2, 3, 5};
int niz2[] = {1, 2, 4, 6, 7};
int niz3[] = {1, 3, 4, 8, 9, 10};
	int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
	return 0;
}
