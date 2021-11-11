#include <stdio.h>

int main() {
	float tarik=0, bojan=0, mirza=0, prvipar, drugipar, prisustvo, zadace, zavrsni;
	int ocjena1=0, ocjena2=0, ocjena3=0;
	printf ("Unesite bodove za Tarika: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &prvipar);
	if (prvipar<0 || prvipar>20){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &drugipar);
	if (drugipar<0 || drugipar>20){
		printf ("Neispravan broj bodova.");
		return 0;
	} 
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	if (prisustvo<0 || prisustvo>10){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%f", &zadace);
	if (zadace<0 || zadace>10){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	if (zavrsni<0 || zavrsni>40){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	tarik = prvipar + drugipar + prisustvo + zadace + zavrsni;
	prvipar = 0; drugipar = 0; prisustvo = 0; zadace = 0; zavrsni = 0;
	printf ("Unesite bodove za Bojana: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &prvipar);
	if (prvipar<0 || prvipar>20){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &drugipar);
	if (drugipar<0 || drugipar>20){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	if (prisustvo<0 || prisustvo>10){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%f", &zadace);
	if (zadace<0 || zadace>10){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	if (zavrsni<0 || zavrsni>40){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	bojan = prvipar + drugipar + prisustvo + zadace + zavrsni;
	prvipar = 0; drugipar = 0; prisustvo = 0; zadace = 0; zavrsni = 0;
	printf ("Unesite bodove za Mirzu: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &prvipar);
	if (prvipar<0 || prvipar>20){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &drugipar);
		if (drugipar<0 || drugipar>20){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
	if (prisustvo<0 || prisustvo>10){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%f", &zadace);
	if (zadace<0 || zadace>10){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni);
	if (zavrsni<0 || zavrsni>40){
		printf ("Neispravan broj bodova.");
		return 0;
	}
	mirza = prvipar + drugipar + prisustvo + zadace + zavrsni;
	prvipar = 0; drugipar = 0; prisustvo = 0; zadace = 0; zavrsni = 0;
	if (tarik>=55 && tarik<65){
		ocjena1 = 6;
	} else if (tarik>=65 && tarik<75){
		ocjena1 = 7;
	} else if (tarik>=75 && tarik<85){
		ocjena1 = 8;
	} else if (tarik>=85 && tarik<92){
		ocjena1 = 9;
	} else if (tarik>=92 && tarik<100){
		ocjena1 = 10;
	}
	if (bojan>=55 && bojan<65){
		ocjena2 = 6;
	} else if (bojan>=65 && bojan<75){
		ocjena2 = 7;
	} else if (bojan>=75 && bojan<85){
		ocjena2 = 8;
	} else if (bojan>=85 && bojan<92){
		ocjena2 = 9;
	} else if (bojan>=92 && bojan<100){
		ocjena2 = 10;
	}
	if (mirza>=55 && mirza<65){
		ocjena3 = 6;
	} else if (mirza>=65 && mirza<75){
		ocjena3 = 7;
	} else if (mirza>=75 && mirza<85){
		ocjena3 = 8;
	} else if (mirza>=85 && mirza<92){
		ocjena3 = 9;
	} else if (mirza>=92 && mirza<100){
		ocjena3 = 10;
	}
	if (tarik<55 && bojan<55 && mirza<55){
		printf ("Nijedan student nije polozio.");
	} else if ((tarik>55 && bojan<55 && mirza<55) || (tarik<55 && bojan>55 && mirza<55) || (tarik<55 && bojan<55 && mirza>55)){
		printf ("Jedan student je polozio.");
	} else if ((tarik>55 && bojan>55 && mirza<55) || (tarik>55 && bojan<55 && mirza>55) || (tarik<55 && bojan>55 && mirza>55)){
		printf ("Dva studenta su polozila.");
	} else if (tarik>55 && bojan>55 && mirza>55){
		printf ("Sva tri studenta su polozila.");
	}
	if (ocjena1 == 0 && ocjena2!=0 && ocjena3!=0 && ocjena2==ocjena3){
		printf ("Dva od tri studenta imaju istu ocjenu.");
	} else if ((ocjena1 != 0 && ocjena2 !=0 && ocjena3 !=0) && (ocjena1==ocjena2 && ocjena1==ocjena3)){
		printf ("Sva tri studenta imaju istu ocjenu.");
	} else if (ocjena2 == 0 && ocjena1!=0 && ocjena3!=0 && ocjena1==ocjena3){
		printf ("Dva od tri studenta imaju istu ocjenu.");
	} else if (ocjena3 == 0 && ocjena2!=0 && ocjena1!=0 && ocjena1==ocjena2){
		printf ("Dva od tri studenta imaju istu ocjenu.");
	}  else if ((ocjena1 != 0 && ocjena2 !=0 && ocjena3 !=0) && (ocjena1!=ocjena2 && ocjena1!=ocjena3 && ocjena2!=ocjena3)){
		printf ("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
}
