#include <stdio.h>
#include <math.h>

int DaLiImaNula(int pocBr,int broj)
{
	int suma1=0,suma2=0;
	while(pocBr!=0) {
		suma1++;
		pocBr/=10;
	}
	while(broj!=0) {
		suma2++;
		broj/=10;
	}
	if(suma1==suma2) return 0;
	return 1;
}

int duzina(int br)
{
	int suma=0;
	if(br<0) suma++;
	while(br!=0) {
		suma++;
		br/=10;
	}
	return suma;
}

int okreni( int br)
{
	int broj=0;
	while(br!=0) {
		broj=(broj+(br%10))*10;
		br/=10;
	}
	broj/=10;
	return broj;
}

char* ubaci_broj (char* tekst, int broj)
{

	char *pocetak=tekst,*k;
	int duzinacifre,pocBr=broj,imaNula=0;
	broj=okreni(broj);
	int cifra;
	int t=broj;
	broj=fabs(broj);
	if(DaLiImaNula(pocBr,broj)) imaNula=1;
	char *hromatika=tekst;
	while(*hromatika!='\0') {
		while(*hromatika==' ') {
			hromatika++;
		}
		while(*hromatika!=' ') {
			hromatika++;
			if(*hromatika=='\0') return pocetak;
		}
		char *h=hromatika;

		/*Provjera da li je zadnja rijec*/
		
		k=hromatika;
		while(*k==' ') {
			k++;
		}
		if(*k=='\0') return pocetak;

		/*prebrojavamo razmake*/

		int brRazmaka=0;
		while(*hromatika==' ') {
			brRazmaka++;
			hromatika++;
		}
		duzinacifre=duzina(t);
		if(brRazmaka==1) duzinacifre=duzinacifre+1;
		if(imaNula==1) duzinacifre++;
		
		/*Pravimo prostor za duzinu cifre*/

		while(*tekst!='\0') {
			tekst++;
		}
		char*text=tekst-1; 
		while(duzinacifre!=0) {
			*tekst=' ';
			tekst++;
			duzinacifre--;
		}
		*tekst='\0';
		tekst--;

		

		while(text!=h) {
			*tekst=*text;
			tekst--;
			text--;
		}
		text++;
		
		/*ubacivanje cifre*/
		
		if(t<0) {
			*text='-';
			text++;
		}

		while(broj!=0) {
			cifra=broj%10;
			broj/=10;
			*text=cifra+'0';
			text++;
		}
		
		if(imaNula==1) {
			*text='0';
			text++;
		}
		*text=' ';
		if(brRazmaka>1) {
			brRazmaka=brRazmaka-2;
			while(brRazmaka!=0) {
				*text=' ';
				text++;
				brRazmaka--;
			}
		}

		hromatika=text;
		broj=fabs(t);
		text=tekst;
		if(brRazmaka==1) duzinacifre=duzinacifre-1;

	}

	return pocetak;
}
int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
