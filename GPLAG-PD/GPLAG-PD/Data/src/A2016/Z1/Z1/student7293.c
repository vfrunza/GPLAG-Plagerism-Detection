#include <stdio.h>

int main()
{
   double T1, T2, TZAD, TP, TZI, BT, Tarik = 0, B1, B2, BZAD, BP, BZI, BB, Bojan = 0, M1, M2, MZAD, MP, MZI, BM, Mirza = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &T2);
   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &TP);
   if (TP < 0 || TP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &TZAD);
   if (TZAD < 0 || TZAD > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &TZI);
   if (TZI < 0 || TZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BT = T1 + T2 + TP + TZAD + TZI;

   if (BT < 55)
   {
      Tarik = 0;
   }
   else if (BT >= 55 && BT < 65)
   {
      Tarik = 6;
   }
   else if (BT >= 65 && BT < 75)
   {
      Tarik = 7;
   }
   else if (BT >= 75 && BT < 85)
   {
      Tarik = 8;
   }
   else if (BT >= 85 && BT < 92)
   {
      Tarik = 9;
   }
   else if (BT >= 92 && BT <= 100)
   {
      Tarik = 10;
   }


   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BP);
   if (BP < 0 || BP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BZAD);
   if (BZAD < 0 || BZAD > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &BZI);
   if (BZI < 0 || BZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BB = B1 + B2 + BP + BZAD + BZI;

   if (BB < 55)
   {
      Bojan = 0;
   }
   else if (BB >= 55 && BB < 65)
   {
      Bojan = 6;
   }
   else if (BB >= 65 && BB < 75)
   {
      Bojan = 7;
   }
   else if (BB >= 75 && BB < 85)
   {
      Bojan = 8;
   }
   else if (BB >= 85 && BB < 92)
   {
      Bojan = 9;
   }
   else if (BB >= 92 && BB <= 100)
   {
      Bojan = 10;
   }


   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &M1);
   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &M2);
   if (M2 < 0 || M2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MP);
   if (MP < 0 || MP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &MZAD);
   if (MZAD < 0 || MZAD > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &MZI);
   if (MZI < 0 || MZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BM = M1 + M2 + MP + MZAD + MZI;

   if (BM < 55)
   {
      Mirza = 0;
   }
   else if (BM >= 55 && BM < 65)
   {
      Mirza = 6;
   }
   else if (BM >= 65 && BM < 75)
   {
      Mirza = 7;
   }
   else if (BM >= 75 && BM < 85)
   {
      Mirza = 8;
   }
   else if (BM >= 85 && BM < 92)
   {
      Mirza = 9;
   }
   else if (BM >= 92 && BM <= 100)
   {
      Mirza = 10;
   }


   if (Tarik == 0 && Bojan == 0 && Mirza == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((Tarik == 6 || Tarik == 7 || Tarik == 8 || Tarik == 9 || Tarik == 10) && Bojan == 0 && Mirza == 0)
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((Bojan == 6 || Bojan == 7 || Bojan == 8 || Bojan == 9 || Bojan == 10) && Tarik == 0 && Mirza == 0)
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((Mirza == 6 || Mirza == 7 || Mirza == 8 || Mirza == 9 || Mirza == 10) && Tarik == 0 && Bojan == 0)
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((Tarik == 6 || Tarik == 7 || Tarik == 8 || Tarik == 9 || Tarik == 10) && (Bojan == 6 || Bojan == 7 || Bojan == 8 || Bojan == 9 || Bojan == 10) && Mirza == 0)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((Tarik == 6 || Tarik == 7 || Tarik == 8 || Tarik == 9 || Tarik == 10) && (Mirza == 6 || Mirza == 7 || Mirza == 8 || Mirza == 9 || Mirza == 10) && Bojan == 0)
   {
      printf("Dva studenta su polozila.,\n");
   }
   else if ((Bojan == 6 || Bojan == 7 || Bojan == 8 || Bojan == 9 || Bojan == 10) && (Mirza == 6 || Mirza == 7 || Mirza == 8 || Mirza == 9 || Mirza == 10) && Tarik == 0)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
   }


   if (Tarik == Bojan && Bojan == Mirza && Tarik != 0 && Bojan != 0 && Mirza != 0)
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if (Tarik == Bojan && Bojan != Mirza && Mirza != 0 && Tarik != 0)
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (Tarik == Mirza && Mirza != Bojan && Bojan != 0 && Tarik != 0)
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (Bojan == Mirza && Mirza != Tarik && Tarik != 0 && Bojan != 0)
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (Tarik != Bojan && Tarik != Mirza && Bojan != Mirza && Tarik != 0 && Bojan != 0 && Mirza != 0)
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }

   return(0);
}
