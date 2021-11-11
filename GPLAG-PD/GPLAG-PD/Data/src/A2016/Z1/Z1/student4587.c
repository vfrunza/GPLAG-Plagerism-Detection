#include <stdio.h>

int main()
{
   double I_T, II_T, P_T, Z_T, ZI_T, I_B, II_B, P_B, Z_B, ZI_B, I_M, II_M, P_M, Z_M, ZI_M;
   double bodovi_T, bodovi_B, bodovi_M;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I_T);
   if (I_T < 0 || I_T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &II_T);
   if (II_T < 0 || II_T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P_T);
   if (P_T < 0 || P_T > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Z_T);
   if (Z_T < 0 || Z_T > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI_T);
   if (ZI_T < 0 || ZI_T > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I_B);
   if (I_B < 0 || I_B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &II_B);
   if (II_B < 0 || II_B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P_B);
   if (P_B < 0 || P_B > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Z_B);
   if (Z_B < 0 || Z_B > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI_B);
   if (ZI_B < 0 || ZI_B > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I_M);
   if (I_M < 0 || I_M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &II_M);
   if (II_M < 0 || II_M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P_M);
   if (P_M < 0 || P_M > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z_M);
   if (Z_M < 0 || Z_M > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI_M);
   if (ZI_M < 0 || ZI_M > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bodovi_T = I_T + II_T + P_T + Z_T + ZI_T;
   bodovi_B = I_B + II_B + P_B + Z_B + ZI_B;
   bodovi_M = I_M + II_M + P_M + Z_M + ZI_M;
   if (bodovi_T < 55 && bodovi_B < 55 && bodovi_M < 55)
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }
   if ((bodovi_T >= 55 && bodovi_B >= 55 && bodovi_M < 55) || (bodovi_T < 55 && bodovi_B >= 55 && bodovi_M >= 55) || (bodovi_T >= 55 && bodovi_B < 55 && bodovi_M >= 55))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   if ((bodovi_T >= 55 && bodovi_B < 55 && bodovi_M < 55) || (bodovi_T < 55 && bodovi_B >= 55 && bodovi_M < 55) || (bodovi_T < 55 && bodovi_B < 55 && bodovi_M >= 55))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   else if (bodovi_T >= 55 && bodovi_B >= 55 && bodovi_M >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if ((bodovi_T >= 55 && bodovi_T < 65 && bodovi_B >= 55 && bodovi_B < 65 && bodovi_M >= 55 && bodovi_M < 65) || (bodovi_T >= 65 && bodovi_T < 75 && bodovi_B >= 65 && bodovi_B < 75 && bodovi_M >= 65 && bodovi_M < 75) || (bodovi_T >= 75 && bodovi_T < 85 && bodovi_B >= 75 && bodovi_B < 85 && bodovi_M >= 75 && bodovi_M < 85) || (bodovi_T >= 85 && bodovi_T < 92 && bodovi_B >= 85 && bodovi_B < 92 && bodovi_M >= 85 && bodovi_M < 92) || (bodovi_T >= 92 && bodovi_T <= 100 && bodovi_B >= 92 && bodovi_B <= 100 && bodovi_M >= 92 && bodovi_M <= 100))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
         return(0);
      }

      else if ((bodovi_T < 65 && bodovi_B < 65 && !(bodovi_M < 65)) || (bodovi_T < 65 && bodovi_M < 65 && !(bodovi_B < 65)) || (bodovi_B < 65 && bodovi_M < 65 && !(bodovi_T < 65)) || (bodovi_T >= 65 && bodovi_T < 75 && bodovi_B >= 65 && bodovi_B < 75 && !(bodovi_M >= 65) && !(bodovi_M < 75)) || (bodovi_T >= 65 && bodovi_T < 75 && bodovi_M >= 65 && bodovi_M < 75 && !(bodovi_B >= 65) && !(bodovi_B < 75)) || (bodovi_B >= 65 && bodovi_B < 75 && bodovi_M >= 65 && bodovi_M < 75 && !(bodovi_T >= 65) && !(bodovi_T < 75)) || (bodovi_T >= 75 && bodovi_T < 85 && bodovi_B >= 75 && bodovi_B < 85 && !(bodovi_M >= 75) && !(bodovi_M < 85)) || (bodovi_T >= 75 && bodovi_T < 85 && bodovi_M >= 75 && bodovi_M < 85 && !(bodovi_B >= 75) && !(bodovi_B < 85)) || (bodovi_B >= 75 && bodovi_B < 85 && bodovi_M >= 75 && bodovi_M < 85 && !(bodovi_T >= 75) && !(bodovi_T < 85)) || (bodovi_T >= 85 && bodovi_T < 92 && bodovi_B >= 85 && bodovi_B < 92 && !(bodovi_M >= 85) && !(bodovi_M < 92)) || (bodovi_T >= 85 && bodovi_T < 92 && bodovi_M >= 85 && bodovi_M < 92 && !(bodovi_B >= 85) && !(bodovi_B < 92)) || (bodovi_B >= 85 && bodovi_B < 92 && bodovi_M >= 85 && bodovi_M < 92 && !(bodovi_T >= 85) && !(bodovi_T < 92)) || (bodovi_T >= 92 && bodovi_T <= 100 && bodovi_B >= 92 && bodovi_B <= 100 && !(bodovi_M >= 92) && !(bodovi_M <= 100)) || (bodovi_T >= 92 && bodovi_T <= 100 && bodovi_M >= 92 && bodovi_M <= 100 && !(bodovi_B >= 92) && !(bodovi_B <= 100)) || (bodovi_B >= 92 && bodovi_B <= 100 && bodovi_M >= 92 && bodovi_M <= 100 && !(bodovi_T >= 92) && !(bodovi_T <= 100)))
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
