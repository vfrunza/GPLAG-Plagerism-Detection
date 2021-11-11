#include <stdio.h>

int main()
{
   double tarik, bojan, mirza;
   double I_par_t, II_par_t, zavrsni_t, zadaca_t, prisustvo_t, I_par_b, II_par_b, zavrsni_b, zadaca_b, prisustvo_b, I_par_m, II_par_m, zavrsni_m, zadaca_m, prisustvo_m;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I_par_t);
   if (I_par_t > 20 || I_par_t < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &II_par_t);
   if (II_par_t > 20 || II_par_t < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo_t);
   if (prisustvo_t > 10 || prisustvo_t < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadaca_t);
   if (zadaca_t > 10 || zadaca_t < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni_t);
   if (zavrsni_t > 40 || zavrsni_t < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I_par_b);
   if (I_par_b > 20 || I_par_b < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &II_par_b);
   if (II_par_b > 20 || II_par_b < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo_b);
   if (prisustvo_b > 10 || prisustvo_b < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadaca_b);
   if (zadaca_b > 10 || zadaca_b < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni_b);
   if (zavrsni_b > 40 || zavrsni_b < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I_par_m);
   if (I_par_m > 20 || I_par_m < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &II_par_m);
   if (II_par_m > 20 || II_par_m < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo_m);
   if (prisustvo_m > 10 || prisustvo_m < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadaca_m);
   if (zadaca_m > 10 || zadaca_m < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni_m);
   if (zavrsni_m > 40 || zavrsni_m < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   tarik = I_par_t + II_par_t + prisustvo_t + zadaca_t + zavrsni_t;
   bojan = I_par_b + II_par_b + prisustvo_b + zadaca_b + zavrsni_b;
   mirza = I_par_m + II_par_m + prisustvo_m + zadaca_m + zavrsni_m;
   if (tarik < 55)
   {
      tarik = 0;
   }
   if (tarik >= 55 && tarik < 65)
   {
      tarik = 6;
   }
   if (tarik >= 65 && tarik < 75)
   {
      tarik = 7;
   }
   if (tarik >= 75 && tarik < 85)
   {
      tarik = 8;
   }
   if (tarik >= 85 && tarik < 92)
   {
      tarik = 9;
   }
   if (tarik >= 92)
   {
      tarik = 10;
   }

   if (bojan < 55)
   {
      bojan = 0;
   }
   if (bojan >= 55 && bojan < 65)
   {
      bojan = 6;
   }
   if (bojan >= 65 && bojan < 75)
   {
      bojan = 7;
   }
   if (bojan >= 75 && bojan < 85)
   {
      bojan = 8;
   }
   if (bojan >= 85 && bojan < 92)
   {
      bojan = 9;
   }
   if (bojan >= 92)
   {
      bojan = 10;
   }

   if (mirza < 55)
   {
      mirza = 0;
   }
   if (mirza >= 55 && mirza < 65)
   {
      mirza = 6;
   }
   if (mirza >= 65 && mirza < 75)
   {
      mirza = 7;
   }
   if (mirza >= 75 && mirza < 85)
   {
      mirza = 8;
   }
   if (mirza >= 85 && mirza < 92)
   {
      mirza = 9;
   }
   if (mirza >= 92)
   {
      mirza = 10;
   }

   if (tarik == 0 && mirza == 0 && bojan == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if ((tarik >= 6 && mirza == 0 && bojan == 0) || (tarik == 0 && mirza >= 6 && bojan == 0) || (tarik == 0 && mirza == 0 && bojan >= 6))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((tarik >= 6 && bojan >= 6 && mirza == 0) || (tarik >= 6 && mirza >= 6 && bojan == 0) || (mirza >= 6 && bojan >= 6 && tarik == 0))
   {
      printf("Dva studenta su polozila.\n");
   }
   if (tarik != 0 && bojan != 0 && mirza != 0)
   {
      printf("Sva tri studenta su polozila.\n");
   }



   if (tarik != bojan && bojan != mirza && tarik != 0 && mirza != 0 && bojan != 0)
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }
   if (((tarik == mirza && mirza != bojan) || (mirza == bojan && bojan != tarik) || (tarik == bojan && mirza != tarik)) && (tarik != 0 && mirza != 0 && bojan != 0))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   if ((tarik == bojan && bojan == mirza) && (tarik != 0 && mirza != 0 && bojan != 0))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }



   return(0);
}
