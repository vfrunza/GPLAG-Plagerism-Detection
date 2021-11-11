#include <stdio.h>
#include <math.h>

#define e    0.001

int main()
{
   float Tarik_b, Tarik_1, Tarik_2, Tarik_p, Tarik_z, Tarik_I, Bojan_b, Bojan_1, Bojan_2, Bojan_p, Bojan_z, Bojan_I, Mirza_b, Mirza_1, Mirza_2, Mirza_p, Mirza_z, Mirza_I;
   int   Tarik_ocjena, Bojan_ocjena, Mirza_ocjena, Tarik_prolaz, Bojan_prolaz, Mirza_prolaz;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit:");
   scanf("%f", &Tarik_1);
   if (Tarik_1 < 0 || Tarik_1 > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" II parcijalni ispit:");
   }
   scanf("%f", &Tarik_2);
   if (Tarik_2 < 0 || Tarik_2 > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Prisustvo:");
   }
   scanf("%f", &Tarik_p);
   if (Tarik_p < 0. || Tarik_p > 10.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Zadace:");
   }
   scanf("%f", &Tarik_z);
   if (Tarik_z < 0. || Tarik_z > 10.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Zavrsni ispit:");
   }
   scanf("%f", &Tarik_I);
   if (Tarik_I < 0. || Tarik_I > 40.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   Tarik_b = Tarik_I + Tarik_1 + Tarik_2 + Tarik_p + Tarik_z;



   printf(" Unesite bodove za Bojana:\nI parcijalni ispit:");
   scanf("%f", &Bojan_1);
   if (Bojan_1 < 0. || Bojan_1 > 20.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" II parcijalni ispit:");
   }
   scanf("%f", &Bojan_2);
   if (Bojan_2 < 0. || Bojan_2 > 20.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Prisustvo:");
   }
   scanf("%f", &Bojan_p);
   if (Bojan_p < 0. || Bojan_p > 10.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Zadace:");
   }
   scanf("%f", &Bojan_z);
   if (Bojan_z < 0. || Bojan_z > 10.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Zavrsni ispit:");
   }
   scanf("%f", &Bojan_I);
   if (Bojan_I < 0. || Bojan_I > 40.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   Bojan_b = Bojan_I + Bojan_1 + Bojan_2 + Bojan_p + Bojan_z;



   printf(" Unesite bodove za Mirzu:\nI parcijalni ispit:");
   scanf("%f", &Mirza_1);
   if (Mirza_1 < 0. || Mirza_1 > 20.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" II parcijalni ispit:");
   }
   scanf("%f", &Mirza_2);
   if (Mirza_2 < 0. || Mirza_2 > 20.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Prisustvo:");
   }
   scanf("%f", &Mirza_p);
   if (Mirza_p < 0. || Mirza_p > 10.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Zadace:");
   }
   scanf("%f", &Mirza_z);
   if (Mirza_z < 0. || Mirza_z > 10.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf(" Zavrsni ispit:");
   }
   scanf("%f", &Mirza_I);
   if (Mirza_I < 0. || Mirza_I > 40.)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   Mirza_b = Mirza_I + Mirza_1 + Mirza_2 + Mirza_p + Mirza_z;



   if (Bojan_b < 55.0)
   {
      Bojan_ocjena = 0;
   }
   else if ((Bojan_b > 55.0 || fabs(Bojan_b - 55.0) < e) && Bojan_b < 65.0)
   {
      Bojan_ocjena = 6;
   }
   else if ((Bojan_b > 65.0 || fabs(Bojan_b - 65.0) < e) && Bojan_b < 75.0)
   {
      Bojan_ocjena = 7;
   }
   else if ((Bojan_b > 75.0 || fabs(Bojan_b - 75.0) < e) && Bojan_b < 85.0)
   {
      Bojan_ocjena = 8;
   }
   else if ((Bojan_b > 85.0 || fabs(Bojan_b - 85.0) < e) && Bojan_b < 92.0)
   {
      Bojan_ocjena = 9;
   }
   else if ((Bojan_b > 92.0 || fabs(Bojan_b - 92.0) < e) && (Bojan_b < 100.0 || fabs(Bojan_b - 100.0) < e))
   {
      Bojan_ocjena = 10;
   }



   if (Tarik_b < 55.0)
   {
      Tarik_ocjena = 0;
   }
   else if ((Tarik_b > 55.0 || fabs(Tarik_b - 55.0) < e) && Tarik_b < 65.0)
   {
      Tarik_ocjena = 6;
   }
   else if ((Tarik_b > 65.0 || fabs(Tarik_b - 65.0) < e) && Tarik_b < 75.0)
   {
      Tarik_ocjena = 7;
   }
   else if ((Tarik_b > 75.0 || fabs(Tarik_b - 75.0) < e) && Tarik_b < 85.0)
   {
      Tarik_ocjena = 8;
   }
   else if ((Tarik_b > 85.0 || fabs(Tarik_b - 85.0) < e) && Tarik_b < 92.0)
   {
      Tarik_ocjena = 9;
   }
   else if ((Tarik_b > 92.0 || fabs(Tarik_b - 92.0) < e) && (Tarik_b < 100.0 || fabs(Tarik_b - 100.0) < e))
   {
      Tarik_ocjena = 10;
   }



   if (Mirza_b < 55.0)
   {
      Mirza_ocjena = 0;
   }
   else if ((Mirza_b > 55.0 || fabs(Mirza_b - 55.0) < e) && Mirza_b < 65.0)
   {
      Mirza_ocjena = 6;
   }
   else if ((Mirza_b > 65.0 || fabs(Mirza_b - 65.0) < e) && Mirza_b < 75.0)
   {
      Mirza_ocjena = 7;
   }
   else if ((Mirza_b > 75.0 || fabs(Mirza_b - 75.0) < e) && Mirza_b < 85.0)
   {
      Mirza_ocjena = 8;
   }
   else if ((Mirza_b > 85.0 || fabs(Mirza_b - 85.0) < e) && Mirza_b < 92.0)
   {
      Mirza_ocjena = 9;
   }
   else if ((Mirza_b > 92.0 || fabs(Mirza_b - 92.0) < e) && (Mirza_b < 100.0 || (Mirza_b - 100.0) < e))
   {
      Mirza_ocjena = 10;
   }



   if (Tarik_ocjena == 0)
   {
      Tarik_prolaz = 0;
   }
   else if (Tarik_ocjena == 6 || Tarik_ocjena == 7 || Tarik_ocjena == 8 || Tarik_ocjena == 9 || Tarik_ocjena == 10)
   {
      Tarik_prolaz = 1;
   }

   if (Bojan_ocjena == 0)
   {
      Bojan_prolaz = 0;
   }
   else if (Bojan_ocjena == 6 || Bojan_ocjena == 7 || Bojan_ocjena == 8 || Bojan_ocjena == 9 || Bojan_ocjena == 10)
   {
      Bojan_prolaz = 1;
   }

   if (Mirza_ocjena == 0)
   {
      Mirza_prolaz = 0;
   }
   else if (Mirza_ocjena == 6 || Mirza_ocjena == 7 || Mirza_ocjena == 8 || Mirza_ocjena == 9 || Mirza_ocjena == 10)
   {
      Mirza_prolaz = 1;
   }


   if (Tarik_prolaz == 0 && Bojan_prolaz == 0 && Mirza_prolaz == 0)
   {
      printf(" Nijedan student nije polozio.");
      return(0);
   }
   else if (Tarik_prolaz == 1 && Bojan_prolaz == 0 && Mirza_prolaz == 0)
   {
      printf(" Jedan student je polozio.");
   }
   else if (Tarik_prolaz == 0 && Bojan_prolaz == 1 && Mirza_prolaz == 0)
   {
      printf(" Jedan student je polozio.");
   }
   else if (Tarik_prolaz == 0 && Bojan_prolaz == 0 && Mirza_prolaz == 1)
   {
      printf(" Jedan student je polozio.");
   }
   else if (Tarik_prolaz == 1 && Bojan_prolaz == 1 && Mirza_prolaz == 0)
   {
      printf(" Dva studenta su polozila.");
   }
   else if (Tarik_prolaz == 1 && Bojan_prolaz == 0 && Mirza_prolaz == 1)
   {
      printf(" Dva studenta su polozila.");
   }
   else if (Tarik_prolaz == 0 && Bojan_prolaz == 1 && Mirza_prolaz == 1)
   {
      printf(" Dva studenta su polozila.");
   }
   else if (Tarik_prolaz == 1 && Bojan_prolaz == 1 && Mirza_prolaz == 1)
   {
      printf(" Sva tri studenta su polozila.");
   }
   if (Tarik_prolaz == 0 || Bojan_prolaz == 0 || Mirza_prolaz == 0)
   {
      return(0);
   }
   if (Tarik_ocjena == Bojan_ocjena && Tarik_ocjena == Mirza_ocjena && Bojan_ocjena == Mirza_ocjena)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else if ((Tarik_ocjena == Bojan_ocjena && Bojan_ocjena != Mirza_ocjena && Tarik_ocjena != Mirza_ocjena) || (Tarik_ocjena == Mirza_ocjena && Bojan_ocjena != Mirza_ocjena && Tarik_ocjena != Mirza_ocjena) || (Bojan_ocjena == Mirza_ocjena && Tarik_ocjena != Bojan_ocjena && Tarik_ocjena != Mirza_ocjena))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (Tarik_ocjena != Mirza_ocjena && Tarik_ocjena != Bojan_ocjena && Mirza_ocjena != Bojan_ocjena)
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }
   return(0);
}
