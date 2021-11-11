/* Zadatak: Iz matrice izbaciti sve redove koji se ponavljaju, tako da ostane prvi odozgo takav red */
/* Zatim izbaciti sve kolone koje se ponavljaju, tako da ostane prva slijeva takva kolona */
#include <stdio.h>

int main() {
	int k,m,n,i,j,a,b,br;
	int mat[200][200];
/* Unos dimenzija i elemenata matrice */
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if (m<1 || m>200 || n<1 || n>200) 
			printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (m<1 || m>200 || n<1 || n>200);
	printf ("Unesite elemente matrice: "); 
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
/* Izbacivanje jednakih redova */
	for (i=0;i<m;i++){
		for (k=1;k<m-i;k++){
			br=0;
			for (j=0;j<n;j++) {
				if (mat[i][j]==mat[i+k][j]) br++;
			}
			if (br==n){
				for (a=i+k;a<m-1;a++){
					for (b=0;b<n;b++){
						mat[a][b]=mat[a+1][b];
					}
				}
			m--;
			k--;
			} 
		}
	}
/* Izbacivanje jednakih kolona */
	for (j=0;j<n;j++){
		for (k=1;k<n-j;k++){
			br=0;
			for (i=0;i<m;i++){
				if (mat[i][j]==mat[i][j+k]) br++;
			}
			if (br==m){
				for (b=j+k;b<n-1;b++){
					for (a=0;a<m;a++){
						mat[a][b]=mat[a][b+1];
					}
				}
				n--;
				k--;
			}
		}
	}
/* Ispisivanje matrice */
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++)
			printf ("%5d",mat[i][j]);
		printf("\n");
	}
	return 0;
}
