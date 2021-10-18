#include <stdio.h>
#include <math.h>
char* ubaci_broj(char* tekst,int broj)
{
	char* pok=tekst;
	int broj_razmaka=0,predznak=0,broj_cifara=0,n=0,n1=0,n2=0;
	if(broj<0) predznak=1;
	n=fabs(broj);
	while(n!=0) {
		n1=n1*10+n%10;
		broj_cifara++;
		n/=10;
	}
	int pomocna2=broj_cifara;
	int broj_cifara1=broj_cifara;
	broj_cifara+=predznak;
	int pomocna=broj_cifara;
	while(*tekst!='\0') {
		n2=n1;
		if(*tekst>='a' && *tekst<='z' || *tekst>='A' && *tekst<='Z') {
			while(*tekst>='a' && *tekst<='z' || *tekst>='A' && *tekst<='Z') tekst++;
			if(*tekst==' ') {
				while(*tekst==' ') {
					tekst++;
					broj_razmaka++;
				}
				if(*tekst>='a' && *tekst<='z' || *tekst>='A' && *tekst<='Z') {
					tekst--;
					while(*tekst==' ') tekst--;
					tekst++;
					if(broj_razmaka==1) broj_cifara++;
					char* pomocni=tekst;
					while(*pomocni!='\0') pomocni++;
					while(pomocni>tekst) {
						*(pomocni+broj_cifara)=*pomocni;
						pomocni--;
					}
					tekst++;
					if(predznak) *tekst++='-';
					while(pomocna2!=0) {
						*tekst++=n2%10+'0';
						n2/=10;
						pomocna2--;
					}
					if(broj_razmaka==1) *tekst++=' ';
				}
				if(*tekst=='\0') break;
			}
		} else tekst++;
		if(*tekst=='\0') break;
		broj_razmaka=0;
		broj_cifara=pomocna;
		pomocna2=broj_cifara1;
	}
	return pok;
}
int main()
{
	return 0;
}
