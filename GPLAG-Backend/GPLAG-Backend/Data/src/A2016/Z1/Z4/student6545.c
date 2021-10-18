#include <stdio.h>

int main() {
//	printf("Zadaća 1, Zadatak 4");
	int n,i,j,p;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while (n<1 || n>50){
		printf("Pogresan unos \n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	if (n==1) {
		for (i=0; i<n; i++)
			for (j=0; j<2*n+1; j++)
				if (i==j || i+j==n || i+j==2*n)
				printf ("*");
				else 
				printf (" ");
	}
	if (n>1){
	p=2*n-2;
	for (i=0; i<n; i++){
		for(j=0; j<2*p+1; j++)
			if(i==j || i+j==p || j-i==p || i+j==2*p)
			printf("*");
			else 
			printf(" ");
	printf("\n");
	}
	}
	return 0;
}
