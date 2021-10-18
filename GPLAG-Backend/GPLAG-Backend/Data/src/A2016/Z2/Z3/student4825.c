#include <stdio.h>

int main() {
	int i, j, k, n, trenutno, x, y;
	char koord[19][19];
	for (i=0;i<=19;i++)
	{
		for (j=0;j<=19;j++)
		{
			koord[i][j]=' ';
		}
	}
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while (n<=0 || n>10) 
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	}
	for (k=0;k<n;k++)
	{	
		trenutno=k;
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d %d", &x, &y);
		if (x<0 || x>19 || y<0 || y>19)
		{
			k=trenutno;
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", k+1);
			scanf("%d %d", &x, &y);
		}
		for (i=0;i<=19;i++)
			for(j=0;j<=19;j++)
				{	
					if (i==y && j==x)
					koord[i][j]='*';
				}
	}
	for (i=0;i<=18;i++)
	{
		for (j=0;j<=18;j++)
		{
			printf("%c", koord[i][j]);
		}
		printf("\n");
	}
	return 0;
}