#include <stdio.h>

int main()
{
   double parc1T, parc2T, zadT, prisT, zavrsT, parc1B, parc2B, zadB, prisB, zavrsB, parc1M, parc2M, zadM, prisM, zavrsM, ukT, ukB, ukM;
   int    ocjenaT, ocjenaM, ocjenaB;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &parc1T);
   if (parc1T < 0 || parc1T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &parc2T);
   if (parc2T < 0 || parc2T > 20)
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
   scanf("%lf", &zavrsT);
   if (zavrsT < 0 || zavrsT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &parc1B);
   if (parc1B < 0 || parc1B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &parc2B);
   if (parc2B < 0 || parc2B > 20)
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
   scanf("%lf", &zavrsB);
   if (zavrsB < 0 || zavrsB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &parc1M);
   if (parc1M < 0 || parc1M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &parc2M);
   if (parc2M < 0 || parc2M > 20)
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
   scanf("%lf", &zavrsM);
   if (zavrsM < 0 || zavrsM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ukT = parc1T + parc2T + zadT + prisT + zavrsT;
   ukM = parc1M + parc2M + zadM + prisM + zavrsM;
   ukB = parc1B + parc2B + zadB + prisB + zavrsB;
   if (ukT < 55 && ukB < 55 && ukM < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (ukT >= 55 && ukM >= 55 && ukB >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if ((ukT >= 55 && ukM >= 55) || (ukT >= 55 && ukB >= 55) || (ukM >= 55 && ukB >= 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((ukT >= 55) || (ukM >= 55) || (ukB >= 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((ukT >= 55) && (ukT < 65))
   {
      ocjenaT = 6;
   }
   else if (ukT >= 65 && ukT < 75)
   {
      ocjenaT = 7;
   }
   else if (ukT >= 75 && ukT < 85)
   {
      ocjenaT = 8;
   }
   else if (ukT >= 85 && ukT < 92)
   {
      ocjenaT = 9;
   }
   else
   {
      ocjenaT = 10;
   }
   if ((ukM >= 55) && (ukM < 65))
   {
      ocjenaM = 6;
   }
   else if (ukM >= 65 && ukM < 75)
   {
      ocjenaM = 7;
   }
   else if (ukM >= 75 && ukM < 85)
   {
      ocjenaM = 8;
   }
   else if (ukM >= 85 && ukM < 92)
   {
      ocjenaM = 9;
   }
   else
   {
      ocjenaM = 10;
   }
   if ((ukB >= 55) && (ukB < 65))
   {
      ocjenaB = 6;
   }
   else if (ukB >= 65 && ukB < 75)
   {
      ocjenaB = 7;
   }
   else if (ukB >= 75 && ukB < 85)
   {
      ocjenaB = 8;
   }
   else if (ukB >= 85 && ukB < 92)
   {
      ocjenaB = 9;
   }
   else
   {
      ocjenaB = 10;
   }
   if (ukT >= 55 && ukM >= 55 && ukB >= 55)
   {
      if ((ocjenaT == ocjenaB) && (ocjenaB == ocjenaM))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((ocjenaT == ocjenaM) || (ocjenaT == ocjenaB) || (ocjenaB == ocjenaM))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
