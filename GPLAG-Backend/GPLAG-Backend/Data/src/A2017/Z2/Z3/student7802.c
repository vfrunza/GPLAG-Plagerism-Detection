#include <stdio.h>

int main()
{
	double A[100][100], B[100][100];
	int i,j,k1,k2;
	int visina1, sirina1;
	int visina2, sirina2;
	double niz1[1000], niz2[1000];

	/*Unos dimenzije matrice A*/
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina1, &visina1);

	/*Unos elemenata matrice A*/
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < visina1; i++) {
		for(j = 0; j < sirina1; j++) {
			scanf("%lf", &A[i][j]);
		}
	}

	/*Unos dimenzije matrice B*/
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina2, &visina2);

	/*Unos elemenata matrice B*/
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < visina2; i++) {
		for(j = 0; j < sirina2; j++) {
			scanf("%lf", &B[i][j]);
		}
	}
	
	/*Formiranje niza koji se sastoji elemenata koji se nalaze u prvom redu matrice A*/
	
		k1 = 0;		 /*Postavljanje brojaca k1 na 0, a to je brojac elemenata niza1*/
		i = 0;		 /*Postavljanje brojaca i na 0 jer nam treba prvi red koji je definisan za i = 0*/
		
		for(j = 0; j < sirina1; j++) {	
			niz1[k1] = A[i][j];
			k1++;
		}

	/*Formiranje niza koji se sastoji od elemenata koji se nalaze u posljednjoj koloni matrice B*/
	
		j = sirina2 - 1;	/*Postavljanje brojaca j na vrijednost sirina2 - 1 jer to predstavlja posljednju kolonu matrice B*/
		k2 = 0;				/*Postavljanje brojaca k2 na 0, a to je brojac elemenata niza2*/
		for(i = 0; i < visina2; i++) {
			niz2[k2] = B[i][j];
			k2++;
		}
		
		/*Prolazak kroz elemente oba prethodno formirana niza i uporedjivanje istih*/
		for(i = 0; i < k1; i++) {
			if((niz1[i] != niz2[i]) || (visina1 != sirina2) || (sirina1 != visina2)){
				printf("NE");
			return 0;
			}
		}
		printf("DA");

	return 0;
}
