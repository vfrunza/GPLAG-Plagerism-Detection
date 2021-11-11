#include <stdio.h>
#define EPSILON    0.00001
int main()
{
   float p1t, p2t, pt, zt, zit, p1b, p2b, pb, zb, zib, p1m, p2m, pm, zm, zim, bp = 0, tp = 0, mp = 0, mbt = 0;
   int   ocjenat, ocjenab, ocjenam;
   float tu = 0, bu = 0, mu = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1t);
   if (p1t < 0 || p1t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2t);
   if (p2t < 0 || p2t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pt);
   if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zt);
   if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zit);
   if (zit < 0 || zit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1b);
   if (p1b < 0 || p1b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2b);
   if (p2b < 0 || p2b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pb);
   if (pb < 0 || pb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zb);
   if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zib);
   if (zib < 0 || zib > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1m);
   if (p1m < 0 || p1m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2m);
   if (p2m < 0 || p2m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pm);
   if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zm);
   if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zim);
   if (zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   tu = p1t + p2t + pt + zt + zit + EPSILON;

   if (tu < 92)
   {
      ocjenat = (tu + 5) / 10;
   }
   else
   {
      ocjenat = (tu + 8) / 10;
   }
   if (tu >= 55)
   {
      tp = 1;
   }
   else
   {
      tp = 0;
   }

   bu = p1b + p2b + pb + zb + zib + EPSILON;
   if (bu < 92)
   {
      ocjenab = (bu + 5) / 10;
   }
   else
   {
      ocjenab = (bu + 8) / 10;
   }
   if (bu >= 55)
   {
      bp = 1;
   }
   else
   {
      bp = 0;
   }


   mu = p1m + p2m + pm + zm + zim + EPSILON;
   if (mu < 92)
   {
      ocjenam = (mu + 5) / 10;
   }
   else
   {
      ocjenam = (mu + 8) / 10;
   }
   if (mu >= 55)
   {
      mp = 1;
   }
   else
   {
      mp = 0;
   }
   mbt = mp + tp + bp;


   if (bu < 55 && mu < 55 && tu < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (bu >= 55 && mu < 55 && tu < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (bu < 55 && mu >= 55 && tu < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (bu < 55 && mu <= 55 && tu > 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (bu >= 55 && mu >= 55 && tu < 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (bu < 55 && mu >= 55 && tu >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (bu >= 55 && mu < 55 && tu >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (bu >= 55 && mu >= 55 && tu >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if (mbt == 3)
   {
      if (ocjenat == ocjenam && ocjenam == ocjenab && ocjenab == ocjenat)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenat == ocjenab && ocjenab != ocjenam && ocjenat != ocjenam && bp == 1 && mp == 1 && tp == 1 && mbt == 3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenat == ocjenam && ocjenam != ocjenab && ocjenat != ocjenab && bp == 1 && mp == 1 && tp == 1 && mbt == 3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenam == ocjenab && ocjenam != ocjenat && ocjenab != ocjenat && bp == 1 && mp == 1 && tp == 1 && mbt == 3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenam != ocjenat && ocjenam != ocjenab && ocjenat != ocjenab && bp == 1 && mp == 1 && tp == 1 && mbt == 3)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
