#include <stdio.h>
#include <stdlib.h>
void unesi (char niz[], int velicina) {
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* ubaci_broj (char* tekst, int broj) {
	char tmp, temp;
	int cifra;
	char* pocetak=broj;
	char* s=tekst;
	char* kraj;
	char* p;
	
	while(*s!='\0') {
		/*tmp=s;*/
		char* nr=s;
		while (*nr==' ') nr++;
		if (*s==' ' && (!(*s==pocetak || *(s-1)==' ')) && *nr!='\0') {
			if (broj<0) {
				broj=abs(broj);
			}
			else if (broj!=0) {
				while (broj!=0) {
					cifra=broj%10 + '0';
					char* kraj=s;
					while(kraj!='\0') kraj++;
					while (kraj>s) {
						*(kraj+cifra)=*(kraj);
						kraj--;
					if (broj<0) cifra='-';
					else if cifra=' ';
					}
				    else {
					char* p=cifra;
					while (*p==cifra) {
					*s++=*p++;
					}
					broj/=10;
					}
				}
			}
		}
		s++;
	}
	
	return pocetak;
}

int main() {
	char tekst[100];
	int broj;
	printf ("Unesite tekst: ");
	unesi (tekst, 100);
	printf ("Unesite broj: ");
	scanf ("%d", &broj);
	printf ("Tekst: %s", ubaci_broj(tekst,broj));
	
	return 0;
}
