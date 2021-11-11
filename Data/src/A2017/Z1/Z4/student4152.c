#include <stdio.h>

int main() {
	int n, r, j, k, s, i, l, p, u, a ;
	 
	 do {
	printf("Unesite broj redova: ");
	scanf ("%d", &r);
	 } while (r<=0 || r>10);
	 
	 do {
	printf ("Unesite broj kolona: ");
	scanf ("%d", &k);
	 } while (k<=0 || k>10);
	 
	do {
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &s);
	} while (s<=0 || s>10);

	
	for (n=0 ; n<r ; n++) {
	for (j=0 ; j<k ; j++) {
		printf ("+");
		for(i=0 ; i<s ; i++)
		printf ("-"); 
		
	}
		printf ("+\n");
		
		
		for (l=0 ; l<k ; l++){ 
		printf("|") ;
		for (p=0 ; p<s ; p++)
		printf (" ");
	}
	   printf ("|\n");
		
	
			}
					
	for (u=0 ; u<k ; u++) {
		printf ("+");
		for(a=0 ; a<s ; a++)
		printf ("-"); 
		
	}
		printf ("+\n");
			
	
	
	
	 
		return 0;
}
