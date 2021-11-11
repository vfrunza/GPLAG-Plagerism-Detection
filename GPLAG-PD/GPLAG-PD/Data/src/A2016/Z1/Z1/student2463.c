#include <stdio.h>
#include <math.h>
int main()
{
   float Tpi1, Tpi2, Tp, Tz, Tzi, Tukupno, Bpi1, Bpi2, Bp, Bz, Bzi, Bukupno, Mpi1, Mpi2, Mp, Mz, Mzi, Mukupno;

   /*Tarik*/
   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Tpi1);
   if (Tpi1 < 0 || Tpi1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Tpi2);
   if (Tpi2 < 0 || Tpi2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Tp);
   if (Tp < 0 || Tp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Tz);
   if (Tz < 0 || Tz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Tzi);
   if (Tzi < 0 || Tzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   /*Bojan*/
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Bpi1);
   if (Bpi1 < 0 || Bpi1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Bpi2);
   if (Bpi2 < 0 || Bpi2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Bp);
   if (Bp < 0 || Bp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Bz);
   if (Bz < 0 || Bz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Bzi);
   if (Bzi < 0 || Bzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   /*Mirza*/
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Mpi1);
   if (Mpi1 < 0 || Mpi1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Mpi2);
   if (Mpi2 < 0 || Mpi2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Mp);
   if (Mp < 0 || Mp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Mz);
   if (Mz < 0 || Mz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Mzi);
   if (Mzi < 0 || Mzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   Tukupno = Tpi1 + Tpi2 + Tp + Tz + Tzi;
   Bukupno = Bpi1 + Bpi2 + Bp + Bz + Bzi;
   Mukupno = Mpi1 + Mpi2 + Mp + Mz + Mzi;

   int Toc, Boc, Moc;

   if (Tukupno >= 92 || fabs(Tukupno - 92) < 0.001)
   {
      Toc = 10;
   }
   else if (Tukupno >= 85 || fabs(Tukupno - 85) < 0.001)
   {
      Toc = 9;
   }
   else if (Tukupno >= 75 || fabs(Tukupno - 75) < 0.001)
   {
      Toc = 8;
   }
   else if (Tukupno >= 65 || fabs(Tukupno - 65) < 0.001)
   {
      Toc = 7;
   }
   else if (Tukupno >= 55 || fabs(Tukupno - 55) < 0.001)
   {
      Toc = 6;
   }
   else
   {
      Toc = 5;
   }

   if (Bukupno >= 92 || fabs(Bukupno - 92) < 0.001)
   {
      Boc = 10;
   }
   else if (Bukupno >= 85 || fabs(Bukupno - 85) < 0.001)
   {
      Boc = 9;
   }
   else if (Bukupno >= 75 || fabs(Bukupno - 75) < 0.001)
   {
      Boc = 8;
   }
   else if (Bukupno >= 65 || fabs(Bukupno - 65) < 0.001)
   {
      Boc = 7;
   }
   else if (Bukupno >= 55 || fabs(Bukupno - 55) < 0.001)
   {
      Boc = 6;
   }
   else
   {
      Boc = 5;
   }

   if (Mukupno >= 92 || fabs(Mukupno - 92) < 0.001)
   {
      Moc = 10;
   }
   else if (Mukupno >= 85 || fabs(Mukupno - 85) < 0.001)
   {
      Moc = 9;
   }
   else if (Mukupno >= 75 || fabs(Mukupno - 75) < 0.001)
   {
      Moc = 8;
   }
   else if (Mukupno >= 65 || fabs(Mukupno - 65) < 0.001)
   {
      Moc = 7;
   }
   else if (Mukupno >= 55 || fabs(Mukupno - 55) < 0.001)
   {
      Moc = 6;
   }
   else
   {
      Moc = 5;
   }

   if (Toc <= 5 && Boc <= 5 && Moc <= 5)
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }
   else if ((Toc > 5 && Boc <= 5 && Moc <= 5) || (Boc > 5 && Toc <= 5 && Moc <= 5) || (Moc > 5 && Boc <= 5 && Toc <= 5))
   {
      printf("Jedan student je polozio.\n"); return(0);
   }
   else if ((Toc > 5 && Boc > 5 && Moc <= 5) || (Toc > 5 && Moc > 5 && Boc <= 5) || (Moc > 5 && Boc > 5 && Toc <= 5))
   {
      printf("Dva studenta su polozila.\n"); return(0);
   }
   else if (Toc > 5 && Boc > 5 && Moc > 5)
   {
      printf("Sva tri studenta su polozila.\n");


      if (Toc == Boc && Boc == Moc)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n"); return(0);
      }
      else if (Toc != Boc && Boc != Moc && Toc != Moc)
      {
         printf("Svaki student ima razlicitu ocjenu.\n"); return(0);
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n"); return(0);
      }
   }

   return(0);
}
