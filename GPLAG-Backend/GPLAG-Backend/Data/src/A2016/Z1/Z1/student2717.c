#include <stdio.h>
#include <math.h>
#define e 0.01
int main() {
	float Itarik, Ibojan, Imirza, IItarik, IIbojan, IImirza, prisustvotarik, prisustvobojan, prisustvomirza, 
	zadacetarik, zadacebojan, zadacemirza, zavrsnitarik, zavrsnibojan, zavrsnimirza, ukupnotarik, ukupnobojan, ukupnomirza,
	ocjenatarik,ocjenabojan,ocjenamirza; 
	
	/*Unos podataka*/
	
	/*Tarik*/
	
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit:");
	scanf ("%f", &Itarik);
	if (Itarik>=0 && Itarik<=20) {
	printf(" II parcijalni ispit:"); }
	else {printf(" Neispravan broj bodova");
	return 0; }
	scanf ("%f", &IItarik);
	if (IItarik>=0 && IItarik<=20) {
	printf(" Prisustvo:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &prisustvotarik);
	if (prisustvotarik>=0 && prisustvotarik<=10) {
	printf(" Zadace:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &zadacetarik);
	if (zadacetarik>=0 && zadacetarik<=10) {
	printf(" Zavrsni ispit:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &zavrsnitarik);
	if (zavrsnitarik>=0 && zavrsnitarik<=40) {
	
	/*Bojan*/
	
	printf(" Unesite bodove za Bojana:"); 
	printf("\nI parcijalni ispit:"); }
	else {
	printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &Ibojan);
	if (Ibojan>=0 && Ibojan<=20) {
	printf(" II parcijalni ispit:"); }
	else {
	printf(" Neispravan broj bodova");
	return 0; }
	scanf ("%f", &IIbojan);
	if (IIbojan>=0 && IIbojan<=20) {
	printf(" Prisustvo:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &prisustvobojan);
	if (prisustvobojan>=0 && prisustvobojan<=10) {
	printf(" Zadace:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &zadacebojan);
	if (zadacebojan>=0 && zadacebojan<=10) {
	printf(" Zavrsni ispit:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &zavrsnibojan);
	if (zavrsnibojan>=0 && zavrsnibojan<=40) {
	
	/*Mirza*/
	
	printf(" Unesite bodove za Mirzu:"); 
	printf("\nI parcijalni ispit:"); }
	else {
	printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &Imirza);
	if (Imirza>=0 && Imirza<=20) {
	printf(" II parcijalni ispit:"); }
	else {
	printf(" Neispravan broj bodova");
	return 0; }
	scanf ("%f", &IImirza);
	if (IImirza>=0 && IImirza<=20) {
	printf(" Prisustvo:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &prisustvomirza);
	if (prisustvomirza>=0 && prisustvomirza<=10) {
	printf(" Zadace:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &zadacemirza);
	if (zadacemirza>=0 && zadacemirza<=10) {
	printf(" Zavrsni ispit:"); }
	else {printf(" Neispravan broj bodova");
	return 0;}
	scanf ("%f", &zavrsnimirza);
	if (zavrsnimirza<0 && zavrsnimirza>40) {
	printf(" Neispravan broj bodova");
	return 0;}
	
		/*racunanje*/
	
	ukupnotarik=(Itarik+IItarik+prisustvotarik+zadacetarik+zavrsnitarik);
	ukupnobojan=(Ibojan+IIbojan+prisustvobojan+zadacebojan+zavrsnibojan);
	ukupnomirza=(Imirza+IImirza+prisustvomirza+zadacemirza+zavrsnimirza);

	/* Ocjene za studente */

	if(ukupnotarik>=(55-e) && ukupnotarik<(65-e)) {ocjenatarik=6;}
	else if (ukupnotarik>=(65-e) && ukupnotarik<(75-e)) {ocjenatarik=7;}
	else if (ukupnotarik>=(75-e) && ukupnotarik<(85-e)) {ocjenatarik=8;}
	else if (ukupnotarik>=(85-e) && ukupnotarik<(92-e)) {ocjenatarik=9;}
	else if (ukupnotarik>=(92-e) && ukupnotarik<(100-e)) {ocjenatarik=10;}
	
	if(ukupnobojan>=(55-e) && ukupnobojan<(65-e)) {ocjenabojan=6;}
	else if (ukupnobojan>=(65-e) && ukupnobojan<(75-e)) {ocjenabojan=7;}
	else if (ukupnobojan>=(75-e) && ukupnobojan<(85-e)) {ocjenabojan=8;}
	else if (ukupnobojan>=(85-e) && ukupnobojan<(92-e)) {ocjenabojan=9;}
	else if (ukupnobojan>=(92-e) && ukupnobojan<(100-e)) {ocjenabojan=10;}
	
	if(ukupnomirza>=(55-e) && ukupnomirza<(65-e)) {ocjenamirza=6;}
	else if (ukupnomirza>=(65-e) && ukupnomirza<(75-e)) {ocjenamirza=7;}
	else if (ukupnomirza>=(75-e) && ukupnomirza<(85-e)) {ocjenamirza=8;}
	else if (ukupnomirza>=(85-e) && ukupnomirza<(92-e)) {ocjenamirza=9;}
	else if (ukupnomirza>=(92-e) && ukupnomirza<(100-e)) {ocjenamirza=10;}
	
	/*Uslov da nijedan nije polozio*/
	
	if ((ukupnotarik<55-e) && (ukupnobojan<55-e) && (ukupnomirza<55-e)) {
		printf(" Nijedan student nije polozio.");}
	
	/*Uslov da je bar jedan polozio*/
	
	else if (((ukupnotarik>=55-e)&&(ukupnobojan<55-e)&&(ukupnomirza<55-e))||((ukupnotarik<55-e)&&(ukupnobojan>=55-e)&&(ukupnomirza<55-e))||((ukupnotarik<55-e)&&(ukupnobojan<55-e)&&(ukupnomirza>=55-e))) {
	printf(" Jedan student je polozio.");}
	
		/*Uslov da su dva polozila*/
	
	else if (((ukupnotarik>=55-e)&&(ukupnomirza>=55-e)&&(ukupnobojan<55-e))||((ukupnotarik<55-e)&&(ukupnomirza>=55-e)&&(ukupnobojan>=55-e))||((ukupnotarik>=55-e)&&(ukupnomirza<55-e)&&(ukupnobojan>=55-e))) {
	printf(" Dva studenta su polozila.");}
	
	/*Sva tri polozila*/
	
	if ((ukupnotarik>=55-e) && (ukupnobojan>=55-e) && (ukupnomirza>=55-e)) {
	printf(" Sva tri studenta su polozila.");
	if ((fabs(ocjenatarik-ocjenamirza)<e)&&(fabs(ocjenatarik-ocjenabojan)<e)) 
	printf("\nSva tri studenta imaju istu ocjenu."); 
	else if ((ocjenabojan!=ocjenamirza)&&(ocjenatarik!=ocjenamirza)&&(ocjenabojan!=ocjenatarik))
	printf("\nSvaki student ima razlicitu ocjenu.");
	if ((fabs(ocjenatarik-ocjenamirza)<e)||(fabs(ocjenatarik-ocjenabojan)<e)||(fabs(ocjenamirza-ocjenabojan<e)))
	printf("\nDva od tri studenta imaju istu ocjenu."); }
	

	return 0;
}


































