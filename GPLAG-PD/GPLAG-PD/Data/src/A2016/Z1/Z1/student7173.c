#include <stdio.h>

int main()
{
   float bodovi, t, b, m, count, e;
   int   ot, ob, om;

   e = -0.0001;
   t = b = m = count = 0;

   /*Unos za Tarika*/
   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   t += bodovi;
   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   t += bodovi;
   printf("Prisustvo: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   t += bodovi;
   printf("Zadace: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   t += bodovi;
   printf("Zavrsni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   t += bodovi;

   /*Unos Bojan*/
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b += bodovi;
   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b += bodovi;
   printf("Prisustvo: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b += bodovi;
   printf("Zadace: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b += bodovi;
   printf("Zavrsni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b += bodovi;

   /*Unos Mirza*/
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   m += bodovi;
   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   m += bodovi;
   printf("Prisustvo: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   m += bodovi;
   printf("Zadace: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   m += bodovi;
   printf("Zavrsni ispit: ");
   scanf("%f", &bodovi);
   if (bodovi < 0 || bodovi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   m += bodovi;

   /*Ocjena Tarik*/
   if (t - 55 < e)
   {
      ot = 0;
   }
   else if (t < 65)
   {
      ot = 1;
   }
   else if (t < 75)
   {
      ot = 3;
   }
   else if (t < 85)
   {
      ot = 4;
   }
   else if (t < 92)
   {
      ot = 5;
   }

   /*Ocjena Bojan*/
   if (b < 55)
   {
      ob = 0;
   }
   else if (b < 65)
   {
      ob = 1;
   }
   else if (b < 75)
   {
      ob = 3;
   }
   else if (b < 85)
   {
      ob = 4;
   }
   else if (b < 92)
   {
      ob = 5;
   }

   /*Ocjena Mirza*/
   if (m < 55)
   {
      om = 0;
   }
   else if (m < 65)
   {
      om = 1;
   }
   else if (m < 75)
   {
      om = 3;
   }
   else if (m < 85)
   {
      om = 4;
   }
   else if (m < 92)
   {
      om = 5;
   }


   /*Count*/
   count = 0;
   if (ot > 0)
   {
      count += 1;
   }

   if (ob > 0)
   {
      count += 1;
   }

   if (om > 0)
   {
      count += 1;
   }

   if (count == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (count == 1)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (count == 2)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if (count == 3)
   {
      if (ot == ob)
      {
         if (ot == om)
         {
            printf("Sva tri studenta imaju istu ocjenu.");
         }
         else
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }
      }
      else if (ot == om || ob == om)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
