/*1. Tri prijatelja - Tarik, Bojan i Mirza - odlučili su da uporede svoj uspjeh na predmetu Osnove računarstva. 
Njima je potreban program koji omogućuje unos bodova po kategorijama: I parcijalni ispit (max. 20 bodova), II parcijalni ispit (max. 20 bodova), 
Prisustvo (max. 10 bodova), Zadaće  (max. 10 bodova) i Završni ispit (max. 40 bodova). Broj bodova može imati i decimalni dio. 
U slučaju da se unese negativan broj bodova ili veći od dozvoljenog, program treba ispisati poruku "Neispravan broj bodova" (bez navodnika) 
i prekinuti rad programa. */

#include <stdio.h>
int main () {
	double IPT,IIPT,ZT,PT,ZIT,IPB,IIPB,ZB,PB,ZIB,IPM,IIPM,ZM,PM,ZIM,UBT,UBM,UBB;
	
	//Unosimo podatke za Tarika
	
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &IPT);
	
					if ((IPT>20) || (IPT <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPT);
	
						if ((IIPT>20) || (IIPT <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	printf("Prisustvo: ");
	scanf("%lf", &PT);
	
						if ((PT>10) || (PT <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	printf("Zadace: ");
	scanf("%lf", &ZT);
	
						if ((ZT>10) || (ZT <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	
						if ((ZIT>40) || (ZIT <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	
	//Unosimo podatke za Bojana
	
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &IPB);
	
						if ((IPB>20) || (IPB <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPB);
						if ((IIPB>20) || (IIPB <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	printf("Prisustvo: ");
	scanf("%lf", &PB);
						if ((PB>10) || (PB <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	printf("Zadace: ");
	scanf("%lf", &ZB);
						if ((ZB>10) || (ZB <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB);
						if ((ZIB>40) || (ZIB <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	//Unosimo podatke za Mirzu
	
	printf("Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &IPM);
	
						if ((IPM>20) || (IPM <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPM);
	
						if ((IIPM>20) || (IIPM <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	
	printf("Prisustvo: ");
	scanf("%lf", &PM);
	
						if ((PM>10) || (PM <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	
	printf("Zadace: ");
	scanf("%lf", &ZM);
	
						if ((ZM>10) || (ZM <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 
	
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);
	
						if ((ZIM>40) || (ZIM <0)) {
				printf ("Neispravan broj bodova");
				return 0;
			} 


/*Ako su svi bodovi uneseni ispravno, nakon unosa treba odrediti ocjene za svakog studenta po važećoj skali:
do 55 bodova - student pao
[55, 65) bodova - ocjena 6
[65, 75) bodova - ocjena 7
[75, 85) bodova - ocjena 8
[85, 92) boda - ocjena 9
[92, 100] bodova - ocjena 10 */

/*Potrebno je ispisati jednu od sljedećih poruka ovisno o situaciji:
Nijedan student nije položio.
Jedan student je položio.
Dva studenta su položila.
Sva tri studenta su položila. */

	//Racunamo ukupne bodove za Tarika, Bojana i Mirzu

UBT=IPT+IIPT+ZT+PT+ZIT;
UBB=IPB+IIPB+ZB+PB+ZIB;
UBM=IPM+IIPM+ZM+PM+ZIM;

	//Postavljamo uslove o studentima koji su polozili/nisu polozili

if ((UBT<55) && (UBM<55) && (UBB<55) )
	{printf("Nijedan student nije polozio.\n");
	return 0;
	}
else if (((UBT>=55) && (UBM<55) && (UBB<55) ) || ((UBT<55) && (UBM>=55) && (UBB<55) ) || ((UBT<55) && (UBM<55) && (UBB>=55) )) {
	printf("Jedan student je polozio.\n"); 
	return 0;
	}
else if (((UBT>=55) && (UBM>=55) && (UBB<55) ) || ((UBT<55) && (UBM>=55) && (UBB>=55) ) || ((UBT>=55) && (UBM<55) && (UBB>=55) )) {
	printf("Dva studenta su polozila.\n"); 
	return 0;
	}
if ((UBT>=55) && (UBM>=55) && (UBB>=55) )
	{printf("Sva tri studenta su polozila.\n");
	}


/*Te ako su sva tri studenta položila, u sljedećem redu ispisati jednu od poruka:
Sva tri studenta imaju istu ocjenu.
Dva od tri studenta imaju istu ocjenu.
Svaki student ima različitu ocjenu.*/

	//Postavljamo uslove za ocjene

if (((UBT>=55) && (UBT<65) && (UBB>=55) && (UBB<65) && (UBM>=55) && (UBM<65)) || 
	((UBT>=65) && (UBT<75) && (UBB>=65) && (UBB<75) && (UBM>=65) && (UBM<75)) ||
	((UBT>=75) && (UBT<85) && (UBB>=75) && (UBB<85) && (UBM>=75) && (UBM<85)) ||
	((UBT>=85) && (UBT<92) && (UBB>=55) && (UBB<92) && (UBM>=55) && (UBM<92)) ||
	((UBT>=92) && (UBT<=100) && (UBB>=92) && (UBB<=100) && (UBM>=92) && (UBM<=100)))
	{
			printf("Sva tri studenta imaju istu ocjenu.\n");
			return 0;
	}
else if (((UBT>=55) && (UBT<65) && (UBB>=65) && (UBB<75) && (UBM>=75) && (UBM<100)) || 
	((UBT>=55) && (UBT<65) && (UBB>=75) && (UBB<100) && (UBM>=65) && (UBM<75)) ||
	((UBB>=55) && (UBB<65) && (UBT>=65) && (UBT<75) && (UBM>=75) && (UBM<100)) || 
	((UBB>=55) && (UBB<65) && (UBT>=75) && (UBT<100) && (UBM>=65) && (UBM<75)) ||
	((UBM>=55) && (UBM<65) && (UBB>=65) && (UBB<75) && (UBT>=75) && (UBT<100)) || 
	((UBM>=55) && (UBM<65) && (UBB>=75) && (UBB<100) && (UBT>=65) && (UBT<75)) )
	{
			printf("Svaki student ima razlicitu ocjenu.\n");
			return 0;
	}

else if (((UBT>=55) && (UBT<65) && (UBB>=55) && (UBB<65) && (UBM>=65) && (UBM<100)) || 
	((UBT>=65) && (UBT<75) && (UBB>=65) && (UBB<75) && (((UBM>=75) && (UBM<100)) || ((UBM>=55) && (UBM<65)))) || 
	((UBT>=75) && (UBT<85) && (UBB>=75) && (UBB<85) && (((UBM>=85) && (UBM<100)) || ((UBM>=55) && (UBM<75)))) || 
	((UBT>=85) && (UBT<92) && (UBB>=85) && (UBB<92) && (((UBM>=92) && (UBM<100)) || ((UBM>=55) && (UBM<85)))) ||
	((UBT>=65) && (UBT<75) && (UBB>=65) && (UBB<75) && (((UBM>=75) && (UBM<100)) || ((UBM>=55) && (UBM<65)))) ||
	((UBT>=92) && (UBT<100) && (UBB>=92) && (UBB<100) && (UBM>=55) && (UBM<92)) || 
	
	((UBB>=55) && (UBB<65) && (UBM>=55) && (UBM<65) && (UBT>=65) && (UBT<100)) || 
	((UBB>=65) && (UBB<75) && (UBM>=65) && (UBM<75) && (((UBT>=75) && (UBT<100)) || ((UBT>=55) && (UBT<65)))) || 
	((UBB>=75) && (UBB<85) && (UBM>=75) && (UBM<85) && (((UBT>=85) && (UBT<100)) || ((UBT>=55) && (UBT<75)))) || 
	((UBB>=85) && (UBB<92) && (UBM>=85) && (UBM<92) && (((UBT>=92) && (UBT<100)) || ((UBT>=55) && (UBT<85)))) ||
	((UBB>=65) && (UBB<75) && (UBM>=65) && (UBM<75) && (((UBT>=75) && (UBT<100)) || ((UBT>=55) && (UBT<65)))) ||
	((UBB>=92) && (UBB<100) && (UBM>=92) && (UBM<100) && (UBT>=55) && (UBT<92)) || 
	
	((UBM>=55) && (UBM<65) && (UBT>=55) && (UBT<65) && (UBB>=65) && (UBM<100)) || 
	((UBM>=65) && (UBM<75) && (UBT>=65) && (UBT<75) && (((UBB>=75) && (UBB<100)) || ((UBB>=55) && (UBB<65)))) || 
	((UBM>=75) && (UBM<85) && (UBT>=75) && (UBT<85) && (((UBB>=85) && (UBB<100)) || ((UBB>=55) && (UBB<75)))) || 
	((UBM>=85) && (UBM<92) && (UBT>=85) && (UBT<92) && (((UBB>=92) && (UBB<100)) || ((UBB>=55) && (UBB<85)))) ||
	((UBM>=65) && (UBM<75) && (UBT>=65) && (UBT<75) && (((UBB>=75) && (UBB<100)) || ((UBB>=55) && (UBB<65)))) ||
	((UBM>=92) && (UBM<100) && (UBT>=92) && (UBT<100) && (UBB>=55) && (UBB<92)))
	
	{
			printf("Dva od tri studenta imaju istu ocjenu.\n");
			return 0;
	}

/*Primjer ulaza i izlaza:
	Unesite bodove za Tarika:
	I parcijalni ispit: 18
	II parcijalni ispit: 15
	Prisustvo: 9
	Zadace: 5
	Zavrsni ispit: 30
	Unesite bodove za Bojana:
	I parcijalni ispit: 12
	...
	Sva tri studenta su polozila.
	Svaki student ima razlicitu ocjenu.


Napomena: Pri rješavanju zadatka nije dozvoljeno koristiti nizove niti petlje!*/


	
	return 0;
}