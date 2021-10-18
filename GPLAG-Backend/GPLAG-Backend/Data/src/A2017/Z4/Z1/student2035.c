#include <stdio.h>
#include <math.h>

int broj_cifara(int x)
{
	int rezultat=0; //SVAKA CAST, BAS JE SUPER STO SI UZELA U OBZIR DA JE NULA ISTO CIFRA I STAVILA TU IF(X==0) RETURN 1;, BRAVO
	while(x) {
		rezultat++;
		x=x/10;
	}
	return rezultat;
}

int broj_rijeci(char *s)
{
	char *p=s;
	int brojrijeci=0;
	int razmak=1;
	while(*p!='\0') {
		if(*p==' ')
			razmak=1;
		else {
			if(razmak) brojrijeci++;
			razmak=0;
		}
		p++;
	}
	return brojrijeci;
}


char *ubaci_broj(char *tekst, int broj)
{
	char *rezultat=tekst;
	int brojrijeci=0;
	int negativan=0;
	int razmak=1;
	int viserazmaka=0;
	int provjeracifara=broj_cifara(broj); //A STA  SI OVDJE OCEKIVALA DA TI POSALJE, U KOM PARALELNOM UNIVERZUMU JE OVDJE BROJ CIFARA NULA, UKLJUCI NEKAD MOZAK
	int max_br_rijeci=broj_rijeci(rezultat);
	if(max_br_rijeci<=1 || provjeracifara==0) return rezultat;
	if(broj<0) negativan=1;
	while(*tekst!='\0') {
		if(*tekst==' ')
			razmak=1;
		else {
			brojrijeci++;
			while(*tekst!=' ' && *tekst!='\0')
				tekst++;
			
			if(brojrijeci<max_br_rijeci) {
				viserazmaka=0;
				int kopija_broja=broj;
				char *ovdeubaci=tekst;
				char *krajrecenice=tekst;
				int brojcifara=broj_cifara(fabs(broj));
				if(negativan) brojcifara++;
		/*ovosam ubacik*/		if(*(tekst+1)==' ') {brojcifara--; viserazmaka=1;}
				while(*krajrecenice!='\0')
					krajrecenice++;
				//	ovdeubaci++; mislim da je ovo bilo izbaceno jos u prvoj verziji, nemoj ga nikada vracati
				while(krajrecenice>=ovdeubaci) {
					*(krajrecenice+1+brojcifara)=*(krajrecenice);
					krajrecenice--;
				}
				ovdeubaci++;
				if(negativan) {
					*ovdeubaci='-';
					ovdeubaci++;
					brojcifara--;
				}
				while(brojcifara) {

					if(kopija_broja<0) kopija_broja=kopija_broja*(-1);
			/*ovosiubacila*/		if(viserazmaka) {brojcifara++; viserazmaka=0; }
					*ovdeubaci=fabs(kopija_broja)/pow(10, brojcifara-1)+'0';
					kopija_broja=fabs(kopija_broja)-(*ovdeubaci-'0')*pow(10, brojcifara-1);
					ovdeubaci++;
					brojcifara--;

				}
				tekst=ovdeubaci;
				if(*tekst=='\0') break; 
			//	else ovdeubaci++;
/*ovosiizbacila*/			//	if(*ovdeubaci==' ') {
			//		char *pomocni=tekst;
			//		while(*pomocni++=*ovdeubaci++);
			//	}
			}

		}
		if(*tekst=='\0') break;
		tekst++;
	}
	return rezultat;
}




int main()
{
	char mas[1000]="     je neka recenica           ima     puno  razmakaaaa     ";
	int b=broj_rijeci(mas);
	printf("%d", b);
	return 0;
}
