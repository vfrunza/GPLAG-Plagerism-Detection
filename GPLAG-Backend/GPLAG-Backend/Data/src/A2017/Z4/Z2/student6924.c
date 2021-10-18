#include <stdio.h>

void unesi(char *s, int velicina)
{
	int i=0;
	char c;
	do {
		c=getchar();
		s[i]=c;
		i++;
	} while(c!='\n' && i<velicina);
	s[i-1]='\0';
}

int duzina(char *s) {
	int neslovo=1, broj_rijeci=0;
	
	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) neslovo=1;
		else if(neslovo==1) {
			neslovo=0;
			broj_rijeci++;
		}
		s++;
	}
	
	return broj_rijeci;
}

int provjeri_duzine(char *s, int *niz, int velicina_niz)
{
	int i=0, duz=0;
	
	if(velicina_niz!=duzina(s)) return 0;
	
	for(i=0; i<velicina_niz; i++) {
		if(*s=='\0') return 0;
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			duz++;
			s++;
		}
		if(duz==0) {
			s++;
			i--;
		}
		else if(niz[i]!=duz) return 0;
		duz=0;
	}
	
	return 1;
}

int main()
{
	int i, velicina_niz=0, niz[100];
	char s[100];

	printf("Unesite tekst: ");
	unesi(s,100);

	printf("Unesite niz brojeva: ");
	for(i=0; i<100; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
		velicina_niz++;
	}

	if(provjeri_duzine(s,niz,velicina_niz)==1) printf("Niz predstavlja duzinu rijeci u recenici.");
	else printf("Niz ne predstavlja duzinu rijeci u recenici.");

	return 0;
}
