#include <stdio.h>

int main() {
	int M,N,i,j,brojac1,brojac2,brojac3,z,k;
	int A[100][100],B[100][100],C[100][100];
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);
	}while(M<0 || M>100 || N<0 || N>100);
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
		for(j=0;j<N;j++){
			brojac1=0;
			brojac2=0;
			brojac3=0;
			for(k=0;k<M;k++){
				for(z=0;z<N;z++){
					if(A[i][j]==A[k][z]) brojac1++;
					if(A[i][j]==B[k][z]) brojac2++;
					if(A[i][j]==C[k][z]) brojac3++;
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
