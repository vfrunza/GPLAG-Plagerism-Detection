#include <stdio.h>

int brojCifri(int broj)
{
	int brojac=0;
	do{
		brojac++;
		broj/=10;
	}while(broj!=0);
	return brojac;
}



char* ubaci_broj(char* tekst,int broj){
	
	int zbunjola;
	int pomagaj;
	int jedanspejs;
	int negativan=0;
	int cifre=brojCifri(broj);
	int pomocnibroj=broj;
	if(broj<0){ negativan=1;pomocnibroj*=(-1);}
	
	char *pocetak=tekst;
	while(*pocetak!='\0'){
		jedanspejs=0;
		pomagaj=0;
		broj=pomocnibroj;
		while(*pocetak==' ') pocetak++;
		while(*pocetak!='\0' && *pocetak!=' ') pocetak++;
		if(*pocetak=='\0') return tekst;
		
		char *zadnjaRijec=pocetak;
		while(*zadnjaRijec==' ') {zadnjaRijec++;pomagaj++;}
		if(*zadnjaRijec=='\0') return tekst;
		if(pomagaj==1) jedanspejs=1;
		
		char *pamti=pocetak;
		char *prostor=pocetak;
		while(*prostor!='\0') prostor++;
		
		while(prostor!=pocetak-1){ *(prostor+jedanspejs+negativan+cifre)=*prostor;prostor--;}
		pocetak++;
		if(negativan) *pocetak++='-';
		zbunjola=cifre-1;
		do{
			*(pocetak+zbunjola--)=(broj%10+48);
			broj/=10;
		}while(broj!=0);
		pocetak=pocetak+jedanspejs+negativan+cifre;
	}
	return tekst;
}

int main(){
	char ime[200]={"Ovo je   neki primjer  teksta"};
	char *novi=ubaci_broj(ime,-123);
	printf("%s",novi);
	return 0;
}