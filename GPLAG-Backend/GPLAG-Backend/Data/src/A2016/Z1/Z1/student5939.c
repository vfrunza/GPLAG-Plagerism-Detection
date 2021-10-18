#include <stdio.h>
#include <math.h>
#define BROJ_STUDENATA 3

int main() {
float parcijalni1,parcijalni2,prisustvo,zadaca,zavrsni;
int ukupno;
int tarik_ocjena,bojan_ocjena,mirza_ocjena;
int broj_palih=0;
int polozili=0;
/*tarik ispiti*/
printf ("Unesite bodove za Tarika:\n");

printf ("I parcijalni ispit: ");
scanf ("%f", &parcijalni1);
if (parcijalni1<0 || parcijalni1>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("II parcijalni ispit: ");
scanf ("%f", &parcijalni2);
if (parcijalni2<0 || parcijalni2>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Prisustvo: ");
scanf ("%f", &prisustvo);
if (prisustvo<0 || prisustvo>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Zadace: ");
scanf ("%f", &zadaca);
if (zadaca<0 || zadaca>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Zavrsni ispit: ");
scanf ("%f", &zavrsni);
if (zavrsni<0 || zavrsni>40)
{
	printf ("Neispravan broj bodova");
	return 1;
}

// provjera unosa 
/*if (parcijalni1<0 || parcijalni1>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}

if (parcijalni2<0 || parcijalni2>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (prisustvo<0 || prisustvo>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (zadaca<0 || zadaca>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (zavrsni<0 || zavrsni>40)
{
	printf ("Neispravan broj bodova");
	return 1;
}
*/

ukupno=floor(parcijalni1+parcijalni2+prisustvo+zadaca+zavrsni);

if (ukupno<55)
{
	tarik_ocjena=5;
	broj_palih=broj_palih+1;
}

else if (ukupno>=55 && ukupno<65)
{
	tarik_ocjena=6;
}
else if (ukupno>=65 && ukupno<75)
{
	tarik_ocjena=7;
}
else if (ukupno>=75 && ukupno<85)
{
	tarik_ocjena=8;
}
else if (ukupno>=85 && ukupno<92)
{
	tarik_ocjena=9;
}
else 
{
	tarik_ocjena=10;
}


//bojan


printf ("Unesite bodove za Bojana: \n");

printf ("I parcijalni ispit: ");
scanf ("%f", &parcijalni1);
if (parcijalni1<0 || parcijalni1>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("II parcijalni ispit: ");
scanf ("%f", &parcijalni2);
if (parcijalni2<0 || parcijalni2>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Prisustvo: ");
scanf ("%f", &prisustvo);
if (prisustvo<0 || prisustvo>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Zadace: ");
scanf ("%f", &zadaca);
if (zadaca<0 || zadaca>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Zavrsni ispit: ");
scanf ("%f", &zavrsni);
if (zavrsni<0 || zavrsni>40)
{
	printf ("Neispravan broj bodova");
	return 1;
}

// provjera unosa 
/*if (parcijalni1<0 || parcijalni1>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}

if (parcijalni2<0 || parcijalni2>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (prisustvo<0 || prisustvo>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (zadaca<0 || zadaca>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (zavrsni<0 || zavrsni>40)
{
	printf ("Neispravan broj bodova");
	return 1;
}
*/
ukupno=floor(parcijalni1+parcijalni2+prisustvo+zadaca+zavrsni);

if (ukupno<55)
{
	bojan_ocjena=5;
	broj_palih=broj_palih+1;
}

else if (ukupno>=55 && ukupno<65)
{
	bojan_ocjena=6;
}
else if (ukupno>=65 && ukupno<75)
{
	bojan_ocjena=7;
}
else if (ukupno>=75 && ukupno<85)
{
	bojan_ocjena=8;
}
else if (ukupno>=85 && ukupno<92)
{
	bojan_ocjena=9;
}
else 
{
	bojan_ocjena=10;
}


//mirza




printf ("Unesite bodove za Mirzu:\n");

printf ("I parcijalni ispit: ");
scanf ("%f", &parcijalni1);
if (parcijalni1<0 || parcijalni1>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("II parcijalni ispit: ");
scanf ("%f", &parcijalni2);
if (parcijalni2<0 || parcijalni2>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Prisustvo: ");
scanf ("%f", &prisustvo);
if (prisustvo<0 || prisustvo>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Zadace: ");
scanf ("%f", &zadaca);
if (zadaca<0 || zadaca>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
printf ("Zavrsni ispit: ");
scanf ("%f", &zavrsni);
if (zavrsni<0 || zavrsni>40)
{
	printf ("Neispravan broj bodova");
	return 1;
}

// provjera unosa 
/*if (parcijalni1<0 || parcijalni1>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}

if (parcijalni2<0 || parcijalni2>20)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (prisustvo<0 || prisustvo>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (zadaca<0 || zadaca>10)
{
	printf ("Neispravan broj bodova");
	return 1;
}
if (zavrsni<0 || zavrsni>40)
{
	printf ("Neispravan broj bodova");
	return 1;
}
*/
ukupno=floor(parcijalni1+parcijalni2+prisustvo+zadaca+zavrsni);

if (ukupno<55)
{
	mirza_ocjena=5;
	broj_palih=broj_palih+1;
}

else if (ukupno>=55 && ukupno<65)
{
	mirza_ocjena=6;
}
else if (ukupno>=65 && ukupno<75)
{
	mirza_ocjena=7;
}
else if (ukupno>=75 && ukupno<85)
{
	mirza_ocjena=8;
}
else if (ukupno>=85 && ukupno<92)
{
	mirza_ocjena=9;
}
else
{
	mirza_ocjena=10;
}

//provjera polozenih ispita
polozili=BROJ_STUDENATA-broj_palih;
if (broj_palih==3)
{
	printf ("Nijedan student nije polozio.\n");
}

else if (polozili==1)
{
	printf("Jedan student je polozio.\n");
}
else if (polozili==2)
{
	printf ("Dva studenta su polozila.\n");
}
else 
{
	printf ("Sva tri studenta su polozila.\n");
	
	if (bojan_ocjena==mirza_ocjena && tarik_ocjena==mirza_ocjena)
	{
		printf ("Sva tri studenta imaju istu ocjenu.\n");
	}
else	if ((tarik_ocjena==bojan_ocjena && tarik_ocjena!=mirza_ocjena) || (tarik_ocjena==mirza_ocjena && tarik_ocjena!=bojan_ocjena) || (bojan_ocjena==mirza_ocjena && bojan_ocjena!=tarik_ocjena))
	{
		printf ("Dva od tri studenta imaju istu ocjenu.\n");
	}
else 
	{
		printf ("Svaki student ima razlicitu ocjenu.\n");
	}

}
	return 0;
}



