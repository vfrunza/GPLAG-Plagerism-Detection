#include <stdio.h>
#define c_min_bod1 0
#define c_max_bod1 20
#define c_min_bod2 0
#define c_max_bod2 20
#define c_min_bod3 0
#define c_max_bod3 10
#define c_min_bod4 0
#define c_max_bod4 10
#define c_min_bod5 0
#define c_max_bod5 40

#define c_min_granica_ocj_6 55
#define c_min_granica_ocj_7 65
#define c_min_granica_ocj_8 75
#define c_min_granica_ocj_9 85
#define c_min_granica_ocj_10 92

int main()
{
	float bod_T1, bod_T2, bod_T3, bod_T4, bod_T5, bod_T;
	float bod_B1, bod_B2, bod_B3, bod_B4, bod_B5, bod_B;
	float bod_M1, bod_M2, bod_M3, bod_M4, bod_M5, bod_M;
	int ocj_T,ocj_B, ocj_M;
	int broj_palih_na_ispitima=0;
	
	
	printf("Unesite bodove za Tarika :\n");
	
	printf("I parcijalni ispit: ");
	scanf(" %f%*[^\n]", &bod_T1);
	if (bod_T1 < c_min_bod1 || bod_T1 > c_max_bod1) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("II parcijalni ispit: ");
	scanf(" %f%*[^\n]", &bod_T2);
	if (bod_T2 < c_min_bod2 || bod_T2 > c_max_bod2) {
		printf("\nNeispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf(" %f%*[^\n]", &bod_T3);
	if (bod_T3 < c_min_bod3 || bod_T3 > c_max_bod3){
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Zadace:");
	scanf(" %f%*[^\n]", &bod_T4);
	if(bod_T4 < c_min_bod4 || bod_T4 > c_max_bod4){
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Zavrsni ispit:");
	scanf(" %f%*[^\n]", &bod_T5);
	if(bod_T5 < c_min_bod5 || bod_T5 > c_max_bod5) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	bod_T = bod_T1 + bod_T2 + bod_T3 + bod_T4 + bod_T5;
	
	if(bod_T< c_min_granica_ocj_6) {
		broj_palih_na_ispitima=broj_palih_na_ispitima + 1;
		ocj_T= 0;
	}
	else if(bod_T < c_min_granica_ocj_7)
	ocj_T = 6;
	else if(bod_T < c_min_granica_ocj_8)
	ocj_T = 7;
	else if (bod_T < c_min_granica_ocj_9)
	ocj_T = 8;
	else if (bod_T < c_min_granica_ocj_10)
	ocj_T = 9;
	else 
	ocj_T = 10;

	
	printf("Unesite bodove za Bojana :\n");
	
	printf("I parcijalni ispit: ");
	scanf(" %f%*[^\n]", &bod_B1);
	if(bod_B1 < c_min_bod1 || bod_B1 > c_max_bod1) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("II parcijalni ispit: ");
	scanf(" %f%*[^\n]", &bod_B2);
	if(bod_B2 < c_min_bod2 || bod_B2 > c_max_bod2) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Prisustvo: ");
	scanf(" %f%*[^\n]", &bod_B3);
	if(bod_B3 < c_min_bod3 || bod_B3 > c_max_bod3) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Zadace:");
	scanf(" %f%*[^\n]", &bod_B4);
	if(bod_B4 < c_min_bod4 || bod_B4 > c_max_bod4){
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Zavrsni ispit:");
	scanf("%f", &bod_B5);
	if(bod_B5 < c_min_bod5 || bod_B5 > c_max_bod5) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	bod_B= bod_B1 + bod_B2 + bod_B3 + bod_B4 + bod_B5;
	
	if(bod_B < c_min_granica_ocj_6) {
		broj_palih_na_ispitima = broj_palih_na_ispitima + 1 ;
		ocj_B = 0;
	}
	else if ( bod_B < c_min_granica_ocj_7)
	ocj_B = 6;
	else if ( bod_B < c_min_granica_ocj_8)
	ocj_B = 7 ;
	else if ( bod_B < c_min_granica_ocj_9)
	ocj_B = 8 ;
	else if ( bod_B < c_min_granica_ocj_10)
	ocj_B = 9;
	else
	ocj_B = 10;
	
	
	
	printf("Unesite bodove za Mirza:\n");
	
	printf("I parcijalni ispit: ");
	scanf("%f", &bod_M1);
	if( bod_M1 < c_min_bod1 || bod_M1 > c_max_bod1) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("II parcijalni ispit: ");
	scanf("%f", &bod_M2);
	if(bod_M2 < c_min_bod2 || bod_M2 > c_max_bod2) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	
	printf("Prisustvo: ");
	scanf("%f", &bod_M3);
	if(bod_M3 < c_min_bod3 || bod_M3 > c_max_bod3) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Zadace: ");
	scanf("%f", &bod_M4);
	if(bod_M5 < c_min_bod5 || bod_M5 > c_max_bod5) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	printf("Zavrsni ispit: ");
	scanf("%f", &bod_M5);
	if(bod_M5 < c_min_bod5 || bod_M5 > c_max_bod5) {
		printf("\nNeispravan broj bodova");
		return 0;
	};
	
	bod_M= bod_M1 + bod_M2 + bod_M3 + bod_M4 + bod_M5 ;
	
	if( bod_M < c_min_granica_ocj_6) {
		broj_palih_na_ispitima= broj_palih_na_ispitima + 1;
		ocj_M= 0;
	}
	else if( bod_M < c_min_granica_ocj_7)
	ocj_M = 6;
	else if ( bod_M < c_min_granica_ocj_8)
	ocj_M = 7;
	else if ( bod_M < c_min_granica_ocj_9)
	ocj_M = 8 ;
	else if ( bod_M < c_min_granica_ocj_10)
	ocj_M = 9 ; 
	else
	ocj_M =10 ;
	
	
	
	
	if (broj_palih_na_ispitima ==3) 
	printf("\nNijedan student nije položio.");
	else if ( broj_palih_na_ispitima == 2)
	printf("\nJedan student je položio.");
	else if (broj_palih_na_ispitima ==1)
	printf("\nDva studenta su položila.");
	else 
	printf("\nSva tri studenta su položila.");
	;
	
	
	
	if(ocj_T == ocj_M && ocj_M == ocj_B)
	printf ("\nSva tri studenta imaju istu ocjenu.");
	else if (ocj_T == ocj_B || ocj_T == ocj_M || ocj_B == ocj_M)
	printf("\nDva od tri studenta imaju istu ocjenu.");
	else
	printf("\nSvaki student ima različitu ocjenu.");
	
	return 0 ;
	
}