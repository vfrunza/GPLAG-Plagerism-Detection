#include <stdio.h>

int main()
{
   float prvi1, drugi1, prisustvo1, zadaca1, zavrsni1;
   float prvi2, drugi2, prisustvo2, zadaca2, zavrsni2;
   float prvi3, drugi3, prisustvo3, zadaca3, zavrsni3;
   float suma1, suma2, suma3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi1);
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi1);
   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 < 0.0 || prisustvo1 > 10)
   {
      return(printf("Neispravan broj bodova"));
   }
   printf("Zadace: ");
   scanf("%f", &zadaca1);
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni1);
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi2);
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi2);
   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0.0 || prisustvo2 > 10)
   {
      return(printf("Neispravan broj bodova"));
   }
   printf("Zadace: ");
   scanf("%f", &zadaca2);
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni2);
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi3);
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi3);
   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 < 0.0 || prisustvo3 > 10)
   {
      return(printf("Neispravan broj bodova"));
   }
   printf("Zadace: ");
   scanf("%f", &zadaca3);
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni3);
   suma1 = prvi1 + drugi1 + prisustvo1 + zadaca1 + zavrsni1;
   suma2 = prvi2 + drugi2 + prisustvo2 + zadaca2 + zavrsni2;
   suma3 = prvi3 + drugi3 + prisustvo3 + zadaca3 + zavrsni3;

   if (suma1 < 55 && suma2 < 55 && suma3 < 55)
   {
      printf("Nijedan student nije polozio. ");
   }
   if (suma1 >= 55 && suma2 < 55 && suma3 < 55)
   {
      printf("Jedan student je polozio. ");
   }
   if (suma1 < 55 && suma2 >= 55 && suma3 < 55)
   {
      printf("Jedan student je polozio. ");
   }
   if (suma1 < 55 && suma2 < 55 && suma3 >= 55)
   {
      printf("Jedan student je polozio. ");
   }
   if (suma1 >= 55 && suma2 >= 55 && suma3 < 55)
   {
      printf("Dva studenta su polozila. ");
   }
   if (suma1 < 55 && suma2 >= 55 && suma3 >= 55)
   {
      printf("Dva studenta su polozila. ");
   }
   if (suma1 >= 55 && suma2 < 55 && suma3 >= 55)
   {
      printf("Dva studenta su polozila. ");
   }

   if (suma1 >= 55 && suma2 >= 55 && suma3 >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (suma1 != suma2 && suma1 != suma3)
      {
         printf("Svaki student ima razlicitu ocjenu. ");
      }
      else if (suma1 == suma2 && suma1 != suma3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (suma1 == suma3 && suma1 != suma2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (suma2 == suma3 && suma2 != suma1)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (suma1 == suma2 && suma1 == suma3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}
