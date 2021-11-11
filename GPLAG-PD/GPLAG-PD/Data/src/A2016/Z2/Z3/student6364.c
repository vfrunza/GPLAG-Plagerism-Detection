#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	char mat[20][20]={0};
	char X[20], Y[20];
	int n, i, j, p;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n); 
	while(n<=0 || n>10) { 
	printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	}
	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &X[i], &Y[i]);
		if(X[i]<0 || X[i]>19 || Y[i]<0 || Y[i]>19 ) {
			printf("Pogresan unos\n"); 
			i--;
			continue;
			}
		}
	for(p=0; p<n; p++) {
		for(i=0; i<20; i++) {				
			for(j=0; j<20; j++) {
					if(i==Y[p] && j==X[p])  mat[i][j]=1;
					}
				} 
			} 
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[i][j]==1) printf("*");
			else printf(" ");
			} 
		printf("\n");
	}
	return 0;
}
