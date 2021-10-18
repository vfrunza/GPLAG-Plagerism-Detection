#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char *p, int *q)
{
	char *pocetak = *p;
	int br = 0;
	while (*p != '\0') {
		if(!(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z'))
			if (br == *q){
				q++;
				continue;
			}
			else return 1;
		else br++;
		p++;
	}
	p = pocetak;
	return 0;
}

int main()
{
	char tekst[100];
	printf("Unesite tekst: ");
	unesi(tekst, 100);
	int niz[100];
	int broj = 0, n = 0;
	while (broj != -1) {
		scanf("%d", &broj);
		if (broj != -1) {
			niz[n]= broj;
			n++;
		}
	}
	printf("%d", provjeri_duzine(tekst, niz));
	return 0;
}