#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double brBodova, suma = 0;
	int ocjena1, ocjena2, ocjena3, polozilo = 0;

	printf ("Unesite bodove za Tarika:");

	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 20)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 20)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    suma += brBodova;
	printf ("Prisustvo: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 10)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    suma += brBodova;
	printf ("Zadace: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 10)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 40)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;

	if (suma < 55)
	ocjena1 = 1;
	if (suma >= 55 && suma < 65)
	ocjena1 = 6;
	if (suma >= 65 && suma < 75)
	ocjena1 = 7;
	if (suma >= 75 && suma < 85)
	ocjena1 = 8;
	if (suma >= 85 && suma < 92)
	ocjena1 = 9;
	if (suma >= 92 && suma <= 100)
	ocjena1 = 10;

	/*IDE BOJAN SADA MALO NA ISPITIVANJE*/
	suma = 0;
	printf ("Unesite bodove za Bojana:");

	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 20)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 20)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    suma += brBodova;
	printf ("Prisustvo: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 10)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    suma += brBodova;
	printf ("Zadace: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 10)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 40)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;

	if (suma < 55)
	ocjena2 = 1;
	if (suma >= 55 && suma < 65)
	ocjena2 = 6;
	if (suma >= 65 && suma < 75)
	ocjena2 = 7;
	if (suma >= 75 && suma < 85)
	ocjena2 = 8;
	if (suma>= 85 && suma < 92)
	ocjena2 = 9;
	if (suma >= 92 && suma <= 100)
	ocjena2 = 10;

	/* IDE SAD MALO I MIRZA */
	suma = 0;
	printf ("Unesite bodove za Mirzu:");

	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 20)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 20)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    suma += brBodova;
	printf ("Prisustvo: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 10)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
    suma += brBodova;
	printf ("Zadace: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 10)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &brBodova);
    if(brBodova < 0 || brBodova > 40)
    {
        printf ("Neispravan broj bodova");
        return 0;
    }
	suma += brBodova;

	if (suma < 55)
	ocjena3 = 1;
	if (suma >= 55 && suma < 65)
	ocjena3 = 6;
	if (suma >= 65 && suma < 75)
	ocjena3 = 7;
	if (suma >= 75 && suma < 85)
	ocjena3 = 8;
	if (suma >= 85 && suma < 92)
	ocjena3 = 9;
	if (suma >= 92 && suma <= 100)
	ocjena3 = 10;
	
	if (ocjena1 > 5) polozilo++;
	if (ocjena2 > 5) polozilo++;
	if (ocjena3 > 5) polozilo++;

	if (polozilo == 0)
		printf ("Nijedan student nije polozio.");
	if (polozilo == 1)
		printf ("Jedan student je polozio.");
	if (polozilo == 2)
		printf ("Dva studenta su polozila.");
	if (polozilo == 3)
	{
        printf ("Sva tri studenta su polozila.");
        if ( ocjena1 != ocjena2 && ocjena2 != ocjena3)
            printf ("\nSvaki student ima razlicitu ocjenu.");
        else if ( ocjena1 == ocjena2 && ocjena2 == ocjena3)
            printf ("\nSva tri studenta imaju istu ocjenu.");
        else printf ("\nDva od tri studenta imaju istu ocjenu.");
	}
		
	return 0;
}