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

int provjeri_duzine (char* recenica, int* niz, int broj)
{
	int brojac_slova = 0, brojac_rijeci = 0, trazi_rijec = 1;
	char* pamti = recenica;

	while(!((*recenica >= 'A' && *recenica <= 'Z') || (*recenica >= 'a' && *recenica <= 'z'))&& trazi_rijec == 1) recenica++;

	while(*recenica != '\0') {
		if(!((*recenica >= 'A' && *recenica <= 'Z') || (*recenica >= 'a' && *recenica <= 'z'))&& trazi_rijec == 1) {
			brojac_rijeci++;
			trazi_rijec=0;
		}

		if((*recenica >= 'A' && *recenica <= 'Z') || (*recenica >= 'a' && *recenica <= 'z')) trazi_rijec = 1;

		recenica++;
	}
	if(!((*(recenica-1) >= 'A' && *(recenica-1) <= 'Z') || (*(recenica-1) >= 'a' && *(recenica-1) <= 'z'))) brojac_rijeci--;
	if(*recenica == '\0') brojac_rijeci++;


	if (brojac_rijeci != broj) return 0;

	recenica = pamti;
	brojac_rijeci = 0;

	while(*recenica != '\0') {
		if((*recenica >= 'A' && *recenica <= 'Z') || (*recenica >= 'a' && *recenica <= 'z')) {
			while((*recenica >= 'A' && *recenica <= 'Z') || (*recenica >= 'a' && *recenica <= 'z')) {
				brojac_slova++;
				recenica++;
			}

			recenica--;
			if(*niz != brojac_slova) return 0;
			niz++;
			brojac_slova = 0;
		}

		recenica++;
	}

	return 1;
}

int main()
{
	char recenica[100];
	int niz[20], i = 0;
	printf("Unesite recenicu: ");
	unesi(recenica,80);
	printf("Unesite niz: ");

	for(i=0; i < 20; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]== -1) {
			niz[i] = 0;
			break;
		}
	}

	printf("%d", provjeri_duzine(recenica, niz,2));
	return 0;
}
