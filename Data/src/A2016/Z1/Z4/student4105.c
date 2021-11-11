#include <stdio.h>

int main() {
	
	int n, i, j;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while (n<=0 || n>50)
	{
		printf("Pogresan unos");
		printf("\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	for (i=0; i<n; i++)
	{
		for(j=0; j<=4*(n-1); j++)
		{
			if(n==1) printf("***");
			else{
			if((i==j || j==2*n-2-i || j==2*n-2+i || j==4*n-4-i)) printf("*");
			else printf(" ");
		}
		}
		printf("\n");
	}
	return 0;
}