#include <stdio.h>

int main() {
	int n, i, j;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while (n<=0 || n>50) {
			printf("Pogresan unos");
			printf("\nUnesite broj n: ");
			scanf ("%d", &n); }
	if (n==1) printf("***");
	else{
	for (i=0; i<=n-1; i++) {
		for(j=0; j<=4*n; j++) {
			if (i==j || j==2*(n-1)+i || i+j==2*(n-1) || i+j==4*(n-1))
				printf ("*");
			else 
				printf (" ");}
		printf("\n");}
	}		
	return 0;
}
