#include <stdio.h>


void sortiraj(int niz[], int vel) {

	int min;
	int i, j;
	int temp;
	
	for (i=0; i<vel; i++) {
		min=i;
		for(j=i+1; j<vel; j++){
			if(niz[j] < niz[min])
			min = j;
		}
		temp = niz[i];
		niz[i] = niz[min];
		niz[min] = temp;
	}
}

void ispisi(int niz[], int vel) {
	int i;
	printf("Sadrzaj niza: ");
	for (i=0; i<vel; i++) {
		printf("%d, ", niz[i]);
	}
	printf("\n");
}

int broj_zajednickih_medju_2_niza(int niz1[], int vel1, int niz2[], int vel2) {

	int total = 0;
	int i, j;
	int trenutni;
	
	for (i=0; i<vel1; i++) {
		/* ovako preskacemo duplikate*/
		if (i>0 && trenutni==niz1[i]) {
			continue;
		}
		trenutni = niz1[i];
		for (j=0; j<vel2; j++) {
			if (niz2[j] == trenutni) {
				total++;
				break;
			}
		}
	}

	return total;
}

int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	int i, j, k;
	int trenutni1 = 0;
	int brojac = 0;
	int rezultat = 0;

	int totalAB, totalBC, totalAC, totalABC;
	
	sortiraj(niz1, vel1);
	/* ispisi(niz1, vel1);*/
	sortiraj(niz2, vel2);
	/* ispisi(niz2, vel2);*/
	sortiraj(niz3, vel3);
	/* ispisi(niz3, vel3);*/
	
	totalAB = broj_zajednickih_medju_2_niza(niz1, vel1, niz2, vel2);
	totalAC = broj_zajednickih_medju_2_niza(niz1, vel1, niz3, vel3);
	totalBC = broj_zajednickih_medju_2_niza(niz2, vel2, niz3, vel3);
	

	totalABC = 0;
	for (i=0; i<vel1; i++) {
		if (i>0 && trenutni1==niz1[i]) {
			continue;
		}
		trenutni1 = niz1[i];
		brojac = 1;
		for (j=0; j<vel2; j++) {
			if (niz2[j] == trenutni1) {
				brojac++;
				break;
			}
		}
		for (k=0; k<vel3; k++) {
			if (niz3[k] == trenutni1) {
				brojac++;
				break;
			}
		}
		if (brojac == 3) {
			totalABC++;
		}
		
	}

	rezultat = totalAB + totalAC + totalBC - 3*totalABC;
	
	return rezultat;
}

int main() {
	int niz1[] = {1, 2, 3, 5}, niz2[] = {1, 2, 4, 6, 7}, niz3[] = {1, 3, 4, 8, 9, 10};
	int rez;
	rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	return 0;
}
