#include <stdio.h>

int suma_cifara(int broj)
{
	int suma = 0, a;
	if(broj < 0) broj = -broj;
	while(broj)
	{
		a = broj % 10;
		broj = broj/10;
		suma += a;
	}
	return suma;
}

void ubaci_sumu(int *niz, int vel, int indeks)
{
	int i;
	for(i = vel; i>indeks; --i)
	{
		niz[i] = niz[i-1];
	}
	niz[indeks+1] = suma_cifara(niz[indeks]);
	
}

void ubaci(int *niz, int vel)
{
	int i;
	int v = vel;
	for(i = 0; i < 2 * vel; i+=2)
	{
		ubaci_sumu(niz, v, i);
		v++;
	}
}

int JeLiFib0(int n)
{
	int fibo1=1;
	int fibo2=1;
	int temp;

	while(fibo2 < n)
	{
		temp = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = temp;
	}
	
	if(fibo2 == n) return 1;
	return 0;
	
}

int izbaci(int *niz, int vel)
{
	int i,j;
	
	for(i = 0; i < vel; i++)
	{
		if(JeLiFib0(niz[i]))
		{
			for(j = i; j < vel-1; j++)
			{
				niz[j] = niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}
int main() {
	
	int niz[20], i, m;
	int x = 10;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < 10; i++)
	{
		scanf("%d ", &niz[i]);
	}
	
	ubaci(niz, x);
	m = izbaci(niz, 2*x);
	
	printf("Modificirani niz glasi: ");
	for(i = 0; i < m; i++)
	{
		if(i != m-1) printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	}
	
	return 0;
}
