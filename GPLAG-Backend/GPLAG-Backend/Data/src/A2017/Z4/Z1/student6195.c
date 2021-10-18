#include <stdio.h>

char *ubaci_broj(char *tekst, int broj)
{
	int razmak = 1, duzina = 0, broj_rijeci = 0,broj2_rijeci=0, znak = 1,raz1=0;
	/* postavljamo pokazivace na prvo slovo stringa */
	char *pomocni1 = tekst;
	char *pomocni2 = tekst;
	int temp = broj;

	/* Ako je broj negativan, zapamti mu znak, i pretvori ga u pozitivan, zatim prebroji koliko ima cifara */
	if(temp<0) {
		temp=-temp;
		znak=-1;
		duzina++;
		do {
			temp/=10;
			duzina++;
		} while (temp>0);
	} else {
		do {
			temp/=10;
			duzina++;
		} while (temp>0);
	}
	/* prvi pokazivac ide kroz rijec, i kad dodje do kraja stringa, vrati ga na zadnji clan stringa*/
	while(*pomocni1 != '\0') {
		if(*pomocni1 == ' ') {
			razmak = 1;
			pomocni1++;
		} else if(razmak == 1) {
			razmak = 0;
			broj_rijeci++;
			pomocni1++;
		} else
			pomocni1++;
	}
	pomocni1--;
	razmak=1;
	/* idemo kroz string s desna na lijevo */
	while(pomocni1 >= tekst) {
		/* kad naidjemo na razmak... */
		if(*pomocni1==' ') {
			if(razmak==0 && broj2_rijeci<broj_rijeci) {
				raz1=0;
				/* ako slovo prije slova na koje pokazivac pokazuje nije razmak povecaj duzinu i stavi logicku raz1 = 1 */
				if(*(pomocni1-1)!=' ') {
					duzina++;
					raz1=1;
				}
				/* kad naidjes na razmak, sve dok je razmak, pokazivac samo pomjeraj ulijevo */
				else {
					while (*pomocni1==' ') {
						pomocni1--;
					}
					/*vratimo ga na posljednji razmak na koji smo naisli */
					pomocni1++;
				}
				/* sada drugi pokazivac pomjeramo na kraj stringa */
				while (*pomocni2!='\0') {
					pomocni2++;
				}
				/* sada prepisujemo sve rijeci za onoliko mjesta koliko trebamo osloboditi da se broj upise */
				while (pomocni2>pomocni1) {
					*(pomocni2+duzina)=*pomocni2;
					pomocni2--;
				}
				/* Ako je razmak 1 pokazivac postavimo na razmak, duzinu smanjimo, i pomjeramo pokazivac ulijevo */
				pomocni2=pomocni1+duzina;
				if(raz1==1) {
					*pomocni2=' ';
					duzina--;
					pomocni2--;
				}
				temp=broj;
				if(broj<0)
					temp=-temp;
				/* konverzija int u char, broj pretvaramo u string */
				do {
					*pomocni2='0'+temp%10;
					temp=temp/10;
					pomocni2--;
				} while(temp>0);
				/*ako je broj negativan, ostavili smo mu mjesto za znak -, sad taj minus upisi */
				if(znak==-1)
					*pomocni2='-';
			}
			razmak=1;
			pomocni1--;
		}
		/* broj2_rijeci broji sve rijeci osim prve i zadnje, tj broji rijeci gdje ce ubaciti broj */
		else if(razmak==1) {
			razmak=0;
			broj2_rijeci++;
			pomocni1--;
		} else
			pomocni1--;
	}
	return tekst;
}
int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
