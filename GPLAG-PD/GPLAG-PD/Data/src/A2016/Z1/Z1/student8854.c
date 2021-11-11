#include <stdio.h>
#include <math.h>
#define ep    0.0001

int main()
{
   float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, e1, e2, e3, suma1, suma2, suma3, a, b, c;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &a1);
   if (a1 < 0 || a1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("II parcijalni ispit: ");
   scanf("%f", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Prisustvo: ");
   scanf("%f", &c1);
   if (c1 < 0 || c1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &d1);
   if (d1 < 0 || d1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%f", &e1);
   if (e1 < 0 || e1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &a2);
   if (a2 < 0 || a2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("II parcijalni ispit: ");
   scanf("%f", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Prisustvo: ");
   scanf("%f", &c2);
   if (c2 < 0 || c2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &d2);
   if (d2 < 0 || d2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%f", &e2);
   if (e2 < 0 || e2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &a3);
   if (a3 < 0 || a3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("II parcijalni ispit: ");
   scanf("%f", &b3);
   if (b3 < 0 || b3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Prisustvo: ");
   scanf("%f", &c3);
   if (c3 < 0 || c3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &d3);
   if (d3 < 0 || d3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%f", &e3);
   if (e3 < 0 || e3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   suma1 = a1 + b1 + c1 + d1 + e1;
   suma2 = a2 + b2 + c2 + d2 + e2;
   suma3 = a3 + b3 + c3 + d3 + e3;


   if (suma1 < 55 - ep && suma2 < 55 - ep && suma3 < 55 - ep)
   {
      printf("Nijedan student nije polozio.");
   }

   if (suma1 >= 55 - ep && suma2 < 55 - ep && suma3 < 55 - ep)
   {
      printf("Jedan student je polozio.");
   }

   if (suma1 < 55 - ep && suma2 >= 55 - ep && suma3 < 55 - ep)
   {
      printf("Jedan student je polozio.");
   }

   if (suma1 < 55 - ep && suma2 < 55 - ep && suma3 >= 55 - ep)
   {
      printf("Jedan student je polozio.");
   }

   if (suma1 >= 55 - ep && suma2 >= 55 - ep && suma3 < 55 - ep)
   {
      printf("Dva studenta su polozila.");
   }

   if (suma1 < 55 - ep && suma2 >= 55 - ep && suma3 >= 55 - ep)
   {
      printf("Dva studenta su polozila.");
   }

   if (suma1 >= 55 - ep && suma2 < 55 - ep && suma3 >= 55 - ep)
   {
      printf("Dva studenta su polozila.");
   }

   if (suma1 >= 55 - ep && suma2 >= 55 - ep && suma3 >= 55 - ep)
   {
      printf("Sva tri studenta su polozila.\n");
      if (suma1 < 65 - ep)
      {
         a = 6;
      }
      else
      {
         if (suma1 < 75 - ep)
         {
            a = 7;
         }
         else
         {
            if (suma1 < 85 - ep)
            {
               a = 8;
            }
            else
            {
               if (suma1 < 92 - ep)
               {
                  a = 9;
               }
               else
               {
                  a = 10;
               }
            }
         }
      }


      if (suma2 < 65 - ep)
      {
         b = 6;
      }
      else
      {
         if (suma2 < 75 - ep)
         {
            b = 7;
         }
         else
         {
            if (suma2 < 85 - ep)
            {
               b = 8;
            }
            else
            {
               if (suma2 < 92 - ep)
               {
                  b = 9;
               }
               else
               {
                  b = 10;
               }
            }
         }
      }


      if (suma3 < 65 - ep)
      {
         c = 6;
      }
      else
      {
         if (suma3 < 75 - ep)
         {
            c = 7;
         }
         else
         {
            if (suma3 < 85 - ep)
            {
               c = 8;
            }
            else
            {
               if (suma3 < 92 - ep)
               {
                  c = 9;
               }
               else
               {
                  c = 10;
               }
            }
         }
      }

      if (fabs(a - b) < ep && fabs(b - c) < ep)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         if (fabs(a - b) >= ep && fabs(a - b) >= ep && fabs(a - b) >= ep)
         {
            printf("Svaki student ima razlicitu ocjenu.\n");
         }
         else
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
      }
   }



   return(0);
}
