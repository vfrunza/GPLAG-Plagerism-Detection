#include <stdio.h>
int main()
{
   double PI1t, PI2t, Pt, Zt, ZIt, PI1b, PI2b, Pb, Zb, ZIb, PI1m, PI2m, Pm, Zm, ZIm, UKt, UKb, UKm, Ot, Ob, Om;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PI1t);
   if (PI1t < 0 || PI1t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &PI2t);
   if (PI2t < 0 || PI2t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pt);
   if (Pt < 0 || Pt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zt);
   if (Zt < 0 || Zt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIt);
   if (ZIt < 0 || ZIt > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   UKt = PI1t + PI2t + Pt + Zt + ZIt; /*Tarikovi ukupni bodovi predstavljaju sumu bodova sa I parcijalnog ispita, II parcijalnog ispita, prisustva, zadace i zavrsnog ispita.*/
   if (UKt >= 55 && UKt < 65)
   {
      Ot = 6;
   }
   else if (UKt >= 65 && UKt < 75)
   {
      Ot = 7;
   }
   else if (UKt >= 75 && UKt < 85)
   {
      Ot = 8;
   }
   else if (UKt >= 85 && UKt < 92)
   {
      Ot = 9;
   }
   else if (UKt >= 92 && UKt <= 100)
   {
      Ot = 10;
   }
   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PI1b);
   if (PI1b < 0 || PI1b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &PI2b);
   if (PI2b < 0 || PI2b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pb);
   if (Pb < 0 || Pb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zb);
   if (Zb < 0 || Zb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIb);
   if (ZIb < 0 || ZIb > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   UKb = PI1b + PI2b + Pb + Zb + ZIb; /*Bojanovi ukupni bodovi predstavljaju sumu bodova sa I parcijalnog ispita, II parcijalnog ispita, prisustva, zadace i zavrsnog ispita.*/
   if (UKb >= 55 && UKb < 65)
   {
      Ob = 6;
   }
   else if (UKb >= 65 && UKb < 75)
   {
      Ob = 7;
   }
   else if (UKb >= 75 && UKb < 85)
   {
      Ob = 8;
   }
   else if (UKb >= 85 && UKb < 92)
   {
      Ob = 9;
   }
   else if (UKb >= 92 && UKb <= 100)
   {
      Ob = 10;
   }
   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PI1m);
   if (PI1m < 0 || PI1m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &PI2m);
   if (PI2m < 0 || PI2m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pm);
   if (Pm < 0 || Pm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zm);
   if (Zm < 0 || Zm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIm);
   if (ZIm < 0 || ZIm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   UKm = PI1m + PI2m + Pm + Zm + ZIm; /*Mirzini ukupni bodovi predstavljaju sumu bodova sa I parcijalnog ispita, II parcijalnog ispita, prisustva, zadace i zavrsnog ispita.*/
   if (UKm >= 55 && UKm < 65)
   {
      Om = 6;
   }
   else if (UKm >= 65 && UKm < 75)
   {
      Om = 7;
   }
   else if (UKm >= 75 && UKm < 85)
   {
      Om = 8;
   }
   else if (UKm >= 85 && UKm < 92)
   {
      Om = 9;
   }
   else if (UKm >= 92 && UKm <= 100)
   {
      Om = 10;
   }
   if (UKt < 55 && UKb < 55 && UKm < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((UKt >= 55 && UKb < 55 && UKm < 55) || (UKt < 55 && UKb >= 55 && UKm < 55) || (UKt < 55 && UKb < 55 && UKm >= 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((UKt >= 55 && UKb >= 55 && UKm < 55) || (UKt >= 55 && UKb < 55 && UKm >= 55) || (UKt < 55 && UKb >= 55 && UKm >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   if (UKt >= 55 && UKb >= 55 && UKm >= 55)
   {
      printf("Sva tri studenta su polozila.");
      if (Ot == Ob && Ob == Om)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((Ot == Ob && Ob != Om) || (Ot == Om && Om != Ob) || (Ob == Om && Om != Ot))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (Ot != Ob && Ob != Om)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
