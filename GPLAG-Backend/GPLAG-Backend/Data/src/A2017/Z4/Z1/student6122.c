#include <stdio.h>
#include <math.h>
//fja koja vraca broj cifara, ukljucujuci i predznak ako je -
int duzina_broja (int broj)
{
	int duzina=0;
	if(broj<0) {
		duzina++;
		broj=-broj;
	}
	do {
		duzina++;
		broj/=10;
	} while(broj);
	return duzina;
}
char* ubaci_broj (char* tekst, int broj)
{
	int temp=broj;
	char *poc = tekst;
	int znak = 0;
	char *kraj;
	while(*tekst) {
		//dok je god vrijednost pokazivaca tekst razlicita od razmaka, pomjeramo ga
		if(*tekst!=' ')
			znak=1;
		else if(znak==1) {
			znak=0;
			kraj=tekst;
			//kada dodjemo do razmaka, pokazivac kraj pomjeramo na kraj stringa
			//kopiramo sve od kraja prema pokazivacu tekst za odredjeni broj mjesta unaprijed, tj. u pokazivac kraj+duzina_broja(broj)
			while(*kraj) kraj++;
			while(kraj>tekst) {
				*(kraj+duzina_broja(broj))=*kraj;
				kraj--;
			}
			temp=broj;
			//preskacemo mjesta koja ce zauzeti nas broj kada ga pretvorimo u string
			if(broj<0) {
				tekst++;
			}
			do {
				tekst++;
				temp/=10;
			} while(temp!=0);

			temp=fabs(broj);
			//upisujemo broj, ali odozada prema pocetku
			while(temp) {
				*tekst=temp%10 + '0';
				temp/=10;
				tekst--;
			}
			if(broj<0) {
				*tekst--='-';
			}
			tekst+=duzina_broja(broj)+1;
			//ako iza unesenog broja odmah nastavlja novi tekst, ubacujemo razmak, prema uslovu zadatka
			if(*tekst!=' ') {
				kraj=tekst;
				while(*kraj) kraj++;
				while(kraj>=tekst) {
					*(kraj+1)=*kraj;
					kraj--;
				}
				*tekst=' ';

			}
		}
		tekst++;
		//provjeravamo da li do kraja teksta ima vise znakova ili su samo razmaci, kako nam program ne bi na narednom razmaku ubacio broj
		kraj=tekst;
		while(*kraj++) {
			if(*kraj=='\0') tekst=kraj;
			if(*kraj!=' ') break;
		}
	}
	return poc;

}
int main()
{

	return 0;
}
