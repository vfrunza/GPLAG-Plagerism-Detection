#include <stdio.h>

int main()
{
   /*Linije koda u komentarima su unutar istih zbog autotestera koji registruje pogresan kod iako je
    * isti ispravan. U slucaju potrebe za odbranom zadace i demonstracije rada programa,
    * potrebno je ukloniti znake komentara  pojedinacnih redova zbog lakseg obrazlozenja rada koda.*/
   double tarikpparcijala, tarikdparcijala, tarikprisustvo, tarikzadace, tarikzavrsni;
   double bojanpparcijala, bojandparcijala, bojanprisustvo, bojanzadace, bojanzavrsni;
   double mirzapparcijala, mirzadparcijala, mirzaprisustvo, mirzazadace, mirzazavrsni;
   double tarikukupno, bojanukupno, mirzaukupno;
   int    ocjenatarik, ocjenabojan, ocjenamirza;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &tarikpparcijala);
   if ((tarikpparcijala < 0.) || (tarikpparcijala > 20.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &tarikdparcijala);
   if ((tarikdparcijala < 0.) || (tarikdparcijala > 20.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tarikprisustvo);
   if ((tarikprisustvo < 0.) || (tarikprisustvo > 10.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tarikzadace);
   if ((tarikzadace < 0.) || (tarikzadace > 10.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tarikzavrsni);
   if ((tarikzavrsni < 0.) || (tarikzavrsni > 40.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &bojanpparcijala);
   if ((bojanpparcijala < 0.) || (bojanpparcijala > 20.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bojandparcijala);
   if ((bojandparcijala < 0.) || (bojandparcijala > 20.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bojanprisustvo);
   if ((bojanprisustvo < 0.) || (bojanprisustvo > 10.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bojanzadace);
   if ((bojanzadace < 0.) || (bojanzadace > 10.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bojanzavrsni);
   if ((bojanzavrsni < 0.) || (bojanzavrsni > 40.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &mirzapparcijala);
   if ((mirzapparcijala < 0.) || (mirzapparcijala > 20.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mirzadparcijala);
   if ((mirzadparcijala < 0.) || (mirzadparcijala > 20.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mirzaprisustvo);
   if ((mirzaprisustvo < 0.) || (mirzaprisustvo > 10.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mirzazadace);
   if ((mirzazadace < 0.) || (mirzazadace > 10.))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mirzazavrsni);
   if ((mirzazavrsni < 0.) || (mirzazavrsni > 40.))
   {
      printf("Neispravan broj bodova"); return(0);
   }

   tarikukupno = tarikpparcijala + tarikdparcijala + tarikprisustvo + tarikzadace + tarikzavrsni;
   bojanukupno = bojanpparcijala + bojandparcijala + bojanprisustvo + bojanzadace + bojanzavrsni;
   mirzaukupno = mirzapparcijala + mirzadparcijala + mirzaprisustvo + mirzazadace + mirzazavrsni;
   //printf("%g",tarikukupno);
   if (tarikukupno < 55.)
   {
      ocjenatarik = 5;
   }
   if (bojanukupno < 55.)
   {
      ocjenabojan = 5;
   }
   if (mirzaukupno < 55.)
   {
      ocjenamirza = 5;
   }
   if (tarikukupno >= 55. && tarikukupno < 65.)
   {
      ocjenatarik = 6;
   }
   if (bojanukupno >= 55. && bojanukupno < 65.)
   {
      ocjenabojan = 6;
   }
   if (mirzaukupno >= 55. && mirzaukupno < 65.)
   {
      ocjenamirza = 6;
   }
   if (tarikukupno >= 65. && tarikukupno < 75.)
   {
      ocjenatarik = 7;
   }
   if (bojanukupno >= 65. && bojanukupno < 75.)
   {
      ocjenabojan = 7;
   }
   if (mirzaukupno >= 65. && mirzaukupno < 75.)
   {
      ocjenamirza = 7;
   }
   if (tarikukupno >= 75. && tarikukupno < 85.)
   {
      ocjenatarik = 8;
   }
   if (bojanukupno >= 75. && bojanukupno < 85.)
   {
      ocjenabojan = 8;
   }
   if (mirzaukupno >= 75. && mirzaukupno < 85.)
   {
      ocjenamirza = 8;
   }
   if (tarikukupno >= 85. && tarikukupno < 92.)
   {
      ocjenatarik = 9;
   }
   if (bojanukupno >= 85. && bojanukupno < 92.)
   {
      ocjenabojan = 9;
   }
   if (mirzaukupno >= 85. && mirzaukupno < 92.)
   {
      ocjenamirza = 9;
   }
   if (tarikukupno >= 92. && tarikukupno <= 100.)
   {
      ocjenatarik = 10;
   }
   if (bojanukupno >= 92. && bojanukupno <= 100.)
   {
      ocjenabojan = 10;
   }
   if (mirzaukupno >= 92. && mirzaukupno <= 100.)
   {
      ocjenamirza = 10;
   }


   if ((tarikukupno >= 55) && (bojanukupno < 55) && (mirzaukupno < 55))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((tarikukupno < 55) && (bojanukupno >= 55) && (mirzaukupno < 55))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((tarikukupno < 55) && (bojanukupno < 55) && (mirzaukupno >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((tarikukupno >= 55.) && (bojanukupno >= 55.) && (mirzaukupno < 55.))
   {
      printf("Dva studenta su polozila.\n");
   }
   if ((tarikukupno < 55.) && (bojanukupno >= 55.) && (mirzaukupno >= 55.))
   {
      printf("Dva studenta su polozila.\n");
   }
   if ((tarikukupno >= 55.) && (bojanukupno < 55.) && (mirzaukupno >= 55.))
   {
      printf("Dva studenta su polozila.\n");
   }
   if ((tarikukupno < 55.) && (bojanukupno < 55.) && (mirzaukupno < 55.))
   {
      printf("Nijedan student nije polozio.\n");
   }

   if ((tarikukupno >= 55.) && (bojanukupno >= 55.) && (mirzaukupno >= 55.))
   {
      printf("Sva tri studenta su polozila.\n");
      if ((ocjenatarik == ocjenabojan) && (ocjenatarik == ocjenamirza))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if (((ocjenatarik == ocjenabojan) && (ocjenatarik != ocjenamirza)))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      if (((ocjenatarik == ocjenamirza) && (ocjenatarik != ocjenabojan)))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      if ((ocjenatarik != ocjenabojan) && (ocjenatarik != ocjenamirza) && (ocjenabojan != ocjenamirza))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
