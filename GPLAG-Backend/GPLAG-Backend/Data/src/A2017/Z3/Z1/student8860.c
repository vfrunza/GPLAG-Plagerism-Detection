#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3)
{
	int i, j, k, br=0, niz4[100000], niz5[100000], niz6[100000], vel4=vel1, vel5=vel2, vel6=vel3;

	/* Ako su nizovi jednaki trebamo vratiti 0 */
	if(niz1==niz2 && niz1==niz3 && niz2==niz3)
		return 0;

	/* Stavljamo nizove u pomocne nizove */
	for(i=0; i<vel1; i++)
		niz4[i]=niz1[i];

	for(i=0; i<vel2; i++)
		niz5[i]=niz2[i];

	for(i=0; i<vel3; i++)
		niz6[i]=niz3[i];
	/* Iz nizova izbacujemo clanove koji se ponavljaju */
	for(i=0; i<vel1; i++) {
		for(j=i+1; j<vel1; j++) {
			if(niz1[j]==niz1[i]) {
				for(k=j; k<vel1-1; k++)
					niz1[k]=niz1[k+1];
				vel1--;
				j--;
			}

		}
	}

	for(i=0; i<vel2; i++) {
		for(j=i+1; j<vel2; j++) {
			if(niz2[j]==niz2[i]) {
				for(k=j; k<vel2-1; k++)
					niz2[k]=niz2[k+1];

				vel2--;
				j--;
			}
		}
	}

	for(i=0; i<vel3; i++) {
		for(j=i+1; j<vel3; j++) {
			if(niz3[j]==niz3[i]) {
				for(k=j; k<vel3-1; k++)
					niz3[k]=niz3[k+1];

				vel3--;
				j--;
			}
		}
	}
	/* Brojimo koliko puta se clanovi niza ponavljaju u nizovima */
	i=0;
	while(i<vel1) {
		for(j=0; j<vel2; j++)
			if(niz1[i]==niz2[j])
				br++;
		i++;
	}

	i=0;
	while(i<vel2) {
		for(j=0; j<vel3; j++)
			if(niz2[i]==niz3[j])
				br++;

		i++;
	}

	i=0;
	while(i<vel1) {
		for(j=0; j<vel3; j++)
			if(niz1[i]==niz3[j])
				br++;
		i++;
	}
	/* Smanjujemo brojac za cifre koje se ponavljaju u svim nizovima */
	for(i=0; i<vel1; i++) {
		for(j=0; j<vel2; j++) {
			for(k=0; k<vel3; k++) {
				if(niz1[i]==niz2[j] && niz1[i]==niz3[k] && niz2[j]==niz3[k])
					br=br-3;
			}
		}
	}
	/* Vracamo vrijednosti nizova iz pomocnih nizova */
	for(i=0; i<vel4; i++)
		niz1[i]=niz4[i];

	for(i=0; i<vel5; i++)
		niz2[i]=niz5[i];

	for(i=0; i<vel6; i++)
		niz3[i]=niz6[i];

	return br;
}

int main()
{

	return 0;
}
