#include <stdio.h>
#include <math.h>
#define MBP1       20.0
#define MBP2       20.0
#define MP         10.0
#define MZ         10.0
#define MZI        40.0
#define EPSILON    0.0001

int main()
{
   double bp1t = 0, bp2t = 0, bpt = 0, bzt = 0, bzit = 0, bp1b = 0, bp2b = 0, bpb = 0, bzb = 0, bzib = 0, bp1m = 0, bp2m = 0, bpm = 0, bzm = 0, bzim = 0, ub1, ub2, ub3, oc1 = 0, oc2 = 0, oc3 = 0;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &bp1t);
   if ((bp1t < 0) || (bp1t > MBP1))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bp2t);
   if ((bp2t < 0) || (bp2t > MBP2))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bpt);
   if ((bpt < 0) || (bpt > MP))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bzt);
   if ((bzt < 0) || (bzt > MZ))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzit);
   if ((bzit < 0) || (bzit > MZI))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit:");
   scanf("%lf", &bp1b);
   if ((bp1b < 0) || (bp1b > MBP1))
   {
      printf(" Neispravan broj bodova\n");
      return(0);
   }
   printf(" II parcijalni ispit: ");
   scanf("%lf", &bp2b);
   if ((bp2b < 0) || (bp2b > MBP2))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bpb);
   if ((bpb < 0) || (bpb > MP))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bzb);
   if ((bzb < 0) || (bzb > MZ))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzib);
   if ((bzib < 0) || (bzib > MZI))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &bp1m);
   if ((bp1m < 0) || (bp1m > MBP1))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bp2m);
   if ((bp2m < 0) || (bp2m > MBP2))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bpm);
   if ((bpm < 0) || (bpm > MP))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bzm);
   if ((bzm < 0) || (bzm > MZ))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzim);
   if ((bzim < 0) || (bzim > MZI))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   ub1 = bp1t + bp2t + bpt + bzt + bzit;
   ub2 = bp1b + bp2b + bpb + bzb + bzib;
   ub3 = bp1m + bp2m + bpm + bzm + bzim;

   if ((ub1 >= 55) && (ub1 < 65))
   {
      oc1 = 6;
   }
   if ((ub1 >= 65) && (ub1 < 75))
   {
      oc1 = 7;
   }
   if ((ub1 >= 75) && (ub1 < 85))
   {
      oc1 = 8;
   }
   if ((ub1 >= 85) && (ub1 < 92))
   {
      oc1 = 9;
   }
   if ((ub1 >= 92) && (ub1 <= 100))
   {
      oc1 = 10;
   }

   if ((ub2 >= 55) && (ub2 < 65))
   {
      oc2 = 6;
   }
   if ((ub2 >= 65) && (ub2 < 75))
   {
      oc2 = 7;
   }
   if ((ub2 >= 75) && (ub2 < 85))
   {
      oc2 = 8;
   }
   if ((ub2 >= 85) && (ub2 < 92))
   {
      oc2 = 9;
   }
   if ((ub2 >= 92) && (ub2 <= 100))
   {
      oc2 = 10;
   }

   if ((ub3 >= 55) && (ub3 < 65))
   {
      oc3 = 6;
   }
   if ((ub3 >= 65) && (ub3 < 75))
   {
      oc3 = 7;
   }
   if ((ub3 >= 75) && (ub3 < 85))
   {
      oc3 = 8;
   }
   if ((ub3 >= 85) && (ub3 < 92))
   {
      oc3 = 9;
   }
   if ((ub3 >= 92) && (ub3 <= 100))
   {
      oc3 = 10;
   }
   if ((oc1 < 6) && (oc2 < 6) && (oc3 < 6))
   {
      printf("Nijedan student nije polozio.");
   }
   if (((oc1 >= 6) && (oc2 < 6) && (oc3 < 6)) || ((oc1 < 6) && (oc2 >= 6) && (oc3 < 6)) || ((oc1 < 6) && (oc2 < 6) && (oc3 >= 6)))
   {
      printf("Jedan student je polozio.");
   }
   if (((oc1 >= 6) && (oc2 >= 6) && (oc3 < 6)) || ((oc1 >= 6) && (oc2 < 6) && (oc3 >= 6)) || ((oc1 < 6) && (oc2 >= 6) && (oc3 >= 6)))
   {
      printf("Dva studenta su polozila.");
   }
   if ((oc1 >= 6 && oc1 <= 10) && (oc2 >= 6 && oc2 <= 10) && (oc3 >= 6 && oc3 <= 10))
   {
      printf("Sva tri studenta su polozila.\n");
      if (fabs(oc1 - oc2) < EPSILON && fabs(oc2 - oc3) < EPSILON)
      {
         printf("\nSva tri studenta imaju istu ocjenu.\n");
      }
      else if (fabs(oc1 - oc2) < EPSILON && fabs(oc2 - oc3) >= EPSILON)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.\n");
      }
      else if (fabs(oc1 - oc2) >= EPSILON && fabs(oc1 - oc3) >= EPSILON && fabs(oc2 - oc3) >= EPSILON)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
