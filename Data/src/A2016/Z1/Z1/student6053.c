#include <stdio.h>
#define e    0.001

int main()
{
   float p1t, p2t, pt, zt, ut, p1b, p2b, pb, zb, ub, p1m, p2m, pm, zm, um, ot, ob, om, ocjenat, ocjenab, ocjenam;

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
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pt);
   if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zt);
   if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ut);
   if (ut < 0 || ut > 40)
   {
      printf("Neispravan broj bodova\n");
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
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ub);
   if (ub < 0 || ub > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1m);
   if (p1m < 0 || p1m > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2m);
   if (p2m < 0 || p2m > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pm);
   if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zm);
   if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &um);
   if (um < 0 || um > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   ot = p1t + p2t + zt + pt + ut + e;
   ob = p1b + p2b + zb + pb + ub + e;
   om = p1m + p2m + zm + pm + um + e;

   if (ot >= 55 && ot < 65)
   {
      ocjenat = 6;
   }
   if (ot >= 65 && ot < 75)
   {
      ocjenat = 7;
   }
   if (ot >= 75 && ot < 85)
   {
      ocjenat = 8;
   }
   if (ot >= 85 && ot < 92)
   {
      ocjenat = 9;
   }
   if (ot >= 92 && ot < 100)
   {
      ocjenat = 10;
   }


   if (ob >= 55 && ob < 65)
   {
      ocjenab = 6;
   }
   if (ob >= 65 && ob < 75)
   {
      ocjenat = 7;
   }
   if (ob >= 75 && ob < 85)
   {
      ocjenab = 8;
   }
   if (ob >= 85 && ob < 92)
   {
      ocjenab = 9;
   }
   if (ob >= 92 && ob < 100)
   {
      ocjenab = 10;
   }


   if (om >= 55 && om < 65)
   {
      ocjenam = 6;
   }
   if (om >= 65 && om < 75)
   {
      ocjenam = 7;
   }
   if (om >= 75 && om < 85)
   {
      ocjenat = 8;
   }
   if (om >= 85 && om < 92)
   {
      ocjenam = 9;
   }
   if (om >= 92 && om < 100)
   {
      ocjenam = 10;
   }

   if (ot < 55 && ob < 55 && om < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if (ot >= 55 && ob < 55 && om < 55)
   {
      printf("Jedan student je polozio.");
   }
   if (ot < 55 && ob >= 55 && om < 55)
   {
      printf("Jedan student je polozio.");
   }
   if (ot < 55 && ob < 55 && om >= 55)
   {
      printf("Jedan student je polozio.");
   }
   if (ot >= 55 && ob >= 55 && om < 55)
   {
      printf("Dva studenta su polozila.");
   }
   if (ot >= 55 && ob < 55 && om >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   if (ot < 55 && ob >= 55 && om >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   if (ot >= 55 && ob >= 55 && om >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjenat == ocjenab && ocjenab == ocjenam && ocjenam == ocjenat)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if ((ocjenat == ocjenab && ocjenab != ocjenam) || (ocjenat == ocjenam && ocjenam != ocjenab) || (ocjenam == ocjenab && ocjenab != ocjenat))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      if (ocjenat != ocjenab && ocjenab != ocjenam && ocjenam != ocjenat)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
