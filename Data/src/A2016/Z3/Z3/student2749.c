#include <stdio.h>

int main() {
	int matrica[200][200] = {{0}},brojac = 0,m,n,i,j,k,o,p;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m > 200 || m <= 0 || n <= 0 || n > 200){
			printf("Brojevi nisu u trazenom opsegu.\n");
			continue;
		}else break;
	}while(1);
	printf("Unesite elemente matrice: ");
	for(i = 0; i < m; i++){
		for(j = 0;j < n; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
/*	printf("\nPrije izbacenja redova matrica glasi: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d", matrica[i][j]);
		}
		printf("\n");
	}*/
	for(i = 0; i < m-1; i++){
		for(j = i+1; j < m; j++){
			/*boolean = 0;*/
			for(k = 0; k < n; k++){
				if(matrica[i][k] == matrica[j][k]) brojac++;
			}
			if(brojac == n){
				for(o = j; o < m-1; o++){
					for(p = 0; p < n; p++){
						matrica[o][p] = matrica[o+1][p];
					}
				}
				m--;
				j--;
			}
			brojac = 0;
		}
	}
/*	printf("\nNakon izbacenja redova matrica glasi: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d", matrica[i][j]);
		}
		printf("\n");
	}*/
	/*sad kolone po sablonu oderat*/
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			/*boolean = 0;*/
			for(k = 0; k < m; k++){
				if(matrica[k][i] == matrica[k][j]) brojac++;
			}
			if(brojac == m){
				for(o = j; o < n-1; o++){
					for(p = 0; p < m; p++){
						matrica[p][o] = matrica[p][o+1];
					}
				}
				n--;
				j--;
			}
			brojac = 0;
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
