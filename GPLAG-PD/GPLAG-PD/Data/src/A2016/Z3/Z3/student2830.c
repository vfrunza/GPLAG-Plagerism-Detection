#include <stdio.h>

int main() {
		int niz[200][200],k[200]={0},i,j,M,N,z,l,r;
		do{
			printf("Unesite brojeve M i N: ");
			scanf("%d %d",&M,&N);
			if(M<1 || M>200 || N<1 || N>200){
				printf("Brojevi nisu u trazenom opsegu.\n");
			}
		}while(M<1 || M>200 || N<1 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &niz[i][j]);
		}
	}
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			for(z=0;z<N;z++){
			if(niz[i][z]==niz[j][z]){
				k[j]++;
			} }
				if(k[j]==N){
					z=j;
					for(l=0;l<M;l++){
						for(r=0;r<N;r++){
							if(l>=z){
								niz[l][r]=niz[l+1][r];
							}
						}
					}
			M--;
			k[j]=0;
			j--;
				}
				k[j]=0;
	}
	}
	for(i=0;i<N;i++){
		k[i]=0;
	}
	
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			for(z=0;z<M;z++){
			if(niz[z][i]==niz[z][j]){
				k[j]++;
				if(k[j]==M){
					z=j;
					for(l=0;l<M;l++){
						for(r=0;r<N;r++){
							if(r>=z){
								niz[l][r]=niz[l][r+1];
							}
						}
					}
			N--;
			k[j]=0;
			j--;
					}
			 
		}
	}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",niz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
