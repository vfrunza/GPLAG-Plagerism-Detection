#include <stdio.h>

int broj_rijeci(char *s)
{
	int br=0;
	int razmak=1;
	while(*s!='\0') {
		if(*s == ' ') razmak=1;
		else if(razmak==1) {
			razmak=0;
			br++;
		}
		s++;
	}
	return br;
}

char* ubaci_broj (char* s, int broj)
{
	char *povratni=s, *kraj, *sb;
	int cifra=0, razmak=1, i, duzina=0;
	int br_rijeci=0, duzina_teksta = broj_rijeci(s);
	char *temp;
	
	char sbroj[12],

	     sb=sbroj;
	if(broj<0) {
		broj = -broj;
		*sb='-';
		sb++;
	}
	temp=broj;
	do {
		temp/=10;
		sb++;
	} while(temp!=0);
	*sb='\0';

	do {
		sb--;
		cifra=broj%10;
		*sb=cifra + '0';
		broj/=10;
	} while(broj!=0);

	while(*s != '\0') {
		if(*s == ' ') razmak=1;
		else if(razmak==1) {
			razmak=0;
			br_rijeci++;
			if(br_rijeci!=duzina_teksta) {
				while(*s!=' ') s++;
				kraj=s;
				s++;
				if(*s!=' ')  
				while(*kraj!='\0') kraj++;
				while(kraj>s) {
					*(kraj+duzina) = *kraj;
					kraj--;
				}
				
				while(*pok_broj != '\0') {
					*s++=*pok_broj++;
				}

			}
		}
		s++;
	}


	return povratni;
}

int main()
{

	return 0;
}
