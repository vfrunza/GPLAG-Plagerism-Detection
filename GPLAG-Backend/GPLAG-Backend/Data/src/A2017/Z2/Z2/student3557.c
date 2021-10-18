#include <stdio.h>
#include <math.h>

int main() {
	
	int i, n=0, b=0, nizA[100], nizB[1000], t;
	short c=0, brojac=0, pozicija=0;
	
	do{
		printf ("Unesite velicinu niza: ");
		scanf ("%d", &n);
	}while (n<1 && n>100);
	
	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++){
		scanf ("%d", &nizA[i]);
	}
	
	c=nizA[n-1] % 10;
	/*printf ("%d", c);*/
	
	for (i=n-1; i>=0; i--){
		b = nizA[i];
	
	    do{
		    if (c == b % 10){
			   brojac++;
		    }
		    else {
			    nizB[pozicija++] = brojac;
			    nizB[pozicija++] = c;
			    c = b % 10;
			    brojac = 1;
		    }
		    b /= 10;
	    }while (b>0);
	}
	
	nizB[pozicija++] = brojac;
	nizB[pozicija++] = c;
	
	for (i=0; i<pozicija/2; i++){
		t= nizB[i];
		nizB[i] = nizB[pozicija-1-i];
		nizB[pozicija-1-i] = t;
	}
	
	printf ("Finalni niz glasi:\n");
	for (i=0; i<pozicija; i++){
		if ( i!=0 && i!= pozicija){
			printf (" ");
		}
		printf ("%d", nizB[i]);
	}
	
	
	return 0;
}
