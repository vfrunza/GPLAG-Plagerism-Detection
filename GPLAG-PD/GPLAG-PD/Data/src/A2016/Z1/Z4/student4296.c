#include <stdio.h>
int main() {
	int i,j,n;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if (n<=0 || n>50)
		printf("Pogresan unos\n");
	}while (n<=0 || n>50);
	if(n==1)
		printf ("***");
	else {
		for(i = 0; i < n; i++){
			for(j = 0; j < 4*n-3; j++)
			{
				if (i == j || i == 2*(n-1)-j || i == j-2*(n-1) || i == 4*n-4-j)
				printf("*");
				else printf(" ");
			}
		printf("\n");
		}
	}
	return 0;
}
