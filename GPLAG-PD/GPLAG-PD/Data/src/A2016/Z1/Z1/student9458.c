#include <stdio.h>

int main()
{
   double a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, a5, b5, c5;
   double t1, t2, t3;
   int    o1 = 0, o2 = 0, o3 = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a1); if (a1 < 0 || a1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &a2); if (a2 < 0 || a2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &a3); if (a3 < 0 || a3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &a4); if (a4 < 0 || a4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &a5); if (a5 < 0 || a5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &b1); if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2); if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &b3); if (b3 < 0 || b3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &b4); if (b4 < 0 || b4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &b5); if (b5 < 0 || b5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &c1); if (c1 < 0 || c1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &c2); if (c2 < 0 || c2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c3); if (c3 < 0 || c3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &c4); if (c4 < 0 || c4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &c5); if (c5 < 0 || c5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   t1 = a1 + a2 + a3 + a4 + a5;
   if (t1 >= 55 && t1 < 65)
   {
      o1 = 6;
   }
   else if (t1 >= 65 && t1 < 75)
   {
      o1 = 7;
   }
   else if (t1 >= 75 && t1 < 85)
   {
      o1 = 8;
   }
   else if (t1 >= 85 && t1 < 92)
   {
      o1 = 9;
   }
   else if (t1 >= 92 && t1 <= 100)
   {
      o1 = 10;
   }
   else if (t1 < 55)
   {
      o1 = 5;
   }
   t2 = b1 + b2 + b3 + b4 + b5;
   if (t2 >= 55 && t2 < 65)
   {
      o2 = 6;
   }
   else if (t2 >= 65 && t2 < 75)
   {
      o2 = 7;
   }
   else if (t2 >= 75 && t2 < 85)
   {
      o2 = 8;
   }
   else if (t2 >= 85 && t2 < 95)
   {
      o2 = 9;
   }
   else if (t2 >= 92 && t2 <= 100)
   {
      o2 = 10;
   }
   else if (t2 < 55)
   {
      o2 = 5;
   }
   t3 = c1 + c2 + c3 + c4 + c5;
   if (t3 >= 55 && t3 < 65)
   {
      o3 = 6;
   }
   else if (t3 >= 65 && t3 < 75)
   {
      o3 = 7;
   }
   else if (t3 >= 75 && t3 < 85)
   {
      o3 = 8;
   }
   else if (t3 >= 85 && t3 < 92)
   {
      o3 = 9;
   }
   else if (t3 >= 92 && t3 <= 100)
   {
      o3 = 10;
   }
   else if (t3 < 55)
   {
      o3 = 5;
   }

   if (o1 == 5 && o2 == 5 && o3 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((o1 != 5 && o2 == 5 && o3 == 5) || (o1 == 5 && o2 != 5 && o3 == 5) || (o1 == 5 && o2 == 5 && o3 != 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((t1 > 55 && t2 > 55 && t3 < 55) || (t1 < 55 && t2 > 55 && t3 > 55) || (t1 > 55 && t2 < 55 && t3 > 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if (t1 > 55 && t2 > 55 && t3 > 55)
   {
      printf("Sva tri studenta su polozila.\n"); if (o1 != o2 && o1 != o3 && o3 != o2)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else if (o1 == o2 && o2 == o3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((o1 == o2 && o1 != o3) || (o2 == o3 && o3 != o1) || (o1 == o3 && o1 != o2))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}
