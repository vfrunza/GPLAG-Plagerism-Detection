#include <stdio.h>

int main()
{
   double p1t, p2t, Pt, dzt, Zt;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &p1t);
   if (p1t < 0 || p1t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2t);
   if (p2t < 0 || p2t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pt);
   if (Pt < 0 || Pt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dzt);
   if (dzt < 0 || dzt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Zt);
   if (Zt < 0 || Zt > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   double p1b, p2b, Pb, dzb, Zb;

   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%lf", &p1b);
   if (p1b < 0 || p1b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2b);
   if (p2b < 0 || p2b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pb);
   if (Pb < 0 || Pb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dzb);
   if (dzb < 0 || dzb > 10)
   {
      printf("Neispravan broj bodova");
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Zb);
   if (Zb < 0 || Zb > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   double p1n, p2n, Pn, dzn, Zn;

   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%lf", &p1n);
   if (p1n < 0 || p1n > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2n);
   if (p2n < 0 || p2n > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pn);
   if (Pn < 0 || Pn > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dzn);
   if (dzn < 0 || dzn > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Zn);
   if (Zn < 0 || Zn > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   float tarik, mirza, bojan;
   int   ocjenat, ocjenam, ocjenab;

   tarik = p1t + p2t + Pt + dzt + Zt;
   if (tarik < 55)
   {
      ocjenat = 5;
   }
   else if (tarik >= 55 && tarik < 65)
   {
      ocjenat = 6;
   }
   else if (tarik >= 65 && tarik < 75)
   {
      ocjenat = 7;
   }
   else if (tarik >= 75 && tarik < 85)
   {
      ocjenat = 8;
   }
   else if (tarik >= 85 && tarik < 92)
   {
      ocjenat = 9;
   }
   else if (tarik >= 92 && tarik <= 100)
   {
      ocjenat = 10;
   }
   mirza = p1n + p2n + Pn + dzn + Zn;
   if (mirza < 55)
   {
      ocjenam = 5;
   }
   else if (mirza >= 55 && mirza < 65)
   {
      ocjenam = 6;
   }
   else if (mirza >= 65 && mirza < 75)
   {
      ocjenam = 7;
   }
   else if (mirza >= 75 && mirza < 85)
   {
      ocjenam = 8;
   }
   else if (mirza >= 85 && mirza < 92)
   {
      ocjenam = 9;
   }
   else if (mirza >= 92 && mirza <= 100)
   {
      ocjenam = 10;
   }
   bojan = p1b + p2b + Pb + dzb + Zb;
   if (bojan < 55)
   {
      ocjenab = 5;
   }
   else if (bojan >= 55 && bojan < 65)
   {
      ocjenab = 6;
   }
   else if (bojan >= 65 && bojan < 75)
   {
      ocjenab = 7;
   }
   else if (bojan >= 75 && bojan < 85)
   {
      ocjenab = 8;
   }
   else if (bojan >= 85 && bojan < 92)
   {
      ocjenab = 9;
   }
   else if (bojan >= 92 && bojan <= 100)
   {
      ocjenab = 10;
   }

   if (ocjenat == 5 && ocjenam == 5 && ocjenab == 5)
   {
      printf("Nijedan student nije polozio. \n");
   }
   else if ((ocjenat > 5 && ocjenat <= 10) && (ocjenam > 5 && ocjenam <= 10) && ocjenab == 5)
   {
      printf("Dva studenta su polozila. \n");
   }
   else if ((ocjenat > 5 && ocjenat <= 10) && (ocjenab > 5 && ocjenab <= 10) && ocjenam == 5)
   {
      printf("Dva studenta su polozila. \n");
   }
   else if ((ocjenab > 5 && ocjenab <= 10) && (ocjenam > 5 && ocjenam <= 10) && ocjenat == 5)
   {
      printf("Dva studenta su polozila. \n");
   }
   else if (ocjenat == 5 && ocjenam == 5 && (ocjenab > 5 && ocjenab <= 10))
   {
      printf("Jedan student je polozio. \n");
   }
   else if (ocjenat == 5 && ocjenab == 5 && (ocjenam > 5 && ocjenam <= 10))
   {
      printf("Jedan student je polozio. \n");
   }
   else if (ocjenab == 5 && ocjenam == 5 && (ocjenat > 5 && ocjenat <= 10))
   {
      printf("Jedan student je polozio. \n");
   }
   else if ((ocjenat > 5 && ocjenat <= 10) && (ocjenam > 5 && ocjenam <= 10) && (ocjenab > 5 && ocjenab <= 10))
   {
      printf("Sva tri studenta su polozila. \n");

      if (ocjenat == ocjenam && ocjenam == ocjenab)
      {
         printf("Sva tri studenta imaju istu ocjenu. \n");
      }
      else if ((ocjenat == ocjenam && ocjenam != ocjenab) || (ocjenat == ocjenab && ocjenab != ocjenam) || (ocjenab == ocjenam && ocjenam != ocjenat))
      {
         printf("Dva od tri studenta imaju istu ocjenu. \n");
      }
      else if (ocjenat != ocjenab && ocjenat != ocjenam && ocjenab != ocjenam)
      {
         printf("Svaki student ima razlicitu ocjenu. \n");
      }
   }


   return(0);
}
