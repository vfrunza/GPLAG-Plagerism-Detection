#include <stdio.h>

int main() {
	int n, i, j;
	do {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n>50 || n<=0)
		printf("Pogresan unos\n");
	}
	while(n>50 || n<=0 );
	if(n==1)
	printf("***");
	else
	{
	for(i=0; i<n; i++)
	{
		for(j=0; j<=(n+n+n+n-4); j++)
		{
		if(i==j || (j==2*n-2 && i==0) || (j==4*n-4 && i==0) || j==2*n-2+i || j==2*n-2-i || j==4*n-4-i )
		printf("*");
		else
		printf(" ");
		}
		printf("\n");
	}
	}
	return 0;
}
