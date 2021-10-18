#include <stdio.h>
#define br_el 100
int main() {
	int niz[br_el];
	int n;
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while(n<=0 || n>100);
	for (i=0;i<n;i++) {
	printf("Unesite clanove niza: ");
	scanf("%d", &niz[i]);
	}
	
	return 0;
}
