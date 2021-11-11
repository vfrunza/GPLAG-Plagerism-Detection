#include <stdio.h>

int main() {
	int i, n, j;
poc:	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50) {printf("Pogresan unos\n"); goto poc; }
if(n==1) { printf("***"); }
else {	for(i=0;i<n;i++)
	{
		for(j=0;j<4*n-3;j++)
		{
			if(i==j || j==((n*4-3)/2)-i || j==((n*4-3)/2)+i || j==((n*4-4)-i))
			printf("*");
			else printf(" ");
		}
		printf("\n");
	} }
	return 0;
	
	
}
