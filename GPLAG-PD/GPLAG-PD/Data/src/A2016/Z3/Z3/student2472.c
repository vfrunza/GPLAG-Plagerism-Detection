#include <stdio.h>
#define max 200

	/* Program koji unesenoj matrici izbaci jednake redove i kolone, te je kao takvu ispise */
int main() {
	int m, n, br=0, br_kolone=0, br_redovi=0, mat[max][max];
	int i, j, k, s, h;
	
	/* Unos matrice */
	do{
		
	if(br>0){printf("Brojevi nisu u trazenom opsegu.\n");}	
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	if(m>200 || m<=0 || n>200 || n<=0)br++;
	
	}while(m>200 || m<=0 || n>200 || n<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	/* Izbacivanje jednakih redova */
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			br_redovi = 0;
		
			for(k=0;k<n;k++){
				if(mat[i][k]==mat[j][k]){br_redovi++;}
			}
				if(br_redovi==n){
					for(s=j;s<m-1;s++){
						for(h=0;h<n;h++){
							mat[s][h]=mat[s+1][h];
						}
				}
				m--;
				j--;
				
			}
		}
	}
	
	/* Izbacivanje jednakih kolona */
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			br_kolone = 0;
			
			for(k=0;k<m;k++){
				if(mat[k][i]==mat[k][j]){br_kolone++;}
			}
				if(br_kolone==m){
					for(s=j;s<n-1;s++){
						for(h=0;h<m;h++){
							mat[h][s]=mat[h][s+1];
						}
				}
				n--;
				j--;
			}
		}
	}

	/* Ispis matrice sa izbacenim jednakim redovima i kolonama */
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
