#include <stdio.h>

int main() {
	int M,N,matrica[100][100],i,j,k,h,kolona,red,ind=0,ind1=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if(M<1 || N<1 || M>200 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<1 || N<1 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matrica[i][j]);	
		}
	} 
	for(i=0;i<M-1;i++){
		if(ind==1)
			i--;
		for(k=i+1;k<M;k++){
			kolona=0;
			while(kolona<N){
				if(matrica[i][kolona]==matrica[k][kolona])
					ind=1;
				else{
					ind=0;
					break;
				}
				kolona++;
			}
		if(ind==1){
			for(j=k;j<M-1;j++){
				for(h=0;h<N;h++){
					matrica[j][h]=matrica[j+1][h];
				}
			}
			M--;
			k--;
		}
		}
	} 
	for(i=0;i<N-1;i++){
		if(ind1==1)
			i--;
		for(k=i+1;k<N;k++){
			red=0;
			while(red<M){
				if(matrica[red][i]==matrica[red][k])
					ind1=1;
				else{
					ind1=0;
					break;
				}
				red++;
			}
		if(ind1==1){
			for(j=k;j<N;j++){
				for(h=0;h<M;h++){
					matrica[h][j]=matrica[h][j+1];
				}
			}
			N--;
			k--;
		}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
			printf("%5d",matrica[i][j]);
		printf("\n");
	}
	return 0;
}