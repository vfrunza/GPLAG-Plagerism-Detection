#include <stdio.h>
#define DUZINA 200

int isti(int *nizA, int *nizB, int brel){
	int i;
	for(i = 0; i < brel ; i++)
		if(nizA[i] != nizB[i])
			return 0;
	return 1;
}

int main() {
	int m,n,mat[DUZINA][DUZINA], i = 0, j = 0;
	int ISTI = 0;
	
	
	int k = 0, l = 0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &m, &n);
		if(m<1 || n<1 || m>200 || n>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<1 || n<1 || m>200 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	/*Izbacivanje po redovima*/
	for(i=1;i<m;i++) {
		for(j = 0; j < i; j++)
			if(isti(mat[i],mat[j],n)){
				for(k = i; k < m-1; k++ )
					for(l = 0; l< n; l++)
						mat[k][l] = mat[k+1][l];
				m--;
				i--;
			}
		
	}
	/*-----------------------*/
	
	/*Izbacivanje po kolonama*/
	for(i=1;i<n;i++) {
		for(j = 0; j < i; j++){
			
			ISTI = 1;
			for(k = 0; k < m; k++)
				if(mat[k][i] != mat[k][j])
					ISTI = 0;
			
			
			if(ISTI){
				for(k = i; k < n-1; k++ )
					for(l = 0; l< m; l++)
						mat[l][k] = mat[l][k+1];
				n--;
				i--;
			}
		}
	}
	
	/*-----------------------*/
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	/*printf("Zadaća 3, Zadatak 3");*/
	return 0;
}
