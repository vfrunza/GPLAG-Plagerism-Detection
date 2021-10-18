#include <stdio.h>
#include <math.h>

#define eps 0.001

int ocjena(float b) {
	//b = round(b); //u korist studenta ;)
	if (b + eps < 55) return 0;
	if (b + eps < 65) return 6;
	if (b + eps < 75) return 7;
	if (b + eps < 85) return 8;
	if (b + eps < 92) return 9;
	if (b + eps < 100) return 10;
	return -1;
}

double pitaj(char* sta, float max) {
	float unos;
	printf(sta);
	scanf("%f", &unos);
	if (unos > max) return -1;
	return unos;
}

#define isto {if (rez < 0) return -1; ukupno += rez;}

int unos(char* ime) {
	float ukupno = 0, rez; 
	
	printf("Unesite bodove za %s: \n", ime);
	rez = pitaj("I parcijalni ispit: ", 20);
	isto
	rez = pitaj("II parcijalni ispit: ", 20);
	isto
	rez = pitaj("Prisustvo: ", 10);
	isto
	rez = pitaj("Zadace: ", 10);
	isto
	rez = pitaj("Zavrsni ispit: ", 40);
	isto
	
	return ocjena(ukupno);
}

#define check(x) if((x)<0) {printf("Neispravan broj bodova"); return 0;}

int main() {
	int tarik, bojan, mirza, polozili = 3;
	
	tarik = unos("Tarika");
	check(tarik)
	bojan = unos("Bojana");
	check(bojan)
	mirza = unos("Mirzu");
	check(mirza)

	if (tarik == 0) polozili--;
	if (bojan == 0) polozili--;
	if (mirza == 0) polozili--;
	
	if (polozili == 0) 
		printf("Nijedan student nije polozio.\n");
	if (polozili == 1) 
		printf("Jedan student je polozio.\n");
	if (polozili == 2) 
		printf("Dva studenta su polozila.\n");
	if (polozili == 3) {
		printf("Sva tri studenta su polozila.\n");
	
		if (tarik == mirza && mirza == bojan)
			printf("Sva tri studenta imaju istu ocjenu.\n");
		else if (tarik != mirza && mirza != bojan && bojan != tarik) 
			printf("Svaki student ima razlicitu ocjenu.\n");
		else
			printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	return 0;
}
