#include <stdio.h>

int main() {
	int N, i, j;
	
	do {
	printf ("Unesite broj N: ");
	scanf ("%d", &N);
	if (N<8 || N%4!=0)
	printf ("Neispravno N!\n");
	}
	while (N<8 || N%4!=0); 
	
	/* red 1 */
	printf ("\n\\");
	for (i=0; i<N/2-2; i++)
		printf (" ");
	printf ("/+");
	for (i=0; i<N/2-2; i++)
		printf ("-");
	printf ("+"); 
	
	/* Opadajuci redovi za X */
	printf ("\n");
	for (i=1; i<=N/4-1; i++) {
		
		for (j=0; j<i; j++)
		printf (" ");
		printf ("\\");
		
		for (j=0; j<N/2-2-(2*i); j++)
		printf (" ");
		printf ("/");
		
		for (j=0; j<i; j++)
		printf (" ");
		printf ("|");
		
		for (j=0; j<N/2-2; j++)
		printf (" ");
		printf ("|\n");
	}
	
	/* Rastuci redovi za X */
	for (i=0; i<N/4-1; i++) {
		
		for (j=0; j<((N/2-2)/2)-i; j++)
		printf (" ");
		printf ("/");
		
		for (j=0; j<2*i; j++)
		printf (" ");
		printf ("\\");
		
		for (j=0; j<((N/2-2)/2)-i; j++)
		printf (" ");
		printf ("|");
		
		for (j=0; j<N/2-2; j++)
		printf (" ");
		printf ("|\n");
	}
	
	/* red N */
	printf ("/");
	for (i=0; i<N/2-2; i++)
		printf (" ");
	printf ("\\+");
	for (i=0; i<N/2-2; i++)
		printf ("-");
	printf ("+");
	
	/* --------------------------------------------- */
	
	/* red 1 */
	printf ("\n+");
	for (i=0; i<N/2-2; i++)
		printf ("-");
	printf ("+");
	for (i=0; i<((N/2-2)/2); i++)
		printf (" ");
	printf ("||");
	for (i=0; i<((N/2-2)/2); i++)
		printf (" ");
	printf ("\n");
	
	
	for (i=0; i<N/4-2; i++) {
		printf ("|");
		for (j=0; j<N/2-2; j++)
			printf (" ");
		printf ("|");
		for (j=0; j<((N/2-2)/2); j++)
			printf (" ");
		printf ("||");
		for (j=0; j<((N/2-2)/2); j++)
			printf (" "); 
		printf ("\n");
	}


	/* srednja 2 reda */
	for (i=0; i<2; i++) {
		printf ("|");
		for (j=0; j<N/2-2; j++)
			printf (" ");
		printf ("|");
		for (j=0; j<((N/2-2)/2); j++)
			printf ("-");
		printf ("++");
		for (j=0; j<((N/2-2)/2); j++)
			printf ("-");
		printf ("\n"); }
	
	
		for (i=0; i<N/4-2; i++) {
		printf ("|");
		for (j=0; j<N/2-2; j++)
			printf (" ");
		printf ("|");
		for (j=0; j<((N/2-2)/2); j++)
			printf (" ");
		printf ("||");
		for (j=0; j<((N/2-2)/2); j++)
			printf (" ");
		printf ("\n");
		}


 	/* red N */
 	printf ("+");
	for (i=0; i<N/2-2; i++)
		printf ("-");
	printf ("+");
	for (i=0; i<((N/2-2)/2); i++)
		printf (" ");
	printf ("||"); 

	return 0;
}
