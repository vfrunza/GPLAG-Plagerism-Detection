#include <stdio.h>
#include <math.h>

char* ubaci_broj(char* tekst, int broj) {
	char* poc=tekst;
	char* pamti;
	int pomocna=0;
	int apsolutna, broj_razmaka=0, broj_cifara=0, pomocni_broj, duzina_pomjeraja, obrnut;
	int negativan=0;
	
	if (broj<0) {
		negativan=1;
		apsolutna=-broj;
	}
	else {
		apsolutna=broj;
	}
	
	pomocni_broj=apsolutna;
	if (negativan) broj_cifara=1;
	do {
		pomocni_broj/=10;
		broj_cifara++;
	} while (pomocni_broj!=0);
	
	/*Obrcemo broj jer nam takav treba kod ubacivanja u string*/
	/*Koristimo promjenljivu pomocni_broj da ne bismo mijenjali nas zadati broj, tj. njegovu apsolutnu vrijednost*/
	pomocni_broj=apsolutna;
	obrnut=0;
	if (broj==0) obrnut=broj;
	else {
		while (pomocni_broj!=0) {
			obrnut=obrnut*10+pomocni_broj%10;
			pomocni_broj/=10;
		}
	}
	
	while (*tekst==' ') {
		tekst++;
	}
	while (*tekst) {
		if (*tekst==' ') {
			char* klizeci=tekst;
			
			while (*klizeci==' ') {
				klizeci++;
				if (*klizeci==0) {
					pomocna=5;
					break;
				}
			}
			if (pomocna==5) {
				pomocna=0;
				break;
			}
			
			broj_razmaka=klizeci-tekst;
			
			if (broj_razmaka==1) {
				pamti=tekst;
				duzina_pomjeraja=broj_cifara+1;
				while (*tekst) tekst++;
				while (tekst>pamti) {
					*(tekst+duzina_pomjeraja)=*tekst;
					tekst--;
				}
				tekst++;
				if (negativan) {
					*tekst++='-';
				}
				pomocni_broj=obrnut;
				do {
					*tekst++='0'+pomocni_broj%10;
					pomocni_broj/=10;
				} while (pomocni_broj!=0);
				*tekst=' ';
			}
			else if (broj_razmaka>1) {
				pamti=tekst;
				while (*tekst) tekst++;
				duzina_pomjeraja=broj_cifara;
				while (tekst>pamti) {
					*(tekst+duzina_pomjeraja)=*tekst;
					tekst--;
				}
				tekst++;
				if (negativan) {
					*tekst++='-';
				}
				pomocni_broj=obrnut;
				do {
					*tekst++='0'+pomocni_broj%10;
					pomocni_broj/=10;
				} while (pomocni_broj!=0);
				while (*tekst==' ') tekst++;
				tekst--;
			}
		}
		tekst++;
	}
	return poc;
}
//nadijina verzija
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
