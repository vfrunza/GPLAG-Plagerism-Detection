#include <stdio.h>

int main()
{
   double IparT, IIparT, prisT, zadT, zavT, IparB, IIparB, prisB, zadB, zavB, IparM, IIparM, prisM, zadM, zavM,
          bt, bb, bm;
   int oct = 0, ocb = 0, ocm = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IparT);
   if (IparT < 0 || IparT > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparT);
   if (IIparT < 0 || IIparT > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisT);
   if (prisT < 0 || prisT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadT);
   if (zadT < 0 || zadT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavT);
   if (zavT < 0 || zavT > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IparB);
   if (IparB < 0 || IparB > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparB);
   if (IIparB < 0 || IIparB > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisB);
   if (prisB < 0 || prisB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadB);
   if (zadB < 0 || zadB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavB);
   if (zavB < 0 || zavB > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IparM);
   if (IparM < 0 || IparM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparM);
   if (IIparM < 0 || IIparM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisM);
   if (prisM < 0 || prisM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadM);
   if (zadM < 0 || zadM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavM);
   if (zavM < 0 || zavM > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   bt = IparT + IIparT + prisT + zadT + zavT;
   bb = IparB + IIparB + prisB + zadB + zavB;
   bm = IparM + IIparM + prisM + zadM + zavM;

   if (bt < 55 && bb < 55 && bm < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (bt >= 55 && bb < 55 && bm < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (bt < 55 && bb >= 55 && bm < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (bt < 55 && bb < 55 && bm >= 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (bt >= 55 && bb >= 55 && bm < 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (bt >= 55 && bb < 55 && bm >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (bt < 55 && bb >= 55 && bm >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (bt >= 55 && bb >= 55 && bm >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if (bt >= 55 && bt < 65)
      {
         oct = 6;
      }
      else if (bt >= 65 && bt < 75)
      {
         oct = 7;
      }
      else if (bt >= 75 && bt < 85)
      {
         oct = 8;
      }
      else if (bt >= 85 && bt < 92)
      {
         oct = 9;
      }
      else if (bt >= 92 && bt <= 100)
      {
         oct = 10;
      }

      if (bb >= 55 && bb < 65)
      {
         ocb = 6;
      }
      else if (bb >= 65 && bb < 75)
      {
         ocb = 7;
      }
      else if (bb >= 75 && bb < 85)
      {
         ocb = 8;
      }
      else if (bb >= 85 && bb < 92)
      {
         ocb = 9;
      }
      else if (bb >= 92 && bb <= 100)
      {
         ocb = 10;
      }

      if (bm >= 55 && bm < 65)
      {
         ocm = 6;
      }
      else if (bm >= 65 && bm < 75)
      {
         ocm = 7;
      }
      else if (bm >= 75 && bm < 85)
      {
         ocm = 8;
      }
      else if (bm >= 85 && bm < 92)
      {
         ocm = 9;
      }
      else if (bm >= 92 && bm <= 100)
      {
         ocm = 10;
      }

      if (oct == ocb && oct == ocm && ocb == ocm)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (oct != ocb && oct != ocm && ocb == ocm)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (oct != ocb && oct == ocm && ocb != ocm)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (oct == ocb && oct != ocm && ocb != ocm)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (oct != ocb && oct != ocm && ocb != ocm)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
