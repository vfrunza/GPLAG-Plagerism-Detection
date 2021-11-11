#include <stdio.h>
int main()
{
   double BT, BB, BM, IP, IIP, P, Z, ZI, IPB, IIPB, PB, ZB, ZIB, IPM, IIPM, PM, ZM, ZIM;
   int    OT, OB, OM;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP);
   if (IP > 20 || IP < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP);
   if (IIP > 20 || IIP < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P);
   if (P > 10 || P < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z);
   if (Z > 10 || Z < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI);
   if (ZI > 40 || ZI < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BT = IP + IIP + P + Z + ZI;

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IPB);
   if (IPB > 20 || IPB < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIPB);
   if (IIPB > 20 || IIPB < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PB);
   if (PB > 10 || PB < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZB);
   if (ZB > 10 || ZB < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIB);
   if (ZIB > 40 || ZIB < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   BB = IPB + IIPB + PB + ZB + ZIB;



   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IPM);
   if (IPM > 20 || IPM < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIPM);
   if (IIPM > 20 || IIPM < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PM);
   if (PM > 10 || PM < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZM);
   if (ZM > 10 || ZM < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIM);
   if (ZI > 40 || ZI < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BM = IPM + IIPM + PM + ZM + ZIM;
   if (BT >= 55 && BT < 65)
   {
      OT = 6;
   }
   else if (BT >= 64 && BT < 75)
   {
      OT = 7;
   }
   else if (BT >= 75 && BT < 85)
   {
      OT = 8;
   }
   else if (BT >= 85 && BT < 92)
   {
      OT = 9;
   }
   else if (BT >= 92 && BT <= 100)
   {
      OT = 10;
   }
   else
   {
      OT = 0;
   }
   if (BB >= 55 && BB < 65)
   {
      OB = 6;
   }
   else if (BB >= 65 && BB < 75)
   {
      OB = 7;
   }
   else if (BB >= 75 && BB < 85)
   {
      OB = 8;
   }
   else if (BB >= 85 && BB < 92)
   {
      OB = 9;
   }
   else if (BB >= 92 && BB <= 100)
   {
      OB = 10;
   }
   else
   {
      OB = 1;
   }
   if (BM >= 55 && BM < 65)
   {
      OM = 6;
   }
   else if (BM >= 65 && BM < 75)
   {
      OM = 7;
   }
   else if (BM >= 75 && BM < 85)
   {
      OM = 8;
   }
   else if (BM >= 85 && BM < 92)
   {
      OM = 9;
   }
   else if (BM >= 92 && BM <= 100)
   {
      OM = 10;
   }
   else
   {
      OM = 2;
   }
   if (BT < 55 && BB < 55 && BM < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if (OT >= 6 && OB >= 6 && OM >= 6)
   {
      printf("Sva tri studenta su polozila.");
      if (OT == OB && OB == OM)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((OT == OB || OB == OM || OM == OT))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   if ((OT >= 6 && OB < 6 && OM < 6) || (OT < 6 && OB >= 6 && OM < 6) || (OT < 6 && OB < 6 && OM >= 6))
   {
      printf("Jedan student je polozio.");
   }

   if ((OT >= 6 && OB >= 6 && OM < 6) || (OT < 6 && OB >= 6 && OM >= 6) || (OT >= 6 && OB < 6 && OM >= 6))
   {
      printf("Dva studenta su polozila.");
   }
   return(0);
}
