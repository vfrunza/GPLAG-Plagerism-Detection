#include <stdio.h>
#define DG    55.0

int main()
{
   float p1t, p2t, pt, zt, zit, p1b, p2b, pb, zb, zib, p1m, p2m, pm, zm, zim;
   float st, sb, sm;
   int   ot, ob, om;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%f", &p1t);
   if (p1t > 20 || p1t < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &p2t);
   if (p2t > 20 || p2t < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &pt);
   if (pt > 10 || pt < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &zt);
   if (zt > 10 || zt < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &zit);
   if (zit > 40 || zit < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   }
   scanf("%f", &p1b);
   if (p1b > 20 || p1b < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &p2b);
   if (p2b > 20 || p2b < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &pb);
   if (pb > 10 || pb < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &zb);
   if (zb > 10 || zb < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &zib);
   if (zib > 40 || zib < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   }
   scanf("%f", &p1m);
   if (p1m > 20 || p1m < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &p2m);
   if (p2m > 20 || p2m < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &pm);
   if (pm > 10 || pm < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &zm);
   if (zm > 10 || zm < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &zim);
   if (zim > 40 || zim < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      st = p1t + p2t + pt + zt + zit + 0.01;
      sb = p1b + p2b + pb + zb + zib + 0.01;
      sm = p1m + p2m + pm + zm + zim + 0.01;
      if (st < 55 && sb < 55 && sm < 55)
      {
         printf("Nijedan student nije polozio.");
      }
      else if ((st >= 55 && sb < 55 && sm < 55) || (st < 55 && sb >= 55 && sm < 55) || (st < 55 && sb < 55 && sm >= 55))
      {
         printf("Jedan student je polozio.");
      }
      else if ((st >= 55 && sb >= 55 && sm < 55) || (st >= 55 && sb < 55 && sm >= 55) || (st < 55 && sb >= 55 && sm >= 55))
      {
         printf("Dva studenta su polozila.");
      }
      else
      {
         printf("Sva tri studenta su polozila.");
         if (st >= 55 && st < 65)
         {
            ot = 6;
         }
         else if (st >= 65 && st < 75)
         {
            ot = 7;
         }
         else if (st >= 75 && st < 85)
         {
            ot = 8;
         }
         else if (st >= 85 && ot < 92)
         {
            ot = 9;
         }
         else
         {
            ot = 10;
         }
         if (sb >= 55 && sb < 65)
         {
            ob = 6;
         }
         else if (sb >= 65 && sb < 75)
         {
            ob = 7;
         }
         else if (sb >= 75 && sb < 85)
         {
            ob = 8;
         }
         else if (sb >= 85 && sb < 92)
         {
            ob = 9;
         }
         else
         {
            ob = 10;
         }
         if (sm >= 55 && sm < 65)
         {
            om = 6;
         }
         else if (sm >= 65 && sm < 75)
         {
            om = 7;
         }
         else if (sm >= 75 && sm < 85)
         {
            om = 8;
         }
         else if (sm >= 85 && sm < 92)
         {
            om = 9;
         }
         else
         {
            om = 10;
         }
         if (ot == ob && ot == om && om == ob)
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         else if ((ot != ob && ot == om) || (ob != om && ob == ot) || (om != ot && ot == ob))
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
         else
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
      }
   }
   return(0);
}
