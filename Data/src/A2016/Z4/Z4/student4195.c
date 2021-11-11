#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

char *obuhvat(char* tekst, float x_lijevi, float y_donji, float x_desni, float y_gornji){
	char *pocetna = tekst, *mjerni_pokazivac,*adresa_trenutnog_para,*p=tekst,*nul_pokazivac=0;
	float x_tacka=0, y_tacka=0;
	int nepravilan_unos=0,predznak=1,ima_tacka=0,broj_cifara=0,stepen_iza_tacke=-1;
	while(*tekst!='\0') {
		if(*tekst!='(') {
			return nul_pokazivac;
		}
		adresa_trenutnog_para=tekst;
		tekst++;
		predznak=1;
		ima_tacka=0;
		broj_cifara=0;
		stepen_iza_tacke=-1;
		x_tacka=0;
		if(*tekst=='-') {
			predznak=-1;
			tekst++;
		}
		mjerni_pokazivac=tekst;
		while(*mjerni_pokazivac!=',' && *mjerni_pokazivac!='.' && *mjerni_pokazivac!=0 && *mjerni_pokazivac>='0' && *mjerni_pokazivac<='9') {
			broj_cifara++;
			mjerni_pokazivac++;
		}
		if(broj_cifara==0){
			return nul_pokazivac;
		}
		while(*tekst!=',') {
			if((*tekst<'0' || *tekst>'9') && *tekst!='.') {
				nepravilan_unos=1;
				break;
			}
			if(*tekst=='.' && (*(tekst-1)<'0'|| *(tekst-1)>'9') ) {
				nepravilan_unos=1;
				break;
			}
			if(*tekst=='.' ) {
				if(ima_tacka)
					return nul_pokazivac;
				ima_tacka=1;
				tekst++;
				continue;
			}
			if(!ima_tacka) {
				x_tacka+=(*tekst - '0') * pow(10,broj_cifara-1);
				broj_cifara--;
			}
			if(ima_tacka) {
				x_tacka+=(*tekst-'0') * pow(10,stepen_iza_tacke);
				stepen_iza_tacke--;
			}
			tekst++;
		}
		if(nepravilan_unos){
			return nul_pokazivac;
		}
		x_tacka*=predznak;
		tekst++;
		predznak=1;
		ima_tacka=0;
		broj_cifara=0;
		stepen_iza_tacke=-1;
		y_tacka=0;
		if(*tekst=='-') {
			predznak=-1;
			tekst++;
		}
		mjerni_pokazivac=tekst;
		while(*mjerni_pokazivac!=',' && *mjerni_pokazivac!='.' && *mjerni_pokazivac!=0 && *mjerni_pokazivac>='0' && *mjerni_pokazivac<='9') {
			broj_cifara++;
			mjerni_pokazivac++;
		}
		if(broj_cifara==0){
			return nul_pokazivac;
		}
		while(*tekst!=')') {
			if((*tekst<'0' || *tekst>'9') && *tekst!='.') {
				nepravilan_unos=1;
				break;
			}
			if(*tekst=='.' && (*(tekst-1)<'0'|| *(tekst-1)>'9') ) {
				nepravilan_unos=1;
				break;
			}
			if(*tekst=='.' ) {
				if(ima_tacka)
					return nul_pokazivac;
				ima_tacka=1;
				tekst++;
				continue;
			}
			if(!ima_tacka) {
				y_tacka+=(*tekst - '0') * pow(10,broj_cifara-1);
				broj_cifara--;
			}
			if(ima_tacka) {
				y_tacka+=(*tekst-'0') * pow(10,stepen_iza_tacke);
				stepen_iza_tacke--;
			}
			tekst++;
		}
		if(nepravilan_unos) {
			return nul_pokazivac;
		}
		y_tacka*=predznak;
		tekst++;
		if(*tekst!=',' && *tekst!=0)
			nepravilan_unos=1;
		if(*tekst==',' && *(tekst+1)=='\0')
			nepravilan_unos=1;
		if(nepravilan_unos) {
			return nul_pokazivac;
		}
		if(*tekst!=0)
			tekst++;
		/*Provjera da li je tacka u pravougaoniku*/
		if( x_tacka-x_desni>EPSILON+0.00001 || x_lijevi-x_tacka>EPSILON+0.00001 || y_tacka-y_gornji>EPSILON+0.00001 || y_donji-y_tacka>EPSILON+0.00001) {
			p=adresa_trenutnog_para;
			if(*tekst==0 && adresa_trenutnog_para!=pocetna){
				adresa_trenutnog_para--;
				p--;
			}
			mjerni_pokazivac=tekst;
			while(*mjerni_pokazivac!=0){
				*adresa_trenutnog_para = *mjerni_pokazivac;
				mjerni_pokazivac++;
				adresa_trenutnog_para++;
			}
			*adresa_trenutnog_para='\0';
			tekst=p;
		}

	}

	tekst=pocetna;
	return tekst;
}

int main(){
	char pom[100] = "(000000000000000000014.555555555555555555555555,5.)";;
	printf("'%s'", 	obuhvat(pom, 1, 5, 4, 6));
	return 0;
}


