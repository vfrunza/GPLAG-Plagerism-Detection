#include <stdio.h>

int main()
{
   double A1 = 0, B1 = 0, C1 = 0, D1 = 0, E1 = 0, A2 = 0, B2 = 0, C2 = 0, D2 = 0, E2 = 0, A3 = 0, B3 = 0, C3 = 0, D3 = 0, E3 = 0, X = 0, Y = 0, Z = 0;



   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &A1);
   if (A1 < 0 || A1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &C1);
   if (C1 < 0 || C1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &D1);
   if (D1 < 0 || D1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &E1);
   if (E1 < 0 || E1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &A2);
   if (A2 < 0 || A2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &C2);
   if (C2 < 0 || C2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &D2);
   if (D2 < 0 || D2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &E2);
   if (E2 < 0 || E2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &A3);
   if (A3 < 0 || A3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B3);
   if (B3 < 0 || B3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &C3);
   if (C3 < 0 || C3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &D3);
   if (D3 < 0 || D3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &E3);
   if (E3 < 0 || E3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   X = A1 + B1 + C1 + D1 + E1;
   Y = A2 + B2 + C2 + D2 + E2;
   Z = A3 + B3 + C3 + D3 + E3;

   if (X < 55 && Y < 55 && Z < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((X >= 55 && Y < 55 && Z < 55) || (X < 55 && Y >= 55 && Z < 55) || (X < 55 && Y < 55 && Z >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((X >= 55 && Y >= 55 && Z < 55) || (X < 55 && Y >= 55 && Z >= 55) || (X >= 55 && Y < 55 && Z >= 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
   }

   int ocjenaT = 0, ocjenaB = 0, ocjenaM = 0;

   if (X >= 55 && X < 65)
   {
      ocjenaT = 6;
   }
   else if (X >= 65 && X < 75)
   {
      ocjenaT = 7;
   }
   else if (X >= 75 && X < 85)
   {
      ocjenaT = 8;
   }
   else if (X >= 85 && X < 92)
   {
      ocjenaT = 9;
   }
   else if (X >= 92 && X <= 100)
   {
      ocjenaT = 10;
   }

   if (Y >= 55 && Y < 65)
   {
      ocjenaB = 6;
   }
   else if (Y >= 65 && Y < 75)
   {
      ocjenaB = 7;
   }
   else if (Y >= 75 && Y < 85)
   {
      ocjenaB = 8;
   }
   else if (Y >= 85 && Y < 92)
   {
      ocjenaB = 9;
   }
   else if (Y >= 92 && Y <= 100)
   {
      ocjenaB = 10;
   }

   if (Z >= 55 && Z < 65)
   {
      ocjenaM = 6;
   }
   else if (Z >= 65 && Z < 75)
   {
      ocjenaM = 7;
   }
   else if (Z >= 75 && Z < 85)
   {
      ocjenaM = 8;
   }
   else if (Z >= 85 && Z < 92)
   {
      ocjenaM = 9;
   }
   else if (Z >= 92 && Z <= 100)
   {
      ocjenaM = 10;
   }
   if (ocjenaM >= 6 && ocjenaB >= 6 && ocjenaT >= 6)
   {
      if (ocjenaM == ocjenaB && ocjenaT == ocjenaM && ocjenaT == ocjenaB)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (ocjenaM != ocjenaB && ocjenaB != ocjenaT && ocjenaM != ocjenaT)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }

   return(0);
}
