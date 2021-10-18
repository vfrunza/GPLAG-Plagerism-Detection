#include <stdio.h>

int main() {
	double par1t,par2t,zadt,zavrt,par1b,par2b,zadb,zavrb,par1m,par2m,zadm,zavrm,pt,pb,pm,bodt,bodb,bodm;
	int ocjenat=0,ocjenab=0,ocjenam=0;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &par1t);
	if(par1t>=0 && par1t<=20) {

		printf("II parcijalni ispit: ");
	}
	else if(par1t<0 || par1t>20) {
		printf("Neispravan broj bodova");
		return 0;
	}

	scanf("%lf", &par2t);
    if (par2t>=0 && par2t<=20) {
	printf("Prisustvo: ");
	}
	else if(par2t<0 || par2t>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf",&pt);
	if (pt>=0 && pt<=10) {
	printf("Zadace: ");
	}
	else if(pt<0 || pt>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &zadt);
	if(zadt>=0 && zadt<=10 ) {
    printf("Zavrsni ispit: ");
	}
	else if(zadt<0 || zadt>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &zavrt);
	if(zavrt>=0 && zavrt<=40) {
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	}
	else if(zavrt<0 || zavrt>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &par1b);
	if(par1b>=0 && par1b<=20) {
	printf("II parcijalni ispit: ");
	}
	else if(par1b<0 || par1b>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &par2b);
	if(par2b>=0 && par2b<=20) {
	printf("Prisustvo: ");
	}
	else if(par2b<0 || par2b>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &pb);
	if(pb>=0 && pb<=20) {
	printf("Zadace: ");
	}
	else if(pb<0 || pb>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &zadb);
	if(zadb>=0 && zadb<=20)
	{
	printf("Zavrsni ispit: ");
	}
	else if(zadb<0 || zadb>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &zavrb);
	if(zavrb>=0 && zavrb<=40) {
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	}
	else if(zavrb<0 || zavrb>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &par1m);
	if(par1m>=0 && par1m<=20) {
	printf("II parcijalni ispit: ");
	}
	else if(par1m<0 || par1m>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &par2m);
	if(par2m>=0 && par2m<=20) {
	printf("Prisustvo: ");
	}
	else if(par2m<0 || par2m>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &pm);
	if(pm>=0 && pm<=10) {

	printf("Zadace: ");
	}
	else if(pm<0 || pm>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &zadm);
	if(zadm>=0 && zadm<=10) {
	printf("Zavrsni ispit: ");
	}
	else if(zadm<0 || zadm>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	scanf("%lf", &zavrm);
	if(zavrm<0 || zavrm>40) {
	printf("Neispravan broj bodova");
	return 0;
	}

		bodt=par1t+par2t+zadt+pt+zavrt;
		bodb=par1b+par2b+zadb+pb+zavrb;
		bodm=par1m+par2m+zadm+pm+zavrm;
	 if(bodt<55)
	 {
	 	ocjenat=5;
	 }
	 else if(bodt>=55 && bodt<65)
	 {
	 	ocjenat=6;
	 }
	 else if(bodt>=65 && bodt<75)
	 {
	 	ocjenat=7;
	 }
	 else if(bodt>=75 && bodt<85)
	 {
	 	ocjenat=8;
	 }
	 else if(bodt>=85 && bodt<95)
	 {
	 	ocjenat=9;
	 }
	 else {
	 	ocjenat=10;
	 }
	 if(bodb<55)
	 {
	 	ocjenab=5;
	 }
	 else if(bodb>=55 && bodb<65)
	 {
	 	ocjenab=6;
	 }
	 else if(bodb>=65 && bodb<75)
	 {
	 	ocjenab=7;
	 }
	 else if(bodb>=75 && bodb<85)
	 {
	 	ocjenab=8;
	 }
	 else if(bodb>=85 && bodb<95)
	 {
	 	ocjenab=9;
	 }
	 else {
	 	ocjenab=10;
	 }
	 if(bodm<55)
	 {
	 	ocjenam=5;
	 }
	 else if(bodm>=55 && bodm<65)
	 {
	 	ocjenam=6;
	 }
	 else if(bodm>=65 && bodm<75)
	 {
	 	ocjenam=7;
	 }
	 else if(bodm>=75 && bodm<85)
	 {
	 	ocjenam=8;
	 }
	 else if(bodm>=85 && bodm<95)
	 {
	 	ocjenam=9;
	 }
	 else {
	 	ocjenam=10;
	 }
     if((ocjenat==5) && (ocjenab==5) && (ocjenam==5))
	 {
	 	printf("Nijedan student nije polozio.\n");

	 }
	 if(((ocjenat>5) && (ocjenab==5) && (ocjenam==5)) || (ocjenat==5 && ocjenab>5 && ocjenam==5) || (ocjenat==5 && ocjenab==5 && ocjenam>5)) {
	 	printf("Jedan student je polozio.\n"); 
	 }
	 if(((ocjenat>5) && (ocjenab>5)  && (ocjenam==5)) || ((ocjenat>5) && (ocjenab==5) && (ocjenam>5)) || ((ocjenat==5) && (ocjenab>5) && (ocjenam>5))) {
	 	printf("Dva studenta su polozila.\n"); 
	 }
	 if ((ocjenat>5) && (ocjenab>5) && (ocjenam>5)) {
	 	printf("Sva tri studenta su polozila.\n");
	 	if(ocjenat==ocjenab && ocjenat==ocjenam)
	 	{
	 		printf("Sva tri studenta imaju istu ocjenu.");
	 	}
	 	else if(ocjenat==ocjenab || ocjenab==ocjenam || ocjenam==ocjenat)
	 	{
	 		printf("Dva od tri studenta imaju istu ocjenu.");
	 	}
	 	else if(ocjenat!=ocjenab && ocjenab!=ocjenam && ocjenam!=ocjenat)
	 	{
	 		printf("Svaki student ima razlicitu ocjenu.");
	 	}
	 } 
	return 0;
}
