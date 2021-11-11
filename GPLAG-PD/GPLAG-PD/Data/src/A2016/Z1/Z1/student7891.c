                        #include <stdio.h>
                        #define e    0.0001

int main()
{
   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   double tariki, tarikii, tarikzadace, tarikp, tarikzavrsni, x, y, z;    /* x-ukupan broj bodova za tarika, y-bojana, z-mirzu*/

   scanf("%lf", &tariki);
   if (tariki < 0 || tariki > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &tarikii);
   if ((tarikii < 0 || tarikii > 20))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tarikp);
   if ((tarikp < 0 || tarikp > 10))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tarikzadace);
   if ((tarikzadace < 0 || tarikzadace > 10))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tarikzavrsni);
   if ((tarikzavrsni < 0 || tarikzavrsni > 40))
   {
      printf("Neispravan broj bodova"); return(0);
   }

   double bojani, bojanii, bojanzadace, bojanp, bojanzavrsni;

   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &bojani);
   if ((bojani < 0 || bojani > 20))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bojanii);
   if (bojanii < 0 || bojanii > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bojanp);
   if ((bojanp < 0 || bojanp > 10))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bojanzadace);
   if ((bojanzadace < 0 || bojanzadace > 10))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bojanzavrsni);
   if ((bojanzavrsni < 0 || bojanzavrsni > 40))
   {
      printf("Neispravan broj bodova");  return(0);
   }

   double mirzai, mirzaii, mirzap, mirzazadace, mirzazavrsni;

   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &mirzai);
   if ((mirzai < 0 || mirzai > 20))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mirzaii);
   if ((mirzaii < 0 || mirzaii > 20))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mirzap);
   if ((mirzap < 0 || mirzap > 10))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mirzazadace);
   if ((mirzazadace < 0 || mirzazadace > 10))
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mirzazavrsni);
   if ((mirzazavrsni < 0 || mirzazavrsni > 40))
   {
      printf("Neispravan broj bodova");  return(0);
   }
   {
      x = tariki + tarikii + tarikzadace + tarikp + tarikzavrsni;
      y = bojani + bojanii + bojanzadace + bojanzavrsni + bojanp;
      z = mirzai + mirzaii + mirzap + mirzazadace + mirzazavrsni;


      if (x < 55 && y < 55 && z < 55)
      {
         printf("Nijedan student nije polozio.");
      }
      if ((x < 49.999 && y < 49.999 && z > 49.999) || (x < 49.999 && y > 49.999 && z < 49.999) || (x > 49.999 && y < 49.999 && z < 49.999))
      {
         printf("Jedan student je polozio.");
      }
      if ((x > 55 && y > 55 && z < 55) || (x > 55 && y < 55 && z > 55) || (x < 55 && y > 55 && z > 55))
      {
         printf("Dva studenta su polozila.");
      }
      if (x >= 55 && y >= 55 && z >= 55)
      {
         printf("Sva tri studenta su polozila.\n");

         double a, b, c;
         if (x >= 55 && x < 65)
         {
            a = 6;
         }
         else if (x > 65 && x < 75)
         {
            a = 7;
         }
         else if (x >= 75 && x < 85)
         {
            a = 8;
         }
         else if (x >= 85 && x < 92)
         {
            a = 9;
         }
         else if (x >= 92 && x <= 100)
         {
            a = 10;
         }
         if (y >= 55 && y < 65)
         {
            b = 6;
         }
         else if (y > 65 && y < 75)
         {
            b = 7;
         }
         else if (y >= 75 && y < 85)
         {
            b = 8;
         }
         else if (y >= 85 && y < 92)
         {
            b = 9;
         }
         else if (y >= 92 && y <= 100)
         {
            b = 10;
         }
         if (z >= 55 && z < 65)
         {
            c = 6;
         }
         else if (z > 65 && z < 75)
         {
            c = 7;
         }
         else if (z >= 75 && z < 85)
         {
            c = 8;
         }
         else if (z >= 85 && z < 92)
         {
            c = 9;
         }
         else if (z >= 92 && z <= 100)
         {
            c = 10;
         }

         if (a == b && b == c)
         {
            printf("Sva tri studenta imaju istu ocjenu.");
         }
         else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != c))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }
         else if (a != b && b != c && a != c)
         {
            printf("Svaki student ima razlicitu ocjenu.");
         }
      }
   }

   return(0);
}
