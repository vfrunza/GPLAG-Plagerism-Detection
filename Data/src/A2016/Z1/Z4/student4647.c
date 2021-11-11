#include <stdio.h>

int main() {
	int n, i, j;
	a: printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n>50) {printf("Pogresan unos\n"); goto a;}
	else if (n==1) printf("***");
	else{
	for (i=1; i<=n; i++)
	{for (j=1; j<=4*n-3; j++) 
	{if (j==i|| j+i==2*n || j-i==2*n-2 || j+i==4*n-2) printf("*");
	else printf(" ");}
	printf("\n");}}
	return 0;
}
