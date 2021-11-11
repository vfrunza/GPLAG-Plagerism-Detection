#include <stdio.h>

int main() {
	int i, j, k, n, X[10], Y[10];
	char ks[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<=0 || n>10) {
		printf("Pogresan unos\nUnesite broj tacaka: ");
		scanf("%d", &n);
	}
	
	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &Y[i], &X[i]);
		while(X[i]<0 || X[i]>19 || Y[i]<0 || Y[i]>19) {
			printf("Pogresan unos\nUnesite %d. tacku: ", i+1);
			scanf("%d %d", &Y[i], &X[i]);
		}
	}
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			ks[i][j]=' ';
		}
	}
		
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			for(k=0; k<n; k++) {
				if(i==X[k] && j==Y[k]) ks[i][j]='*';
			}
		}
	}
	
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			printf("%c", ks[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
