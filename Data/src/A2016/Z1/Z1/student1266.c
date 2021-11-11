#include <stdio.h>
#define PPI    20 /*maksimalan broj bodova za prvi parcijalni ispit*/
#define DPI    20 /*maksimalan broj bodova za drugi parcijalni ispit*/
#define P      10 /*maksimalan broj bodova za prisustvo*/
#define DZ     10 /*maksimalan broj bodova iz zadace*/
#define ZI     40 /*maksimalan broj bodova iz zavrsnog ispita*/


int main()
{
   float ppi1, dpi1, p1, dz1, zi1, ppi2, ppi3, dpi2, dpi3, p2, p3, dz2, dz3, zi2, zi3, ubb1, ubb2, ubb3;

   /*Unos bodova za Tarika*/
   printf("Unesite bodove za Tarika: ");
   printf("I parcijalni ispit: ");
   scanf("%f", &ppi1);
   printf("II parcijalni ispit: ");
   scanf("%f", &dpi1);
   printf("Prisustvo: ");
   scanf("%f", &p1);
   printf("Zadace: ");
   scanf("%f", &dz1);
   printf("Zavrsni ispit: ");
   scanf("%f", &zi1);
   /*Unos bodova za Bojana*/
   printf("Unesite bodove za Bojana: ");
   printf("I parcijalni ispit: ");
   scanf("%f", &ppi2);
   printf("II parcijalni ispit: ");
   scanf("%f", &dpi2);
   printf("Prisustvo: ");
   scanf("%f", &p2);
   printf("Zadace: ");
   scanf("%f", &dz2);
   printf("Zavrsni ispit: ");
   scanf("%f", &zi2);
   /*Unos bodova za Mirzu*/
   printf("Unesite bodove za Mirzu: ");
   printf("I parcijalni ispit: ");
   scanf("%f", &ppi3);
   printf("II parcijalni ispit: ");
   scanf("%f", &dpi3);
   printf("Prisustvo:");
   scanf("%f", &p3);
   printf("Zadace: ");
   scanf("%f", &dz3);
   printf("Zavrsni ispit: ");
   scanf("%f", &zi3);

   if (((ppi1 <= PPI && ppi1 > 0) && (dpi1 <= DPI && dpi1 > 0) && (p1 <= P && p1 > 0) && (dz1 <= DZ && dz1 > 0) && (zi1 <= ZI && zi1 > 0)) &&
       ((ppi2 <= PPI && ppi2 > 0) && (dpi2 <= DPI && dpi2 > 0) && (p2 <= P && p2 > 0) && (dz2 <= DZ && dz2 > 0) && (zi2 <= ZI && zi2 > 0)) &&
       ((ppi3 <= PPI && ppi3 > 0) && (dpi3 <= DPI && dpi3 > 0) && (p3 <= P && p3 > 0) && (dz3 <= DZ && dz3 > 0) && (zi3 <= ZI && zi3 > 0)))
   {
      /*ukupan broj bodova-ubb*/
      ubb1 = ppi1 + dpi1 + p1 + dz1 + zi1;
      printf("Rezultat 1 %.2f", &ubb1);
      ubb2 = ppi2 + dpi2 + p2 + dz2 + zi2;
      printf("Rezultat 2 %.2f", &ubb2);
      ubb3 = ppi3 + dpi3 + p3 + dz3 + zi3;
      printf("Rezultat 3 %.2f", &ubb3);
   }
   else
   {
      printf("Neispravan broj bodova");
   }
   if ((ubb1 < 55) || (ubb2 < 55) || (ubb3 < 55))
   {
      printf("Student pao");
   }
   else if ((ubb1 >= 55 && ubb1 < 65) || (ubb2 >= 55 && ubb2 < 65) || (ubb3 >= 55 && ubb3 < 65))
   {
      printf("ocjena 6");
   }
   else if ((ubb1 >= 65 && ubb1 < 75) || (ubb2 >= 65 && ubb2 < 75) || (ubb3 >= 65 && ubb3 < 75))
   {
      printf("ocjena 7");
   }
   else if ((ubb1 >= 75 && ubb1 < 85) || (ubb2 >= 75 && ubb2 < 85) || (ubb3 >= 75 && ubb3 < 85))
   {
      printf("ocjena 8");
   }
   else if ((ubb1 >= 85 && ubb1 < 92) || (ubb2 >= 85 && ubb2 < 92) || (ubb3 >= 85 && ubb3 < 92))
   {
      printf("ocjena 9");
   }
   else
   {
      printf("ocjena 10");
   }

   if (ubb1 < 55 && ubb2 < 55 && ubb3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((ubb1 < 55 && ubb2 < 55 && ubb3 >= 55) || (ubb1 >= 55 && ubb2 < 55 && ubb3 < 55) || (ubb1 < 55 && ubb2 >= 55 && ubb3 < 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((ubb1 >= 55 && ubb2 >= 55 && ubb3 < 55) || (ubb1 >= 55 && ubb2 < 55 && ubb3 >= 55) || (ubb1 < 55 && ubb2 >= 55 && ubb3 >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.");
   }
   if ((ubb1 >= 55 && ubb2 >= 55 && ubb3 >= 55) && (((ubb1 >= 55 && ubb1 < 65) && (ubb2 >= 55 && ubb2 < 65)) || ((ubb1 >= 65 && ubb1 < 75) && (ubb2 >= 65 && ubb2 < 75)) ||
                                                    ((ubb1 >= 75 && ubb1 < 85) && (ubb2 >= 75 && ubb2 < 85)) || ((ubb1 >= 85 && ubb1 < 92) && (ubb2 >= 85 && ubb2 < 92)) || (
                                                       ((ubb1 >= 92 && ubb1 <= 100) && (ubb2 <= 100 && ubb2 >= 92)) || (((ubb1 >= 55 && ubb1 < 65) && (ubb3 >= 55 && ubb3 < 65)) ||
                                                                                                                        ((ubb1 >= 65 && ubb1 < 75) && (ubb3 < 75 && ubb3 >= 65)) || ((ubb1 >= 75 && ubb1 < 85) && (ubb3 < 85 && ubb3 >= 75)) || ((ubb1 >= 85 && ubb1 < 92) && (ubb3 < 92 && ubb3 >= 85)) ||
                                                                                                                        ((ubb1 >= 92 && ubb1 <= 100) && (ubb3 >= 92 && ubb3 <= 100)) ||
                                                                                                                        ((ubb2 >= 55 && ubb2 < 65) && (ubb3 < 65 && ubb3 >= 55)) || ((ubb2 >= 65 && ubb2 < 75) && (ubb3 < 75 && ubb3 >= 65)) ||
                                                                                                                        ((ubb2 >= 75 && ubb2 < 85) && (ubb3 < 85 && ubb3 >= 75)) || ((ubb2 >= 85 && ubb2 < 92) && (ubb3 < 92 && ubb3 >= 85)) ||
                                                                                                                        ((ubb2 >= 92 && ubb2 <= 100) && (ubb3 >= 92 && ubb3 <= 100))))))
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   else if (((ubb1 >= 55 && ubb2 >= 55 && ubb3 >= 55) && (ubb1 < 65 && ubb2 < 65 && ubb3 < 65) || (ubb1 >= 65 && ubb2 >= 65 && ubb3 >= 65) && (ubb1 < 75 && ubb2 < 75 && ubb3 < 75) ||
             (ubb1 >= 75 && ubb2 >= 75 && ubb3 >= 75) && (ubb1 < 85 && ubb2 < 85 && ubb3 < 85) || (ubb1 >= 85 && ubb2 >= 85 && ubb3 >= 85) && (ubb1 < 92 && ubb2 < 92 && ubb3 < 92) ||
             (ubb1 >= 92 && ubb2 >= 92 && ubb3 >= 92) && (ubb1 <= 100 && ubb2 <= 100 && ubb3 <= 100)))
   {
      printf("Sva tri studenta imaju istu ocjenu.");
   }
   else
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
}

return(0);
}
