#include <stdio.h>
#include <math.h>

char* ubaci_broj(char* s, int broj) {
	
	char *pocetak, *pok, *pok1, *kraj, *provjerijelzadnja;
	int ubacivanje=1, temp=broj, brojac=0;
	
	do{
		ubacivanje++;     //prebrojavanje cifara broja
		temp/=10;
	}while(temp!=0);
	
	
	if(broj<0) {
		brojac++;
		ubacivanje++;
		broj=-broj;
	}
	pok=s;
	while(*pok==' ') pok++; //preskoci razmak ako je na pocetku
	while(*pok!='\0'){
		if(*pok==' '){
			provjerijelzadnja=pok;
			while(*provjerijelzadnja==' ') provjerijelzadnja++;
			if(provjerijelzadnja=='\0')break; //nema umetanja ako je zadnja
			pocetak=pok;
			kraj=pok;
			
			while(*kraj==' ')kraj++;
			brojac=kraj-pocetak; //broj razmaka ako zatreba
			pok1=pok;
			
			while(*pok1!='\0') pok1++;
			while(pok1>pok){
				*(ubacivanje+pok1)=*pok1;
				pok1--; //nakon ovog pok1 ce biti kraj umetanja a pok je na razmaku koji treba zadrzati pa umecemo izmedju njih dvoje
				
			}
			pok1+=ubacivanje; 
			temp=broj;
		
			*pok1 = ' ';
			pok1--;
			while(temp!=0){
				*pok1=temp%10+'0';
				temp/=10;
				pok1--;
			}
			if(broj<0) {
				*pok1='-';
				pok1--;
			}
			*pok1=' ';
			pok+=ubacivanje+brojac;
		}
		pok++;
	}
	return s;
	
}
int main() {
	
	char s[44] = "Ovo je neki primjer teksta";
	printf("\"%s\"", ubaci_broj(s, 123));
	
	return 0;
}
