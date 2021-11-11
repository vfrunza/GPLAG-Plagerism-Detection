#include <stdio.h>


int main (){
	
	float prvi_parcijalni, drugi_parcijalni, zadaca, zavrsni, prisustvo, ocjena, broj_bodova_Tarik, broj_bodova_Bojan, broj_bodova_Mirza;
	
	printf ("Unesite bodove za Tarika:\nI parcijalni: ");
	scanf ("%f", &prvi_parcijalni);
	printf ("II parcijalni: ");
	scanf ("%f", &drugi_parcijalni);
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	printf ("Zadaca: ");
	scanf ("%f", &zadaca);
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	
	broj_bodova_Tarik=prvi_parcijalni+drugi_parcijalni+zadaca+prisustvo+zavrsni;
	/*printf ("%.f\n", broj_bodova_Tarik);*/
	
	printf ("Unesite bodove za Bojana:\nI parcijalni: ");
	scanf ("%f", &prvi_parcijalni);
	printf ("II parcijalni: ");
	scanf ("%f", &drugi_parcijalni);
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	printf ("Zadaca: ");
	scanf ("%f", &zadaca);
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	
	broj_bodova_Bojan=prvi_parcijalni+drugi_parcijalni+zadaca+prisustvo+zavrsni;
	/*printf ("%.f\n", broj_bodova_Bojan);*/
	
	printf ("Unesite bodove za Mirzu:\nI parcijalni: ");
	scanf ("%f", &prvi_parcijalni);
	printf ("II parcijalni: ");
	scanf ("%f", &drugi_parcijalni);
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	printf ("Zadaca: ");
	scanf ("%f", &zadaca);
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	
	broj_bodova_Mirza=prvi_parcijalni+drugi_parcijalni+zadaca+prisustvo+zavrsni;
	/*printf ("%.f\n", broj_bodova_Mirza);*/
	
	if (prvi_parcijalni<0 || prvi_parcijalni>20 || drugi_parcijalni<0 || drugi_parcijalni>20 || prisustvo<0 || prisustvo>10 || zadaca<0 || zadaca>10 || zavrsni<0 || zavrsni>40){
		printf ("Neispravan broj bodova!\n");
	}
	else if (broj_bodova_Tarik<55 && broj_bodova_Bojan<55 && broj_bodova_Mirza<55){
		printf ("Nijedan student nije polozi.\n");
	}
	else if (broj_bodova_Tarik<55 && broj_bodova_Mirza>=55 && broj_bodova_Bojan>=55){
		printf ("Dva studenta su polozila.\n");
	}
	else if (broj_bodova_Mirza<55 && broj_bodova_Tarik>=55 && broj_bodova_Bojan>=55){
		printf ("Dva studenta su polozila.\n");
	}
	else if (broj_bodova_Bojan<55 && broj_bodova_Mirza>=55 && broj_bodova_Tarik>=55){
		printf ("Dva studenta su polozila.\n");
	}
	else if (broj_bodova_Tarik>=55 && broj_bodova_Mirza>=55 && broj_bodova_Bojan>=55){
		printf ("Sva tri studenta su polozila.\n");
	}

	
	return 0;
}