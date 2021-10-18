#include <stdio.h>

int main() {
	/*printf("Zadaća 1, Zadatak 1");*/
	float Tarik_Iparc,Tarik_IIparc,Tarik_Pris,Tarik_Zad,Tarik_Usm,Tarik_Uk,Tarik_Ocj;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Tarik_Iparc);
	if(Tarik_Iparc<0 || Tarik_Iparc > 20) { printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&Tarik_IIparc);
	if(Tarik_IIparc < 0 || Tarik_IIparc > 20 ) { printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&Tarik_Pris);
	if(Tarik_Pris < 0 || Tarik_Pris > 10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&Tarik_Zad);
	if(Tarik_Zad < 0 || Tarik_Zad > 10 ) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&Tarik_Usm);
	if(Tarik_Usm < 0 || Tarik_Usm > 40 ) { printf("Neispravan broj bodova"); return 0;}
	
	float Bojan_Iparc,Bojan_IIparc,Bojan_Pris,Bojan_Zad,Bojan_Usm,Bojan_Uk,Bojan_Ocj;
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Bojan_Iparc);
	if(Bojan_Iparc < 0 || Bojan_Iparc > 20) { printf("Neispravan broj bodova"); return 0;} 
	printf("II parcijalni ispit: ");
	scanf("%f",&Bojan_IIparc);
	if(Bojan_IIparc < 0 || Bojan_IIparc > 20 ) { printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&Bojan_Pris);
	if(Bojan_Pris < 0 || Bojan_Pris > 10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&Bojan_Zad);
	if(Bojan_Zad < 0 || Bojan_Zad > 10) { printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&Bojan_Usm);
	if(Bojan_Usm <0 || Bojan_Usm > 40) {printf("Neispravan broj bodova"); return 0;}
	
	float Mirza_Iparc,Mirza_IIparc,Mirza_Pris,Mirza_Zad,Mirza_Usm,Mirza_Uk,Mirza_Ocj;
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Mirza_Iparc);
	if(Mirza_Iparc<0||Mirza_Iparc>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&Mirza_IIparc);
	if(Mirza_IIparc<0||Mirza_IIparc>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&Mirza_Pris);
	if(Mirza_Pris<0||Mirza_Pris>10){ printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&Mirza_Zad);
	if(Mirza_Zad<0||Mirza_Zad>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: "); 
	scanf("%f",&Mirza_Usm);
	if(Mirza_Usm<0||Mirza_Usm>40) {printf("Neispravan broj bodova"); return 0;}
	
	
	Tarik_Uk=Tarik_Iparc+Tarik_IIparc+Tarik_Pris+Tarik_Zad+Tarik_Usm;
	Bojan_Uk=Bojan_Iparc+Bojan_IIparc+Bojan_Pris+Bojan_Zad+Bojan_Usm;
	Mirza_Uk=Mirza_Iparc+Mirza_IIparc+Mirza_Pris+Mirza_Zad+Mirza_Usm;
	
	/*if(Tarik_Uk < 55 && Bojan_Uk < 55 && Mirza_Uk < 55)  
	if(Tarik_Uk >= 55 ||  Bojan_Uk >= 55 ||  Mirza_Uk >= 55) {printf("Jedan student je polozio. "); return 0;}*/
	
	
	if( Tarik_Uk >= 55 && Tarik_Uk<65) {Tarik_Ocj=6;}
	else if (Tarik_Uk >=65 && Tarik_Uk <75 ) {Tarik_Ocj=7;}
	else if (Tarik_Uk >=65 && Tarik_Uk <85 ) {Tarik_Ocj=8;}
	else if ( Tarik_Uk>=85 && Tarik_Uk <92) {Tarik_Ocj=9;}
	else if (Tarik_Uk >= 92 &&Tarik_Uk<=100) {Tarik_Ocj=10;}
	else {Tarik_Ocj=0;}
	
	if(Bojan_Uk >=55 && Bojan_Uk <65) {Bojan_Ocj=6;}
	else if(Bojan_Uk >=65 && Bojan_Uk < 75) {Bojan_Ocj=7;}
	else if(Bojan_Uk >= 75 && Bojan_Uk < 85) {Bojan_Ocj=8;}
	else if(Bojan_Uk >= 85 && Bojan_Uk < 92){Bojan_Ocj=9;}
	else if(Bojan_Uk >=92 && Bojan_Uk <=100) {Bojan_Ocj=10;}
	else {Bojan_Ocj=0;}
	
	if(Mirza_Uk >=55 && Mirza_Uk < 65) {Mirza_Ocj=6;}
	else if (Mirza_Uk >=65 && Mirza_Uk <75) {Mirza_Ocj=7;}
	else if (Mirza_Uk >=75 && Mirza_Uk <85){Mirza_Ocj=8;}
	else if (Mirza_Uk >=85 && Mirza_Uk < 92) {Mirza_Ocj=9;}
	else if (Mirza_Uk >=92 && Mirza_Uk<=100) {Mirza_Ocj=10;}
	else {Mirza_Ocj=0;}
	
	
	if(Tarik_Ocj==0 && Bojan_Ocj==0 && Mirza_Ocj==0 ) { printf("Nijedan student nije polozio. "); return 0;}
	else if((Tarik_Ocj <=10 || Tarik_Ocj >=6) && Bojan_Ocj <6 && Mirza_Ocj <6 ) {printf("Jedan student je polozio. ");}
	else if((Mirza_Ocj <=10 || Mirza_Ocj >=6)&& Bojan_Ocj <6 && Tarik_Ocj <6) {printf("Jedan student je polozio. ");}
	else if( (Bojan_Ocj<=10 || Bojan_Ocj >=6)&& Mirza_Ocj<6 && Tarik_Ocj<6 ) {printf("Jedan student je polozio. ");}
	
	if( (Tarik_Ocj <=10 || Tarik_Ocj >=6)&& (Mirza_Ocj <=10 || Mirza_Ocj >=6)&& Bojan_Ocj <6  ){printf("Dva studenta su polozila.");}
	else if((Tarik_Ocj <=10 || Tarik_Ocj >=6)&& (Bojan_Ocj<=10 || Bojan_Ocj >=6) && Mirza_Ocj<6) {printf("Dva studenta su polozila");}
	else if((Bojan_Ocj <=10 || Bojan_Ocj >=6)&& (Mirza_Ocj<=10 || Mirza_Ocj>=6)&& Tarik_Ocj<6) {printf("Dva studenta su polozila.");}
	
	
	return 0;
}
