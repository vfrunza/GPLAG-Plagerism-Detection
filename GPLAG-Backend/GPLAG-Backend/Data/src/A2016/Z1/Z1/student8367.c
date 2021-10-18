#include <stdio.h>

int main(){
float prvi_parc_Tarik, drugi_parc_Tarik, prisustvo_Tarik, zadace_Tarik, zavrsni_ispit_Tarik;
float prvi_parc_Bojan, drugi_parc_Bojan, prisustvo_Bojan, zadace_Bojan, zavrsni_ispit_Bojan;
float prvi_parc_Mirza, drugi_parc_Mirza, prisustvo_Mirza, zadace_Mirza, zavrsni_ispit_Mirza;
float br_bodova_Tarik, br_bodova_Bojan, br_bodova_Mirza;
int ocjena_Tarik, ocjena_Bojan, ocjena_Mirza;


printf("Unesite bodove za Tarika: \n");

printf("I parcijalni ispit: ");
scanf("%f", &prvi_parc_Tarik);
if(prvi_parc_Tarik<0 || prvi_parc_Tarik>20)
{printf("Neispravan broj bodova");
return 0;}

printf("II parcijalni ispit: ");
scanf("%f", &drugi_parc_Tarik);
if(drugi_parc_Tarik<0 || drugi_parc_Tarik>20)
{printf("Neispravan broj bodova");
return 0;}

printf("Prisustvo: ");
scanf("%f",&prisustvo_Tarik);
if(prisustvo_Tarik<0 || prisustvo_Tarik>10)
{printf("Neispravan broj bodova");
return 0;}

printf("Zadace: ");
scanf("%f",&zadace_Tarik);
if(zadace_Tarik<0 || zadace_Tarik>10)
{printf("Neispravan broj bodova");
return 0;}

printf("Zavrsni ispit: ");
scanf("%f",&zavrsni_ispit_Tarik);
if(zavrsni_ispit_Tarik<0 || zavrsni_ispit_Tarik>40)
{printf("Neispravan broj bodova");
return 0;}


br_bodova_Tarik = prvi_parc_Tarik + drugi_parc_Tarik + prisustvo_Tarik + zadace_Tarik + zavrsni_ispit_Tarik;

printf("Unesite bodove za Bojana: \n");

printf("I parcijalni ispit: ");
scanf("%f",&prvi_parc_Bojan);
if(prvi_parc_Bojan<0 || prvi_parc_Bojan>20)
{printf("Neispravan broj bodova");
return 0;}

printf("II parcijalni ispit: ");
scanf("%f",&drugi_parc_Bojan);
if(drugi_parc_Bojan<0 || drugi_parc_Bojan>20)
{printf("Neispravan broj bodova");
return 0;}

printf("Prisustvo: ");
scanf("%f",&prisustvo_Bojan);
if(prisustvo_Bojan<0 || prisustvo_Bojan>10)
{printf("Neispravan broj bodova");
return 0;}

printf("Zadace: ");
scanf("%f",&zadace_Bojan);
if(zadace_Bojan<0 || zadace_Bojan>10)
{printf("Neispravan broj bodova");
return 0;}

printf("Zavrsni ispit: ");
scanf("%f",&zavrsni_ispit_Bojan);
if(zavrsni_ispit_Bojan<0 || zavrsni_ispit_Bojan>40)
{printf("Neispravan broj bodova");
return 0;}


br_bodova_Bojan=prvi_parc_Bojan+drugi_parc_Bojan+prisustvo_Bojan+zadace_Bojan+zavrsni_ispit_Bojan;


printf("Unesite bodove za Mirzu: \n");

printf("I parcijalni ispit: ");
scanf("%f",&prvi_parc_Mirza);
if(prvi_parc_Mirza<0 || prvi_parc_Mirza>20)
{printf("Neispravan broj bodova");
return 0;}

printf("II parcijalni ispit: ");
scanf("%f",&drugi_parc_Mirza);
if(drugi_parc_Mirza<0 || drugi_parc_Mirza>20)
{printf("Neispravan broj bodova");
return 0;}

printf("Prisustvo: ");
scanf("%f",&prisustvo_Mirza);
if(prisustvo_Mirza<0 || prisustvo_Mirza>10)
{printf("Neispravan broj bodova");
return 0;}

printf("Zadace: ");
scanf("%f",&zadace_Mirza);
if(zadace_Mirza<0 || zadace_Mirza>10)
{printf("Neispravan broj bodova");
return 0;}

printf("Zavrsni ispit: ");
scanf("%f",&zavrsni_ispit_Mirza);
if(zavrsni_ispit_Mirza<0 || zavrsni_ispit_Mirza>40)
{printf("Neispravan broj bodova");
return 0;}


br_bodova_Mirza = prvi_parc_Mirza + drugi_parc_Mirza + prisustvo_Mirza + zadace_Mirza + zavrsni_ispit_Mirza;



/*Zbrajanje ostvarenih bodova*/


if(br_bodova_Tarik>55 && br_bodova_Tarik<65)
ocjena_Tarik=6;
else if(br_bodova_Tarik>=65 && br_bodova_Tarik<75)
ocjena_Tarik=7;
else if(br_bodova_Tarik>=75 && br_bodova_Tarik<85)
ocjena_Tarik=8;
else if(br_bodova_Tarik>=85 && br_bodova_Tarik<92)
ocjena_Tarik=9;
else if(br_bodova_Tarik>=92 && br_bodova_Tarik<=100)
ocjena_Tarik=10;

if(br_bodova_Bojan>=55 && br_bodova_Bojan<65)
ocjena_Bojan=6;
else if(br_bodova_Bojan>=65 && br_bodova_Bojan<75)
ocjena_Bojan=7;
else if(br_bodova_Bojan>=75 && br_bodova_Bojan<85)
ocjena_Bojan=8;
else if(br_bodova_Bojan>=85 && br_bodova_Bojan<92)
ocjena_Bojan=9;
else if(br_bodova_Bojan>=92 && br_bodova_Bojan<=100)
ocjena_Bojan=10;


if(br_bodova_Mirza>=55 && br_bodova_Mirza<65)
ocjena_Mirza=6;
else if(br_bodova_Mirza>=65 && br_bodova_Mirza<75)
ocjena_Mirza=7;
else if(br_bodova_Mirza>=75 && br_bodova_Mirza<85)
ocjena_Mirza=8;
else if(br_bodova_Mirza>=85 && br_bodova_Mirza<92)
ocjena_Mirza=9;
else if(br_bodova_Mirza>=92 && br_bodova_Mirza<=100)
ocjena_Mirza=10;



/*Statistika o prolaznosti studenata Tarik, Mirza i Bojan*/



if(br_bodova_Tarik<55 && br_bodova_Bojan<55 && br_bodova_Mirza<55)
printf("Nijedan student nije polozio.");

else if(br_bodova_Tarik>=55 && br_bodova_Bojan<55 && br_bodova_Mirza<55)
printf("Jedan student je polozio.");

else if(br_bodova_Tarik<55 && br_bodova_Bojan>=55 && br_bodova_Mirza<55)
printf("Jedan student je polozio.");

else if(br_bodova_Tarik<55 && br_bodova_Bojan<55 && br_bodova_Mirza>=55)
printf("Jedan student je polozio.");

else if(br_bodova_Tarik>=55 && br_bodova_Bojan>=55 && br_bodova_Mirza<55)
printf("Dva studenta su polozila.");

else if(br_bodova_Tarik>=55 && br_bodova_Bojan<55 && br_bodova_Mirza>=55)
printf("Dva studenta su polozila.");

else if(br_bodova_Tarik<55 && br_bodova_Bojan>=55 && br_bodova_Mirza>=55)
printf("Dva studenta su polozila.");

else if(br_bodova_Tarik>=55 && br_bodova_Bojan>=55 && br_bodova_Mirza>=55)
{printf("Sva tri studenta su polozila.\n");

if(ocjena_Tarik==ocjena_Mirza && ocjena_Mirza==ocjena_Bojan && ocjena_Tarik==ocjena_Bojan)
printf("Sva tri studenta imaju istu ocjenu.");
else if(ocjena_Tarik==ocjena_Mirza && ocjena_Tarik!=ocjena_Bojan && ocjena_Mirza!=ocjena_Bojan)
printf("Dva od tri studenta imaju istu ocjenu.");
else if(ocjena_Tarik==ocjena_Bojan && ocjena_Tarik!=ocjena_Mirza && ocjena_Bojan!=ocjena_Mirza)
printf("Dva od tri studenta imaju istu ocjenu.");
else if(ocjena_Mirza==ocjena_Bojan && ocjena_Mirza!=ocjena_Tarik && ocjena_Bojan!=ocjena_Tarik)
printf("Dva od tri studenta imaju istu ocjenu.");
else if(ocjena_Tarik!=ocjena_Bojan && ocjena_Tarik!=ocjena_Mirza && ocjena_Bojan!=ocjena_Mirza)
printf("Svaki student ima razlicitu ocjenu.");
}



return 0;
}

