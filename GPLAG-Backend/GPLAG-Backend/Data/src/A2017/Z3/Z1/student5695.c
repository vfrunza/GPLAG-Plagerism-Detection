#include <stdio.h>

int dva_od_tri(int prvi_niz[100], int velicina_prvog_niza, int drugi_niz[100], int velicina_drugog_niza, int treci_niz[100], int velicina_treceg_niza) {
	int i,j,k,povratna_vrijednost=0,brojac1,brojac2;
	/*provjerava pojavljivanje elemenata u dva od tri niza u odnosu na prvi niz*/
	for(i=0;i<velicina_prvog_niza;i++) {
		brojac1=0, brojac2=0;
		for(j=0;j<velicina_drugog_niza;j++) { 
			if(drugi_niz[j]==prvi_niz[i]) {
				for(k=0;k<i;k++) {
					if(prvi_niz[i]==prvi_niz[k]) { 
						brojac1--; 
						break; 
					}
				}
				brojac1++; 
				break; 
			}
		}
		for(k=0;k<velicina_treceg_niza;k++) { 
			if(treci_niz[k]==prvi_niz[i]) {
				for(j=0;j<i;j++) {
					if(prvi_niz[i]==prvi_niz[j]) { 
						brojac2--; 
						break; 
					}
				}
				brojac2++; 
				break; 
			}
		}
		if(brojac1!=brojac2) povratna_vrijednost++;
	}
	/*provjerava pojavljivanje elemenata u dva od tri niza u odnosu na drugi niz*/
	for(i=0;i<velicina_drugog_niza;i++) {
		brojac1=0, brojac2=0;
		for(j=0;j<velicina_prvog_niza;j++) { 
			if(prvi_niz[j]==drugi_niz[i]) {
				for(k=0;k<i;k++) {
					if(drugi_niz[i]==drugi_niz[k]) { 
						brojac1--; 
						break; 
					}
				}
				brojac1++; 
				break; 
			}
		}
		for(k=0;k<velicina_treceg_niza;k++) { 
			if(treci_niz[k]==drugi_niz[i]) {
				for(j=0;j<i;j++) {
					if(drugi_niz[i]==drugi_niz[j]) { 
						brojac2--; 
						break;
					}
				}
				brojac2++; 
				break; 
			}
		}
		if(brojac1!=brojac2 && brojac2!=0) povratna_vrijednost++;
	}
	return povratna_vrijednost;
}
int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}