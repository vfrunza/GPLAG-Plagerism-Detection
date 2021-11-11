#include <stdio.h>
int main()
{
   double prvi_parc, prvi_parc2, prvi_parc3, drugi_parc, drugi_parc2, drugi_parc3, prisustvo, prisustvo2, prisustvo3, zadace, zadace2, zadace3, zavrsni, zavrsni2, zavrsni3, suma1, suma2, suma3;
   int    br1 = 0, br2 = 0, br3 = 0, br4 = 0, br5 = 0, br6 = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prvi_parc);
   if (prvi_parc < 0 || prvi_parc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugi_parc);
   if (drugi_parc < 0 || drugi_parc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace);
   if (zadace < 0 || zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma1 = prvi_parc + drugi_parc + prisustvo + zadace + zavrsni;

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prvi_parc2);
   if (prvi_parc2 < 0 || prvi_parc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugi_parc2);
   if (drugi_parc2 < 0 || drugi_parc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace2);
   if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni2);
   if (zavrsni2 < 0 || zavrsni2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma2 = prvi_parc2 + drugi_parc2 + prisustvo2 + zadace2 + zavrsni2;

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prvi_parc3);
   if (prvi_parc3 < 0 || prvi_parc3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugi_parc3);
   if (drugi_parc3 < 0 || drugi_parc3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace3);
   if (zadace3 < 0 || zadace3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni3);
   if (zavrsni3 < 0 || zavrsni3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma3 = prvi_parc3 + drugi_parc3 + prisustvo3 + zadace3 + zavrsni3;

   if (suma1 < 55)
   {
      br1++;
   }
   else if (suma1 >= 55 && suma1 < 65)
   {
      br2++;
   }
   else if (suma1 >= 65 && suma1 < 75)
   {
      br3++;
   }
   else if (suma1 >= 75 && suma1 < 85)
   {
      br4++;
   }
   else if (suma1 >= 85 && suma1 < 92)
   {
      br5++;
   }
   else if (suma1 >= 92 && suma1 <= 100)
   {
      br6++;
   }

   if (suma2 < 55)
   {
      br1++;
   }
   else if (suma2 >= 55 && suma2 < 65)
   {
      br2++;
   }
   else if (suma2 >= 65 && suma2 < 75)
   {
      br3++;
   }
   else if (suma2 >= 75 && suma2 < 85)
   {
      br4++;
   }
   else if (suma2 >= 85 && suma2 < 92)
   {
      br5++;
   }
   else if (suma2 >= 92 && suma2 <= 100)
   {
      br6++;
   }

   if (suma3 < 55)
   {
      br1++;
   }
   else if (suma3 >= 55 && suma3 < 65)
   {
      br2++;
   }
   else if (suma3 >= 65 && suma3 < 75)
   {
      br3++;
   }
   else if (suma3 >= 75 && suma3 < 85)
   {
      br4++;
   }
   else if (suma3 >= 85 && suma3 < 92)
   {
      br5++;
   }
   else if (suma3 >= 92 && suma3 <= 100)
   {
      br6++;
   }

   if (br1 == 3)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (br1 == 2)
   {
      printf("Jedan student je polozio.");
   }
   else if (br1 == 1)
   {
      printf("Dva studenta su polozila.");
   }
   else if (br1 == 0)
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if (br1 == 0)
   {
      if (br2 == 3 || br3 == 3 || br4 == 3 || br5 == 3 || br6 == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (br2 == 2 || br3 == 2 || br4 == 2 || br5 == 2 || br6 == 2)
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
