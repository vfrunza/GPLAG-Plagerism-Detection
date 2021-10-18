#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main() {
	int a[VISINA][SIRINA], b[VISINA][SIRINA], i, j, a1, a2, b1, b2;
	do{
		printf("Unesite sirinu i visinu matrice A: ");
		scanf("%d %d", &b1, &a1);
	}while(a1 < 1 || b1 < 1);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < a1; i++)
		for(j = 0; j < b1; j++)
			scanf("%d", &a[i][j]);
	do{
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d %d", &b2, &a2);
	}while(a2 < 1 || b2 < 1);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < a2; i++)
		for(j = 0; j < b2; j++)
			scanf("%d", &b[i][j]);
	if(a1 == b2 && b1 == a2){
		for(i = 0; i < a1; i++){
			for(j = 0; j < b1; j++){
				if(a[i][j] != b[j][a1-1-i]){
					printf("NE\n");
					return 0;
				}
			}
		}
		printf("DA\n");
	}
	else printf("NE\n");
	return 0;
}
