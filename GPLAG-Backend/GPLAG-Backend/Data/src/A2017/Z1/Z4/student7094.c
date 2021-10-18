#include <stdio.h>

int main() {
	int a,b,c;
	int i,j,k;
	
	do {
	printf("Unesite broj redova: ");
	scanf ("%d", &a);
	} while (a<1 || a>10);
	
	do { 
	printf ("Unesite broj kolona: ");
	scanf ("%d", &b);
	} while (b<1 || b>10);
	 
	 do {
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &c);
	 } while (c<1 || c>10);
	
	for (i=0; i<a; i++) {
		for (j=0; j<b; j++){
		printf ("+");
		for (k=0; k<c; k++){
		printf("-");
		}
	}
	printf ("+\n");
	
	for (j=0; j<b; j++){
		printf("|");
		for (k=0; k<c; k++){
		printf (" ");
		}
	}
	printf ("|\n");
	}
		for (j=0; j<b; j++){
		printf ("+");
		for (k=0; k<c; k++){
		printf("-");
		}
		}
	printf ("+");
	return 0;
}
