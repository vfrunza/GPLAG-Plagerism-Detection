#include <stdio.h>

int main(){
	int i,j,mat[200][200],M,N,isti_red,ista_kolona,l=0,g=0,k=0,z=0;
	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	if (M<=0 || N<=0 || M>200 || N>200){
		printf("Brojevi nisu u trazenom opsegu.\n");
	}
	} while(M<=0 || N<=0 || M>200 || N>200);
	
	printf("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=i+1;j<M;j++){
			isti_red=1;
			for(l=0;l<N;l++)
				if(mat[i][l]!=mat[j][l]) 
				isti_red=0;
				
				if(isti_red==1){
					g=0;
					for(l=j;l<M;l++){
						for(g=0;g<N;g++)
							mat[l][g]=mat[l+1][g];
					}
			M--;
			i--;
			break;
				}
		}
	}
	for (j=0;j<N-1;j++){
		for (i=j+1;i<N;i++){
			ista_kolona=1;
			for(k=0;k<M;k++)
			if (mat[k][i]!=mat[k][j])
			ista_kolona=0;
			
			if(ista_kolona==1){
				
				for(k=i;k<N;k++){
					for(z=0;z<M;z++)
						mat[z][k]=mat[z][k+1];
				}
				N--;
				j--;
				break;
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