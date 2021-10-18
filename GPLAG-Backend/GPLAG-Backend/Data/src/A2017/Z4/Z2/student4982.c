#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char *s, int *cifre, int velicina)
{
	int *pok_na_cifre = cifre;
	int duzina = 0;
	/*Provjera velicine niza cifara*/
	char *pok = s;
	int razmak = 1,broj_rijeci = 0;
	while (*pok != '\0') {
		if (!((*pok >= 'A' && *pok <= 'Z') || (*pok >= 'a' && *pok <= 'z'))) {
			razmak = 1;
		} else if (razmak == 1) {
			razmak = 0;
			broj_rijeci++;
		}
		pok ++;
	}
	if(broj_rijeci != velicina) return 0;
	
    /*Poredjenje cifri i duzina rijeci*/
	while (*s != '\0') {
		if(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
			if(duzina != 0) {
				if(duzina != *pok_na_cifre) {
					return 0;
					break;
				}

				pok_na_cifre++;
			}
			duzina = 0;
		} else {
			duzina ++;
		}
		s++;
	}
	return 1;
}


int main()
{
	char text[1000];
	int cifre[1000];
	int vel,i;
	printf("Unesite recenicu: \n");
	unesi(text,1000);
	printf("Unesite velicinu niza cifara: ");
	scanf("%d", &vel);
	printf("Unesite niz cifara: \n");
	for(i=0; i<vel; i++) {
		scanf("%d", &cifre[i]);
	}
	printf("%d", provjeri_duzine(text,cifre,vel));

	return 0;
}
