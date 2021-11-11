#include <stdio.h>

int main() {
	int niz1[1000], niz2[1000];
	int i, j, velicina, n, broj, red, k;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
		if(n <= 0 || n > 100) printf("Neispravna velicina!\n");
	}while(n <= 0 || n > 100);
	
	printf("Unesite clanove niza: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &niz1[i]);
		if(niz1[i] < 0) 
		{
			printf("Neispravan clan niza. Ponovite unos:\n");
			i--;
		}
	}
	velicina = 0;
	for(i = 0; i < n; i++)
	{
		red = 1;
		broj = niz1[i];
		while(broj / red > 9) red *= 10;
		while(red > 0)
		{
			niz2[velicina] = broj / red;
			broj -= niz2[velicina] * red;
			red/=10;
			velicina++;
		}
	}
	k = 0;
	for(i = 0; i < velicina; i++)
	{
		broj = niz2[i];
		j = i;
		while(j < velicina && niz2[j] == broj) j++;
		niz1[k++] = broj;
		niz1[k++] = j - i;
		i = j-1;
	}
	printf("Finalni niz glasi:\n");
	for(i = 0; i < k; i++)
		printf("%d ", niz1[i]);
	
	return 0;
}
