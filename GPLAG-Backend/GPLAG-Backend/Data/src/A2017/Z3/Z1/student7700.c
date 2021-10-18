/*#include <stdio.h>
int dva_od_tri(int *niz1, int duz1, int *niz2, int duz2, int *niz3,int duz3)//Funkcija vraca broj clanova koji se nalaze u dva od tri proslijedjena niza
{
	int i,j,k,g;
	int brojac=0;

	for(i=0; i<duz1; i++) {
		for(g=0; g<i; g++) {
			if(niz1[i]==niz1[g]) break; //Prolazak kroz niz i provjeravanje clanova jer je moguce ponavljivanje istih clanova
		}
		if(g==i) { //Ako se desi da je g==i nije pronaslo iste clanove u prvom nizu
			for(j=0; j<duz2; j++) {
				if (niz1[i]==niz2[j]) {
					for(k=0; k<duz3; k++) {//Nakon sto je nasao iste clanove u prvom i drugom nizu provjerava treci niz
						if(niz1[i]==niz3[k]) break; //Ako se desi da isti clan postoji u sva tri niza, provjeravanje se prekida
					}
					if (k==duz3) {//Ako dodje do kraja treceg niza a ne nadje clan koji smo prethodno nasli u prvom i drugom onda uvecavamo brojac koji broji pojavljivanje clana u 2 od 3 niza
						brojac++;
						break;
					}
				}
			}
		}
	}
	for(i=0; i<duz2; i++) {
		for(g=0; g<i; g++) {
			if(niz2[i]==niz2[g]) break;
		}
		if(g==i) {
			for(j=0; j<duz3; j++) {
				if (niz2[i]==niz3[j]) {
					for(k=0; k<duz1; k++) {
						if(niz2[i]==niz1[k]) break;
					}
					if (k==duz1) {
						brojac++;
						break;
					}
				}
			}
		}
	}
	for(i=0; i<duz1; i++) {
		for(g=0; g<i; g++) {
			if(niz1[i]==niz1[g]) break;
		}
		if(g==i) {
			for(j=0; j<duz3; j++) {
				if (niz1[i]==niz3[j]) {
					for(k=0; k<duz2; k++) {
						if(niz1[i]==niz2[k]) break;
					}
					if (k==duz2) {
						brojac++;
						break;
					}
				}
			}
		}
	}
	return brojac;
}
int main()
{
	int niz1[]= {1,3,3};
	int niz2[]= {1,4,5};
	int niz3[]= {3,2,8};
	printf("%d",dva_od_tri(niz1,3,niz2,3,niz3,3));

	return 0;
}*/

