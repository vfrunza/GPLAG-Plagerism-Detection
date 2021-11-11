#include <stdio.h>

int main() {
	int niz[100], i, broj, konacni_niz[1000], cifra, pomocni[1000]={0}, brojac_ponavljanja, vel, vel_pom;
	brojac_ponavljanja=1; vel=0, vel_pom=0;
	printf ("Unesite velicinu niza: ");
	scanf("%d", &broj);
	printf ("Unesite clanove niza: ");
	for (i=0; i<broj; i++) {
		scanf ("%d ", &niz[i]);
	}
	for (i=broj-1; i>=0; i--) {
		if (niz[i]==0) {
			pomocni[vel_pom]=niz[i];
			vel_pom++;
		}
		while (niz[i]!=0) {
		cifra=niz[i]%10;
		niz[i]=niz[i]/10;
		pomocni[vel_pom]=cifra;
		vel_pom++;
		}
	}
	/*for (i=vel_pom-1; i>=0; i--) {
		printf ("%d,", pomocni[i]);
	}*/
	for (i=vel_pom-1; i>=0; i--) {
		if (i>=0) {
			 if (i!=0 && pomocni[i]==pomocni[i-1]) {
			 	brojac_ponavljanja++;
			 	continue;
			 }
			 else {
			 	konacni_niz[vel]=pomocni[i];
			 	konacni_niz[vel+1]=brojac_ponavljanja;
			 	vel+=2;
			 }
		}
		if(i!=0 && pomocni[i] != pomocni[i-1]) brojac_ponavljanja=1;

	}
	printf ("Finalni niz glasi:\n");
	for (i=0; i<vel; i++) {
		if (i==vel-1) printf ("%d", konacni_niz[i]);
		else printf ("%d ", konacni_niz[i]);
	}
	return 0;
}
