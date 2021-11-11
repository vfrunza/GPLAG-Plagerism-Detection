#include <stdio.h>

int main()
{
	int visina1,sirina1,visina2,sirina2,i,j;
	int mata[100][100] ,matb[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &visina1,&sirina1);
	for(i=0; i<visina1; i++) {
		for(j=0; j<sirina1; j++) {
			printf("Unesite clanove matrice A: ");
			scanf("%5d", &mata[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &visina2,&sirina2);
	for(i=0; i<visina2; i++) {
		for(j=0; j<sirina2; j++) {
			printf("Unesite clanove matrice B: ");
			scanf("%5d", &matb[i][j]);
		}
	}
}
return 0;
}
