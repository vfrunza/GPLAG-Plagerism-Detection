#include <stdio.h>
#include <math.h>
int main() 
{
	int i, br, brc, c1, c2, rez, pom;
	brc=0;
	printf ("Unesite broj: ");
	scanf ("%d", &br);
	
	pom=br;
	
	while (pom != 0)
	{
		brc++;
		pom = pom / 10;
		}
	i = 1;
	
	while (br != 0 && i < brc)
	{
			c1 = br % 10;
			br = br / 10;
			c2 = br % 10;
			rez  = (c2 - c1);
			
			if (rez < 0) 
			{
				rez =- rez;
			}
			if (i == 1)
			{
				pom = rez;
			}
			else 
			{
				pom = pom + (rez*pow(10,i-1));
			}
			i++;
		}
	
	printf ("%d", pom);
	
	return 0;
}
