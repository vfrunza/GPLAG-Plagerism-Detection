#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int n)
{
	int i;
	double broj;
	for(i=0;i<n;i++) 
	{
		broj=round(niz[i]*10)/10;
		niz[i]=broj;
	}
}

void preslozi(float niz[], int n, int k)
{
	
	int i,j,brojac1=0,broj,suma;
	double temp;
	zaokruzi1(niz,n);
	for(i=0;i<n;i++)
	{
		suma=0;
		for(broj=niz[i]*10;broj!=0;broj/=10) suma+=fabs(broj%10);
	    if(suma>=k) 
		{
			if(i!=brojac1) /*Ako se broj cija je suma cifara veca od datog k ne nalazi na mjestu gdje se treba nalaziti, pomjerimo ga na to mjesto i sve ostale elemente za jedno mjesto u desno */
			{
				temp=niz[brojac1];
				niz[brojac1]=niz[i];
				for(j=i;j>brojac1;j--) 
				{
					niz[j]=niz[j-1];
				}
				brojac1++;
				niz[brojac1]=temp;
			}
			else brojac1++;
		}
	}
}

int main() 
{
	int i;
	float niz[] = { 3.1, 2.2, 1.1, 7.2, 4.5, 5.6 };
	preslozi(niz, 6, 5);
	printf("Niz glasi: ");
	for (i=0; i<6; i++)
    	printf("%g ", niz[i]);
 	return 0;
}
