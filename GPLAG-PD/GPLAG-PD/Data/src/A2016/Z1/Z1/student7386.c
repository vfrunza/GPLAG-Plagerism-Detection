#include <stdio.h>

int main()
{
   printf("Zadaća 1, Zadatak 1");
   return(0);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
   int    Otarik, Obojan, Omirza;
   double PPtarik, PPbojan, PPmirza, DPtarik, DPbojan, DPmirza, Ztarik, Zbojan, Zmirza, Ptarik, Pbojan, Pmirza, ZAtarik, ZAbojan, ZAmirza, Tarik = 0, Mirza = 0, Bojan = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PPtarik);
   if (PPtarik > 20 || PPtarik < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPtarik);
   if (DPtarik > 20 || DPtarik < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Ptarik);
   if (Ptarik > 10 || Ptarik < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Ztarik);
   if (Ztarik > 10 || Ztarik < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZAtarik);
   if (ZAtarik > 40 || ZAtarik < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   if ((PPtarik <= 20 && PPtarik >= 0) && (DPtarik <= 20 && DPtarik >= 0) && (Ztarik <= 10 && Ztarik >= 0) && (Ptarik <= 10 && Ptarik >= 0) && (ZAtarik <= 40 && ZAtarik >= 0))
   {
      Tarik = PPtarik + DPtarik + Ztarik + Ptarik + ZAtarik;
      if (Tarik >= 55 && Tarik < 65)
      {
         Otarik = 6;
      }
      else if (Tarik >= 65 && Tarik < 75)
      {
         Otarik = 7;
      }
      else if (Tarik >= 75 && Tarik < 85)
      {
         Otarik = 8;
      }
      else if (Tarik >= 85 && Tarik < 92)
      {
         Otarik = 9;
      }
      else if (Tarik >= 92 && Tarik <= 100)
      {
         Otarik = 10;
      }
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PPbojan);
   if (PPbojan > 20 || PPbojan < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPbojan);
   if (DPbojan > 20 || DPbojan < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pbojan);
   if (Pbojan > 10 || Pbojan < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zbojan);
   if (Zbojan > 10 || Zbojan < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZAbojan);
   if (ZAbojan > 40 || ZAbojan < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   if (PPbojan <= 20 && PPbojan >= 0 && DPbojan <= 20 && DPbojan >= 0 && Zbojan <= 10 && Zbojan >= 0 && Pbojan <= 10 && Pbojan >= 0 && ZAbojan <= 40 && ZAbojan >= 0)
   {
      Bojan = PPbojan + DPbojan + Zbojan + Pbojan + ZAbojan;
      if (Bojan >= 55 && Bojan < 65)
      {
         Obojan = 6;
      }
      else if (Bojan >= 65 && Bojan < 75)
      {
         Obojan = 7;
      }
      else if (Bojan >= 75 && Bojan < 85)
      {
         Obojan = 8;
      }
      else if (Bojan >= 85 && Bojan < 92)
      {
         Obojan = 9;
      }
      else if (Bojan >= 92 && Bojan <= 100)
      {
         Obojan = 10;
      }
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PPmirza);
   if (PPmirza > 20 || PPmirza < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPmirza);
   if (DPmirza > 20 || DPmirza < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pmirza);
   if (Pmirza > 10 || Pmirza < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zmirza);
   if (Zmirza > 10 || Zmirza < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZAmirza);
   if (ZAmirza > 40 || ZAmirza < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   if (PPmirza <= 20 && PPmirza >= 0 && DPmirza <= 20 && DPmirza >= 0 && Zmirza <= 10 && Zmirza >= 0 && Pmirza <= 10 && Pmirza >= 0 && ZAmirza <= 40 && ZAmirza >= 0)
   {
      Mirza = PPmirza + DPmirza + Zmirza + Pmirza + ZAmirza;
      if (Mirza >= 55 && Mirza < 65)
      {
         Omirza = 6;
      }
      else if (Mirza >= 65 && Mirza < 75)
      {
         Omirza = 7;
      }
      else if (Mirza >= 75 && Mirza < 85)
      {
         Omirza = 8;
      }
      else if (Mirza >= 85 && Mirza < 92)
      {
         Omirza = 9;
      }
      else if (Mirza >= 92 && Mirza <= 100)
      {
         Omirza = 10;
      }
   }
   if (Tarik < 55 && Mirza < 55 && Bojan < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (Tarik >= 55 && Mirza < 55 && Bojan < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (Tarik < 55 && Mirza < 55 && Bojan >= 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (Tarik < 55 && Mirza >= 55 && Bojan < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (Tarik >= 55 && Mirza >= 55 && Bojan < 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (Tarik >= 55 && Mirza < 55 && Bojan >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (Tarik < 55 && Mirza >= 55 && Bojan >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (Tarik >= 55 && Mirza >= 55 && Bojan >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((Otarik == Omirza) && (Otarik == Obojan))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((Otarik == Omirza) && (Otarik != Obojan) || ((Otarik == Obojan) && (Otarik != Omirza)) || ((Omirza == Obojan) && (Omirza != Otarik)))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if ((Otarik != Omirza) && (Otarik != Obojan) && (Omirza != Obojan))
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
