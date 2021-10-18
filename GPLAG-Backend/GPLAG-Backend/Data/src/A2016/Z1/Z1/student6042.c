#include <stdio.h>
#include <math.h>

int main () {
        double brojac,suma1,suma2,suma3,ocjena1,ocjena2,ocjena3,tarik_1,tarik_2,tarik_p,tarik_zad,tarik_zav,bojan_1,bojan_2,bojan_p,bojan_zad,bojan_zav,mirza_1,mirza_2,mirza_p,mirza_zad,mirza_zav;
        printf ("Unesite bodove za Tarika:");
        printf ("\nI parcijalni ispit: ");
        scanf ("%lf",&tarik_1); if (tarik_1<0 || tarik_1>20) { printf ("Neispravan broj bodova"); return 0; }
        printf ("II parcijalni ispit: ");
        scanf ("%lf",&tarik_2); if (tarik_2<0 || tarik_2>20) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Prisustvo: ");
        scanf ("%lf",&tarik_p); if (tarik_p<0 || tarik_p>10) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Zadace: ");
        scanf ("%lf",&tarik_zad); if (tarik_zad<0 || tarik_zad>10) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Zavrsni ispit: ");
        scanf ("%lf",&tarik_zav); if (tarik_zav<0 || tarik_zav>40) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Unesite bodove za Bojana:");
        printf ("\nI parcijalni ispit: ");
        scanf ("%lf",&bojan_1);   if (bojan_1<0 || bojan_1>20) { printf ("Neispravan broj bodova"); return 0; }
        printf ("II parcijalni ispit: ");
        scanf ("%lf",&bojan_2);   if (bojan_2<0 || bojan_2>20) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Prisustvo: ");
        scanf ("%lf",&bojan_p);   if (bojan_p<0 || bojan_p>10) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Zadace: ");
        scanf ("%lf",&bojan_zad); if (bojan_zad<0 || bojan_zad>10) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Zavrsni ispit: ");
        scanf ("%lf",&bojan_zav); if (bojan_zav<0 || bojan_zav>40) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Unesite bodove za Mirzu:");
        printf ("\nI parcijalni ispit: ");
        scanf ("%lf",&mirza_1);   if (mirza_1<0 || mirza_1>20) { printf ("Neispravan broj bodova"); return 0; }
        printf ("II parcijalni ispit: ");
        scanf ("%lf",&mirza_2);   if (mirza_2<0 || mirza_2>20) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Prisustvo: ");
        scanf ("%lf",&mirza_p);   if (mirza_p<0 || mirza_p>10) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Zadace: ");
        scanf ("%lf",&mirza_zad); if (mirza_zad<0 || mirza_zad>10) { printf ("Neispravan broj bodova"); return 0; }
        printf ("Zavrsni ispit: ");
        scanf ("%lf",&mirza_zav); if (mirza_zav<0 || mirza_zav>40) { printf ("Neispravan broj bodova"); return 0; }

if (tarik_1<0 || tarik_2<0 || tarik_p<0 || tarik_zad<0 || tarik_zav<0 || bojan_1<0 || bojan_2<0 || bojan_p<0 || bojan_zad<0 || bojan_zav<0 || mirza_1<0 || mirza_2<0 || mirza_p<0 || mirza_zad<0 || mirza_zav<0 || tarik_1>20 || tarik_2>20 || tarik_p>10 || tarik_zad>10 || tarik_zav>40 || bojan_1>20 || bojan_2>20 || bojan_p>10 || bojan_zad>10 || bojan_zav>40 || mirza_1>20 || mirza_2>20 || mirza_p>10 || mirza_zad>10 || mirza_zav>40 ) {
    printf ("Neispravan broj bodova");
    return 0;
}

brojac=0;
suma1=tarik_1+tarik_2+tarik_p+tarik_zad+tarik_zav;  if(suma1>=55) brojac++;
suma2=bojan_1+bojan_2+bojan_p+bojan_zad+bojan_zav; if(suma2>=55) brojac++;
suma3=mirza_1+mirza_2+mirza_p+mirza_zad+mirza_zav; if(suma3>=55) brojac++;

if(brojac==0) {
        printf ("Nijedan student nije polozio.");
return 0;
}

if (brojac==1) { printf ("Jedan student je polozio."); return 0; }
if (brojac==2)  { printf ("Dva studenta su polozila."); return 0; }
if (brojac==3)  printf ("Sva tri studenta su polozila.\n");

if (suma1>=55 && suma1<65) ocjena1=6;
if (suma2>=55 && suma2<65) ocjena2=6;
if (suma3>=55 && suma3<65) ocjena3=6;

if (suma1>=65 && suma1<75) ocjena1=7;
if (suma2>=65 && suma2<75) ocjena2=7;
if (suma3>=65 && suma3<75) ocjena3=7;

if (suma1>=75 && suma1<85) ocjena1=8;
if (suma2>=75 && suma2<85) ocjena2=8;
if (suma3>=75 && suma3<85) ocjena3=8;

if (suma1>=85 && suma1<92) ocjena1=9;
if (suma2>=85 && suma2<92) ocjena2=9;
if (suma3>=85 && suma3<92) ocjena3=9;

if (suma1>=92 && suma1<=100) ocjena1=10;
if (suma2>=92 && suma2<=100) ocjena2=10;
if (suma3>=92 && suma3<=100) ocjena3=10;

if (ocjena1!=ocjena2 && ocjena1!=ocjena3 && ocjena2!=ocjena3) printf ("Svaki student ima razlicitu ocjenu.");
if (ocjena1==ocjena2 && ocjena1==ocjena3) printf ("Sva tri studenta imaju istu ocjenu.");
if ( (ocjena1==ocjena2 && ocjena1!=ocjena3) || (ocjena2==ocjena3 && ocjena2!=ocjena1) || (ocjena1==ocjena3 && ocjena1!=ocjena2) ) {
    printf ("Dva od tri studenta imaju istu ocjenu.");
}



return 0;
}