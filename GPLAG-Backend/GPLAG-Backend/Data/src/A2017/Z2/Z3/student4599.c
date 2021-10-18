#include <stdio.h>

int main() {
	double matricaA[100][100], matricaB[100][100], pomocna[100][100];
	int i, j, s1, s2, v1, v2;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &s1, &v1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<v1; i++){
		for(j=0; j<s1; j++)
			scanf("%lf", &matricaA[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &s2, &v2);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<v2; i++){
		for(j=0; j<s2; j++)
			scanf("%lf", &matricaB[i][j]);
	}
	for(i=0; i<v1; i++){
		for(j=0; j<s1; j++)
		pomocna[j][s1-i-1]=matricaA[i][j];
	}
	for(i=0; i<s1; i++){
		for(j=0; j<v1; j++){
			if(pomocna[i][j]!=matricaB[i][j]){
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
