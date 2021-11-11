#include <stdio.h>
#include <stdlib.h>
int izbaciDuple(int niz[],int vel) {
	int i,j,k;
	for(i=0;i<vel;i++) {
		for(j=i;j<vel-1;j++) {
			if(niz[j+1]==niz[i]) {
				for(k=j+1;k<vel-1;k++) {
					niz[k]=niz[k+1];
				}
				j--;
				vel--;
			}
		}
	}
	return vel;
}
int dva_od_tri(int PrviNiz[],int vel1,int DrugiNiz[],int vel2,int TreciNiz[],int vel3) {
	
	int i,pozHist[10000] = {0},negHist[10000] = {0},brojac=0;
	
	// Pravim kopije originalnih nizova da izbjegnem modifikovanje
	int niz1[10000],niz2[10000],niz3[10000];
	for(i=0;i<vel1;i++) 
		niz1[i]=PrviNiz[i];
	for(i=0;i<vel2;i++) 
		niz2[i]=DrugiNiz[i];
	for(i=0;i<vel3;i++) 
		niz3[i]=TreciNiz[i];
	
	vel1 = izbaciDuple(niz1,vel1);
	vel2 = izbaciDuple(niz2,vel2);
	vel3 = izbaciDuple(niz3,vel3);
	
	// Histogram nizova
	for(i=0;i<vel1;i++) {
		if(niz1[i] >= 0)
		// Pozitivni brojevi
			pozHist[niz1[i]]++;
		else 
		// Negativni brojevi
			negHist[abs(niz1[i])]++;
	}

	for(i=0;i<vel2;i++) {
		if(niz2[i] >= 0)
		// Pozitivni brojevi
			pozHist[niz2[i]]++;
		else 
		// Negativni brojevi
			negHist[abs(niz2[i])]++;
	}
	for(i=0;i<vel3;i++) {
		if(niz3[i] >= 0)
		// Pozitivni brojevi
			pozHist[niz3[i]]++;
		else 
		// Negativni brojevi
			negHist[abs(niz3[i])]++;
	}

	for(i=0;i<10000;i++) {
		if(pozHist[i]==2)
			brojac++;
		if(negHist[i]==2)
			brojac++;
	}
	return brojac;
}
int main() {
	/*int i;

	int niz1[] = {3,4,5};
	int niz2[] = {4,4,4};
	int niz3[] = {7,8,9};
	
	int rez = dva_od_tri(niz1, 3, niz2, 2, niz3, 0);

	printf("\n%d ", rez);
	printf("\n"); */
	
	return 0;
}

	
