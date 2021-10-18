#include <stdio.h>
#include <math.h>

int main() {
	float tarik_prviParc,tarik_drugiParc,tarik_zadace,tarik_prisustvo,tarik_zavrsni;
	float bojan_prviParc,bojan_drugiParc,bojan_zadace,bojan_prisustvo,bojan_zavrsni;
	float mirza_prviParc,mirza_drugiParc,mirza_zadace,mirza_prisustvo,mirza_zavrsni;
	
	float tarik,bojan,mirza;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");scanf("%f",&tarik_prviParc);if(tarik_prviParc<0 || tarik_prviParc>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");scanf("%f",&tarik_drugiParc);if(tarik_drugiParc<0 || tarik_drugiParc>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");scanf("%f",&tarik_prisustvo);if(tarik_prisustvo<0 ||tarik_prisustvo>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");scanf("%f",&tarik_zadace);if(tarik_zadace<0 ||tarik_zadace>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");scanf("%f",&tarik_zavrsni);if(tarik_zavrsni<0 ||tarik_zavrsni>40){printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");scanf("%f",&bojan_prviParc);if(bojan_prviParc<0 || bojan_prviParc>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");scanf("%f",&bojan_drugiParc);if(bojan_drugiParc<0 || bojan_drugiParc>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");scanf("%f",&bojan_prisustvo);if(bojan_prisustvo<0 ||bojan_prisustvo>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");scanf("%f",&bojan_zadace);if(bojan_zadace<0 ||bojan_zadace>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");scanf("%f",&bojan_zavrsni);if(bojan_zavrsni<0 ||bojan_zavrsni>40){printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: "); scanf("%f",&mirza_prviParc); if(mirza_prviParc<0||mirza_prviParc>20){printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");scanf("%f",&mirza_drugiParc);if(mirza_drugiParc<0 ||mirza_drugiParc>20){printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");scanf("%f",&mirza_prisustvo);if(mirza_prisustvo<0 ||mirza_prisustvo>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");scanf("%f",&mirza_zadace);if(mirza_zadace<0 ||mirza_zadace>10){printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");scanf("%f",&mirza_zavrsni);if(mirza_zavrsni<0 || mirza_zavrsni>40){printf("Neispravan broj bodova"); return 0;}
	
	{
		tarik=tarik_prviParc+tarik_drugiParc+tarik_prisustvo+tarik_zadace+tarik_zavrsni;
		bojan=bojan_prviParc+bojan_drugiParc+bojan_prisustvo+bojan_zadace+bojan_zavrsni;
		mirza=mirza_prviParc+mirza_drugiParc+mirza_prisustvo+mirza_zadace+mirza_zavrsni;
		if(tarik<54.99999 && bojan<55 && mirza<55){
			printf("Nijedan student nije polozio.\n");
		}
		else if((tarik<55 && bojan>=55 && mirza>=55) || (tarik>=55 && bojan<55 && mirza >=55) || (tarik>=55 && bojan>=55 && mirza<55)){
			printf("Dva studenta su polozila.\n");
		}
		else if((fabs(tarik)>=54.99999 && bojan<55 && mirza<55) || (fabs(tarik)<54.9999 && bojan>=55 && mirza<55) ||(fabs(tarik)<54.99999 && bojan<55 && mirza>=55)){
			printf("Jedan student je polozio.\n");
		}
		else{
			if(tarik>=55.00 && tarik<65) tarik=6;
			else if(tarik>=65 && tarik<75) tarik=7;
			else if(tarik>=75 && tarik<85) tarik=8;
			else if(tarik>=85 && tarik<95) tarik=9;
			else tarik=10;
			
			if(bojan>=55 && bojan<65) bojan=6;
			else if(bojan>=65 && bojan<75) bojan=7;
			else if(bojan>=75 && bojan<85) bojan=8;
			else if(bojan>=85 && bojan<95) bojan=9;
			else bojan=10;
			
			if(mirza>=55.00 && mirza<65) mirza=6;
			else if(mirza>=65 && mirza<75) mirza=7;
			else if(mirza>=75 && mirza<85) mirza=8;
			else if(mirza>=85 && mirza<95) mirza=9;
			else mirza=10;
			printf("Sva tri studenta su polozila.\n");
			if(0.0000001>fabs(tarik-bojan) && 0.0000001>fabs(bojan-mirza)){
				printf("Sva tri studenta imaju istu ocjenu.");
			}
			else if((0.0000001>fabs(tarik-bojan) && 0.0000001<=fabs(bojan-mirza)) || (0.0000001>fabs(tarik-mirza) && 0.0000001<=fabs(mirza-bojan)) || (0.0000001>fabs(mirza-bojan) && 0.0000001<=fabs(tarik-bojan))){
				printf("Dva od tri studenta imaju istu ocjenu.");
			}
			else{
				printf("Svaki student ima razlicitu ocjenu.");
			}
		}
	}
	return 0;
}
