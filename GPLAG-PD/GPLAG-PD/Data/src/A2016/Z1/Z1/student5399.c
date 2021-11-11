#include <stdio.h>

int main()
{
   float Tp1, Tp2, Tp, Tz, Tu;
   float Bp1, Bp2, Bp, Bz, Bu;
   float Mp1, Mp2, Mp, Mz, Mu;
   int   Tpol = 0, Bpol = 0, Mpol = 0;
   int   Toc, Boc, Moc;
   float St, Sb, Sm;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Tp1);
   if (Tp1 < 0 || Tp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Tp2);
   if (Tp2 < 0 || Tp2 > 20)
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
   scanf("%f", &Tu);
   if (Tu < 0 || Tu > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   St = Tp1 + Tp2 + Tp + Tz + Tu + 0.01;

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Bp1);
   if (Bp1 < 0 || Bp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Bp2);
   if (Bp2 < 0 || Bp2 > 20)
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
   scanf("%f", &Bu);
   if (Bu < 0 || Bu > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   Sb = Bp1 + Bp2 + Bp + Bz + Bu + 0.01;

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Mp1);
   if (Mp1 < 0 || Mp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Mp2);
   if (Mp2 < 0 || Mp2 > 20)
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
   scanf("%f", &Mu);
   if (Mu < 0 || Mu > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   Sm = Mp1 + Mp2 + Mp + Mz + Mu + 0.01;

   if (St < 55)
   {
      Toc  = 5;
      Tpol = 0;
   }
   else if (St >= 55 && St < 65)
   {
      Toc  = 6;
      Tpol = 1;
   }
   else if (St >= 65 && St < 75)
   {
      Toc  = 7;
      Tpol = 1;
   }
   else if (St >= 75 && St < 85)
   {
      Toc  = 8;
      Tpol = 1;
   }
   else if (St >= 85 && St < 92)
   {
      Toc  = 9;
      Tpol = 1;
   }
   else
   {
      Toc  = 10;
      Tpol = 1;
   }

   if (Sb < 55)
   {
      Boc  = 5;
      Bpol = 0;
   }
   else if (Sb >= 55 && Sb < 65)
   {
      Boc  = 6;
      Bpol = 1;
   }
   else if (Sb >= 65 && Sb < 75)
   {
      Boc  = 7;
      Bpol = 1;
   }
   else if (Sb >= 75 && Sb < 85)
   {
      Boc  = 8;
      Bpol = 1;
   }
   else if (Sb >= 85 && Sb < 92)
   {
      Boc  = 9;
      Bpol = 1;
   }
   else
   {
      Boc  = 10;
      Bpol = 1;
   }

   if (Sm < 55)
   {
      Moc  = 5;
      Mpol = 0;
   }
   else if (Sm >= 55 && Sm < 65)
   {
      Moc  = 6;
      Mpol = 1;
   }
   else if (Sm >= 65 && Sm < 75)
   {
      Moc  = 7;
      Mpol = 1;
   }
   else if (Sm >= 75 && Sm < 85)
   {
      Moc  = 8;
      Mpol = 1;
   }
   else if (Sm >= 85 && Sm < 92)
   {
      Moc  = 9;
      Mpol = 1;
   }
   else
   {
      Moc  = 10;
      Mpol = 1;
   }

   if (Tpol == 0 && Bpol == 0 && Mpol == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (Tpol == 1 && Bpol == 0 && Mpol == 0 && St >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (Tpol == 0 && Bpol == 1 && Mpol == 0 && Sb >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (Tpol == 0 && Bpol == 0 && Mpol == 1 && Sm >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if ((Tpol == 0 && Bpol == 1 && Mpol == 1) || (Tpol == 1 && Bpol == 0 && Mpol == 1) || (Tpol == 1 && Bpol == 1 && Mpol == 0))
   {
      printf("Dva studenta su polozila.");
   }
   else if (Tpol == 1 && Bpol == 1 && Mpol == 1)
   {
      printf("Sva tri studenta su polozila. \n");
      if (Toc == Boc && Toc == Moc && Boc == Moc)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (((Toc != Moc && Boc != Moc && Toc == Boc) || (Toc != Boc && Toc != Moc && Boc == Moc)) || (Moc != Boc && Toc != Boc && Moc == Toc))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (Toc != Boc && Toc != Moc && Boc != Moc)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
