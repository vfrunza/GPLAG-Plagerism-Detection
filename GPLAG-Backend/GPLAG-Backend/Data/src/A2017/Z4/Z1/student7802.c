#include <stdio.h>

int prebroji_mjesta_za_broj(int br)
{
	int cifre, broj_cifara = 0;

	if(br< 0) {
		while(br != 0) {
			cifre = br % 10;
			broj_cifara++;
			br = br / 10;
		}
		/*Zbog minusa koji se nalazi ispred broja*/
		broj_cifara++;

	} else {
		while(br != 0) {
			cifre = br % 10;
			broj_cifara++;
			br = br / 10;
		}
	}
	return broj_cifara;
}
int prebroji_rijec(char *s3)
{
	int br_rijeci = 0;

	while(*s3 != '\0') {
		if(((*s3 >= 'A' && *s3 <= 'Z') || (*s3 >= 'a' && *s3 <= 'z')) && !((*(s3 + 1) >= 'A' && *(s3+1) <= 'Z') || (*(s3 + 1) >= 'a' && *(s3+1) <= 'z'))) {
			br_rijeci++;
		}
		s3++;
	}
	return br_rijeci;
}
char* ubaci_broj (char* tekst, int broj)
{
	char* s1 = tekst;
	char *q = tekst;
	char *r = tekst;
	char *p = tekst;
	char *a = tekst;
	char *s2 = tekst;

	int brojac = 0, cifra, broj_razmaka = 0;
	int broj_mjesta = prebroji_mjesta_za_broj(broj);
	int temp, broj_puta = 0, broj_rijeci;

	broj_rijeci = prebroji_rijec(tekst);


	/*Preskacemo sve sto nije slovo i sto  se nalazi ispred prvog slova*/
	while(*s1 == ' ' || *s1 < 'A' || (*s1 > 'Z' && *s1 < 'a') || *s1 > 'z') {
		s1++;
	}
	/**Postavljanje pokazivaca q na prvo slovo*/
	q = s1;

	while(broj_puta < broj_rijeci - 1) {
		temp = broj;
		/*Pomjeranje pokazivaca q do prvog razmaka*/
		while(*q != ' ' && *q != '\0') {
			q++;
		}
		/*Postavljanje pokazivaca a na prvi razmak*/
		a = q;
		r = q;

		/*Brojanje razmaka izmedu dvije rijeci*/
		broj_razmaka = 0;
		while(*r == ' ' && *r != '\0') {
			r++;
			broj_razmaka++;
		}

		/*Pomjeranje pokazivaca p do kraja stringa*/
		while (*p != '\0') {
			p++;

		}

		/*Pomjeranje stringa za potreban broj mjesta  u desno zbog potrebnih razmaka*/

		if(broj_razmaka == 1) {
			while(p >= a) {
				*(p + broj_mjesta +1) = *p;
				p--;
			}
		}

		else {
			while(p > a) {
				*(p + broj_mjesta) = *p;
				p--;
			}
		}

		/*Pomjeranje pokazivaca q za onoliko mjesta kolika je duzina broja, jer upisivanje broja krece zdesna na lijevo*/
		brojac = 0;
		while(brojac < broj_mjesta) {
			q++;
			brojac++;
		}
		while(q > a) {

			p = q;
			if(temp < 0) {
				temp = temp * (-1);
				while(temp != 0) {
					cifra = temp % 10;
					*p = cifra + '0';
					p--;
					if(q = a+1) *p = '-';
					temp = temp / 10;
					q--;
				}
			} else {
				while(temp != 0) {
					cifra = temp % 10;
					*p = cifra + '0';
					p--;
					temp = temp / 10;
					q--;
				}
			}
		}
		while((*q < 'A' || (*q > 'Z' && *q < 'a') || *q > 'z' || *q == ' ') && *q != '\0') {
			q++;
		}
		p = q;

		broj_puta++;
	}
	while(*s2 != '\0') {
		s2++;
	}
	s2--;


	while(*s2 < 'A' || (*s2 > 'Z' && *s2 < 'a') || *s2 > 'z' || *s2 == ' ') {
		*s2 = ' ';
		s2--;
	}




	return tekst;
}

int main()
{

	return 0;
}
