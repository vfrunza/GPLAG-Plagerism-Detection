#include <stdio.h>

int main() {
	int i,j,n=0;
	while (n<1 || n>50) {
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if (n<1 || n>50) printf("Pogresan unos\n");
		if (n==1) {printf("***"); return 0;}
	}
	for (i=0;i<n;i++) {
		for(j=0;j<n*4-3;j++) {
			if (i==j || (j==((n-1)*2)-i) || (j==((n-1)*2)+i) || (j==((n-1)*4)-i)) printf("*"); else printf(" ");
		} printf("\n");
	}
	
	return 0;
}
