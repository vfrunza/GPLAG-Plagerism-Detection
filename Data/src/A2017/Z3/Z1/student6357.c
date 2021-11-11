#include <stdio.h>
int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int i,j,broj_razlicitih=0,broj,istiAB=0,istiAC=0,brojac=0,jednaki=-1234567890;
	for(i=0; i<vel1; i++) {
		broj=niz1[i];
		if(broj!=jednaki) {
			for(j=0; j<vel1; j++) {
				if(niz1[j]==broj) brojac++;
			}
			if(brojac>1) {
				brojac=0;
				jednaki=broj;
			}
			for(j=0; j<vel2; j++) {
				if(niz2[j]==broj) {
					istiAB++;
					break;
				}
			}
			brojac=0;
			for(j=0; j<vel3; j++) {
				if(niz3[j]==broj) {
					istiAC++;
					break;
				}
			}
			if(istiAC!=istiAB) broj_razlicitih++;
			istiAB=istiAC=0;
		}
	}
	jednaki=-1234567890;
	for(i=0; i<vel2; i++) {
		broj=niz2[i];
		if(broj!=jednaki) {
			for(j=0; j<vel2; j++) {
				if(niz2[j]==broj) brojac++;
			}
			if(brojac>1) {
				brojac=0;
				jednaki=broj;
			}
			brojac=0;
			for(j=0; j<vel1; j++) {
				if(niz1[j]==broj) {
					brojac++;
				}
			}
			if(brojac==0) {
				for(j=0; j<vel3; j++) {
					if(niz3[j]==broj) {
						broj_razlicitih++;
						break;
					}
				}
			}
			brojac=0;
		}
	}
	return broj_razlicitih;
}
int main()
{
	return 0;
}
