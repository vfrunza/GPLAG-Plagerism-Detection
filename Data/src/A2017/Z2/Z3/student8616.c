#include <stdio.h>
#define BROJ_EL 100

int main() {
	int sirina1=0, sirina2=1, visina1=3, visina2=5, i, j, br=0;
	int A[BROJ_EL][BROJ_EL], B[BROJ_EL][BROJ_EL], C[BROJ_EL][BROJ_EL];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina1 , &visina1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina1; i++){
		for(j=0; j<sirina1; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina2 , &visina2);
	printf("Unesite clanove matrice B: ");
	if((sirina1+visina1==sirina2+visina2) && ((sirina1==sirina2) || (sirina1==visina2)) && ((visina1==sirina2) || (visina1==visina2))){
	for(i=0; i<visina2; i++){
		for(j=0; j<sirina2; j++){
			scanf("%d", &B[i][j]);
		}
	}
	for(i=0; i<visina2; i++){
		for(j=0; j<sirina2; j++){
			C[i][j]=A[visina1-1-j][i];
			if(C[i][j]==B[i][j]) br++;
		}
	}
	if(br==visina2*sirina2) printf("DA");
	else printf("NE");
	}
	else printf("NE");
	return 0;
}
