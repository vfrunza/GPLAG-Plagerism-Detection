#include <stdio.h>
#include <math.h>
#define eps    0.000000000000000000000000000000001
int main()
{
   float IpiTarik, IIpiTarik, PTarik, ZTarik, ZITarik, IpiBojan, IIpiBojan, PBojan, ZBojan, ZIBojan, IpiMirza, IIpiMirza, PMirza, ZMirza, ZIMirza, T, B, M;
   int   ocjenaT, ocjenaB, ocjenaM;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &IpiTarik);
   if (IpiTarik > 20 || IpiTarik < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIpiTarik);
   if (IIpiTarik > 20 || IIpiTarik < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PTarik);
   if (PTarik > 10 || PTarik < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZTarik);
   if (ZTarik > 10 || ZTarik < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZITarik);
   if (ZITarik > 40 || ZITarik < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &IpiBojan);
   if (IpiBojan > 20 || IpiBojan < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIpiBojan);
   if (IIpiBojan > 20 || IIpiBojan < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PBojan);
   if (PBojan > 10 || PBojan < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZBojan);
   if (ZBojan > 10 || ZBojan < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIBojan);
   if (ZIBojan > 40 || ZIBojan < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &IpiMirza);
   if (IpiMirza > 20 || IpiMirza < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIpiMirza);
   if (IIpiMirza > 20 || IIpiMirza < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PMirza);
   if (PMirza > 10 || PMirza < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZMirza);
   if (ZMirza > 10 || ZMirza < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIMirza);
   if (ZIMirza > 40 || ZIMirza < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   T = IpiTarik + IIpiTarik + PTarik + ZTarik + ZITarik;
   B = IpiBojan + IIpiBojan + PBojan + ZBojan + ZIBojan;
   M = IpiMirza + IIpiMirza + PMirza + ZMirza + ZIMirza;

   if (T < 54.95 && B < 55 && M < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((T >= 54.95 && B < 55 && M < 55) || (T < 55 && B >= 55 && M < 55) || (T < 55 && B < 55 && M >= 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((T >= 55 && B >= 55 && M < 55) || (T < 55 && B >= 55 && M >= 55) || (T >= 55 && B < 55 && M >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   if (T >= 55 && B >= 55 && M >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }

   if (T < 55)
   {
      ocjenaT = 5;
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
      ocjenaB = 5;
   }
   if (B >= 55 && B < 65)
   {
      ocjenaB = 6;
   }
   if (B >= 65 && B < 75)
   {
      ocjenaB = 7;
   }
   if (B >= 75 && B < 85)
   {
      ocjenaB = 8;
   }
   if (B >= 85 && B < 92)
   {
      ocjenaB = 9;
   }
   if (B >= 92 && B <= 100)
   {
      ocjenaB = 10;
   }

   if (M < 55)
   {
      ocjenaM = 5;
   }
   if (M >= 55 && M < 65)
   {
      ocjenaM = 6;
   }
   if (M >= 65 && M < 75)
   {
      ocjenaM = 7;
   }
   if (M >= 75 && M < 85)
   {
      ocjenaM = 8;
   }
   if (M >= 85 && M < 92)
   {
      ocjenaM = 9;
   }
   if (M >= 92 && M <= 100)
   {
      ocjenaM = 10;
   }

   if (ocjenaT > 5 && ocjenaB > 5 && ocjenaM > 5)
   {
      if (ocjenaT == ocjenaB && ocjenaB == ocjenaM)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      if ((ocjenaT != ocjenaB) && (ocjenaB != ocjenaM) && (ocjenaT != ocjenaM))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      if (((ocjenaT == ocjenaB) && (ocjenaB != ocjenaM)) || ((ocjenaB == ocjenaM) && (ocjenaM != ocjenaT)) || ((ocjenaT == ocjenaM) && (ocjenaM != ocjenaB)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}
