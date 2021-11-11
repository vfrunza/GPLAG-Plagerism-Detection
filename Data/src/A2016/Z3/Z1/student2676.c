#include <stdio.h>

int daj_prost()
{
	static int broj=1;
	broj++;
	int prost, i;
	do
	{
		// Provjeravanje da li je broj prost, ako nije provjeravamo za slijedeci
		prost=1;
		for(i=2;i<broj;i++)
		{
			if(broj%i==0) prost=0;
		}
		if(prost) return broj; else broj++;
	} while(!prost);
}

int main() 
{
	int brA, brB, i, suma=0, prost;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &brA, &brB);
		if(brA>=brB) printf("A nije manje od B.\n");
		else if(brA<1) printf("A nije prirodan broj.\n");
		else if(brB<1) printf("B nije prirodan broj.\n");
	} while(brA<1 || brB<1 || brA>=brB);
	
	prost=daj_prost();
	
	for(i=brA+1;i<brB;i++)
	{
		do
		{
			if(prost==i) 
			{
				suma+=prost;
				break;
			}
			else if(prost<i) prost=daj_prost();
			if(prost==i) suma+=prost;
		} while(prost<i);
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", brA, brB, suma);
	
	return 0;
}
