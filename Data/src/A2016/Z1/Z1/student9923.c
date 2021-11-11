#include <stdio.h>

int main()
{
   double TIp, TIIp, Tp, Tz, Tzi, To, BIp, BIIp, Bp, Bz, Bzi, Bo, MIp, MIIp, Mp, Mz, Mzi, Mo;
   int    ocj1, ocj2, ocj3;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &TIp);
   if (TIp < 0 || TIp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &TIIp);
   if (TIIp < 0 || TIIp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Tp);
   if (Tp < 0 || Tp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Tz);
   if (Tz < 0 || Tz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Tzi);
   if (Tzi < 0 || Tzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   if ((TIp >= 0 && TIp <= 20) && (TIIp >= 0 && TIIp <= 20) && (Tp >= 0 && Tp <= 10) && (Tz >= 0 && Tz <= 10) && (Tzi >= 0 && Tzi <= 40))
   {
      To = (TIp + TIIp + Tp + Tz + Tzi);
   }
   if (To < 55)
   {
      ocj1 = 5;
   }
   else if (To >= 55 && To < 65)
   {
      ocj1 = 6;
   }
   else if (To >= 65 && To < 75)
   {
      ocj1 = 7;
   }
   else if (To >= 75 && To < 85)
   {
      ocj1 = 8;
   }
   else if (To >= 85 && To < 92)
   {
      ocj1 = 9;
   }
   else if (To >= 92 && To <= 100)
   {
      ocj1 = 10;
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &BIp);
   if (BIp < 0 || BIp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BIIp);
   if (BIIp < 0 || BIIp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Bp);
   if (Bp < 0 || Bp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Bz);
   if (Bz < 0 || Bz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Bzi);
   if (Bzi < 0 || Bzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   if ((BIp >= 0 && BIp <= 20) && (BIIp >= 0 && BIIp <= 20) && (Bp >= 0 && Bp <= 10) && (Bz >= 0 && Bz <= 10) && (Bzi >= 0 && Bzi <= 40))
   {
      Bo = BIp + BIIp + Bp + Bz + Bzi;
   }
   if (Bo < 55)
   {
      ocj2 = 5;
   }
   else if (Bo >= 55 && Bo < 65)
   {
      ocj2 = 6;
   }
   else if (Bo >= 65 && Bo < 75)
   {
      ocj2 = 7;
   }
   else if (Bo >= 75 && Bo < 85)
   {
      ocj2 = 8;
   }
   else if (Bo >= 85 && Bo < 92)
   {
      ocj2 = 9;
   }
   else if (Bo >= 92 && Bo <= 100)
   {
      ocj2 = 10;
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &MIp);
   if (MIp < 0 || MIp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MIIp);
   if (MIIp < 0 || MIIp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Mp);
   if (Mp < 0 || Mp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Mz);
   if (Mz < 0 || Mz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Mzi);
   if (Mzi < 0 || Mzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   if ((MIp >= 0 && MIp <= 20) && (MIIp >= 0 && MIIp <= 20) && (Mp >= 0 && Mp <= 10) && (Mz >= 0 && Mz <= 10) && (Mzi >= 0 && Mzi <= 40))
   {
      Mo = MIp + MIIp + Mp + Mz + Mzi;
   }
   if (Mo < 55)
   {
      ocj3 = 5;
   }
   else if (Mo >= 55 && Mo < 65)
   {
      ocj3 = 6;
   }
   else if (Mo >= 65 && Mo < 75)
   {
      ocj3 = 7;
   }
   else if (Mo >= 75 && Mo < 85)
   {
      ocj3 = 8;
   }
   else if (Mo >= 85 && Mo < 92)
   {
      ocj3 = 9;
   }
   else if (Mo >= 92 && Mo <= 100)
   {
      ocj3 = 10;
   }

   if (ocj1 >= 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("Sva tri studenta su polozila.");
   }
   else if (ocj1 >= 6 && ocj2 >= 6 && ocj3 < 6)
   {
      printf("Dva studenta su polozila.");
   }
   else if (ocj1 < 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("Dva studenta su polozila.");
   }
   else if (ocj1 >= 6 && ocj2 < 6 && ocj3 >= 6)
   {
      printf("Dva studenta su polozila.");
   }
   else if (ocj1 >= 6 && ocj2 < 6 && ocj3 < 6)
   {
      printf("Jedan student je polozio.");
   }
   else if (ocj1 < 6 && ocj2 >= 6 && ocj3 < 6)
   {
      printf("Jedan student je polozio.");
   }
   else if (ocj1 < 6 && ocj2 < 6 && ocj3 >= 6)
   {
      printf("Jedan student je polozio.");
   }
   else if (ocj1 < 6 && ocj2 < 6 && ocj3 < 6)
   {
      printf("Nijedan student nije polozio.");
   }

   if (ocj1 == ocj2 && ocj2 == ocj3 && ocj1 == ocj3 && ocj1 >= 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else if (ocj1 == ocj2 && ocj2 != ocj3 && ocj1 >= 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (ocj1 == ocj3 && ocj2 != ocj1 && ocj1 >= 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (ocj2 == ocj3 && ocj2 != ocj1 && ocj1 >= 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (ocj1 != ocj2 && ocj2 != ocj3 && ocj1 != ocj3 && ocj1 >= 6 && ocj2 >= 6 && ocj3 >= 6)
   {
      printf("\nSvaki student ima razlicitu ocjenu. ");
   }

   return(0);
}
