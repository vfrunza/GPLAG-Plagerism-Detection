#include <stdio.h>

int main()
{
   int    oct, ocb, ocm;
   double ppt, dpt, prist, zadt, zit, brbt, ppb, dpb, prisb, zadb, zib, brbb, ppm, dpm, prism, zadm, zim, brbm;

   /*Tarik*/
   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &ppt);
   if (ppt < 0 || ppt > 20)
   {
      printf("Neispravan broj bodova");
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &dpt);
   if (dpt < 0 || dpt > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prist);
   if (prist < 0 || prist > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadt);
   if (zadt < 0 || zadt > 10)
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

   /*Bojan*/

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
   scanf("%lf", &prisb);
   if (prisb < 0 || prisb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadb);
   if (zadb < 0 || zadb > 10)
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

   /*Mirza*/

   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &ppm);
   if (ppm < 0 || ppm > 20)
   {
      printf("Neispravan broj bodova");
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
   scanf("%lf", &prism);
   if (prism < 0 || prism > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadm);
   if (zadm < 0 || zadm > 10)
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

   /*ukupan broj bodova*/

   brbt = ppt + dpt + prist + zadt + zit;
   brbb = ppb + dpb + prisb + zadb + zib;
   brbm = ppm + dpm + prism + zadm + zim;
   brbt = (int)(brbt);
   brbb = (int)(brbb);
   brbm = (int)(brbm);

   if (brbt >= 55 && brbt < 65)
   {
      oct = 6;
   }
   else if (brbt >= 65 && brbt < 75)
   {
      oct = 7;
   }
   else if (brbt >= 75 && brbt < 85)
   {
      oct = 8;
   }
   else if (brbt >= 85 && brbt < 92)
   {
      oct = 9;
   }
   else if (brbt >= 92 && brbt <= 100)
   {
      oct = 10;
   }
   else if (brbt < 55)
   {
      oct = 0;
   }

   if (brbb >= 55 && brbb < 65)
   {
      ocb = 6;
   }
   else if (brbb >= 65 && brbb < 75)
   {
      ocb = 7;
   }
   else if (brbb >= 75 && brbb < 85)
   {
      ocb = 8;
   }
   else if (brbb >= 85 && brbb < 92)
   {
      ocb = 9;
   }
   else if (brbb >= 92 && brbb <= 100)
   {
      ocb = 10;
   }
   else if (brbb < 55)
   {
      ocb = 0;
   }

   if (brbm >= 55 && brbm < 65)
   {
      ocm = 6;
   }
   else if (brbm >= 65 && brbm < 75)
   {
      ocm = 7;
   }
   else if (brbm >= 75 && brbm < 85)
   {
      ocm = 8;
   }
   else if (brbm >= 85 && brbm < 92)
   {
      ocm = 9;
   }
   else if (brbm >= 92 && brbm <= 100)
   {
      ocm = 10;
   }
   else if (brbm < 55)
   {
      ocm = 0;
   }

   if (oct == 0 && ocb == 0 && ocm == 0)
   {
      printf("Nijedan student nije polozio.");
   }

   else if ((oct > 6 && ocb == 0 && ocm == 0) || (oct == 0 && ocb > 6 && ocm == 0) || (oct == 0 && ocb == 0 && ocm > 6))
   {
      printf("Jedan student je polozio.");
   }

   else if ((oct > 6 && ocb > 6 && ocm == 0) || (oct > 6 && ocb == 0 && ocm > 6) || (oct == 0 && ocb > 6 && ocm > 6))
   {
      printf("Dva studenta su polozila.");
   }

   else if (oct > 6 && ocb > 6 && ocm > 6)
   {
      printf("Sva tri studenta su polozila. \n");
      if (oct == ocb && oct == ocm)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (oct == ocb || oct == ocm || ocb == ocm)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (oct != ocb && oct != ocm)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
