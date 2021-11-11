#include <stdio.h>

int main()
{
   double Ti, Tii, Tp, Tdz, Tz, Bi, Bii, Bp, Bdz, Bz, Mi, Mii, Mp, Mdz, Mz, Z1, Z2, Z3, Ocj1, Ocj2, Ocj3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Ti);
   if (Ti > 20 || Ti < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &Tii);
   if (Tii > 20 || Tii < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Tp);
   if (Tp > 10 || Tp < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Tdz);
   if (Tdz > 10 || Tdz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Tz);
   if (Tz > 40 || Tz < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   Z1 = Ti + Tii + Tp + Tdz + Tz;
   if (Z1 >= 55 && Z1 < 65)
   {
      Ocj1 = 6;
   }
   if (Z1 >= 65 && Z1 < 75)
   {
      Ocj1 = 7;
   }
   if (Z1 >= 75 && Z1 < 85)
   {
      Ocj1 = 8;
   }
   if (Z1 >= 85 && Z1 < 92)
   {
      Ocj1 = 9;
   }
   if (Z1 >= 92 && Z1 <= 100)
   {
      Ocj1 = 10;
   }

   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &Bi);
   if (Bi > 20 || Bi < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &Bii);
   if (Bii > 20 || Bii < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Bp);
   if (Bp > 10 || Bp < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Bdz);
   if (Bdz > 10 || Bdz < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Bz);
   if (Bz > 40 || Bz < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   Z2 = Bi + Bii + Bp + Bdz + Bz;
   if (Z2 >= 55 && Z2 < 65)
   {
      Ocj2 = 6;
   }
   if (Z2 >= 65 && Z2 < 75)
   {
      Ocj2 = 7;
   }
   if (Z2 >= 75 && Z2 < 85)
   {
      Ocj2 = 8;
   }
   if (Z2 >= 85 && Z2 < 92)
   {
      Ocj2 = 9;
   }
   if (Z2 >= 92 && Z2 <= 100)
   {
      Ocj2 = 10;
   }


   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Mi);
   if (Mi > 20 || Mi < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &Mii);
   if (Mii > 20 || Mii < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Mp);
   if (Mp > 10 || Mp < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Mdz);
   if (Mdz > 10 || Mdz < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Mz);
   if (Mz > 40 || Mz < 0)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   Z3 = Mi + Mii + Mp + Mdz + Mz;
   if (Z3 >= 55 && Z3 < 65)
   {
      Ocj3 = 6;
   }
   if (Z3 >= 65 && Z3 < 75)
   {
      Ocj3 = 7;
   }
   if (Z3 >= 75 && Z3 < 85)
   {
      Ocj3 = 8;
   }
   if (Z3 >= 85 && Z3 < 92)
   {
      Ocj3 = 9;
   }
   if (Z3 >= 92 && Z3 <= 100)
   {
      Ocj3 = 10;
   }

   if (Z1 < 55 && Z2 < 55 && Z3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (Z1 >= 55 && Z2 >= 55 && Z3 >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (Ocj1 == Ocj2 && Ocj1 == Ocj3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if (Ocj1 != Ocj2 && Ocj1 != Ocj3 && Ocj2 != Ocj3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      if ((Ocj1 == Ocj2 && Ocj2 != Ocj3) || (Ocj1 == Ocj3 && Ocj2 != Ocj3) || (Ocj1 != Ocj2 && (Ocj2 == Ocj3 && Ocj1 != Ocj3)))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }

   else if ((Z1 >= 55 && Z2 >= 55 && Z3 < 55) || (Z1 >= 55 && Z2 < 55 && Z3 >= 55) || (Z1 < 55 && Z2 >= 55 && Z2 >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if ((Z1 >= 55 && Z2 < 55 && Z3 < 55) || (Z1 < 55 && Z2 >= 55 && Z3 < 55) || (Z1 < 55 && Z2 < 55 && Z3 >= 55))
   {
      printf("Jedan student je polozio.");
   }


   return(0);
}
