#include <stdio.h>

int main() {
	int m, n, i, j, min, tpm, u, v;
	int mtA[100][100];
	int mtB[100][100];
	int mtC[100][100];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while(n>100||n<1||m>100||m<1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		scanf("%d", &mtA[i][j]);
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		scanf("%d", &mtB[i][j]);
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		scanf("%d", &mtC[i][j]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			min=mtA[i][j];
			i=u;
			j=v;
			if(mtA[u][v]<min){
				tpm=mtA[u][v];
				mtA[i][j]=min;
				mtA[u][v]=tpm;
				
			}
			printf("%d", mtA[u][v]);
		}
	}
	return 0;
}
