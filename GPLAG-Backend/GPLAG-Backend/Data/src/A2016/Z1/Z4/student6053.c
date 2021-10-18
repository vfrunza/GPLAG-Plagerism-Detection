#include <stdio.h>

int main() {
	int n;
	int i,j;
	printf("Unesite broj n: ");
	scanf ("%d", &n);
	if(n>50){
	printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	}
	if (n<0){
	printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	}
	if (n==1) {
		printf("***");
		return 0;
	}
	if (n==0) {
		printf ("Pogresan unos");
		printf("\n");
		printf("Unesite broj n: ");
		scanf ("%d", &n);
		if(n<0){
			printf ("Pogresan unos\n");
			printf("Unesite broj n: ");
			scanf("%d", &n);
		}
		if (n>50) {
			printf ("Pogresan unos\n");
			printf("Unesite broj n: ");
			scanf ("%d", n);
		}
		if (n==1) {
			printf("***");
			return 0;
		}
	}
	for (i=0; i<n; i++ ){
		for(j=0; j<4*n-3;j++){
			if(i==j || i==2*n-2-j || j==2*n-2+i || i==4*n-4-j )
			printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	
	return 0;
}
