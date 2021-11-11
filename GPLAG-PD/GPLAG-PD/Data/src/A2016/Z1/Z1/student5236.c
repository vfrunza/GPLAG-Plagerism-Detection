#include <stdio.h>

int main()
{
   double ppT, dpT, pT, zT, ziT, ppB, dpB, pB, zB, ziB, ppM, dpM, pM, zM, ziM, uT, uB, uM, ocjena1, ocjena2, ocjena3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &ppT);
   if (ppT < 0 || ppT > 20)
   {
      printf("Neisprava broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &dpT);
      if (dpT < 0 || dpT > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &pT);
         if (pT < 0 || pT > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &zT);
            if (zT < 0 || zT > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &ziT);
               if (ziT < 0 || ziT > 40)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana:\n");
                  printf("I parcijalni ispit: ");
                  scanf("%lf", &ppB);
                  if (ppB < 0 || ppB > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &dpB);
                     if (dpB < 0 || dpB > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &pB);
                        if (pB < 0 || pB > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &zB);
                           if (zB < 0 || zB > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &ziB);
                              if (ziB < 0 || ziB > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu:\n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%lf", &ppM);
                                 if (ppM < 0 || ppM > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &dpM);
                                    if (dpM < 0 || dpM > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &pM);
                                       if (pM < 0 || pM > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &zM);
                                          if (zM < 0 || zM > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &ziM);
                                          } if (ziM < 0 || ziM > 40)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             uT = ppT + dpT + pT + zT + ziT;
                                             uB = ppB + dpB + pB + zB + ziB;
                                             uM = ppM + dpM + pM + zM + ziM;
                                             if (uT >= 55 && uT < 65)
                                             {
                                                ocjena1 = 6;
                                             }
                                             else if (uT >= 65 && uT < 75)
                                             {
                                                ocjena1 = 7;
                                             }
                                             else if (uT >= 75 && uT < 85)
                                             {
                                                ocjena1 = 8;
                                             }
                                             else if (uT >= 85 && uT < 92)
                                             {
                                                ocjena1 = 9;
                                             }
                                             else if (uT > 92 && uT <= 100)
                                             {
                                                ocjena1 = 10;
                                             }
                                             if (uB >= 55 && uB < 65)
                                             {
                                                ocjena2 = 6;
                                             }
                                             else if (uB >= 65 && uB < 75)
                                             {
                                                ocjena2 = 7;
                                             }
                                             else if (uB >= 75 && uB < 85)
                                             {
                                                ocjena2 = 8;
                                             }
                                             else if (uB >= 85 && uB < 92)
                                             {
                                                ocjena2 = 9;
                                             }
                                             else if (uB >= 92 && uB <= 100)
                                             {
                                                ocjena2 = 10;
                                             }
                                             if (uM >= 55 && uM < 65)
                                             {
                                                ocjena3 = 6;
                                             }
                                             else if (uM >= 65 && uM < 75)
                                             {
                                                ocjena3 = 7;
                                             }
                                             else if (uM >= 75 && uM < 85)
                                             {
                                                ocjena3 = 8;
                                             }
                                             else if (uM >= 85 && uM < 92)
                                             {
                                                ocjena3 = 9;
                                             }
                                             else if (uM >= 92 && uM <= 100)
                                             {
                                                ocjena3 = 10;
                                             }
                                             if (uB < 55 && uT < 55 && uM < 55)
                                             {
                                                printf("Nijedan student nije polozio.");
                                             }
                                             else if (uB > 55 && uT > 55 && uM > 55)
                                             {
                                                printf("Sva tri studenta su polozila.\n");
                                                if (ocjena1 == ocjena2 && ocjena1 == ocjena3 && ocjena2 == ocjena3)
                                                {
                                                   printf("Sva tri studenta imaju istu ocjenu.");
                                                }
                                                else if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
                                                {
                                                   printf("Svaki student ima razlicitu ocjenu.");
                                                }
                                                else
                                                {
                                                   printf("Dva od tri studenta imaju istu ocjenu.");
                                                }
                                             }
                                             else if (uT >= 55 && uB <= 55 && uM <= 55 || uT <= 55 && uM <= 55 && uB >= 55 || uT <= 55 && uB <= 55 && uM >= 55)
                                             {
                                                printf("Jedan student je polozio.");
                                             }
                                             else if (uT > 55 && uB > 55 && uM < 55 || uT < 55 && uB > 55 && uM > 55 || uM > 55 && uT > 55 || uB < 55)
                                             {
                                                printf("Dva studenta su polozila.");
                                             }
                                          }
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }

   return(0);
}
