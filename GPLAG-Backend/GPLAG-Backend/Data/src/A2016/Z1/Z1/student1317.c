#include <stdio.h>

int main() 
{
	double prva_parc1, druga_parc1, prisustvo1, zadace1, zav_ispit1;
	double prva_parc2, druga_parc2, prisustvo2, zadace2, zav_ispit2;
	double prva_parc3, druga_parc3, prisustvo3, zadace3, zav_ispit3;
	double suma1, suma2, suma3;
	int  ocjena1=0, ocjena2=0, ocjena3=0;
	
	/* Unos bodova */
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &prva_parc1);
	if(prva_parc1 >= 0.0f && prva_parc1 <= 20.0f)
	{
	    printf("II parcijalni ispit: ");
	    scanf("%lf", &druga_parc1);
	    if(druga_parc1 >= 0.0f && druga_parc1 <= 20.0f)
	    {
	        printf("Prisustvo: ");
	        scanf("%lf", &prisustvo1);
	        if(prisustvo1 >= 0.0f && prisustvo1 <= 10.0f)
	        {
	            printf("Zadace: ");
	            scanf("%lf", &zadace1);
	            if(zadace1 >= 0.0f && zadace1 <= 10.0f)
	            {
	                printf("Zavrsni ispit: ");
                    scanf("%lf", &zav_ispit1);
                    if(zav_ispit1 >= 0.0f && zav_ispit1 <= 40.0f)
                    {
                        suma1 = prva_parc1 + druga_parc1 + prisustvo1 + zadace1 + zav_ispit1;
                    }
                    else {printf("Neispravan broj bodova"); return 0;}
	            }
	            else {printf("Neispravan broj bodova"); return 0;}
	        }
	        else {printf("Neispravan broj bodova"); return 0;}
	    }
	    else {printf("Neispravan broj bodova"); return 0;}
	}
	else {printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &prva_parc2);
	if(prva_parc2 >= 0.0f && prva_parc2 <= 20.0f)
	{
	    printf("II parcijalni ispit: ");
	    scanf("%lf", &druga_parc2);
	    if(druga_parc2 >= 0.0f && druga_parc2 <= 20.0f)
	    {
	        printf("Prisustvo: ");
	        scanf("%lf", &prisustvo2);
	        if(prisustvo2 >= 0.0f && prisustvo2 <= 10.0f)
	        {
	            printf("Zadace: ");
	            scanf("%lf", &zadace2);
	            if(zadace2 >= 0.0f && zadace2 <= 10.0f)
	            {
	                printf("Zavrsni ispit: ");
                    scanf("%lf", &zav_ispit2);
                    if(zav_ispit2 >= 0.0f && zav_ispit2 <= 40.0f)
                    {
                        suma2 = prva_parc2 + druga_parc2 + prisustvo2 + zadace2 + zav_ispit2;
                    }
                    else {printf("Neispravan broj bodova"); return 0;}
	            }
	            else {printf("Neispravan broj bodova"); return 0;}
	        }
	        else {printf("Neispravan broj bodova"); return 0;}
	    }
	    else {printf("Neispravan broj bodova"); return 0;}
	}
	else {printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &prva_parc3);
	if(prva_parc3 >= 0.0f && prva_parc3 <= 20.0f)
	{
	    printf("II parcijalni ispit: ");
	    scanf("%lf", &druga_parc3);
	    if(druga_parc3 >= 0.0f && druga_parc3 <= 20.0f)
	    {
	        printf("Prisustvo: ");
	        scanf("%lf", &prisustvo3);
	        if(prisustvo3 >= 0.0f && prisustvo3 <= 10.0f)
	        {
	            printf("Zadace: ");
	            scanf("%lf", &zadace3);
	            if(zadace3 >= 0.0f && zadace3 <= 10.0f)
	            {
	                printf("Zavrsni ispit: ");
                    scanf("%lf", &zav_ispit3);
                    if(zav_ispit3 >= 0.0f && zav_ispit3 <= 40.0f)
                    {
                        suma3 = prva_parc3 + druga_parc3 + prisustvo3 + zadace3 + zav_ispit3;
                    }
                    else {printf("Neispravan broj bodova"); return 0;}
	            }
	            else {printf("Neispravan broj bodova"); return 0;}
	        }
	        else {printf("Neispravan broj bodova"); return 0;}
	    }
	    else {printf("Neispravan broj bodova"); return 0;}
	}
	else {printf("Neispravan broj bodova"); return 0;}
	
	/* Definisanje ocjena */
	if(suma1 >= 55.0f && suma1 < 65.0f) ocjena1 = 6;
	else if(suma1 >= 65.0f && suma1 < 75.0f) ocjena1 = 7;
	else if(suma1 >= 75.0f && suma1 < 85.0f) ocjena1 = 8;
	else if(suma1 >= 85.0f && suma1 < 92.0f) ocjena1 = 9;
	else if(suma1 >= 92.0f && suma1 <= 100.0f) ocjena1 = 10;
 
    if(suma2 >= 55.0f && suma2 < 65.0f) ocjena2 = 6;
	else if(suma2 >= 65.0f && suma2 < 75.0f) ocjena2 = 7;
	else if(suma2 >= 75.0f && suma2 < 85.0f) ocjena2 = 8;
	else if(suma2 >= 85.0f && suma2 < 92.0f) ocjena2 = 9;
	else if(suma2 >= 92.0f && suma2 <= 100.0f) ocjena2 = 10;
	
	if(suma3 >= 55.0f && suma3 < 65.0f) ocjena3 = 6;
	else if(suma3 >= 65.0f && suma3 < 75.0f) ocjena3 = 7;
	else if(suma3 >= 75.0f && suma3 < 85.0f) ocjena3 = 8;
	else if(suma3 >= 85.0f && suma3 < 92.0f) ocjena3 = 9;
	else if(suma3 >= 92.0f && suma3 <= 100.0f) ocjena3 = 10;
	
	/* Ispitivanje koliko je studenata polozilo */
	if(suma1 >= 55.0f && suma2 < 55.0f && suma3 < 55.0f) printf("Jedan student je polozio.");
	else if(suma1 < 55.0f && suma2 >= 55.0f && suma3 < 55.0f) printf("Jedan student je polozio.");
	else if(suma1 < 55.0f && suma2 < 55.0f && suma3 >= 55.0f) printf("Jedan student je polozio.");
	else if(suma1 >= 55.0f && suma2 >= 55.0f && suma3 < 55.0f) printf("Dva studenta su polozila.");
	else if(suma1 >= 55.0f && suma2 < 55.0f && suma3 >= 55.0f) printf("Dva studenta su polozila.");
	else if(suma1 < 55.0f && suma2 >= 55.0f && suma3 >= 55.0f) printf("Dva studenta su polozila.");
	else if(suma1 >= 55.0f && suma2 >= 55.0f && suma3 >= 55.0f) 
	{
		printf("Sva tri studenta su polozila.");
		if(ocjena1 == ocjena2 && ocjena1 == ocjena3) printf("\nSva tri studenta imaju istu ocjenu.");
		else if(ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3) printf("\nSvaki student ima razlicitu ocjenu.");
		else if(ocjena1 == ocjena2 && ocjena1 != ocjena3) printf("\nDva od tri studenta imaju istu ocjenu.");
		else if(ocjena1 == ocjena3 && ocjena1 != ocjena2) printf("\nDva od tri studenta imaju istu ocjenu.");
		else if(ocjena2 == ocjena3 && ocjena2 != ocjena1) printf("\nDva od tri studenta imaju istu ocjenu.");
	}
	else if(suma1 < 55.0f && suma2 < 55.0f && suma3 < 55.0f) printf("Nijedan student nije polozio.");
	return 0;
}
