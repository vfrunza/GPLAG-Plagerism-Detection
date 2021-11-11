#include <stdio.h>

int main()
{
   float Tarik, T1, T2, Tp, Tzd, Tzi;
   float Bojan, B1, B2, Bp, Bzd, Bzi;
   float Mirza, M1, M2, Mp, Mzd, Mzi;
   float Tk = 0, bk = 0, Mk = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &T2);
   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Tp);
   if (Tp < 0 || Tp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Tzd);
   if (Tzd < 0 || Tzd > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Tzi);
   if (Tzi < 0 || Tzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   Tarik = T1 + T2 + Tp + Tzd + Tzi + 0.0001;
   if (Tarik < 55)
   {
      Tk = 5;
   }
   else if (Tarik >= 55 && Tarik < 65)
   {
      Tk = 6;
   }
   else if (Tarik >= 65 && Tarik < 75)
   {
      Tk = 7;
   }
   else if (Tarik >= 75 && Tarik < 85)
   {
      Tk = 8;
   }
   else if (Tarik >= 85 && Tarik < 92)
   {
      Tk = 9;
   }
   else if (Tarik >= 92 && Tarik <= 100)
   {
      Tk = 10;
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Bp);
   if (Bp < 0 || Bp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Bzd);
   if (Bzd < 0 || Bzd > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Bzi);
   if (Bzi < 0 || Bzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   Bojan = B1 + B2 + Bp + Bzd + Bzi + 0.0001;
   if (Bojan < 55)
   {
      bk = 5;
   }
   else if (Bojan >= 55 && Bojan < 65)
   {
      bk = 6;
   }
   else if (Bojan >= 65 && Bojan < 75)
   {
      bk = 7;
   }
   else if (Bojan >= 75 && Bojan < 85)
   {
      bk = 8;
   }
   else if (Bojan >= 85 && Bojan < 92)
   {
      bk = 9;
   }
   else if (Bojan >= 92 && Bojan <= 100)
   {
      bk = 10;
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &M1);
   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &M2);
   if (M2 < 0 || M2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Mp);
   if (Mp < 0 || Mp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Mzd);
   if (Mzd < 0 || Mzd > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Mzi);
   if (Mzi < 0 || Mzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   Mirza = M1 + M2 + Mp + Mzd + Mzi + 0.0001;
   if (Mirza < 55)
   {
      Mk = 5;
   }
   else if (Mirza >= 55 && Mirza < 65)
   {
      Mk = 6;
   }
   else if (Mirza >= 65 && Mirza < 75)
   {
      Mk = 7;
   }
   else if (Mirza >= 75 && Mirza < 85)
   {
      Mk = 8;
   }
   else if (Mirza >= 85 && Mirza < 92)
   {
      Mk = 9;
   }
   else if (Mirza >= 92 && Mirza <= 100)
   {
      Mk = 10;
   }

   if (Mk == 5 && Tk == 5 && bk == 5)
   {
      printf("Nijedan student nije polozio.");
   }

   if (Mk == 5 && Tk == 5 && bk > 5)
   {
      printf("Jedan student je polozio.");
   }
   if (Mk == 5 && Tk > 5 && bk == 5)
   {
      printf("Jedan student je polozio.");
   }
   if (Mk > 5 && Tk == 5 && bk == 5)
   {
      printf("Jedan student je polozio.");
   }

   if (Mk == 5 && Tk > 5 && bk > 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (Mk > 5 && Tk > 5 && bk == 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (Mk > 5 && Tk == 5 && bk > 5)
   {
      printf("Dva studenta su polozila.");
   }

   if (Mk > 5 && Tk > 5 && bk > 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if (Mk == Tk && Tk == bk)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }

      if (Mk == Tk && Tk != bk)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (Mk != Tk && Tk == bk)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (Mk == bk && Tk != bk)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      if (Mk != Tk && Tk != bk && Mk != bk)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }


   return(0);
}
