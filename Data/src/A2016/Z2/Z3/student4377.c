#include <stdio.h>

int main() 
{
	int t[20][20] = {{0}, {0}}, i, n, niz1, niz2;
	
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n <=0 || n>10)
		{
			printf("Pogresan unos\n");
		}
	}
	while(n <=0 || n>10);
	
	
	for(i=0; i<n; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d", &niz1);
		scanf("%d", &niz2);
		if(niz1 >= 20 || niz1 < 0 || niz2 >= 20 || niz2 < 0)
		{
			printf("Pogresan unos\n");
			i--;
		}
		else
		{
			t[niz1][niz2]++;
		}
	}
	
	for(i=0; i<20; i++)
	{
		for(n=0; n<20; n++)
		{
			if(t[n][i] == 0)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}
