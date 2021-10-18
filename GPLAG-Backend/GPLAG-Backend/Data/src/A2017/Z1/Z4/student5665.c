#include <stdio.h>

int main() {
	int r, c, s;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &r); }
	while (r<1 || r>10);
	
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &c); }
	while (c<1 || c>10);
	
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &s); }
	while (s<1 || s>10);
	
	int i, j, k;
	for (i=1; i<=2*r+1; i++) {
		
		if (i%2==0) {
			for (j=1; j<=c; j++) {
			printf ("|");
			for (k=1; k<=s; k++)
			printf (" "); }
			printf ("|\n"); }
			
		else {
			for (j=1; j<=c; j++) {
			printf ("+");
			for (k=1; k<=s; k++)
			printf ("-"); }
			printf ("+\n"); }
	} 
	
	return 0;
}
