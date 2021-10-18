#include <stdio.h>
#include <stdlib.h>


char* razdvoji_cifre(char* rez, int broj)
{
	char *p=rez;
	int zadnja_cifra=0;
	char pom[10];
	char *x=pom;


	*p=' ';
	p++;


	if (broj<0) {
		*p='-';
		p++;
		broj=-broj;
	}


	while(broj>0) {
		zadnja_cifra=broj%10;
		*x=(zadnja_cifra+'0');
		x++;
		broj=broj/10;
	}
	x--;

	while(x>=pom) {
		*p = *x;
		p++;
		x--;
	}

	*p=' ';
	p++;

	*p='\0';


	return rez;
}

int duzina(char* tekst)
{
	int d=0;
	while(*tekst != '\0') {
		d++;
		tekst++;
	}
	return d;
}

char* ubaci_broj(char* tekst ,int broj)
{
	char rez[10];
	char* zamjena = razdvoji_cifre(rez, broj);
	char* pzamjene=zamjena;
	int pomak=duzina(zamjena)-1;
	int prvi_space=0;
	int prvi_znak=0;
	char* p = tekst;
	while(*p!='\0') {
		if (*p==' ' && prvi_space!=0) {
			p++;
		} else if (*p==' ' && prvi_znak==0) {
			p++;
		} else if (*p!=' ') {
			p++;
			prvi_znak=1;
			prvi_space=0;
		} else if (*p==' ') {
			prvi_space=1;
			char* kraj=p;
			while(*kraj!='\0')
				kraj++;

			while(kraj>p) {
				*(kraj+pomak)=*kraj;
				kraj--;
			}

			while(*pzamjene != '\0') {
				*p=*pzamjene;
				p++;
				pzamjene++;

			}

			pzamjene=zamjena;
			p++;

		}
	}
	return tekst;
}





int main()
{

	char tekst[1000]=" Ovo   je neki    primjer teksta";
	printf("%s",ubaci_broj(tekst,-123));


	return 0;
}
