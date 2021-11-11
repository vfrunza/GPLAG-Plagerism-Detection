#include <stdio.h>
int main() {
	int M,N,A[100][100],B[100][100],C[100][100],i,j,k,l/*za petlje*/,brojac_a,brojac_b,brojac_c,n/*za provjeru elemenata*/;
	
	/*unos dimenzija*/
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
	}
	/*unos elemenata*/
	while(M<0 || M>100 || N<0 || N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) scanf("%d",&A[i][j]);
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) scanf("%d",&B[i][j]);
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) scanf("%d",&C[i][j]);
	}
	/*provjera*/
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			brojac_a=0;
			brojac_b=0;
			brojac_c=0;
			n=A[i][j];
			for(k=0;k<M;k++) {
				for(l=0;l<N;l++) {
					if(A[k][l]==n) brojac_a++;
					if(B[k][l]==n) brojac_b++;
					if(C[k][l]==n) brojac_c++;
				}
			}
			if(brojac_a!=brojac_b || brojac_a!=brojac_c) {
				printf("NE\n");
				return 0;
			}
		}
	}
	printf("DA\n");
	return 0;
}