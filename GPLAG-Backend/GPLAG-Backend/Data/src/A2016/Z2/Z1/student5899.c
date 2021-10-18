#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() 
{
	int broj,nbroj=0,cifra1,cifra2,raz,i=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	broj=abs(broj);
	
	if(broj<10)
	{
		nbroj=0;
		printf("%d",nbroj);
	}
	else
	{
	
	do 
	{
		cifra1=broj%10;
		broj=broj/10;
		if(broj!=0)
		{
		cifra2=broj%10;
		raz=abs(cifra2-cifra1);
		nbroj+=raz*pow(10,i);
		i++;
		}
	}
	while(broj!=0);
	
	printf("%d",nbroj);
	}
	return 0;
}
