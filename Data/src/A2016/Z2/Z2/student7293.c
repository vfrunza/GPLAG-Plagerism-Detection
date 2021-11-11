#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415923

int main() 
{
	int bru,i,stepen,minuta,sekunda=0,j;
	double niz[500], pom=0, broj;
	
	printf("Unesite broj uglova: ");
	scanf ("%d", &bru);
	
	
	for (i=0; i<bru; i++)
	{
		scanf ("%lf", &niz[i]);
	}
	
	
	for (i=0; i<bru; i++)
	{
		broj=niz[i];
		
		
		stepen=broj*(180/PI);
		pom=(broj*(180/PI))-stepen;
		
		minuta=pom*60;
		pom*=60;
		
		pom-=minuta;
		pom*=60;
		
		sekunda=round(pom);
		if(sekunda==60){
			sekunda=0;
			minuta=minuta+1;
			
		} if(minuta==60){
				minuta=0;
				stepen=stepen+1;
			}
			if(sekunda==-60){
				sekunda=0;
				minuta=minuta-1;
			}
			if(minuta==-60){
				minuta=0;
				stepen--;
			}
		
		
		if (sekunda>30 || sekunda <-30)
		{
			if (i==(bru-1))
			{
				bru--;
				i--;
			}
			else
			{
				for (j=i; j<bru; j++)
				{
					niz[j]=niz[j+1];
					bru--;
					i--;
				}	
					
			}
			
		}
	
	}
	
	bru=i;
	
	printf ("Uglovi su:\n");
	for (i=0; i<bru; i++)
	{
		broj=niz[i];
		
		stepen=broj*(180/PI);
		pom=(broj*(180/PI))-stepen;
		
		minuta=pom*60;
		pom*=60;
		
		pom-=minuta;
		pom*=60;
		
		
		sekunda=round(pom);
		if(sekunda==60){
			sekunda=0;
			minuta=minuta+1;
			
		} if(minuta==60){
				minuta=0;
				stepen=stepen+1;
			}
			if(sekunda==-60){
				sekunda=0;
				minuta=minuta-1;
			}
			if(minuta==-60){
				minuta=0;
				stepen--;
			}
		
		
		sekunda=fabs(sekunda);
		minuta=fabs(minuta);
		printf ("%d stepeni %d minuta %d sekundi\n", stepen, minuta,sekunda);
	}
	
	return 0;
}
