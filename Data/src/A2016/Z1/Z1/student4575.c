#include <stdio.h>
#include <math.h>
int main()
{
   double TI, TII, TP, TZ, TZI, T, t, TO, BI, BII, BP, BZ, BZI, B, BO, b, MI, MII, MP, MZ, MZI, M, MO, m;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &TI);
   if (TI < 0 || TI > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &TII);
   if (TII < 0 || TII > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &TP);
   if (TP < 0 || TP > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &TZ);
   if (TZ < 0 || TZ > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &TZI);
   if (TZI < 0 || TZI > 40)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   T = TI + TII + TP + TZ + TZI;
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &BI);
   if (BI < 0 || BI > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BII);
   if (BII < 0 || BII > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BP);
   if (BP < 0 || BP > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BZ);
   if (BZ < 0 || BZ > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &BZI);
   if (BZI < 0 || BZI > 40)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   B = BI + BII + BP + BZ + BZI;
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &MI);
   if (MI < 0 || MI > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MII);
   if (MII < 0 || MII > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MP);
   if (MP < 0 || MP > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &MZ);
   if (MZ < 0 || MZ > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &MZI);
   if (MZI < 0 || MZI > 40)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   M = MI + MII + MP + MZ + MZI;
   if (T >= 55 && B >= 55 && M >= 55)
   {
      printf("Sva tri studenta su polozila. \n");
   }
   if ((T >= 55 && B >= 55 && M < 55) || (T >= 55 && B < 55 && M >= 55) || (T < 55 && B >= 55 && M >= 55))
   {
      printf("Dva studenta su polozila. \n");
   }
   if ((T >= 55 && B < 55 && M < 55) || (T < 55 && B >= 55 && M < 55) || (T < 55 && B < 55 && M >= 55))
   {
      printf("Jedan student je polozio. \n");
   }
   if (T < 55 && B < 55 && M < 55)
   {
      printf("Nijedan student nije polozio. \n");
   }
   TO = (TI + TII + TP + TZ + TZI) / 10.0;
   t  = round(TO);
   BO = (BI + BII + BP + BZ + BZI) / 10.0;
   b  = round(BO);
   MO = (MI + MII + MP + MZ + MZI) / 10.0;
   m  = round(MO);
   if ((T >= 55 && B >= 55 && M >= 55) && (t == b && b == m))
   {
      printf("Sva tri studenta imaju istu ocjenu. \n");
   }
   if ((T >= 55 && B >= 55 && M >= 55) && ((t == b && b != m) || (t != b && b == m) || (t == m && b != m)))
   {
      printf("Dva od tri studenta imaju istu ocjenu. \n");
   }
   if ((T >= 55 && B >= 55 && M >= 55) && (t != b && b != m && m != t))
   {
      printf("Svaki student ima razlicitu ocjenu. \n");
   }
   return(0);
}
