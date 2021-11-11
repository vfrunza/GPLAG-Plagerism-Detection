#include <stdio.h>
#include <math.h>
#define epsilon    0.00001
int main()
{
   double IPT, IIPT, PT, ZT, ZVT, IPB, IIPB, PB, ZB, ZVB, IPM, IIPM, PM, ZM, ZVM, BT, BB, BM;
   int    OM = 0, OB = 0, OT = 0;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &IPT);
   if (IPT < 0 || IPT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIPT);
   if (IIPT < 0 || IIPT > 20)
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
   scanf("%lf", &ZVT);
   if (ZVT < 0 || ZVT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%lf", &IPB);
   if (IPB < 0 || IPB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIPB);
   if (IIPB < 0 || IIPB > 20)
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
   scanf("%lf", &ZVB);
   if (ZVB < 0 || ZVB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%lf", &IPM);
   if (IPM < 0 || IPM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIPM);
   if (IIPM < 0 || IIPM > 20)
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
   scanf("%lf", &ZVM);
   if (ZVM < 0 || ZVM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BT = IPT + IIPT + ZT + PT + ZVT;

   if ((fabs(BT - 55) < epsilon || BT > 55.0) && BT < 65.0)
   {
      OT = 6;
   }
   else if ((fabs(BT - 65) < epsilon || BT > 65.0) && BT < 75.0)
   {
      OT = 7;
   }
   else if ((fabs(BT - 75) < epsilon || BT > 75.0) && BT < 85.0)
   {
      OT = 8;
   }
   else if ((fabs(BT - 85) < epsilon || BT > 85.0) && BT < 92.0)
   {
      OT = 9;
   }
   else if (fabs(BT - 92) < epsilon || BT > 92.0)
   {
      OT = 10;
   }
   else if (BT < 55.0)
   {
      OT = 5;
   }

   BB = IPB + IIPB + ZB + PB + ZVB;

   if ((fabs(BB - 55) < epsilon || BB > 55.0) && BB < 65.0)
   {
      OB = 6;
   }
   else if ((fabs(BB - 65) < epsilon || BB >= 65.0) && BB < 75.0)
   {
      OB = 7;
   }
   else if ((fabs(BB - 75) < epsilon || BB > 75.0) && BB < 85.0)
   {
      OB = 8;
   }
   else if ((fabs(BB - 85) < epsilon || BB > 85.0) && BB < 92.0)
   {
      OB = 9;
   }
   else if (fabs(BB - 92) < epsilon || BB > 92)
   {
      OB = 10;
   }
   else if (BB < 55.0)
   {
      OB = 5;
   }

   BM = IPM + IIPM + ZM + PM + ZVM;
   if ((fabs(BM - 55) < epsilon || BM > 55.0) && BM < 65.0)
   {
      OM = 6;
   }
   else if ((fabs(BM - 65) < epsilon || BM > 65.0) && BM < 75.0)
   {
      OM = 7;
   }
   else if ((fabs(BM - 75) < epsilon || BM > 75.0) && BM < 85.0)
   {
      OM = 8;
   }
   else if ((fabs(BM - 85) < epsilon || BM > 85.0) && BM < 92.0)
   {
      OM = 9;
   }
   else if (fabs(BM - 92) < epsilon || BM > 92.0)
   {
      OM = 10;
   }
   else if (BM < 55)
   {
      OM = 5;
   }

   if (OT == 5 && OM == 5 && OB == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((OM == 5 && OB == 5 && OT >= 6) || (OB == 5 && OT == 5 && OM >= 6) || (OM == 5 && OT == 5 && OB >= 6))
   {
      printf("Jedan student je polozio.");
   }
   else if ((OB == 5 && OM >= 6 && OT >= 6) || (OM == 5 && OT >= 6 && OB >= 6) || (OT == 5 && OM >= 6 && OB >= 6))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.");
      if (OT == OB && OB == OM && OT == OM)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((OB == OT && OM != OB && OM != OT) || (OB == OM && OT != OB && OT != OM) || (OT == OM && OB != OM && OB != OT))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
