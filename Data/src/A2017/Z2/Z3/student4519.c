#include <stdio.h>

int main() {
	int a[100][100], b[100][100];
	int i, j, jednake, a_sirina, a_visina, b_sirina, b_visina;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a_sirina, &a_visina);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<a_sirina; i++)
		for(j=0; j<a_visina; j++)
			scanf("%d", &a[i][j]);
			
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &b_sirina, &b_visina);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<b_sirina; i++)
		for(j=0; j<b_visina; j++)
			scanf("%d", &b[i][j]);
			
			
	for(jednake=1,i=0; i<a_sirina; i++)
		for(j=0; j<a_visina; j++)
			if(a[i][j] != b[j][a_sirina-i-1]) {
				jednake=0;
				break;
			}
	if(jednake) printf("DA");
	else printf("NE");
	return 0;
}
