#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if(znak=='\n') znak=getchar();
	int i = 0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char* s;
	int brojac=0;
	char** r = rijeci;
	char** z = zamjene;
	char** r1=rijeci;
	char** z1=zamjene;
	s=tekst;
	char* p;
	char* k;
	if(broj_rijeci == 0) return tekst; /*za slucaj da su date rijeci i zamjene a broj_rijeci nuli*/
	while(*s!='\0') {
		p=s;
		while(*s==**r) {
			if(*s==**r && *s!=' ' && **r!='\0') {
				s++;
				(*r)++;
				if(*s==' ' && **r=='\0') {
					while(**z!='\0') {
						s=p;
						*s=**z;
						(*z)++;
						p++;
					}
				}
			}
			
		}
		s++;
		p++;
	}
	return tekst;
}
int main() {
	char tekst[1000];
	printf("Unesi tekst: ");
	unesi(tekst, 1000);
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}