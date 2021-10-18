#include <stdio.h>

int main() {
	int n=0,i=0, j=0, k=0, p=1;
	while(n<=0 || n>50) {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if (n<=0 || n>50) {printf("Pogresan unos\n");}
	}
	
	k=2*n-5; p=1;
	if (n==1) printf("***");
	else{
	for(j=0; j<n; j++) {
		if(j==0) {
			printf("*");
			for(i=0;i<2*n-3;i++) printf(" ");
			printf("*");
			for(i=0;i<2*n-3;i++) printf(" ");
			printf("*");
		}
		else if(j==n-1) {
			for(i=0;i<n-1;i++) printf(" ");
			printf("*");
			for(i=0;i<2*n-3;i++) printf(" ");
			printf("*");
			for(i=0;i<n-1;i++) printf(" ");
		}
		else {
			for(i=0;i<j;i++) printf(" ");
			printf("*");
			for(i=0;i<k;i++) printf(" ");
			printf("*");
			for(i=0;i<p;i++) printf(" ");
			printf("*");
			for(i=0;i<k;i++) printf(" ");
			printf("*");
			for(i=0;i<j;i++) printf(" ");
			k-=2; p+=2;
		}
		printf("\n");
	}
}	
	return 0;
}
