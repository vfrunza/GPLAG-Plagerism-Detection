#include <stdio.h>

char* ubaci_broj (char *tekst, int broj)
{
	char *s, *kraj;
	int brojznakova, duzina,provjera, predznak;
	int tmp;
	s=tekst;
	duzina =0;

	/* provjera predznaka */
	if (broj<0) {
		predznak=1;
		duzina++;
	} else predznak=0;
	if(broj<0)
		tmp=-broj;
	else
		tmp=broj;

	/* prebrojavanje cifara*/
	do {
		duzina++;
		tmp=tmp/10;
	} while (tmp>0);


	brojznakova=duzina;
	if(broj<0)
		tmp=-broj;
	else
		tmp=broj;

	/* prolazimo kroz primljeni string, ako naidjemo na razmak broj*/

	while (*tekst!='\0') {
		if(*tekst==' ' && *(tekst-1)==broj%10+'0') tekst++; /* ako je znak prije razmaka jednak zadnjoj cifri broja onda tu ne upisujemo*/


		if (*tekst==' '&& *(tekst-1)!=' ' && tekst-s>0) {
			provjera=0;
			if (*(tekst+1)!=' ') provjera=1; /*pamtimo ako nema razmaka iza da ga mozemo dodati poslije broja*/

			/* pravimo mjesto za upisivanje broja, odnosno pomjeramo string za duzinu broja*/
			kraj=tekst;
			while (*kraj!='\0') kraj++;
			while (kraj>=tekst) {
				*(kraj+duzina)=*kraj;
				kraj--;
			}

			/* pomjeramo se na kraj prostora za broj kako ne bi bio upisan naopako*/
			while(duzina!=0) {
				tekst++;
				duzina--;
			}

			/*rastavljanje na cifre i ubacivanje u string*/

			duzina=brojznakova;
			while(duzina!=0) {
				if(duzina==1 && predznak==1) *tekst='-';
				else *tekst=tmp%10 + '0';
				tmp/=10;
				duzina--;
				tekst--;
			}
			if(broj<0)
				tmp=-broj;
			else
				tmp=broj;
			duzina=brojznakova;
			tekst=tekst+duzina+1;

			/* ako nije bilo razmaka iza razmaka onda ga dodajemo*/
			if(provjera==1) {
				kraj=tekst;

				/* prvo pomjerimo cijeli string za jedno mjesto a zatim na to mjesto ubacimo razmak*/
				while (*kraj!='\0') kraj++;
				while (kraj>=tekst) {
					*(kraj+1)=*kraj;
					kraj--;
				}

				*tekst=' ';
				while (*tekst==' ') {
					tekst++;
				}
			}
		} else
			tekst++;
	}
	return s;
}
int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
