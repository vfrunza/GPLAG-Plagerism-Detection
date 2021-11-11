#include <stdio.h>
#include <string.h>

/*funkciju za unosenje stringa je kopirana iz ranije uradjenih zadataka*/
void unesi(char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if(znak == '\n')
		znak=getchar();
	while(i<velicina-1 && znak != '\n') {
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* kodiraj(char* s, char* p)
{
	int pomocni_niz[95]= {0};
	/*pamtimo na sta je pokazivalo s(pocetak niza) da bi mogli vratiti*/
	char* q = s;
	char* t = p;

	int i,j;

	/*trazimo koji se karakter u tekstu ponavlja max broj puta*/
	char* m = s;
	char* n = s;
	int brojac=0, max=0;

	while(*m != '\0') {
		n=m;
		while(*n != '\0') {
			if(*m == *n) {
				brojac++;
			}
			n++;
		}
		if(brojac>max) max=brojac;
		m++;
	}
	/*vracamo na pocetak*/
	s=q;

	/*u pomocni niz smjestamo koliko puta se ponvalja karakter u tekstu*/
	while(*s != '\0') {
		pomocni_niz[*s-32]++;
		s++;
	}

	s=q;

	/*u prazan niz(tablicu) smjestano elemente teksta( niza s)*/
	while(max>-1) {
		for(i=0; i<95; i++) {
			if (pomocni_niz[i]==max) {
				*p=i+32;
				p++;
			}
		}
		max--;
	}

	s=q;

	while(*s != '\0') {
		p=t;
		for(j=0; j<95; j++) {
			if(*s == p[j]) {
				*s=126-j;
				break;
			}
		}
		s++;
	}
	/*vracamo pokazivac na pocetak reda*/
	return q;
}

char* dekodiraj(char* s, char* p)
{
	int i, vel=0;
	vel=strlen(s);
	char* q;
	q = s;
	/*u niz s upisujemo dekodiranu vrijednost iz tablice*/
	for(i=0; i<vel; i++) {
		s[i] = p [126 - s[i]];
	}
	return q;
}

int main()
{
	char s[95];
	char p[95];
	unesi(s,95);
	kodiraj(s,p);
	dekodiraj(s,p);

	return 0;
}
