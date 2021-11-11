#include <stdio.h>

int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3)
{
	int brojac=0;
	int i,j;
	int brojac1;
	int ima_u_prvom;
	int idi_dalje;
	for(i=0; i<vel1; i++) {
		brojac1=0;
		idi_dalje=0;
		for(j=0; j<i; j++) {
			if(niz1[i]==niz1[j]) {
				idi_dalje=1;
				break;
			}
		}
		if(idi_dalje) continue;
		for(j=0; j<vel2; j++) {
			if(niz1[i]==niz2[j]) {
				brojac1++;
				break;
			}
		}
		for(j=0; j<vel3; j++) {
			if(niz1[i]==niz3[j]) {
				brojac1++;
				break;
			}
		}
		if(brojac1==1) brojac++;
	}
	for(i=0; i<vel2; i++) {
		idi_dalje=0;
		for(j=0; j<i; j++) {
			if(niz2[i]==niz2[j]) {
				idi_dalje=1;
				break;
			}
		}
		if(idi_dalje) continue;
		ima_u_prvom=0;
		for(j=0; j<vel1; j++) {
			if(niz2[i]==niz1[j]) {
				ima_u_prvom=1;
				break;
			}
		}
		if(ima_u_prvom) continue;
		for(j=0; j<vel3; j++) {
			if(niz2[i]==niz3[j]) {
				brojac++;
				break;
			}
		}
	}
	return brojac;
}

int main()
{
	return 0;
}
