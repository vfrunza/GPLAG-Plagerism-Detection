#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<1 || n>50) {
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
	}
	if(n==1)
		printf("***");
	else {	
		for(i=0;i<n;i++) {
			for(j=0;j<4*n-1;j++) {
				if(i==j || (i+j)==(2*n-2) || (i+2*(n-1))==j || (i+j)==(4*n-4))
					printf("*");
				else
					printf(" ");
			}
			if(i!=n-1)
				printf("\n");
		}
	}
	return 0;
}