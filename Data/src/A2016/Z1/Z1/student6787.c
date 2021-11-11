#include <stdio.h>

int main()
{
   float bTarik1, bTarik2, prisustvoTarik, zadaceTarik, zavrsniTarik;
   float bBojan1, bBojan2, prisustvoBojan, zadaceBojan, zavrsniBojan;
   float bMirza1, bMirza2, prisustvoMirza, zadaceMirza, zavrsniMirza;
   int   ocjenaTarik, ocjenaBojan, ocjenaMirza, prolaz = 0;
   float zbir;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bTarik1);
   if (bTarik1 < 0 || bTarik1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &bTarik2);
   if (bTarik2 < 0 || bTarik2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvoTarik);
   if (prisustvoTarik < 0 || prisustvoTarik > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadaceTarik);
   if (zadaceTarik < 0 || zadaceTarik > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniTarik);
   if (zavrsniTarik < 0 || zavrsniTarik > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bBojan1);
   if (bBojan1 < 0 || bBojan1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &bBojan2);
   if (bBojan2 < 0 || bBojan2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvoBojan);
   if (prisustvoBojan < 0 || prisustvoBojan > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadaceBojan);
   if (zadaceBojan < 0 || zadaceBojan > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniBojan);
   if (zavrsniBojan < 0 || zavrsniBojan > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bMirza1);
   if (bMirza1 < 0 || bMirza1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &bMirza2);
   if (bMirza2 < 0 || bMirza2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvoMirza);
   if (prisustvoMirza < 0 || prisustvoMirza > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadaceMirza);
   if (zadaceMirza < 0 || zadaceMirza > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniMirza);
   if (zavrsniMirza < 0 || zavrsniMirza > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   zbir = (bTarik1 + bTarik2 + prisustvoTarik + zadaceTarik + zavrsniTarik);
   if (zbir >= 54.999 && zbir < 65)
   {
      ocjenaTarik = 6;
   }
   else if (zbir >= 64.999 && zbir < 75)
   {
      ocjenaTarik = 7;
   }
   else if (zbir >= 74.999 && zbir < 85)
   {
      ocjenaTarik = 8;
   }
   else if (zbir >= 84.999 && zbir < 92)
   {
      ocjenaTarik = 9;
   }
   else if (zbir >= 91.999 && zbir < 100)
   {
      ocjenaTarik = 10;
   }
   else
   {
      ocjenaTarik = 5;
   }

   zbir = (bBojan1 + bBojan2 + prisustvoBojan + zadaceBojan + zavrsniBojan);
   if (zbir >= 54.999 && zbir < 65)
   {
      ocjenaBojan = 6;
   }
   else if (zbir >= 64.999 && zbir < 75)
   {
      ocjenaBojan = 7;
   }
   else if (zbir >= 74.999 && zbir < 85)
   {
      ocjenaBojan = 8;
   }
   else if (zbir >= 84.999 && zbir < 92)
   {
      ocjenaBojan = 9;
   }
   else if (zbir >= 91.999 && zbir < 100)
   {
      ocjenaBojan = 10;
   }
   else
   {
      ocjenaBojan = 5;
   }

   zbir = (bMirza1 + bMirza2 + prisustvoMirza + zadaceMirza + zavrsniMirza);
   if (zbir >= 54.999 && zbir < 65)
   {
      ocjenaMirza = 6;
   }
   else if (zbir >= 64.999 && zbir < 75)
   {
      ocjenaMirza = 7;
   }
   else if (zbir >= 74.999 && zbir < 85)
   {
      ocjenaMirza = 8;
   }
   else if (zbir >= 84.999 && zbir < 92)
   {
      ocjenaMirza = 9;
   }
   else if (zbir >= 91.999 && zbir < 100)
   {
      ocjenaMirza = 10;
   }
   else
   {
      ocjenaMirza = 5;
   }

   if (ocjenaTarik > 5)
   {
      prolaz++;
   }
   if (ocjenaBojan > 5)
   {
      prolaz++;
   }
   if (ocjenaMirza > 5)
   {
      prolaz++;
   }

   if (prolaz == 1)
   {
      printf("Jedan student je polozio.");
   }
   else if (prolaz == 2)
   {
      printf("Dva studenta su polozila.");
   }
   else if (prolaz == 3)
   {
      printf("Sva tri studenta su polozila.");
   }
   else
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   printf("\n");
   if (ocjenaBojan != ocjenaMirza && ocjenaBojan != ocjenaTarik && ocjenaTarik != ocjenaMirza && prolaz == 3)
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
   else if ((ocjenaBojan == ocjenaTarik) && (ocjenaBojan == ocjenaMirza) && prolaz == 3)
   {
      printf("Sva tri studenta imaju istu ocjenu.");
   }
   else if ((ocjenaBojan == ocjenaMirza || ocjenaBojan == ocjenaTarik || ocjenaTarik == ocjenaMirza) && prolaz == 3)
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }

   return(0);
}
