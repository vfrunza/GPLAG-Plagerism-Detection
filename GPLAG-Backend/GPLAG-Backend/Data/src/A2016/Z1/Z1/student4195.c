#include <stdio.h>

int main() {
	double prvi_parcijalni,drugi_parcijalni,prisustvo,zadace,zavrsni_ispit,broj_bodova;
	int tarik_ocjena, bojan_ocjena, mirza_ocjena, broj_razlictih_ocjena = 3, uspjeli_studenti = 3;

	
	//Tarik
	//Unos bodova i provjera ispravnosti istih
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi_parcijalni);
	if(prvi_parcijalni<0 || prvi_parcijalni>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi_parcijalni);
	if(drugi_parcijalni<0 || drugi_parcijalni>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo);
	if(prisustvo<0 || prisustvo>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zadace);
	if(zadace<0 || zadace>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni_ispit);
	if(zavrsni_ispit<0 || zavrsni_ispit>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	broj_bodova = prvi_parcijalni + drugi_parcijalni + prisustvo + zadace + zavrsni_ispit;
	
	//Provjera ocjene
	if(broj_bodova<55)
		tarik_ocjena = 5;
	else if(broj_bodova>=55 && broj_bodova<65)
		tarik_ocjena = 6;
	else if(broj_bodova>=65 && broj_bodova<75)
		tarik_ocjena = 7;
	else if(broj_bodova>=75 && broj_bodova<85)
		tarik_ocjena = 8;
	else if(broj_bodova>=85 && broj_bodova<92)
		tarik_ocjena = 9;
	else 
		tarik_ocjena = 10;
	//Provjera da li je tarik prosao. Ako nije, smanji broj uspjelih za jedan 
	//Pretpostavili smo da je 3 pa eventualno smanjujemo za jedan od slucaja do slucaja
	if(tarik_ocjena == 5)
		--uspjeli_studenti;
	
	//Bojan
	//Unos bodova i provjera ispravnosti istih
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi_parcijalni);
	if(prvi_parcijalni<0 || prvi_parcijalni>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi_parcijalni);
	if(drugi_parcijalni<0 || drugi_parcijalni>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo);
	if(prisustvo<0 || prisustvo>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zadace);
	if(zadace<0 || zadace>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni_ispit);
	if(zavrsni_ispit<0 || zavrsni_ispit>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	broj_bodova = prvi_parcijalni + drugi_parcijalni + prisustvo + zadace + zavrsni_ispit;
	
	//Provjera ocjene
	if(broj_bodova<55)
		bojan_ocjena = 5;
	else if(broj_bodova>=55 && broj_bodova<65)
		bojan_ocjena = 6;
	else if(broj_bodova>=65 && broj_bodova<75)
		bojan_ocjena = 7;
	else if(broj_bodova>=75 && broj_bodova<85)
		bojan_ocjena = 8;
	else if(broj_bodova>=85 && broj_bodova<92)
		bojan_ocjena = 9;
	else 
		bojan_ocjena = 10;
	//Provjera da li je Bojan prosao
	if(bojan_ocjena == 5)
		--uspjeli_studenti;
	//Provjeri jesu li tarikova i bojanova ocjena iste
	if(bojan_ocjena == tarik_ocjena)
		--broj_razlictih_ocjena;
		
	//Mirza
	//Unos bodova i provjera ispravnosti istih
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi_parcijalni);
	if(prvi_parcijalni<0 || prvi_parcijalni>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi_parcijalni);
	if(drugi_parcijalni<0 || drugi_parcijalni>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prisustvo);
	if(prisustvo<0 || prisustvo>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zadace);
	if(zadace<0 || zadace>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni_ispit);
	if(zavrsni_ispit<0 || zavrsni_ispit>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	broj_bodova = prvi_parcijalni + drugi_parcijalni + prisustvo + zadace + zavrsni_ispit;
	
	//Provjera ocjene
	if(broj_bodova<55)
		mirza_ocjena = 5;
	else if(broj_bodova>=55 && broj_bodova<65)
		mirza_ocjena = 6;
	else if(broj_bodova>=65 && broj_bodova<75)
		mirza_ocjena = 7;
	else if(broj_bodova>=75 && broj_bodova<85)
		mirza_ocjena = 8;
	else if(broj_bodova>=85 && broj_bodova<92)
		mirza_ocjena = 9;
	else 
		mirza_ocjena = 10;
	if(mirza_ocjena == 5)
		--uspjeli_studenti;
	
	
	if(uspjeli_studenti == 3) {
		//Provjeri da li su prve dvije ocjene iste
		//Ako nisu, onda provjeri mirzinu sa svakom od prethodnih
		if(broj_razlictih_ocjena == 3 ) {
			if(mirza_ocjena == tarik_ocjena)
				--broj_razlictih_ocjena;
			else if(mirza_ocjena == bojan_ocjena)
				--broj_razlictih_ocjena;
		}
		//Ako jesu, provjeri samo sa prvom. Ako je sa prvom, onda znaci i da je s drugom jer su one medjusobno jednake.
		//Znamo da su jednake ako nam je broj_razlicitih_ocjena == 2, odnosno smanjen za jedan kad smo bojanovu ocjenu izracunali ( linija 114 )
		else if(broj_razlictih_ocjena == 2) {
			if(mirza_ocjena == tarik_ocjena)
				--broj_razlictih_ocjena;
		}
		
	}
	
		
	//Provjera i ispis - koliko je studenata proslo
	if(uspjeli_studenti==3)
		printf("Sva tri studenta su polozila.\n");
	else if(uspjeli_studenti == 2)
		printf("Dva studenta su polozila.\n");
	else if(uspjeli_studenti == 1)
		printf("Jedan student je polozio.\n");
	else
		printf ("Nijedan student nije polozio.\n");
		
	//Provjera i ispis - koliko ih ima razlicitu ocjenu
	if(uspjeli_studenti == 3) {
		if(broj_razlictih_ocjena == 3)
			printf("Svaki student ima razlicitu ocjenu.");
		else if(broj_razlictih_ocjena == 2)
			printf("Dva od tri studenta imaju istu ocjenu.");
		else
			printf("Sva tri studenta imaju istu ocjenu.");
	}
	
	return 0;
}
