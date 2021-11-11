#include <stdio.h>
#include <math.h>
#define e    0.001
int main()
{
   float X1, X2, X3, X4, X5, Y1, Y2, Y3, Y4, Y5, Z1, Z2, Z3, Z4, Z5, Sx, Sy, Sz;
   int   Ox, Oy, Oz;

   { printf("Unesite bodove za Tarika:\n");
     printf("I parcijalni ispit: ");
     scanf("%f", &X1);
     if (X1 < 0 || X1 > 20)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("II parcijalni ispit: ");
     scanf("%f", &X2);
     if (X2 < 0 || X2 > 20)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Prisustvo: ");
     scanf("%f", &X3);
     if (X3 < 0 || X3 > 10)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Zadace: ");
     scanf("%f", &X4);
     if (X4 < 0 || X4 > 10)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Zavrsni ispit: ");
     scanf("%f", &X5);
     if (X5 < 0 || X5 > 40)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
   }


   { printf("Unesite bodove za Bojana:\n");
     printf("I parcijalni ispit: ");
     scanf("%f", &Y1);
     if (Y1 < 0 || Y1 > 20)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("II parcijalni ispit: ");
     scanf("%f", &Y2);
     if (Y1 < 0 || Y1 > 20)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Prisustvo: ");
     scanf("%f", &Y3);
     if (Y3 < 0 || Y3 > 10)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Zadace: ");
     scanf("%f", &Y4);
     if (Y4 < 0 || Y4 > 10)
     {
        printf("Nesipravan broj bodova");
        return(0);
     }
     printf("Zavrsni ispit: ");
     scanf("%f", &Y5);
     if (Y5 < 0 || Y5 > 40)
     {
        printf("Neisravan broj bodova");
        return(0);
     }
   }

   { printf("Unesite bodove za Mirzu:\n");
     printf("I parcijalni ispit: ");
     scanf("%f", &Z1);
     if (Z1 < 0 || Z1 > 20)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("II parcijalni ispit: ");
     scanf("%f", &Z2);
     if (Z2 < 0 || Z2 > 20)
     {
        printf("Nesipravan broj bodova");
        return(0);
     }
     printf("Prisustvo: ");
     scanf("%f", &Z3);
     if (Z3 < 0 || Z3 > 10)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Zadace: ");
     scanf("%f", &Z4);
     if (Z4 < 0 || Z4 > 10)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
     printf("Zavrsni ispit: ");
     scanf("%f", &Z5);
     if (Z5 < 0 || Z5 > 40)
     {
        printf("Neispravan broj bodova");
        return(0);
     }
   }

   Sx = X1 + X2 + X3 + X4 + X5;
   Sy = Y1 + Y2 + Y3 + Y4 + Y5;
   Sz = Z1 + Z2 + Z3 + Z4 + Z5;

   { if ((fabs(Sx - 55) < e || Sx > 55) && Sx < 65)
     {
        Ox = 6;
     }
     else if ((fabs(Sx - 65) < e || Sx > 65) && Sx < 75)
     {
        Ox = 7;
     }
     else if ((fabs(Sx - 75) < e || Sx > 75) && Sx < 85)
     {
        Ox = 8;
     }
     else if ((fabs(Sx - 85) < e || Sx > 85) && Sx < 92)
     {
        Ox = 9;
     }
     else if ((fabs(Sx - 92) < e || Sx > 92) && (fabs(Sx - 100) < e || Sx < 100))
     {
        Ox = 10;
     }
   }

   { if ((fabs(Sy - 55) < e || Sy > 55) && Sy < 65)
     {
        Oy = 6;
     }
     else if ((fabs(Sy - 65) < e || Sy > 65) && Sy < 75)
     {
        Oy = 7;
     }
     else if ((fabs(Sy - 75) < e || Sy > 75) && Sy < 85)
     {
        Oy = 8;
     }
     else if ((fabs(Sy - 85) < e || Sy > 85) && Sy < 92)
     {
        Oy = 9;
     }
     else if ((fabs(Sy - 92) < e || Sy > 92) && (fabs(Sy - 100) < e || Sy < 100))
     {
        Oy = 10;
     }
   }

   { if ((fabs(Sz - 55) < e || Sz > 55) && Sz < 65)
     {
        Oz = 6;
     }
     else if ((fabs(Sz - 65) < e || Sz > 65) && Sz < 75)
     {
        Oz = 7;
     }
     else if ((fabs(Sz - 75) < e || Sz > 75) && Sz < 85)
     {
        Oz = 8;
     }
     else if ((fabs(Sz - 85) < e || Sz > 85) && Sz < 92)
     {
        Oz = 9;
     }
     else if ((fabs(Sz - 92) < e || Sz > 92) && (fabs(Sz - 100) < e || Sz < 100))
     {
        Oz = 10;
     }
   }

   if (((fabs(Sx - 55) < e || Sx > 55) && Sy < 55 && Sz < 55) || ((fabs(Sy - 55) < e || Sy > 55) && Sx < 55 && Sz < 55) || ((fabs(Sz - 55) < e || Sz > 55) && Sx < 55 && Sy < 55))
   {
      printf("Jedan student je polozio.\n");
   }
   else if (Sx < 55 && Sy < 55 && Sz < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (((fabs(Sx - 55) < e || Sx > 55) && (fabs(Sy - 55) < e || Sy > 55) && Sz < 55) || ((fabs(Sx - 55) < e || Sx > 55) && Sy < 55 && (fabs(Sz - 55) < e || Sz > 55)) || ((fabs(Sy - 55) < e || Sy > 55) && (fabs(Sz - 55) < e || Sz > 55) && Sx < 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((fabs(Sx - 55) < e || Sx > 55) && (fabs(Sy - 55) < e || Sy > 55) && (fabs(Sz - 55) < e || Sz > 55))
   {
      printf("Sva tri studenta su polozila.\n");
      if (Ox == Oy && Oy == Oz)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (Ox != Oy && Oy != Oz)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else if ((Ox == Oy && Ox != Oz) || (Ox == Oz && Ox != Oy) || (Oy == Oz && Oy != Ox))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }
   return(0);
}
