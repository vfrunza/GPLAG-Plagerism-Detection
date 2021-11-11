#include <stdio.h>
#define B1    55.00
#define B2    65.00
#define B3    75.00
#define B4    85.00
#define B5    92.00
#define B6    100.00
int main()
{
   double TPI1, TPI2, TPR, TZ, TZI, BPI1, BPI2, BPR, BZ, BZI, MPI1, MPI2, MPR, MZ, MZI, SBT, SBM, SBB;
   int    OT, OB, OM;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &TPI1);
   if ((TPI1 < 0) || (TPI1 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &TPI2);
   }
   if ((TPI2 < 0) || (TPI2 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%lf", &TPR);
   }
   if ((TPR < 0) || (TPR > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zadace: ");
      scanf("%lf", &TZ);
   }
   if ((TZ < 0) || (TZ > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
      scanf("%lf", &TZI);
   }
   if ((TZI < 0) || (TZI > 40))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Unesite bodove za Bojana: ");
      printf("\nI parcijalni ispit: ");
      scanf("%lf", &BPI1);
   }
   if ((BPI1 < 0) || (BPI1 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &BPI2);
   }
   if ((BPI2 < 0) || (BPI2 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%lf", &BPR);
   }
   if ((BPR < 0) || (BPR > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zadace: ");
      scanf("%lf", &BZ);
   }
   if ((BZ < 0) || (BZ > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
      scanf("%lf", &BZI);
   }
   if ((BZI < 0) || (BZI > 40))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Unesite bodove za Mirzu: ");
      printf("\nI parcijalni ispit: ");
      scanf("%lf", &MPI1);
   }
   if ((MPI1 < 0) || (MPI1 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &MPI2);
   }
   if ((MPI2 < 0) || (MPI2 > 20))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%lf", &MPR);
   }
   if ((MPR < 0) || (MPR > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zadace: ");
      scanf("%lf", &MZ);
   }
   if ((MZ < 0) || (MZ > 10))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
      scanf("%lf", &MZI);
   }
   if ((MZI < 0) || (MZI > 40))
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   SBT = TPI1 + TPI2 + TPR + TZ + TZI;
   if (SBT < B1)
   {
      OT = 5;
   }
   else if (SBT >= B1 && SBT < B2)
   {
      OT = 6;
   }
   else if (SBT >= B2 && SBT < B3)
   {
      OT = 7;
   }
   else if (SBT >= B3 && SBT < B4)
   {
      OT = 8;
   }
   else if (SBT >= B4 && SBT < B5)
   {
      OT = 9;
   }
   else if (SBT >= B5 && SBT <= B6)
   {
      OT = 10;
   }

   SBB = BPI1 + BPI2 + BPR + BZ + BZI;
   if (SBB < B1)
   {
      OB = 5;
   }
   else if (SBB >= B1 && SBB < B2)
   {
      OB = 6;
   }
   else if (SBB >= B2 && SBB < B3)
   {
      OB = 7;
   }
   else if (SBB >= B3 && SBB < B4)
   {
      OB = 8;
   }
   else if (SBB >= B4 && SBB < B5)
   {
      OB = 9;
   }
   else if (SBB >= B5 && SBB >= B6)
   {
      OB = 10;
   }
   SBM = MPI1 + MPI2 + MPR + MZ + MZI;
   if (SBM < B1)
   {
      OM = 5;
   }
   else if (SBM >= B1 && SBM < B2)
   {
      OM = 6;
   }
   else if (SBM >= B2 && SBM < B3)
   {
      OM = 7;
   }
   else if (SBM >= B3 && SBM < B4)
   {
      OM = 8;
   }
   else if (SBM >= B4 && SBM < B5)
   {
      OM = 9;
   }
   else if (SBM >= B5 && SBM <= B6)
   {
      OM = 10;
   }
   if ((OT == 5) && (OB == 5) && (OM == 5))
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   else if (((OT == OB) && (OB == 5) && (OM != 5)) || ((OT == OM) && (OM == 5) && (OB != 5)) || ((OM == OB) && (OB == 5) && (OT != 5)))
   {
      printf("Jedan student je polozio.");
      return(0);
   }
   else if (((OB == 5) && (OT != OB) && (OM != OB)) || ((OT == 5) && (OB != OT) && (OM != OT)) || ((OM == 5) && (OT != OM) && (OB != OM)))
   {
      printf("Dva studenta su polozila.");
      return(0);
   }
   else if ((OB != 5) && (OT != 5) && (OM != 5))
   {
      printf("Sva tri studenta su polozila.");
   }
   if ((OT == OB && OB == OM && OM == 5) || (OT == OB && OB == OM && OM == 6) || (OT == OB && OB == OM && OM == 7) || (OT == OB && OB == OM && OM == 8) || (OT == OB && OB == OM && OM == 9) || (OT == OB && OB == OM && OM == 10))
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   if ((OT != OB && OB != OM && OT != OM))
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }
   else
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }

   return(0);
}
