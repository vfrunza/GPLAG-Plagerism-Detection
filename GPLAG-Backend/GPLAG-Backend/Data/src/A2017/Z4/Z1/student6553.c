#include <stdio.h>

int duzina(int a)
{
	int br=0;
	if(a<0) {
		br++;
		a=-a;
	}
	do {
		a/=10;
		br++;
	} while(a);
	return br;
}

void napravi_niz(char*s, int a)
{

	if(a<0) {
		*s='-';
		s++;
		a=-a;
	}
	s+=duzina(a)-1;

	do {
		*s=a%10+'0';
		a/=10;
		s--;

	} while(a);




}

char*ubaci_broj(char*tekst, int broj)
{
	int pomak=duzina(broj), nerazmak=0,pomocni;
	char  *pocetak=tekst, *tmp=pocetak,*provjera;
	pomocni=pomak;

	while(*tekst!='\0') {
		pomak=pomocni;
		if(*tekst!=' ') nerazmak=1;
		else if(nerazmak) {

			provjera=tekst;
			while(*provjera==' ' && *provjera!='\0') provjera++;
			if(*provjera!='\0') {

				if(*(tekst+1)!=' ') pomak++;
				while(*tmp!='\0') tmp++;
				while(tmp>=tekst) {
					*(tmp+pomak)=*tmp;
					tmp--;
				}

				tekst++;
				napravi_niz(tekst,broj);
				tekst+=pomak-1;
				nerazmak=0;
			}
		}

		tekst++;
	}
	return pocetak;

}


int main()
{
return 0;
}
