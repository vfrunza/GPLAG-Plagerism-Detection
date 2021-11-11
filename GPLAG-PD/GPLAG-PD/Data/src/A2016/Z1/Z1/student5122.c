#include <stdio.h>
#include <stdlib.h>

int main()
{
   float PrviParc1, PrviParc2, PrviParc3, DrugiParc1, DrugiParc2, DrugiParc3, Zadace1, Zadace2, Zadace3, Prisustvo1, Prisustvo2, Prisustvo3, Zavrsni1, Zavrsni2, Zavrsni3;
   float BrojBodova1, BrojBodova2, BrojBodova3;

   scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &PrviParc1, &DrugiParc1, &Prisustvo1, &Zadace1, &Zavrsni1, &PrviParc2, &DrugiParc2, &Prisustvo2, &Zadace2, &Zavrsni2, &PrviParc3, &DrugiParc3, &Prisustvo3, &Zadace3, &Zavrsni3);

   BrojBodova1 = (int)(((PrviParc1 + DrugiParc1 + Prisustvo1 + Zadace1 + Zavrsni1) * 100 + 0.5) / 100);
   BrojBodova2 = (int)(((PrviParc2 + DrugiParc2 + Prisustvo2 + Zadace2 + Zavrsni2) * 100 + 0.5) / 100);
   BrojBodova3 = (int)(((PrviParc3 + DrugiParc3 + Prisustvo3 + Zadace3 + Zavrsni3) * 100 + 0.5) / 100);

   if (PrviParc1 < 0 || PrviParc1 > 20)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: Neispravan broj bodova", PrviParc1); return(0);

      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (PrviParc2 < 0 || PrviParc2 > 20)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: Neispravan broj bodova", PrviParc2); return(0);

      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (PrviParc3 < 0 || PrviParc3 > 20)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: Neispravan broj bodova", PrviParc3); return(0);

      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (DrugiParc1 < 0 || DrugiParc1 > 20)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: Neispravan broj bodova", DrugiParc1); return(0);

      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (DrugiParc2 < 0 || DrugiParc2 > 20)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: Neispravan broj bodova", DrugiParc2); return(0);

      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (DrugiParc3 < 0 || DrugiParc3 > 20)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: Neispravan broj bodova", DrugiParc3); return(0);

      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Prisustvo1 < 0 || Prisustvo1 > 10)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: Neispravan broj bodova", Prisustvo1); return(0);

      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Prisustvo2 < 0 || Prisustvo2 > 10)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: Neispravan broj bodova", Prisustvo2); return(0);

      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Prisustvo3 < 0 || Prisustvo3 > 10)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: Neispravan broj bodova", Prisustvo3); return(0);

      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Zadace1 < 0 || Zadace1 > 10)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: Neispravan broj bodova", Zadace1); return(0);

      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Zadace2 < 0 || Zadace2 > 10)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: Neispravan broj bodova", Zadace2); return(0);

      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Zadace3 < 0 || Zadace3 > 10)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: Neispravan broj bodova", Zadace3); return(0);

      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Zavrsni1 < 0 || Zavrsni2 > 40)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: Neispravan broj bodova", Zavrsni1); return(0);

      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Zavrsni2 < 0 || Zavrsni2 > 40)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: Neispravan broj bodova", Zavrsni2); return(0);

      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
   }
   else if (Zavrsni3 < 0 || Zavrsni3 > 40)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: Neispravan broj bodova", Zavrsni3);
      return(0);
   }
   else if (BrojBodova1 < 55 && BrojBodova2 < 55 && BrojBodova3 < 55)
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
      printf("Nijedan student nije polozio.\n"); return(0);
   }
   else if ((BrojBodova1 > 55) && (BrojBodova2 > 55) && (BrojBodova3 > 55))
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
      printf("Sva tri studenta su polozila.\n");
   }
   else if (((BrojBodova1 >= 55 && BrojBodova2 < 55 && BrojBodova3 < 55) || (BrojBodova1 < 55 && BrojBodova2 >= 55 && BrojBodova3 < 55) || (BrojBodova1 < 55 && BrojBodova2 < 55 && BrojBodova3 >= 55)))
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", &Zavrsni3);
      printf("Jedan student je polozio.\n"); return(0);
   }
   else if ((BrojBodova1 < 55 && BrojBodova2 > 55 && BrojBodova3 > 55) || (BrojBodova1 > 55 && BrojBodova2 > 55 && BrojBodova3 < 55) || (BrojBodova1 > 55 && BrojBodova2 < 55 && BrojBodova3 > 55))
   {
      printf("Unesite bodove za Tarika:\n");
      printf("I parcijalni ispit: ", PrviParc1);
      printf("II parcijalni ispit: ", DrugiParc1);
      printf("Prisustvo: ", Prisustvo1);
      printf("Zadace: ", Zadace1);
      printf("Zavrsni ispit: ", Zavrsni1);
      printf("Unesite bodove za Bojana:\n");
      printf("I parcijalni ispit: ", PrviParc2);
      printf("II parcijalni ispit: ", DrugiParc2);
      printf("Prisustvo: ", Prisustvo2);
      printf("Zadace: ", Zadace2);
      printf("Zavrsni ispit: ", Zavrsni2);
      printf("Unesite bodove za Mirzu:\n");
      printf("I parcijalni ispit: ", PrviParc3);
      printf("II parcijalni ispit: ", DrugiParc3);
      printf("Prisustvo: ", Prisustvo3);
      printf("Zadace: ", Zadace3);
      printf("Zavrsni ispit: ", Zavrsni3);
      printf("Dva studenta su polozila.\n"); return(0);
   }
   if (((BrojBodova1 >= 55 && BrojBodova1 < 65) && (BrojBodova2 >= 55 && BrojBodova2 < 65) && (BrojBodova3 >= 55 && BrojBodova3 < 65)) || ((BrojBodova1 >= 65 && BrojBodova1 < 75) && (BrojBodova2 >= 65 && BrojBodova2 < 75) && (BrojBodova3 >= 65 && BrojBodova3 < 75)) || ((BrojBodova1 >= 75 && BrojBodova1 < 85) && (BrojBodova2 >= 75 && BrojBodova2 < 85) && (BrojBodova3 >= 75 && BrojBodova3 < 85)) || ((BrojBodova1 >= 85 && BrojBodova1 < 92) && (BrojBodova2 > 85 && BrojBodova2 < 92) && (BrojBodova3 >= 85 && BrojBodova3 < 92)) || ((BrojBodova1 >= 92 && BrojBodova1 <= 100) && (BrojBodova2 >= 92 && BrojBodova2 <= 100) && (BrojBodova3 >= 92 && BrojBodova3 <= 100)))
   {
      printf("Sva tri studenta imaju istu ocjenu.");
   }
   else if ((((BrojBodova1 >= 55 && BrojBodova1 < 65) && (BrojBodova2 >= 55 && BrojBodova2 < 65)) || ((BrojBodova1 >= 55 && BrojBodova1 < 65) && (BrojBodova3 >= 55 && BrojBodova3 < 65)) || ((BrojBodova3 >= 55 && BrojBodova3 < 65) && (BrojBodova2 >= 55 && BrojBodova2 < 65))) || (((BrojBodova1 >= 65 && BrojBodova1 < 75) && (BrojBodova2 >= 65 && BrojBodova2 < 75)) || ((BrojBodova1 >= 65 && BrojBodova1 < 75) && (BrojBodova3 >= 65 && BrojBodova3 < 75)) || ((BrojBodova3 >= 65 && BrojBodova3 < 75) && (BrojBodova2 >= 65 && BrojBodova2 < 75))) || (((BrojBodova1 >= 75 && BrojBodova1 < 85) && (BrojBodova2 >= 75 && BrojBodova2 < 85)) || ((BrojBodova1 >= 75 && BrojBodova1 < 85) && (BrojBodova3 >= 75 && BrojBodova3 < 85)) || ((BrojBodova3 >= 75 && BrojBodova3 < 85) && (BrojBodova2 >= 75 && BrojBodova2 < 85))) || (((BrojBodova1 >= 85 && BrojBodova1 < 92) && (BrojBodova2 >= 85 && BrojBodova2 < 92)) || ((BrojBodova1 >= 85 && BrojBodova1 < 92) && (BrojBodova3 >= 85 && BrojBodova3 < 92)) || ((BrojBodova3 >= 85 && BrojBodova3 < 92) && (BrojBodova2 >= 85 && BrojBodova2 < 92))) || (((BrojBodova1 >= 92 && BrojBodova1 < 100) && (BrojBodova2 >= 92 && BrojBodova2 < 100)) || ((BrojBodova1 >= 92 && BrojBodova1 < 100) && (BrojBodova3 >= 92 && BrojBodova3 < 100)) || ((BrojBodova3 >= 92 && BrojBodova3 < 100) && (BrojBodova2 >= 92 && BrojBodova2 < 100))))
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   else
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
   return(0);
}
