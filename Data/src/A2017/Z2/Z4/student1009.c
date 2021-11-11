#include <stdio.h>

int main() {
	int m,n,A[100][100]={0},B[100][100]={0},C[100][100]={0},i,j,jeste=1,broj,brojac=0,brojac1=0,brojac2=0,k=0,s=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	}while(m>100 || n>100 );
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&C[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			broj=A[i][j];
			for(k=0;k<n;k++){
				for(s=0;s<m;s++){
					if(A[k][s]==broj) brojac++;
					if(B[k][s]==broj) brojac1++;
					if(C[k][s]==broj) brojac2++;
				}
			}
			if(brojac!=brojac2 || brojac!=brojac1) {
				printf("NE");
				return 0;
			}
			brojac1=0;brojac2=0,brojac=0;
		}
	}
	printf("DA");
	return 0;
}
