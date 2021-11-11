#include <stdio.h>

int main()
{
   double p1, p2, p3, p4, p5, U1, U2, U3;
   int    O1, O2, O3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if (p3 < 0 || p3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &p4);
   if (p4 < 0 || p4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &p5);
   if (p5 < 0 || p5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   U1 = p1 + p2 + p3 + p4 + p5;
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if (p3 < 0 || p3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &p4);
   if (p4 < 0 || p4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &p5);
   if (p5 < 0 || p5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   U2 = p1 + p2 + p3 + p4 + p5;
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if (p3 < 0 || p3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &p4);
   if (p4 < 0 || p4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &p5);
   if (p5 < 0 || p5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   U3 = p1 + p2 + p3 + p4 + p5;
   if (U1 < 55)
   {
      O1 = 5;
   }
   else if (U1 >= 55 && U1 < 65)
   {
      O1 = 6;
   }
   else if (U1 >= 65 && U1 < 75)
   {
      O1 = 7;
   }
   else if (U1 >= 75 && U1 < 85)
   {
      O1 = 8;
   }
   else if (U1 >= 85 && U1 < 92)
   {
      O1 = 9;
   }
   else if (U1 >= 92 && U1 <= 100)
   {
      O1 = 10;
   }
   if (U2 < 55)
   {
      O2 = 5;
   }
   else if (U2 >= 55 && U2 < 65)
   {
      O2 = 6;
   }
   else if (U2 >= 65 && U2 < 75)
   {
      O2 = 7;
   }
   else if (U2 >= 75 && U2 < 85)
   {
      O2 = 8;
   }
   else if (U2 >= 85 && U2 < 92)
   {
      O2 = 9;
   }
   else if (U2 >= 92 && U2 <= 100)
   {
      O2 = 10;
   }
   if (U3 < 55)
   {
      O3 = 5;
   }
   else if (U3 >= 55 && U3 < 65)
   {
      O3 = 6;
   }
   else if (U3 >= 65 && U3 < 75)
   {
      O3 = 7;
   }
   else if (U3 >= 75 && U3 < 85)
   {
      O3 = 8;
   }
   else if (U3 >= 85 && U3 < 92)
   {
      O3 = 9;
   }
   else if (U3 >= 92 && U3 <= 100)
   {
      O3 = 10;
   }
   if (O1 == 5 && O2 == 5 && O3 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((O1 == 5 && O2 == 5 && O3 != 5) || (O1 == 5 && O2 != 5 && O3 == 5) || (O1 != 5 && O2 == 5 && O3 == 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((O1 != 5 && O2 == 5 && O3 != 5) || (O1 != 5 && O2 != 5 && O3 == 5) || (O1 == 5 && O2 != 5 && O3 != 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (O1 != 5 && O2 != 5 && O3 != 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (O1 == O2 && O2 == O3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((O1 == O2 && O2 != O3) || (O1 != O2 && O2 == O3) || (O1 == O3 && O2 != O3))
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
