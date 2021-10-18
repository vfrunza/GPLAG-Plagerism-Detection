#include <stdio.h>

int main() {
	int m,n,i,j,k,l,s,br=0,mat[200][200]={{0}};
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	if(m<1 || n<1 || m>=200 || n>=200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<1 || n<1 || m>=200 || n>=200);
		
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
	}
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	/*Izbacivanje istih redova iz matrice*/
	for(i=0; i<m; i++) {
		for(k=i+1; k<m; k++) {
			for(l=0; l<n; l++) {
				/*Poredi redove, prvo prvi red sa ostalim, pa dalje redom, drugi sa preostalim itd.*/
				if(mat[i][l]==mat[k][l]) 
					br++;
			}
			/*Ako se svaki put brojac povecavao za jedan znaci da su mu svi elementi
			reda jednaki drugim elementima nekog drugog reda*/
			if(br==n) {
				for(j=0; j<m; j++) {
					for(s=k; s<m-1; s++) 
						mat[s][j]=mat[s+1][j];
				}
			m--;
			k--;
			}
		br=0;
		}
	}
	/*Izbacivanje istih kolona iz matrice, na analogan nacin kao i izbacivanje redova, samo obrnuto*/
	for(i=0; i<n; i++) {
		for(k=i+1; k<n; k++) {
			for(l=0; l<m; l++) {
				if(mat[l][k]==mat[l][i]) 
					br++;
			}
			if(br==m) {
				for(j=0; j<m; j++) {
					for(s=k; s<n-1; s++) 
						mat[j][s]=mat[j][s+1];
				}
			n--;
			k--;
			}
		br=0;
		}
	}
	
	/*Na kraju ispisivanje modificirane matrice*/
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++)
		 	printf("%5d", mat[i][j]);
		printf("\n");
	}
	
	return 0;
}
