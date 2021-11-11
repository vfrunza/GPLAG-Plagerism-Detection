#include <stdio.h>

int main()
{
   /*TARIK*/
   double PI1t, PI2t, PRt, Zt, ZIt, Ut, OCt;

   printf("Unesite bodove za Tarika:\n");
   scanf("%lf%lf%lf%lf%lf", &PI1t, &PI2t, &PRt, &Zt, &ZIt);
   Ut = PI1t + PI2t + PRt + Zt + ZIt;
   if (PI1t > 20 || PI1t < 0)
   {
      printf("I parcijalni ispit: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("I parcijalni ispit: ");
   }
   if (PI2t > 20 || PI2t < 0)
   {
      printf("II parcijalni ispit: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   if (PRt > 10 || PRt < 0)
   {
      printf("Prisustvo: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   if (Zt > 10 || Zt < 0)
   {
      printf("Zadace: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   if (ZIt > 40 || ZIt < 0)
   {
      printf("Zavrsni ispit: Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }


   if (Ut >= 55 && Ut < 65)
   {
      OCt = 6;
   }
   else if (Ut >= 65 && Ut < 75)
   {
      OCt = 7;
   }
   else if (Ut >= 75 && Ut < 85)
   {
      OCt = 8;
   }
   else if (Ut >= 85 && Ut < 92)
   {
      OCt = 9;
   }
   else if (Ut >= 92 && Ut >= 100)
   {
      OCt = 10;
   }


   /*BOJAN*/

   double PI1b, PI2b, PRb, Zb, ZIb, Ub, OCb;

   printf("Unesite bodove za Bojana:\n");
   scanf("%lf%lf%lf%lf%lf", &PI1b, &PI2b, &PRb, &Zb, &ZIb);
   Ub = PI1b + PI2b + PRb + Zb + ZIb;
   if (PI1b > 20 || PI1b < 0)
   {
      printf("I parcijalni ispit: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("I parcijalni ispit: ");
   }
   if (PI2b > 20 || PI2b < 0)
   {
      printf("II parcijalni ispit: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   if (PRb > 10 || PRb < 0)
   {
      printf("Prisustvo: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   if (Zb > 10 || Zb < 0)
   {
      printf("Zadace: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   if (ZIb > 40 || ZIb < 0)
   {
      printf("Zavrsni ispit: Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   if (Ub >= 55 && Ub < 65)
   {
      OCb = 6;
   }
   else if (Ub >= 65 && Ub < 75)
   {
      OCb = 7;
   }
   else if (Ub >= 75 && Ub < 85)
   {
      OCb = 8;
   }
   else if (Ub >= 85 && Ub < 92)
   {
      OCt = 9;
   }
   else if (Ub >= 92 && Ub >= 100)
   {
      OCb = 10;
   }


   /*MIRZA*/


   double PI1m, PI2m, PRm, Zm, ZIm, Um, OCm;

   printf("Unesite bodove za Mirzu:\n");
   scanf("%lf%lf%lf%lf%lf", &PI1m, &PI2m, &PRm, &Zm, &ZIm);
   Um = PI1m + PI2m + PRm + Zm + ZIm;
   if (PI1m > 20 || PI1m < 0)
   {
      printf("I parcijalni ispit: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("I parcijalni ispit: ");
   }
   if (PI2m > 20 || PI2m < 0)
   {
      printf("II parcijalni ispit: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   if (PRm > 10 || PRm < 0)
   {
      printf("Prisustvo: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   if (Zm > 10 || Zm < 0)
   {
      printf("Zadace: Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   if (ZIm > 40 || ZIm < 0)
   {
      printf("Zavrsni ispit: Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   if (Um >= 55 && Um < 65)
   {
      OCm = 6;
   }
   else if (Um >= 65 && Um < 75)
   {
      OCm = 7;
   }
   else if (Um >= 75 && Um < 85)
   {
      OCm = 8;
   }
   else if (Um >= 85 && Um < 92)
   {
      OCm = 9;
   }
   else if (Um >= 92 && Um >= 100)
   {
      OCm = 10;
   }

   if (Ut >= 55 && Um >= 55 && Ub >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if (Ut < 55. && Um < 55. && Ub < 55.)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((Ut < 55 && Um >= 55 && Ub >= 55) || (Um < 55 && Ub >= 55 && Ut >= 55) || (Ub < 55 && Ut >= 55 && Um >= 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((Ut < 55 && Um < 55 && Ub >= 55) || (Um < 55 && Ub < 55 && Ut >= 55) || (Ub < 55 && Ut < 55 && Um >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((Ut >= 55 && Um >= 55 && Ub >= 55) && (OCm == OCt && OCt == OCb))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if ((Ut >= 55 && Um >= 55 && Ub >= 55) && ((OCm == OCt && OCb != OCt) || (OCm == OCb && OCt != OCb) || (OCt == OCb && OCm != OCt)))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (Ut >= 55 && Um >= 55 && Ub >= 55)
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }



   return(0);
}
