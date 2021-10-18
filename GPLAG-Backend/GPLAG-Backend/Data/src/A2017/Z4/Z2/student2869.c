#include <stdio.h>

int provjeri_duzine(char *string, int niz[], int duzina_niza)
{
	int velicina_rijeci;
	int i=0;

	while(*string != '\0') {
		if(duzina_niza <= i) return 0;
		velicina_rijeci = 0;
		while(  ( (*string < 'a' || *string > 'z')   &&  (*string < 'A' || *string > 'Z') )  &&  *string != '\0') string++;

		while(  ( (*string >= 'a' && *string <= 'z') || (*string >= 'A' && *string <= 'Z')  ) && *string != '\0') {
			velicina_rijeci++;
			string++;
		}
		if(velicina_rijeci != niz[i]) return 0;
		while((*string < 'a' || *string > 'z') && (*string < 'A' || *string > 'Z') && *string != '\0') string++;

		i++;
	}
	if(i < duzina_niza) return 0;

	return 1;
}

int main()
{
	/* AT1: Primjer iz zadatka */
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 6};
	int bezveze_niz[] = {1, 2, 3, 4, 5};

	printf("%d ", provjeri_duzine(tekst, niz, 5));
	printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));
	return 0;

}
