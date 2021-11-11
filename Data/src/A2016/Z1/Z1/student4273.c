#include <stdio.h>
#define sestDonja      55
#define sestGornja     64
#define sedamDonja     65
#define sedamGornja    74
#define osamDonja      75
#define osamGornja     84
#define devetDonja     85
#define devetGornja    91
#define desetDonja     92
#define desetGornja    100

int main()
{
   double prviParcijalniIspit1, prviParcijalniIspit2, prviParcijalniIspit3, drugiParcijalniIspit1, drugiParcijalniIspit2, drugiParcijalniIspit3, prisustvo1, prisustvo2, prisustvo3, zadace1, zadace2, zadace3, zavrsniIspit1, zavrsniIspit2, zavrsniIspit3, ukupno1, ukupno2, ukupno3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prviParcijalniIspit1);
   if (prviParcijalniIspit1 < 0 || prviParcijalniIspit1 > 21)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiParcijalniIspit1);
   if (drugiParcijalniIspit1 < 0 || drugiParcijalniIspit1 > 21)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 11)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace1);
   if (zadace1 < 0 || zadace1 > 11)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsniIspit1);
   if (zavrsniIspit1 < 0 || zavrsniIspit1 > 41)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prviParcijalniIspit2);
   if (prviParcijalniIspit2 < 0 || prviParcijalniIspit2 > 21)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiParcijalniIspit2);
   if (drugiParcijalniIspit2 < 0 || drugiParcijalniIspit2 > 21)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 11)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace2);
   if (zadace2 < 0 || zadace2 > 11)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsniIspit2);
   if (zavrsniIspit2 < 0 || zavrsniIspit2 > 41)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prviParcijalniIspit3);
   if (prviParcijalniIspit3 < 0 || prviParcijalniIspit3 > 21)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiParcijalniIspit3);
   if (drugiParcijalniIspit3 < 0 || drugiParcijalniIspit3 > 21)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 11)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace3);
   if (zadace3 < 0 || zadace3 > 11)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsniIspit3);
   if (zavrsniIspit1 < 0 || zavrsniIspit1 > 41)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   ukupno1 = prviParcijalniIspit1 + drugiParcijalniIspit1 + prisustvo1 + zadace1 + zavrsniIspit1;
   ukupno2 = prviParcijalniIspit2 + drugiParcijalniIspit2 + prisustvo2 + zadace2 + zavrsniIspit2;
   ukupno3 = prviParcijalniIspit3 + drugiParcijalniIspit3 + prisustvo3 + zadace3 + zavrsniIspit3;

   if (ukupno1 < sestDonja && ukupno2 < sestDonja && ukupno3 < sestDonja)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((ukupno1 >= sestDonja && ukupno2 < sestDonja && ukupno3 < sestDonja) || (ukupno2 >= sestDonja && ukupno3 < sestDonja && ukupno1 < sestDonja) || (ukupno3 >= sestDonja && ukupno1 < sestDonja && ukupno2 < sestDonja))
   {
      printf("Jedan student je polozio.");
   }
   else if ((ukupno1 < sestDonja && ukupno2 > sestDonja && ukupno3 > sestDonja) || (ukupno2 < sestDonja && ukupno1 > sestDonja && ukupno3 > sestDonja) || (ukupno3 < sestDonja && ukupno1 > sestDonja && ukupno2 > sestDonja))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.");
      if ((ukupno1 >= sestDonja && ukupno1 <= sestGornja) && (ukupno2 >= sestDonja && ukupno2 <= sestGornja) && (ukupno3 >= sestDonja && ukupno3 <= sestGornja))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ukupno1 >= sedamDonja && ukupno1 <= sedamGornja) && (ukupno2 >= sedamDonja && ukupno2 <= sedamGornja) && (ukupno3 >= sedamDonja && ukupno3 <= sedamGornja))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ukupno1 >= osamDonja && ukupno1 <= osamGornja) && (ukupno2 >= osamDonja && ukupno2 <= osamGornja) && (ukupno3 >= osamDonja && ukupno3 <= osamGornja))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ukupno1 >= devetDonja && ukupno1 <= devetGornja) && (ukupno2 >= devetDonja && ukupno2 <= devetGornja) && (ukupno3 >= devetDonja && ukupno3 <= devetGornja))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ukupno1 >= desetDonja && ukupno1 <= desetGornja) && (ukupno2 >= desetDonja && ukupno2 <= desetGornja) && (ukupno3 >= desetDonja && ukupno3 <= desetGornja))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (((ukupno1 >= sestDonja && ukupno1 <= sestGornja) && ((ukupno2 >= sestDonja && ukupno2 <= sestGornja) || (ukupno3 >= sestDonja && ukupno3 <= sestGornja))) || ((ukupno2 >= sestDonja && ukupno2 <= sestGornja) && (ukupno3 >= sestDonja && ukupno3 <= sestGornja)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (((ukupno1 >= sedamDonja && ukupno1 <= sedamGornja) && ((ukupno2 >= sedamDonja && ukupno2 <= sedamGornja) || (ukupno3 >= sedamDonja && ukupno3 <= sedamGornja))) || ((ukupno2 >= sedamDonja && ukupno2 <= sedamGornja) && (ukupno3 >= sedamDonja && ukupno3 <= sedamGornja)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (((ukupno1 >= osamDonja && ukupno1 <= osamGornja) && ((ukupno2 >= osamDonja && ukupno2 <= osamGornja) || (ukupno3 >= osamDonja && ukupno3 <= osamGornja))) || ((ukupno2 >= osamDonja && ukupno2 <= osamGornja) && (ukupno3 >= osamDonja && ukupno3 <= osamGornja)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (((ukupno1 >= devetDonja && ukupno1 <= devetGornja) && ((ukupno2 >= devetDonja && ukupno2 <= devetGornja) || (ukupno3 >= devetDonja && ukupno3 <= devetGornja))) || ((ukupno2 >= devetDonja && ukupno2 <= devetGornja) && (ukupno3 >= devetDonja && ukupno3 <= devetGornja)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (((ukupno1 >= desetDonja && ukupno1 <= desetGornja) && ((ukupno2 >= desetDonja && ukupno2 <= desetGornja) || (ukupno3 >= desetDonja && ukupno3 <= desetGornja))) || ((ukupno2 >= desetDonja && ukupno2 <= desetGornja) && (ukupno3 >= desetDonja && ukupno3 < desetGornja)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }


   return(0);
}
