#include <stdio.h>

int izbaci_cifre (int *prvi_niz, int vel1, int *drugi_niz, int vel2) {
	int i=0,k=0, element, cifra[10], brojac=0, pom_niz[100], kon_niz[100];
	for (i=0; i<vel1; i++)
	    {
	    	element=prvi_niz[i];
	    	do {
	    		cifra[brojac]=element%10;
	    		brojac++;
	    		element/=10;
	    	} while (element);
	    	for (j=0; j<brojac; j++)
	    	    pom_niz[k+j]=cifra[brojac-j-1];
	        k+=brojac;	    
	    }
	for (i=0; i<k; i++)
	    for (j=0; j<vel2; j++)
	        {
	           if (pom_niz[i]==drugi_niz[j]) continue;
	           else kon_niz[i]=pom_niz[i];
}

int main() {
	int niz1[100], niz2 [10], vel_pr, vel_dr, i=0;
	scanf ("%d", &vel_pr);
	for (i=0; i<vel_pr; i++)
	    scanf ("%d", &niz1[i]);
    scanf ("%d", &vel_dr);
    for (i=0; i<vel_dr; i++)
        scanf ("%d", &niz2[i]);
	
	izbaci_cifre(niz1, vel_pr, niz2, vel_dr);
	for (i=0; i<vel_pr; i++)
	    printf ("%d", niz1[i]);
	return 0;
}
