#include <stdio.h>
int main()
{
   double Tb, Bb, Mb, p1, p2, P, dz, zi, Bp1, Bp2, BP, Bdz, Bzi, Mp1, Mp2, MP, Mdz, Mzi;
   int    oT, oB, oM;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 > 20 || p1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 > 20 || p2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P);
   if (P > 10 || P < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dz);
   if (dz > 10 || dz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi);
   if (zi > 40 || zi < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   Tb = p1 + p2 + P + dz + zi;

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Bp1);
   if (Bp1 > 20 || Bp1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &Bp2);
   if (Bp2 > 20 || Bp2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BP);
   if (BP > 10 || BP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Bdz);
   if (Bdz > 10 || Bdz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Bzi);
   if (Bzi > 40 || Bzi < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   Bb = Bp1 + Bp2 + BP + Bdz + Bzi;

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Mp1);
   if (Mp1 > 20 || Mp1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &Mp2);
   if (Mp2 > 20 || Mp2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MP);
   if (MP > 10 || MP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Mdz);
   if (Mdz > 10 || Mdz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Mzi);
   if (Mzi > 40 || Mzi < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   Mb = Mp1 + Mp1 + MP + Mdz + Mzi;

   if (Tb >= 55 && Tb < 65)
   {
      oT = 6;
   }
   else if (Tb >= 65 && Tb < 75)
   {
      oT = 7;
   }
   else if (Tb >= 75 && Tb < 85)
   {
      oT = 8;
   }
   else if (Tb >= 85 && Tb < 92)
   {
      oT = 9;
   }
   else if (Tb >= 92 && Tb <= 100)
   {
      oT = 10;
   }
   else
   {
      oT = 0;
   }
   if (Bb >= 55 && Bb < 65)
   {
      oB = 6;
   }
   else if (Bb >= 65 && Bb < 75)
   {
      oB = 7;
   }
   else if (Bb >= 75 && Bb < 85)
   {
      oB = 8;
   }
   else if (Bb >= 85 && Bb < 92)
   {
      oB = 9;
   }
   else if (Bb >= 92 && Bb <= 100)
   {
      oB = 10;
   }
   else
   {
      oB = 0;
   }
   if (Mb >= 55 && Mb < 65)
   {
      oM = 6;
   }
   else if (Mb >= 65 && Mb < 75)
   {
      oM = 7;
   }
   else if (Mb >= 75 && Mb < 85)
   {
      oM = 8;
   }
   else if (Mb >= 85 && Mb < 92)
   {
      oM = 9;
   }
   else if (Mb >= 92 && Mb <= 100)
   {
      oM = 10;
   }
   else
   {
      oM = 0;
   }
   if (oT < 6 && oB < 6 && oM < 6)
   {
      printf("Nijedan student nije polozio.");
   }
   if (Tb >= 55 && Bb >= 55 && Mb >= 55)
   {
      printf("Sva tri studenta su polozila.");
      if (oT == oB && oB == oM)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (oT == oB || oB == oM || oM == oT)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   if ((Tb >= 55 && Bb >= 55 && Mb < 55) || (Tb < 55 && Bb >= 55 && Mb >= 55) || (Tb >= 55 && Bb < 55 && Mb >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   if ((Tb >= 55 && Bb < 55 && Mb < 55) || (Tb < 55 && Bb >= 55 && Mb < 55) || (Tb < 55 && Bb < 55 && Mb >= 55))
   {
      printf("Jedan student je polozio.");
   }

   return(0);
}
