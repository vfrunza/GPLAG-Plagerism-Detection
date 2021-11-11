#include <stdio.h>

int main() {
	//printf("Zadaća 3, Zadatak 3");
	int M,N,i,j,k,s,counter=0,mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M,&N);
		if(M>200 || M<1 || N>200 || N<1){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while (M>200 || M<1 || N>200 || N<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	//Izbacivanje redova
	for(i=0; i<M-1; i++){
		for(k=i+1; k<M; k++){
			counter=1;
			for(j=0; j<N; j++){
				if(mat[i][j]!=mat[k][j]){
					counter=0;
					break;
				}
			}
			if(counter==1){
				for(s=k; s<M-1; s++ ){
					for(j=0; j<N; j++){
						mat[s][j]=mat[s+1][j];
					}
				}
				M--;
				//Da se ne dopusti propadanje na minus 1
				if(i!=0 || M==2)
				i--;
			}
		}
	}
	//Izbacivanje kolona
	for(j=0; j<N-1; j++){
		for(k=j+1; k<N; k++){
			counter=1;
			for(i=0; i<M; i++){
				if(mat[i][j]!=mat[i][k]){
					counter=0;
					break;
					
				}
			}
			if(counter==1){
				for(s=k; s<N-1; s++ ){
					for(i=0; i<M; i++){
						 mat[i][s]=mat[i][s+1];
					}
				}
				N--;
				//Da se ne dopusti propadanje na minus 1
				if(j!=0 || N==2)
				j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
