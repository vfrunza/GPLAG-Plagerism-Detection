#include <stdio.h>
#define DUZINA 100

void unesi(char *tekst, int velicina)
{
	int i=0;
	char c;
	do {
		c=getchar();
		tekst[i]=c;
		i++;
	} while(c!='\n' && i<velicina);
	tekst[i-1]='\0';
}

char* ubaci_broj(char* tekst, int broj)
{
	int pom, duz=0, razmak=1, i, pom1=0;
	char broj_string[12];
	char* bs=broj_string;
	char* adres=tekst;
	char* pok_tekst;

	if(broj<0) {
		broj=(-1)*broj;
		*bs++='-';
		duz++;
		pom1=1;
	}
	pom=broj;

	if(broj==0) {
		*bs++='0';
		duz++;
		pom1=1;
	}

	while(pom!=0) {
		bs++;
		duz++;
		pom=pom/10;
	}
	*bs--='\0';

	while(broj!=0) {
		*bs--=broj%10+'0';
		broj=broj/10;
	}
	if(pom1==0) bs++;


	while(*tekst!='\0') {
		if(*tekst==' ') {
			if(razmak==0) {
				pok_tekst=tekst;
				
				while(*pok_tekst!='\0') {
					if(*pok_tekst!=' ') break;
					pok_tekst++;
				}
				
				if(*pok_tekst=='\0') {
					tekst=pok_tekst-1;
					break;
				}
				
				while(*pok_tekst!='\0') pok_tekst++;
				
				if(*(tekst+1)!=' ') {
					pok_tekst++;
					while(pok_tekst>tekst) {
						*(pok_tekst)=*(pok_tekst-1);
						pok_tekst--;
					}
					while(*pok_tekst!='\0') pok_tekst++;
				}
				
				while(pok_tekst>tekst) {
					*(pok_tekst+duz)=*pok_tekst;
					pok_tekst--;
				}
				tekst++;
				
				for(i=0; i<duz; i++) {
					*tekst++=*bs++;
				}
				bs=broj_string;
			} 
			razmak=1;
		} 
		else razmak=0;
		tekst++;
	}

	return adres;
}

int main()
{
	char tekst[DUZINA];
	int broj;

	printf("Unesite tekst: ");
	unesi(tekst,DUZINA);

	printf("Unesite broj: ");
	scanf("%d", &broj);

	printf("Nakon zamjene: %s", ubaci_broj(tekst,broj));

	return 0;
}
