#include <stdio.h>

int main()
{
   double TI, TII, TP, TZ, TU, BI, BII, BP, BZ, BU, MI, MII, MP, MZ, MU, ET, EB, EM;
   int    POL = 0, OT, OB, OM;


   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &TI);
   if (TI > 20 || TI < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &TII);
   if (TII > 20 || TII < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &TP);
   if (TP > 10 || TP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%lf", &TZ);
   if (TZ > 10 || TZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &TU);
   if (TU > 40 || TU < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &BI);
   if (BI > 20 || BI < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &BII);
   if (BII > 20 || BII < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &BP);
   if (BP > 10 || BP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%lf", &BZ);
   if (BZ > 10 || BZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &BU);
   if (BU > 40 || BU < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &MI);
   if (MI > 20 || MI < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &MII);
   if (MII > 20 || MII < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &MP);
   if (MP > 10 || MP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%lf", &MZ);
   if (MZ > 10 || MZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &MU);
   if (MU > 40 || MU < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ET = TI + TII + TP + TZ + TU + 1e-8;
   EB = BI + BII + BP + BZ + BU + 1e-8;
   EM = MI + MII + MP + MZ + MU + 1e-8;

   if (ET < 55)
   {
      OT = 5;
   }
   else
   {
      if (ET < 65)
      {
         OT = 6;
      }
      else if (ET < 75)
      {
         OT = 7;
      }
      else if (ET < 85)
      {
         OT = 8;
      }
      else if (ET < 92)
      {
         OT = 9;
      }
      else
      {
         OT = 10;
      }
   }

   if (EB < 55)
   {
      OB = 5;
   }
   else
   {
      if (EB < 65)
      {
         OB = 6;
      }
      else if (EB < 75)
      {
         OB = 7;
      }
      else if (EB < 85)
      {
         OB = 8;
      }
      else if (EB < 92)
      {
         OB = 9;
      }
      else
      {
         OB = 10;
      }
   }

   if (EM < 55)
   {
      OM = 5;
   }
   else
   {
      if (EM < 65)
      {
         OM = 6;
      }
      else if (EM < 75)
      {
         OM = 7;
      }
      else if (EM < 85)
      {
         OM = 8;
      }
      else if (EM < 92)
      {
         OM = 9;
      }
      else
      {
         OM = 10;
      }
   }

   POL = OT / 6 + OB / 6 + OM / 6;
   if (POL == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (POL == 1)
   {
      printf("Jedan student je polozio.");
   }
   else if (POL == 2)
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
      if (OT == OB && OB == OM)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (OT == OB || OB == OM || OT == OM)
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
