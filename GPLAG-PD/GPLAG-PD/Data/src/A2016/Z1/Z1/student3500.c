#include <stdio.h>

int main()
{
   float Tarik_Ip, Tarik_IIp, Tarik_P, Tarik_Z, Tarik_U, Mirza_Ip, Mirza_IIp, Mirza_P, Mirza_Z, Mirza_U, Bojan_Ip, Bojan_IIp, Bojan_U, Bojan_Z, Bojan_P;
   int   bodoviM, bodoviB, bodoviT, ocjenaM, ocjenaB, ocjenaT;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Tarik_Ip);
   if ((Tarik_Ip < 0) || (Tarik_Ip > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Tarik_IIp);
   if ((Tarik_IIp < 0) || (Tarik_IIp > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Tarik_P);
   if ((Tarik_P < 0) || (Tarik_P > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Tarik_Z);
   if ((Tarik_Z < 0) || (Tarik_Z > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Tarik_U);
   if ((Tarik_U < 0) || (Tarik_U > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Bojan_Ip);
   if ((Bojan_Ip < 0) || (Bojan_Ip > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Bojan_IIp);
   if ((Bojan_IIp < 0) || (Bojan_IIp > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Bojan_P);
   if ((Bojan_P < 0) || (Bojan_P > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Bojan_Z);
   if ((Bojan_Z < 0) || (Bojan_Z > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Bojan_U);
   if ((Bojan_U < 0) || (Bojan_U > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Mirza_Ip);
   if ((Mirza_Ip < 0) || (Mirza_Ip > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Mirza_IIp);
   if ((Mirza_IIp < 0) || (Mirza_IIp > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Mirza_P);
   if ((Mirza_P < 0) || (Mirza_P > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Mirza_Z);
   if ((Mirza_Z < 0) || (Mirza_Z > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Mirza_U);
   if ((Mirza_U < 0) || (Mirza_U > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   bodoviM = (Mirza_U + Mirza_Z + Mirza_P + Mirza_IIp + Mirza_Ip) * 100;
   bodoviB = (Bojan_U + Bojan_Z + Bojan_P + Bojan_IIp + Bojan_Ip) * 100;
   bodoviT = (Tarik_U + Tarik_Z + Tarik_P + Tarik_IIp + Tarik_Ip) * 100;

   if (bodoviM < 5500)
   {
      ocjenaM = 5;
   }
   else if ((bodoviM >= 5500) && (bodoviM < 6500))
   {
      ocjenaM = 6;
   }
   else if ((bodoviM >= 6500) && (bodoviM < 7500))
   {
      ocjenaM = 7;
   }
   else if ((bodoviM >= 7500) && (bodoviM < 8500))
   {
      ocjenaM = 8;
   }
   else if ((bodoviM >= 8500) && (bodoviM < 9200))
   {
      ocjenaM = 9;
   }
   else if ((bodoviM >= 9200) && (bodoviM < 10000))
   {
      ocjenaM = 10;
   }

   if (bodoviB < 5500)
   {
      ocjenaB = 5;
   }
   else if ((bodoviB >= 5500) && (bodoviB < 6500))
   {
      ocjenaB = 6;
   }
   else if ((bodoviB >= 6500) && (bodoviB < 7500))
   {
      ocjenaB = 7;
   }
   else if ((bodoviB >= 7500) && (bodoviB < 8500))
   {
      ocjenaB = 8;
   }
   else if ((bodoviB >= 8500) && (bodoviB < 9200))
   {
      ocjenaB = 9;
   }
   else if ((bodoviB >= 9200) && (bodoviB < 10000))
   {
      ocjenaB = 10;
   }

   if (bodoviT < 5500)
   {
      ocjenaT = 5;
   }
   else if ((bodoviT >= 5500) && (bodoviT < 6500))
   {
      ocjenaT = 6;
   }
   else if ((bodoviT >= 6500) && (bodoviT < 7500))
   {
      ocjenaT = 7;
   }
   else if ((bodoviT >= 7500) && (bodoviT < 8500))
   {
      ocjenaT = 8;
   }
   else if ((bodoviT >= 8500) && (bodoviT < 9200))
   {
      ocjenaT = 9;
   }
   else if ((bodoviT >= 9200) && (bodoviT < 10000))
   {
      ocjenaT = 10;
   }

   if ((ocjenaT > 5) && (ocjenaB > 5) && (ocjenaM > 5))
   {
      printf("Sva tri studenta su polozila.\n");
      if ((ocjenaT == ocjenaB) && (ocjenaT == ocjenaM))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjenaT == ocjenaB) && (ocjenaT != ocjenaM) || ((ocjenaT == ocjenaM) && (ocjenaT != ocjenaB)) || (ocjenaB == ocjenaM) && (ocjenaB != ocjenaT))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if ((ocjenaT != ocjenaB) && (ocjenaT != ocjenaM))
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   else if ((ocjenaT == 5) && (ocjenaB == 5) && (ocjenaM == 5))
   {
      printf("Nijedan student nije polozio.");
   }
   else if (((ocjenaT > 5) && (ocjenaM == 5) && (ocjenaB == 5)) || ((ocjenaB > 5) && (ocjenaM == 5) && (ocjenaT == 5)) || ((ocjenaM > 5) && (ocjenaT == 5) && (ocjenaB == 5)))
   {
      printf("Jedan student je polozio.");
   }
   else if (((ocjenaT > 5) && (ocjenaM > 5) && (ocjenaB == 5)) || ((ocjenaB > 5) && (ocjenaM > 5) && (ocjenaT == 5)) || ((ocjenaB > 5) && (ocjenaT > 5) && (ocjenaM == 5)))
   {
      printf("Dva studenta su polozila.");
   }

   return(0);
}
