#include <stdio.h>

int main() {
	int i,j,n,temp;
	
	printf ("Unesite broj N: ");
	do {
	   scanf ("%d", &temp);
	   if (temp<8 || temp%4!=0) {
	   printf ("Neispravno N!\n");
	   printf ("Unesite broj N: ");
	    }
	   else n=temp;
	}
	while (temp%4!=0 || temp<8);
	printf ("\n");
	
	/* Ispis "gornjeg dijela" (prvog i drugog kvadranta) */ 
	
	for (i=0; i<n/2; i++) {
		for (j=0; j<n; j++) {
			if (i==j) printf ("\\");
			else if (i+j==n/2-1) printf ("/");
			else if ((i==0 || i==n/2-1) && (j==n/2 || j==n-1)) printf ("+");
			else if ((i==0 && j>n/2) || (i==n/2-1 && j>n/2)) printf ("-");
			else if (j==n/2 || j==n-1) printf ("|");
			else printf (" ");
		}
		printf ("\n");
	}
	
	
	/* Ispis "donjeg dijela" (treceg i cetvrtog kvadranta) */
	
	for (i=n/2; i<n; i++ ) {
		for (j=0; j<n; j++) {
			if ( ((i==n/4*3-1 && j==n/4*3-1) || (i==n/4*3-1 && j==n/4*3) || (i==n/4*3 && j==n/4*3-1) || (i==n/4*3 && j==n/4*3)) || ((i==n/2 || i==n-1) && (j==0 || j==n/2-1)) ) printf ("+");
			else if ((j==0 || j==n/2-1) || (j==n/4*3 || j==n/4*3-1) ) printf ("|");
			else if ((i==n/2 && j<n/2) || (i==n-1 && j<n/2) || (i==n/4*3 && j>=n/2) || (i==n/4*3-1 && j>=n/2)) printf ("-");
			else printf (" ");
		}
		printf ("\n");
	}
	
	
	return 0;
}