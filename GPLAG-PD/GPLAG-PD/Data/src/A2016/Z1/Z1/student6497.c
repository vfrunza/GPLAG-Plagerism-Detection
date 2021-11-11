#include <stdio.h>

int main()
{
   double prviT, drugiT, zadT, prisT, zavrsT, prviB, drugiB, zadB, prisB, zavrsB, prviM, drugiM, zadM, prisM, zavrsM, zbirT, zbirB, zbirM;
   int    ocT, ocB, ocM, polozili = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prviT);
   if (prviT < 0 || prviT > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiT);
   if (drugiT < 0 || drugiT > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisT);
   if (prisT < 0 || prisT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadT);
   if (zadT < 0 || zadT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsT);
   if (zavrsT < 0 || zavrsT > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prviB);
   if (prviB < 0 || prviB > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiB);
   if (drugiB < 0 || drugiB > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisB);
   if (prisB < 0 || prisB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadB);
   if (zadB < 0 || zadB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsB);
   if (zavrsB < 0 || zavrsB > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prviM);
   if (prviM < 0 || prviM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiM);
   if (drugiM < 0 || drugiM > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisM);
   if (prisM < 0 || prisM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadM);
   if (zadM < 0 || zadM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsM);
   if (zavrsM < 0 || zavrsM > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   zbirT = prviT + drugiT + prisT + zadT + zavrsT;
   zbirB = prviB + drugiB + prisB + zadB + zavrsB;
   zbirM = prviM + drugiM + prisM + zadM + zavrsM;

   if (zbirT < 55)
   {
      ocT = 5;
   }
   else if (zbirT < 65)
   {
      ocT = 6;
   }
   else if (zbirT < 75)
   {
      ocT = 7;
   }
   else if (zbirT < 85)
   {
      ocT = 8;
   }
   else if (zbirT < 92)
   {
      ocT = 9;
   }
   else
   {
      ocT = 10;
   }

   if (zbirB < 55)
   {
      ocB = 5;
   }
   else if (zbirB < 65)
   {
      ocB = 6;
   }
   else if (zbirB < 75)
   {
      ocB = 7;
   }
   else if (zbirB < 85)
   {
      ocB = 8;
   }
   else if (zbirB < 92)
   {
      ocB = 9;
   }
   else
   {
      ocB = 10;
   }

   if (zbirM < 55)
   {
      ocM = 5;
   }
   else if (zbirM < 65)
   {
      ocM = 6;
   }
   else if (zbirM < 75)
   {
      ocM = 7;
   }
   else if (zbirM < 85)
   {
      ocM = 8;
   }
   else if (zbirM < 92)
   {
      ocM = 9;
   }
   else
   {
      ocM = 10;
   }

   if (ocT > 5)
   {
      polozili++;
   }
   if (ocB > 5)
   {
      polozili++;
   }
   if (ocM > 5)
   {
      polozili++;
   }

   if (polozili == 3)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if (polozili == 2)
   {
      printf("Dva studenta su polozila.\n"); return(0);
   }
   else if (polozili == 1)
   {
      printf("Jedan student je polozio.\n"); return(0);
   }
   else
   {
      printf("Nijedan student nije polozio.\n"); return(0);
   }

   if (ocT == ocB && ocB == ocM)
   {
      printf("Sva tri studenta imaju istu ocjenu.");
   }
   else if (ocT != ocB && ocB != ocM)
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
   else
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }

   return(0);
}
