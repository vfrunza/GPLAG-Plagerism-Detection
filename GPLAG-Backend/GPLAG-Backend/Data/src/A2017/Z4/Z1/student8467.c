#include <stdio.h>

int duzina(int x){
	int duzina_broja = 0;
	if(x == 0){
		return 2;
	}
	while(x != 0){
		duzina_broja++;	
		x /= 10;
	}
	return duzina_broja + 1; 
}

const char *ubaci_broj(char *tekst, int broj){
	int negativan = 0; /* logička varijabla, po defaulutu pozitivan*/
	int duzina_broja = duzina(broj);
	int bio_je_ovdje = 0;
	char *kraj;
	char *temp;
	/*Ako je broj negativan to znači da se sastoji od još jednog znaka, '-'*/
	if(broj < 0){
		negativan = 1;
		duzina_broja++;  /*Dodajemo još prostora za znak '-'*/
		broj *= -1;
	}
	
	const char *poc = tekst; /*U postavci zadatka je naglašeno da program mora vraćati pokazivač na početak stringa*/
	
	int razmak = 1; /*Logička varijabla koja služi na registrovanje promjene iz spejsa u neko drugo. Nešto slično interuptu.*/
	
	while(*tekst != '\0'){
		if(*poc == ' ' && bio_je_ovdje != 1){ /*Ovo treba da proguta početne razmak*/
			while(*tekst == ' '){
				tekst++;
			}
			bio_je_ovdje = 1;
		}
		
		if(*tekst == ' '){
			int dodatak = 0, magic = 0; /*varijable za rješavanje problema razmaka, prljav kod, slažem se...*/
			razmak = 1; /*Došlo je do promjene sa slova na razmak, ovo registrujemo kao potencijalno mjesto za ubacivanje broja
			//Potencijalno zato jer se može desiti situacija da se pokazivač nalazi na mjestu iza zadnje riječi, gdje ne treba ubaciti broj
			//To rješavamo sljedećom provjerom*/
			temp = tekst;
			while(*(++tekst) == ' '){
				dodatak++;
				/*Izbaciti će nas iz petlje ako je neki drugi znak od ' ', uključujući i znak '\0'*/
			}
			if(dodatak >= 1){
				magic = 1;
			}
			if(*tekst == '\0' ){
				return poc;  /*To znači da smo došli na kraj i da nemamo šta raditi više*/
			}
			else if(*tekst != ' '){
				/*U ovom slučaju ipak nismo na kraju rečenice, tako da pokazivač vraćamo na mjesto gdje je bio*/
				tekst = temp;
			}
			
			/*pošto smo se uvjerili da se nalazimo na mjestu gdje trebamo ubaciti broj bacamo se na taj posao*/
			/*---------------UBACIVANJE BROJA U STRING------------*/
			/*ovo radimo po taktici odzada prema naprijed*/
			kraj = tekst;
			while(*kraj != '\0'){
				kraj++; /*Pomjeramo pokazivač kraj, na kraj stringa*/
			}
			while(kraj > tekst){
				/*Ovime stvaramo mjesta za naš broj, da ga možemo ubacti*/
				*(kraj + duzina_broja - magic) = *(kraj);
				kraj--;
			}
			/*Naš pokazivač *tekst se u ovom trenutku nalazi na mjestu gdje mi možemo sa prijeda ubaciti broj, al to nam je teže*/
			tekst += duzina_broja; /*Pomjeramo ga tako da možemo odzada ubaciti broj i jedan razmak odzada*/
			*tekst = ' ';
			tekst = tekst - 1;
			int zrtva = broj;
			/*Rješavamo kada je broj = 0*/
			if(broj == 0){
				*(tekst) = 0 + '0';
				tekst--;
			}
			while(zrtva != 0){
				*(tekst) = (zrtva % 10) + '0';
				zrtva /= 10;
				tekst--;
			}
			if(negativan){
				*(tekst) = '-';
			}
			tekst += duzina_broja + dodatak + magic; /*Sumnjivo doboga*/ /*rješava problem kada imamo više od jednog razmaka*/
		/*--------------------------------------------------------------------*/
		}else if(razmak == 1){
			razmak = 0;
		}
		tekst++;
	}
	
	return poc;
}

int main() {
	/*
	char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
	printf("\"%s\"", ubaci_broj(s, 0));*/
	/*KO OVO GLEDA FAKAT IMA PREVIŠE SLOBODNOG VREMENA*/
	return 0;
}
