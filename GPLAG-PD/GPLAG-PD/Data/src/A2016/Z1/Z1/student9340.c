#include <stdio.h>

int main()
{
   int   br, ocjena1, ocjena2, ocjena3;
   float zbir1, zbir2, zbir3;
   float Iparcijalni1, IIparcijalni1, Zadace1, Zavrsniispit1, Prisustvo1, Iparcijalni2, IIparcijalni2, Zadace2, Zavrsniispit2, Prisustvo2, Iparcijalni3, IIparcijalni3, Zadace3, Zavrsniispit3, Prisustvo3;

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%f", &Iparcijalni1);
   if (Iparcijalni1 < 0 || Iparcijalni1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcijalni1);
   if (IIparcijalni1 < 0 || IIparcijalni1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Prisustvo1);
   if (Prisustvo1 < 0 || Prisustvo1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Zadace1);
   if (Zadace1 < 0 || Zadace1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Zavrsniispit1);
   if (Zavrsniispit1 < 0 || Zavrsniispit1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%f", &Iparcijalni2);
   if (Iparcijalni2 < 0 || Iparcijalni2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcijalni2);
   if (IIparcijalni2 < 0 || IIparcijalni2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Prisustvo2);
   if (Prisustvo2 < 0 || Prisustvo2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Zadace2);
   if (Zadace2 < 0 || Zadace2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Zavrsniispit2);
   if (Zavrsniispit2 < 0 || Zavrsniispit2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%f", &Iparcijalni3);
   if (Iparcijalni3 < 0 || Iparcijalni3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcijalni3);
   if (IIparcijalni3 < 0 || IIparcijalni3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Prisustvo3);
   if (Prisustvo3 < 0 || Prisustvo3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Zadace3);
   if (Zadace3 < 0 || Zadace3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Zavrsniispit3);
   if (Zavrsniispit3 < 0 || Zavrsniispit3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   zbir1 = Iparcijalni1 + IIparcijalni1 + Zadace1 + Zavrsniispit1 + Prisustvo1;
   zbir2 = Iparcijalni2 + IIparcijalni2 + Zadace2 + Zavrsniispit2 + Prisustvo2;
   zbir3 = Iparcijalni3 + IIparcijalni3 + Zadace3 + Zavrsniispit3 + Prisustvo3;
   if (zbir1 < (float)55)
   {
      ocjena1 = 5;
   }

   if (zbir1 >= 55. && zbir1 < 65)
   {
      ocjena1 = 6;
   }
   else
   {
      if (zbir1 >= 65. && zbir1 < 75)
      {
         ocjena1 = 7;
      }
      else
      {
         if (zbir1 >= 75. && zbir1 < 85)
         {
            ocjena1 = 8;
         }
         else
         {
            if (zbir1 >= 85. && zbir1 < 92)
            {
               ocjena1 = 9;
            }
            else
            {
               if (zbir1 >= 92. && zbir1 <= 100)
               {
                  ocjena1 = 10;
               }
            }
         }
      }
   }
   if (zbir2 < 55)
   {
      ocjena2 = 5;
   }
   if (zbir2 >= 55. && zbir2 < 65)
   {
      ocjena2 = 6;
   }
   else
   {
      if (zbir2 >= 65. && zbir2 < 75)
      {
         ocjena2 = 7;
      }
      else
      {
         if (zbir2 >= 75. && zbir2 < 85)
         {
            ocjena2 = 8;
         }
         else
         {
            if (zbir2 >= 85. && zbir2 < 92)
            {
               ocjena2 = 9;
            }
            else
            {
               if (zbir2 >= 92. && zbir2 <= 100)
               {
                  ocjena2 = 10;
               }
            }
         }
      }
   }
   if (zbir3 < 55)
   {
      ocjena3 = 5;
   }
   if (zbir3 >= 55. && zbir3 < 65)
   {
      ocjena3 = 6;
   }
   else
   {
      if (zbir3 >= 65. && zbir3 < 75)
      {
         ocjena3 = 7;
      }
      else
      {
         if (zbir3 >= 75. && zbir3 < 85)
         {
            ocjena3 = 8;
         }
         else
         {
            if (zbir3 >= 85. && zbir3 < 92)
            {
               ocjena3 = 9;
            }
            else
            {
               if (zbir3 >= 92. && zbir3 <= 100)
               {
                  ocjena3 = 10;
               }
            }
         }
      }
   }


   if (ocjena1 == 5 && ocjena2 == 5 && ocjena3 == 5)
   {
      br = 0;
      printf("Nijedan student nije polozio.\n");
   }
   else
   {
      if (ocjena1 != 5 && ocjena2 != 5 && ocjena3 != 5)
      {
         br = 3;
         printf("Sva tri studenta su polozila.\n");
      }
      else
      {
         if ((ocjena1 != 5 && ocjena2 == 5 && ocjena3 == 5) || (ocjena1 == 5 && ocjena2 == 5 && ocjena3 != 5) || (ocjena1 == 5 && ocjena2 != 5 && ocjena3 == 5))
         {
            br = 1;
            printf("Jedan student je polozio.\n");
         }
         else
         {
            if ((ocjena1 != 5 && ocjena2 != 5 && ocjena3 == 5) || (ocjena1 == 5 && ocjena2 != 5 && ocjena3 != 5) || (ocjena1 != 5 && ocjena2 == 5 && ocjena3 != 5))
            {
               br = 2;
               printf("Dva studenta su polozila.\n");
            }
         }
      }
   }

   if (br == 3)
   {
      if (ocjena1 == ocjena2 && ocjena2 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         if (ocjena1 != ocjena2 && ocjena2 != ocjena3 && ocjena1 != ocjena3)
         {
            printf("Svaki student ima razlicitu ocjenu.\n");
         }
         else
         {
            if ((ocjena1 == ocjena2 && ocjena2 != ocjena3) || (ocjena1 == ocjena3 && ocjena2 != ocjena3) || (ocjena2 == ocjena3 && ocjena3 != ocjena1))
            {
               printf("Dva od tri studenta imaju istu ocjenu.\n");
            }
         }
      }
   }

   return(0);
}
