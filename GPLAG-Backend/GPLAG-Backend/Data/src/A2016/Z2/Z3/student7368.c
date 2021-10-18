#include <stdio.h>
int main () {
	int i, j, broj, kolone, redovi;
	int mat[20][20];
	do {
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &broj);
		if (broj<=0 || broj>10) {
			printf ("Pogresan unos\n");
		}
	}
	while (broj>10 || broj<=0);
	
	for (i=0; i<20; i++){
		for (j=0; j<20; j++) {
			mat[i][j]=0;
		}
	}
	for (i=0; i<broj; i++){
		printf ("Unesite %d. tacku: ",i+1);
		scanf ("%d %d", &kolone, &redovi);
		if (kolone<0 || redovi<0 || kolone>=20 || redovi>=20) {
			do {
				printf ("Pogresan unos\n");
			printf ("Unesite %d. tacku: ",i+1);
			scanf ("%d %d", &kolone, &redovi);
		}
		while (kolone<0 || redovi<0 || kolone>=20 || redovi >=20);
	}
	mat[redovi][kolone]=1;
	}
	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			if (mat[i][j]==1) printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
	
	