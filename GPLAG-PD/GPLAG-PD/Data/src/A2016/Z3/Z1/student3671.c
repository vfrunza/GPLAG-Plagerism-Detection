#include <stdio.h>

int daj_prost(){
	static int x=1;
	int prost,i;
	prost=1;
	x++; /* mora se povecavati promjenjiva x zbog toga sto promjenjiva static ce imati istu vrijednost ukoliko je ne povecamo */
	do
	{	
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				prost=0;
				break;
			}
			else prost=1;
		}	
		x++;
	}while(prost==0);
	x--;
	return x;
}

int main() {
	int a,b;
	int suma=0;
	int broj;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
		printf("A nije prirodan broj.\n");
		if(a>=b)
		printf("A nije manje od B.\n");
	}while((a<=0) || (a>=b));

	broj=1;
	while(broj<b)
	{
		broj=daj_prost(); 
		if(broj>a && broj<b)
		{
			suma+=broj;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
