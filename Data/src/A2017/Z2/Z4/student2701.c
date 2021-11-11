#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main() {
	int a[VISINA][SIRINA], b[VISINA][SIRINA], c[VISINA][SIRINA], niz[VISINA*SIRINA], i, j, m, n, temp;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while(m < 0 || m > 100 || n < 0 || n > 100);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
			niz[n*i+j] = a[i][j];
		}
	for(i = 0; i < m * n; i++)
		for(j = i; j < m * n; j++)
			if(niz[i] > niz[j]){
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			a[i][j] = niz[n*i + j];
			
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++){
			scanf("%d", &b[i][j]);
			niz[n*i+j] = b[i][j];
		}
	for(i = 0; i < m * n; i++)
		for(j = i; j < m * n; j++)
			if(niz[i] > niz[j]){
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			b[i][j] = niz[n*i + j];

	printf("Unesite clanove matrice C: ");
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++){
			scanf("%d", &c[i][j]);
			niz[n*i+j] = c[i][j];
		}
	for(i = 0; i < m * n; i++)
		for(j = i; j < m * n; j++)
			if(niz[i] > niz[j]){
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			c[i][j] = niz[n*i + j];
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(a[i][j] != b[i][j]){
				printf("NE");
				return 0;
			}
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(a[i][j] != c[i][j]){
				printf("NE");
				return 0;
			}
	printf("DA");
	return 0;
}
