#include <stdio.h>
#include <math.h>

int daj_prost()
{
	static int x = 2; 
	int broj_koji_saljemo;
	int prost;
	do
	{
		int i;
		prost = 1;
		for(i = 2; i*i <= x; ++i)
			{
				if(x%i==0)
			{
				prost=0;
				break;
			}
		
		}
		broj_koji_saljemo = x++;
	}
	while(!prost);
	return broj_koji_saljemo;
}	

int main() {
	
	int a, b, i, suma = 0;
	int broj;
	do 
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a <= 0)
		{
			printf("A nije prirodan broj.\n");
		}
		else if(a >= b)
		{
			printf("A nije manje od B.\n");
		}
	}
	while(a <= 0 || a >= b);
	
	for(i=0; i < b; i++)
	{
		broj = daj_prost();
		if(broj > a && broj < b)
		{
			suma += broj;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
