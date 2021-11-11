#include <stdio.h>

int main()
{
   float tprvipi = 0, tdrugipi = 0, tzadaca = 0, tprisustvo = 0, bprvipi = 0, bdrugipi = 0, bzadaca = 0, bprisustvo = 0,
         mprvipi = 0, mdrugipi = 0, mzadaca = 0, mprisustvo = 0, tarik = 0, bojan = 0, mirza = 0, tzavrsni = 0, bzavrsni = 0, mzavrsni = 0;

   /*Bodovi tarik*/
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &tprvipi);
   if (tprvipi < 0 || tprvipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("II parcijalni ispit: ");
   scanf("%f", &tdrugipi);
   if (tdrugipi < 0 || tdrugipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Prisustvo: ");
   scanf("%f", &tprisustvo);
   if (tprisustvo < 0 || tprisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Zadace: ");
   scanf("%f", &tzadaca);
   if (tzadaca < 0 || tzadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Zavrsni ispit: ");
   scanf("%f", &tzavrsni);
   if (tzavrsni < 0 || tzavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   tarik = tprvipi + tdrugipi + tprisustvo + tzavrsni + tzadaca;

   /**bodovi bojan*/
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bprvipi);
   if (bprvipi < 0 || bprvipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("II parcijalni ispit: ");
   scanf("%f", &bdrugipi);
   if (bdrugipi < 0 || bdrugipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Prisustvo: ");
   scanf("%f", &bprisustvo);
   if (bprisustvo < 0 || bprisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Zadace: ");
   scanf("%f", &bzadaca);
   if (bzadaca < 0 || bzadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Zavrsni ispit: ");
   scanf("%f", &bzavrsni);
   if (bzavrsni < 0 || bzavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   bojan = bprisustvo + bprvipi + bdrugipi + bzavrsni + bzadaca;

   /*bodovi mirza*/
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &mprvipi);
   if (mprvipi < 0 || mprvipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("II parcijalni ispit: ");
   scanf("%f", &mdrugipi);
   if (mdrugipi < 0 || mdrugipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Prisustvo: ");
   scanf("%f", &mprisustvo);
   if (mprisustvo < 0 || mprisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Zadace: ");
   scanf("%f", &mzadaca);
   if (mzadaca < 0 || mzadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   printf("Zavrsni ispit: ");
   scanf("%f", &mzavrsni);
   if (mzavrsni < 0 || mzavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ;
   mirza = mprvipi + mdrugipi + mprisustvo + mzadaca + mzavrsni;


   int mo, bo, to;

   if (mirza < 55)
   {
      mo = 5;
   }
   else if (mirza >= 55 && mirza < 65)
   {
      mo = 6;
   }
   else if (mirza >= 65 && mirza < 75)
   {
      mo = 7;
   }
   else if (mirza >= 75 && mirza < 85)
   {
      mo = 8;
   }
   else if (mirza >= 85 && mirza < 92)
   {
      mo = 9;
   }
   else if (mirza >= 92 && mirza <= 100)
   {
      mo = 10;
   }
   ;

   if (tarik < 55)
   {
      to = 5;
   }
   else if (tarik >= 55 && tarik < 65)
   {
      to = 6;
   }
   else if (tarik >= 65 && tarik < 75)
   {
      to = 7;
   }
   else if (tarik >= 75 && tarik < 85)
   {
      to = 8;
   }
   else if (tarik >= 85 && tarik < 92)
   {
      to = 9;
   }
   else if (tarik >= 92 && tarik <= 100)
   {
      to = 10;
   }
   ;

   if (bojan < 55)
   {
      bo = 5;
   }
   else if (bojan >= 55 && bojan < 65)
   {
      bo = 6;
   }
   else if (bojan >= 65 && bojan < 75)
   {
      bo = 7;
   }
   else if (bojan >= 75 && bojan < 85)
   {
      bo = 8;
   }
   else if (bojan >= 85 && bojan < 92)
   {
      bo = 9;
   }
   else if (bojan >= 92 && bojan <= 100)
   {
      bo = 10;
   }
   ;

   if (mo == 5 && to == 5 && bo == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   ;
   if ((mo == 5 && to == 5 && bo != 5) || (mo == 5 && bo == 5 && to != 5) || (to == 5 && bo == 5 && mo != 5))
   {
      printf("Jedan student je polozio.");
   }
   ;
   if ((to == 5 && bo != 5 && mo != 5) || (bo == 5 && to != 5 && mo != 5) || (mo == 5 && bo != 5 && to != 5))
   {
      printf("Dva studenta su polozila.");
   }
   if (bo != 5 && mo != 5 && to != 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (mo == bo && bo == to)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      ;
      if ((mo == bo && mo != to) || (mo == to && mo != bo) || (to == bo && to != mo))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      ;
      if (mo != bo && bo != to)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   ;

   /*
    *   do 55 bodova - student pao
    *   [55,65) bodova - ocjena 6
    *   [65,75) bodova - ocjena 7
    *   [75,85) bodova - ocjena 8
    *   [85,92) boda - ocjena 9
    *   [92,100] bodova - ocjena 10
    */
   return(0);
}
