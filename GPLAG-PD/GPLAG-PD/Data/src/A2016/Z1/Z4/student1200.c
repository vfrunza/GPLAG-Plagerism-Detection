#include <stdio.h>

int main()
{
	int n,i,j;
	do {
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<1 || n>50) printf("Pogresan unos\n");
	} while(n<1 || n>50);
	if(n!=1)
		for(i=0; i<n; i++) {
			for(j=0; j<4*n; j++) {
				if(i==0 && j==0 || i==0 && j==4*n-4 || i==0 && j==2*n-2) printf("*");
				else if(i==j || j==2*n+i-1-1) printf("*");
				else if(i+j==2*n-2 && i!=n-1 && j<2*n-1) printf("*");
				else if(i+j==4*n-4 && i!=n-1 && j<4*n-1) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	else printf("***");
	return 0;
}
