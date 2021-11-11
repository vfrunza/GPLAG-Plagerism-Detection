#include <stdio.h>

int postoji(int niz[], int vel_niza, int trazeni_br)
{
	int i;
	for(i=0; i<vel_niza; i++) {
		if(niz[i]==trazeni_br) return 1;
	}
	return 0;
}

int kopiraj(int niz1[], int vel1, int niz2[])
{
	int i, j, brojac=0;
	for(i=0; i<vel1; i++) {
		for(j=0; j<brojac; j++) {
			if(niz1[i]==niz2[j]) {
				break;
			}
		}
		if(j==brojac) {
			niz2[brojac]=niz1[i];
			brojac++;
		}
	}
	return brojac;
}

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int brojac=0, i;
	int kopija1[10000], kopija2[10000], kopija3[10000];
	vel1=kopiraj(niz1, vel1, kopija1);
	vel2=kopiraj(niz2, vel2, kopija2);
	vel3=kopiraj(niz3, vel3, kopija3);
	for(i=0; i<vel1; i++) {
		if((postoji(kopija2, vel2, kopija1[i])==0 && postoji(kopija3, vel3, kopija1[i])==1) || (postoji(kopija2, vel2, kopija1[i])==1 && postoji(kopija3, vel3, kopija1[i])==0)) brojac++;
	}
	for(i=0; i<vel2; i++) {
		if(postoji(kopija3, vel3, kopija2[i])==1 && postoji(kopija1, vel1, kopija2[i])==0) brojac++;
	}
	return brojac;
}

int main()
{
	/*	printf("Zadaća 3, Zadatak 1");*/
	return 0;
}
