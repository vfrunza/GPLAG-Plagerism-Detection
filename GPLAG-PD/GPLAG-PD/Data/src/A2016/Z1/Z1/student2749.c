#include <stdio.h>
#include <math.h>
#define epsilon    0.0001
int main()
{
   double prolaz = 55;
   double a, b, c;     /*prve parcijale za svu trojicu*/
   double a1, b1, c1;  /*druge parcijale za svu trojicu*/
   double a2, b2, c2;  /*zavrsni za svu trojicu*/
   double z1, z2, z3;  /*zadace za svu trojicu*/
   double p1, p2, p3;  /*prisustva za svu trojicu*/
   double o1, o2, o3;  /*zbir bodova za ocjene za svu trojicu*/
   int    brojac_studenata = 0;
   int    brojac_ocjena = 0;
   int    tarik, bojan, mirza;

   tarik = 0;
   bojan = 0;
   mirza = 0;
   /*tarik*/
   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%lf", &a);
   if ((a < 0) || (a > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &a1);
   if ((a1 < 0) || (a1 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p1);
   if ((p1 < 0) || (p1 > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z1);
   if ((z1 < 0) || (z1 > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &a2);
   if ((a2 < 0) || (a2 > 40))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   /*bojan*/
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &b);
   if ((b < 0) || (b > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b1);
   if ((b1 < 0) || (b1 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p2);
   if ((p2 < 0) || (p2 > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z2);
   if ((z2 < 0) || (z2 > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &b2);
   if ((b2 < 0) || (b2 > 40))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   /*Mirza*/
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &c);
   if ((c < 0) || (c > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &c1);
   if ((c1 < 0) || (c1 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if ((p3 < 0) || (p3 > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z3);
   if ((z3 < 0) || (z3 > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &c2);
   if ((c2 < 0) || (c2 > 40))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   /*idemo*/
   o1 = a + a1 + a2 + p1 + z1;
   o2 = b + b1 + b2 + p2 + z2;
   o3 = c + c1 + c2 + p3 + z3;
   if ((o1 < prolaz) && (o2 < prolaz) && (o3 < prolaz))
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   else if (o1 >= prolaz && o2 >= prolaz && o3 >= prolaz)
   {
      brojac_studenata = 3;
   }
   else if (o1 >= prolaz && o2 >= prolaz && o3 < prolaz)
   {
      brojac_studenata = 2;
   }
   else if (o1 >= prolaz && o2 < prolaz && o3 >= prolaz)
   {
      brojac_studenata = 2;
   }
   else if (o1 >= prolaz && o2 < prolaz && o3 < prolaz)
   {
      brojac_studenata = 1;
   }
   else if (o1 < prolaz && o2 >= prolaz && o3 >= prolaz)
   {
      brojac_studenata = 2;
   }
   else if (o1 < prolaz && o2 >= prolaz && o3 < prolaz)
   {
      brojac_studenata = 1;
   }
   else if (o1 < prolaz && o2 < prolaz && o3 >= prolaz)
   {
      brojac_studenata = 1;
   }
   /*tarik ocjena*/
   if ((o1 >= prolaz) && (o1 <= 65.75))
   {
      tarik = 6;
   }
   else if ((o1 > 65.75) && (o1 <= 75.85))
   {
      tarik = 7;
   }
   else if ((o1 > 75.85) && (o1 <= 85.92))
   {
      tarik = 8;
   }
   else if ((o1 > 85.92) && (o1 <= 95.00))
   {
      tarik = 9;
   }
   else if ((o1 > 95.00) && (o1 <= 100.00))
   {
      tarik = 10;
   }
   /*bojanojan ocjena*/
   if ((o2 >= prolaz) && (o2 <= 65.75))
   {
      bojan = 6;
   }
   else if ((o2 > 65.75) && (o2 <= 75.85))
   {
      bojan = 7;
   }
   else if ((o2 > 75.85) && (o2 <= 85.92))
   {
      bojan = 8;
   }
   else if ((o2 > 85.92) && (o2 <= 95.00))
   {
      bojan = 9;
   }
   else if ((o2 > 95.00) && (o2 <= 100.00))
   {
      bojan = 10;
   }
   /*mirza ocjena*/
   if ((o3 >= prolaz) && (o3 <= 65.75))
   {
      mirza = 6;
   }
   else if ((o3 > 65.75) && (o3 <= 75.85))
   {
      mirza = 7;
   }
   else if ((o3 > 75.85) && (o3 <= 85.92))
   {
      mirza = 8;
   }
   else if ((o3 > 85.92) && (o3 <= 95.00))
   {
      mirza = 9;
   }
   else if ((o3 > 95.00) && (o3 <= 100.00))
   {
      mirza = 10;
   }
   /*zbir isih ocjena*/
   if ((tarik == bojan) && (bojan == mirza))
   {
      brojac_ocjena = 0;
   }
   else if ((tarik == bojan) && (bojan != mirza))
   {
      brojac_ocjena = 2;
   }
   else if ((tarik != bojan) && (bojan != mirza))
   {
      brojac_ocjena = 3;
   }
   /*brojac studenata*/
   switch (brojac_studenata)
   {
   case 1:
      printf("Jedan student je polozio.\n");
      break;

   case 2:
      printf("Dva studenta su polozila.\n");
      break;

   case 3:
      printf("Sva tri studenta su polozila.\n");
      break;
   }
   /*brojac ocjena*/
   if (brojac_studenata == 3)
   {
      switch (brojac_ocjena)
      {
      case 0:
         printf("Sva tri studenta imaju istu ocjenu.\n");
         break;

      case 2:
         printf("Dva od tri studenta imaju istu ocjenu.\n");
         break;

      case 3:
         printf("Svaki student ima razlicitu ocjenu.\n");
         break;

      default:
         printf("brojac ocjena na radi\n");
      }
   }
   return(0);
}
