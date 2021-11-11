#include <stdio.h>

int main()
{
   double pi1t, pi2t, zit, pt, Zt, pi1m, pi2m, pm, zm, pi1b, pi2b, zib, pb, zb, zim, ot, ob, om;
   float  ot1, om1, ob1;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit:");
   scanf("%lf", &pi1t);
   if ((pi1t < 0) || (pi1t > 20.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &pi2t);
   if ((pi2t < 0) || (pi2t > 20.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &pt);
   if ((pt < 0) || (pt > 10.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &Zt);
   if ((Zt < 0) || (Zt > 10.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zit);
   if ((zit < 0) || (zit > 40.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit:");
   scanf("%lf", &pi1m);
   if ((pi1m < 0) || (pi1m > 20.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &pi2m);
   if ((pi2m < 0) || (pi2m > 20.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &pm);
   if ((pm < 0) || (pm > 10.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &zm);
   if ((zm < 0) || (zm > 10.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zim);
   if ((zim < 0) || (zim > 40.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit:");
   scanf("%lf", &pi1b);
   if ((pi1b < 0) || (pi1b > 20.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &pi2b);
   if ((pi2b < 0) || (pi2b > 20.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &pb);
   if ((pb < 0) || (pb > 10.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &zb);
   if ((zb < 0) || (zb > 10.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zib);
   if ((zib < 0) || (zib > 40.0f))
   {
      printf(" Neispravan broj bodova"); return(0);
   }
   if (((pi1t + pi2t + Zt + pt + zit) < 55.0f) && ((pi1m + pi2m + zm + zim + pm) < 55.0f) && ((pi1b + pi2b + zb + pb + zib) < 55.0f))
   {
      printf(" Nijedan student nije polozio.");
   }
   if ((((pi1t + pi2t + Zt + pt + zit) >= 55.0f) && ((pi1b + pi2b + zb + zib + pb) < 55.0f) && ((pi1m + pi2m + zm + zim + pm) < 55.0f)) || ((pi1t + pi2t + Zt + pt + zit) < 55.0f) && ((pi1b + pi2b + pb + zb + zib) >= 55.0f) && ((pi1m + pi2m + zm + zim + pm) < 55.0f) || (((pi1m + pi2m + zm + zim + pm) >= 55.0f) && ((pi1t + pi2t + pt + Zt + zit) < 55.0f) && ((pi1b + pb + pi2b + zb + zib) < 55.0f)))
   {
      printf(" Jedan student je polozio.");
   }
   if ((((pi1t + pi2t + Zt + pt + zit) >= 55.0f) && ((pi1b + pi2b + zb + zib + pb) >= 55.0f) && ((pi1m + pi2m + zm + zim + pm) < 55.0f)) || ((pi1t + pi2t + Zt + pt + zit) >= 55.0f) && ((pi1b + pi2b + pb + zb + zib) < 55.0f) && ((pi1m + pi2m + zm + zim + pm) >= 55.0f) || (((pi1m + pi2m + zm + zim + pm) >= 55.0f) && ((pi1t + pi2t + pt + Zt + zit) < 55.0f) && ((pi1b + pb + pi2b + zb + zib) >= 55.0f)))
   {
      printf(" Dva studenta su polozila.");
   }
   if (((pi1t + pi2t + Zt + pt + zit) >= 55.0f) && ((pi1b + pi2b + zb + zib + pb) >= 55.0f) && ((pi1m + pi2m + zm + zim + pm) >= 55.0f))
   {
      printf(" Sva tri studenta su polozila.");
      ot = pi1t + pi2t + Zt + pt + zit;
      ob = pi1b + pi2b + zb + zib + pb;
      om = pi1m + pi2m + zm + zim + pm;
      if ((ot > 0) && (ot < 55.0f))
      {
         ot1 = 5;
      }
      else if ((ot >= 55.0f) && (ot < 65.0f))
      {
         ot1 = 6;
      }
      else if ((ot >= 65.0f) && (ot < 75.0f))
      {
         ot1 = 7;
      }
      else if ((ot >= 75.0f) && (ot < 85.0f))
      {
         ot1 = 8;
      }
      else if ((ot >= 85.0f) && (ot < 92.0f))
      {
         ot1 = 9;
      }
      else if ((ot >= 92.0f) && (ot <= 100.0f))
      {
         ot1 = 10;
      }
      if ((ob > 0) && (ob < 55.0f))
      {
         ob1 = 5;
      }
      else if ((ob >= 55.0f) && (ob < 65.0f))
      {
         ob1 = 6;
      }
      else if ((ob >= 65.0f) && (ob < 75.0f))
      {
         ob1 = 7;
      }
      else if ((ob >= 75.0f) && (ob < 85.0f))
      {
         ob1 = 8;
      }
      else if ((ob >= 85.0f) && (ob < 92.0f))
      {
         ob1 = 9;
      }
      else if ((ob >= 92.0f) && (ob <= 100.0f))
      {
         ob1 = 10;
      }
      if ((om > 0) && (om < 55.0f))
      {
         om1 = 5;
      }
      else if ((om >= 55.0f) && (om < 65.0f))
      {
         om1 = 6;
      }
      else if ((om >= 65.0f) && (om < 75.0f))
      {
         om1 = 7;
      }
      else if ((om >= 75.0f) && (om < 85.0f))
      {
         om1 = 8;
      }
      else if ((om >= 85.0f) && (om < 92.0f))
      {
         om1 = 9;
      }
      else if ((om >= 92.0f) && (om <= 100.0f))
      {
         om1 = 10;
      }
      if (ot1 == ob1 && ot1 == om1)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ot1 == ob1) || (ob1 == om1) || (ot1 == om1))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if ((ot1 != ob1) && (ot1 != om1) && (om1 != ob1))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
