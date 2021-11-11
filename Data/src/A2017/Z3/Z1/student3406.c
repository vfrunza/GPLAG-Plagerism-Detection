#include <stdio.h>

int dva_od_tri(int niz1[], int  velicina1, int niz2[], int  velicina2, int niz3[], int  velicina3) {
	int i=0, j, k, brojac1, brojac2, broj1, pomocni=0;
	
	while(i < velicina1) {
		broj1=niz1[i];
		brojac1=0;
		 for(j=0; j<velicina2; j++) {
		 	if(broj1==niz2[j]) brojac1++;
		 }
		 brojac2=0;
		 for(k=0; k<velicina3; k++) {
		 	if(broj1==niz3[k]) brojac2++;
		 }
		 
		 if ((brojac1==1 && brojac2!=1) || (brojac1!=1 && brojac2==1)) pomocni++;
		 i++;
	}
	return pomocni;
}

int main() {
	int niz1[] = {1, 2, 3, 5};
	int niz2[] = {1, 2, 4, 6, 7};
	int niz3[] = {1, 3, 4, 8, 9, 10};
	int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
	return 0;
}
