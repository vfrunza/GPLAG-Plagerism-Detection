#include <stdio.h>
#define BROJ_EL 100
#define limit 1000
int main() {
	int niz[BROJ_EL],n, histogram[BROJ_EL+1],konacni_niz[limit];
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++){
		scanf("%d", &niz[i]);
	}
	return 0;
}
