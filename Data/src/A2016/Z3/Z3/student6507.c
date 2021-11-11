#include <stdio.h>

int main() {
	int matrica[200][200];
	int m, n, i, j, k, x, y, t=0, brojac=0; /*t-om osiguravamo da li je neka petlja izvršena barem jednom ili nije*/
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	if(m>200 || n>200 || m<=0 || n<=0){
		do{
			printf("Brojevi nisu u trazenom opsegu.");
			printf("\nUnesite brojeve M i N: ");
	    	scanf("%d %d", &m, &n);
		}while(m>200 || n>200 || m<=0 || n<=0);
	}
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	
	for(i=0; i<m; i++){/*Izbacivanje reda*/
	if(m==1) break;
	brojac=0;
	t=0;
		for(k=i+1; k<m; k++){
			if(matrica[i][0]==matrica[k][0]){
				for(j=1; j<n; j++){
					if(matrica[i][j]==matrica[k][j]) brojac++;
				}
				t=1;
				break;
			}
		}
		if(t==1 && brojac==n-1){
			for(x=k; x<m-1; x++){
				for(y=0; y<n; y++){
					matrica[x][y]=matrica[x+1][y];
				}
			}
			m--;
			i--;
		}
	}
	
	for(i=0; i<n; i++){/*Izbacivanje kolone*/ 
	brojac=0;
	t=0;
		for(k=i+1; k<n; k++){
			if(matrica[0][i]==matrica[0][k]){
				for(j=1; j<m; j++){
					if(matrica[j][i]==matrica[j][k]) brojac++;
				}
				t=1;
				break;
			}
		}
		if(t==1 && brojac==m-1){
			
			for(x=k; x<n-1; x++){
				for(y=0; y<m; y++){
					matrica[y][x]=matrica[y][x+1];
				}
			}
			n--;
			i--;
		}
	}

	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
