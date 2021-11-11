#include <stdio.h>

int main()
{
   double TB, PPT, DPT, PT, ZT, ZIT, BB, PPB, DPB, PB, ZB, ZIB, MB, PPM, DPM, PM, ZM, ZIM;
   int    TO, BO, MO;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PPT);
   if (PPT < 0 || PPT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPT);
   if (DPT < 0 || DPT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PT);
   if (PT < 0 || PT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZT);
   if (ZT < 0 || ZT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIT);
   if (ZIT < 0 || ZIT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PPB);
   if (PPB < 0 || PPB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPB);
   if (DPB < 0 || DPB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PB);
   if (PB < 0 || PB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZB);
   if (ZB < 0 || ZB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIB);
   if (ZIB < 0 || ZIB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PPM);
   if (PPM < 0 || PPM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPM);
   if (DPM < 0 || DPM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PM);
   if (PM < 0 || PM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZM);
   if (ZM < 0 || ZM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIM);
   if (ZIM < 0 || ZIM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   TB = PPT + DPT + PT + ZT + ZIT;
   BB = PPB + DPB + PB + ZB + ZIB;
   MB = PPM + DPM + PM + ZM + ZIM;

   if (TB < 55)
   {
      TO = 5;
   }
   else if (TB >= 55 && TB < 65)
   {
      TO = 6;
   }
   else if (TB >= 65 && TB < 75)
   {
      TO = 7;
   }
   else if (TB >= 75 && TB < 85)
   {
      TO = 8;
   }
   else if (TB >= 85 && TB < 92)
   {
      TO = 9;
   }
   else if (TB >= 92 && TB < 100)
   {
      TO = 10;
   }

   if (BB < 55)
   {
      BO = 5;
   }
   else if (BB >= 55 && BB < 65)
   {
      BO = 6;
   }
   else if (BB >= 65 && BB < 75)
   {
      BO = 7;
   }
   else if (BB >= 75 && BB < 85)
   {
      BO = 8;
   }
   else if (BB >= 85 && BB < 92)
   {
      BO = 9;
   }
   else if (BB >= 92 && BB < 100)
   {
      BO = 10;
   }

   if (MB < 55)
   {
      MO = 5;
   }
   else if (MB >= 55 && MB < 65)
   {
      MO = 6;
   }
   else if (MB >= 65 && MB < 75)
   {
      MO = 7;
   }
   else if (MB >= 75 && MB < 85)
   {
      MO = 8;
   }
   else if (MB >= 85 && MB < 92)
   {
      MO = 9;
   }
   else if (MB >= 92 && MB < 100)
   {
      MO = 10;
   }

   if (TO == 5 && BO == 5 && MO == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (TO != 5 && BO == 5 && MO == 5 || TO == 5 && BO != 5 && MO == 5 || TO == 5 && BO == 5 && MO != 5)
   {
      printf("Jedan student je polozio.");
   }
   else if (TO != 5 && BO != 5 && MO == 5 || TO != 5 && BO == 5 && MO != 5 || TO == 5 && BO != 5 && MO != 5)
   {
      printf("Dva studenta su polozila.");
   }
   else if (TO != 5 && MO != 5 && BO != 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if (TO != BO && BO != MO)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else if ((TO == BO && MO != BO) || (TO == MO && BO != MO) || (TO != MO && BO == MO))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
   }
   return(0);
}
