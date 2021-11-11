#include <stdio.h>

int main()
{
   double IParcT, IIParcT, PrisustvoT, ZadacaT, IParcB, IIParcB, PrisustvoB, ZadacaB, IParcM, IIParcM, PrisustvoM, ZadacaM, BodoviT, BodoviB, BodoviM, ZavrsniT, ZavrsniB, ZavrsniM, OT, OB, OM, UO;

   printf("Unesite bodove za Tarika: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IParcT);
   if (IParcT < 0 || IParcT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &IIParcT);
   if (IIParcT < 0 || IIParcT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &PrisustvoT);
   if (PrisustvoT < 0 || PrisustvoT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &ZadacaT);
   if (ZadacaT < 0 || ZadacaT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZavrsniT);
   if (ZavrsniT < 0 || ZavrsniT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IParcB);
   if (IParcB < 0 || IParcB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &IIParcB);
   if (IIParcB < 0 || IIParcB > 20)
   {
      printf("Neispravan bodova bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &PrisustvoB);
   if (PrisustvoB < 0 || PrisustvoB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &ZadacaB);
   if (ZadacaB < 0 || ZadacaB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZavrsniB);
   if (ZavrsniB < 0 || ZavrsniB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IParcM);
   if (IParcM < 0 || IParcM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &IIParcM);
   if (IIParcM < 0 || IIParcM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &PrisustvoM);
   if (PrisustvoM < 0 || PrisustvoM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &ZadacaM);
   if (ZadacaM < 0 || ZadacaM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZavrsniM);
   if (ZavrsniM < 0 || ZavrsniM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   BodoviT = IParcT + IIParcT + PrisustvoT + ZadacaT + ZavrsniT;
   BodoviB = IParcB + IIParcB + PrisustvoB + ZadacaB + ZavrsniB;
   BodoviM = IParcM + IIParcM + PrisustvoM + ZadacaM + ZavrsniM;


   if (BodoviT >= 0 && BodoviT < 55)
   {
      OT = 5;
   }
   if (BodoviT >= 55 && BodoviT < 65)
   {
      OT = 6;
   }
   if (BodoviT >= 65 && BodoviT < 75)
   {
      OT = 7;
   }
   if (BodoviT >= 75 && BodoviT < 85)
   {
      OT = 8;
   }
   if (BodoviT >= 85 && BodoviT < 92)
   {
      OT = 9;
   }
   if (BodoviT >= 92 && BodoviT < 100)
   {
      OT = 10;
   }

   if (BodoviB >= 0 && BodoviB < 55)
   {
      OB = 5;
   }
   if (BodoviB >= 55 && BodoviB < 65)
   {
      OB = 6;
   }
   if (BodoviB >= 65 && BodoviB < 75)
   {
      OB = 7;
   }
   if (BodoviB >= 75 && BodoviB < 85)
   {
      OB = 8;
   }
   if (BodoviB >= 85 && BodoviB < 92)
   {
      OB = 9;
   }
   if (BodoviB >= 92 && BodoviB < 100)
   {
      OB = 10;
   }

   if (BodoviM >= 0 && BodoviM < 55)
   {
      OM = 5;
   }
   if (BodoviM >= 55 && BodoviM < 65)
   {
      OM = 6;
   }
   if (BodoviM >= 65 && BodoviM < 75)
   {
      OM = 7;
   }
   if (BodoviM >= 75 && BodoviM < 85)
   {
      OM = 8;
   }
   if (BodoviM >= 85 && BodoviM < 92)
   {
      OM = 9;
   }
   if (BodoviM >= 92 && BodoviM <= 100)
   {
      OM = 10;
   }

   if (OT == 5 && OB == 5 && OM == 5)
   {
      printf("Nijedan student nije polozio. \n");
   }
   else if (OT > 5 && OB > 5 && OM > 5)
   {
      printf("Sva tri studenta su polozila. \n");

      if (OT == OB && OB == OM)
      {
         printf("Sva tri studenta imaju istu ocjenu. \n");
      }
      else if (OT != OB && OB != OM && OT != OM)
      {
         printf("Svaki student ima razlicitu ocjenu. \n");
      }

      else
      {
         printf("Dva od tri studenta imaju istu ocjenu. \n");
      }
   }

   else if ((OT > 5 && OT <= 10 && OB > 5 && OB <= 10) || (OB > 5 && OB <= 10 && OM > 5 && OM <= 10) || (OT > 5 && OT <= 10 && OM > 5 && OM <= 10))
   {
      printf("Dva studenta su polozila. \n");
   }
   else if ((OT > 5 && OT <= 10) || (OB > 5 && OB <= 10) || (OM > 5 && OM <= 10))
   {
      printf("Jedan student je polozio. \n");
   }


   return(0);
}
