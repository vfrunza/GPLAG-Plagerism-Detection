#include <stdio.h>

int main() {
	int M,N,i,j,A[100][100],B[100][100],C[100][100],brojac1,brojac2,brojac3,k,p;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while (M>100 || N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&C[i][j]);
		}
	}
		for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			int temp=A[i][j];
			brojac1=0;brojac2=0;brojac3=0;
			for(k=0;k<M;k++){
				for(p=0;p<N;p++){
					if(A[k][p]==temp) brojac1++;
					if(B[k][p]==temp) brojac2++;
					if(C[k][p]==temp) brojac3++;
				}
			}
			if(brojac1!=brojac2 || brojac1!=brojac3) {
				printf("NE\n");
				return 0;
			}
		}
		}
		printf("DA\n");
	return 0;
}
