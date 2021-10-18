#include <stdio.h>

int main() {
	double I_Tarik, II_Tarik, PR_Tarik, ZAD_Tarik, ZAVR_Tarik, I_Bojan, II_Bojan, PR_Bojan, ZAD_Bojan, ZAVR_Bojan, I_Mirza, II_Mirza, PR_Mirza, ZAD_Mirza, ZAVR_Mirza;
	int ocjenaTarik, ocjenaBojan, ocjenaMirza;
	double UkupnoTarik, UkupnoMirza, UkupnoBojan;
	int brojac=0;
	
	/*Tarik*/
	printf ("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf ("%lf", &I_Tarik);
	if(I_Tarik>20 || I_Tarik<0){
		printf("Neispravan broj bodova"); 
		return 0;
		
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &II_Tarik);
	if(II_Tarik>20 || II_Tarik<0){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	
	printf ("Prisustvo: ");
	scanf ("%lf", &PR_Tarik);
	if(PR_Tarik>10 || PR_Tarik<0){ 
		printf("Neispravan broj bodova"); 
		return 0;
	}
	
	printf ("Zadace: ");
	scanf ("%lf", &ZAD_Tarik);
	if(ZAD_Tarik>10 || ZAD_Tarik<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &ZAVR_Tarik);
	if(ZAVR_Tarik>40 || ZAVR_Tarik<0){
	printf("Neispravan broj bodova"); 
	return 0;
	}
	UkupnoTarik = I_Tarik + II_Tarik + PR_Tarik + ZAD_Tarik + ZAVR_Tarik;
	if(UkupnoTarik>=55) brojac++;
	
	if (UkupnoTarik<55) ocjenaTarik=5;
	if (UkupnoTarik>=55 && UkupnoTarik<65) ocjenaTarik=6;
	if (UkupnoTarik>=65 && UkupnoTarik<75) ocjenaTarik=7;
	if (UkupnoTarik>=75 && UkupnoTarik<85) ocjenaTarik=8;
	if (UkupnoTarik>=85 && UkupnoTarik<92) ocjenaTarik=9;
	if (UkupnoTarik>=92 && UkupnoTarik<100) ocjenaTarik=10;
	
	/*Bojan*/
	printf ("Unesite bodove za Bojana: ");
	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &I_Bojan);
	if(I_Bojan < 0 || I_Bojan > 20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &II_Bojan);
	if(II_Bojan < 0 || II_Bojan > 20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf", &PR_Bojan);
	if(PR_Bojan < 0 || PR_Bojan > 10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf", &ZAD_Bojan);
		if(ZAD_Bojan < 0 || ZAD_Bojan > 10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf("%lf", &ZAVR_Bojan);
		if(ZAVR_Bojan < 0 || ZAVR_Bojan > 40){
		printf ("Neispravan broj bodova");
		return 0;
	}
	UkupnoBojan = I_Bojan + II_Bojan + PR_Bojan + ZAD_Bojan + ZAVR_Bojan;
	if(UkupnoBojan>=55) brojac++;
	
	if (UkupnoBojan<55) ocjenaBojan = 5;
	if (UkupnoBojan>=55 && UkupnoBojan<65) ocjenaBojan=6;
	if (UkupnoBojan>=65 && UkupnoBojan<75) ocjenaBojan=7;
	if (UkupnoBojan>=75 && UkupnoBojan<85) ocjenaBojan=8;
	if (UkupnoBojan>=85 && UkupnoBojan<92) ocjenaBojan=9;
	if (UkupnoBojan>=92 && UkupnoBojan<100) ocjenaBojan=10;

	/*Mirza*/
	printf ("Unesite bodove za Mirzu: ");
	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &I_Mirza);
		if(I_Mirza < 0 || I_Mirza > 20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &II_Mirza);
		if(II_Mirza < 0 || II_Mirza > 20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf", &PR_Mirza);
		if(PR_Mirza < 0 || PR_Mirza > 10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf", &ZAD_Mirza);
		if(ZAD_Mirza < 0 || ZAD_Mirza > 10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &ZAVR_Mirza);
		if(ZAVR_Mirza < 0 || ZAVR_Mirza > 40){
		printf ("Neispravan broj bodova");
		return 0;
	}
	UkupnoMirza = I_Mirza + II_Mirza + PR_Mirza + ZAD_Mirza + ZAVR_Mirza;
	if(UkupnoMirza>=55) brojac++;
	
	if (UkupnoMirza<55) ocjenaMirza=5;
	if (UkupnoMirza>=55 && UkupnoMirza<65) ocjenaMirza=6;
	if (UkupnoMirza>=65 && UkupnoMirza<75) ocjenaMirza=7;
	if (UkupnoMirza>=75 && UkupnoMirza<85) ocjenaMirza=8;
	if (UkupnoMirza>=85 && UkupnoMirza<92) ocjenaMirza=9;
	if (UkupnoMirza>=92 && UkupnoMirza<=100) ocjenaMirza=10;
	
	if(brojac==0) printf("Nijedan student nije polozio.");
	if(brojac==1) printf("Jedan student je polozio.");
	if(brojac==2) printf("Dva studenta su polozila.");
	if(brojac==3) printf("Sva tri studenta su polozila.");
	
	if(ocjenaMirza==5 && ocjenaTarik==5 && ocjenaBojan==5) return 0;
	if((ocjenaBojan>=6 && ocjenaTarik<6 && ocjenaMirza<6) || (ocjenaMirza>=6 && ocjenaTarik<6 && ocjenaBojan<6) || (ocjenaTarik>=6 && ocjenaBojan<6 && ocjenaMirza<6)) return 0;
	if(brojac==3)
	{
	if ((ocjenaMirza == ocjenaTarik) && (ocjenaMirza == ocjenaBojan)){
		printf ("\nSva tri studenta imaju istu ocjenu.");
	}
	if ((ocjenaMirza == ocjenaBojan) && (ocjenaMirza != ocjenaTarik)){
		printf ("\nDva od tri studenta imaju istu ocjenu.");
	}
	if ((ocjenaTarik == ocjenaBojan) && (ocjenaTarik != ocjenaMirza)){
		printf ("\nDva od tri studenta imaju istu ocjenu.");
	}
	if ((ocjenaTarik == ocjenaMirza) && (ocjenaTarik != ocjenaBojan)){
		printf ("\nDva od tri studenta imaju istu ocjenu.");
	}
	if ((ocjenaBojan != ocjenaMirza) && (ocjenaBojan != ocjenaTarik) && (ocjenaMirza != ocjenaTarik)){
		printf ("\nSvaki student ima razlicitu ocjenu.");
	}}
	
	
	return 0;
}
