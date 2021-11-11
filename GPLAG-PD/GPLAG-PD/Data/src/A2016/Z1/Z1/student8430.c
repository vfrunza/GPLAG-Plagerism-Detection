#include <stdio.h>

int main()
{
   double p1, p2, pri, zad, zavrsnit, p1b, p2b, prib, zadb, zavrsnib, p1m, p2m, prim, zadm, zavrsnim;
   double Ta, Mi, Bo;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pri);
   if (pri < 0 || pri > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zad);
   if (zad < 0 || zad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsnit);
   if (zavrsnit < 0 || zavrsnit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
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
   scanf("%lf", &prib);
   if (prib < 0 || prib > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadb);
   if (zadb < 0 || zadb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsnib);
   if (zavrsnib < 0 || zavrsnib > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1m);
   if (p1m < 0 || p1m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2m);
   if (p2m < 0 || p2m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prim);
   if (prim < 0 || prim > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadm);
   if (zadm < 0 || zadm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsnim);
   if (zavrsnim < 0 || zavrsnim > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   Ta = p1 + p2 + pri + zad + zavrsnit;
   Bo = p1b + p2b + prib + zadb + zavrsnib;
   Mi = p1m + p2m + prim + zadm + zavrsnim;
   if (Ta < 55 && Bo < 55 && Mi < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((Ta >= 55 && Bo < 55 && Mi < 55) || (Bo >= 55 && Mi < 55 && Ta < 55) || (Mi >= 55 && Bo < 55 && Ta < 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((Ta >= 55 && Bo >= 55 && Mi < 55) || (Ta >= 55 && Mi >= 55 && Bo < 55) || (Bo >= 55 && Mi >= 55 && Ta < 55))
   {
      printf("Dva studenta su polozila.");
   }
   if (Ta >= 55 && Bo >= 55 && Mi >= 55)
   {
      printf("Sva tri studenta su polozila.");
      if (((Ta >= 55 && Ta < 65) && (Bo >= 55 && Bo < 65) && (Mi >= 55 && Mi < 65)) || ((Ta >= 65 && Ta < 75) && (Bo >= 65 && Bo < 75) && (Mi >= 65 && Mi < 75)) || ((Ta >= 75 && Ta < 85) && (Bo >= 75 && Bo < 85) && (Mi >= 75 && Mi < 85)) || ((Ta >= 85 && Ta < 92) && (Bo >= 85 && Bo < 92) && (Mi >= 85 && Mi < 92)) || ((Ta >= 92 && Ta <= 100) && (Bo >= 92 && Bo <= 100) && (Mi >= 92 && Mi <= 100)))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((((Ta >= 55 && Ta < 65) && (Bo >= 55 && Bo < 65)) || ((Ta >= 65 && Ta < 75) && (Bo >= 65 && Bo < 75)) || ((Ta >= 75 && Ta < 85) && (Bo >= 75 && Bo < 85)) || ((Ta >= 85 && Ta < 92) && (Bo >= 85 && Bo < 92)) || ((Ta >= 92 && Ta <= 100) && (Bo >= 92 && Bo <= 100))) || (((Ta >= 55 && Ta < 65) && (Mi >= 55 && Mi < 65)) || ((Ta >= 65 && Ta < 75) && (Mi >= 65 && Mi < 75)) || ((Ta >= 75 && Ta < 85) && (Mi >= 75 && Mi < 85)) || ((Ta >= 85 && Ta < 92) && (Mi >= 85 && Mi < 92)) || ((Ta >= 92 && Ta <= 100) && (Mi >= 92 && Mi <= 100))) || (((Bo >= 55 && Bo < 65) && (Mi >= 55 && Mi < 65)) || ((Bo >= 65 && Bo < 75) && (Mi >= 65 && Mi < 75)) || ((Bo >= 75 && Bo < 85) && (Mi >= 75 && Mi < 85)) || ((Bo >= 85 && Bo < 92) && (Mi >= 85 && Mi < 92)) || ((Bo >= 92 && Bo <= 100) && (Mi >= 92 && Mi <= 100))))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
