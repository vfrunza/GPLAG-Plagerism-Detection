#include <stdio.h>

char *ubaci_broj(char *tekst,int broj)
{
	char *pok_pom=tekst;
	char *pocetak=tekst;
	char *kraj_str=tekst;
	char *za_vracanje=tekst;
	int duz=1,pom_br=broj,broj_cifara=0,br_razmaka=0;
	while(pom_br!=0) {
		broj_cifara++;
		pom_br/=10;
	}
	if(broj<0) duz++;
	duz+=broj_cifara;
	while(*tekst!='\0') {
		if(*tekst==' ') {
			if(tekst==pocetak) {
				while(*tekst==' ' && *tekst!='\0') tekst++;
			}
			while(*tekst!=' ' && *tekst!='\0') tekst++;
			pok_pom=tekst;
			while(*pok_pom==' ' && *pok_pom!='\0') {
				br_razmaka++;
				pok_pom++;
			}
			kraj_str=tekst;
			if(*pok_pom=='\0') break;
			while(*kraj_str!='\0') {
				kraj_str++;
			}

			while(kraj_str!=tekst) {
				*(kraj_str+duz)=*kraj_str;
				kraj_str--;
			}
			tekst+=duz;
			*tekst--=' ';
			pom_br=broj;
			if(pom_br<0) {
				pom_br*=-1;
			}
			while(pom_br!=0) {
				*tekst--=pom_br%10+'0';
				pom_br/=10;
			}
			if(broj<0) {
				*tekst='-';
			}
			tekst+=duz;
			if(br_razmaka>1) {
				kraj_str=tekst;
				while(*kraj_str!='\0') {
					*kraj_str=*(kraj_str+1);
					kraj_str++;
				}
			}

		}
		if(*tekst==' ') {
			while(*tekst==' ' && *tekst!='\0' && *(tekst+1)==' ') tekst++;
		}
		if(*tekst!='\0') tekst++;
		br_razmaka=0;
	}
	return za_vracanje;

}

int main()
{
	char s[77] = "Ovdje izmedju rijeci ima po      nekoliko razmaka   ";
	printf("\"%s\"", ubaci_broj(s, 320));
	return 0;
}
