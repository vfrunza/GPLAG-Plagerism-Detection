#include<stdio.h>
int main ()
{
	double Tppi,Tdpi,Tpris,Tzad,Tzp,Bppi,Bdpi,Bpris,Bzad,Bzp,Mppi,Mdpi,Mpris,Mzad,Mzp,Tarik,Bojan,Mirza;
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit:");
	scanf("%lf",&Tppi);
	if(Tppi<0 || Tppi>20 ){
		printf(" Neispravan broj bodova");}
		else {
	printf(" II parcijalni ispit:");
	scanf("%lf",&Tdpi);
	if(Tdpi<0 || Tdpi>20){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Prisustvo:");
	scanf("%lf",&Tpris);
	if(Tpris<0 || Tpris>10){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Zadace:");
	scanf("%lf",&Tzad);
	if(Tzad<0 || Tzad>10){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Zavrsni ispit:");
	scanf("%lf",&Tzp);
	if(Tzp<0 || Tzp>40){
		printf(" Neispravan broj bodova");}
	
		else {
	
		printf(" Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit:");
	scanf("%lf",&Bppi);
	if(Bppi<0 || Bppi>20 ){
		printf(" Neispravan broj bodova");}
		else {
	printf(" II parcijalni ispit:");
	scanf("%lf",&Bdpi);
	if(Bdpi<0 || Bdpi>20){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Prisustvo:");
	scanf("%lf",&Bpris);
	if(Bpris<0 || Bpris>10){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Zadace:");
	scanf("%lf",&Bzad);
	if(Bzad<0 || Bzad>10){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Zavrsni ispit:");
	scanf("%lf",&Bzp);
	if(Bzp<0 || Bzp>40){
		printf(" Neispravan broj bodova");}
		
		else{
		
		printf(" Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit:");
	scanf("%lf",&Mppi);
	if(Mppi<0 || Mppi>20 ){
		printf(" Neispravan broj bodova");}
		else {
	printf(" II parcijalni ispit:");
	scanf("%lf",&Mdpi);
	if(Mdpi<0 || Mdpi>20){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Prisustvo:");
	scanf("%lf",&Mpris);
	if(Mpris<0 || Mpris>10){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Zadace:");
	scanf("%lf",&Mzad);
	if(Mzad<0 || Mzad>10){
		printf(" Neispravan broj bodova");}
		else{
	printf(" Zavrsni ispit:");
	scanf("%lf",&Mzp);
	if(Mzp<0 || Mzp>40){
		printf(" Neispravan broj bodova");}
		else {
	
    Tarik=Tppi+Tdpi+Tpris+Tzad+Tzp;
	Bojan=Bppi+Bdpi+Bpris+Bzad+Bzp;
	Mirza=Mppi+Mdpi+Mpris+Mzad+Mzp;
	if(Tarik<55 && Bojan<55 && Mirza<55){
			printf(" Nijedan student nije polozio.");}
			else if (Tarik>=55 && Bojan<55 && Mirza<55 || Tarik<55 && Bojan>=55 && Mirza<55 || Tarik<55 && Bojan<55 && Mirza>=55){
			printf(" Jedan student je polozio.");}
			else if (Tarik>=55 && Bojan>=55 && Mirza<55 || Tarik>=55 && Bojan<55 && Mirza>=55 || Tarik<55 && Bojan>=55 && Mirza>=55){
			printf(" Dva studenta su polozila.");}
			else if (Tarik>=55 && Bojan>=55 && Mirza>=55){
			printf(" Sva tri studenta su polozila.");}
			if (Tarik>=55 && Bojan>=55 && Mirza>=55){
				
				if (Tarik>=55 && Tarik<65 && Bojan>=55 && Bojan<65 && Mirza>=55 && Mirza<65 || Tarik>=65 && Tarik<75 && Bojan>=65 && Bojan<75 && Mirza>=65 && Mirza<75 || Tarik>=75 && Tarik<85 && Bojan>=75 && Bojan<85 && Mirza>=75 && Mirza<85 || Tarik>=85 && Tarik<92 && Bojan>=85 && Bojan<92 && Mirza>=85 && Mirza<92 || Tarik>=92 && Tarik<=100 && Bojan>=92 && Bojan<=100 && Mirza>=92 && Mirza<=100){
					printf(" \nSva tri studenta imaju istu ocjenu.");}
					else if (Tarik>=55 && Tarik<65 && Bojan>=55 && Bojan<65 || Tarik>=65 && Tarik<75 && Bojan>=65 && Bojan<75  || Tarik>=75 && Tarik<85 && Bojan>=75 && Bojan<85 || Tarik>=85 && Tarik<92 && Bojan>=85 && Bojan<92  || Tarik>=92 && Tarik<=100 && Bojan>=92 && Bojan<=100 ||   Bojan>=55 && Bojan<65 && Mirza>=55 && Mirza<65 || Bojan>=65 && Bojan<75 && Mirza>=65 && Mirza<75 || Bojan>=75 && Bojan<85 && Mirza>=75 && Mirza<85 || Bojan>=85 && Bojan<92 && Mirza>=85 && Mirza<92 || Bojan>=92 && Bojan<=100 && Mirza>=92 && Mirza<=100 ||   Tarik>=55 && Tarik<65 && Mirza>=55 && Mirza<65 || Tarik>=65 && Tarik<75 &&  Mirza>=65 && Mirza<75 || Tarik>=75 && Tarik<85 && Mirza>=75 && Mirza<85 || Tarik>=85 && Tarik<92 &&  Mirza>=85 && Mirza<92 || Tarik>=92 && Tarik<=100 && Mirza>=92 && Mirza<=100){
						printf("\nDva od tri studenta imaju istu ocjenu.");}
						else {
							printf("\nSvaki student ima razlicitu ocjenu.");}
			}
						
		}}}}}}}}}}}}}}}
							return 0 ;}
								
					