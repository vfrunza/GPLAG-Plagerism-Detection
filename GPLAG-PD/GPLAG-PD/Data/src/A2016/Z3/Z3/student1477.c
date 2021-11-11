#include <stdio.h>

int main() {
	int i,j,k,x,visina,sirina,L,S,mat[100][100],ponavlja_se;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &visina,&sirina);
		if (visina<=0 || visina>200 || sirina<=0 || sirina>200)
		printf ("Brojevi nisu u trazenom opsegu.\n");  
		} while (visina<=0 || visina>200 || sirina<=0 || sirina>200);
		
		printf("Unesite elemente matrice: ");
		for (i=0; i<visina; i++) {
			for (j=0; j<sirina; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		/*izbacivanje kolona*/
		for (j=0; j<sirina; j++) {
			for (x=j+1; x<sirina; x++) {
				ponavlja_se=1;
				for (i=0; i<visina; i++)
				if (mat[i][j]!=mat[i][x])
				ponavlja_se=0;
				if (ponavlja_se==1) {
					for (i=x; i<sirina-1; i++)
					 for (S=0; S<visina; S++)
					  mat[S][j]=mat[S][j+1];
					  sirina--;
					  x--;
				}
			}
		}
		/*izbacivanje redova*/
		for (i=0; i<visina; i++) {
			for (k=i+1; k<visina; k++) {
				ponavlja_se=1;
				for (j=0; j<sirina; j++)
				 if (mat[i][j]!=mat[k][j])
				 ponavlja_se=0;
				 if (ponavlja_se==1) {
						for (j=k; j<visina-1; j++) 
						 for (L=0; L<sirina; L++)
							mat[j][L]=mat[j+1][L];
							visina--;
							k--;
				 	}
				}
			}
			printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
			for (i=0; i<visina; i++) {
				for (j=0; j<sirina; j++) {
					printf("%5d", mat[i][j]);
				}
				printf("\n");
			}
			return 0;
}
	
	