#include <stdio.h>
#include <math.h>
/*Trazimo broj cifara broja,kako bismo znali koliko mjesta nam je potrebno za prosirivanje stringa*/
/*Ukoliko je broj negativan rezervisemo jos jedno mjesto za - */
int br_cifara (int n)
{
	int brojac;
	if (n>0)
		brojac=0;
	else if (n==0)
		brojac=1;
	else
		brojac=1;
	if (n<0)
		n=-n;
	while (n>0) {
		n/=10;
		brojac++;
	}
	return brojac;
}
/*Trazimo broj rijeci u stringu,kako bismo znali kad dodjemo do posljednje rijeci,jer nakon nje ne upisujemo broj*/
int broj_rijeci (char *tekst)
{
	int razmak=1;
	int brojac=0;
	while (*tekst!='\0') {
		if (*tekst==' ') {
			razmak=1;
		} else if (razmak==1) {
			razmak=0;
			brojac++;
		}
		tekst++;
	}
	return brojac;
}
char* ubaci_broj (char *tekst,int broj)
{
	int razmak=1;
	char* ret=tekst;
	char* kraj;
	int cifra,i;
	int duz;
	int br_rijeci=0;
	int duzina_teksta=broj_rijeci(tekst);
	int temp=broj,pomocna,stepen=br_cifara(broj);
	int pomocni_brojac=br_cifara(broj);
	while (*tekst!='\0') {
		/*Koristimo definiciju rijeci iz postavke zadatka da bismo pronasli rijec,uz pomoc logicke varijable razmak*/
		if (*tekst==' ')
			razmak=1;
		else if (razmak==1) {
			razmak=0;
			duz=br_cifara(broj);
			br_rijeci++;
			/*Dodavanje cifre samo ukoliko nije posljednja rijec u stringu*/
			if (duzina_teksta!=br_rijeci) {
				/*Saljemo pokazivac na string do prvog razmaka,tj. do mjesta ubacivanja*/
				while (*tekst!='\0' && *tekst!=' ')
					tekst++;
				kraj=tekst;
				tekst++;
				/*Ako je samo jedan razmak izmedju rijeci povecavamo broj mjesta koje treba dodati za jedan,jer se jedan razmak mora nalaziti i nakon ubacenog broja*/
				if (!(*tekst==' '))
					duz++;
				while (*kraj!='\0')
					kraj++;
				/*Uz pomoc while petlje povecavamo velicinu stringa*/
				while (kraj>=tekst ) {
					*(kraj+duz)=*kraj;
					kraj--;
				}
				/*Ako je broj negativan upisemo minus*/
				if (broj<0) {
					temp=-temp;
					pomocni_brojac--;
					stepen--;
					*tekst='-';
					tekst++;
				}
				/*Ubacujemo broj,pocevsi od prve cifre, prema kraju*/
				/*Broj koji treba ubaciti cuvamo u varijabli temp,pomocni brojac je ustvari broj cifara*/
				/*Varijabla stepen nam pokazuje kojim brojem treba djeliti da bismo uzeli cifre redom slijeva nadesno*/
				for (i=0; *tekst!='\0' && i<pomocni_brojac; i++) {
					pomocna=pow(10,stepen-1);
					cifra=temp/pomocna;
					temp=temp-cifra*pomocna;
					stepen--;
					cifra=cifra+'0';
					*tekst=cifra;
					tekst++;
				}
				if (*tekst!='\0')
					*tekst=' ';
				tekst--;
			}

		}
		/*Vracamo sve pomocne varijable na prvobitne vrijednosti,jer cemo ih opet koristiti*/
		temp=broj;
		pomocni_brojac=br_cifara(broj);
		stepen=br_cifara(broj);
		tekst++;
	}
	return ret;
}

int main()
{
	return 0;
}
