#include <stdio.h>
#include <math.h>
#define d    0.001
int main()
{
   float tarikpp, bojanpp, mirzapp, tarikdp, tarikz, tarikp, tarikzi, bojandp, bojanz, bojanp, bojanzi, mirzadp, mirzap, mirzaz, mirzazi, tarikb, mirzab, bojanb;
   int   tariko, mirzao, bojano;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &tarikpp);
   if (tarikpp < 0 || tarikpp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tarikdp);
   if (tarikdp < 0 || tarikdp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tarikp);
   if (tarikp < 0 || tarikp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tarikzi);
   if (tarikzi < 0 || tarikzi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &tarikz);
   if (tarikz < 0 || tarikz > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &bojanpp);
   if (bojanpp < 0 || bojanpp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bojandp);
   if (bojandp < 0 || bojandp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bojanp);
   if (bojanp < 0 || bojanp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bojanz);
   if (bojanz < 0 || bojanz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bojanzi);
   if (bojanzi < 0 || bojanzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &mirzapp);
   if (mirzapp < 0 || mirzapp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mirzadp);
   if (mirzadp < 0 || mirzadp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mirzap);
   if (mirzap < 0 || mirzap > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mirzaz);
   if (mirzaz < 0 || mirzaz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mirzazi);
   if (mirzazi < 0 || mirzazi > 40)
   {
      printf("Neispravan broj bodova");

      return(0);
   }
   tarikb = tarikdp + tarikpp + tarikz + tarikp + tarikzi;
   bojanb = bojandp + bojanpp + bojanz + bojanp + bojanzi;
   mirzab = mirzadp + mirzapp + mirzaz + mirzap + mirzazi;
   if (tarikb >= 55 && tarikb <= 65)
   {
      tariko = 6;
   }
   else if (tarikb >= 65 && tarikb <= 75)
   {
      tariko = 7;
   }
   else if (tarikb >= 75 && tarikb <= 85)
   {
      tariko = 8;
   }
   else if (tarikb >= 85 && tarikb <= 92)
   {
      tariko = 9;
   }
   else if (tarikb >= 92 && tarikb <= 100)
   {
      tariko = 10;
   }
   if (bojanb >= 55 && bojanb <= 65)
   {
      bojano = 6;
   }
   else if (bojanb >= 65 && bojanb <= 75)
   {
      bojano = 7;
   }
   else if (bojanb >= 75 && bojanb <= 85)
   {
      bojano = 8;
   }
   else if (bojanb >= 85 && bojanb <= 92)
   {
      bojano = 9;
   }
   else if (bojanb >= 92 && bojanb <= 100)
   {
      bojano = 10;
   }
   if (mirzab >= 55 && mirzab <= 65)
   {
      mirzao = 6;
   }
   else if (mirzab >= 65 && mirzab <= 75)
   {
      mirzao = 7;
   }
   else if (mirzab >= 75 && mirzab <= 85)
   {
      mirzao = 8;
   }
   else if (mirzab >= 85 && mirzab <= 92)
   {
      mirzao = 9;
   }
   else if (mirzab >= 92 && mirzab <= 100)
   {
      mirzao = 10;
   }
   if (tarikb < 55 && mirzab < 55 && bojanb < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((mirzab < 55 && bojanb < 55 && fabs(55 - tarikb) <= d) || (tarikb < 55 && mirzab >= 55 && bojanb < 55) || (tarikb < 55 && mirzab < 55 && bojanb >= 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((tarikb >= 55 && mirzab >= 55 && bojanb < 55) || (tarikb < 55 && mirzab >= 55 && bojanb >= 55) || (tarikb >= 55 && mirzab < 55 && bojanb >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if (tarikb >= 55 && mirzab >= 55 && bojanb >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if (tariko == bojano && bojano == mirzao && tariko == mirzao)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((tariko == bojano && bojano != mirzao) || (tariko == mirzao && mirzao != bojano) || (mirzao == bojano && bojano != tariko))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (tariko != bojano && bojano != mirzao && tariko != mirzao)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
