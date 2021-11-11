#include <stdio.h>

int main() {
	int k,l,n;
	do {
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n>50 || n<=0) {printf("Pogresan unos\n");}
	}
	while(n>50 || n<=0);
	if(n==1) {
		for(k=0;k<3*n;k++) {
			printf("*");
		}
	}
	else {
		for(k=0;k<n;k++) {
			for(l=0;l<4*n-3;l++) {
				if(k==l || (k+l==2*n-2) || (l-k==2*n-2) || (k+l==4*n-4))
				printf("*");
				else printf(" ");
			}
			printf("\n");
		}
		return 0;
	}
}
