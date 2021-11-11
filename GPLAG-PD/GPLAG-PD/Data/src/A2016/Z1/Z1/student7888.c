#include <stdio.h>

int main()
{
   double P1T, P2T, PRT, ZT, ZIT, P1B, P2B, PRB, ZB, ZIB, P1M, P2M, PRM, ZM, ZIM, Tarik, Bojan, Mirza;

   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit:");
   scanf("%lf", &P1T);
   if (P1T < 0 || P1T > 20)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &P2T);
   if (P2T < 0 || P2T > 20)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Prisustvo:");
   scanf("%lf", &PRT);
   if (PRT < 0 || PRT > 10)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Zadace:");
   scanf("%lf", &ZT);
   if (ZT < 0 || ZT > 10)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &ZIT);
   if (ZIT < 0 || ZIT > 40)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit:");
   scanf("%lf", &P1B);
   if (P1B < 0 || P1B > 20)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &P2B);
   if (P2B < 0 || P2B > 20)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Prisustvo:");
   scanf("%lf", &PRB);
   if (PRB < 0 || PRB > 10)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Zadace:");
   scanf("%lf", &ZB);
   if (ZB < 0 || ZB > 10)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &ZIB);
   if (ZIB < 0 || ZIB > 40)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit:");
   scanf("%lf", &P1M);
   if (P1M < 0 || P1M > 20)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &P2M);
   if (P2M < 0 || P2M > 20)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Prisustvo:");
   scanf("%lf", &PRM);
   if (PRM < 0 || PRM > 10)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Zadace:");
   scanf("%lf", &ZM);
   if (ZM < 0 || ZM > 10)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &ZIM);
   if (ZIM < 0 || ZIM > 40)
   {
      printf(" Neispravan broj bodova");
      return(1);
   }
   Tarik = P1T + P2T + PRT + ZT + ZIT;
   Bojan = P1B + P2B + PRB + ZB + ZIB;
   Mirza = P1M + P2M + PRM + ZM + ZIM;

   if (Tarik < 55 && Bojan < 55 && Mirza < 55)
   {
      printf(" Nijedan student nije polozio.\n");
      return(1);
   }
   else if ((Tarik >= 55 && Bojan < 55 && Mirza < 55) || (Tarik < 55 && Bojan >= 55 && Mirza < 55) || (Tarik < 55 && Bojan < 55 && Mirza >= 55))
   {
      printf(" Jedan student je polozio.\n");
      return(1);
   }
   else if ((Tarik >= 55 && Bojan >= 55 && Mirza < 55) || (Tarik >= 55 && Bojan < 55 && Mirza >= 55) || (Tarik < 55 && Bojan >= 55 && Mirza >= 55))
   {
      printf(" Dva studenta su polozila.\n");
      return(1);
   }
   else if (Tarik >= 55 && Bojan >= 55 && Mirza >= 55)
   {
      printf(" Sva tri studenta su polozila.\n");
   }

   if ((Tarik >= 55 && Tarik < 65) && (Bojan >= 55 && Bojan < 65) && (Mirza >= 55 && Mirza < 65))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }

   else if ((Tarik >= 65 && Tarik < 75) && (Bojan >= 65 && Bojan < 75) && (Mirza >= 65 && Mirza < 75))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }

   else if ((Tarik >= 75 && Tarik < 85) && (Bojan >= 75 && Bojan < 85) && (Mirza >= 75 && Mirza < 85))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 85 && Tarik < 92) && (Bojan >= 85 && Bojan < 92) && (Mirza >= 85 && Mirza < 92))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 92 && Tarik <= 100) && (Bojan >= 92 && Bojan <= 100) && (Mirza >= 92 && Mirza <= 100))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 55 && Tarik < 65) && (Bojan >= 55 && Bojan < 65) && (Mirza >= 65))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 65 && Tarik < 75) && (Bojan >= 65 && Bojan < 75) && ((Mirza >= 55) && (Mirza < 65) || (Mirza >= 75)))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 75 && Tarik < 85) && (Bojan >= 75 && Bojan < 85) && ((Mirza >= 55) && (Mirza < 75) || (Mirza >= 85)))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 85 && Tarik < 92) && (Bojan >= 85 && Bojan < 92) && ((Mirza >= 55) && (Mirza < 85) || (Mirza >= 92)))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 92 && Tarik <= 100) && (Bojan >= 92 && Bojan <= 100) && (Mirza < 92))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 65) && (Bojan >= 55 && Bojan < 65) && (Mirza >= 55 && Bojan < 65))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (((Tarik >= 55) && (Tarik < 65) || (Tarik >= 75)) && (Bojan >= 65 && Bojan < 75) && (Mirza >= 65 && Mirza < 75))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (((Tarik >= 55) && (Tarik < 75) || (Tarik >= 85)) && (Bojan >= 75 && Bojan < 85) && (Mirza >= 75 && Mirza < 85))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (((Tarik >= 55) && (Tarik < 85) || (Tarik >= 92)) && (Bojan >= 85 && Bojan < 92) && (Mirza >= 85 && Mirza < 92))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik < 92) && (Bojan >= 92 && Bojan <= 100) && (Mirza >= 92 && Mirza <= 100))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 55 && Tarik < 65) && (Bojan >= 65) && (Mirza >= 55 && Bojan < 65))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 65 && Tarik < 75) && ((Bojan < 65) || (Bojan >= 75)) && (Mirza >= 65 && Mirza < 75))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 75 && Tarik < 85) && ((Bojan < 75) || (Bojan >= 85)) && (Mirza >= 75 && Mirza < 85))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 85 && Tarik < 92) && ((Bojan < 85) || (Bojan >= 92)) && (Mirza >= 85 && Mirza < 92))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((Tarik >= 92 && Tarik <= 100) && (Bojan < 92) && (Mirza >= 92 && Mirza <= 100))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }

   return(0);
}
