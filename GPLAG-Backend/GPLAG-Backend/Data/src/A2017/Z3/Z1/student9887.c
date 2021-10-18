#include <stdio.h>

/* funkcija provjerava da li se proslijedeni broj N nalazi u proslijedenom nizu */
int pomocna(int *niz, int vel, int N)
{
	int i;
	for(i=0; i<vel; i++) {
		if(niz[i]==N) return 1;
	}
	return 0;
}


int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3)
{
	int br_ponovljenih=0, i;
	for(i=0; i<vel1; i++) {
		/* provjeravamo da li se niz1[i] vec ranije pojavljivao u niz1 */
		if(pomocna(niz1,i,niz1[i])==0) {
			/* provjeravamo da li se niz1[i] javlja u jos nekom od proslijedenih nizova */
			if(pomocna(niz2,vel2,niz1[i])==1 && pomocna(niz3,vel3,niz1[i])==0) {
				br_ponovljenih++;
			} else if (pomocna(niz2,vel2,niz1[i])==0 && pomocna(niz3,vel3,niz1[i])==1) {
				br_ponovljenih++;
			}
		}
	}

	for(i=0; i<vel2; i++) {
		/* provjeravamo da li se niz2[i] vec ranije pojavljivao u niz2 */
		if(pomocna(niz2,i,niz2[i])==0) {
			/* provjeravamo da li se niz2[i] javlja u niz3 */
			if(pomocna(niz3,vel3,niz2[i])==1 && pomocna(niz1,vel1,niz2[i])==0) br_ponovljenih++;
		}
	}

	return br_ponovljenih;
}

int main()
{

	return 0;
}
