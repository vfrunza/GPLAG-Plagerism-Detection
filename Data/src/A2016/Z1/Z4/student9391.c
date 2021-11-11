#include <stdio.h>
#include <math.h>
int main() {
	int n,i,j,k=0;
	do {
		printf("Unesite broj n: ");
		scanf("%d", &n);
	if (n>0 && n<=50) break;
	printf ("Pogresan unos\n");
	} while(n<=0 || n>50);
	if (n==1) printf("*");
	for(i=1; i<=4*n; i++) {
		for(j=1;j<=n;j++) {
			if (i==j) { printf("*"); }
			else { printf(" "); }
		}
			for(j=n-1;j>1;j--) {
			if (i==j) { printf("*"); }
			else { printf(" "); }
		}
			for(j=1;j<=n;j++) {
			if (i==j) { printf("*"); }
			else { printf(" "); }
		}
			for(j=n-1;j>=1;j--) {
			if (i==j) { printf("*"); }
			else { printf(" "); }
		}
		if (i<n)printf("\n");
	}
	/*printf("Zadaća 1, Zadatak 4");*/
	return 0;
}
