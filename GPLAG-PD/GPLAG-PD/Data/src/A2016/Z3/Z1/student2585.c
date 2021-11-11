#include <stdio.h>

int daj_prost()
{
	int brojac=0,i;
	static int prost, x=1;
	int jeste_prost=0;
	while (jeste_prost==0)
	{
		brojac=0;
		x++; 
		
		if (x==2) 
		{
			prost=2;
			return prost;
		}
		
		if (x==3) 
		{
			prost=3;
			return prost;
		}
		
		for (i=1; i<=x; i++)
		{
			if(x%i==0) brojac++; //ako je broj djeljiv sa i, povecavamo brojac za 1 
		}
		
		if(brojac==2) 
			{
				jeste_prost=1; //ako je broj prost, dodjeljujemo vrijednost 1 
				prost=x;
			}
	}
return prost;
    }

int main() {
	
	int A, B; 
	int x, i;
	int suma=0; //pocetna vrijednost sume je nula jer cemo na nju dodavati proste brojeve 
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
		if(A<=0) 
		{
			printf("A nije prirodan broj.\n");
			continue;
		}		
		
		if(A>=B) 
		{
			printf("A nije manje od B.\n");
			continue;
		}
		
		if(B<=0) 
		{
			printf("B nije prirodan broj.\n");
			continue;
		}

	} while(A<=0 || B<=0 || A>=B);
	
	for (i=0; i<=B; i++)
	{
		x=daj_prost();  //poziva se funkcija daj_prost 
		if (x>=B) break; //broj ne smije biti veći od B
		if(x>A)
	{

	suma=suma+x; //na sumu se dodaje svaki naredni prost broj 
	}

	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
