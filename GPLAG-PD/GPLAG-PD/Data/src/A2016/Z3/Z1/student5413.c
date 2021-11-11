#include <stdio.h>

int iz_it_prost(int n)
{
	int i;
	for(i = 2; i < n; i++)
	{
		if(n%i == 0)
		  return 0;
	}
	return 1;
}

int prost_po_redu(int n)
{
	int i, br = 0;
	for(i = 2; i <= n; i++)
	{
		if(iz_it_prost(i) == 1)
		  br++;
	}
	return br;
}

int daj_prost()
{
	static int x = 2;
	
	while(iz_it_prost(x) == 0)
	{
		x++;
	}
	x++;
	return x - 1;
}

int main() 
{
	int a, b, suma = 0;
	int i, k, preskoci, x = 0;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a <= 0)
		  printf("A nije prirodan broj.\n");
		else if(a >= b)
		  printf("A nije manje od B.\n");
		
	}while(a <= 0 || a >= b);
	
	for(i = a + 1 ; i < b; i++)
	{
		if(iz_it_prost(i) == 1 && x == 0)
		{
			preskoci = prost_po_redu(i);
			for(k = 1; k < preskoci; k++)
			  daj_prost();
			x = 1;
		}
		if(iz_it_prost(i) == 1)
		{
			suma += daj_prost();
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
