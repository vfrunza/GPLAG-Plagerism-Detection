#include <stdio.h>

long int daj_prost()
{
	static long broj_poziva=0, prost=0;
	long int i, n;
	
	broj_poziva++;
	
	if(broj_poziva==1) prost=2;
	else if(broj_poziva==2) prost=3;
	else
	{
		/* Odredjivanje sljedeceg prostog broja */
		n=prost;
		do
		{
			n++;
			for(i=2; i<n; i++)
			{
				if(n%i==0) break;
			}
			if(i==n) 
			{
				prost=n;
				break;
			}
		} while(1);
	}
	return prost;
}

int main() 
{
	long int A, B, suma=0, prost_broj=0;
	
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%ld %ld", &A, &B);
		
		if(A>=B) printf("A nije manje od B.\n");
		if(A<1) printf("A nije prirodan broj.\n");
		
	} while(A>=B || A<1);
	
	do
	{
		prost_broj=daj_prost();
		if(prost_broj>A && prost_broj<B) suma+=prost_broj;
	} while(prost_broj<B);
	
	printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", A, B, suma);
	
	return 0;
}
