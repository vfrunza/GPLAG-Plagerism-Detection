#include <stdio.h>

int main() {
	int	mat[200][200]={{0}},m,n,prekid=0,i,j,b,k,c,brojac=0;
	
	
	//Unos i provjera opsega M i N
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m>200 || m<1 || n<1 || n>200){ printf("Brojevi nisu u trazenom opsegu.\n");}
		else { prekid=1; }
		
	}while (prekid!=1);
	
	printf("Unesite elemente matrice: ");
	
	for (i=0; i<m; i++) {
		
		for (j=0; j<n; j++) {
			
			scanf("%d",&mat[i][j]);
		}
		
	}
	
	//Provjera jednakosti redova

	for (i=0; i<m; i++) {
		
		for (b=i+1; b<m; b++) {
			
			brojac=0;
			
			for (j=0; j<n; j++) {							
				
				if(mat[i][j]!=mat[b][j]){break;}
				if(mat[i][j]==mat[b][j]){brojac++;}
				if(brojac==n){							//Izbacivanje istih redova
					
					for (k=b; k<m-1; k++) {
						
						for (c=0; c<n; c++) {
							
							mat[k][c]=mat[k+1][c];
						}
						
					}
					b--;
					m--;
				}
			}
			
		}
		
	}
	
	//Provjera jednakosti kolona nove matrice
	 brojac=0;
	for (j=0; j<n; j++) {
		
		for (b=j+1; b<n; b++) {
			
			brojac=0;
			
			for (i=0; i<m; i++ ) {
				
				if(mat[i][j]!=mat[i][b]){break;}
				if(mat[i][j]==mat[i][b]){brojac++;}
				if(brojac==m){								//Izbacivanje istih kolona
					
					for(k=b; k<n-1; k++) {
						
						for(c=0; c<m; c++) {
							
							mat[c][k]=mat[c][k+1];
						}
					}
					n--;
					b--;
				}
			}
		}
		
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
