#include <stdio.h>
void Status();

int main()
{
   float Iparc, IIparc, suma, prisustvo, zadace, zavrsni, sumaBojan, sumaTarik, sumaMirza;

   printf("Unesite bodove za Tarika:\n");
   printf("I.parcijalni ispit:\n");
   scanf("%f", &Iparc);
   printf("II.parcijalni ispit:\n");
   scanf("%f", &IIparc);
   printf("Prisustvo:\n");
   scanf("%f", &prisustvo);
   printf("Zadace:\n");
   scanf("%f", &zadace);
   printf("Zavrsni ispit:\n");
   scanf("%f", &zavrsni);

   sumaTarik = Iparc + IIparc + prisustvo + zadace + zavrsni;
   suma      = sumaTarik;

   suma = 0;

   printf("Unesite bodove za Bojana:\n");
   printf("I. parcijalni ispit:\n");
   scanf("%f", &Iparc);
   printf("II. parcijani ispit:\n");
   scanf("%f", &IIparc);
   printf("Prisustvo:\n");
   scanf("%f", &prisustvo);
   printf("Zadace:\n");
   scanf("%f", &zadace);
   printf("Zavrsni ispit:\n");
   scanf("%f", &zavrsni);

   sumaBojan = Iparc + IIparc + prisustvo + zadace + zavrsni;
   suma      = sumaBojan;

   suma = 0;


   printf("Unesite bodove za Mirzu:\n");
   printf("I.parcijani ispit:\n");
   scanf("%f", &Iparc);
   printf("II.parcijalni ispit:\n");
   scanf("%f", &IIparc);
   printf("Prisustvo:\n");
   scanf("%f", &prisustvo);
   printf("Zadace:\n");
   scanf("%f", &zadace);
   printf("Zavrsni ispit:\n");
   scanf("%f", &zavrsni);


   sumaMirza = Iparc + IIparc + prisustvo + zadace + zavrsni;
   suma      = sumaMirza;

   suma = 0;


   if (sumaMirza + sumaTarik + sumaBojan < 168)
   {
      printf("Nijedan student nije polozio.");
   }
   if (sumaMirza > 55 || sumaBojan > 55)
   {
      printf("Jedan student je polozio.");
   }
   if (sumaMirza > 55 || sumaTarik > 55)
   {
      printf("Jedan student je polozio.");
   }
   if (sumaBojan > 55 || sumaTarik > 55)
   {
      printf("Jedan student je polozio");
   }

   if (sumaMirza > 55 && sumaBojan > 55 && sumaTarik > 55)
   {
      printf("Tri studenta su polozila.");
   }



   if (suma < 55)
   {
      printf("Student pao.");
   }
   if (suma > 55 && suma < 65)
   {
      printf("Ocjena 6");
   }
   if (suma > 65 && suma < 75)
   {
      printf("Ocjena 7");
   }
   if (suma > 75 && suma < 85)
   {
      printf("Ocjena 8");
   }
   if (suma > 85 && suma < 92)
   {
      printf("Ocjena 9");
   }
   if (suma > 92 && suma < 100)
   {
      printf("Ocjena 10");
   }
   else
   {
      printf("Pogresan unos");
   }

   return(0);
}
