#include <stdio.h>

int main()
{
   int   pao = 0;
   float suma1 = 0, suma2 = 0, suma3 = 0;
   float pr1, dr1, pri1, zad1, zav1, pr2, dr2, pri2, zad2, zav2, pr3, dr3, pri3, zad3, zav3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pr1);
   if (pr1 < 0 || pr1 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dr1);
   if (dr1 < 0 || dr1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pri1);
   if (pri1 < 0 || pri1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad1);
   if (zad1 < 0 || zad1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zav1);
   if (zav1 < 0 || zav1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pr2);
   if (pr2 < 0 || pr2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dr2);
   if (dr2 < 0 || dr2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pri2);
   if (pri2 < 0 || pri2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad2);
   if (zad2 < 0 || zad2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zav2);
   if (zav2 < 0 || zav2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pr3);
   if (pr3 < 0 || pr3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dr3);
   if (dr3 < 0 || dr3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pri3);
   if (pri3 < 0 || pri3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad3);
   if (zad3 < 0 || zad3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zav3);
   if (zav3 < 0 || zav3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma1 = pr1 + dr1 + pri1 + zad1 + zav1;
   if (suma1 <= 54.99)
   {
      pao++;
   }
   if (suma1 >= 55 && suma1 < 65)
   {
      suma1 = 6;
   }
   else if (suma1 >= 65 && suma1 < 75)
   {
      suma1 = 7;
   }
   else if (suma1 >= 75 && suma1 < 85)
   {
      suma1 = 8;
   }
   else if (suma1 >= 85 && suma1 < 92)
   {
      suma1 = 9;
   }
   else if (suma1 >= 92 && suma1 <= 100)
   {
      suma1 = 10;
   }
   suma2 = pr2 + dr2 + pri2 + zad2 + zav2;
   if (suma2 < 54.99)
   {
      pao++;
   }
   if (suma2 >= 55 && suma2 < 65)
   {
      suma2 = 6;
   }
   else if (suma2 >= 65 && suma2 < 75)
   {
      suma2 = 7;
   }
   else if (suma2 >= 75 && suma2 < 85)
   {
      suma2 = 8;
   }
   else if (suma2 >= 85 && suma2 < 92)
   {
      suma2 = 9;
   }
   else if (suma2 >= 92 && suma2 <= 100)
   {
      suma2 = 10;
   }
   suma3 = pr3 + dr3 + pri3 + zad3 + zav3;
   if (suma3 < 54.99)
   {
      pao++;
   }
   if (suma3 >= 55 && suma3 < 65)
   {
      suma3 = 6;
   }
   else if (suma3 >= 65 && suma3 < 75)
   {
      suma3 = 7;
   }
   else if (suma3 >= 75 && suma3 < 85)
   {
      suma3 = 8;
   }
   else if (suma3 >= 85 && suma3 < 92)
   {
      suma3 = 9;
   }
   else if (suma3 >= 92 && suma3 <= 100)
   {
      suma3 = 10;
   }

   if (pao == 0 && suma1 == suma2 && suma2 == suma3)
   {
      printf("Sva tri studenta su polozila.\n");
      printf("Sva tri studenta imaju istu ocjenu.\n");
      return(0);
   }
   else if (pao == 0 && suma1 != suma2 && suma2 != suma3 && suma1 != suma3)
   {
      printf("Sva tri studenta su polozila.\n");
      printf("Svaki student ima razlicitu ocjenu.\n");
      return(0);
   }
   else if (pao == 0 && ((suma1 == suma2 && suma2 != suma3) || (suma1 == suma3 && suma3 != suma2) || (suma2 == suma3 && suma2 != suma1)))
   {
      printf("Sva tri studenta su polozila.\n");
      printf("Dva od tri studenta imaju istu ocjenu.\n");
      return(0);
   }
   if (pao == 1)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (pao == 2)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (pao == 3)
   {
      printf("Nijedan student nije polozio.\n");
   }

   return(0);
}
