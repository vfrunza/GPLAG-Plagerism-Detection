#include <stdio.h>

int main()
{
   double Ipt, Ipb, Ipm, IIpt, IIpb, IIpm, prisustvot, prisustvob, prisustvom, dzt, dzb, dzm, zavrt, zavrb, zavrm, ut, ub, um, ot, ob, om;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &Ipt);
   if (Ipt < 0 || Ipt > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpt);
   if (IIpt < 0 || IIpt > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvot);
   if (prisustvot < 0 || prisustvot > 10)
   {
      printf("Nesipravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dzt);
   if (dzt < 0 || dzt > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrt);
   if (zavrt < 0 || zavrt > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ut = Ipt + IIpt + prisustvot + dzt + zavrt;
   if (ut < 55)
   {
      ot = 5;
   }
   if (ut >= 55 && ut < 65)
   {
      ot = 6;
   }
   if (ut >= 65 && ut < 75)
   {
      ot = 7;
   }
   if (ut >= 75 && ut < 85)
   {
      ot = 8;
   }
   if (ut >= 85 && ut < 92)
   {
      ot = 9;
   }
   if (ut >= 92 && ut <= 100)
   {
      ot = 10;
   }


   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &Ipb);
   if (Ipb < 0 || Ipb > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpb);
   if (IIpb < 0 || IIpb > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvob);
   if (prisustvob < 0 || prisustvob > 10)
   {
      printf("Nesipravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dzb);
   if (dzb < 0 || dzb > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrb);
   if (zavrb < 0 || zavrb > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ub = Ipb + IIpb + prisustvob + dzb + zavrb;
   if (ub < 55)
   {
      ob = 5;
   }
   if (ub >= 55 && ub < 65)
   {
      ob = 6;
   }
   if (ub >= 65 && ub < 75)
   {
      ob = 7;
   }
   if (ub >= 75 && ub < 85)
   {
      ob = 8;
   }
   if (ub >= 85 && ub < 92)
   {
      ob = 9;
   }
   if (ub >= 92 && ub <= 100)
   {
      ob = 10;
   }


   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &Ipm);
   if (Ipm < 0 || Ipm > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpm);
   if (IIpm < 0 || IIpm > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvom);
   if (prisustvom < 0 || prisustvom > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dzm);
   if (dzm < 0 || dzm > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrm);
   if (zavrm < 0 || zavrm > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   um = Ipm + IIpm + prisustvom + dzm + zavrm;
   if (um < 55)
   {
      om = 5;
   }
   if (um >= 55 && um < 65)
   {
      om = 6;
   }
   if (um >= 65 && um < 75)
   {
      om = 7;
   }
   if (um >= 75 && um < 85)
   {
      om = 8;
   }
   if (um >= 85 && um < 92)
   {
      om = 9;
   }
   if (um >= 92 && um <= 100)
   {
      om = 10;
   }

   if (ot >= 6 && ob >= 6 && om >= 6)
   {
      printf("Sva tri studenta su polozila.");

      if (ot == ob && ob == om)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      if (ot == ob && ob != om)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      if (ot != ob && ob == om)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      if (ot != ob && ob != om)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   if (ot < 6 && ob < 6 && om < 6)
   {
      printf("Nijedan student nije polozio.");
   }
   if (ot < 6 && ob < 6 && om >= 6)
   {
      printf("Jedan student je polozio.");
   }
   if (ot < 6 && ob >= 6 && om < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (ot >= 6 && ob < 6 && om < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (ot < 6 && ob >= 6 && om >= 6)
   {
      printf("Dva studenta su polozila.");
   }
   if (ot >= 6 && ob < 6 && om >= 6)
   {
      printf("Dva studenta su polozila.");
   }
   if (ot >= 6 && ob >= 6 && om < 6)
   {
      printf("Dva studenta su polozila.");
   }

   return(0);
}
