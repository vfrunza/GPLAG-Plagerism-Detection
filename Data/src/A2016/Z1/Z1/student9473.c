#include <stdio.h>
#include <math.h>
int Poredi(double x, double y)
{
   const double Eps = 0.0000000000000000000000000000000000000000001;

   return(fabs(x - y) <= Eps * (fabs(x) + fabs(y)));
}

int main()
{
   int    Ocjena1, Ocjena2, Ocjena3;
   double P11, P12, P13, P21, P22, P23, Prisustvo1, Prisustvo2, Prisustvo3, Zadace1, Zadace2, Zadace3, Zavrsni1, Zavrsni2, Zavrsni3, U1, U2, U3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P11);
   if ((P11 < 0 && !Poredi(P11, 0)) || (P11 > 20 && !Poredi(P11, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P21);
   if ((P21 < 0 && !Poredi(P21, 0)) || (P21 > 20 && !Poredi(P21, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo1);
   if ((Prisustvo1 < 0 && !Poredi(Prisustvo1, 0)) || (Prisustvo1 > 10 && !Poredi(Prisustvo1, 10)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zadace1);
   if ((Zadace1 < 0 && !Poredi(Zadace1, 0)) || (Zadace1 > 10 && !Poredi(Zadace1, 10)))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Zavrsni1);
   if ((Zavrsni1 < 0 && !Poredi(Zavrsni1, 0)) || (Zavrsni1 > 40 && !Poredi(Zavrsni1, 40)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   U1 = P11 + P21 + Prisustvo1 + Zadace1 + Zavrsni1;


   if ((U1 > 55 || Poredi(U1, 55)) && (U1 < 65 && !Poredi(U1, 65)))
   {
      Ocjena1 = 6;
   }
   else if ((U1 > 65 || Poredi(U1, 65)) && (U1 < 75 && !Poredi(U1, 75)))
   {
      Ocjena1 = 7;
   }
   else if ((U1 > 75 || Poredi(U1, 75)) && (U1 < 85 && !Poredi(U1, 85)))
   {
      Ocjena1 = 8;
   }
   else if ((U1 > 85 || Poredi(U1, 85)) && (U1 < 92 && !Poredi(U1, 92)))
   {
      Ocjena1 = 9;
   }
   else if ((U1 > 92 || Poredi(U1, 92)) && (U1 < 100 || Poredi(U1, 100)))
   {
      Ocjena1 = 10;
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P12);
   if ((P12 < 0 && !Poredi(P12, 0)) || (P12 > 20 && !Poredi(P12, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P22);
   if ((P22 < 0 && !Poredi(P22, 0)) || (P22 > 20 && !Poredi(P22, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo2);
   if ((Prisustvo2 < 0 && !Poredi(Prisustvo2, 0)) || (Prisustvo2 > 10 && !Poredi(Prisustvo2, 10)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zadace2);
   if ((Zadace2 < 0 && !Poredi(Zadace2, 0)) || (Zadace2 > 10 && !Poredi(Zadace2, 10)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Zavrsni2);
   if ((Zavrsni2 < 0 && !Poredi(Zavrsni2, 0)) || (Zavrsni2 > 40 && !Poredi(Zavrsni2, 40)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   U2 = P12 + P22 + Prisustvo2 + Zadace2 + Zavrsni2;


   if ((U2 > 55 || Poredi(U2, 55)) && (U2 < 65 && !Poredi(U2, 65)))
   {
      Ocjena2 = 6;
   }
   else if ((U2 > 65 || Poredi(U2, 65)) && (U2 < 75 && !Poredi(U2, 75)))
   {
      Ocjena2 = 7;
   }
   else if ((U2 > 75 || Poredi(U2, 75)) && (U2 < 85 && !Poredi(U2, 85)))
   {
      Ocjena2 = 8;
   }
   else if ((U2 > 85 || Poredi(U2, 85)) && (U2 < 92 && !Poredi(U2, 92)))
   {
      Ocjena2 = 9;
   }
   else if ((U2 > 92 || Poredi(U2, 92)) && (U2 < 100 || Poredi(U2, 100)))
   {
      Ocjena2 = 10;
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P13);
   if ((P13 < 0 && !Poredi(P13, 0)) || (P13 > 20 && !Poredi(P13, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P23);
   if ((P23 < 0 && !Poredi(P23, 0)) || (P23 > 20 && !Poredi(P23, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo3);
   if ((Prisustvo3 < 0 && !Poredi(Prisustvo3, 0)) || (Prisustvo3 > 10 && !Poredi(Prisustvo3, 10)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zadace3);
   if ((Zadace3 < 0 && !Poredi(Zadace3, 0)) || (Zadace3 > 10 && !Poredi(Zadace3, 10)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &Zavrsni3);
   if ((Zavrsni3 < 0 && !Poredi(Zavrsni3, 0)) || (Zavrsni3 > 40 && !Poredi(Zavrsni3, 20)))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   U3 = P13 + P23 + Prisustvo3 + Zadace3 + Zavrsni3;



   if ((U3 > 55 || Poredi(U3, 55)) && (U3 < 65 && !Poredi(U3, 65)))
   {
      Ocjena3 = 6;
   }
   else if ((U3 > 65 || Poredi(U3, 65)) && (U3 < 75 && !Poredi(U3, 75)))
   {
      Ocjena3 = 7;
   }
   else if ((U3 > 75 || Poredi(U3, 75)) && (U3 < 85 && !Poredi(U3, 85)))
   {
      Ocjena3 = 8;
   }
   else if ((U3 > 85 || Poredi(U3, 85)) && (U3 < 92 && !Poredi(U3, 92)))
   {
      Ocjena3 = 9;
   }
   else if ((U3 > 92 || Poredi(U3, 92)) && (U3 < 100 || Poredi(U3, 100)))
   {
      Ocjena3 = 10;
   }
   if ((U1 < 55 && !Poredi(U1, 55)) && (U2 < 55 && !Poredi(U2, 55)) && (U3 < 55 && !Poredi(U3, 55)))
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (((U1 > 55 || Poredi(U1, 55)) && (U2 < 55 && !Poredi(U2, 55)) && (U3 < 55 && !Poredi(U3, 55))) || ((U1 < 55 && !Poredi(U1, 55)) && (U2 > 55 || Poredi(U2, 55)) && (U3 < 55 && !Poredi(U3, 55))) || ((U1 < 55 && !Poredi(U1, 55)) && (U2 < 55 && !Poredi(U2, 55)) && (U3 > 55 || Poredi(U3, 55))))
   {
      printf("Jedan student je polozio.\n");
   }
   else if (((U1 > 55 || Poredi(U1, 55)) && (U2 > 55 || Poredi(U2, 55)) && (U3 < 55)) || ((U1 > 55 || Poredi(U1, 55)) && (U2 < 55) && (U3 > 55 || Poredi(U3, 55))) || ((U1 < 55) && (U2 > 55 || Poredi(U2, 55)) && (U3 > 55 || Poredi(U3, 55))))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((U1 > 55 || Poredi(U1, 55)) && (U2 > 55 || Poredi(U2, 55)) && (U3 > 55 || Poredi(U3, 55)))
   {
      printf("Sva tri studenta su polozila.\n");
   }
   if (((U1 > 55 || Poredi(U1, 55)) && (U2 > 55 || Poredi(U2, 55)) && (U3 > 55 || Poredi(U3, 55))) && ((Ocjena1 == Ocjena2) && (Ocjena1 == Ocjena3) && (Ocjena2 == Ocjena3)))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if (((U1 > 55 || Poredi(U1, 55)) && (U2 > 55 || Poredi(U2, 55)) && (U3 > 55 || Poredi(U3, 55))) && (((Ocjena1 == Ocjena2) && (Ocjena1 != Ocjena3) && (Ocjena2 != Ocjena3)) || ((Ocjena1 == Ocjena3) && (Ocjena1 != Ocjena2) && (Ocjena3 != Ocjena2)) || ((Ocjena2 == Ocjena3) && (Ocjena2 != Ocjena1) && (Ocjena3 != Ocjena1))))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (((U1 > 55 || Poredi(U1, 55)) && (U2 > 55 || Poredi(U2, 55)) && (U3 > 55 || Poredi(U3, 55))) && ((Ocjena1 != Ocjena2) && (Ocjena1 != Ocjena3) && (Ocjena2 != Ocjena3)))
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }
   return(0);
}
