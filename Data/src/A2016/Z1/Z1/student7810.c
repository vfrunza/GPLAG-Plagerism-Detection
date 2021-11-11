#include <stdio.h>
int main()
{
   double pt, ppt, dpt, zt, zit, pb, ppb, dpb, zb, zib, pm, ppm, dpm, zm, zim;
   int    ot, ob, om;

   printf("Unesite bodove za Tarika: \n"); printf("I parcijalni ispit: "); scanf("%lf", &ppt); if (ppt < 0 || ppt > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &dpt); if (dpt < 0 || dpt > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &pt); if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &zt); if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &zit); if (zit < 0 || zit > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana: \n"); printf("I parcijalni ispit: "); scanf("%lf", &ppb); if (ppb < 0 || ppb > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &dpb); if (dpb < 0 || dpb > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &pb); if (pb < 0 || pb > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &zb); if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &zib); if (zib < 0 || zib > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Mirzu: \n"); printf("I parcijalni ispit: "); scanf("%lf", &ppm); if (ppm < 0 || ppm > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &dpm); if (dpm < 0 || dpm > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &pm); if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &zm); if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &zim); if (zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   if (ppt < 0 || ppt > 20 || dpt < 0 || dpt > 20 || pt < 0 || pt > 10 || zt < 0 || zt > 10 || zit < 0 || zit > 40 || ppb < 0 || ppb > 20 || dpb < 0 || dpb > 20 || pb < 0 || pb > 10 || zb < 0 || zb > 10 || zib < 0 || zib > 40 || ppm < 0 || ppm > 20 || dpm < 0 || dpm > 20 || pm < 0 || pm > 10 || zm < 0 || zm > 10 || zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova\n");
   }

   else
   {
      ot = ppt + dpt + pt + zt + zit; ob = ppb + dpb + pb + zb + zib; om = ppm + dpm + pm + zm + zim;

      if (ot >= 55 && ob >= 55 && om < 55)
      {
         printf("Dva studenta su polozila.\n");
      }
      else if (ot >= 55 && ob < 55 && om >= 55)
      {
         printf("Dva studenta su polozila.\n");
      }
      else if (ot < 55 && ob >= 55 && om >= 55)
      {
         printf("Dva studenta su polozila.\n");
      }
      else if (ot >= 55 && ob < 55 && om < 55)
      {
         printf("Jedan student je polozio.\n");
      }
      else if (ot < 55 && ob >= 55 && om < 55)
      {
         printf("Jedan student je polozio.\n");
      }
      else if (ot < 55 && ob < 55 && om >= 55)
      {
         printf("Jedan student je polozio.\n");
      }
      else if (ot < 55 && ob < 55 && om < 55)
      {
         printf("Nijedan student nije polozio.\n");
      }
      else if (ot >= 55 && ob >= 55 && om >= 55)
      {
         printf("Sva tri studenta su polozila.\n");
         if ((ot >= 55 && ot < 65 && ob >= 55 && ob < 65 && om >= 55 && om < 65) || (ot >= 65 && ot < 75 && ob >= 65 && ob < 75 && om >= 65 && om < 75) || (ot >= 75 && ot < 85 && ob >= 75 && ob < 85 && om >= 75 && om < 85) || (ot >= 85 && ot < 92 && ob >= 85 && ob < 92 && om >= 85 && om < 92) || (ot >= 92 && ob >= 92 && om >= 92))
         {
            printf("Sva tri studenta imaju istu ocjenu.\n");
         }
         else if ((ot >= 55 && ot < 65 && ob >= 55 && ob < 65 && (om >= 65 || om < 65)) || (ot >= 65 && ot < 75 && ob >= 65 && ob < 75 && (om < 65 || om >= 75)) || (ot >= 75 && ot < 85 && ob >= 75 && ob < 85 && (om < 75 || om >= 85)) || (ot >= 85 && ot < 92 && ob >= 85 && ob < 92 && (om < 85 || om >= 92)) || (ot >= 92 && ob >= 92 && om < 92))
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else if ((ot >= 55 && ot < 65 && om >= 55 && om < 65 && (ob >= 65 || ob < 65)) || (ot >= 65 && ot < 75 && om >= 65 && om < 75 && (ob < 65 || ob >= 75)) || (ot >= 75 && ot < 85 && om >= 75 && om < 85 && (ob < 75 || ob >= 85)) || (ot >= 85 && ot < 92 && om >= 85 && om < 92 && (ob < 85 || ob >= 92)) || (ot >= 92 && om >= 92 && ob < 92))
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else if ((om >= 55 && om < 65 && ob >= 55 && ob < 65 && (ot >= 65 || ot < 65)) || (om >= 65 && om < 75 && ob >= 65 && ob < 75 && (ot < 65 || ot >= 75)) || (om >= 75 && om < 85 && ob >= 75 && ob < 85 && (ot < 75 || ot >= 85)) || (om >= 85 && om < 92 && ob >= 85 && ob < 92 && (ot < 85 || ot >= 92)) || (om >= 92 && ob >= 92 && ot < 92))
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else if (ot != ob && ot != om && ob != om)
         {
            printf("Svaki student ima razlicitu ocjenu.\n");
         }
      }
   }


   return(0);
}
