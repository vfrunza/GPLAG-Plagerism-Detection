#include <stdio.h>

int main()
{
	int niz[100], brojaci[1000]= {0}, finalni[200], pom[200];
	int i, j, n, x, vel = 0, temp;
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while(n<1 || n>100);

	printf("Unesite clanove niza: ");
	for(i = 0; i < n; i++)
		scanf("%d", &niz[i]);

	j = 0;
	for(i = 0; i < n; i++) {
		while(niz[i] != 0) {
			pom[j++] = niz[i] % 10;
			niz[i] /= 10;
		}
		for(k = 0; k < j / 2; k++)
			pom[k] = pom[k - 1];
	}
	vel = j;
	printf("Finalni niz glasi: \n");
	for(i = 0; i < vel; i++)
		printf("%d ", pom[i]);
	return 0;
}
