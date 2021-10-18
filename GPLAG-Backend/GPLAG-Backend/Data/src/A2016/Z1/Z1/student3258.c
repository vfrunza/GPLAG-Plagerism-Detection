#include <stdio.h>

int main() {
	double Tarik1;
	double Tarik2,Tarikdz,Tarikus,Tarikp,Tarik;
    double Bojan1,Bojan2,Bojandz,Bojanus,Bojanp,Bojan;
    double Mirza1,Mirza2,Mirzadz,Mirzaus,Mirzap,Mirza;
    int brojac;
    brojac=0;
    int ocjena;
	
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&Tarik1);
	if(Tarik1>20 || Tarik1<0){ printf("Neispravan broj bodova");
	return 0;}

	printf("II parcijalni ispit: ");
	scanf("%lf",&Tarik2);
	if(Tarik2>20 || Tarik2<0){ printf("Neispravan broj bodova");
	return 0;}
	
	printf("Prisustvo: ");
	scanf("%lf",&Tarikp);
	if(Tarikp>10 || Tarikp<0){
		 printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zadace: ");
	scanf("%lf",&Tarikdz);
	if(Tarikdz>10 || Tarikdz<0){
		 printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&Tarikus);
	if(Tarikus<0 || Tarikus>40){
		 printf("Neispravan broj bodova");
	return 0;}
	Tarik=Tarik1+Tarik2+Tarikus+Tarikdz+Tarikp;

	/*Bojannn*/
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&Bojan1);
	if(Bojan1>20 || Bojan1<0){ printf("Neispravan broj bodova");
	return 0;}

	printf("II parcijalni ispit: ");
	scanf("%lf",&Bojan2);
	if(Bojan2>20 || Bojan2<0){ printf("Neispravan broj bodova");
	return 0;}
	
	printf("Prisustvo: ");
	scanf("%lf",&Bojanp);
	if(Bojanp>10 || Bojanp<0){
		 printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zadace: ");
	scanf("%lf",&Bojandz);
	if(Bojandz>10 || Bojandz<0){
		 printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&Bojanus);
	if(Bojanus<0 || Bojanus>40){
		 printf("Neispravan broj bodova");
	return 0;}
	Bojan=Bojan1+Bojan2+Bojanus+Bojandz+Bojanp;
	
	/*Mirza*/
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Mirza1);
	if(Mirza1>20 || Mirza1<0){ printf("Neispravan broj bodova");
	return 0;}

	printf("II parcijalni ispit: ");
	scanf("%lf",&Mirza2);
	if(Mirza2>20 || Mirza2<0){ printf("Neispravan broj bodova");
	return 0;}
	
	printf("Prisustvo: ");
	scanf("%lf",&Mirzap);
	if(Mirzap>10 || Mirzap<0){
		 printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zadace: ");
	scanf("%lf",&Mirzadz);
	if(Mirzadz>10 || Mirzadz<0){
		 printf("Neispravan broj bodova");
	return 0;}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&Mirzaus);
	if(Mirzaus<0 || Mirzaus>40){
		 printf("Neispravan broj bodova");
	return 0;}
	Mirza=Mirzaus+Mirzadz+Mirzap+Mirza2+Mirza1;
	
	if(Mirza<55) Mirza=5;
	else if(Mirza>=55 && Mirza<65) Mirza=6;
	else if(Mirza>=65 && Mirza<75) Mirza=7;
	else if(Mirza>=75 && Mirza<85) Mirza=8;
	else if(Mirza>=85 && Mirza<92) Mirza=9;
	else{ Mirza=10;}
	
	if(Tarik<55) Tarik=5;
	else if(Tarik>=55 && Tarik<65) Tarik=6;
	else if(Tarik>=65 && Tarik<75) Tarik=7;
	else if(Tarik>=75 && Tarik<85) Tarik=8;
	else if(Tarik>=85 && Tarik<92) Tarik=9;
	else{ Tarik=10;}
	
	if(Bojan<55) Bojan=5;
	else if(Bojan>=55 && Bojan<65) Bojan=6;
	else if(Bojan>=65 && Bojan<75) Bojan=7;
	else if(Bojan>=75 && Bojan<85) Bojan=8;
	else if(Bojan>=85 && Bojan<92) Bojan=9;
	else{ Bojan=10;}
	
	if(Mirza>5) brojac++;
	if(Bojan>5) brojac++;
	if(Tarik>5) brojac++;
	
	if(brojac==0)printf("Nijedan student nije polozio.");
	else if(brojac==1) printf("Jedan student je polozio.");
	else if(brojac==2) printf("Dva studenta su polozila.");
	else{
		printf("Sva tri studenta su polozila.");
		ocjena=Mirza;
		if(ocjena==Bojan && ocjena==Tarik){ printf("\nSva tri studenta imaju istu ocjenu.");}
		else if(ocjena==Bojan || ocjena==Tarik || Tarik==Bojan) {printf("\nDva od tri studenta imaju istu ocjenu.");}
		else{ printf("\nSvaki student ima razlicitu ocjenu.");}
	}
	
	
	return 0;
}
