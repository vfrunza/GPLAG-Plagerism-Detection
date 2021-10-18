#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, k, l;
	int br_ponavljanja=0, veci_br_ponavljanja=0;
	int broj, clan=matrica[0][0];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			broj=matrica[i][j];
			br_ponavljanja=0;
			/* brojimo koliko puta se broj(clan matrice) javlja u istoj matrici */
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {
					if(matrica[k][l]==broj) {
						br_ponavljanja++;
					}
				}
			}
			if(br_ponavljanja>veci_br_ponavljanja) {
				veci_br_ponavljanja=br_ponavljanja;
				clan=matrica[i][j];
				/* ako se dva clana matrice javljaju isti broj puta u obzir se uzima manji od ta dva clana */
			} else if(br_ponavljanja==veci_br_ponavljanja) {
				veci_br_ponavljanja=br_ponavljanja;
				if(broj<clan) clan=broj;
			}
		}
	}
	return clan;
}

/* funkcija izbacuje kolone matrice u kojima se nalazi proslijedeni broj N uz ocuvanje redoslijeda */
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, br_kolone, k, l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(k=0; k<visina; k++) {
					for(l=j; l<sirina; l++) {
						if(l==sirina-1) break;
						matrica[k][l]=matrica[k][l+1];
					}
				}
				j--;
				sirina--;
			}
		}
	}
	br_kolone=sirina;
	return br_kolone;
}

int main()
{
	int matrica[100][100], visina, sirina, i, j, clan, br_kolone, br=1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}

	clan=max(matrica,visina,sirina);
	br_kolone=izbaci_kolone(matrica,visina,sirina,clan);
	sirina=br_kolone;
	while(sirina!=0) {
		printf("\nNakon %d. prolaza matrica glasi: \n", br++);
		for(i=0; i<visina; i++) {
			for(j=0; j<br_kolone; j++) {
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
		}
		clan=max(matrica,visina,sirina);
		br_kolone=izbaci_kolone(matrica,visina,sirina,clan);
		sirina=br_kolone;
	}
	if(sirina==0) {
		printf("\nNakon %d. prolaza matrica je prazna!", br);
	}

	return 0;
}
