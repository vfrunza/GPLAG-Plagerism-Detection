#include <stdio.h>

char * obrniStringBroj(char *s)  //12345 => 54321
{
	char*k=s;
	char*p=s;
	if(*p=='-')p++;
	char temp;
	while(*k!='\0')k++;
	k--; // pomjeramo ga za jedno mjesto iza nul-terminiranog znaka
	while(p<k) {
		temp = *p;
		*p=*k;
		*k=temp;
		p++;
		k--;
	}

	return s;
}



char*brojUString(char *tekst, int broj)
{
	int cifra;
	char*p=tekst;
	if(broj<0) {
		*p++ = '-';
		broj*=-1;
	} else if(broj==0) {
		*p++='0';
	}
	while(broj!=0) {
		cifra = broj%10;
		*p++ = cifra+'0';
		broj/=10;
	}
	*p='\0';
	return tekst;
}

int duzina(char*s)
{
	int broj=0;
	while(*s!='\0') {
		broj++;
		s++;
	}
	return broj;
}

char* ubaciBrojUtekst(char*tekst, char *broj)
{
	int razmak=1;
	char *p=tekst;
	int pomjeriZa;
	char *k=tekst;
	while(*k!='\0')k++; // k nakon petlje pokazuje na zadnji element nul-terminirani znak
	if(*p==' ')razmak=0;
	pomjeriZa = duzina(broj)+razmak;
	do {
		*(k+pomjeriZa)=*k;
		k--;
	} while(k!=p);
	*(k+pomjeriZa)=*k;

	while(*broj!='\0') {
		*p++ = *broj++;
	}
	if(razmak)*p=' ';
	return tekst;
}


char* ubaci_broj (char* tekst, int broj)
{
	int pomjeriZa;
	char*p=tekst;
	char *k;
	char tekstualnoBroj[12];
	brojUString(tekstualnoBroj,broj);
	obrniStringBroj(tekstualnoBroj);
	int brojCifara = duzina(tekstualnoBroj);
	while(*tekst==' ') {
		tekst++;
	}

	int prethodna=1;
	int sljedeca=0;
	while(*tekst!='\0') {
		if(*tekst!=' ') {
			prethodna=1;
		} else {
			if(prethodna) {
				k=tekst;
				while(*k!='\0') {
					if(*k!=' ') {
						sljedeca=1;
						break;
					}
					k++;
				}
				if(sljedeca){
					tekst++;
					ubaciBrojUtekst(tekst,tekstualnoBroj);
					tekst+=brojCifara;
					sljedeca=0;
				}
				prethodna=0;
			}
		}
		tekst++;
	}

	return p;
}


int main()
{
	int broj = -123;
	char t[1000]="teksta  asdf  ";
	ubaci_broj(t,broj);
	printf("%s",t);
	return 0;
}
