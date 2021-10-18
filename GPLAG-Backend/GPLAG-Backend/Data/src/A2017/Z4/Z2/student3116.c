#include <stdio.h>

int provjeri_duzine(char *s, int* niz, int velicina){
	int razmak=1, broj_slova=0, brojac=0;
	while(*s!='\0'){
		broj_slova=0;
		if(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) razmak=1;
			else if(razmak==1){
				razmak=0;
					while(((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) && *s!='\0') {
						broj_slova++;
						s++; 
					}
					if(broj_slova!=niz[brojac]) return 0;
						else { brojac++; s--; }
			}
			s++; 
	}
	if (brojac!=velicina) return 0;
	return 1;
}

int main() {
	char tekst[]={"Ovo.je_neki'primjer$teksta"};
	int niz[]={3,2,4,7,6};
	printf("%d", provjeri_duzine(tekst, niz, 5));
	return 0;
}