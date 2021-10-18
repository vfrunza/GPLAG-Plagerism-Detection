#include <stdio.h>
char *ubaci_broj(char *s,int broj)
{
	char *p=s,*q,*pok1;
	int duzina=0,temp=broj,razmak=1,broj_razmaka,i=0,znak=0;
	/*predznak*/
	if (temp<0) {
		temp=-temp;
		duzina++;
		znak=1;
	}
	/*cifre*/
	do {
		temp/=10;
		duzina++;
	} while (temp>0);
	while(*p!='\0') {
		if(*p==' ') {
			broj_razmaka=0;
			/*Razmak je a nije bio, */
			if(razmak==0) {
				if (broj>=0)
					temp=broj;
				else
					temp=-broj;
				q=p;
				/*provjera koliko je razmaka izmedju rijeci i da li je zadnja*/
				pok1=p+1;
				while(*pok1==' ') {
					pok1++;
					broj_razmaka++;
				}
				/*zadnja rijec nema ubacivanja*/
				if(*pok1=='\0')
					break;
				/*provjera treba li ubaciti i razmak,prosirivanje za potrebnu duzinu*/
				while (*q!='\0') q++;
				if(broj_razmaka==0)
					duzina++;
				while(q>p) {
					*(q+duzina)=*q;
					q--;
				}
				q=p+duzina;
				/*upisivanje eventualnog razmaka */
				if(broj_razmaka==0) {
					*q=' ';
					q--;
					duzina--;
				}
				/*upisivanje cifara*/
				do {
					*q--='0'+temp%10;
					temp=temp/10;
				} while (temp>0);
				/*predznak ako je broj negativan*/
				if(znak==1)
					*q='-';
				p=p+duzina;
			}
			razmak=1;
			p++;

		} else if(razmak==1) {
			razmak=0;
			p++;
		} else p++;

	}

	return s;
}

int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
