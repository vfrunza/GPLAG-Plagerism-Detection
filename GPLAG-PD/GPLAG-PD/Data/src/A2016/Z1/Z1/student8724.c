#include <stdio.h>
#include <stdlib.h>
#define EP     20.0000000000001
#define EP1    10.0000000000001
#define EP2    40.0000000000001
int main()
{
   float TIparc, TIIparc, TPrisustvo, TZadace, TZavrsni, TZbir;
   float BIparc, BIIparc, BPrisustvo, BZadace, BZavrsni, BZbir;
   float MIparc, MIIparc, MPrisustvo, MZadace, MZavrsni, MZbir;
   int   TOcjena, BOcjena, MOcjena;

   //UNOS BODOVA

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &TIparc);
   if (TIparc < 0 || TIparc > EP)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &TIIparc);
   if (TIIparc < 0 || TIIparc > EP)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &TPrisustvo);
   if (TPrisustvo < 0 || TPrisustvo > EP1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &TZadace);
   if (TZadace < 0 || TZadace > EP1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &TZavrsni);
   if (TZavrsni < 0 || TZavrsni > EP2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &BIparc);
   if (BIparc < 0 || BIparc > EP)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &BIIparc);
   if (BIIparc < 0 || BIIparc > EP)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &BPrisustvo);
   if (BPrisustvo < 0 || BPrisustvo > EP1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &BZadace);
   if (BZadace < 0 || BZadace > EP1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &BZavrsni);
   if (BZavrsni < 0 || BZavrsni > EP2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &MIparc);
   if (MIparc < 0 || MIparc > EP)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &MIIparc);
   if (MIIparc < 0 || MIIparc > EP)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &MPrisustvo);
   if (MPrisustvo < 0 || MPrisustvo > EP1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &MZadace);
   if (MZadace < 0 || MZadace > EP1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &MZavrsni);
   if (MZavrsni < 0 || MZavrsni > EP2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   TZbir = TIparc + TIIparc + TPrisustvo + TZadace + TZavrsni;
   BZbir = BIparc + BIIparc + BPrisustvo + BZadace + BZavrsni;
   MZbir = MIparc + MIIparc + MPrisustvo + MZadace + MZavrsni;



   if (TZbir <= 54.99)
   {
      TOcjena = 5;
   }
   else if (TZbir <= 64.99)
   {
      TOcjena = 6;
   }
   else if (TZbir <= 74.99)
   {
      TOcjena = 7;
   }
   else if (TZbir <= 84.99)
   {
      TOcjena = 8;
   }
   else if (TZbir <= 94.99)
   {
      TOcjena = 9;
   }
   else if (TZbir < 100.05)
   {
      TOcjena = 10;
   }


   if (MZbir <= 54.99)
   {
      MOcjena = 5;
   }
   else if (MZbir <= 64.99)
   {
      MOcjena = 6;
   }
   else if (MZbir <= 74.99)
   {
      MOcjena = 7;
   }
   else if (MZbir <= 84.99)
   {
      MOcjena = 8;
   }
   else if (MZbir <= 94.99)
   {
      MOcjena = 9;
   }
   else if (MZbir < 100.05)
   {
      MOcjena = 10;
   }
   if (BZbir <= 54.99)
   {
      BOcjena = 5;
   }
   else if (BZbir <= 4.99)
   {
      BOcjena = 6;
   }
   else if (BZbir <= 74.99)
   {
      BOcjena = 7;
   }
   else if (BZbir <= 84.99)
   {
      BOcjena = 8;
   }
   else if (BZbir <= 94.99)
   {
      BOcjena = 9;
   }
   else if (BZbir < 100.05)
   {
      BOcjena = 10;
   }



   if (TOcjena == 5 && BOcjena == 5 && MOcjena == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else
   {
      if (
         (TOcjena > 5 && BOcjena == 5 && MOcjena == 5) ||
         (TOcjena == 5 && BOcjena > 5 && MOcjena == 5) ||
         (TOcjena == 5 && BOcjena == 5 && MOcjena > 5)
         )
      {
         printf("Jedan student je polozio.\n");
      }

      else
      {
         if ((TOcjena > 5 && BOcjena > 5 && MOcjena <= 5) ||
             (TOcjena > 5 && BOcjena <= 5 && MOcjena > 5) ||
             (TOcjena <= 5 && BOcjena > 5 && MOcjena > 5)
             )
         {
            printf("Dva studenta su polozila.\n");
         }

         else
         {
            if (TOcjena > 5 && BOcjena > 5 && MOcjena > 5)
            {
               printf("Sva tri studenta su polozila.\n");

               if (TOcjena == BOcjena && TOcjena == MOcjena)
               {
                  printf("Sva tri studenta imaju istu ocjenu.\n");
               }

               else
               {
                  if ((TOcjena == BOcjena && TOcjena != MOcjena) ||
                      (TOcjena == MOcjena && TOcjena != BOcjena) ||
                      (MOcjena == BOcjena && TOcjena != MOcjena))
                  {
                     printf("Dva od tri studenta imaju istu ocjenu.\n");
                  }
                  else
                  {
                     if (TOcjena != BOcjena && TOcjena != MOcjena && BOcjena != MOcjena)
                     {
                        printf("Svaki student ima razlicitu ocjenu.\n");
                     }
                  }
               }
            }
         }
      }
   }



   return(0);
}
