#include <stdio.h>

int main()
{
   double IpT, IIpT, zT, pT, ZiT, IpB, IIpB, zB, pB, ZiB, IpM, IIpM, zM, pM, ZiM, OT, OB, OM, BM, BB, BT;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IpT); if (IpT < 0 || IpT > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpT); if (IIpT < 0 || IIpT > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pT); if (pT < 0 || pT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zT); if (zT < 0 || zT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZiT); if (ZiT < 0 || ZiT > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IpB); if (IpB < 0 || IpB > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpB); if (IIpB < 0 || IIpB > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pB); if (pB < 0 || pB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zB); if (zB < 0 || zB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZiB); if (ZiB < 0 || ZiB > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IpM); if (IpM < 0 || IpM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpM); if (IIpM < 0 || IIpM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pM); if (pM < 0 || pM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zM); if (zM < 0 || zM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZiM); if (ZiM < 0 || ZiM > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BT = IpT + IIpT + zT + pT + ZiT;
   BB = IpB + IIpB + zB + pB + ZiB;
   BM = IpM + IIpM + zM + pM + ZiM;

   if (BT < 55)
   {
      OT = 5;
   }
   else if (BT >= 55 && BT < 65)
   {
      OT = 6;
   }
   else if (BT >= 65 && BT < 75)
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
   else if (BT >= 91 && BT <= 100)
   {
      OT = 10;
   }

   if (BM < 55)
   {
      OM = 5;
   }
   else if (BM >= 55 && BM < 65)
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
   else if (BM >= 91 && BM <= 100)
   {
      OM = 10;
   }

   if (BB < 55)
   {
      OB = 5;
   }
   else if (BB >= 55 && BB < 65)
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
   else if (BB >= 91 && BB <= 100)
   {
      OB = 10;
   }


   if (OT == 5 && OM == 5 && OB == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((OT > 5 && (OM == 5 && OB == 5)) || (OM > 5 && (OT == 5 && OB == 5)) || (OB > 5 && (OT == 5 && OM == 5)))
   {
      printf("Jedan student je polozio.");
   }
   else if ((OT == 5 && (OM > 5 && OB > 5)) || (OM == 5 && (OT > 5 && OB > 5)) || (OB == 5 && (OT > 5 && OM > 5)))
   {
      printf("Dva studenta su polozila.");
   }
   else if (OT > 5 && OM > 5 && OB > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (OT == OB && OB == OM)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (OT == OB && OB != OM)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (OT != OB && OB != OM)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
