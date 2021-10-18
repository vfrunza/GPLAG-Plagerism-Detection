#include <stdio.h>
int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n>50 || n<0) printf("Pogresan unos\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=4*n-2;j++) {
			if (i==1){
				if (j==1 || j==(2*n-1) || j==(4*n-3)) {
					printf("*");
				}
				else printf(" ");
			}
			else {
				if (j<i) printf(" ");
				else if (i==j) printf("*");
				else if (i==2*n-j) printf("*");
				else if (i<2*n-j) printf(" ");
				else if (i==3*n-2 && j==n) printf("*");
				else if (i<3*n-2 && j==n) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
