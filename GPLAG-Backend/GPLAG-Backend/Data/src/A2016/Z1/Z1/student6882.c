#include <stdio.h>
#include <stdlib.h>



int main() {
	float prvi_parc;
	float drugi_parc;
	float prisustvo;
	float zadaca;
	float zavrsni_ispit;
	float suma;
	float prvi_parc1;
	float drugi_parc1;
	float prisustvo1;
	float zadaca1;
	float zavrsni_ispit1;
	float suma1;
	float prvi_parc2;
	float drugi_parc2;
	float prisustvo2;
	float zadaca2;
	float zavrsni_ispit2;
	float suma2;
	int ocjena;
	int ocjena1;
	int ocjena2;


	printf("Unesite bodove za Tarika: ");
	printf("\n");
	printf ("I parcijalni ispit: ");
	scanf ("%f",&prvi_parc);
		if (prvi_parc<0 || prvi_parc>20)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
					
		}


	printf ("II parcijalni ispit: ");
	scanf ("%f",&drugi_parc);
			if (drugi_parc<0 || drugi_parc>20)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
	

	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo);
			if (prisustvo<0 || prisustvo>10)
		{
		
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
	
	printf ("Zadace: ");
	scanf ("%f", &zadaca);
			if (zadaca<0 || zadaca>10)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
		

	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni_ispit);
			if (zavrsni_ispit<0 || zavrsni_ispit>40)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
	

		printf("Unesite bodove za Bojana: ");
	printf("\n");
	printf ("I parcijalni ispit: ");
	scanf ("%f",&prvi_parc1);
		if (prvi_parc1<0 || prvi_parc1>20)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}	


	printf ("II parcijalni ispit: ");
	scanf ("%f",&drugi_parc1);
			if (drugi_parc1<0 || drugi_parc1>20)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
	printf ("Prisustvo: ");
	scanf ("%f", &prisustvo1);
			if (prisustvo1<0 || prisustvo1>10)
		{
		
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
	
	printf ("Zadace: ");
	scanf ("%f", &zadaca1);
			if (zadaca1<0 || zadaca1>10)
		{
		
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
		

	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni_ispit1);
			if (zavrsni_ispit1<0 || zavrsni_ispit1>40)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
							printf("\n");
		}
	

		printf("Unesite bodove za Mirzu: ");
	printf("\n");
	printf ("I parcijalni ispit: ");
	scanf ("%f",&prvi_parc2);
		if (prvi_parc2<0 || prvi_parc2>20)
		{
		
					printf ("Neispravan broj bodova");
					return 0;
						printf("\n");
		}


	printf ("II parcijalni ispit: ");
	scanf ("%f",&drugi_parc2);
			if (drugi_parc2<0 || drugi_parc2>20)
		{
	
					printf ("Neispravan broj bodova");
					return 0;
						printf("\n");
		}
				

 printf ("Prisustvo: ");
	scanf ("%f", &prisustvo2);
			if (prisustvo2<0 || prisustvo2>10)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
						printf("\n");
		}
		

	printf ("Zadace: ");
	scanf ("%f", &zadaca2);
			if (zadaca2<0 || zadaca2>10)
		{
			
					printf ("Neispravan broj bodova");
					return 0;
						printf("\n");
		}
		

	printf ("Zavrsni ispit: ");
	scanf ("%f", &zavrsni_ispit2);
			if (zavrsni_ispit2<0 || zavrsni_ispit2>40)
		{
				
					printf ("Neispravan broj bodova");
					return 0;
						printf("\n");
		}
	

	suma=((double)prvi_parc+drugi_parc+prisustvo+zadaca+zavrsni_ispit);
	suma1=((double)prvi_parc1+drugi_parc1+prisustvo1+zadaca1+zavrsni_ispit1);
	suma2=((double)prvi_parc2+drugi_parc2+prisustvo2+zadaca2+zavrsni_ispit2);

	if (suma==0 || suma<55) ocjena=5;
	else if (suma<65) ocjena=6;
	else if (suma<75) ocjena=7;
	else if (suma<85) ocjena=8;
	else if(suma<95) ocjena=9;
	else if (suma<101) ocjena=10;

	if (suma1==0 || suma1<55) ocjena1=5;
	else if (suma1<65) ocjena1=6;
	else if (suma1<75) ocjena1=7;
	else if (suma1<85) ocjena1=8;
	else if(suma1<95) ocjena1=9;
	else if (suma1<101) ocjena1=10;

	if (suma2==0 || suma2<55) ocjena2=5;
	else if (suma2<65) ocjena2=6;
	else if (suma2<75) ocjena2=7;
	else if (suma2<85) ocjena2=8;
	else if(suma2<95) ocjena2=9;
	else if (suma2<101) ocjena2=10;

	if (ocjena==5 && ocjena1==5 && ocjena2==5)
	printf ("Nijedan student nije polozio.");
		if (((ocjena>5) && (ocjena1==5 && ocjena2==5)) ||((ocjena1>5) && (ocjena==5 && ocjena2==5)) || ((ocjena2>5) && (ocjena1==5 && ocjena==5)))
		printf ("Jedan student je polozio.");
	if (((ocjena==5) && (ocjena1>5 && ocjena2>5)) ||((ocjena1==5) && (ocjena>5 && ocjena2>5)) || ((ocjena2==5) && (ocjena1>5 && ocjena>5)))

	printf ("Dva studenta su polozila.");
	 if (ocjena>5 && ocjena1>5 && ocjena2>5)
	 {	 printf ("Sva tri studenta su polozila.");
	 printf ("\n");
	  if (ocjena==ocjena1 && ocjena1==ocjena2)
	  printf ("Sva tri studenta imaju istu ocjenu.");
	  else if (((ocjena==ocjena1) && ocjena!=ocjena2) ||((ocjena==ocjena2) && ocjena!=ocjena1) || ((ocjena1==ocjena2) && ocjena1!=ocjena))
	 	printf ("Dva od tri studenta imaju istu ocjenu.");
	 	else if (ocjena!=ocjena1 && ocjena!=ocjena2 && ocjena1!=ocjena2)
	 	printf ("Svaki student ima razlicitu ocjenu.");
	 }






	return 0;
}
