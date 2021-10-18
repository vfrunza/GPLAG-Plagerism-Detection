#include <stdio.h>

int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	
	int i, j, k, br=0;
	
	for (i=0; i<vel1; i++) {
		for (j=0; j<vel2; j++) {
			for (k=0; k<vel3; k++) {
				
				if ( *niz1==*niz2 && *niz1!=*niz3 && *niz2!=*niz3 )	br++;
				if ( *niz1==*niz3 && *niz1!=*niz2 && *niz3!=*niz2 )	br++;
				if ( *niz2==*niz3 && *niz2!=*niz1 && *niz3!=*niz1 )	br++;
				niz1++; niz2++; niz3++;
			}
		}
	}
	return br;
}

int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
