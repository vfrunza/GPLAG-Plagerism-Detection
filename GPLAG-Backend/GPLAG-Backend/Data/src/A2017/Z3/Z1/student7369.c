#include <stdio.h>
#include <math.h>

int dva_od_tri (int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3) {
	int i, j, k, velicina1=0, velicina2=0, velicina3=0, pomocna=0, br=0;
	int pomocniNiz1[100], pomocniNiz2[100], pomocniNiz3[100];
	
	/*presjek prvog i drugog niza*/
	for (i=0; i<vel1; i++) {
		for (j=0; j<vel2; j++) {
			if (niz1[i]==niz2[j]) {
				pomocna=0;
				for (k=0; k<velicina1; k++) {
					if (niz1[i]==pomocniNiz1[k]) {
						pomocna=1;
						break;
					}
				}
				if (pomocna==0) {
					pomocniNiz1[velicina1]=niz1[i];
					velicina1++;
				}
			}
		}
	}
	
	/*presjek prvog i treceg niza*/
	for (i=0; i<vel1; i++) {
		for (j=0; j<vel3; j++) {
			if (niz1[i]==niz3[j]) {
				pomocna=0;
				for (k=0; k<velicina2; k++) {
					if (niz1[i]==pomocniNiz2[k]) {
						pomocna=1;
						break;
					}
				}
				if (pomocna==0) {
					pomocniNiz2[velicina2]=niz1[i];
					velicina2++;
				}
			}
		}
	}
	
	/*presjek drugog i treceg niza*/
	for (i=0; i<vel2; i++) {
		for (j=0; j<vel3; j++) {
			if (niz2[i]==niz3[j]) {
				pomocna=0;
				for (k=0; k<velicina3; k++) {
					if (niz2[i]==pomocniNiz3[k]) {
						pomocna=1;
						break;
					}
				}
				if (pomocna==0) {
					pomocniNiz3[velicina3]=niz2[i];
					velicina3++;
				}
			}
		}
	}

	/*zajednicki elementi sva tri niza*/
	for (i=0; i<velicina1; i++) {
		for (j=0; j<velicina2; j++) {
			if (pomocniNiz1[i]==pomocniNiz2[j]) {
				for (k=0; k<velicina3; k++) {
					if (pomocniNiz1[i]==pomocniNiz3[k]) {
						br++;
					}
				}
			}
		}
	}
	
	br=velicina1+velicina2+velicina3-3*br;
	
	return br;
}

int main() {
	int prviNiz[100], drugiNiz[100], treciNiz[100], vel1, vel2, vel3, i;
	
	printf ("Unesite velicinu prvog niza: ");
	scanf ("%d", &vel1);
	
	printf ("Unesite prvi niz: ");
	for (i=0; i<vel1; i++) {
		scanf ("%d", &prviNiz[i]);
	}
	
	printf ("Unesite velicinu drugog niza: ");
	scanf ("%d", &vel2);

	printf ("Unesite drugi niz: ");
	for (i=0; i<vel2; i++) {
		scanf ("%d", &drugiNiz[i]);
	}
	
	printf ("Unesite velicinu treceg niza: ");
	scanf ("%d", &vel3);
	
	printf ("Unesite treci niz: ");
	for (i=0; i<vel3; i++) {
		scanf ("%d", &treciNiz[i]);
	}

	printf ("\n%d", dva_od_tri(prviNiz, vel1, drugiNiz, vel2, treciNiz, vel3));
	
	return 0;
}
