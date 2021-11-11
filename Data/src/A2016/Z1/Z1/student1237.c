#include <stdio.h>

int main()
{
   double p1t, p1b, p1m, p2t, p2m, p2b, pt, pm, pb, zb, zt, zm, zim, zit, zib, T, B, M, OT, OB, OM;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1t);
   if (p1t < 0 || p1t > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2t);
   if (p2t < 0 || p2t > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &pt);
   if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zt);
   if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zit);
   if (zit < 0 || zit > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1b);
   if (p1b < 0 || p1b > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2b);
   if (p2b < 0 || p2b > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pb);
   if (pb < 0 || pb > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zb);
   if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zib);
   if (zib < 0 || zib > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1m);
   if (p1m < 0 || p1m > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2m);
   if (p2m < 0 || p2m > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pm);
   if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zm);
   if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zim);
   if (zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   T = p1t + p2t + pt + zt + zit;
   B = p1b + p2b + pb + zb + zib;
   M = p1m + p2m + pm + zm + zim;
   if (T < 55 && B < 55 && M < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if ((T < 55 && B < 55 && M >= 55) || (T < 55 && M < 55 && B >= 55) || (T >= 55 && M < 55 && B < 55))
   {
      printf("Jedan student je polozio.\n");
   }
   if (T >= 55 && B >= 55 && M >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   if ((T >= 55 && M >= 55 && B < 55) || (T >= 55 && B >= 55 && M < 55) || (T < 55 && M >= 55 && B >= 55))
   {
      printf("Dva studenta su polozila.\n");
   }

   if (T > 55 &&
       B > 55 && M > 55)
   {
      if (T >= 55 && T < 65)
      {
         OT = 6;
      }
      else if (T >= 65 && T < 75)
      {
         OT = 7;
      }
      else if (T >= 75 && T < 85)
      {
         OT = 8;
      }
      else if (T >= 85 && T < 92)
      {
         OT = 9;
      }
      else if (T >= 92 && T <= 100)
      {
         OT = 10;
      }
      if (B >= 55 && B < 65)
      {
         OB = 6;
      }
      else if (B >= 65 && B < 75)
      {
         OB = 7;
      }
      else if (B >= 75 && B < 85)
      {
         OB = 8;
      }
      else if (B >= 85 && B < 92)
      {
         OB = 9;
      }
      else if (B >= 92 && B <= 100)
      {
         OB = 10;
      }
      if (M >= 55 && M < 65)
      {
         OM = 6;
      }
      else if (M >= 65 && M < 75)
      {
         OM = 7;
      }
      else if (M >= 75 && M < 85)
      {
         OM = 8;
      }
      else if (M >= 85 && M < 92)
      {
         OM = 9;
      }
      else if (M >= 92 && M <= 100)
      {
         OM = 10;
      }
      if (OM == OB && OB == OT)
      {
         printf("\nSva tri studenta imaju istu ocjenu.\n");
      }
      if ((OM == OB && OB != OT) || (OM == OT && OT != OB) || (OB == OT && OT != OM))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.\n");
      }
      if (OM != OB && OB != OT)
      {
         printf("\nSvaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
