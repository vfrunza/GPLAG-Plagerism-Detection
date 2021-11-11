#include <stdio.h>
#include <stdlib.h>

int pomocna(int n)
{
	int s = 0;
	
	while(n != 0)
	{
		s += abs (n % 10);
		n = n / 10;
	}
	
	return s;
}

void ubaci(int *niz, int br)
{
	int i = 0, j = 0, suma = 0, n;
	
	n = 2 * br;
	
	for(i = 1; i <= n; i+=2)
	{
		suma = pomocna(niz[i-1]);
		
		for(j = br; j >= i; j--)
			niz[j] = niz[j - 1];
		
		niz[i] = suma;
		br++;
		
		if(br == n)
			return;
	}
}

int fibonacijev(int n)
{
	int prvi = 1, drugi = 1, f;
	
	if(n == 1)
		return 1;
		
	for( ; ; )
	{
		f = prvi + drugi;
		
		if(f == n)
			return 1;
			
		if(f > n)
			return 0;
			
		prvi = drugi;
		drugi = f;
	}
	return 0;
}

int izbaci(int *niz, int br)
{
	int i = 0, j = 0, brojac = 0;
	
	for(i = 0; i < br; i++)
	{
		if(fibonacijev(niz[i]) == 1)
		{
			for(j = i; j < br - 1; j++)
				niz[j] = niz[j + 1];
			
			i--;
			br--;
			brojac++;
		}
	}
	return br;
}

int main() 
{
	/*printf("Zadaća 3, Zadatak 2");*/
	
	int niz[20], i = 0, vel;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i = 0; i < 10; i++)
		scanf("%d", &niz[i]);
		
	ubaci(niz, 10);
	vel = izbaci(niz, 20);
	
	printf("Modificirani niz glasi: ");
	for(i = 0; i < vel - 1; i++)
		printf("%d, ", niz[i]);
	
	if(i == vel - 1)
		printf("%d.", niz[vel-1]);
	
	return 0;
}
