#include <stdio.h>

int main()
{
   double T1, T2, T3, T4, T5, B1, B2, B3, B4, B5, M1, M2, M3, M4, M5, O1, O2, O3;

   //*T A R I K*//
   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &T1);

   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &T2);

   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Prisustvo: ");
   scanf("%lf", &T3);

   if (T3 < 0 || T3 > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }


   printf("Zadace: ");
   scanf("%lf", &T4);

   if (T4 < 0 || T4 > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &T5);

   if (T5 < 0 || T5 > 40)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   O1 = T1 + T2 + T3 + T4 + T5;

   //* B O J A N*//
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%lf", &B1);

   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);

   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Prisustvo: ");
   scanf("%lf", &B3);

   if (B3 < 0 || B3 > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Zadace: ");
   scanf("%lf", &B4);

   if (B4 < 0 || B4 > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &B5);

   if (B5 < 0 || B5 > 40)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   O2 = B1 + B2 + B3 + B4 + B5;



   //* M I R Z A*//
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%lf", &M1);

   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &M2);

   if (M2 < 0 || M2 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Prisustvo: ");
   scanf("%lf", &M3);

   if (M3 < 0 || M3 > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   printf("Zadace: ");
   scanf("%lf", &M4);

   if (M4 < 0 || M4 > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &M5);

   if (M5 < 0 || M5 > 40)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   O3 = M1 + M2 + M3 + M4 + M5;


   if (O1 < 55 && O2 < 55 && O3 < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }

   else if (O1 >= 55 && O2 >= 55 && O3 >= 55)
   {
      printf("Sva tri studenta su polozila. \n");

      if ((O1 >= 55 && O1 < 65 && O2 >= 55 && O2 < 65 && O3 >= 55 && O3 < 65) ||
          (O1 >= 65 && O2 >= 65 && O3 >= 65 && O1 < 75 && O2 < 75 && O3 < 75) ||
          (O1 >= 75 && O2 >= 75 && O3 >= 75 && O1 < 85 && O2 < 85 && O3 < 85) ||
          (O1 >= 85 && O2 >= 85 && O3 >= 85 && O1 < 92 && O2 < 92 && O3 < 92) ||
          (O1 >= 92 && O2 >= 92 && O3 >= 92 && O1 <= 100 && O2 <= 100 && O3 <= 100))
      {
         printf("Sva tri studenta imaju istu ocjenu. \n");
      }


      if (O1 >= 55 && O1 < 65)
      {
         if ((O2 >= 65 && O2 < 75 && O3 >= 65 && O3 < 75) ||
             (O2 >= 75 && O2 < 85 && O3 >= 75 && O3 < 85) ||
             (O2 >= 85 && O2 < 92 && O3 >= 85 && O3 < 92) ||
             (O2 >= 92 && O2 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O2 >= 65 && O2 < 75 && O3 >= 75 && O3 < 85) ||
                  (O2 >= 75 && O2 < 85 && O3 >= 65 && O3 < 75) ||
                  (O2 >= 85 && O2 < 92 && O3 >= 92 && O3 <= 100) ||
                  (O2 >= 92 && O2 <= 100 && O3 >= 85 && O3 < 92))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O1 >= 65 && O1 < 75)
      {
         if ((O2 >= 55 && O2 < 65 && O3 >= 55 && O3 < 65) ||
             (O2 >= 75 && O2 < 85 && O3 >= 75 && O3 < 85) ||
             (O2 >= 85 && O2 < 92 && O3 >= 85 && O3 < 92) ||
             (O2 >= 92 && O2 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O2 >= 55 && O2 < 65 && O3 >= 75 && O3 < 85) ||
                  (O2 >= 75 && O2 < 85 && O3 >= 55 && O3 < 65) ||
                  (O2 >= 85 && O2 < 92 && O3 > 92 && O3 <= 100) ||
                  (O2 >= 92 && O2 <= 100 && O3 >= 55 && O3 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O1 >= 75 && O1 < 85)
      {
         if ((O2 >= 55 && O2 < 65 && O3 >= 55 && O3 < 65) ||
             (O2 >= 65 && O2 < 75 && O3 >= 65 && O3 < 75) ||
             (O2 >= 85 && O2 < 92 && O3 >= 85 && O3 < 92) ||
             (O2 >= 92 && O2 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O2 >= 65 && O2 < 75 && O3 >= 75 && O3 < 65) ||
                  (O2 >= 55 && O2 < 65 && O3 >= 65 && O3 < 75) ||
                  (O2 >= 85 && O2 < 92 && O3 > 92 && O3 <= 100) ||
                  (O2 >= 92 && O2 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O1 >= 85 && O1 < 92)
      {
         if ((O2 >= 55 && O2 < 65 && O3 >= 55 && O3 < 65) ||
             (O2 >= 65 && O2 < 75 && O3 >= 65 && O3 < 75) ||
             (O2 >= 75 && O2 < 85 && O3 >= 75 && O3 < 85) ||
             (O2 >= 92 && O2 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }


         else if ((O2 >= 65 && O2 < 75 && O3 >= 65 && O3 < 75) ||
                  (O2 >= 75 && O2 < 85 && O3 >= 65 && O3 < 75) ||
                  (O2 >= 55 && O2 < 65 && O3 > 92 && O3 <= 100) ||
                  (O2 >= 92 && O2 <= 100 && O3 >= 55 && O3 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O1 >= 92 && O1 <= 100)
      {
         if ((O2 >= 65 && O2 < 75 && O3 >= 65 && O3 < 75) ||
             (O2 >= 75 && O2 < 85 && O3 >= 75 && O3 < 85) ||
             (O2 >= 85 && O2 < 92 && O3 >= 85 && O3 < 92) ||
             (O2 >= 55 && O2 < 65 && O3 >= 55 && O3 < 65))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O2 >= 55 && O2 < 65 && O3 >= 75 && O3 < 85) ||
                  (O2 >= 75 && O2 < 85 && O3 >= 65 && O3 < 75) ||
                  (O2 >= 85 && O2 < 92 && O3 > 92 && O3 <= 100) ||
                  (O2 >= 65 && O2 <= 75 && O3 >= 55 && O3 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      if (O2 >= 55 && O2 < 65)
      {
         if ((O1 >= 65 && O1 < 75 && O3 >= 65 && O3 < 75) ||
             (O1 >= 75 && O1 < 85 && O3 >= 75 && O3 < 85) ||
             (O1 >= 85 && O1 < 92 && O3 >= 85 && O3 < 92) ||
             (O1 >= 92 && O1 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 65 && O1 < 75 && O3 >= 75 && O3 < 85) ||
                  (O1 >= 75 && O1 < 85 && O3 >= 65 && O3 < 75) ||
                  (O1 >= 85 && O1 < 92 && O3 >= 92 && O3 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O3 >= 85 && O3 < 92))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O2 >= 65 && O2 < 75)
      {
         if ((O1 >= 55 && O1 < 65 && O3 >= 55 && O3 < 65) ||
             (O1 >= 75 && O1 < 85 && O3 >= 75 && O3 < 85) ||
             (O1 >= 85 && O1 < 92 && O3 >= 85 && O3 < 92) ||
             (O1 >= 92 && O1 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 55 && O1 < 65 && O3 >= 75 && O3 < 85) ||
                  (O1 >= 75 && O1 < 85 && O3 >= 55 && O3 < 65) ||
                  (O1 >= 85 && O1 < 92 && O3 > 92 && O3 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O3 >= 55 && O3 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O2 >= 75 && O2 < 85)
      {
         if ((O1 >= 55 && O1 < 65 && O3 >= 55 && O3 < 65) ||
             (O1 >= 65 && O1 < 75 && O3 >= 65 && O3 < 75) ||
             (O1 >= 85 && O1 < 92 && O3 >= 85 && O3 < 92) ||
             (O1 >= 92 && O1 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 65 && O1 < 75 && O3 >= 75 && O3 < 65) ||
                  (O1 >= 55 && O1 < 65 && O3 >= 65 && O3 < 75) ||
                  (O1 >= 85 && O1 < 92 && O3 > 92 && O3 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O2 >= 85 && O2 < 92)
      {
         if ((O1 >= 55 && O1 < 65 && O3 >= 55 && O3 < 65) ||
             (O1 >= 65 && O1 < 75 && O3 >= 65 && O3 < 75) ||
             (O1 >= 75 && O1 < 85 && O3 >= 75 && O3 < 85) ||
             (O1 >= 92 && O1 <= 100 && O3 >= 92 && O3 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }


         else if ((O1 >= 65 && O1 < 75 && O3 >= 65 && O3 < 75) ||
                  (O1 >= 75 && O1 < 85 && O3 >= 65 && O3 < 75) ||
                  (O1 >= 55 && O1 < 65 && O3 > 92 && O3 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O3 >= 55 && O3 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O2 >= 92 && O2 <= 100)
      {
         if ((O1 >= 65 && O1 < 75 && O3 >= 65 && O3 < 75) ||
             (O1 >= 75 && O1 < 85 && O3 >= 75 && O3 < 85) ||
             (O1 >= 85 && O1 < 92 && O3 >= 85 && O3 < 92) ||
             (O1 >= 55 && O1 < 65 && O3 >= 55 && O3 < 65))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 55 && O1 < 65 && O3 >= 75 && O3 < 85) ||
                  (O1 >= 75 && O1 < 85 && O3 >= 65 && O3 < 75) ||
                  (O1 >= 85 && O1 < 92 && O3 > 92 && O3 <= 100) ||
                  (O1 >= 65 && O1 <= 75 && O3 >= 55 && O3 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }


      if (O3 >= 55 && O3 < 65)
      {
         if ((O1 >= 65 && O1 < 75 && O2 >= 65 && O2 < 75) ||
             (O1 >= 75 && O1 < 85 && O2 >= 75 && O2 < 85) ||
             (O1 >= 85 && O1 < 92 && O2 >= 85 && O2 < 92) ||
             (O1 >= 92 && O1 <= 100 && O2 >= 92 && O2 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 65 && O1 < 75 && O2 >= 75 && O2 < 85) ||
                  (O1 >= 75 && O1 < 85 && O2 >= 65 && O2 < 75) ||
                  (O1 >= 85 && O1 < 92 && O2 >= 92 && O2 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O2 >= 85 && O2 < 92))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O3 >= 65 && O3 < 75)
      {
         if ((O1 >= 55 && O1 < 65 && O2 >= 55 && O2 < 65) ||
             (O1 >= 75 && O1 < 85 && O2 >= 75 && O2 < 85) ||
             (O1 >= 85 && O1 < 92 && O2 >= 85 && O2 < 92) ||
             (O1 >= 92 && O1 <= 100 && O2 >= 92 && O2 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 55 && O1 < 65 && O2 >= 75 && O2 < 85) ||
                  (O1 >= 75 && O1 < 85 && O2 >= 55 && O2 < 65) ||
                  (O1 >= 85 && O1 < 92 && O2 > 92 && O2 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O2 >= 55 && O2 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O3 >= 75 && O3 < 85)
      {
         if ((O1 >= 55 && O1 < 65 && O2 >= 55 && O2 < 65) ||
             (O1 >= 65 && O1 < 75 && O2 >= 65 && O2 < 75) ||
             (O1 >= 85 && O1 < 92 && O2 >= 85 && O2 < 92) ||
             (O1 >= 92 && O1 <= 100 && O2 >= 92 && O2 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O1 >= 65 && O1 < 75 && O2 >= 75 && O2 < 65) ||
                  (O1 >= 55 && O1 < 65 && O2 >= 65 && O2 < 75) ||
                  (O1 >= 85 && O1 < 92 && O2 > 92 && O2 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O2 >= 92 && O2 <= 100))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O3 >= 85 && O3 < 92)
      {
         if ((O1 >= 55 && O1 < 65 && O2 >= 55 && O2 < 65) ||
             (O1 >= 65 && O1 < 75 && O2 >= 65 && O2 < 75) ||
             (O1 >= 75 && O1 < 85 && O2 >= 75 && O2 < 85) ||
             (O1 >= 92 && O1 <= 100 && O2 >= 92 && O2 <= 100))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }


         else if ((O1 >= 65 && O1 < 75 && O2 >= 65 && O2 < 75) ||
                  (O1 >= 75 && O1 < 85 && O2 >= 65 && O2 < 75) ||
                  (O1 >= 55 && O1 < 65 && O2 > 92 && O2 <= 100) ||
                  (O1 >= 92 && O1 <= 100 && O2 >= 55 && O2 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }

      else if (O3 >= 92 && O3 <= 100)
      {
         if ((O2 >= 65 && O2 < 75 && O1 >= 65 && O1 < 75) ||
             (O2 >= 75 && O2 < 85 && O1 >= 75 && O1 < 85) ||
             (O2 >= 85 && O2 < 92 && O1 >= 85 && O1 < 92) ||
             (O2 >= 55 && O2 < 65 && O1 >= 55 && O1 < 65))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }

         else if ((O2 >= 55 && O2 < 65 && O3 >= 75 && O1 < 85) ||
                  (O2 >= 75 && O2 < 85 && O1 >= 65 && O1 < 75) ||
                  (O2 >= 85 && O2 < 92 && O1 > 92 && O1 <= 100) ||
                  (O2 >= 65 && O2 <= 75 && O1 >= 55 && O1 < 65))
         {
            printf("Svaki student ima razlicitu ocjenu.");
            return(1);
         }
      }
   }
   else if ((O1 >= 55 && O2 < 55 && O3 < 55) || (O1 < 55 && O2 >= 55 && O3 < 55) || (O1 < 55 && O2 < 55 && O3 >= 55))
   {
      printf("Jedan student je polozio.\n");
   }

   else if ((O1 >= 55 && O2 >= 55 && O3 < 55) || (O1 >= 55 && O2 < 55 && O3 >= 55) || (O1 < 55 && O2 >= 55 && O3 >= 55))
   {
      printf("Dva studenta su polozila. \n");
   }


   return(0);
}
