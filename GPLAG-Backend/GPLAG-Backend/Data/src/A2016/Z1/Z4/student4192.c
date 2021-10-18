#include <stdio.h>

int main() {
	int n,i,j;
	for(;;)
	{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n>0 && n<=50) break;
		if(n<=0||n>50) printf("Pogresan unos\n");
	}
	if(n==1)
	{
		for(i=0;i<2;i++)
		printf("*");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<4*n-3;j++)
		{
			if(i==j || (i+j)==((4*n-3)/2) || (j-i)==((4*n-3)/2) || i+j==4*n-4) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
