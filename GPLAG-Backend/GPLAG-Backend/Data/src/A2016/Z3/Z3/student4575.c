#include <stdio.h>

int main() {
	int m=0, n=0, niz[200][200]={{0}}, i, j, z=0, brojac=0, x=0, y=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if(m<1 || m>200 || n<1 || n>200){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while(m<1 || m>200 || n<1 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &niz[i][j]);
		}
	}
	
	/* Izbacivanje redova */
	
	do{
		for(i=z+1;i<m;i++){
			for(j=0;j<n;j++){
				if(niz[z][j]==niz[i][j]){
					brojac++;
				}
				if(brojac==n){
					for(x=i;x<m;x++){
						for(y=0;y<n;y++){
							niz[x][y]=niz[x+1][y];
						}
					}
					brojac=0;
					m--;
					i--;
				}
			}
			brojac=0;
		}
		if(i==m){
			z++;
		}
	} while(z<m-1);
	
	/* Izbacivanje kolona */
	
	z=0;
	brojac=0;
	y=0;
	do {
		for(i=z+1;i<n;i++){
			for(j=0;j<m;j++){
				if(niz[j][z]==niz[j][i]){
					brojac++;
				}
				if(brojac==m){
					for(x=i;x<n;x++){
						for(y=0;y<m;y++){
							niz[y][x]=niz[y][x+1];
						}
					}
					brojac=0;
					n--;
					i--;
				}
			}
			brojac=0;
		}
		if(i==n){
			z++;
		}
	} while(z<n-1);
	
	/* Ispis */
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(niz[i][j]<0 && niz[i][j]<=-10){
				printf("  %d", niz[i][j]);
			}
			if(niz[i][j]<0 && niz[i][j]>=-10){
				printf("   %d", niz[i][j]);
			}
			if(niz[i][j]>0 && niz[i][j]<10){
				printf("    %d", niz[i][j]);
			}
			if(niz[i][j]>0 && niz[i][j]>=10){
				printf("   %d", niz[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
