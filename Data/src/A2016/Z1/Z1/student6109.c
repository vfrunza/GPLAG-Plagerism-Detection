#include <stdio.h>
#define EPS    0.001

int main()
{
   float pr1, pr2, pr3, dr1, dr2, dr3, za1, za2, za3, us1, us2, us3;
   float prisustvo1, prisustvo2, prisustvo3;
   int   o1, o2, o3;
   float zbir1, zbir2, zbir3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pr1);
   if (pr1 < 0 || pr1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dr1);
   if (dr1 < 0 || dr1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &za1);
   if (za1 < 0 || za1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &us1);
   if (us1 < 0 || us1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pr2);
   if (pr2 < 0 || pr2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dr2);
   if (dr2 < 0 || dr2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &za2);
   if (za2 < 0 || za2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &us2);
   if (us2 < 0 || us2 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pr3);
   if (pr3 < 0 || pr3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dr3);
   if (dr3 < 0 || dr3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &za3);
   if (za3 < 0 || za3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &us3);
   if (us3 < 0 || us3 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   zbir1 = pr1 + dr1 + za1 + prisustvo1 + us1;
   zbir2 = pr2 + dr2 + za2 + prisustvo2 + us2;
   zbir3 = pr3 + dr3 + za3 + prisustvo3 + us3;


   o1 = 5;
   if (zbir1 + EPS >= 55 && zbir1 < 65)
   {
      o1 = 6;
   }
   else if (zbir1 + EPS >= 65 && zbir1 < 75)
   {
      o1 = 7;
   }
   else if (zbir1 + EPS >= 75 && zbir1 < 85)
   {
      o1 = 8;
   }
   else if (zbir1 + EPS >= 85 && zbir1 < 95)
   {
      o1 = 9;
   }
   else if (zbir1 + EPS >= 95 && zbir1 < 100)
   {
      o1 = 10;
   }

   o2 = 5;
   if (zbir2 + EPS > 55 && zbir2 < 65)
   {
      o2 = 6;
   }
   else if (zbir2 + EPS > 65 && zbir2 < 75)
   {
      o2 = 7;
   }
   else if (zbir2 + EPS > 75 && zbir2 < 85)
   {
      o2 = 8;
   }
   else if (zbir2 + EPS > 85 && zbir2 < 95)
   {
      o2 = 9;
   }
   else if (zbir2 + EPS > 95 && zbir2 < 100)
   {
      o2 = 10;
   }

   o3 = 5;
   if (zbir3 + EPS > 55 && zbir3 < 65)
   {
      o3 = 6;
   }
   else if (zbir3 + EPS > 65 && zbir3 < 75)
   {
      o3 = 7;
   }
   else if (zbir3 + EPS > 75 && zbir3 < 85)
   {
      o3 = 8;
   }
   else if (zbir3 + EPS > 85 && zbir3 < 95)
   {
      o3 = 9;
   }
   else if (zbir3 + EPS > 95 && zbir3 < 100)
   {
      o3 = 10;
   }

   if (o1 == 5 && o2 == 5 && o3 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((o3 == 5 && o2 > 5 && o1 > 5) || (o3 > 5 && o2 == 5 && o1 > 5) || (o3 > 5 && o2 > 5 && o1 == 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if ((o1 > 5 && o2 == 5 && o3 == 5) || (o1 == 5 && o2 > 5 && o3 == 5) || (o1 == 5 && o2 == 5 && o3 > 5))
   {
      printf("Jedan student je polozio.");
   }
   else if (o1 > 5 && o2 > 5 && o3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (o1 == o2 && o1 == o3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((o1 == o2 && o1 != o3) || (o2 == o3 && o2 != o1) || (o3 == o1 && o3 != o2))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
