#include <stdio.h>

int main() {
	int  n, i, j;
	while(0==0)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n>0 && n<=50) break;
		else printf("Pogresan unos\n");
	}
	if(n==1)
	{
		for(i=0; i<1; i++)
			for(j=0; j<3; j++)
			printf("*");
	}
	else {
	for(i=0; i<n; i++)
	{
		for(j=0; j<4*n-3; j++)
		{
			if(i==j || i+j==(4*n-3)/2 || j-i==(4*n-3)/2 || i+j==(4*n-3)-1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	}
	return 0;
}
