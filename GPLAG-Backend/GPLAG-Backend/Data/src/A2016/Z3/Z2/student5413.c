#include <stdio.h>
#include <math.h>

int suma(int n)
{
	int E = 0;
	while(n != 0)
	{
		E += n%10;
		n /= 10;
	}
	return fabs(E);
}

void ubaci(int niz[], int x)
{
	int i, k;
	
	for(i = 0; i < x; i++)
	{
		for(k = x; k > i; k--)
		{
			niz[k] = niz[k - 1];
		}
		niz[i + 1] = suma(niz[i]);
		x++;
		i++;
	}
}

int Fibonacci(int n)
{
	int Fi[100], i;
	if(n == 1)
	  return 1;
	
	Fi[0] = 1;
	Fi[1] = 1;
	for(i = 2; i <= n; i++)
	{
		Fi[i] = Fi[i - 1] + Fi[i - 2];
		if(Fi[i] == n)
		  return 1;
		else if(Fi[i] > n)
		  break;
	}
	return 0;
}

int izbaci(int niz[], int x)
{
	int i, k;
	for(i = 0; i < x; i++)
	{
		if(Fibonacci(niz[i]) == 1)
		{
			for(k = i + 1; k < x; k++)
			{
				if(k == i + 1)
				{
					niz[i] = niz[k];
				  	niz[k] = niz[k + 1];	
				}
				else if(k < x - 1)
				  niz[k] = niz[k + 1];
			}
			x--;
			i--;
		}
	}
	return x;
}

int main() 
{
	int niz[20], i, x;
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz, 10);
	x = izbaci(niz, 20);
	
	printf("Modificirani niz glasi: ");
	for(i = 0; i < x; i++)
	{
		if(i == x - 1)
		  printf("%d.", niz[i]);
		else
		  printf("%d, ", niz[i]);
	}
	return 0;
}
