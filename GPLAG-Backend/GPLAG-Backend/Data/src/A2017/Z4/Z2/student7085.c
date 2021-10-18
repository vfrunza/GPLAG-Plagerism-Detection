#include <stdio.h>


void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if(znak == '\n') znak = getchar();
	int i = 0;
	while(i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}



int provjeri_duzine(char* str, int niz[100], int n)
{

	int brslova = 0;

	char* pstringa = str;

	int* pniza = niz;

	int brrijeci = 0;


	while (*pstringa != '\0') {

		if((*pstringa) < 'A' || (*pstringa) > 'Z' && (*pstringa) < 'a' || (*pstringa) > 'z') {

			brslova = 0;
			
			if(*pniza == brslova) {
				pniza++;
				brrijeci++;
			} else {
				return 0;

			}

		}

		else brslova++;

		pstringa++;

	}


	return 1;
}



int main()
{
	char tekst[100];
	int niz[100] = {0};
	int i;
	int n;

	n = 0;

	printf("Unesite tekst: ");

	unesi(tekst, 100);

	printf("Unesite niz: \n");


	for(i=0; i<100; i++) {
		scanf("%d", &niz[i]);
		if(niz[i] == 0) break;
		else if(niz[i] < -1) {
			i--;
			n--;
		} else n++;
	}

	printf("%d ", provjeri_duzine(tekst, niz, n));


	return 0;
}
