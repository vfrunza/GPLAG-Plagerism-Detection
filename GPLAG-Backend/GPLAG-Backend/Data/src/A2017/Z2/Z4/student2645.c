#include <stdio.h>

int main() {
		
	int matA[100][100];
	int matB[100][100];
	int matC[100][100];
	int M,N;
	int i,j,k,l,m,n,pom,da=1;
	int br_ponA=0, br_ponB=0 ,br_ponC=0;
	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d", &M);
	scanf("%d", &N);
	}while(M>100 || M<0 || N>100 || N<0);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &matB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &matC[i][j]);
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			br_ponA=0;
			br_ponB=0;
			br_ponC=0;
			pom=matA[i][j];
			for(k=0;k<M;k++){
				for(l=0;l<N;l++){
					if(pom==matA[k][l]) br_ponA++;
				}
			}
			for(m=0;m<M;m++){
				for(n=0;n<N;n++){
					if(pom==matB[m][n]) br_ponB++;
					if(pom==matC[m][n]) br_ponC++;
				}	
			}
			
			if(br_ponA!=br_ponB || br_ponA!=br_ponC) da=0;
		}
	}
	
	if(da) printf("DA\n");
	else printf("NE\n");
	
	
	return 0;
}
