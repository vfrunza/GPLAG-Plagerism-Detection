#include <stdio.h>
#include <stdlib.h>
char *ubaci_broj(char *tekst, int broj)
{

	char *s = tekst;
	int broji_cifre = 0;
	int brojacrazmaka = 0;
	int n = broj;
	if(n<0) broji_cifre = broji_cifre+1; /*cuvaj i duzinu za predznak */
	n = abs(n);
	while(n != 0) {
		n/=10;
		broji_cifre++;
	}


	while(*s==' ' && *s!='\0') s++; /*Pomjeramo pokazivac sve dok je razmak */

	while(*s!= '\0') {

		while(*s!=' ' && *s!='\0') {
			s++;

		}

		char *tmp=s;
		while(*tmp == ' ' && *tmp!= '\0')  {
			tmp++;
			brojacrazmaka=1;
		}


		if(*tmp!='\0') {
			char * kraj=s;

//if(brojacrazmaka==1) broji_cifre=broji_cifre+1;

			while(*kraj!='\0') kraj++;
			while(kraj > s) {
				*(kraj + broji_cifre+1) = *kraj;
				kraj--;
			}
			s++;
			char *pbr = s + broji_cifre ;
			n = broj;
			if(brojacrazmaka==1) {
				*pbr =  ' ';
				pbr --;
			}

			while(n!=0) {
				*pbr=n%10 +'0';
				n/=10;
				pbr--;

			}

		} else break;

		while(*s>= '0' && *s<='9' && *s!='\0') s++;
		while(*s== ' ' && *s!='\0') s++;
	}
	return tekst;

}

int main()
{

	return 0;
}
