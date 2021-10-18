#include <stdio.h>
#include <math.h>

char* ubaci_broj(char* tekst, int broj)
{
	char* pocetak=tekst;
	int temp_d,temp,duzina=0,razmak=0,d=0,negativan=0;
	if(broj<0) {
		broj=broj*(-1);
		negativan=1;
	}
	temp_d=broj;
	while(temp_d>0) {
		duzina++;
		temp_d/=10;
	}
	if(broj==0) duzina=1;
	/*preskakanje razmaka na pocetku*/
	while(*tekst!='\0') {
		if(*tekst==' ') tekst++;
		else break;
	}

	while(*tekst!='\0') {
		if(*tekst==' ') {
			razmak++;
		} 
		else if(razmak!=0) {
			char* kraj=tekst;
			while(*kraj!='\0') kraj++;
			tekst-=(razmak-1); /*vracanje pokazivaca na mjesto nakon prvog razmaka*/
			temp=broj;
			d+=duzina;
			if(negativan==1) d++;
			if(razmak==1) d++; /*ako je razmak=1, mora se dodati jos jedan razmak nakon broja*/
			while(kraj>=tekst) {
				*(kraj+d)=*kraj;
				kraj--;
			}
			if (negativan==1) {
				*tekst++='-';
				d--;
			}
			if(razmak==1) d--;
			if(broj==0) {
				*tekst++='0';
				d--;
			} else {
				while(d>0) {
					int cifra;
					d--;
					cifra=temp/(int)pow(10,d);
					temp-=cifra*pow(10,d);
					*tekst++=cifra+'0';
				}
			}
			if(razmak==1) *tekst++=' ';
			else tekst=tekst+(razmak-2); /*preskakanje ostalih razmaka*/
			razmak=0;
		}
		tekst++;
	}
	return pocetak;
}

int main()
{
	return 0;
}