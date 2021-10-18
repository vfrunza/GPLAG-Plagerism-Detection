#include <stdio.h>

int main() {
	int n=8, i, j;
	
	do {
		if (n<8 || n%4!=0) printf ("Neispravno N!\n");
		printf ("Unesite broj N: ");
		scanf ("%d", &n);
	} while (n<8 || n%4!=0);
	printf ("\n");
	
	for (i=0; i<(n/2); i++) {
		for (j=0; j<n; j++) {
			if (i==j || i==n/2-j-1) {
				if (i==j) printf ("\\");
				if (i==n/2-j-1) printf ("/");
			}
			else if ((i==0 && j==n/2) || (i==0 && j==n-1) || (i==n/2-1 && j==n/2) || (i==n/2-1 && j==n-1)) printf ("+");
			else if ((i==0 && j>n/2) || (i==n/2-1 && j>n/2-1)) printf ("-");
			else if (j==n/2 || j==n-1) printf ("|");
			else printf (" ");
			
		}
		
		
		printf ("\n");
		
	}
	
	for (i = 0; i<n/2; i++) {
		for (j=0; j<n; j++) {
			if ((i==0 || i==n/2-1) && j<n/2) {
				if (j==0 || j==n/2-1) printf ("+");
				else if (j==n/2+2 || j==n/2+3) printf ("|");
				else if (j>n/2) printf (" ");
				else printf ("-");
			}
			else if (j==3*n/4-1 || j==3*n/4) {
				if (i==n/4-1 || i==n/4) {
					printf ("+");
				} else printf ("|");
			}
			else if(j==0 || j==n/2-1) printf ("|"); 
			else if ((i==n/4-1 || i==n/4) && j>=n/2) printf ("-");
			else printf (" ");
		}
		
		printf ("\n");
	}

	
	
	return 0;
}
