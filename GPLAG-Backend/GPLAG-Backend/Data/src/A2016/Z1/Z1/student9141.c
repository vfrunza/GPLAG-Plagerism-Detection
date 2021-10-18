#include <stdio.h>

int main() {
	double Tarik_prvi, Tarik_drugi, Tarik_prisustvo, Tarik_zadaca, Tarik_zavrsni;
	double Bojan_prvi, Bojan_drugi, Bojan_prisustvo, Bojan_zadaca, Bojan_zavrsni;
	double Mirza_prvi, Mirza_drugi, Mirza_prisustvo, Mirza_zadaca, Mirza_zavrsni;
	double ukupno_tarik=0, ukupno_bojan=0, ukupno_mirza=0;
	int ocjena_tarik=0, ocjena_bojan=0, ocjena_mirza=0;
	
	printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
	scanf("%lf", &Tarik_prvi);
	if(Tarik_prvi<0 || Tarik_prvi>20){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &Tarik_drugi);
	if(Tarik_drugi<0 || Tarik_drugi>20){
	    printf("Neispravan broj bodova");
	    return 0;
	}    
	printf("Prisustvo: ");
	scanf("%lf", &Tarik_prisustvo);
	if(Tarik_prisustvo<0 || Tarik_prisustvo>10){
	    printf("Neispravan broj bodova");
	    return 0;
	}    
	printf("Zadace: ");
	scanf("%lf", &Tarik_zadaca);
	if(Tarik_zadaca<0 || Tarik_zadaca>10){
	    printf("Neispravan broj bodova");
	    return 0;
	}    
	printf("Zavrsni ispit: ");
	scanf("%lf", &Tarik_zavrsni);
	if(Tarik_zavrsni<0 || Tarik_zavrsni>40){
	    printf("Neispravan broj bodova");
	    return 0;
	}    
	ukupno_tarik=Tarik_prvi+Tarik_drugi+Tarik_prisustvo+Tarik_zadaca+Tarik_zavrsni;
	printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
	scanf("%lf", &Bojan_prvi);
	if(Bojan_prvi<0 || Bojan_prvi>20){
	    printf("Neispravan broj bodova");
	    return 0;
	}    
	printf("II parcijalni ispit: ");
	scanf("%lf", &Bojan_drugi);
	if(Bojan_drugi<0 || Bojan_drugi>20){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Bojan_prisustvo);
	if(Bojan_prisustvo<0 || Bojan_prisustvo>10){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Bojan_zadaca);
	if(Bojan_zadaca<0 || Bojan_zadaca>10){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Bojan_zavrsni);
	if(Bojan_zavrsni<0 || Bojan_zavrsni>40){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	ukupno_bojan=Bojan_prvi+Bojan_drugi+Bojan_prisustvo+Bojan_zadaca+Bojan_zavrsni;
	printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
	scanf("%lf", &Mirza_prvi);
	if(Mirza_prvi<0 || Mirza_prvi>20){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &Mirza_drugi);
	if(Mirza_drugi<0 || Mirza_drugi>20){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Mirza_prisustvo);
	if(Mirza_prisustvo<0 || Mirza_prisustvo>10){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Mirza_zadaca);
	if(Mirza_zadaca<0 || Mirza_zadaca>10){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Mirza_zavrsni);
	if(Mirza_zavrsni<0 || Mirza_zavrsni>40){
	    printf("Neispravan broj bodova");
	    return 0;
	}
	ukupno_mirza=Mirza_prvi+Mirza_drugi+Mirza_prisustvo+Mirza_zadaca+Mirza_zavrsni;
	
	if(ukupno_tarik<55)
	    ocjena_tarik=5;
	else if(ukupno_tarik>=55 && ukupno_tarik<65)
	    ocjena_tarik=6;
	else if(ukupno_tarik>=65 && ukupno_tarik<75)
	    ocjena_tarik=7;
	else if(ukupno_tarik>=75 && ukupno_tarik<85)
	    ocjena_tarik=8;
	else if(ukupno_tarik>=85 && ukupno_tarik<92)
	    ocjena_tarik=9;
	else if(ukupno_tarik>=92 && ukupno_tarik<=100)
	    ocjena_tarik=10;
	
	if(ukupno_bojan<55)
	    ocjena_bojan=5;
	else if(ukupno_bojan>=55 && ukupno_bojan<65)
	    ocjena_bojan=6;
	else if(ukupno_bojan>=65 && ukupno_bojan<75)
	    ocjena_bojan=7;
	else if(ukupno_bojan>=75 && ukupno_bojan<85)
	    ocjena_bojan=8;
	else if(ukupno_bojan>=85 && ukupno_bojan<92)
	    ocjena_bojan=9;
	else if(ukupno_bojan>=92 && ukupno_bojan<=100)
	    ocjena_bojan=10;
	    
	if(ukupno_mirza<55)
	    ocjena_mirza=5;
	else if(ukupno_mirza>=55 && ukupno_mirza<65)
	    ocjena_mirza=6;
	else if(ukupno_mirza>=65 && ukupno_mirza<75)
	    ocjena_mirza=7;
	else if(ukupno_mirza>=75 && ukupno_mirza<85)
	    ocjena_mirza=8;
	else if(ukupno_mirza>=85 && ukupno_mirza<92)
	    ocjena_mirza=9;
	else if(ukupno_mirza>=92 && ukupno_mirza<=100)
	    ocjena_mirza=10;
	
	if(ocjena_tarik==5 && ocjena_bojan==5 && ocjena_mirza==5)
	    printf("Nijedan student nije polozio.");    
	if((ocjena_tarik>5 && ocjena_bojan==5 && ocjena_mirza==5) || (ocjena_tarik==5 && ocjena_bojan>5 && ocjena_mirza==5) || (ocjena_tarik==5 && ocjena_bojan==5 && ocjena_mirza>5))
	    printf("Jedan student je polozio.");
	if((ocjena_tarik>5 && ocjena_bojan>5 && ocjena_mirza==5) || (ocjena_tarik>5 && ocjena_bojan==5 && ocjena_mirza>5) || (ocjena_tarik==5 && ocjena_bojan>5 && ocjena_mirza>5))
	    printf("Dva studenta su polozila.");
	if((ocjena_tarik>5 && ocjena_bojan>5 && ocjena_mirza>5)){
	    printf("Sva tri studenta su polozila.");
	    if(ocjena_mirza==ocjena_bojan && ocjena_mirza==ocjena_tarik)
	        printf("\nSva tri studenta imaju istu ocjenu.");
	    else if((ocjena_tarik==ocjena_bojan && ocjena_tarik!=ocjena_mirza) || (ocjena_tarik==ocjena_mirza && ocjena_tarik!=ocjena_bojan) || (ocjena_mirza==ocjena_bojan && ocjena_mirza!=ocjena_tarik))
	        printf("\nDva od tri studenta imaju istu ocjenu.");
	    else if(ocjena_tarik!=ocjena_bojan && ocjena_tarik!=ocjena_mirza && ocjena_bojan!=ocjena_mirza)
	        printf("\nSvaki student ima razlicitu ocjenu.");
	}
	return 0;
}
