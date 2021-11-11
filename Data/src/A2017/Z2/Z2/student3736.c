#include <stdio.h>

int main() {
	int n, brojCifara = 0, brojac= 0,j = 0, k = 0, hljeb = 0;
	int i, niz[100] = {0}, nizCifara[1000] = {0}, cifre[1000] = {0};
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	}while(n>100 || n<=0);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++) {
		scanf("%d", &niz[i]);
	}
	int niz2[1000], broj;
	for(i = 0; i < n; i++)
	{
		brojac = 0;
		do {
			cifre[brojac] = niz[i] % 10;
			niz[i] /= 10;
			brojac++;
		} while(niz[i] != 0);
		for(j = hljeb , k = brojac-1; k >= 0; j++, k--, brojCifara++)
			nizCifara[j] = cifre[k];
		hljeb += brojac;
	}
	
	brojac = 0;
	for(i = 0, k = 0; i < brojCifara; k+=2)
	{
		brojac = 0;
		cifre[k] = nizCifara[i];
		for(j = i; j < brojCifara; j++)
		{
			if(nizCifara[i] != nizCifara[j])
				break;
			brojac++;
		}
		cifre[k+1] = brojac;
		i+=brojac;
	}
	
	printf("Finalni niz glasi:\n");
	for(i = 0; i < k; i++)
		printf("%d ", cifre[i]);
	return 0;
}
