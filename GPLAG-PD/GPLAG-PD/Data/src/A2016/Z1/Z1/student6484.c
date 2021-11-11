#include <stdio.h>

int main()
{
   double ppt, dpt, pt, zt, zit, ppb, dpb, pb, zb, zib, ppm, dpm, pm, zm, zim, ubb, ubm, ubt;

   /*  unos za Tarika */
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &ppt);
   if (ppt < 0 || ppt > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dpt);
   if (dpt < 0 || dpt > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pt);
   if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zt);
   if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zit);
   if (zit < 0 || zit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   /* unos za Bojana */
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &ppb);
   if (ppb < 0 || ppb > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dpb);
   if (dpb < 0 || dpb > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pb);
   if (pb < 0 || pb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zb);
   if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zib);
   if (zib < 0 || zib > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /* unos  za Mirzu */
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &ppm);
   if (ppm < 0 || ppm > 20)
   {
      printf("Neispravan  broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dpm);
   if (dpm < 0 || dpm > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &pm);
   if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zm);
   if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zim);
   if (zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   ubt = ppt + dpt + zt + zit + pt;
   ubm = ppm + dpm + zm + zim + pm;
   ubb = ppb + dpb + zb + zib + pb;

   if (ubb < 55 && ubm < 55 && ubt < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((ubb < 55 && ubm < 55 && ubt >= 55) || (ubb < 55 && ubm >= 55 && ubt < 55) || (ubb >= 55 && ubm < 55 && ubt < 55))
   {
      printf("Jedan student je polozio.\n");
   }
   else if (ubb >= 55 && ubm >= 55 && ubt >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((ubm < 65 && ubt < 65 && ubb < 65) || (ubm >= 92 && ubt >= 92 && ubb >= 92))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 85 && ubm < 92 && ubt >= 85 && ubt < 92 && ubb >= 85 && ubb < 92)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((ubm >= 75 && ubm < 85) && (ubb >= 75 && ubb < 85) && (ubt >= 75 && ubt < 85))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((ubm >= 65 && ubm < 75) && (ubt >= 65 && ubt < 75) && (ubb >= 65 && ubb < 75))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 55 && ubm < 65 && ubt >= 55 && ubt < 65 && ubb >= 65)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 92 && ubt >= 92 && ubb < 92)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 65 && ubm < 75 && ubt >= 65 && ubt < 75 && ubb < 65 && ubb >= 75)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 75 && ubm < 85 && ubt >= 75 && ubt < 85 && ubb < 75 && ubb >= 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 85 && ubm < 92 && ubt >= 85 && ubt < 92 && ubb >= 92 && ubb < 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }


      else if (ubm >= 55 && ubm < 65 && ubb >= 55 && ubb < 65 && ubt >= 65)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 92 && ubb >= 92 && ubt < 92)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 65 && ubm < 75 && ubb >= 65 && ubb < 75 && ubt < 65 && ubt >= 75)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 75 && ubm < 85 && ubb >= 75 && ubb < 85 && ubt < 75 && ubt >= 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubm >= 85 && ubm < 92 && ubb >= 85 && ubb < 92 && ubt >= 92 && ubt < 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }

      else if (ubt >= 55 && ubt < 65 && ubb >= 55 && ubb < 65 && ubm >= 65)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubt >= 92 && ubb >= 92 && ubm < 92)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubt >= 65 && ubt < 75 && ubb >= 65 && ubb < 75 && ubm < 65 && ubm >= 75)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubt >= 75 && ubt < 85 && ubb >= 75 && ubb < 85 && ubm < 75 && ubm >= 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ubt >= 85 && ubt < 92 && ubb >= 85 && ubb < 92 && ubm >= 92 && ubm < 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   else
   {
      printf("Dva studenta su polozila.");
   }


   return(0);
}
