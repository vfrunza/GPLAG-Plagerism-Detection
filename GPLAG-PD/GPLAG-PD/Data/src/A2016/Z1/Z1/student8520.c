#include <stdio.h>
#include <math.h>

int ispravnostParcijala(float bodovi)
{
   if (bodovi < 0 || bodovi > 20)
   {
      return(0);
   }
   else
   {
      return(1);
   }
}

int ispravnostZavrsnog(float bodovi)
{
   if (bodovi < 0 || bodovi > 40)
   {
      return(0);
   }
   else
   {
      return(1);
   }
}

int ispravnostPIZ(float bodovi)
{
   if (bodovi < 0 || bodovi > 10)
   {
      return(0);
   }
   else
   {
      return(1);
   }
}

void polozeni(float t, float b, float h)
{
   if (fabs(t) < 54.99999 && b < 54.99999 && h < 54.99999)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((fabs(t) < 54.99999 && b >= 55.00 && h >= 55.00) || (t >= 55.00 && b < 54.99999 && h >= 55.00) || (t >= 55.00 && b >= 55.00 && h < 54.99999))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((fabs(t) >= 54.99999 && b < 54.99999 && h < 54.99999) || (fabs(t) < 54.99999 && b >= 55.00 && h < 54.99999) || (fabs(t) < 54.99999 && b < 54.99999 && h >= 55.00))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   {
      if (t >= 55 && t < 65)
      {
         t = 6;
      }
      else if (t >= 65 && t < 75)
      {
         t = 7;
      }
      else if (t >= 75 && t < 85)
      {
         t = 8;
      }
      else if (t >= 85 && t < 95)
      {
         t = 9;
      }
      else
      {
         t = 10;
      }

      if (b >= 55 && b < 65)
      {
         b = 6;
      }
      else if (b >= 65 && b < 75)
      {
         b = 7;
      }
      else if (b >= 75 && b < 85)
      {
         b = 8;
      }
      else if (b >= 85 && b < 95)
      {
         b = 9;
      }
      else
      {
         b = 10;
      }

      if (h >= 55 && h < 65)
      {
         h = 6;
      }
      else if (h >= 65 && h < 75)
      {
         h = 7;
      }
      else if (h >= 75 && h < 85)
      {
         h = 8;
      }
      else if (h >= 85 && h < 95)
      {
         h = 9;
      }
      else
      {
         h = 10;
      }

      printf("Sva tri studenta su polozila.\n");
      if (fabs(t - b) < 0.0000001 && fabs(b - h) < 0.0000001)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((fabs(t - b) < 0.0000001 && fabs(b - h) >= 0.0000001) || (fabs(t - h) < 0.0000001 && fabs(h - b) >= 0.0000001) || (fabs(h - b) < 0.0000001 && fabs(t - b) >= 0.0000001))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
}

int main()
{
   float tarikpp, tarikdp, tarikzd, tarikp, tarikza;
   float bojanpp, bojandp, bojanzd, bojanp, bojanza;
   float mirzapp, mirzadp, mirzazd, mirzap, mirzaza;
   float t, b, m;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &tarikpp);
   if (!ispravnostParcijala(tarikpp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tarikdp);
   if (!ispravnostParcijala(tarikdp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tarikp);
   if (!ispravnostPIZ(tarikp))
   {
      printf("Neispravan broj bodva");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tarikzd);
   if (!ispravnostPIZ(tarikzd))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tarikza);
   if (!ispravnostZavrsnog(tarikza))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bojanpp);
   if (!ispravnostParcijala(bojanpp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bojandp);
   if (!ispravnostParcijala(bojandp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bojanp);
   if (!ispravnostPIZ(bojanp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bojanzd);
   if (!ispravnostPIZ(bojanzd))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bojanza);
   if (!ispravnostZavrsnog(bojanza))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &mirzapp);
   if (!ispravnostParcijala(mirzapp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mirzadp);
   if (!ispravnostParcijala(mirzadp))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mirzap);
   if (!ispravnostPIZ(mirzap))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mirzazd);
   if (!ispravnostPIZ(mirzazd))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mirzaza);
   if (!ispravnostZavrsnog(mirzaza))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   t = tarikpp + tarikdp + tarikp + tarikzd + tarikza;
   b = bojanpp + bojandp + bojanp + bojanzd + bojanza;
   m = mirzapp + mirzadp + mirzap + mirzazd + mirzaza;
   polozeni(t, b, m);
   return(0);
}
