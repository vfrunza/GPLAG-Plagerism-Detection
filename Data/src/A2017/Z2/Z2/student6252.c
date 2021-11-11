#include <stdio.h>
#define brelp 100
#define brelk 1000

int main() {
	double nizp[brelp]={0},nizk[brelk]={0};
	int n, i, brojac;
	
	do {
	printf ("Unesite velicinu niza: ");
	scanf ("%d", &n);
	} while (n<1 || n>100);
	
	for (i=0; i<n; i++) {
		printf ("Unesite clanove niza: ");
		scanf ("%d", &nizp[i]);
	}
	
	
	return 0;
}
