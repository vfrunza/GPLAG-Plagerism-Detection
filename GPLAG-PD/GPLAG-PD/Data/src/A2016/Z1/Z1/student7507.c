#include <stdio.h>
#include <stdlib.h>

int main()
{
   float IT, IIT, PT, ZT, ZIT, IB, IIB, PB, ZB, ZIB, IM, IIM, PM, ZM, ZIM, ST = 0, SB = 0, SM = 0, OT = 0, OB = 0, OM = 0;
   int   br = 0;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%f", &IT);
   if (IT > 20 || IT < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIT);
   if (IIT > 20 || IIT < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PT);
   if (PT > 10 || PT < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZT);
   if (ZT > 10 || ZT < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIT);
   if (ZIT > 40 || ZIT < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%f", &IB);
   if (IB > 20 || IB < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIB);
   if (IIB > 20 || IIB < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PB);
   if (PB > 10 || PB < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZB);
   if (ZB > 10 || ZB < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIB);
   if (ZIB > 40 || ZIB < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%f", &IM);
   if (IM > 20 || IM < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIM);
   if (IIM > 20 || IIM < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PM);
   if (PM > 10 || PM < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZM);
   if (ZM > 10 || ZM < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIM);
   if (ZIM > 40 && ZIM < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   else if ((IT || IB || IM || IIT || IIB || IIM) < 20 || (IT || IB || IM || IIB || IIT || IIM) > 0 || (PT || PB || PM || ZT || ZB || ZM) < 10 || (PT || PB || PM || ZT || ZB || ZM) > 0 || (ZIT || ZIB || ZIM) < 40 || (ZIT || ZIB || ZIM) > 0)
   {
      ST = IT + IIT + PT + ZT + ZIT;
      if (ST >= 55 && ST < 65)
      {
         OT = 6;
      }
      else if (ST >= 65 && ST < 75)
      {
         OT = 7;
      }
      else if (ST >= 75 && ST < 85)
      {
         OT = 8;
      }
      else if (ST >= 85 && ST < 92)
      {
         OT = 9;
      }
      else if (ST >= 92 && ST >= 100)
      {
         OT = 10;
      }

      SB = IB + IIB + PB + ZB + ZIB;
      if (SB >= 55 && SB < 65)
      {
         OB = 6;
      }
      else if (SB >= 65 && SB < 75)
      {
         OB = 7;
      }
      else if (SB >= 75 && SB < 85)
      {
         OB = 8;
      }
      else if (SB >= 85 && SB < 92)
      {
         OB = 9;
      }
      else if (SB >= 92 && SB <= 100)
      {
         OB = 10;
      }

      SM = IM + IIM + PM + ZM + ZIM;
      if (SM >= 55 && SM < 65)
      {
         OM = 6;
      }
      else if (SM >= 65 && SM < 75)
      {
         OM = 7;
      }
      else if (SM >= 75 && SM < 85)
      {
         OM = 8;
      }
      else if (SM >= 85 && SM < 92)
      {
         OM = 9;
      }
      else if (SM >= 92 && SM <= 100)
      {
         OM = 10;
      }

      if (OT >= 6)
      {
         br++;
      }
      if (OB >= 6)
      {
         br++;
      }
      if (OM >= 6)
      {
         br++;
      }

      if (br == 0)
      {
         printf("Nijedan student nije polozio.\n");
      }
      if (br == 1)
      {
         printf("Jedan student je polozio.\n");
      }
      if (br == 2)
      {
         printf("Dva studenta su polozila.\n");
      }
      if (br == 3)
      {
         printf("Sva tri studenta su polozila.\n");
         if (OT == OB && OT == OM)
         {
            printf("Sva tri studenta imaju istu ocjenu.\n");
         }
         else if (OT == OB)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else if (OT == OM)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else if (OB == OM)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else
         {
            printf("Svaki student ima razlicitu ocjenu.\n");
         }
      }
   }
   return(0);
}
