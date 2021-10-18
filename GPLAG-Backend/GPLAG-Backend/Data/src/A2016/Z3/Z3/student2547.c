#include <stdio.h>

int main() {
	int M=0, N=0, mat[200][200], k=0, L=0, i=0, j=0, p=0, x, y;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || N>200 || M<0 || N<0){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(M>200 || N>200 || N<0 || M<0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%d", &mat[i][j]);

	 for(i=0;i<M;i++){
	    for(k=i+1;k<M;k++){
	    	p=1;
	    	for(j=0;j<N;j++){
	    		if(mat[i][j]!=mat[k][j]){
	    			p=0;
	    			break;
	    		} 
	    	}
	    	if(p==1){
	    		for(x=k;x<M-1;x++){
	    			for(y=0;y<N;y++){
	    				mat[x][y]=mat[x+1][y];
	    			}
	    		}
	    		M--;
	    		k--;
	    	}
	    }
	}
	
	for(i=0;i<N;i++){
		for(k=i+1;k<N;k++){
			p=1;
			for(j=0;j<M;j++){
				if(mat[j][i]!=mat[j][k]){
					p=0;
					break;
				}
			}
			if(p==1){
				for(x=0;x<M;x++)
					for(L=k;L<N-1;L++)
						mat[x][L]=mat[x][L+1];
			N--;
			k--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%5d", mat[i][j]);
	    }
		printf("\n");
	}
	return 0;
}
