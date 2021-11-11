#include <stdio.h>

int main() {
	int matrica[200][200],i,j,M,N,l,k,jednaki=1;
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || M>200 || N<1 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(M<1 || M>200 || N<1 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	for(i=0;i<M;i++){
		for(k=1;k<M-i;k++){
			for(j=0;j<N;j++){
				if(matrica[i][j]!=matrica[i+k][j]){
					jednaki--;
					break;
				}
			}
				if(jednaki){
				for(l=i+k;l<M-1;l++){
					for(j=0;j<N;j++){
				matrica[l][j]=matrica[l+1][j];}
				}
				M--;
				k--;
				}
				jednaki=1;
			}
		}
	for(j=0;j<N;j++){
		for(k=1;k<N-j;k++){
			for(i=0;i<M;i++){
				if(matrica[i][j]!=matrica[i][j+k]){
					jednaki--;
					break;
				}
			}
				if(jednaki){
				for(l=j+k;l<N-1;l++){
					for(i=0;i<M;i++){
				matrica[i][l]=matrica[i][l+1];}
				}
				N--;
				k--;
				}
				jednaki=1;
			}
		}	
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
