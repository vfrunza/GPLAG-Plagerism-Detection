#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak != '\n') znak=getchar();
	int i = 0;
	while(i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}


char* ubaci_broj(char* tekst, int broj)
{
	char *vrati = tekst, *kraj;
	int velicina = 0;
	int broj_karaktera = 1;
	int broj_razmaka = 0;
	int i = 0;
	int temp = broj;

	if(broj != 0) {
		broj_karaktera = 0;
		if(broj < 0) temp *= (-1);
		if(broj < 0) broj_karaktera++;
		while(temp != 0) {
			temp /= 10;
			broj_karaktera++;
		}
	}

	while(tekst[i] != '\0') {
		velicina++;
		i++;
	}
	if(*tekst == ' ') {
		while(*tekst == ' ') tekst++;
	}
	
	tekst++;

	while(*tekst != '\0') {

		if(*tekst == ' ' && *(++tekst) != '\0') {
			
			kraj = vrati + velicina;
			
			while(*tekst != '\0' && kraj >= tekst) {
				*(kraj + broj_karaktera + 1) = *kraj;
				kraj--;
			}
			kraj += broj_karaktera + 1;
			*kraj = ' ';
			kraj--;
			temp = broj;

			if(broj < 0) {
				temp = broj*(-1);
				tekst += 2;
			}

			while(kraj >= tekst) {
				*kraj = temp % 10 + '0';
				temp /= 10;
				kraj--;
			}

			if(broj < 0) {
				*(--kraj) = '-';
				kraj++;
				*kraj-- = temp % 10 + '0';
			} 
			
			
			while(*tekst != '\0' && *tekst != ' ') tekst++;
			while(*tekst != '\0' && *tekst == ' ') {
				tekst++;
				broj_razmaka++;
			}
			tekst--;
			velicina += broj_karaktera + 1;
		}
		tekst++;
	}

	return vrati;
}

int main()
{
	char niz[100000];
	int broj;
	printf("Unesite tekst: ");
	unesi(niz, 100000);
	printf("Unesite neki broj: ");
	scanf("%d", &broj);
	ubaci_broj(niz, broj);
	printf("Ovo je novi tekst:\n%s", niz);
	return 0;
}
