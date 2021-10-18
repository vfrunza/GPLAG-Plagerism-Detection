#include <stdio.h>

int main() {
	int n, i, j, k, x[10], y[10];
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n>10||n<1) {
			printf("Pogresan unos\n");
		}
	} while(n>10||n<1);
	
	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x[i], &y[i]);
		if(x[i]>19||x[i]<0||y[i]>19||y[i]<0) {
			printf("Pogresan unos\n");
			i--;
		}
	}
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			for(k=0; k<n; k++) {
				if(x[k]==j&&y[k]==i) {
					printf("*");
					break;
				}
			}
			if(k==n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
