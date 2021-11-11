#include <stdio.h>
#define DUZINA 20
#define MAX_KOOR 10


int main() {
	int n, niz1[MAX_KOOR], niz2[MAX_KOOR];
	int a, b, i, j, k;
	char ksistem[DUZINA][DUZINA];

	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if (n>10 || n<=0)
		{
			printf("Pogresan unos\n");
		}
	}while(n>10 || n<=0);
	
	for (i=0; i<n; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a, &b);
		if ((a<0||a>19)||(b<0||b>19))
		{
			printf("Pogresan unos\n");
			i--;
		}
		else
		{
			niz1[i]=a;
			niz2[i]=b;
		}
	}
	
	for (i=0; i<DUZINA; i++)
	{
		for (j=0; j<DUZINA; j++)
		{
			ksistem[i][j]=' ';
		}
	}
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<DUZINA; j++)
		{
			for(k=0; k<DUZINA; k++)
			{
				if((j==niz2[i])&&(k==niz1[i]))
				{
					ksistem[j][k]='*';
				}
			}
		}
	}
	
	for(i=0; i<DUZINA; i++)
	{
		for (j=0; j<DUZINA; j++)
		{
			printf("%c", ksistem[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
