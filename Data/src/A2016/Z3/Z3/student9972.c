#include <stdio.h>

int br(int* niz,int vel) {
	int i,k=1,suma=0;
	for(i=0;i<vel;i++) {
		if(i>=0){
	suma=suma+niz[i]*k;
	k=k*10;
	} }return suma;
}
int main() {
	int M,N, mat[200][200],i,j,k,p;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || N<1 || M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
		
	} while (M<1 || N<1 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d",&mat[i][j]);
			
			
		}
	}  for(i=0;i<M;i++) {
		for(j=i+1;j<M;j++) {
			if (br(mat+i,N)==br(mat+j,N)) {
				for(p=j;p<M-1;p++) {
					for(k=0;k<N;k++) {
						mat[p][k]=mat[p+1][k];
						
					}
				}
				if(M>0){
				M--;
				j--;}
			}
	}
	}
	
		int r;
		i=0;int br,l;
		while (i<N) {
			for(j=i+1;j<N;j++) {
				br=0;
				for(r=0;r<M;r++) {
					if(mat[r][i]!=mat[r][j]) br++;
				}
				if(br==0) {
					for(p=j;p<N-1;p++) {
						for(l=0;l<M;l++) {
							mat[l][p]=mat[l][p+1];
						}
						
					}
					if(N>0){
					j--; N--;}
				}
			}
			if(i>=0)
			i++;
		}
		
	printf("Nakon izbacivanja redova/kolona matrica glasi:",mat[i][j]);
	printf("\n");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++) {
			printf("%5d",mat[i][j]);
			
		}
		printf("\n");
	}	
	return 0;
}
