#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int mat[20][20]={0}, niz[20], niz2[20];
	int n, i, j, k;
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n<=0 || n>10) {
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
	}
	for(i=0;i<n;i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niz[i], &niz2[i]);
		if(niz[i]<0 || niz[i]>19 || niz2[i]<0 || niz2[i]>19) {
			printf("Pogresan unos\n");
			i--;
			continue;
		}
	}
	
	for(i=0;i<n;i++) 
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<20;k++) {
 				if(j==niz[i] && k==niz2[i]) mat[j][k]=1;
				}
			}
		
		}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++) {
			if (mat[j][i]==1) printf("*");
			else printf (" ");
		} 
	printf("\n");}
	return 0;
}
