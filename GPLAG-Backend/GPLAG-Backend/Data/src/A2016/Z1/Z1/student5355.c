#include <stdio.h>
#include <stdlib.h>
int main()
{
	float bodovi_tarik1, bodovi_bojan1, bodovi_mirza1, bodovi_tarik2, bodovi_bojan2, bodovi_mirza2,
	prisustvo_tarik, prisustvo_bojan, prisustvo_mirza, zadace_tarik, zadace_bojan, zadace_mirza,
   zavrsni_tarik, zavrsni_bojan, zavrsni_mirza, suma_tarik=0, suma_bojan=0, suma_mirza=0,
   ocjena_tarik, ocjena_bojan, ocjena_mirza;
   int broj_polozenih=0 ;
   
   printf("Unesite bodove za Tarika: ");
   
   printf("I prvi parcijalni ispit: ");
   scanf("%f", &bodovi_tarik1);
   if (bodovi_tarik1 < 0 || bodovi_tarik1 > 20) {
      printf("Neispravan broj bodoa");
      return 0;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi_tarik2);
   if (bodovi_tarik2<0 || bodovi_tarik2>20) {
      printf("Neispravan broj bodova");
      return 0;
   }
   printf ("prisustvo: ");
   scanf("%f", &prisustvo_tarik);
   if (prisustvo_tarik < 0 || prisustvo_tarik >10){
      printf("Neispravan broj bodova");
      return 0;
   }
   printf ("Zadace: ");
   scanf ("%f", &zadace_tarik);
   if (zadace_tarik < 0 || zadace_tarik >10){ 
      printf ("Neispravan broj bodova");
      return 0;
   }
    printf("Zavrsni: \n");
    scanf ("%f", &zavrsni_tarik);
    if (zavrsni_tarik < 0 || zavrsni_tarik > 40) {
       printf ("Neispravan broj bodova");
       return 0;
    }
    
    suma_tarik = bodovi_tarik1 + bodovi_tarik2 + zadace_tarik + prisustvo_tarik + zavrsni_tarik;
    
    
     printf("Unesite bodove za Bojana: ");
   printf("I prvi parcijalni ispit: ");
   scanf("%f", &bodovi_bojan1);
   if (bodovi_bojan1 < 0 || bodovi_bojan1 > 20) {
      printf("Neispravan broj bodoa");
      return 0;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi_bojan2);
   if (bodovi_bojan2<0 || bodovi_bojan2 > 20) {
      printf("Neispravan broj bodova");
      return 0;
   }
   printf ("Prisustvo: ");
   scanf("%f", &prisustvo_bojan);
   if (prisustvo_bojan < 0 || prisustvo_bojan >10){
      printf("Neispravan broj bodova");
      return 0;
   }
   printf ("Zadace: ");
   scanf ("%f", &zadace_bojan);
   if (zadace_bojan < 0 || zadace_bojan >10){ 
      printf ("Neispravan broj bodova");
      return 0;
   }
    printf("Zavrsni: ");
    scanf ("%f", &zavrsni_bojan);
    if (zavrsni_bojan < 0 || zavrsni_bojan > 40) {
       printf ("Neispravan broj bodova");
       return 0;
    }
    
    suma_bojan = bodovi_bojan1 + bodovi_bojan2 + zadace_bojan + prisustvo_bojan + zavrsni_bojan;
    
    
     printf("Unesite bodove za Mirzu: ");
   printf("I prvi parcijalni ispit: ");
   scanf("%f", &bodovi_mirza1);
   if (bodovi_mirza1 < 0 || bodovi_mirza1 > 20) {
      printf("Neispravan broj bodoa");
      return 0;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi_mirza2);
   if (bodovi_mirza2<0 || bodovi_mirza2>20) {
      printf("Neispravan broj bodova");
      return 0;
   }
   printf ("prisustvo: ");
   scanf("%f", &prisustvo_mirza);
   if (prisustvo_mirza < 0 || prisustvo_mirza >10){
      printf("Neispravan broj bodova");
      return 0;
   }
   printf ("Zadace: ");
   scanf ("%f", &zadace_mirza);
   if (zadace_mirza < 0 || zadace_mirza >10){ 
      printf ("Neispravan broj bodova");
      return 0;
   }
    printf("Zavrsni: ");
    scanf ("%f", &zavrsni_mirza);
    if (zavrsni_mirza < 0 || zavrsni_mirza > 40) {
       printf ("Neispravan broj bodova");
       return 0;
    }
    
    suma_mirza = bodovi_mirza1 + bodovi_mirza2 + zadace_mirza + prisustvo_mirza + zavrsni_mirza;
    
    if (suma_tarik > 55) broj_polozenih++;
    if (suma_bojan > 55) broj_polozenih++;
    if (suma_mirza > 55) broj_polozenih++;
    
    switch (broj_polozenih) {
       case 0: printf ("Nijedan student nije polozio \n");
       break;
       case 1: printf ("Jedan student je polozio \n");
       break;
       case 2: printf ("Dva studenta su polozila \n");
       break;
       case 3: printf ("Sva tri studenta su polozila \n");
       break;
    }
    
      if (suma_tarik >= 55 && suma_tarik < 65) ocjena_tarik=6;
      if (suma_tarik >= 65 && suma_tarik < 75) ocjena_tarik=7;
      if (suma_tarik >= 75 && suma_tarik < 85) ocjena_tarik=8;
      if (suma_tarik >= 85 && suma_tarik < 92) ocjena_tarik=9;
      if (suma_tarik >= 92 && suma_tarik < 100) ocjena_tarik=10;
      
      if (suma_bojan >= 55 && suma_bojan < 65) ocjena_bojan=6;
      if (suma_bojan >= 65 && suma_bojan < 75) ocjena_bojan=7;
      if (suma_bojan >= 75 && suma_bojan < 85) ocjena_bojan=8;
      if (suma_bojan >= 85 && suma_bojan < 92) ocjena_bojan=9;
      if (suma_bojan >= 92 && suma_bojan < 100) ocjena_bojan=10;
      
      if (suma_mirza >= 55 && suma_mirza < 65) ocjena_mirza=6;
      if (suma_mirza >= 65 && suma_mirza < 75) ocjena_mirza=7;
      if (suma_mirza >= 75 && suma_mirza < 85) ocjena_mirza=8;
      if (suma_mirza >= 85 && suma_mirza < 92) ocjena_mirza=9;
      if (suma_mirza >= 92 && suma_mirza < 100) ocjena_mirza=10;
      
      if (broj_polozenih == 3) {
         if(ocjena_tarik == ocjena_bojan == ocjena_mirza) printf("Sva tri studenta imaju istu ocjenu \n");
         else if ((ocjena_tarik == ocjena_bojan) || (ocjena_tarik == ocjena_mirza) || (ocjena_bojan == ocjena_mirza))
         printf ("Dva od tri studenta imaju istu ocjenu \n");
         else printf ("Svaki student ima razlicitu ocjenu \n");}
         
         return 0;
      }
      
      
      
      
      
      
      
      

      