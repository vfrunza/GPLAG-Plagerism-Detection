#include <stdio.h>

int main()
{
   double Ipt, Ipb, Ipm, IIpt, IIpb, IIpm, Pt, Pb, Pm, Zt, Zb, Zm, Zst, Zsb, Zsm;
   double Ut, Ub, Um;
   int    Ot, Ob, Om, br = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Ipt);
   if (Ipt < 0 || Ipt > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpt);
   if (IIpt < 0 || IIpt > 20)
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
   scanf("%lf", &Zst);
   if (Zst < 0 || Zst > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Ipb);
   if (Ipb < 0 || Ipb > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpb);
   if (IIpb < 0 || IIpb > 20)
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
   scanf("%lf", &Zsb);
   if (Zsb < 0 || Zsb > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Ipm);
   if (Ipm < 0 || Ipm > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpm);
   if (IIpm < 0 || IIpm > 20)
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
   scanf("%lf", &Zsm);
   if (Zsm < 0 || Zsm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   Ut = Ipt + IIpt + Pt + Zt + Zst;
   Ub = Ipb + IIpb + Pb + Zb + Zsb;
   Um = Ipm + IIpm + Pm + Zm + Zsm;

   if (Ut < 55)
   {
      Ot = 5;
   }
   else if (Ut >= 55 && Ut < 65)
   {
      Ot = 6;
   }
   else if (Ut >= 65 && Ut < 75)
   {
      Ot = 7;
   }
   else if (Ut >= 75 && Ut < 85)
   {
      Ot = 8;
   }
   else if (Ut >= 85 && Ut < 92)
   {
      Ot = 9;
   }
   else if (Ut >= 92 && Ut < 100)
   {
      Ot = 10;
   }

   if (Ub < 55)
   {
      Ob = 5;
   }
   else if (Ub >= 55 && Ub < 65)
   {
      Ob = 6;
   }
   else if (Ub >= 65 && Ub < 75)
   {
      Ob = 7;
   }
   else if (Ub >= 75 && Ub < 85)
   {
      Ob = 8;
   }
   else if (Ub >= 85 && Ub < 92)
   {
      Ob = 9;
   }
   else if (Ub >= 92 && Ub < 100)
   {
      Ob = 10;
   }

   if (Um < 55)
   {
      Om = 5;
   }
   else if (Um >= 55 && Um < 65)
   {
      Om = 6;
   }
   else if (Um >= 65 && Um < 75)
   {
      Om = 7;
   }
   else if (Um >= 75 && Um < 85)
   {
      Om = 8;
   }
   else if (Um >= 85 && Um < 92)
   {
      Om = 9;
   }
   else if (Um >= 92 && Um < 100)
   {
      Om = 10;
   }

   if (Ut >= 55)
   {
      br++;
   }
   if (Ub >= 55)
   {
      br++;
   }
   if (Um >= 55)
   {
      br++;
   }


   if (br == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (br == 1)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (br == 2)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
   }


   if (br == 3)
   {
      if (Ot == Ob && Ot == Om)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (Ot == Ob && Ot != Om)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (Ot == Om && Ot != Ob)
      {
         printf("Dva od tri studenta imaju istu ocjenu");
      }
      else if (Ob == Om && Ob != Ot)
      {
         printf("Dva od tri studenta imaju istu ocjenu");
      }
      else if (Ot != Ob && Ot != Om && Om != Ob)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }



   return(0);
}
