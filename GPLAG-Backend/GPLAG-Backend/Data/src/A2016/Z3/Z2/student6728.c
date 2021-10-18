#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ubaci(int *niz, int vel)
{
	
	int i,suma = 0,ostatak,pomocni;
	
	for(i = vel-1; i >= 0; i--)
	{
		niz[2*i] = niz[i];
		
	}
	
	for(i = 0; i < 2*vel; i+=2)
	{
		if(niz[i] < 10)
			niz[i+1] = niz[i];
			
		else
			 {	
			 	pomocni = niz[i];
			 	while(pomocni > 0 || pomocni < 0)
			 	{
					ostatak = pomocni%10;
					suma += ostatak;
					pomocni/=10;
			 	}
			 	
			 	niz[i+1] = suma;
			 	
			 	
			 }
			 suma = 0;
	}
}
int izbaci(int *niz,int vel)
{
	int fibskup[50],i,j,k;
	fibskup[0] = 1;
	fibskup[1] = 1;
	
	for(i = 0; i < 48; i++)
	{
		fibskup[i+2] = fibskup[i] + fibskup[i+1];
	}
	for(i = 0 ; i < vel; i++)
	{
		for(j = 0; j < 50; j++)
		{
			if(niz[i] == fibskup[j])
			{
				for(k = i; k < vel-1; k++)
				{
					niz[k] = niz[k+1];
					
				}
				vel--;
				i--;
				break;
			}
		}
	}
	return vel;
}
	







int main()
{
	int niz[20],i,velicina;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &niz[i]);
		
	}
	ubaci(niz,10);
velicina =izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i = 0; i < velicina; i++)
	{
		{
			if(i == velicina - 1)
			printf("%d.",niz[i]);
			
			else printf("%d, ",niz[i]);
		}
	}
	
	return 0;
}

