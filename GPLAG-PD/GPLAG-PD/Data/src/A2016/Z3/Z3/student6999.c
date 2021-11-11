#include <stdio.h>

int main() {
	int mat[200][200],i,j,M,N,brojac=0,k=0,x,y,privremena;
do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if((M<=0 || N<=0 || M>200 || N>200)) {
	printf("Brojevi nisu u trazenom opsegu.\n");}
}while(M<=0 || N<=0 || M>200 || N>200);
	
printf("Unesite elemente matrice: ");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%d",&mat[i][j]);
	}
}
	/*poređenje redova*/ 
for(i=0;i<M;i++){
	for(j=i+1;j<M;j++){
		brojac=0;
			for(k=0;k<N;k++){
				if(mat[i][k]==mat[j][k]){brojac++;}
		/*izbacivanje reda*/
		if(brojac==N){
			for(x=j+1;x<M;x++){
				for(y=0;y<N;y++){
					privremena=mat[x-1][y];
					mat[x-1][y]=mat[x][y];
					mat[x][y]=privremena;
				}
			}
			M--;
			j--;
			}
		}
	}
}

	/*poređenje kolona*/
for(i=0;i<N;i++){
	for(j=i+1;j<N;j++){
		brojac=0;
		for(k=0;k<M;k++){
			if(mat[k][i]==mat[k][j]){brojac++;}
			/*izbacivanje kolone*/
			if(brojac==M){
				for(x=j+1;x<N;x++){
					for(y=0;y<M;y++){
						privremena=mat[y][x-1];
						mat[y][x-1]=mat[y][x];
						mat[y][x]=privremena;
					}
				}
			N--;
			j--;
			}
		}
	}
}
	
printf("Nakon izbacivanja redova/kolona matrica glasi: \n");	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}