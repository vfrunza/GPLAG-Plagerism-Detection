#include <stdio.h>
#include <math.h>
char* ubaci_broj(char* tekst,int broj){
	int cifra,br_cifara=0,razmak=1,br=0,i=0,broj0;
	int broj1,br_1=0,broj2=broj,broj_rijeci=0,brojac=0,brojac_1=0;
	char* s = tekst;
	char* kraj=tekst;
	//ukoliko ima razmaka na pocetku stringa pomjeri pokazivac na prvi znak 
	while(*tekst==' '){
		tekst++;
		brojac_1++;
	}
	//prebroji rijeci u stringu
	while(*tekst!='\0'){
		if(*tekst==' '){
			razmak=1;
	}else if(razmak==1){
		razmak=0;
		broj_rijeci++;
	}
	tekst++;
	brojac_1++;
	}
    //vrati pokazivac na pocetak stringa
	while(brojac_1!=0){
		tekst--;
		brojac_1--;
	}
    //obrni zadani broj 
    do{
    	cifra=broj2%10;
    	broj2=broj2/10;
    	br_cifara+=1;
    }while(broj2 !=0);
    
    i=br_cifara;
    broj0=broj;
    do{
    	cifra=broj0%10;
    	br+=cifra*pow(10,i-1);
    	broj0=broj0/10;
        i--;
    }while(broj0!=0);
    while(*tekst==' '){
    	tekst++;
    }
   razmak=0;
    //sada ubaci zadani broj izmedju svake rijeci
	while(*tekst !='\0'){
	if(*tekst == ' ' && razmak==0 && br_1==0 && brojac<(broj_rijeci-1)){
			brojac+=1;
			razmak=1;
			while(*kraj!='\0'){
				kraj++;
			}
			broj1=br;
			//ukoliko je broj negativan zauzmi jos jedno mjesto za minus
			if(broj<0){
				broj1=fabs(br);
        while(kraj>tekst){
        	*(kraj+br_cifara+2)=*kraj;
        	kraj--;
        }
        tekst++;
        *tekst++='-';
			}else if(broj>0){
				while(kraj>tekst){
					*(kraj+br_cifara+1)=*kraj;
					kraj--;
				}
				tekst++;
			}
			//postavi varijablu br_1 na vrijednost 1 tako da se broj ne ubacuje jedan za drugim
        do{
        	cifra=broj1%10;
        	*tekst++=cifra + '0';
        	broj1/=10;
        	br_1=1;
		}while(broj1!=0);
		if(br_1==1 && *tekst!=' '){
		*tekst++=' ';
		}
		
	}else if(*tekst!=' ' || razmak==1){
	razmak=0;
	br_1=0;
	tekst++;
	}else if(*tekst==' ' && br_1==1){
		tekst++;
	}else{
		tekst++;
	}
}
	return s;
}
int main() {
	char tekst[100]="Ovo je neki primjer teksta";
	ubaci_broj(tekst,1234);
	printf("%s",tekst);
	return 0;
}
