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

int vrati_duzinu(char *s)
{
	int duzina = 0;
	char *pom = s;
	while(*pom != '\0') {
		duzina++;
		pom++;
	}
	return duzina;
}

int provjeri(const char *s)
{
	char pomocni[100000], *kraj, *pocetak;
	const char *vrati = s;
	int i = 0, j = 0, duzina = 0;
	int istina = 1;
	while(s[i] != '\0') {
		if(s[i] == '<') {
			while(s[i] != '>' && s[i] != ' ') {
				pomocni[j] = s[i];
				i++;
				j++;
			}
			pomocni[j] = '>';
			j++;
		}
		i++;
	}
	s = vrati;
	while(*s != '\0') {
		if(*s == '<' && *(s+1)==' ')return 0;
		s++;
	}
	s = vrati;
	while(*s != '\0') {

		if((*s == '<' || *s == '>' || *s == '/') && *s != '\0') istina = 0;
		else {
			istina = 1;
			break;
		}
		s++;
	}
	if(istina == 0) return 0;
	pomocni[j] = '\0';
	i = 0;
	duzina = vrati_duzinu(pomocni);
	pocetak = pomocni;
	while(*pocetak != '\0') {
		if(*pocetak == '\0') break;
		if(*pocetak == '<' && *pocetak != '\0') {
			kraj = pocetak + 1;
			while(*kraj != '<' && *pocetak != '\0') kraj++;
			kraj++;
			if(*kraj == '/' && *pocetak != '\0') {
				if(*(pocetak+1) != *(kraj+1) && *pocetak != '\0') return 0;
				else if(*(pocetak + 1) == *(kraj + 1) && *pocetak != '\0') {
					pocetak++;
					kraj++;
					while((*pocetak != '>' && *pocetak != ' ') && (*kraj != '>' && *kraj != ' ') && *pocetak != '\0' && *kraj != '\0') {
						if(*pocetak != *kraj && *pocetak != '\0') return 0;
						pocetak++;
						kraj++;
					}
					if(pocetak != vrati) pocetak--;
					while(*pocetak != '>' && *pocetak != '\0' && pocetak > pomocni) pocetak--;
					pocetak++;
					kraj++;
					if(*kraj == '\0' && *pocetak != '\0') {
						pocetak = pomocni;
						while(pocetak != kraj) {
							*pocetak = '\0';
							pocetak++;
						}
					}
					while(*kraj != '\0' && *pocetak != '\0') {
						*pocetak = *kraj;
						kraj++;
						pocetak++;
					}
					*pocetak = '\0';
				}
				pocetak = pomocni;
				i++;
			} else if(*(pocetak+1) != *kraj) pocetak = kraj - 1;
		}
	}
	return 1;
}

int main()
{
	char s[100000];
	printf("Unesite tekst: ");
	unesi(s, 100000);
	provjeri(s);
	printf("Ovo je tekst nakon izmjene: %s", s);
	return 0;
}
