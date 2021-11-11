#include <stdio.h>
#include <stdlib.h>

int main()
{
   float IparcT;
   float IIparcT;
   float prisustvoT;
   float zadaceT;
   float zavrsniT;

   float IparcB;
   float IIparcB;
   float prisustvoB;
   float zadaceB;
   float zavrsniB;

   float IparcM;
   float IIparcM;
   float prisustvoM;
   float zadaceM;
   float zavrsniM;

   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &IparcT);
   if (IparcT > 20 || IparcT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcT);
   if (IIparcT > 20 || IIparcT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvoT);
   if (prisustvoT > 10 || prisustvoT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadaceT);
   if (zadaceT > 10 || zadaceT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniT);
   if (zavrsniT > 40 || zavrsniT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &IparcB);
   if (IparcB > 20 || IparcB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcB);
   if (IIparcB > 20 || IIparcB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvoB);
   if (prisustvoB > 10 || prisustvoB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadaceB);
   if (zadaceB > 10 || zadaceB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniB);
   if (zavrsniB > 40 || zavrsniB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &IparcM);
   if (IparcM > 20 || IparcM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcM);
   if (IIparcM > 20 || IIparcM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvoM);
   if (prisustvoM > 10 || prisustvoM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadaceM);
   if (zadaceM > 10 || zadaceM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniM);
   if (zavrsniM > 40 || zavrsniM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   float sumaT = IparcT + IIparcT + prisustvoT + zadaceT + zavrsniT;
   float sumaB = IparcB + IIparcB + prisustvoB + zadaceB + zavrsniB;
   float sumaM = IparcM + IIparcM + prisustvoM + zadaceM + zavrsniM;

   if (sumaT - 0.001 < 55 && sumaT - 0.001 > 54)
   {
      sumaT = 55;
   }

   //printf("%f %f %f\n", sumaT, sumaB, sumaM);

   int ocjenaT, ocjenaB, ocjenaM;

   if (sumaT < 55)
   {
      ocjenaT = 5;
   }
   if (sumaB < 55)
   {
      ocjenaB = 5;
   }
   if (sumaM < 55)
   {
      ocjenaM = 5;
   }
   if (sumaT >= 55 && sumaT < 65)
   {
      ocjenaT = 6;
   }
   if (sumaB >= 55 && sumaB < 65)
   {
      ocjenaB = 6;
   }
   if (sumaM >= 55 && sumaM < 65)
   {
      ocjenaM = 6;
   }
   if (sumaT >= 65 && sumaT < 75)
   {
      ocjenaT = 7;
   }
   if (sumaB >= 65 && sumaB < 75)
   {
      ocjenaB = 7;
   }
   if (sumaM >= 65 && sumaM < 75)
   {
      ocjenaM = 7;
   }
   if (sumaT >= 75 && sumaT < 85)
   {
      ocjenaT = 8;
   }
   if (sumaB >= 75 && sumaB < 85)
   {
      ocjenaB = 8;
   }
   if (sumaM >= 75 && sumaM < 85)
   {
      ocjenaM = 8;
   }
   if (sumaT >= 85 && sumaT < 92)
   {
      ocjenaT = 9;
   }
   if (sumaB >= 85 && sumaB < 92)
   {
      ocjenaB = 9;
   }
   if (sumaM >= 85 && sumaM < 92)
   {
      ocjenaM = 9;
   }
   if (sumaT >= 92 && sumaT <= 100)
   {
      ocjenaT = 10;
   }
   if (sumaB >= 92 && sumaB <= 100)
   {
      ocjenaB = 10;
   }
   if (sumaM >= 92 && sumaM <= 100)
   {
      ocjenaM = 10;
   }

   //printf("%d %d %d \n", ocjenaT, ocjenaB, ocjenaM);

   if (ocjenaB == 5 && ocjenaM == 5 && ocjenaT == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }

   else if (ocjenaB == 5 && (ocjenaM > 5 && ocjenaT > 5))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (ocjenaM == 5 && (ocjenaB > 5 && ocjenaT > 5))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (ocjenaT == 5 && (ocjenaM > 5 && ocjenaB > 5))
   {
      printf("Dva studenta su polozila.\n");
   }

   else if (ocjenaT == 5 && ocjenaB == 5 && ocjenaM != 5)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (ocjenaB != 5 && ocjenaM == 5 && ocjenaT == 5)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (ocjenaT != 5 && ocjenaM == 5 && ocjenaB == 5)
   {
      printf("Jedan student je polozio.\n");
   }

   else if (ocjenaB > 5 && ocjenaM > 5 && ocjenaT > 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if ((ocjenaB == ocjenaM) && (ocjenaB == ocjenaT) && (ocjenaM == ocjenaT))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((ocjenaB != ocjenaM) && (ocjenaB == ocjenaT))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if ((ocjenaB == ocjenaM) && (ocjenaB != ocjenaT))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if ((ocjenaB == ocjenaM) && (ocjenaM != ocjenaT))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if ((ocjenaB != ocjenaM) && (ocjenaB != ocjenaT) && (ocjenaM != ocjenaT))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
