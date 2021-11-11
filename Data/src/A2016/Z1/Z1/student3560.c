#include <stdio.h>

int main()
{
   double T, B, M, prviparcT, prviparcB, prviparcM, drugiparcT, drugiparcB, drugiparcM, prisustvoT, prisustvoB, prisustvoM, zadacaT, zadacaB, zadacaM, zavrsniT, zavrsniB, zavrsniM, ocjenaT, ocjenaB, ocjenaM;

   printf("Unesite bodove Tarika na I parcijalnom ispitu:");
   scanf("%lf", &prviparcT);
   if (prviparcT < 0 || prviparcT > 20)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Bojana na I parcijalnom ispitu:");
   scanf("%lf", &prviparcB);
   if (prviparcB < 0 || prviparcB > 20)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Mirze na I parcijalnom ispitu:");
   scanf("%lf", &prviparcM);
   if (prviparcM < 0 || prviparcM > 20)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Tarika na II parcijalnom ispitu:");
   scanf("%lf", &drugiparcT);
   if (drugiparcT < 0 || drugiparcT > 20)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Bojana na II parcijalnom ispitu:");
   scanf("%lf", &drugiparcB);
   if (drugiparcB < 0 || drugiparcB > 20)
   {
      printf("\nNeispravan broj bodova");
   }
   printf("\nUnesite bodove Mirze na II parcijalnom ispitu:");
   scanf("%lf", &drugiparcM);
   if (drugiparcM < 0 || drugiparcM > 20)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Tarika na prisustvo:");
   scanf("%lf", &prisustvoT);
   if (prisustvoT < 0 || prisustvoT > 10)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Bojana na prisustvo:");
   scanf("%lf", &prisustvoB);
   if (prisustvoB < 0 || prisustvoB > 10)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Mirze na prisustvo:");
   scanf("%lf", &prisustvoM);
   if (prisustvoM < 0 || prisustvoM > 10)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Tarika za zadace:");
   scanf("%lf", &zadacaT);
   if (zadacaT < 0 || zadacaT > 10)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Bojana za zadace:");
   scanf("%lf", &zadacaB);
   if (zadacaB < 0 || zadacaB > 10)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Mirze za zadace:");
   scanf("%lf", &zadacaM);
   if (zadacaM < 0 || zadacaM > 10)
   {
      printf("\nNeispravan broj bodova");
   }
   printf("\nUnesite bodove Tarika na zavrsnom ispitu:");
   scanf("%lf", &zavrsniT);
   if (zavrsniT < 0 || zavrsniT > 40)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Bojana na zavrsnom ispitu:");
   scanf("%lf", &zavrsniB);
   if (zavrsniB < 0 || zavrsniB > 40)
   {
      printf("Neispravan broj bodova");
   }
   printf("\nUnesite bodove Mirze na zavrsnom ispitu:");
   scanf("%lf", &zavrsniT);
   if (zavrsniM < 0 || zavrsniM > 40)
   {
      printf("Neispravan broj bodova");
   }
   T = prviparcT + drugiparcT + prisustvoT + zadacaT + zavrsniT;
   B = prviparcB + drugiparcB + prisustvoB + zadacaB + zavrsniB;
   M = prviparcM + drugiparcM + prisustvoM + zadacaM + zavrsniM;

   if (T < 55)
   {
      printf("student pao");
   }
   if (T >= 55 && T < 65)
   {
      ocjenaT = 6;
   }
   if (T >= 65 && T < 75)
   {
      ocjenaT = 7;
   }
   if (T >= 75 && T < 85)
   {
      ocjenaT = 8;
   }
   if (T >= 85 && T < 92)
   {
      ocjenaT = 9;
   }
   if (T >= 92 && T <= 100)
   {
      ocjenaT = 10;
   }
   if (B < 55)
   {
      printf("student pao");
   }

   if (B >= 55 && T < 65)
   {
      ocjenaB = 6;
   }
   if (B >= 65 && T < 75)
   {
      ocjenaB = 7;
   }
   if (B >= 75 && T < 85)
   {
      ocjenaB = 8;
   }
   if (B >= 85 && T < 92)
   {
      ocjenaB = 9;
   }
   if (B >= 92 && T <= 100)
   {
      ocjenaB = 10;
   }

   if (M < 55)
   {
      printf("student pao");
   }
   if (M >= 55 && T < 65)
   {
      ocjenaM = 6;
   }
   if (M >= 65 && T < 75)
   {
      ocjenaM = 7;
   }
   if (M >= 75 && T < 85)
   {
      ocjenaM = 8;
   }
   if (M >= 85 && T < 92)
   {
      ocjenaM = 9;
   }
   if (M >= 92 && T <= 100)
   {
      ocjenaM = 10;
   }

   if (T < 55 & B < 55 && M < 55)
   {
      printf("\nNijedan student nije polozio.");
   }
   else if (T >= 55 && B >= 55 && M >= 55)
   {
      printf("\nSva tri studenta su polozila.");
   }
   else if (T >= 55 || B >= 55 || M >= 55)
   {
      printf("\nJedan student je polozio.");
   }
   else if ((T >= 6 && B >= 6) || (T >= 6 && M >= 6) || (B >= 6 && M >= 6))
   {
      printf("\nDva studenta su polozila.");
   }

   if (ocjenaT == ocjenaB && ocjenaB == ocjenaM && ocjenaT == ocjenaM)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else if (ocjenaT == ocjenaB || ocjenaB == ocjenaM || ocjenaT == ocjenaM)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }


   return(0);
}
