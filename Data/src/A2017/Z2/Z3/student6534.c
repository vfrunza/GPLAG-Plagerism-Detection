#include <stdio.h>
#define max 100
int main() {
/*	printf("Zadaća 2, Zadatak 3"); */

int matrica[max][max], i, j, visina, sirina, visinab, sirinab, matricab[max][max], jeste;

printf ("Unesite sirinu i visinu matrice A: ");
scanf ("%d %d", &sirina, &visina);
printf ("Unesite clanove matrice A: ");
for (i=0; i<visina; i++)
	for(j=0; j<sirina; j++) 
		scanf ("%d", &matrica[i][j]);
		
printf ("Unesite sirinu i visinu matrice B: ");
scanf ("%d %d", &sirinab, &visinab);
printf ("Unesite clanove matrice B: ");
for (i=0; i<visinab; i++)
	for(j=0; j<sirinab; j++) 
		scanf ("%d", &matricab[i][j]);
jeste=1;
if (sirina!=visinab || visina!=sirinab) 
	jeste=0;
else {
for (i=0; i<visina; i++)
	for (j=0; j<sirina; j++)
		if(matrica[i][j]!=matricab[j][sirinab-1-i]) {
			jeste=0;
			break;
		}
}
if (jeste)
	printf ("DA");
else 
	printf ("NE");
	return 0;
}