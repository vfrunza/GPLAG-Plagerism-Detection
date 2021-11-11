#include <stdio.h>

int main() {
	int M,N,i=0,j,k,l,nasao_red=0;
	int niz[200][200];
	do{
		if(i!=0) printf("Brojevi nisu u trazenom opsegu.\n");
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
		i++;
	}while(M<=0 || M>200 || N<=0 || N>200);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&niz[i][j]);
		}
	}
	for(k=0;k<M;k++){
		
		for(i=k+1;i<M;i++){
			nasao_red=1;
			if(niz[k][0]!=niz[i][0]){
				nasao_red=0;
				
			
			}
			else {
				for(j=1;j<N;j++){
					if(niz[k][j]!=niz[i][j]){
						nasao_red=0;
						break;
					}
				}
			}
			
			if(nasao_red!=0)  { 
			
				j=i;
				while(j!=M-1){
					for(l=0;l<N;l++){
						niz[j][l]=niz[j+1][l];
					
					}
					j++;
				}
				M--;
				i--;
			}
				
		}
	}
	for(k=0;k<N;k++){
		for(i=k+1;i<N;i++){
			nasao_red=1;
			if(niz[0][k]!=niz[0][i]){
				nasao_red=0;
			}
			else {
				for(j=0;j<M;j++){
					if(niz[j][k]!=niz[j][i]){
						nasao_red=0;
						break;
					}
				}
			}
			if(nasao_red!=0){
				j=i+1;
				while(j!=N){
					for(l=0;l<M;l++){
						niz[l][j]=niz[l][j+1];
					}
					j++;
				}
				N--;
				i--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(j==0)
			printf("%5.d",niz[i][j]);
			else printf("%5.d",niz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
