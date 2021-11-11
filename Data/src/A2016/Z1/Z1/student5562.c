#include <stdio.h>
#include <math.h>
#define EPS    0.00001


int main()
{
   float bod = 0;             /*VARIJABLE KOJE BROJE BODOVE*/
   float uk = 0;
   int   tarik, bojan, mirza; /*VARIJABLA KOJA SADRZI VRIJEDNOST OCJENE*/
   int   br  = 3;             /*VARIJABLA KOJA BROJI BROJ STUDENATA KOJI SU POLOZILI*/
   int   jed = 3;             /*VARIJABLA KOJA BROJI BROJ RAZLICITIH OCJENA, POD UVJETOM DA SU SVI POLOZILI*/



   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &bod); if (bod - 20 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("II parcijalni ispit: ");
   scanf("%f", &bod); if (bod - 20 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Prisustvo: ");
   scanf("%f", &bod); if (bod - 10 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Zadace: ");
   scanf("%f", &bod); if (bod - 10 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Zavrsni ispit: ");
   scanf("%f", &bod); if (bod - 40 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   if (uk - 55 < -EPS)
   {
      tarik = 5;
      br--;
   }
   else if (uk - 55 >= EPS && uk - 65 < EPS)
   {
      tarik = 6;
   }
   else if (uk - 65 >= EPS && uk - 75 < EPS)
   {
      tarik = 7;
   }
   else if (uk - 75 >= EPS && uk - 85 < EPS)
   {
      tarik = 8;
   }
   else if (uk - 85 >= EPS && uk - 92 < EPS)
   {
      tarik = 9;
   }
   else if (uk - 92 >= EPS && uk - 100 <= EPS)
   {
      tarik = 10;
   }


   uk = 0;      /*VARIJABLA SE RESETUJE, PONOVO CE SE KORISTITI*/


   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &bod); if (bod - 20 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("II parcijalni ispit: ");
   scanf("%f", &bod); if (bod - 20 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Prisustvo: ");
   scanf("%f", &bod); if (bod - 10 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Zadace: ");
   scanf("%f", &bod); if (bod - 10 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Zavrsni ispit: ");
   scanf("%f", &bod); if (bod - 40 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   if (uk - 55 < EPS)
   {
      bojan = 5;
      br--;
   }
   else if (uk - 55 >= EPS && uk - 65 < EPS)
   {
      bojan = 6;
   }
   else if (uk - 65 >= EPS && uk - 75 < EPS)
   {
      bojan = 7;
   }
   else if (uk - 75 >= EPS && uk - 85 < EPS)
   {
      bojan = 8;
   }
   else if (uk - 85 >= EPS && uk - 92 < EPS)
   {
      bojan = 9;
   }
   else if (uk - 92 >= EPS && uk - 100 <= EPS)
   {
      bojan = 10;
   }

   uk = 0;      /*RESET*/


   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &bod); if (bod - 20 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("II parcijalni ispit: ");
   scanf("%f", &bod); if (bod - 20 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Prisustvo: ");
   scanf("%f", &bod); if (bod - 10 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Zadace: ");
   scanf("%f", &bod); if (bod - 10 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   printf("Zavrsni ispit: ");
   scanf("%f", &bod); if (bod - 40 > EPS || bod < -EPS)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uk += bod;

   if (uk - 55 < EPS)
   {
      mirza = 5;
      br--;
   }
   else if (uk - 55 >= EPS && uk - 65 < EPS)
   {
      mirza = 6;
   }
   else if (uk - 65 >= EPS && uk - 75 < EPS)
   {
      mirza = 7;
   }
   else if (uk - 75 >= EPS && uk - 85 < EPS)
   {
      mirza = 8;
   }
   else if (uk - 85 >= EPS && uk - 92 < EPS)
   {
      mirza = 9;
   }
   else if (uk - 92 >= EPS && uk - 100 <= EPS)
   {
      mirza = 10;
   }

   if (br == 3)      /*BROJANJE PROLAZNIKA*/

   {
      printf("Sva tri studenta su polozila.\n");

      if (fabs(mirza - bojan) >= EPS)           /*BROJANJE JEDNAKIH OCJENA*/
      {
         jed--;
      }

      else if (fabs(mirza - tarik) >= EPS)
      {
         jed--;
      }
      if (fabs(tarik - bojan) >= EPS)
      {
         jed--;
      }



      if (jed == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (jed == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (jed == 1)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   else if (br == 2)
   {
      printf("Dva studenta su polozila.");
   }
   else if (br == 1)
   {
      printf("Jedan student je polozio.");
   }
   else if (br == 0)
   {
      printf("Nijedan student nije polozio.");
   }



   return(0);
}
