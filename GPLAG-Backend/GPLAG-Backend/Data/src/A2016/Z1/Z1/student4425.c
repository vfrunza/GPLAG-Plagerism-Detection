#include <stdio.h>
#include <math.h>
#define REFValue 0.00001

int main() {
	
	float prvi, drugi, prisustvo, zadace, zavrsni, tarik, bojan, mirza;
	int ocjena_bojan=0, ocjena_tarik=0, ocjena_mirza=0;
	
	//Unos
	
	//tarik
	printf ("Unesite bodove za Tarika:\n");
	
	printf ("I parcijalni ispit: ");
	scanf ("%f", &prvi);
	if (prvi<0 || prvi>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("II parcijalni ispit: ");
	scanf ("%f", &drugi);
	if (drugi<0 || drugi>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	if (prisustvo<0 || prisustvo>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zadace: ");
	scanf ("%f", &zadace);
	if (zadace<0 || zadace>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	if (zavrsni<0 || zavrsni>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	tarik=prvi+drugi+prisustvo+zadace+zavrsni;
	
	//bojan
	printf ("Unesite bodove za Bojana:\n");
	
	printf ("I parcijalni ispit: ");
	scanf ("%f", &prvi);
	if (prvi<0 || prvi>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("II parcijalni ispit: ");
	scanf ("%f", &drugi);
	if (drugi<0 || drugi>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	if (prisustvo<0 || prisustvo>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zadace: ");
	scanf ("%f", &zadace);
	if (zadace<0 || zadace>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	if (zavrsni<0 || zavrsni>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	bojan=prvi+drugi+prisustvo+zadace+zavrsni;
	
	//mirza
	printf ("Unesite bodove za Mirzu:\n");
	
	printf ("I parcijalni ispit: ");
	scanf ("%f", &prvi);
	if (prvi<0 || prvi>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("II parcijalni ispit: ");
	scanf ("%f", &drugi);
	if (drugi<0 || drugi>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	if (prisustvo<0 || prisustvo>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zadace: ");
	scanf ("%f", &zadace);
	if (zadace<0 || zadace>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	if (zavrsni<0 || zavrsni>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	mirza=prvi+drugi+prisustvo+zadace+zavrsni;
	
	//Kraj unosa
	
	//skaliranje bodova i određivanje ocjene
	if (bojan<55+REFValue || bojan<55-REFValue) ocjena_bojan=5;
	if (bojan>55-REFValue && bojan<65-REFValue) ocjena_bojan=6;
	if (bojan>65-REFValue && bojan<75-REFValue) ocjena_bojan=7;
	if (bojan>75-REFValue && bojan<85-REFValue) ocjena_bojan=8;
	if (bojan>85-REFValue && bojan<92-REFValue) ocjena_bojan=9;
	if (bojan>92-REFValue && bojan<100+REFValue) ocjena_bojan=10;
	
	if (tarik<55+REFValue || tarik<55-REFValue) ocjena_tarik=5;
	if (tarik>55-REFValue && tarik<65-REFValue) ocjena_tarik=6;
	if (tarik>65-REFValue && tarik<75-REFValue) ocjena_tarik=7;
	if (tarik>75-REFValue && tarik<85-REFValue) ocjena_tarik=8;
	if (tarik>85-REFValue && tarik<92-REFValue) ocjena_tarik=9;
	if (tarik>92-REFValue && tarik<100+REFValue) ocjena_tarik=10;
	
	if (mirza<55+REFValue || mirza<55-REFValue) ocjena_mirza=5;
	if (mirza>55-REFValue && mirza<65-REFValue) ocjena_mirza=6;
	if (mirza>65-REFValue && mirza<75-REFValue) ocjena_mirza=7;
	if (mirza>75-REFValue && mirza<85-REFValue) ocjena_mirza=8;
	if (mirza>85-REFValue && mirza<92-REFValue) ocjena_mirza=9;
	if (mirza>92-REFValue && mirza<100+REFValue) ocjena_mirza=10;
	//kraj skaliranja bodova i određivanja ocjene
	
	//last task 
	if (ocjena_bojan==5 && ocjena_tarik==5 && ocjena_mirza==5) printf ("Nijedan student nije polozio.");
	else if ((ocjena_bojan>5 && ocjena_tarik==5 && ocjena_mirza==5) || (ocjena_bojan==5 && ocjena_tarik>5 && ocjena_mirza==5) || (ocjena_bojan==5 && ocjena_tarik==5 && ocjena_mirza>5)) printf ("Jedan student je polozio.");
	else if ((ocjena_bojan>5 && ocjena_tarik>5 && ocjena_mirza==5) || (ocjena_bojan>5 && ocjena_tarik==5 && ocjena_mirza>5) || (ocjena_bojan==5 && ocjena_tarik>5 && ocjena_mirza>5)) printf ("Dva studenta su polozila.");
	else if (ocjena_bojan>5 && ocjena_tarik>5 && ocjena_mirza>5) {
		printf ("Sva tri studenta su polozila.\n");
		if (ocjena_bojan==ocjena_tarik && ocjena_tarik==ocjena_mirza) printf("Sva tri studenta imaju istu ocjenu.");
		else if ((ocjena_bojan==ocjena_tarik && ocjena_tarik!=ocjena_mirza)||(ocjena_bojan==ocjena_mirza && ocjena_mirza!=ocjena_tarik)||(ocjena_tarik==ocjena_mirza && ocjena_mirza!=ocjena_bojan)) printf("Dva od tri studenta imaju istu ocjenu.");
		else printf("Svaki student ima razlicitu ocjenu.");
	} else printf ("Neka greska!!!"); 											//self-control
	//end of last task
	
	return 0;
}