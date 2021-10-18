#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
	double p1T, p2T, zT, pT, ziT, p1B, p2B, zB, pB, ziB, p1M, p2M, zM, pM, ziM, ocjenaT, ocjenaB, ocjenaM;
	int ukupnibrojac=0, ocjena6=0, ocjena7=0, ocjena8=0, ocjena9=0, ocjena10=0, T=0, M=0, B=0;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &p1T);
	if(p1T<0||p1T>20){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2T);
	if(p2T<0||p2T>20){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Prisustvo: ");
	scanf("%lf", &pT);
	if(pT<0||pT>10){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Zadace: ");
	scanf("%lf", &zT); 
	if(zT<0||zT>10){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Zavrsni ispit: ");
	scanf("%lf", &ziT);
	if(ziT<0||ziT>40){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &p1B);
	if(p1B<0||p1B>20){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2B);
	if(p2B<0||p2B>20){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Prisustvo: ");
	scanf("%lf", &pB);
	if(pB<0||pB>10){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Zadace: ");
	scanf("%lf", &zB);
	if(zB<0||zB>10){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Zavrsni ispit: ");
	scanf("%lf", &ziB);
	if(ziB<0||ziB>40){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &p1M);
	if(p1M<0||p1M>20){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("II parcijalni ispit: ");
	scanf("%lf", &p2M);
	if(p2M<0||p2M>20){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Prisustvo: ");
	scanf("%lf", &pM);
	if(pM<0||pM>10){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Zadace: ");
	scanf("%lf", &zM);
	if(zM<0||zM>10){printf("Neispravan broj bodova"); return 0;}
	else{
	printf("Zavrsni ispit: ");
	scanf("%lf", &ziM);
	if(ziM<0||ziM>40){printf("Neispravan broj bodova"); return 0;}
	else{
	ocjenaT=p1T+p2T+zT+pT+ziT;
	ocjenaB=p2B+p1B+zB+pB+ziB;
	ocjenaM=p1M+p2M+zM+pM+ziM;
	if(ocjenaT>=55) T++;
	if(ocjenaB>=55) B++;
	if(ocjenaM>=55) M++;
	ukupnibrojac=T+B+M;
	if(ukupnibrojac==0) printf("Nijedan student nije polozio.");
	if(ukupnibrojac==1) printf("Jedan student je polozio.");
	if(ukupnibrojac==2) printf("Dva studenta su polozila.");
	if(ukupnibrojac==3) {printf("Sva tri studenta su polozila.\n");
	if((ocjenaT+e)>=55&&(ocjenaT+e)<65) ocjena6++;
	if((ocjenaM+e)>=55&&(ocjenaM+e)<65) ocjena6++;
	if((ocjenaB+e)>=55&&(ocjenaB+e)<65) ocjena6++;
	 if((ocjenaT+e)>=65&&(ocjenaT+e)<75) ocjena7++;
	 if((ocjenaM+e)>=65&&(ocjenaM+e)<75) ocjena7++;
	 if((ocjenaB+e)>=65&&(ocjenaB+e)<75) ocjena7++;
	 if((ocjenaT+e)>=75&&(ocjenaT+e)<85) ocjena8++;
	 if((ocjenaM+e)>=75&&(ocjenaM+e)<85) ocjena8++;
	 if((ocjenaB+e)>=75&&(ocjenaB+e)<85) ocjena8++;
	 if((ocjenaT+e)>=85&&(ocjenaT+e)<92) ocjena9++;
	 if((ocjenaM+e)>=85&&(ocjenaM+e)<92) ocjena9++;
	 if((ocjenaB+e)>=85&&(ocjenaB+e)<92) ocjena9++;
	 if((ocjenaT+e)>=92&&(ocjenaM+e)>=92) ocjena10++;
	 if((ocjenaM+e)>=92&&(ocjenaB+e)>=92) ocjena10++;
	 if((ocjenaB+e)>=92&&(ocjenaT+e)>=92) ocjena10++;
	if(ocjena6==3 || ocjena7==3 || ocjena8==3 || ocjena9==3 || ocjena10==3) printf("Sva tri studenta imaju istu ocjenu.");
	else if(ocjena6==2 || ocjena7==2 || ocjena8==2 || ocjena9==2 || ocjena10==2) printf("Dva od tri studenta imaju istu ocjenu.");
	else printf("Svaki student ima razlicitu ocjenu.");}}}}}}}}}}}}}}}}
	return 0; }
