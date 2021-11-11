#include <stdio.h>
/* Krampanje > olaksice :'( */

int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int i,j,k,l;
	int brojac=0;
	/* U narednoj petlji provjeravam da li se u nizu nalaze cifre koje se ponavljaju */
	for (i=0; i<vel1; i++) {
		for (j=0; j<i; j++) {
			if (niz1[i]==niz1[j] && i!=j) {
				break;
			}
		}
		if (i==j) {							/* Sada poredim prvi sa drugim i drugi sa trecim */
			for (k=0; k<vel2; k++) {
				if (niz1[i]==niz2[k]) {
					for (l=0; l<vel3; l++)
						if(niz2[k]==niz3[l]) {
							break;
						}
					if (l==vel3) {
						brojac++;
						break;
					}
				}
			}
		}
	}
	/* Analogno prethodnom poredjenju poredim ostale clanove */
	for (i=0; i<vel2; i++) {
		for (j=0; j<i; j++) {
			if (niz2[i]==niz2[j] && i!=j) {
				break;
			}
		}
		if (i==j) {
			for (k=0; k<vel3; k++) {
				if (niz2[i]==niz3[k]) {
					for (l=0; l<vel1; l++)
						if(niz3[k]==niz1[l]) {
							break;
						}
					if (l==vel1) {
						brojac++;
						break;
					}
				}
			}
		}
	}

	for (i=0; i<vel3; i++) {
		for (j=0; j<i; j++) {
			if (niz3[i]==niz3[j] && i!=j) {
				break;
			}
		}
		if (i==j) {
			for (k=0; k<vel1; k++) {
				if (niz3[i]==niz1[k]) {
					for (l=0; l<vel2; l++)
						if(niz1[k]==niz2[l]) {
							break;
						}
					if (l==vel2) {
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
	int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int niz2[] = {3, 3, 3, 2, 2};
	int niz3[] = {1, 3, 4};


	int rez = dva_od_tri (niz1, 11, niz2, 5, niz3, 3);

	printf ("%d", rez);
	return 0;
}
