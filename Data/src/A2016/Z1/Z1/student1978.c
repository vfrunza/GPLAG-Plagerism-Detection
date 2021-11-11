#include <stdio.h>

int main()
{
   float ppt, dpt, pt, zt, zat, TarikUkupno;

   printf("Unesite bodove za Tarika: ");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &ppt);
   if (ppt > 20 || ppt < 0)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dpt);
   if (dpt > 20 || dpt < 0)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Prisustvo: ");
   scanf("%f", &pt);
   if (pt > 10 || pt < 0)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zadace: ");
   scanf("%f", &zt);
   if (zt > 10 || zt < 0)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zat);
   if (zat > 40 || zat < 0)
   {
      printf("Neispravan broj bodova");
      return(1);
   }

   TarikUkupno = ppt + dpt + pt + zt + zat;


   float BojanUkupno, ppb, dpb, pb, zb, zab;

   printf("Unesite bodove za Bojana: ");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &ppb);
   if (ppb > 20 || ppb < 0)
   {
      printf("Neispravan broj bodova");
      return(2);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dpb);
   if (dpb > 20 || dpb < 0)
   {
      printf("Neispravan broj bodova");
      return(2);
   }
   printf("Prisustvo: ");
   scanf("%f", &pb);
   if (pb > 10 || pb < 0)
   {
      printf("Neispravan broj bodova");
      return(2);
   }
   printf("Zadace: ");
   scanf("%f", &zb);
   if (zb > 10 || zb < 0)
   {
      printf("Neispravan broj bodova");
      return(2);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zab);
   if (zab > 40 || zab < 0)
   {
      printf("Neispravan broj bodova");
      return(2);
   }



   BojanUkupno = ppb + dpb + pb + zb + zab;

   float MirzaUkupno, ppm, dpm, pm, zm, zam;

   printf("Unesite bodove za Mirzu: ");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &ppm);
   if (ppm > 20 || ppm < 0)
   {
      printf("Neispravan broj bodova");
      return(3);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dpm);
   if (dpm > 20 || dpm < 0)
   {
      printf("Neispravan broj bodova");
      return(3);
   }
   printf("Prisustvo: ");
   scanf("%f", &pm);
   if (pm > 10 || pm < 0)
   {
      printf("Neispravan broj bodova");
      return(3);
   }
   printf("Zadace: ");
   scanf("%f", &zm);
   if (zm > 10 || zm < 0)
   {
      printf("Neispravan broj bodova");
      return(3);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zam);
   if (zam > 40 || zam < 0)
   {
      printf("Neispravan broj bodova");
      return(3);
   }

   MirzaUkupno = ppm + dpm + pm + zm + zam;

   int polozio;

   polozio = 0;
   if (MirzaUkupno > 54.99)
   {
      polozio++;
   }
   if (BojanUkupno > 54.99)
   {
      polozio++;
   }
   if (TarikUkupno > 54.99)
   {
      polozio++;
   }

   switch (polozio)
   {
   case 1: printf("Jedan student je polozio.\n");
      break;

   case 2: printf("Dva studenta su polozila.\n");
      break;

   case 3: printf("Sva tri studenta su polozila.\n");
      break;

   case 0: printf("Nijedan student nije polozio.\n");
      break;
   }

   if (polozio == 3)
   {
      int sest = 0, sedam = 0, osam = 0, devet = 0, deset = 0;
      if (MirzaUkupno >= 55 && MirzaUkupno < 65)
      {
         sest++;
      }
      if (MirzaUkupno >= 65 && MirzaUkupno < 75)
      {
         sedam++;
      }
      if (MirzaUkupno >= 75 && MirzaUkupno < 85)
      {
         osam++;
      }
      if (MirzaUkupno >= 85 && MirzaUkupno < 92)
      {
         devet++;
      }
      if (MirzaUkupno >= 92 && MirzaUkupno < 100)
      {
         deset++;
      }

      if (BojanUkupno >= 55 && BojanUkupno < 65)
      {
         sest++;
      }
      if (BojanUkupno >= 65 && BojanUkupno < 75)
      {
         sedam++;
      }
      if (BojanUkupno >= 75 && BojanUkupno < 85)
      {
         osam++;
      }
      if (BojanUkupno >= 85 && BojanUkupno < 92)
      {
         devet++;
      }
      if (BojanUkupno >= 92 && BojanUkupno < 100)
      {
         deset++;
      }

      if (TarikUkupno >= 55 && TarikUkupno < 65)
      {
         sest++;
      }
      if (TarikUkupno >= 65 && TarikUkupno < 75)
      {
         sedam++;
      }
      if (TarikUkupno >= 75 && TarikUkupno < 85)
      {
         osam++;
      }
      if (TarikUkupno >= 85 && TarikUkupno < 92)
      {
         devet++;
      }
      if (TarikUkupno >= 92 && TarikUkupno < 100)
      {
         deset++;
      }

      if (sest == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (sest == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (sedam == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (sedam == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (osam == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (osam == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (devet == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (devet == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (deset == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (deset == 2)
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
