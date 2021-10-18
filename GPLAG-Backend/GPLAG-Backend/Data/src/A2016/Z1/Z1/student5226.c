#include <stdio.h>

int main() {
	float Tarik_Iparcijala,Tarik_IIparcijala,Tarik_Prisustvo,Tarik_Zadace,Tarki_ZavrsniIspit,Tarik_Bodovi;
	float Bojan_Iparcijala,Bojan_IIparcijala,Bojan_Prisustvo,Bojan_Zadace,Bojan_ZavrsniIspit,Bojan_Bodovi;
	float Mirza_Iparcijalni,Mirza_IIparcijalni,Mirza_Prisustvo,Mirza_Zadace,Mirza_ZavrsniIspit,Mirza_Bodovi;
	int Tarik_Ocjena, Bojan_Ocjena,Mirza_Ocjena;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijani: ");
	scanf("%f", &Tarik_Iparcijala);
	if(Tarik_Iparcijala<0 || Tarik_Iparcijala>20) { printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni: ");
	scanf("%f",&Tarik_IIparcijala);
	if(Tarik_IIparcijala<0 || Tarik_IIparcijala>20) {printf("Neispravan broj bodova. ");return 0;}
	printf("Prisustvo: ");
	scanf("%f",&Tarik_Prisustvo);
	if(Tarik_Prisustvo<0 || Tarik_Prisustvo>10) {printf("Neispravan broj bodova. "); return 0;}
	printf("Zadace: ");
	scanf("%f",&Tarik_Zadace);
	if(Tarik_Zadace<0 || Tarik_Zadace>10) {printf("Neispravan broj bodova."); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&Tarki_ZavrsniIspit);
	if(Tarki_ZavrsniIspit<0 || Tarki_ZavrsniIspit>40) {printf("Neispravan broj bodova. "); return 0;}
	
	printf("\nUnesite bodove za Bojana: \n");
	printf("I parcijala: ");
	scanf("%f",&Bojan_Iparcijala);
	if(Bojan_Iparcijala<0 || Bojan_Iparcijala>20) {printf("Neispravan broj bodova. "); return 0;}
	printf("II parcijala: ");
	scanf("%f",&Bojan_IIparcijala);
	if(Bojan_IIparcijala<0 || Bojan_IIparcijala>20) {printf("Neispravan broj bodova. "); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&Bojan_Prisustvo);
	if(Bojan_Prisustvo<0 || Bojan_Prisustvo>10) {printf("Neispravan broj bodova. "); return 0;}
	printf("Zadace: ");
	scanf("%f",&Bojan_Zadace);
	if(Bojan_Zadace<0 || Bojan_Zadace>10) {printf("Neispravan broj bodova. "); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&Bojan_ZavrsniIspit);
	if(Bojan_ZavrsniIspit<0 || Bojan_ZavrsniIspit>40) {printf("Neispravan broj bodova. "); return 0;}
	
	printf("\nUnesite bodove za Mirzu: \n");
	printf("I parcijalni: ");
	scanf("%f",&Mirza_Iparcijalni);
	if(Mirza_Iparcijalni<0 || Mirza_Iparcijalni>20) {printf("Neispravan broj bodova. "); return 0;}
	printf("II parcijalni: ");
	scanf("%f",&Mirza_IIparcijalni);
	if(Mirza_IIparcijalni<0 || Mirza_IIparcijalni>20) {printf("Neispravan broj bodova. "); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&Mirza_Prisustvo);
	if(Mirza_Prisustvo<0 || Mirza_Prisustvo >10) {printf("Neispravan broj bodova. "); return 0;}
	printf("Zadace: ");
	scanf("%f",&Mirza_Zadace);
	if(Mirza_Zadace<0 || Mirza_Zadace>10) {printf("Neispravan broj bodova. "); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&Mirza_ZavrsniIspit);
	if(Mirza_ZavrsniIspit<0 || Mirza_ZavrsniIspit>40) {printf("Neispravan broj bodova. "); return 0;}
	
	Tarik_Bodovi=Tarik_Iparcijala+Tarik_IIparcijala+Tarik_Prisustvo+Tarik_Zadace+Tarki_ZavrsniIspit;
	if(Tarik_Bodovi>=55 && Tarik_Bodovi<65)
	Tarik_Ocjena=6;
	else if(Tarik_Bodovi<=65 && Tarik_Bodovi>75)
	Tarik_Ocjena=7;
	else if(Tarik_Bodovi>=75 && Tarik_Bodovi<85)
	Tarik_Ocjena=8;
	else if(Tarik_Bodovi>=85 && Tarik_Bodovi<95)
	Tarik_Ocjena=9;
	else 
	Tarik_Ocjena=10;
	
	Bojan_Bodovi=Bojan_Iparcijala+Bojan_IIparcijala+Bojan_Prisustvo+Bojan_Zadace+Bojan_ZavrsniIspit;
	if(Bojan_Bodovi>=55 && Bojan_Bodovi<65)
	Bojan_Ocjena=6;
	else if(Bojan_Bodovi>=65 && Bojan_Bodovi<75)
	Bojan_Ocjena=7;
	else if(Bojan_Bodovi>=75 && Bojan_Bodovi<85)
	Bojan_Ocjena=8;
	else if(Bojan_Bodovi>=85 && Bojan_Bodovi<95)
	Bojan_Ocjena=9;
	else
	Bojan_Ocjena=10;
	
	Mirza_Bodovi=Mirza_Iparcijalni+Mirza_IIparcijalni+Mirza_Zadace+Mirza_Prisustvo+Mirza_ZavrsniIspit;
	if(Mirza_Bodovi>=55 && Mirza_Bodovi<65)
	Mirza_Ocjena=6;
	else if(Mirza_Bodovi>=65 && Mirza_Bodovi<75)
	Mirza_Ocjena=7;
	else if(Mirza_Bodovi>=75 && Mirza_Bodovi<85)
	Mirza_Ocjena=8;
	else if(Mirza_Bodovi>=85 && Mirza_Bodovi<95)
	Mirza_Ocjena=9;
	else
	Mirza_Ocjena=10;
	
	if(Tarik_Bodovi>=55.00 && Mirza_Bodovi>=55.00 && Bojan_Bodovi>=55.00)
	{
		printf(" \nSva tri studenta su polozila.");
	    if(Tarik_Ocjena==Mirza_Ocjena && Mirza_Ocjena==Bojan_Ocjena && Tarik_Ocjena==Bojan_Ocjena)
	    printf("\nSva tri studenta imaju istu ocjenu.");
	    else if((Tarik_Ocjena==Mirza_Ocjena && Mirza_Ocjena!=Bojan_Ocjena && Tarik_Ocjena!=Bojan_Ocjena )||(Tarik_Ocjena==Bojan_Ocjena && Mirza_Ocjena!=Bojan_Ocjena && Tarik_Ocjena!=Mirza_Ocjena)||(Bojan_Ocjena==Mirza_Ocjena && Bojan_Ocjena!=Tarik_Ocjena && Mirza_Ocjena!=Tarik_Ocjena))
	    printf("\nDva od tri studenta imaju istu ocjenu. ");
	    else
	    printf("\nSvaki student ima razlicitu ocjenu. ");
	}   
	else if((Tarik_Bodovi>=55.00 && Bojan_Bodovi>=55.00 && Mirza_Bodovi<55.00)||(Tarik_Bodovi<55.00 && Mirza_Bodovi>=55.00 && Bojan_Bodovi>=55.00) ||(Mirza_Bodovi>=55.00 && Tarik_Bodovi>=55.00 &&Bojan_Bodovi<55.00))
	printf("\nDva studenta su polozila.");
	else if((Tarik_Bodovi<55.00 && Mirza_Bodovi<55.00 && (Bojan_Bodovi>55.00||Bojan_Bodovi==55.00))||(Tarik_Bodovi<55.00 && (Mirza_Bodovi>55.00 ||Mirza_Bodovi==55.00) && Bojan_Bodovi<55.00)||((Tarik_Bodovi==55.00 || Tarik_Bodovi>55.00) && Mirza_Bodovi<55.00 && Bojan_Bodovi<55.00))
	printf("\nJedan student je polozio. ");
	else 
	printf("\nNijedan student nije polozio.");
	
	return 0;
}
