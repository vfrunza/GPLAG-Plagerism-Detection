#include <stdio.h>

int main()
{
   float t1, t2, tp, tz, ti, b1, b2, bp, bz, bi, m1, m2, mp, mz, mi, ocjenat, ocjenam, ocjenab;
   int   tarik, bojan, mirza;


   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &t2);
   if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodava"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ti);
   if (ti < 0 || ti > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bi);
   if (bi < 0 || bi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &m2);
   if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mi);
   if (ti < 0 || ti > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   {
      ocjenat = t1 + t2 + tp + tz + ti + 0.01;
      ocjenab = b1 + b2 + bp + bz + bi + 0.01;
      ocjenam = m1 + m2 + mp + mz + mi + 0.01;
      tarik   = ocjenat;
      mirza   = ocjenam;
      bojan   = ocjenab;
   }
   {
      if (tarik < 55 && bojan < 55 && mirza < 55)
      {
         printf("Nijedan student nije polozio."); return(0);
      }
      if (tarik >= 55 && bojan < 55 && mirza < 55)
      {
         printf("Jedan student je polozio."); return(0);
      }
      if (bojan >= 55 && tarik < 55 && mirza < 55)
      {
         printf("Jedan student je polozio."); return(0);
      }
      if (mirza >= 55 && bojan < 55 && tarik < 55)
      {
         printf("Jedan student je polozio."); return(0);
      }
      if (tarik >= 55 && bojan >= 55 && mirza < 55)
      {
         printf("Dva studenta su polozila."); return(0);
      }
      if (tarik >= 55 && mirza >= 55 && bojan < 55)
      {
         printf("Dva studenta su polozila."); return(0);
      }
      if (mirza >= 55 && bojan >= 55 && tarik < 55)
      {
         printf("Dva studenta su polozila."); return(0);
      }
      if (mirza >= 55 && bojan >= 55 && tarik >= 55)
      {
         printf("Sva tri studenta su polozila.");

         if (tarik < 65 && tarik >= 55)
         {
            tarik = 6;
         }
         if (bojan < 65 && bojan >= 55)
         {
            bojan = 6;
         }
         if (mirza < 65 && mirza >= 55)
         {
            mirza = 6;
         }
         if (tarik >= 65 && tarik < 75)
         {
            tarik = 7;
         }
         if (bojan < 75 && bojan >= 65)
         {
            bojan = 7;
         }
         if (mirza < 75 && mirza >= 65)
         {
            mirza = 7;
         }
         if (tarik >= 75 && tarik < 85)
         {
            tarik = 8;
         }
         if (bojan >= 75 && bojan < 85)
         {
            bojan = 8;
         }
         if (mirza >= 75 && mirza < 85)
         {
            mirza = 8;
         }
         if (tarik >= 85 && tarik < 92)
         {
            tarik = 9;
         }
         if (bojan >= 85 && bojan < 92)
         {
            bojan = 9;
         }
         if (mirza >= 85 && mirza < 92)
         {
            mirza = 9;
         }
         if (tarik >= 92 && tarik <= 100)
         {
            tarik = 10;
         }
         if (bojan >= 92 && bojan <= 100)
         {
            bojan = 10;
         }
         if (mirza >= 92 && mirza <= 100)
         {
            mirza = 10;
         }



         if (tarik != mirza && tarik != bojan && mirza != bojan)
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
         else if (tarik == bojan && bojan != mirza && tarik != mirza)
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
         else if (bojan != tarik && bojan == mirza && mirza != tarik)
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
         else if (mirza != bojan && mirza == tarik && bojan != tarik)
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
         else if (tarik == mirza && tarik == bojan && mirza == bojan)
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
      }
   }
   return(0);
}
