#include <stdio.h>

int main()
{
   double parc1T, parc2T, pT, zT, ziT;
   double parc1B, parc2B, pB, zB, ziB;
   double parc1M, parc2M, pM, zM, ziM;
   double parc1, parc2, p, z, zi, T, B, M;
   int    OT, OB, OM;

   parc1 = 20;
   parc2 = 20;
   p     = 10;
   z     = 10;
   zi    = 40;
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &parc1T); if (parc1T < 0 || parc1T > parc1)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &parc2T); if (parc2T < 0 || parc2T > parc2)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &pT); if (pT < 0 || pT > p)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &zT); if (zT < 0 || zT > z)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &ziT); if (ziT < 0 || ziT > zi)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana:\n");
                  printf("I parcijalni ispit: ");
                  scanf("%lf", &parc1B); if (parc1B < 0 || parc1B > parc1)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &parc2B); if (parc2B < 0 || parc2B > parc2)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &pB);  if (pB < 0 || pB > p)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &zB); if (zB < 0 || zB > z)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &ziB); if (ziB < 0 || ziB > zi)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu:\n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%lf", &parc1M); if (parc1M < 0 || parc1M > parc1)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &parc2M); if (parc2M < 0 || parc2M > parc2)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &pM); if (pM < 0 || pM > p)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &zM); if (zM < 0 || zM > z)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &ziM); if (ziB < 0 || ziB > zi)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                T = parc1T + parc2T + pT + zT + ziT;
                                                B = parc1B + parc2B + pB + zB + ziB;
                                                M = parc1M + parc2M + pM + zM + ziM;
                                                if (T >= 55 && T < 65)
                                                {
                                                   OT = 6;
                                                }
                                                else if (T >= 65 && T < 75)
                                                {
                                                   OT = 7;
                                                }
                                                else if (T >= 75 && T < 85)
                                                {
                                                   OT = 8;
                                                }
                                                else if (T >= 85 && T < 92)
                                                {
                                                   OT = 9;
                                                }
                                                else if (T >= 92 && T <= 100)
                                                {
                                                   OT = 10;
                                                }
                                                if (B >= 55 && B < 65)
                                                {
                                                   OB = 6;
                                                }
                                                else if (B >= 65 && B < 75)
                                                {
                                                   OB = 7;
                                                }
                                                else if (B >= 75 && B < 85)
                                                {
                                                   OB = 8;
                                                }
                                                else if (B >= 85 && B < 92)
                                                {
                                                   OB = 9;
                                                }
                                                else if (B >= 92 && B <= 100)
                                                {
                                                   OB = 10;
                                                }
                                                if (M >= 55 && M < 65)
                                                {
                                                   OM = 6;
                                                }
                                                else if (M >= 65 && M < 75)
                                                {
                                                   OM = 7;
                                                }
                                                else if (M >= 75 && M < 85)
                                                {
                                                   OM = 8;
                                                }
                                                else if (M >= 85 && M < 92)
                                                {
                                                   OM = 9;
                                                }
                                                else if (M >= 92 && M <= 100)
                                                {
                                                   OM = 10;
                                                }
                                                if (T < 55 && B < 55 && M < 55)
                                                {
                                                   printf("Nijedan student nije polozio.");
                                                }
                                                else if (T >= 55 && B >= 55 && M >= 55)
                                                {
                                                   printf("Sva tri studenta su polozila.\n");
                                                   if ((OT - OB) == 0 && (OT - OM) == 0)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu.");
                                                   }
                                                   else if ((OT - OB) != 0 && (OT - OM) != 0 && (OB - OM) != 0)
                                                   {
                                                      printf("Svaki student ima razlicitu ocjenu.");
                                                   }
                                                   else
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                }
                                                else if ((T >= 55 && B < 55 && M < 55) || (T < 55 && B >= 55 && M < 55) || (T < 55 && B < 55 && M >= 55))
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                else
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
   }
   return(0);
}
