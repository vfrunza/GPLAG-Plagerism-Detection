#include <stdio.h>
#include <math.h>
#define EPSILON 0.01

void zaokruzi1 (float* niz, int velicina) {
	int i;
	for (i=0; i<velicina; i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	    
	}
}

void preslozi (float* niz, int velicina, int k) {
	float suma=0, pomocniNiz1[100], pomocniNiz2[100];
	int i, vel=0, pomocnibrojac=0, pombrojac2=0, cifra=1, brojcifara=1;
	
    zaokruzi1 (niz, velicina);
    
    for (i=0; i<velicina; i++) {
    	suma=0;
    	cifra=niz[i];
    	while (cifra!=0) {
    		cifra=cifra/10;
    		brojcifara++;
    	}
    	
    	cifra=niz[i]*10;
    	while (cifra!=0) {
    		suma+=cifra%10;
    		cifra=cifra/10;
    	}
    		
    	if (fabs(suma)>=k) {
    		pomocniNiz1[pomocnibrojac]=niz[i];
    		vel++;
    		pomocnibrojac++;
    	} else {
    		pomocniNiz2[pombrojac2]=niz[i];
    		pombrojac2++;
    	}
    }
    
    pomocnibrojac=0;
    for (i=0; i<velicina; i++) {
    	if (i<vel) niz[i]=pomocniNiz1[i];
    	else {
    		niz[i]=pomocniNiz2[pomocnibrojac];
    		pomocnibrojac++;
    	}
    	
    }
    
}

int main() {
	float niz[100];
	int velicina, k, i;
	printf ("Unesite velicinu niza: ");
	scanf ("%d", &velicina);
	printf ("Unesite k: ");
	scanf ("%d", &k);
	printf ("Unesite niz: ");
	for (i=0; i<velicina; i++) {
		scanf ("%f", &niz[i]);
	}
	
	
	preslozi (niz, velicina, k);
	printf ("\n");
	for (i=0; i<velicina; i++) {
		printf ("%.1f ", niz[i]);
	}
	
	return 0;
}
