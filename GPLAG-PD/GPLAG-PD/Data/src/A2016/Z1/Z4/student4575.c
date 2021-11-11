#include <stdio.h>

int main() {
	int n, j, i, h=0;
	do {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if (n<=0 || n>50)
	printf("Pogresan unos \n");}
	while (n<=0 || n>50);
	if (n==1)
	printf("***");
	else if (n>=2 && n<=50)
	h=n*3+(n-3);
	for(i=0;i<n;i++)
	{
		for(j=0;j<h;j++) {
		if (j<n && j==i)
		printf("*");
		else if (j<=h/2 && i+j==h/2)
		printf("*");
		else if (j<h-n && j-i==h/2)
		printf("*");
		else if (h-j-1==i)
		printf("*");
		else
		printf(" ");
	}
	printf("\n");
	}
	return 0;
}
