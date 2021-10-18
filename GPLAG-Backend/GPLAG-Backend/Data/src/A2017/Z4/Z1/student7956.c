#include <stdio.h>

void unesi (char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

char* ubaci_broj (char* tekst, int broj)
{
	char* pamti = tekst, *kraj;
	int broj_char_broja = 0, brojac_razmamka = 0;
	char* kraj_rijeci;

	int temp = broj;
	int velicina = 0;

	while (*tekst != '\0') {
		velicina++;
		tekst++;
	}

	tekst = pamti;

	if(broj != 0) {

		if(broj < 0) {

			temp = (-1)*temp;
			broj_char_broja++;
		}

		while (temp != 0) {
			temp /= 10;
			broj_char_broja++;
		}

	}

	else broj_char_broja  = 1 ;


	while (*tekst == ' ') tekst++;
	tekst++;

	while(*tekst != '\0') {
		if(*tekst == ' ') {

			tekst++;

			kraj = pamti + velicina - 1;

			while (*tekst != '\0' && kraj >= tekst) {
				*(kraj + broj_char_broja +1 ) = *kraj ;
				kraj--;
			}

			kraj = kraj + broj_char_broja + 1;

			*kraj = ' ';
			kraj--;
			temp = broj;

			if (broj < 0) {
				temp = -broj;
				tekst++;
				tekst++;

			}


			while (kraj >= tekst) {
				*kraj = temp % 10 + '0';
				temp /= 10;
				kraj--;

			}
			if (broj < 0) {
				*kraj = temp % 10 + '0';
				kraj --;
			}


			if (broj<0) {
				*kraj = '-';
			}



			while (*tekst != '\0' && *tekst !=' ') {
				tekst++;
			}
			while(*tekst != '\0' && *tekst == ' ') {
				brojac_razmamka++;
				tekst++;

			}
		
			tekst--;


			velicina = velicina + broj_char_broja + 1;

		}

		tekst++;
		if(*tekst == '\0') break;

	}


	return pamti;
}

int main()
{
	char recenica[200];
	int broj;

	printf("Unesite neki tekst: ");
	unesi(recenica,200);

	printf("Unesite broj: ");
	scanf("%d", &broj);
	printf("%s", ubaci_broj(recenica,broj));
	return 0;
}
