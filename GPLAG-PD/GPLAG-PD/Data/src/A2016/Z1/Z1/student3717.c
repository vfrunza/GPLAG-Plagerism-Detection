#include <stdio.h>

int main()
{
   double P1T, P1B, P1M, P2T, P2B, P2M, prisT, prisB, prisM, zadT, zadB, zadM, zavT, zavB, zavM, bodT, bodB, bodM, ocT, ocB, ocM;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1T);
   if (P1T < 0 || P1T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2T);
   if (P2T < 0 || P2T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisT);
   if (prisT < 0 || prisT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadT);
   if (zadT < 0 || zadT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavT);
   if (zavT < 0 || zavT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1B);
   if (P1B < 0 || P1B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2B);
   if (P2B < 0 || P2B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisB);
   if (prisB < 0 || prisB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadB);
   if (zadB < 0 || zadB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavB);
   if (zavB < 0 || zavB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1M);
   if (P1M < 0 || P1M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2M);
   if (P2M < 0 || P2M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisM);
   if (prisM < 0 || prisM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadM);
   if (zadM < 0 || zadM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavM);
   if (zavM < 0 || zavM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bodT = P1T + P2T + prisT + zadT + zavT;
   bodB = P1B + P2B + prisB + zadB + zavB;
   bodM = P1M + P2M + prisM + zadM + zavM;

   if (bodT < 55)
   {
      ocT = 5;
   }
   else if (bodT >= 55 && bodT < 65)
   {
      ocT = 6;
   }
   else if (bodT >= 65 && bodT < 75)
   {
      ocT = 7;
   }
   else if (bodT >= 75 && bodT < 85)
   {
      ocT = 8;
   }
   else if (bodT >= 85 && bodT < 92)
   {
      ocT = 9;
   }
   else if (bodT >= 92 && bodT <= 100)
   {
      ocT = 10;
   }
   if (bodB < 55)
   {
      ocB = 5;
   }
   else if (bodB >= 55 && bodB < 65)
   {
      ocB = 6;
   }
   else if (bodB >= 65 && bodB < 75)
   {
      ocB = 7;
   }
   else if (bodB >= 75 && bodB < 85)
   {
      ocB = 8;
   }
   else if (bodB >= 85 && bodB < 92)
   {
      ocB = 9;
   }
   else if (bodB >= 92 && bodB <= 100)
   {
      ocB = 10;
   }
   if (bodM < 55)
   {
      ocM = 5;
   }
   else if (bodM >= 55 && bodM < 65)
   {
      ocM = 6;
   }
   else if (bodM >= 65 && bodM < 75)
   {
      ocM = 7;
   }
   else if (bodM >= 75 && bodM < 85)
   {
      ocM = 8;
   }
   else if (bodM >= 85 && bodM < 92)
   {
      ocM = 9;
   }
   else if (bodM >= 92 && bodM <= 100)
   {
      ocM = 10;
   }

   if (bodT < 55 && bodB < 55 && bodM < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((bodT >= 55 && bodB < 55 && bodM < 55) || (bodT < 55 && bodB >= 55 && bodM < 55) || (bodT < 55 && bodB < 55 && bodM >= 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((bodT >= 55 && bodB >= 55 && bodM < 55) || (bodT >= 55 && bodB < 55 && bodM >= 55) || (bodT < 55 && bodB >= 55 && bodM >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.");
      if (ocT - ocB == 0 && ocB - ocM == 0)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (ocT - ocB == 0 || ocT - ocM == 0 || ocB - ocM == 0)
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
