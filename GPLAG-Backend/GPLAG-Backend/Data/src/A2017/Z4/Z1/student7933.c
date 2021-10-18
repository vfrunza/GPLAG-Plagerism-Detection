#include <stdio.h>

char* ubaci_broj (char* tekst, int broj){
	char *r, *s, *p, *k;
	s = r = p = k = tekst;
	int duzina = 0, temp;
	int razmaka = 0;
	int minus;
	
	/*Abs*/
	temp = (broj < 0)? -broj : broj;
	minus = (broj < 0)? 1 : 0;
	
	/*Broj cifara*/
	if(temp == 0) 
		duzina = 1;
	else
		while(temp > 0){
			duzina++;
			temp /= 10;
		}
	
	//Preskoci prve razmake
	while(*s == ' ')
		s++;
	
	//Idi k na kraj stringa
	k = s;
	while(*k != '\0')
		k++;
	k--;
	
	/*Ako ima razmaka na kraju, pomjeri k na kraj posljednje rijeci*/
	while(*k == ' ')
		k--;
	
	while(s < k){
		
		if(*s == ' ') {
			/*abs broja*/
			temp = (broj < 0)? -broj : broj;
			
			/*Idi p do kraja*/
			p = s;
			while(*p != '\0') p++;
			
			/*Pomjeri string za duzinu broja*/
			while(p > s){
				*(p+duzina+minus) = *p;
				p--;
			}
			
			/*Pomjeri p za duzinu od s*/
			p = s + duzina+minus;
			/*Idi unazad i uzimaj cifru po cifru broja i convert-uj je u char*/
			while(p > s){
				*p = '0' + temp%10;
				temp /= 10;
				p--;
			}
			if(minus){
				p++;
				*p = '-';
			}
			
			/*s na prvi karakter nakon ubacenog broja*/
			s += duzina+1+minus;
			
			/*prodji kroz razmake i prebroj ih*/
			p = s;
			razmaka = 0;
			while(*p == ' ') {
				razmaka++;
				p++;
			}
			
			/*velicina stringa promjenjena*/
			k += duzina;
			
			/*nema razmaka, ubaci jedan*/
			if(razmaka == 0){
				/*idi p na kraj*/
				p = s;
				while(*p != '\0') p++;
				
				/*pomjeri citav string od s za jedno mjesto udesno*/
				while(p >= s){
					*(p+1) = *p;
					p--;
				}
				/*postavi razmak*/
				p++;
				*p = ' ';
				
				/*sada postoji jedan razmak*/
				razmaka++;
				//dodat razmak, pa povecati k za 1
				k++;
			}
			
			/*pomjeri s za broj razmaka*/
			s += razmaka;
			
			//printf("\n%s", r);	
		}
		
		if(*s == '\0') break;
		
		s++;
	}
	
	return r;
}

int main() {
	
	char tekst[1000] = "      Ovo   je neki     primjer   teksta     ";
	//printf("%s", tekst);
	printf("\n%s", ubaci_broj(tekst, 0));
	
	return 0;
}
