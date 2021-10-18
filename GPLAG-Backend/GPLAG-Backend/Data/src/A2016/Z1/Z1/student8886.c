#include <stdio.h>
int main () {
     float P11, P21, p1, DZ1, Z1, P12, P22, p2, DZ2, Z2, P13, P23, p3, DZ3, Z3, O1=0, O2=0, O3=0;
printf ("Unesite bodove za Tarika:\n");
printf ("I parcijalni ispit: ");
scanf ("%f", &P11);
if (P11<0.0 || P11>20.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("II parcijalni ispit: "); }
scanf ("%f", &P21);
if (P21<0.0 || P21>20.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Prisustvo: "); }
scanf ("%f", &p1);
if (p1<0.0 || p1>10.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Zadace: "); }
scanf ("%f", &DZ1);
if (DZ1<0.0 || DZ1>10.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else { 
printf ("Zavrsni ispit: "); }
scanf ("%f", &Z1);
if (Z1<0.0 || Z1>40.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Unesite bodove za Bojana:\n"); }
printf ("I parcijalni ispit: ");
scanf ("%f", &P12);
if (P12<0.0 || P12>20.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("II parcijalni ispit: "); }
scanf ("%f", &P22);
if (P22<0.0 || P22>20.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Prisustvo: "); }
scanf ("%f", &p2);
if (p2<0.0 || p2>10.0) { printf ("Neispravan broj bodova"); 
        return 0; }
else {
printf ("Zadace: "); }
scanf ("%f", &DZ2);
if (DZ2<0.0 || DZ2>10.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Zavrsni ispit: "); }
scanf ("%f", &Z2);
if (Z2<0.0 || Z2>40.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Unesite bodove za Mirzu:\n"); }
printf ("I parcijalni ispit: ");
scanf ("%f", &P13);
if (P13<0.0 || P13>20.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("II parcijalni ispit: "); }
scanf ("%f", &P23);
if (P23<0.0 || P23>20.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Prisustvo: "); }
scanf ("%f", &p3);
if (p3<0.0 || p3>10.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Zadace: "); }
scanf ("%f", &DZ3);
if (DZ3<0.0 || DZ3>10.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else {
printf ("Zavrsni ispit: "); }
scanf ("%f", &Z3);
if (Z3<0.0 || Z3>40.0) { printf ("Neispravan broj bodova"); 
    return 0; }
else { 
O1=P11+P21+p1+Z1+DZ1;
O2=P12+P22+p2+Z2+DZ2;
O3=P13+P23+p3+Z3+DZ3; 
if (O1<55 && O2<55 && O3<55) { printf ("Nijedan student nije polozio."); }
else if (O1<55 && O2<55 && O3>=55) { printf ("Jedan student je polozio."); }
else if (O1<55 && O2>=55 && O3<55) { printf ("Jedan student je polozio."); }
else if (O1>=55 && O2<55 && O3<55) { printf ("Jedan student je polozio."); }
else if (O1>=55 && O2>=55 && O3<55) { printf ("Dva studenta su polozila."); } 
else if (O1>=55 && O2<55 && O3>=55) { printf ("Dva studenta su polozila."); } 
else if (O1<55 && O2>=55 && O3>=55) { printf ("Dva studenta su polozila."); } 
/*Situacija1: 3 studenta imaju istu ocjenu*/
else if (O1>=55 && O1<65 && O2>=55 && O2<65 && O3>=55 && O3<65) { printf ("Sva tri studenta su polozila.\nSva tri studenta imaju istu ocjenu."); }
else if (O1>=65 && O1<75 && O2>=65 && O2<75 && O3>=65 && O3<75) { printf ("Sva tri studenta su polozila.\nSva tri studenta imaju istu ocjenu."); }
else if (O1>=75 && O1<85 && O2>=75 && O2<85 && O3>=75 && O3<85) { printf ("Sva tri studenta su polozila.\nSva tri studenta imaju istu ocjenu."); }
else if (O1>=85 && O1<92 && O2>=85 && O2<92 && O3>=85 && O3<92) { printf ("Sva tri studenta su polozila.\nSva tri studenta imaju istu ocjenu."); }
else if (O1>=92 && O1<=100 && O2>=92 && O2<=100 && O3>=92 && O3<=100) { printf ("Sva tri studenta su polozila.\nSva tri studenta imaju istu ocjenu."); }
/*Situacija2: Tarik i Bojan imaju istu ocjenu*/
else if (O1>=55 && O1<65 && O2>=55 && O2<65 && O3>=65) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=65 && O1<75 && O2>=65 && O2<75 && O3>=75) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=65 && O1<75 && O2>=65 && O2<75 && O3<65 && O3>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=75 && O1<85 && O2>=75 && O2<85 && O3>=85) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=75 && O1<85 && O2>=75 && O2<85 && O3<75 && O3>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=85 && O1<92 && O2>=85 && O2<85 && O3<85 && O3>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=85 && O1<92 && O2>=85 && O2<92 && O3>=92) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=92 && O1<=100 && O2>=92 && O2<=100 && O3<92 && O3>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
/*Situacija3: Tarik i Mirza imaju istu ocjenu*/
else if (O1>=55 && O1<65 && O3>=55 && O3<65 && O2>=65) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=65 && O1<75 && O3>=65 && O3<75 && O2>=75) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=65 && O1<75 && O3>=65 && O3<75 && O2<65 && O2>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=75 && O1<85 && O3>=75 && O3<85 && O2>=85) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=75 && O1<85 && O3>=75 && O3<85 && O2<75 && O2>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=85 && O1<92 && O3>=85 && O3<85 && O2<85 && O2>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=85 && O1<92 && O3>=85 && O3<92 && O2>=92) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O1>=92 && O1<=100 && O3>=92 && O3<=100 && O2<92 && O2>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
/*Situacija4: Mirza i Bojan imaju istu ocjenu*/
else if (O2>=55 && O2<65 && O3>=55 && O1<65 && O1>=65) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=65 && O2<75 && O3>=65 && O3<75 && O1>=75) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=65 && O2<75 && O3>=65 && O3<75 && O1<65 && O1>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=75 && O2<85 && O3>=75 && O3<85 && O1>=85) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=75 && O2<85 && O3>=75 && O3<85 && O1<75 && O1>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=85 && O2<92 && O3>=85 && O3<85 && O1<85 && O1>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=85 && O2<92 && O3>=85 && O3<92 && O1>=92) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
else if (O2>=92 && O2<=100 && O3>=92 && O3<=100 && O1<92 && O1>=55) { printf ("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu."); }
/*Situacija5: 3 studenta imaju različite ocjene*/
else if (O1>=55 && O1<65 && O2>=65 && O2<75 && O3>=75 && O3<85) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O1>=65 && O1<75 && O2>=75 && O2<85 && O3>=85 && O3<92) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O1>=75 && O1<85 && O2>=85 && O2<92 && O3>=92 && O3<=100) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O1>=55 && O1<65 && O3>=65 && O3<75 && O2>=75 && O2<85) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O1>=65 && O1<75 && O3>=75 && O3<85 && O2>=85 && O2<92) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O1>=75 && O1<85 && O3>=85 && O3<92 && O2>=92 && O2<=100) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O2>=55 && O2<65 && O1>=65 && O1<75 && O3>=75 && O3<85) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O2>=65 && O2<75 && O1>=75 && O1<85 && O3>=85 && O3<92) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O2>=75 && O2<85 && O1>=85 && O1<92 && O3>=92 && O3<=100) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O2>=55 && O2<65 && O3>=65 && O3<75 && O1>=75 && O1<85) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O2>=65 && O2<75 && O3>=75 && O3<85 && O1>=85 && O1<92) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O2>=75 && O2<85 && O3>=85 && O3<92 && O1>=92 && O1<=100) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O3>=55 && O3<65 && O1>=65 && O1<75 && O2>=75 && O2<85) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O3>=65 && O3<75 && O1>=75 && O1<85 && O2>=85 && O2<92) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O3>=75 && O3<85 && O1>=85 && O1<92 && O2>=92 && O2<=100) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O3>=55 && O3<65 && O2>=65 && O2<75 && O1>=75 && O1<85) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O3>=65 && O3<75 && O2>=75 && O2<85 && O1>=85 && O1<92) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
else if (O3>=75 && O3<85 && O2>=85 && O2<92 && O1>=92 && O1<=100) { printf ("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu."); }
 }
 return 0;
}