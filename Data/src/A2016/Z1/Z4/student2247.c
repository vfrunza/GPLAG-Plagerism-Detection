#include <stdio.h>
int main() {
	int n, i, j;
	opet:
	printf("\nUnesite broj n: ");
	scanf("%d", &n);
	if (n<1 || n>50) {
		printf("Pogresan unos");
		goto opet;
	}
	if(n>1) {
	for(i=0; i<n; i++) {
		for(j=0; j<n*3+n-3; j++) {
			if(i==j || j==n*2-i-2 || i==j-n*2+2 || j==n*2-i-2+2*n-2) 
			{printf("*");}
			else
			{printf(" ");}
		}
		printf("\n");
	}
	}
	else if(n==1) printf("***");
				   
	return 0;
}
