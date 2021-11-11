#include <stdio.h>


int main() {
	
	int i, k, br, j, mat[200][200],m,n,a,b,temp;
	
	/* dio 1: unos matrice */
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<1||m>=200 || n<1 || n>=200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
		
	}while(m<1||m>200 ||n<1|| n>200);	
	
	
	/* dio 2: unos elemenata */
	
		printf("Unesite elemente matrice: ");
		for (i=0; i<m; i++) {
			for (j=0; j<n; j++) {
				scanf("%d", &mat[i][j]);
	}
	
}	
	/* dio 3: poredjenje i izbacivanje redova */
	
		for (i=0; i<n; i++) {
			for (j=i+1;j<m;j++){
				br=0;
				
				for(k=0;k<n;k++){
					if(mat[i][k]==mat[j][k]){
						br++;
					}
					if(br==n){
						for (a=j+1;a<m;a++){
							for(b=0;b<n;b++){
								temp=mat[m-1][n];
								mat[m-1][n]=mat[m][n];
								mat[m][n]=temp;
							}
						}
						m--;
						j--;
					}
				}
				
			}
    }
	


	/* dio 4: poredjenje i izbacivanje kolona */
	
		for (i=0; i<n; i++) {
			for (j=i+1;j<n;j++){
				br=0;
				
				for(k=0;k<m;k++){
					if(mat[k][i]==mat[k][j]){
						br++;
					}
					if(br==m){
						for (a=j+1;a<n;a++){
							for(b=0;b<m;b++){
								temp=mat[n][m-1];
								mat[n][m-1]=mat[n][m];
								mat[n][m]=temp;
							}
						}
						n--;
						j--;
					}
				}
				
			}
    }
	

	
	
	
	
	
	
	
	
	
	/*ispis matrice*/
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	
	return 0;
}
