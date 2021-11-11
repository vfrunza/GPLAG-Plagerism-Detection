#include <stdio.h>

int main()
{
   double TarikP1, TarikP2, TarikZAD, TarikPRI, TarikZAV, TarikBOD, TarikOCJ;
   double BojanP1, BojanP2, BojanZAD, BojanPRI, BojanZAV, BojanBOD, BojanOCJ;
   double MirzaP1, MirzaP2, MirzaZAD, MirzaPRI, MirzaZAV, MirzaBOD, MirzaOCJ;

   double PAD;

   PAD = 0;

   //TarikUNOS i provjera

   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &TarikP1);
   if (TarikP1 < 0 || TarikP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }


   printf("II parcijalni ispit: ");
   scanf("%lf", &TarikP2);
   if (TarikP2 < 0 || TarikP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &TarikPRI);
   if (TarikPRI < 0 || TarikPRI > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &TarikZAD);
   if (TarikZAD < 0 || TarikZAD > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &TarikZAV);
   if (TarikZAV < 0 || TarikZAV > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   //BojanUNOS i porvjera

   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &BojanP1);
   if (BojanP1 < 0 || BojanP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &BojanP2);
   if (BojanP2 < 0 || BojanP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &BojanPRI);
   if (BojanPRI < 0 || BojanPRI > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &BojanZAD);
   if (BojanZAD < 0 || BojanZAD > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &BojanZAV);
   if (BojanZAV < 0 || BojanZAV > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   //MirzaUNOS i provjera

   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &MirzaP1);
   if (MirzaP1 < 0 || MirzaP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &MirzaP2);
   if (MirzaP2 < 0 || MirzaP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &MirzaPRI);
   if (MirzaPRI < 0 || MirzaPRI > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &MirzaZAD);
   if (MirzaZAD < 0 || MirzaZAD > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &MirzaZAV);
   if (MirzaZAV < 0 || MirzaZAV > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   //RacunBODOVI

   TarikBOD = TarikP1 + TarikP2 + TarikPRI + TarikZAD + TarikZAV;

   BojanBOD = BojanP1 + BojanP2 + BojanPRI + BojanZAD + BojanZAV;

   MirzaBOD = MirzaP1 + MirzaP2 + MirzaPRI + MirzaZAD + MirzaZAV;

   //ProlazBROJAC

   if (TarikBOD < 55)
   {
      PAD++;
   }
   if (BojanBOD < 55)
   {
      PAD++;
   }
   if (MirzaBOD < 55)
   {
      PAD++;
   }

   if (PAD == 0)
   {
      printf("Sva tri studenta su polozila.\n");

      //TarikOCJENA
      if (TarikBOD > 54 && TarikBOD < 65)
      {
         TarikOCJ = 6;
      }
      else if (TarikBOD > 64 && TarikBOD < 75)
      {
         TarikOCJ = 7;
      }
      if (TarikBOD > 74 && TarikBOD < 85)
      {
         TarikOCJ = 8;
      }
      if (TarikBOD > 84 && TarikBOD < 92)
      {
         TarikOCJ = 9;
      }
      if (TarikBOD > 91 && TarikBOD < 101)
      {
         TarikOCJ = 10;
      }

      //BojanOCJENA
      if (BojanBOD > 54 && BojanBOD < 65)
      {
         BojanOCJ = 6;
      }
      if (BojanBOD > 64 && BojanBOD < 75)
      {
         BojanOCJ = 7;
      }
      if (BojanBOD > 74 && BojanBOD < 85)
      {
         BojanOCJ = 8;
      }
      if (BojanBOD > 84 && BojanBOD < 92)
      {
         BojanOCJ = 9;
      }
      if (BojanBOD > 91 && BojanBOD < 101)
      {
         BojanOCJ = 10;
      }

      //MirzaOCJENA
      if (MirzaBOD > 54 && MirzaBOD < 65)
      {
         MirzaOCJ = 6;
      }
      if (MirzaBOD > 64 && MirzaBOD < 75)
      {
         MirzaOCJ = 7;
      }
      if (MirzaBOD > 74 && MirzaBOD < 85)
      {
         MirzaOCJ = 8;
      }
      if (MirzaBOD > 84 && MirzaBOD < 92)
      {
         MirzaOCJ = 9;
      }
      if (MirzaBOD > 91 && MirzaBOD < 101)
      {
         MirzaOCJ = 10;
      }

      //Broj jednakih/razlicitih ocjena

      if (TarikOCJ == BojanOCJ && BojanOCJ == MirzaOCJ)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
         return(0);
      }

      else if (TarikOCJ == BojanOCJ)
      {
         if (BojanOCJ != MirzaOCJ)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
            return(0);
         }
      }
      else if (TarikOCJ == MirzaOCJ)
      {
         if (MirzaOCJ != BojanOCJ)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
            return(0);
         }
      }
      else if (MirzaOCJ == BojanOCJ)
      {
         if (BojanOCJ != TarikOCJ)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
            return(0);
         }
      }
      else if (TarikOCJ != BojanOCJ)
      {
         if (BojanOCJ != MirzaOCJ)
         {
            printf("Svaki student ima razlicitu ocjenu.\n");
            return(0);
         }
      }
   }
   else if (PAD == 1)
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if (PAD == 2)
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   else if (PAD == 3)
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }

   return(0);
}
