#include <stdio.h>

int main() {
	int M,N,mat[200][200],i,j,x,m,n;
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if(M<=0 || M>200 || N<=0 || N>200){
		do{
			printf("Brojevi nisu u trazenom opsegu.\n");
			printf("Unesite brojeve M i N: ");
			scanf("%d %d",&M,&N);
		}while(M<=0 || M>200 || N<=0 || N>200);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++) scanf("%d",&mat[i][j]); 
	}
	/*redovi*/
	
	 int DA=1;
	for(x=0;x<M-1;x++){
		for(i=x+1;i<M;i++){ DA=1;
			for(j=0;j<N;j++){
				if(mat[x][j]!=mat[i][j])  { DA=0; j=N-1;}
			}
			if(DA==1) {
				for(m=i+1;m<M;m++){
					for(n=0;n<N;n++) mat[m-1][n]=mat[m][n]; }
			M--; i--; }
			
		} 
		} 
		
		/*kolone*/
		
		DA=1;
		for(x=0;x<N-1;x++){
			for(j=x+1;j<N;j++){ DA=1;
				for(i=0;i<M;i++){
					if(mat[i][x]!=mat[i][j]) { DA=0; i=M-1; }
				}
				if(DA==1) {
					for(n=j+1;n<N;n++){
						for(m=0;m<M;m++){
							mat[m][n-1]=mat[m][n]; }
				   }
			N--; j--;	}
			}
		}
		
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++) {printf("%5d",mat[i][j]);}
		printf("\n");
	}
	return 0;
}
