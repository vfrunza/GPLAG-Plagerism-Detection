#include <stdio.h>
#include <math.h>
#define EPSILON    0.0001

int main()
{
   double T_prvi_par, T_drugi_par, T_prisustvo, T_zadace, T_zav_ispit, T_suma;
   double B_prvi_par, B_drugi_par, B_prisustvo, B_zadace, B_zav_ispit, B_suma;
   double M_prvi_par, M_drugi_par, M_prisustvo, M_zadace, M_zav_ispit, M_suma;
   int    T_ocjena = 0, M_ocjena = 0, B_ocjena = 0, T_cs = 1, M_cs = 1, B_cs = 1;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &T_prvi_par);
   if (T_prvi_par < 0 || T_prvi_par > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &T_drugi_par);
   if (T_drugi_par < 0 || T_drugi_par > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &T_prisustvo);
   if (T_prisustvo < 0 || T_prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &T_zadace);
   if (T_zadace < 0 || T_zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &T_zav_ispit);
   if (T_zav_ispit < 0 || T_zav_ispit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   T_suma = T_prvi_par + T_drugi_par + T_prisustvo + T_zadace + T_zav_ispit;

   if (T_suma < 55)
   {
      T_ocjena = 5;
      T_cs     = 0;
   }
   else
   {
      if (T_suma >= 55 && T_suma < 65)
      {
         T_ocjena = 6;
      }
      else
      {
         if (T_suma >= 65 && T_suma < 75)
         {
            T_ocjena = 7;
         }
         else
         {
            if (T_suma >= 75 && T_suma < 85)
            {
               T_ocjena = 8;
            }
            else
            {
               if (T_suma >= 85 && T_suma < 92)
               {
                  T_ocjena = 9;
               }
               else
               {
                  if (T_suma >= 92 && T_suma <= 100)
                  {
                     T_ocjena = 10;
                  }
               }
            }
         }
      }
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &B_prvi_par);
   if (B_prvi_par < 0 || B_prvi_par > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B_drugi_par);
   if (B_drugi_par < 0 || B_drugi_par > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &B_prisustvo);
   if (B_prisustvo < 0 || B_prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &B_zadace);
   if (B_zadace < 0 || B_zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &B_zav_ispit);
   if (B_zav_ispit < 0 || B_zav_ispit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   B_suma = B_prvi_par + B_drugi_par + B_prisustvo + B_zadace + B_zav_ispit;

   if (B_suma < 55)
   {
      B_ocjena = 5;
      B_cs     = 0;
   }
   else
   {
      if (B_suma >= 55 && B_suma < 65)
      {
         B_ocjena = 6;
      }
      else
      {
         if (B_suma >= 65 && B_suma < 75)
         {
            B_ocjena = 7;
         }
         else
         {
            if (B_suma >= 75 && B_suma < 85)
            {
               B_ocjena = 8;
            }
            else
            {
               if (B_suma >= 85 && B_suma < 92)
               {
                  B_ocjena = 9;
               }
               else
               {
                  if (B_suma >= 92 && B_suma <= 100)
                  {
                     B_ocjena = 10;
                  }
               }
            }
         }
      }
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &M_prvi_par);
   if (M_prvi_par < 0 || M_prvi_par > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &M_drugi_par);
   if (M_drugi_par < 0 || M_drugi_par > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &M_prisustvo);
   if (M_prisustvo < 0 || M_prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &M_zadace);
   if (M_zadace < 0 || M_zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &M_zav_ispit);
   if (M_zav_ispit < 0 || M_zav_ispit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   M_suma = M_prvi_par + M_drugi_par + M_prisustvo + M_zadace + M_zav_ispit;

   if (M_suma < 55)
   {
      M_ocjena = 5;
      M_cs     = 0;
   }
   else
   {
      if (M_suma >= 55 && M_suma < 65)
      {
         M_ocjena = 6;
      }
      else
      {
         if (M_suma >= 65 && M_suma < 75)
         {
            M_ocjena = 7;
         }
         else
         {
            if (M_suma >= 75 && M_suma < 85)
            {
               M_ocjena = 8;
            }
            else
            {
               if (M_suma >= 85 && M_suma < 92)
               {
                  M_ocjena = 9;
               }
               else
               {
                  if (M_suma >= 92 && M_suma <= 100)
                  {
                     M_ocjena = 10;
                  }
               }
            }
         }
      }
   }

   if (T_cs == 0 && B_cs == 0 && M_cs == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   {
      if (T_cs == 1 && B_cs == 1 && M_cs == 1)
      {
         printf("Sva tri studenta su polozila.");
      }
   }
   if ((T_ocjena == M_ocjena && M_ocjena == B_ocjena && T_ocjena == B_ocjena) && T_cs == 1 && B_cs == 1 && M_cs == 1)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else
   {
      if (((T_ocjena != M_ocjena && T_ocjena == B_ocjena) || (T_ocjena == M_ocjena && B_ocjena != T_ocjena) || (T_ocjena != B_ocjena && B_ocjena == M_ocjena)) && (T_cs == 1 && B_cs == 1 && M_cs == 1))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         if ((T_ocjena != B_ocjena && T_ocjena != M_ocjena) && T_cs == 1 && B_cs == 1 && M_cs == 1)
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
      }
      if ((T_cs == 1 && B_cs == 1 && M_cs == 0) || (T_cs == 1 && B_cs == 0 && M_cs == 1) || (T_cs == 0 && B_cs == 1 && M_cs == 1))
      {
         printf("Dva studenta su polozila.");
      }
      else
      {
         if ((T_cs == 1 && B_cs == 0 && M_cs == 0) || (B_cs == 1 && T_cs == 0 && M_cs == 0) || (M_cs == 1 && T_cs == 0 && B_cs == 0))
         {
            printf("Jedan student je polozio.");
         }
      }
   }



   return(0);
}
