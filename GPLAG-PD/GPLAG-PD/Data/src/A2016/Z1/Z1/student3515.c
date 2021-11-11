#include <stdio.h>
#define E    0.0001
int main()
{
   float Tarik, Bojan, Mirza, Toc, Toc1, Boc, Boc1, Moc, Moc1, Tparcijala1, Tparcijala2, Tprisustvo, Tzadace, Tzavrsniispit, Bparcijala1, Bparcijala2, Bprisustvo, Bzadace, Bzavrsniispit, Mparcijala1, Mparcijala2, Mprisustvo, Mzadace, Mzavrsniispit;

   /*Tarik*/

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Tparcijala1);

   if (Tparcijala1 > 20 || Tparcijala1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &Tparcijala2);

   if (Tparcijala2 > 20 || Tparcijala2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &Tprisustvo);

   if (Tprisustvo > 10 || Tprisustvo < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &Tzadace);

   if (Tzadace > 10 || Tzadace < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &Tzavrsniispit);

   if (Tzavrsniispit > 40 || Tzavrsniispit < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   /*Bojan*/

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Bparcijala1);
   if (Bparcijala1 > 20 || Bparcijala1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &Bparcijala2);
   if (Bparcijala2 > 20 || Bparcijala2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Bprisustvo);
   if (Bprisustvo > 10 || Bprisustvo < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Bzadace);
   if (Bzadace > 10 || Bzadace < 0)
   {
      printf("Neispravan broj bodova");
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Bzavrsniispit);
   if (Bzavrsniispit > 40 || Bzavrsniispit < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   /*Mirza*/

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Mparcijala1);
   if (Mparcijala1 > 20 || Mparcijala1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &Mparcijala2);
   if (Mparcijala2 > 20 || Mparcijala2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Mprisustvo);
   if (Mprisustvo > 10 || Mprisustvo < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Mzadace);
   if (Mzadace > 10 || Mzadace < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Mzavrsniispit);
   if (Mzavrsniispit > 40 || Mzavrsniispit < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   Toc = (Tparcijala1 + Tparcijala2 + Tprisustvo + Tzadace + Tzavrsniispit);
   Boc = (Bparcijala1 + Bparcijala2 + Bprisustvo + Bzadace + Bzavrsniispit);
   Moc = (Mparcijala1 + Mparcijala2 + Mprisustvo + Mzadace + Mzavrsniispit);



   if (Toc >= 55 && Toc < 65)
   {
      Toc1 = 6;
   }
   else if (Toc >= 65 && Toc < 75)
   {
      Toc1 = 7;
   }
   else if (Toc >= 75 && Toc < 85)
   {
      Toc1 = 8;
   }
   else if (Toc >= 85 && Toc < 92)
   {
      Toc1 = 9;
   }
   else if (Toc >= 92 && Toc <= 100)
   {
      Toc1 = 10;
   }
   else
   {
      Toc1 = 1;
   }



   if (Boc >= 55 && Boc < 65)
   {
      Boc1 = 6;
   }
   else if (Boc >= 65 && Boc < 75)
   {
      Boc1 = 7;
   }
   else if (Boc >= 75 && Boc < 85)
   {
      Boc1 = 8;
   }
   else if (Boc >= 85 && Boc < 92)
   {
      Boc1 = 9;
   }
   else if (Boc >= 92 && Boc <= 100)
   {
      Boc1 = 10;
   }
   else
   {
      Boc1 = 1;
   }


   if (Moc >= 55 && Moc < 65)
   {
      Moc1 = 6;
   }
   else if (Moc >= 65 && Moc < 75)
   {
      Moc1 = 7;
   }
   else if (Moc >= 75 && Moc < 85)
   {
      Moc1 = 8;
   }
   else if (Moc >= 85 && Moc < 92)
   {
      Moc1 = 9;
   }
   else if (Moc >= 92 && Moc <= 100)
   {
      Moc1 = 10;
   }
   else
   {
      Moc1 = 1;
   }



   if ((Toc + E) < 55 && (Boc + E) < 55 && (Moc + E) < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((Toc + E) >= 55 && (Boc + E) >= 55 && (Moc + E) >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }

   else if ((Toc + E) >= 55 && (Boc + E) < 55 && (Moc + E) < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if ((Toc + E) < 55 && (Boc + E) >= 55 && (Moc + E) < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if ((Toc + E) < 55 && (Boc + E) < 55 && (Moc + E) >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else
   {
      printf("Dva studenta su polozila.");
   }

   if ((Toc + E) >= 55 && (Boc + E) >= 55 && (Moc + E) >= 55)
   {
      if ((Toc1 == Boc1) && (Boc1 == Moc1) && (Moc1 == Toc1))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((Toc1 != Boc1) && (Boc1 != Moc1) && (Moc1 != Toc1))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
}
