#include <stdio.h>

int main() {
	int i,j,k,R,K,S;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &R); }
		while (R<=0 || R>10);
	do {
		printf ("Unesite broj kolona: ");
		scanf ("%d", &K); }
		while (K<=0 || K>10);
	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &S); }
		while (S<=0 || S>10);
		
	for (i=0; i<R+1; i++) {
	for (j=0; j<K+1; j++) { 
		printf("+");
		if (j==K)
		break ;
	for (k=0; k<S; k++) 
		printf ("-"); }
		if (i==R)
		break;
		printf ("\n"); 
	for (j=0; j<K+1; j++) {
		printf("|");
	for (k=0; k<S; k++)
		printf(" "); }
		printf ("\n"); }

return 0;
}
