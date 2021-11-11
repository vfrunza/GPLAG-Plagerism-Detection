#include <stdio.h>

int main() {
	int matrica[400][400],i ,j ,m, n, ja_bi_to_izbacio_haha,idi,dodi,k;
	for(;;){
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
		if(m <= 0 || m > 200 || n <= 0 || n > 200) 
			printf("Brojevi nisu u trazenom opsegu.\n"); 
		else break;
	}
	
	printf("Unesite elemente matrice: ");
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			scanf("%d",&matrica[i][j]);
			
/*Izbacivanje redova*/

		for(i = 0; i < m; i++){
			for(j = i + 1; 	j < m; j++){
				ja_bi_to_izbacio_haha = 1;
					for(k = 0; k < n; k++)	
						if(matrica[j][k] != matrica[i][k]) ja_bi_to_izbacio_haha = 0;
				
				if(ja_bi_to_izbacio_haha){
					for(idi = j; idi < m - 1; idi++)
						for(dodi = 0; dodi < n; dodi++)	matrica[idi][dodi] = matrica[idi + 1][dodi];
						m--;
						j--;
				}
			}
		}

/*Izbacivanje kolone, samo smo rotirali slova */

	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			ja_bi_to_izbacio_haha = 1;
				for(k = 0; k < m; k++) 
					if(	matrica[k][j] != matrica[k][i])ja_bi_to_izbacio_haha = 0;
				if(ja_bi_to_izbacio_haha){
					for(idi = 0; idi < m; idi++)
						for( dodi = j; dodi < n - 1 ;dodi++)
							matrica[idi][dodi] = matrica[idi][dodi + 1];
							n--;
							j--;
				}
		}
	}

printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i = 0; i < m; i++){
	for(j = 0; j < n; j++)
		printf("%5d",matrica[i][j]);
	printf("\n");
}

	return 0;
}
