#include <stdio.h>

int daj_prost()
{
	int i;
	int brojac=0;
	static int x = 2;
	
	while(1)
	{
		brojac = 0;
		for(i=1;i<=x;i++)
		{
			if(x%i==0) brojac++; 
			
		}
		
		if(brojac==2) break; /*Broj je prost ako je djeljiv sa 1 i sa samim sobom*/
		
		x++;
	
	}

	
	x++; /*Da ne uzima uvijek isti broj*/
	return x- 1;
}

int main()
{
	int A,B;
	int suma=0;
	
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<=0) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
		else if(B<=0) printf("B nije prirodan broj.\n");
		
	}while(A<=0 || B<=0 || A>=B);
	
	int x; 
	do {
		x = daj_prost(); /*Pozivamo funkciju*/
		if (x>A&&x<B) suma+=x; /*Ako datom intervalu, racunamo sumu prostih*/
	} while (x < B);
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d." , A,B,suma);
	return 0;
}