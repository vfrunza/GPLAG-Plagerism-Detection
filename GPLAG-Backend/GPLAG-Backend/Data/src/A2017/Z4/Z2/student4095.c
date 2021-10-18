#include <stdio.h>
void unesi(char niz[], int velicina)
{
	char znak = getchar();
	int i;
	if(znak != '\n') znak = getchar();
	i = 0;
	while(i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';

}

int provjeri_duzine(char *tekst, int *niz, int broj_clanova_niza)
{

	int broj_rijeci = 0;
	int broj_slova = 0;
	int istina = 1; /*ako pri prolasku kroz petlju nadjemo clan ciji broj slova nije podudaran sa odgovarajucim clanom niza brojeva, istina postaje 0*/
	int rijec = 1; /*govori da li je pokazivac *tekst na rijeci ili nije*/
	char *prva_rijec = tekst;

	while (!((*tekst >= 'A' && *tekst <= 'Z') || (*tekst >= 'a' && *tekst <= 'z'))) tekst++;
	while(*tekst != '\0') {
		if(!((*tekst >= 'A' && *tekst <= 'Z') || (*tekst >= 'a' && *tekst <= 'z')) && rijec == 1) {
			rijec = 0;
			broj_rijeci++;
		}
		if(((*tekst >= 'A' && *tekst <= 'Z') || (*tekst >= 'a' && *tekst <= 'z')) && *tekst != ' ' && *tekst != '\0') rijec = 1;
		tekst++;
	}

	tekst--;
	
	if(!((*tekst >= 'A' && *tekst <= 'Z') || (*tekst >= 'a' && *tekst <= 'z'))) broj_rijeci--;
	tekst++;
	if(*tekst == '\0') broj_rijeci++;

	if(broj_rijeci != broj_clanova_niza) return 0;

	tekst = prva_rijec;

	while(*tekst != '\0') {
		broj_slova = 0;
		if((*tekst >= 'A' && *tekst <= 'Z') || (*tekst >= 'a' && *tekst <= 'z')) {
			while((*tekst >= 'A' && *tekst <= 'Z') || (*tekst >= 'a' && *tekst <= 'z')) {
				broj_slova++;
				tekst++;
			}
			tekst--;
			if(*niz++ != broj_slova) istina = 0;
		}
		tekst++;
		
	if(istina == 0) return 0;
	
	}

	return 1;
}

int main()
{
	char tekst[1000];
	int niz[1000];
	int i;
	int broj_clanova_niza = 0;
	printf("Unesite tekst: ");
	unesi(tekst, 1000);
	printf("Unesite niz brojeva (-1 za kraj): ");
	for(i = 0 ; i < 1000 ; i++) {
		scanf("%d", &niz[i]);
		if(niz[i] == -1) break;
		if(niz[i] <= 0) {
			printf("Neispravan broj.");
			i--;
		}
		broj_clanova_niza++;
	}
	provjeri_duzine(tekst, niz, broj_clanova_niza);
	return 0;
}
