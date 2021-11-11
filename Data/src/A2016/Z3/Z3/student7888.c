#include <stdio.h>


int main() {
		int matrica[200][200];
		int M,N,i,j,m,n,k=0,temp,brojac=0;
	do {
								/* Unos broja redova i kolona */
			printf("Unesite brojeve M i N: ");
			scanf("%d %d", &M,&N);
		
		if(M<=0 || M>=200 || N<=0 || N>=200) {
			
			printf("Brojevi nisu u trazenom opsegu.\n");
			
			
		}
		
		
	}while(M<=0 || M>=200 || N<=0 || N>=200);
										/* Unos elemenata matrice */
			printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++) {
		
		for(j=0; j<N; j++) {
			
			scanf("%d", &matrica[i][j]);
			
			
		}
		
	}
										/* Poredjenje i izbacivanje redova */
		for(i=0; i<M; i++)	{
		
			for(j=i+1; j<M; j++)	{
				brojac=0;
				
					for(k=0; k<N; k++)	{
						if(matrica[i][k]==matrica[j][k]){
							brojac++;
										}	
						if(brojac==N){
						
							for(m=j+1; m<M; m++){
								
								for(n=0; n<N; n++){
									temp=matrica[m-1][n];
									matrica[m-1][n]=matrica[m][n];
									matrica[m][n]=temp;
							}
					
						}
					
						M--;
						j--;
				
					}
			
				}
		
			}
		}
	
	
	
	
											/* Poredjenje i izbacivanje kolona */
	
		for(i=0; i<N; i++)	{
		
			for (j=i+1; j<N; j++)	{
				brojac=0;
			
				for(k=0; k<M; k++)	{
					if(matrica[k][i]==matrica[k][j]){
						brojac++;
					}
				
					if(brojac==M){
					
						for(m=j+1;m<N;m++){
						
							for(n=0;n<M;n++){
								temp=matrica[n][m-1];
								matrica[n][m-1]=matrica[n][m];
								matrica[n][m]=temp;
							}
					
						}
					
						N--;
						j--;
				
					}
			
				}
		
			}
	
		}
			
		
	

											/* Matrica nakon izbacivanja */

	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");

	for (i=0; i<M; i++){
	
		for(j=0; j<N; j++){
			printf("%5d", matrica[i][j]);
		}
	
		printf("\n");
	}
		


	return 0;
}