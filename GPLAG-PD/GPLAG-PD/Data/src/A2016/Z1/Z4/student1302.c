#include <stdio.h>

int main() {
	/*printf("Zadaća 1, Zadatak 4");*/
	int n,i,j;
	ponovo:
	printf("Unesite broj n: ");
	scanf("%i", &n);
	if(n<1 || n>50) {
		printf("Pogresan unos\n"); 
		goto ponovo;
	}
	if (n==1) printf("***");
	else{
		for (i=0; i<n;i++) {
			for (j=0; j<4*n-3;j++){
				//if(i==0 && j==0) printf("*");
				//if (j==0) printf (" ");
				if(j==i) printf("*");
				else if(j==((n*4-3)/2)-i) printf("*");
				else if(j==((n*4-3)/2)+i) printf("*");
				else if(j==(n*4-4)-i) printf ("*");
				else printf(" ");
			}
		 printf("\n");
		}
	}
	return 0;
}
