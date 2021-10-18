/* Zadaca 3, zadatak 1 */

#include <stdio.h>

int da_li_je_prost(int x)
{
	int i;
	int prost = 1;
	
	for(i=2; i<x; i++)
	{
		if(x%i==0)
		{
			prost=0;
			break;
		}
	}
	return prost;
}

int daj_prost()
{
	static int i = 1;
	int j, provjera;
	
	for(j=2; j<100000; j++)
	{
		i++;
		provjera = i;
	
	if(da_li_je_prost(provjera) == 1) return i;
	else { continue; }
	}
}

int main() 
{
	int A, B, i, suma=0, broj;
	
	do
	{
		printf ("\nUnesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
	
		if(A <= 0 /*|| B <= 0*/) printf ("A nije prirodan broj.");
		else if(B < A || A == B) printf ("A nije manje od B.");
		else
		{
			for(i=0; i<B; i++)
			{
				broj = daj_prost();
				
				if(broj>A && broj<B)
				suma = suma + broj;
			}
		}
	}
	while (A<1 || B<1 || A ==B);
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	
	
	return 0;
}
