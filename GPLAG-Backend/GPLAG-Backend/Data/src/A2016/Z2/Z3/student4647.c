#include <stdio.h>

int main() {
	int i, j, n, k, m;
	int a[20][20]={{0},{0}};
	
	a: printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10) {
		printf("Pogresan unos\n");
		goto a;
	}
	for (i=0; i<n; i++) {
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &k, &m);
			if (k<0 || m<0 || k>19 || m>19) {
				printf("Pogresan unos\n");
				i--;
			}
		
			else a[k][m]=100;
			
		}
		for (i=0; i<=19; i++) {
			for (j=0; j<=19; j++) {
				if (a[j][i]==100 && a[k][m]!=20) printf("*");
				else printf(" ");
			}  
				printf("\n");
		}
	
	return 0;
}
