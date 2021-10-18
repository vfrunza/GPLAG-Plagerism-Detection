#include <stdio.h>
int main () {
	double prviParc, drugiParc, pris, zad, zavrs, bodTarik, bodBojan, bodMirza;
	int ocjenaTarik, ocjenaBojan, ocjenaMirza;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prviParc);
	if(prviParc<0 || prviParc>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugiParc);
	if(drugiParc<0 || drugiParc>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pris);
	if(pris<0 || pris>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zad);
	if(zad<0 || zad>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrs);
	if(zavrs<0 || zavrs>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	bodTarik = prviParc + drugiParc + pris + zad + zavrs;
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prviParc);
	if(prviParc<0 || prviParc>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugiParc);
	if(drugiParc<0 || drugiParc>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pris);
	if(pris<0 || pris>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zad);
	if(zad<0 || zad>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrs);
	if(zavrs<0 || zavrs>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	bodBojan = prviParc + drugiParc + pris + zad + zavrs;
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &prviParc);
	if(prviParc<0 || prviParc>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &drugiParc);
	if(drugiParc<0 || drugiParc>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pris);
	if(pris<0 || pris>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zad);
	if(zad<0 || zad>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrs);
	if(zavrs<0 || zavrs>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	bodMirza = prviParc + drugiParc + pris + zad + zavrs;
	if(bodTarik < 55) {
		ocjenaTarik = 5;
	} else if(bodTarik < 65) {
		ocjenaTarik = 6;
	} else if(bodTarik < 75) {
		ocjenaTarik = 7;
	} else if(bodTarik < 85) {
		ocjenaTarik = 8;
	} else if(bodTarik < 95) {
		ocjenaTarik = 9;
	} else {
		ocjenaTarik = 10;
	}
	if(bodBojan < 55) {
		ocjenaBojan = 5;
	} else if(bodBojan < 65) {
		ocjenaBojan = 6;
	} else if(bodBojan < 75) {
		ocjenaBojan = 7;
	} else if(bodBojan < 85) {
		ocjenaBojan = 8;
	} else if(bodBojan < 95) {
		ocjenaBojan = 9;
	} else {
		ocjenaBojan = 10;
	}
	if(bodMirza < 55) {
		ocjenaMirza = 5;
	} else if(bodMirza < 65) {
		ocjenaMirza = 6;
	} else if(bodMirza < 75) {
		ocjenaMirza = 7;
	} else if(bodMirza < 85) {
		ocjenaMirza = 8;
	} else if(bodMirza < 95) {
		ocjenaMirza = 9;
	} else {
		ocjenaMirza = 10;
	}
	if(ocjenaTarik == ocjenaBojan && ocjenaBojan == ocjenaMirza && ocjenaMirza == 5) {
		printf("Nijedan student nije polozio.\n");
	} else if((ocjenaTarik == ocjenaBojan && ocjenaBojan == 5) || 
		(ocjenaBojan == ocjenaMirza && ocjenaMirza == 5) || 
		(ocjenaTarik == ocjenaMirza && ocjenaMirza == 5)) {
			printf("Jedan student je polozio.\n");
	} else if(ocjenaTarik == 5 || ocjenaBojan == 5 || ocjenaMirza == 5) {
		printf("Dva studenta su polozila.\n");
	} else {
		printf("Sva tri studenta su polozila.\n");
		if(ocjenaTarik == ocjenaBojan && ocjenaBojan == ocjenaMirza) {
			printf("Sva tri studenta imaju istu ocjenu.");
		} else if(ocjenaTarik != ocjenaBojan && ocjenaBojan != ocjenaMirza && ocjenaTarik != ocjenaMirza) {
			printf("Svaki student ima razlicitu ocjenu.");
		} else {
			printf("Dva od tri studenta imaju istu ocjenu.");
		}
	}
	return 0;
}