#include <stdio.h>


void zaokruzi1 (float *niz, int vel) {
	int i=0;
	for (i=0; i<vel; i++)
	    {
	       if (niz[i]>0) niz[i]=(int) (niz[i]*10+0.5)/10.0;
	       else niz[i]=(int) (niz[i]*10-0.5)/10.0;
	    }   
}

void preslozi (float *prim_niz, int vel_niza, int k) {
	int i, j, cifra, element, suma, velA=0, velB=0, nizA[100], nizB[100], nizC[100];
	zaokruzi1(prim_niz, vel_niza);
	for (i=0; i<vel_niza; i++)
	    {
	    	suma=0;
	    	element=prim_niz[i]*10;
	    	if (element<0) element=-element;
	    	do {
	    		cifra=element%10;
	    		suma+=cifra;
	    		element/=10;
	    	} while (element);
	        if (suma>=k)
	           {
	           	  nizA[i]=prim_niz[i];
	           	  velA++;
	           }
	        else  {
	        	nizB[i]=prim_niz[i];
	        	velB++;
	        } 
	     }
	 for (i=0; i<velA; i++)
	     nizC[i]=nizA[i];
	 for (i=velA; i<velB; i++)
	     nizC[i+velA]=nizB[i];
}
int main() {
	int i=0, vel, br;
	float neki_niz[100];
	scanf ("%d", &vel);
	for (i=0; i<vel; i++)
	  	scanf ("%f", &neki_niz[i]);
	    	
	scanf ("%d", &br);
	printf ("Niz glasi:");
	preslozi(neki_niz, vel, br);
	for (i=0; i<vel; i++)
	    printf ("%g", neki_niz[i]);    
	return 0;
}
