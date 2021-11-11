#include <stdio.h>
	int redgledaj(int mat[200][200],int N,int i,int j){
		int q,T=1;
		for(q=0;q<N;q++)
			if(mat[i][q]!=mat[j][q])
				T=0;
		return T;
	}
	int kolgledaj(int mat[200][200],int M,int i,int j){
		int q,T=1;
		for(q=0;q<M;q++)
			if(mat[q][i]!=mat[q][j])
		    	T=0;
		return T;   
	}
int main(){
	int M,N,i,j,mat[200][200],k,d;
	do{
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M>200 || N>200 || M<=0 || N<=0){
			printf("Brojevi nisu u trazenom opsegu.");
		}
	} while(M>200 || N>200 || M<=0 || N<=0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
    	for(j=0;j<N;j++){
        	scanf("%d",&mat[i][j]);
    	}
	}
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			if(redgledaj(mat,N,i,j)==1){
				for(k=j;k<M-1;k++){
					for(d=0;d<N;d++){
						mat[k][d]=mat[k+1][d];
					}
				}
				M--;j--;
			}
		}
	}
	//za redove //
for(i=0;i<N;i++){
	for(j=i+1;j<N;j++){
		if(kolgledaj(mat,M,i,j)==1){
			for(k=0;k<M;k++){
				for(d=j;d<N-1;d++){
					mat[k][d]=mat[k][d+1];
				}
			}
			N--;j--;
		}
	}
}
//za kolone//
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {//printanje nove matrice//
		for (j=0; j<N; j++){
		printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
return 0;
}

		



