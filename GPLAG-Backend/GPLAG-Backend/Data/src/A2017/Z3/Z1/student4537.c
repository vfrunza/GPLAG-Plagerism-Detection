/*Napisati funkciju dva_od_tri koja prima tri niza cijelih brojeva različite veličine, a vraća broj 
članova koji se javljaju u dva od tri niza (bez ponavljanja). Obratite pažnju da ne treba brojati članove
koji se nalaze u sva tri niza, nego samo one koji se nalaze u dva od tri niza!

Primjer: Recimo da nizovi glase ovako:
	1 2 3 5
	1 2 4 6 7
	1 3 4 8 9 10
Funkcija treba vratiti broj 3 jer:
Brojevi 2, 3 i 4 se nalaze u dva od tri niza. Broj 2 se nalazi u prvom i drugom, 3 u prvom i trećem, a 4 u
drugom i trećem.
Broj 1 se nalazi u sva tri niza pa ga ne brojimo.
Brojevi 5, 6, 7, 8, 9 i 10 se nalaze u samo po jednom nizu, pa ni njih ne računamo.
*/

#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3){
	int i,j,k, brojac1=0, brojac2=0;
	for (i=0; i<n1; i++){
		for (j=i+1; j<n1; j++){
			if (niz1[i]==niz1[j]){
			niz1[i]=niz1[n1-1];
			n1--;
			j--;
			}
		}
	}
	for (i=0; i<n2; i++){
		for (j=i+1; j<n2; j++){
			if (niz2[i]==niz2[j]){
			niz2[i]=niz2[n2-1];
			n2--;
			j--;
			}
		}
	}
	for (i=0; i<n3; i++){
		for (j=i+1; j<n3; j++){
			if (niz3[i]==niz3[j]){
			niz3[i]=niz3[n3-1];
			n3--;
			j--;
			}
		}
	}
	
	for (i=0; i<n1; i++){
		for (j=0; j<n2; j++){
			if (niz1[i]==niz2[j]){
				brojac1=0;
				for (k=0; k<n3; k++){
					if (niz2[j]!=niz3[k]) brojac1++;
				}
				if (brojac1==n3) brojac2++;
			}
		}
	}
	
	for (i=0; i<n1; i++){
		for (j=0; j<n3; j++){
			if (niz1[i]==niz3[j]){
				brojac1=0;
				for (k=0; k<n2; k++){
					if (niz3[j]!=niz2[k]) brojac1++;
				}
				if (brojac1==n2) brojac2++;
			}
		}
	}
	for (i=0; i<n2; i++){
		for (j=0; j<n3; j++){
			if (niz2[i]==niz3[j]){
				brojac1=0;
				for (k=0; k<n1; k++){
					if (niz3[j]!=niz1[k]) brojac1++;
				}
				if (brojac1==n1) brojac2++;
			}
		}
	}
	return brojac2;

}
int main() {
	
	return 0;
}
