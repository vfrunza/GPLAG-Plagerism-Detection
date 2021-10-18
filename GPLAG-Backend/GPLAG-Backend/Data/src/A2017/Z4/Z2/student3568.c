#include <stdio.h>

void unesi(char niz[], int vel)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<vel-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* s, int *niz, int velicina)
{
	int i=0, duzina;

	while (*s!='\0') {
		duzina=0;
		if((*s>='a' && *s<='z') || ( *s>='A' && *s<='Z')) {

			while(*s!='\0' && ((*s>='a' && *s<='z') || ( *s>='A' && *s<='Z')) ) {
				s++;
				duzina++;

			}

			if(i>=velicina) return 0;
			if(duzina!=niz[i]) return 0;

			i++;
		}

		if(*s == '\0') break;
		s++;

	}

	if(i!=velicina) return 0;
	return 1;
}

int main()
{

	char tekst[100];
	int niz[]= {1,3,4,7,2};
	unesi(tekst,100);
	printf("%d", provjeri_duzine(tekst, niz, 5));
	return 0;
}
