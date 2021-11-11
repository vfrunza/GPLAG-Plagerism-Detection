#include <stdio.h>
#include <math.h>

int main()
{
   float       prist, prvit, drugit, zadacat, zavrst, prisb, prvib, drugib, zadacab, zavrsb, prism, prvim, drugim, zadacam, zavrsm;
   long double ukupan_broj_bodova_tarik, ukupan_broj_bodova_mirza, ukupan_broj_bodova_bojan;
   int         ocjena_mirza, ocjena_bojan, ocjena_tarik;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvit);
   if (prvit < 0 || prvit > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugit);
   if (drugit < 0 || drugit > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prist);
   if (prist < 0 || prist > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadacat);
   if (zadacat < 0 || zadacat > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrst);
   if (zavrst < 0 || zavrst > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvib);
   if (prvib < 0 || prvib > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugib);
   if (drugib < 0 || drugib > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisb);
   if (prisb < 0 || prisb > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadacab);
   if (zadacab > 10 || zadacab < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsb);
   if (zavrsb < 0 || zavrsb > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvim);
   if (prvim < 0 || prvim > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugim);
   if (drugim < 0 || drugim > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prism);
   if (prism < 0 || prism > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadacam);
   if (zadacam < 0 || zadacam > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsm);
   if (zavrsm < 0 || zavrsm > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   ukupan_broj_bodova_tarik = prvit + drugit + zadacat + prist + zavrst;
   ukupan_broj_bodova_bojan = prvib + drugib + zadacab + prisb + zavrsb;
   ukupan_broj_bodova_mirza = prvim + drugim + zadacam + prism + zavrsm;


   if (ukupan_broj_bodova_tarik < 55 && ukupan_broj_bodova_tarik > 54.999)
   {
      if (fabs(55 - ukupan_broj_bodova_tarik) < 0.00009)
      {
         ukupan_broj_bodova_tarik = 55;
      }
   }



   if (ukupan_broj_bodova_tarik < 65 && ukupan_broj_bodova_tarik > 64.999)
   {
      if (fabs(65 - ukupan_broj_bodova_tarik) < 0.00009)
      {
         ukupan_broj_bodova_tarik = 65;
      }
   }

   if (ukupan_broj_bodova_tarik < 75 && ukupan_broj_bodova_tarik > 74.999)
   {
      if (fabs(75 - ukupan_broj_bodova_tarik) < 0.00009)
      {
         ukupan_broj_bodova_tarik = 75;
      }
   }

   if (ukupan_broj_bodova_tarik < 85 && ukupan_broj_bodova_tarik > 84.999)
   {
      if (fabs(85 - ukupan_broj_bodova_tarik) < 0.00009)
      {
         ukupan_broj_bodova_tarik = 85;
      }
   }

   if (ukupan_broj_bodova_tarik < 95 && ukupan_broj_bodova_tarik > 94.999)
   {
      if (fabs(95 - ukupan_broj_bodova_tarik) < 0.00009)
      {
         ukupan_broj_bodova_tarik = 95;
      }
   }



   if (ukupan_broj_bodova_bojan < 55 && ukupan_broj_bodova_bojan > 54.999)
   {
      if (fabs(55 - ukupan_broj_bodova_bojan) < 0.00009)
      {
         ukupan_broj_bodova_bojan = 55;
      }
   }



   if (ukupan_broj_bodova_bojan < 65 && ukupan_broj_bodova_bojan > 64.999)
   {
      if (fabs(65 - ukupan_broj_bodova_bojan) < 0.00009)
      {
         ukupan_broj_bodova_bojan = 65;
      }
   }

   if (ukupan_broj_bodova_bojan < 75 && ukupan_broj_bodova_bojan > 74.999)
   {
      if (fabs(75 - ukupan_broj_bodova_bojan) < 0.00009)
      {
         ukupan_broj_bodova_bojan = 75;
      }
   }

   if (ukupan_broj_bodova_bojan < 85 && ukupan_broj_bodova_bojan > 84.999)
   {
      if (fabs(85 - ukupan_broj_bodova_bojan) < 0.00009)
      {
         ukupan_broj_bodova_bojan = 85;
      }
   }

   if (ukupan_broj_bodova_bojan < 95 && ukupan_broj_bodova_bojan > 94.999)
   {
      if (fabs(95 - ukupan_broj_bodova_bojan) < 0.00009)
      {
         ukupan_broj_bodova_bojan = 95;
      }
   }



   if (ukupan_broj_bodova_mirza < 55 && ukupan_broj_bodova_mirza > 54.999)
   {
      if (fabs(55 - ukupan_broj_bodova_mirza) < 0.00009)
      {
         ukupan_broj_bodova_mirza = 55;
      }
   }



   if (ukupan_broj_bodova_mirza < 65 && ukupan_broj_bodova_mirza > 64.999)
   {
      if (fabs(65 - ukupan_broj_bodova_mirza) < 0.00009)
      {
         ukupan_broj_bodova_mirza = 65;
      }
   }

   if (ukupan_broj_bodova_mirza < 75 && ukupan_broj_bodova_mirza > 74.999)
   {
      if (fabs(75 - ukupan_broj_bodova_mirza) < 0.00009)
      {
         ukupan_broj_bodova_mirza = 75;
      }
   }

   if (ukupan_broj_bodova_mirza < 85 && ukupan_broj_bodova_mirza > 84.999)
   {
      if (fabs(85 - ukupan_broj_bodova_mirza) < 0.00009)
      {
         ukupan_broj_bodova_mirza = 85;
      }
   }

   if (ukupan_broj_bodova_mirza < 95 && ukupan_broj_bodova_mirza > 94.999)
   {
      if (fabs(95 - ukupan_broj_bodova_mirza) < 0.00009)
      {
         ukupan_broj_bodova_mirza = 95;
      }
   }


   if (ukupan_broj_bodova_tarik < 55.0)
   {
      ocjena_tarik = 5;
   }
   if (ukupan_broj_bodova_tarik >= 55.0 && ukupan_broj_bodova_tarik < 65.0)
   {
      ocjena_tarik = 6;
   }
   if (ukupan_broj_bodova_tarik >= 65.0 && ukupan_broj_bodova_tarik < 75.0)
   {
      ocjena_tarik = 7;
   }
   if (ukupan_broj_bodova_tarik >= 75.0 && ukupan_broj_bodova_tarik < 85.0)
   {
      ocjena_tarik = 8;
   }
   if (ukupan_broj_bodova_tarik >= 85.0 && ukupan_broj_bodova_tarik < 95.0)
   {
      ocjena_tarik = 9;
   }
   if (ukupan_broj_bodova_tarik >= 95.0)
   {
      ocjena_tarik = 10;
   }



   if (ukupan_broj_bodova_mirza < 55.0)
   {
      ocjena_mirza = 5;
   }
   if (ukupan_broj_bodova_mirza >= 55.0 && ukupan_broj_bodova_mirza < 65.0)
   {
      ocjena_mirza = 6;
   }
   if (ukupan_broj_bodova_mirza >= 65.0 && ukupan_broj_bodova_mirza < 75.0)
   {
      ocjena_mirza = 7;
   }
   if (ukupan_broj_bodova_mirza >= 75.0 && ukupan_broj_bodova_mirza < 85.0)
   {
      ocjena_mirza = 8;
   }
   if (ukupan_broj_bodova_mirza >= 85.0 && ukupan_broj_bodova_mirza < 95.0)
   {
      ocjena_mirza = 9;
   }
   if (ukupan_broj_bodova_mirza >= 95.0)
   {
      ocjena_mirza = 10;
   }



   if (ukupan_broj_bodova_bojan < 55.0)
   {
      ocjena_bojan = 5;
   }
   if (ukupan_broj_bodova_bojan >= 55.0 && ukupan_broj_bodova_bojan < 65.0)
   {
      ocjena_bojan = 6;
   }
   if (ukupan_broj_bodova_bojan >= 65.0 && ukupan_broj_bodova_bojan < 75.0)
   {
      ocjena_bojan = 7;
   }
   if (ukupan_broj_bodova_bojan >= 75.0 && ukupan_broj_bodova_bojan < 85.0)
   {
      ocjena_bojan = 8;
   }
   if (ukupan_broj_bodova_bojan >= 85.0 && ukupan_broj_bodova_bojan < 95.0)
   {
      ocjena_bojan = 9;
   }
   if (ukupan_broj_bodova_bojan >= 95.0)
   {
      ocjena_bojan = 10;
   }

   if ((ocjena_bojan > 5 && ocjena_mirza == 5 && ocjena_tarik == 5) || (ocjena_tarik > 5 && ocjena_bojan == 5 && ocjena_mirza == 5) || (ocjena_mirza > 5 && ocjena_bojan == 5 && ocjena_tarik == 5))
   {
      printf("Jedan student je polozio.");
      return(0);
   }


   if (ocjena_tarik == 5 && ocjena_bojan == 5 && ocjena_mirza == 5)
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   if (ocjena_mirza > 5 && ocjena_bojan > 5 && ocjena_tarik > 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if (ocjena_tarik != ocjena_mirza && ocjena_tarik != ocjena_bojan && ocjena_bojan != ocjena_mirza)
      {
         printf("Svaki student ima razlicitu ocjenu.");
         return(0);
      }
      if ((ocjena_tarik == ocjena_mirza && ocjena_tarik != ocjena_bojan) || (ocjena_tarik == ocjena_bojan && ocjena_tarik != ocjena_mirza) || (ocjena_mirza == ocjena_bojan && ocjena_mirza != ocjena_tarik))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
         return(0);
      }
      else
      {
         printf("Sva tri studenta imaju istu ocjenu."); return(0);
      }
   }
   else
   {
      printf("Dva studenta su polozila.");
   }
   return(0);
}
