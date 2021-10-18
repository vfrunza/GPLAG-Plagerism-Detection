#include <stdio.h>
int main() {
	int mat[20][20]={0};
	int l,n,k,i=0,j=0;
	do {printf("Unesite broj tacaka: ");
	scanf("%d", &n); if(n<1 ||n>10){printf("Pogresan unos\n");}} while (n>10 || n<1);
	for(i=0; i<n; i++) {
			printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &l, &k); 
		if (l<0 || k>=20 || k<0 || l>=20) {printf("Pogresan unos\n"); i=i-1;}
		else mat[l][k]=100; }
			for(i=0; i<20; i++) {
				for(j=0; j<20; j++) {
					if(mat[j][i]==100) printf("*"); else printf(" ");
				}
				printf("\n");
			}
	return 0;
}
