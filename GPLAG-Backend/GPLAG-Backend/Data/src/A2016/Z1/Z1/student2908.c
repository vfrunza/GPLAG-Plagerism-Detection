#include <stdio.h>
#include <math.h>
#define eps 0.00001
int main() {
	float  pparTar,dparTar,PriTar,ZadTar,UsmTar,pparBoj,dparBoj,PriBoj,ZadBoj,UsmBoj,pparMir,dparMir,PriMir,ZadMir,UsmMir,zbirT,zbirM,zbirB;
	int ocjenaT,ocjenaB,ocjenaM;
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit:");
	scanf("%f",&pparTar);
     if(pparTar<0 || pparTar>20){printf(" Neispravan broj bodova"); return 0;} 
	printf(" II parcijalni ispit:");
	scanf("%f",&dparTar);
	if(dparTar<0 || dparTar>20){printf(" Neispravan broj bodova");return 0;}
	printf(" Prisustvo:");
	scanf("%f",&PriTar);
	if(PriTar<0 || PriTar>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zadace:");
	scanf("%f",&ZadTar);
	if(ZadTar<0 || ZadTar>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zavrsni ispit:");
	scanf("%f",&UsmTar);
	if(UsmTar<0 || UsmTar>40) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit:");
	scanf("%f",&pparBoj);
	if(pparBoj<0 || pparBoj>20) { printf(" Neispravan broj bodova"); return 0;}
	printf(" II parcijalni ispit:");
	scanf("%f",&dparBoj);
	if(dparBoj<0 || dparBoj>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Prisustvo:");
	scanf("%f",&PriBoj);
	if(PriBoj<0 || PriBoj>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zadace:");
	scanf("%f",&ZadBoj);
	if(ZadBoj<0 || ZadBoj>10) {printf(" Neispravan broj bodova");return 0;}
	printf(" Zavrsni ispit:");
	scanf("%f",&UsmBoj);
	if(UsmBoj<0 || UsmBoj>40) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit:");
	scanf("%f",&pparMir);
	if(pparMir<0 || pparMir>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" II parcijalni ispit:");
	scanf("%f",&dparMir);
	if(dparMir<0 || dparMir>20) { printf(" Neispravan broj bodova"); return 0;}
	printf(" Prisustvo:");
	scanf("%f",&PriMir);
	if(PriMir<0 || PriMir>10){ printf(" Neispravan broj bodova"); return 0;}
	printf(" Zadace:");
	scanf("%f",&ZadMir);
	if(ZadMir<0 || ZadMir>10) { printf(" Neispravan broj bodova"); return 0;}
	printf(" Zavrsni ispit:");
	scanf("%f",&UsmMir);
	if(UsmMir<0 || UsmMir>40) { printf(" Neispravan broj bodova"); return 0;}
	zbirT=pparTar+dparTar+PriTar+ZadTar+UsmTar;
	zbirB=pparBoj+dparBoj+PriBoj+ZadBoj+UsmBoj;
	zbirM=pparMir+dparMir+PriMir+ZadMir+UsmMir;
	if(55-zbirT>eps && 55-zbirB>eps && 55-zbirM>eps) {printf(" Nijedan student nije polozio."); return 0;}
	if((55-zbirT<eps && zbirM<55 && zbirB<55) || (zbirT<55 && 55-zbirB<eps && zbirM<55) || (55-zbirM<eps && zbirB<55&& zbirT<55))  { printf(" Jedan student je polozio."); return 0;}
	if((55-zbirT<eps && zbirM>=55 && zbirB<55) || (zbirT>=55 && zbirB>=55 && zbirM<55) || (zbirM>=55 && zbirB>=55&& zbirT<55)) {printf(" Dva studenta su polozila."); return 0;}
	if(zbirB>=55 && zbirM>=55 && zbirT>=55) {printf(" Sva tri studenta su polozila.");}
		if(55-zbirT<eps && zbirT<65) {ocjenaT=6;}
		if(65-zbirT<eps && zbirT<75) {ocjenaT=7;}
		if(75-zbirT<eps && zbirT<85) {ocjenaT=8;}
		if(85-zbirT<eps && zbirT<92) {ocjenaT=9;}
		if(92-zbirT<eps && 100-zbirT<eps) {ocjenaT=10;}
		
		if(55-zbirM<eps && zbirM<65) {ocjenaM=6;}
		if(65-zbirM<eps && zbirM<75) {ocjenaM=7;}
		if(75-zbirM<eps && zbirM<85) {ocjenaM=8;}
		if(85-zbirM<eps && zbirM<92) {ocjenaM=9;}
		if(92-zbirM<eps && 100-zbirM<eps) {ocjenaM=10;}
		
		if(55-zbirB<eps && zbirB<65) {ocjenaB=6;} 
		if(65-zbirB<eps && zbirB<75) {ocjenaB=7;}
		if(75-zbirB<eps && zbirB<85) {ocjenaB=8;}
		if(85-zbirB<eps && zbirB<92) {ocjenaB=9;}
		if(92-zbirB<eps && 100-zbirB<eps) {ocjenaB=10;}
		if(ocjenaT!=ocjenaM && ocjenaT!=ocjenaB && ocjenaM!=ocjenaB) {
			printf("\nSvaki student ima razlicitu ocjenu.");}
		if(ocjenaB==ocjenaM && ocjenaB==ocjenaT && ocjenaM==ocjenaT) {
			printf("\nSva tri studenta imaju istu ocjenu.");}
		else if((ocjenaM==ocjenaT && ocjenaM!=ocjenaB) || (ocjenaM==ocjenaB && ocjenaM!=ocjenaT) || (ocjenaB==ocjenaT && ocjenaB!=ocjenaM)) {
			printf("\nDva od tri studenta imaju istu ocjenu.");}
		return 0;
}