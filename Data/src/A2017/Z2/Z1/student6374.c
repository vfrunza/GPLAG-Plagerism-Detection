#include <stdio.h>

int main() {
	printf("Zadaća 2, Zadatak 1");
	return 0;
}

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
char* tritacke(char* s)
{
	char *r=s, *pocetak, *kraj, *pamti;
	while(*s!='\0') {
		while (*s==' ') {
			s++;
			if(*s=='\0') return r;

		}
	}
	pocetak=s;
	while(*s!=' ') {
		s++;
		if(*s=='\0') {
			if (s-pocetak>=10) {
				*(pocetak+3)='.';
				pocetak+=4;
				*pocetak='\0';
			}
			return r;
		}
	}
	kraj=s;
	if (kraj-pocetak>=10) {
		*(pocetak+3)='.';
		pocetak+=4;
		pamti=pocetak;
		while(*pocetak++=*kraj++);
		*pocetak='\0';
		s=pamti-1;
	}
	s++;
	return r;
}
int main()
{
	char v[100];
	printf("Unesite tekst:");
	unesi(v,100);
	printf("%s", tritacke(v));

	return 0;
}
