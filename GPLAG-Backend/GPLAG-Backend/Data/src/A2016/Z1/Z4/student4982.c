#include <stdio.h>

int main() {
	int n=0;

while(1)
{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n>0 && n<=50) break;
	printf("Pogresan unos\n");
}

	
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4*n-3;j++)
		{
			if(j==i || j==4*n-4-i || j==(4*n-3)/2+i || j==(4*n-3)/2-i ) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
