#include <stdio.h>
#include <math.h>
#define E    0.00001
int main()
{
   float t1, t2, tp, tz, z1, z2, z3, b1, b2, bp, bz, m1, m2, mp, mz, tarik, mirza, bojan;
   int   pao = 0, polozio = 0, vi = 0, vii = 0, viii = 0, ix = 0, x = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &t2);
   if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z1);
   if (z1 < 0 || z1 > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }


   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z2);
   if (z2 < 0 || z2 > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }


   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &m2);
   if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z3);
   if (tz < 0 || tz > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   tarik = t1 + t2 + tp + tz + z1;
   bojan = b1 + b2 + bp + bz + z2;
   mirza = m1 + m2 + mp + mz + z3;

   if (tarik < fabs(55 - E))
   {
      pao = pao + 1;
   }
   else
   {
      polozio = polozio + 1;
   }
   if (mirza < fabs(55 - E))
   {
      pao = pao + 1;
   }
   else
   {
      polozio = polozio + 1;
   }
   if (bojan < fabs(55 - E))
   {
      pao = pao + 1;
   }
   else
   {
      polozio = polozio + 1;
   }

   switch (polozio)
   {
   case 0: printf("Nijedan student nije polozio.\n");  break;

   case 1: printf("Jedan student je polozio.\n"); break;

   case 2: printf("Dva studenta su polozila.\n"); break;

   case 3: printf("Sva tri studenta su polozila.\n"); break;
   }

   if (55 <= tarik && tarik < 65)
   {
      vi++; goto boj;
   }
   if (65 <= tarik && tarik < 75)
   {
      vii++; goto boj;
   }
   if (75 <= tarik && tarik < 85)
   {
      viii++; goto boj;
   }
   if (85 <= tarik && tarik < 92)
   {
      ix++; goto boj;
   }
   if (92 <= tarik && tarik <= 100)
   {
      x++; goto boj;
   }

boj:
   if (55 <= bojan && bojan < 65)
   {
      vi++; goto mir;
   }
   if (65 <= bojan && bojan < 75)
   {
      vii++; goto mir;
   }
   if (75 <= bojan && bojan < 85)
   {
      viii++; goto mir;
   }
   if (85 <= bojan && bojan < 92)
   {
      ix++; goto mir;
   }
   if (92 <= bojan && bojan <= 100)
   {
      x++; goto mir;
   }

mir:

   if (55 <= mirza && mirza < 65)
   {
      vi++;
   }
   if (65 <= mirza && mirza < 75)
   {
      vii++;
   }
   if (75 <= mirza && mirza < 85)
   {
      viii++;
   }
   if (85 <= mirza && mirza < 92)
   {
      ix++;
   }
   if (92 <= mirza && mirza <= 100)
   {
      x++;
   }

   if (polozio == 3)
   {
      if (vi == 3 || vii == 3 || viii == 3 || ix == 3 || x == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (vi == 2 || vii == 2 || viii == 2 || ix == 2 || x == 2)
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
