#include <stdio.h>
#include <math.h>
#define EPSILON    0.0001
int main()
{
   double T1, T2, T3, T4, T5, T, B1, B2, B3, B4, B5, B, M1, M2, M3, M4, M5, M; int OCJM, OCJT, OCJB;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &T1); if (T1 < 0 || T1 > 20)
   {
      printf(" Neispravan broj bodova");
   }
   else
   {
      printf(" II parcijalni ispit:");
      scanf("%lf", &T2); if (T2 < 0 || T2 > 20)
      {
         printf(" Neispravan broj bodova");
      }
      else
      {
         printf(" Prisustvo:");
         scanf("%lf", &T3); if (T3 < 0 || T3 > 10)
         {
            printf(" Neispravan broj bodova");
         }
         else
         {
            printf(" Zadace:");
            scanf("%lf", &T4); if (T4 < 0 || T4 > 10)
            {
               printf(" Neispravan broj bodova");
            }
            else
            {
               printf(" Zavrsni ispit:");
               scanf("%lf", &T5); if (T5 < 0 || T5 > 40)
               {
                  printf(" Neispravan broj bodova");
               }
               else
               {
                  printf(" Unesite bodove za Bojana:\nI parcijalni ispit:");
                  scanf("%lf", &B1); if (B1 < 0 || B1 > 20)
                  {
                     printf(" Neispravan broj bodova");
                  }
                  else
                  {
                     printf(" II parcijalni ispit:");
                     scanf("%lf", &B2); if (B2 < 0 || B2 > 20)
                     {
                        printf(" Neispravan broj bodova");
                     }
                     else
                     {
                        printf(" Prisustvo:");
                        scanf("%lf", &B3); if (B3 < 0 || B3 > 10)
                        {
                           printf(" Neispravan broj bodova");
                        }
                        else
                        {
                           printf(" Zadace:");
                           scanf("%lf", &B4); if (B4 < 0 || B4 > 10)
                           {
                              printf(" Neispravan broj bodova");
                           }
                           else
                           {
                              printf(" Zavrsni ispit:");
                              scanf("%lf", &B5); if (B5 < 0 || B5 > 40)
                              {
                                 printf(" Neispravan broj bodova");
                              }
                              else
                              {
                                 printf(" Unesite bodove za Mirzu:\nI parcijalni ispit:");
                                 scanf("%lf", &M1); if (M1 < 0 || M1 > 20)
                                 {
                                    printf(" Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf(" II parcijalni ispit:");
                                    scanf("%lf", &M2); if (M2 < 0 || M2 > 20)
                                    {
                                       printf(" Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf(" Prisustvo:");
                                       scanf("%lf", &M3); if (M3 < 0 || M3 > 10)
                                       {
                                          printf(" Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf(" Zadace:");
                                          scanf("%lf", &M4); if (M4 < 0 || M4 > 10)
                                          {
                                             printf(" Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf(" Zavrsni ispit:");
                                             scanf("%lf", &M5);
                                             if (M5 < 0 || M5 > 40)
                                             {
                                                printf("Neispravno unesen broj bodova");

                                                return(0);
                                             }

                                             else
                                             {
                                                B = B1 + B2 + B3 + B4 + B5;
                                                M = M1 + M2 + M3 + M4 + M5;
                                                T = T1 + T2 + T3 + T4 + T5;

                                                if (M >= 55 && M < 65)
                                                {
                                                   OCJM = 6;
                                                }
                                                else if (M >= 65 && M < 75)
                                                {
                                                   OCJM = 7;
                                                }
                                                else if (M >= 75 && M < 85)
                                                {
                                                   OCJM = 8;
                                                }
                                                else if (M >= 85 && M < 92)
                                                {
                                                   OCJM = 9;
                                                }
                                                else if (M >= 92 && M < 100)
                                                {
                                                   OCJM = 10;
                                                }
                                                if (T >= 55 && T < 65)
                                                {
                                                   OCJT = 6;
                                                }
                                                else if (T >= 65 && T < 75)
                                                {
                                                   OCJT = 7;
                                                }
                                                else if (T >= 75 && T < 85)
                                                {
                                                   OCJT = 8;
                                                }
                                                else if (T >= 85 && T < 92)
                                                {
                                                   OCJT = 9;
                                                }
                                                else if (T >= 92 && T < 100)
                                                {
                                                   OCJT = 10;
                                                }
                                                if (B >= 55 && B < 65)
                                                {
                                                   OCJB = 6;
                                                }
                                                else if (B >= 65 && B < 75)
                                                {
                                                   OCJB = 7;
                                                }
                                                else if (B >= 75 && B < 85)
                                                {
                                                   OCJB = 8;
                                                }
                                                else if (B >= 85 && B < 92)
                                                {
                                                   OCJB = 9;
                                                }
                                                else if (B >= 92 && B < 100)
                                                {
                                                   OCJB = 10;
                                                }
                                             }
                                             if (M < 55 && B < 55 && T < 55)
                                             {
                                                printf(" Nijedan student nije polozio.");

                                                return(0);
                                             }
                                             if (fabs(B - 55) < EPSILON || (B - 55 > 0) && (T - 55 < 0) && (M - 55 < 0))


                                             {
                                                printf(" Jedan student je polozio.\n");
                                                return(0);
                                             }

                                             else if (fabs(M - 55) < EPSILON || (M - 55 > 0) && (B - 55 < 0) && (T - 55 < 0))
                                             {
                                                printf(" Jedan student je polozio.\n");

                                                return(0);
                                             }
                                             else if (fabs(T - 55) < EPSILON || (T - 55 > 0) && (B - 55 < 0) && (M - 55 < 0))
                                             {
                                                printf(" Jedan student je polozio.\n");

                                                return(0);
                                             }
                                             else if (fabs(B - 55) < EPSILON || (B - 55 > 0) && (fabs(T - 55) < EPSILON || (T - 55 > 0)) && (M - 55 < 0))
                                             {
                                                printf(" Dva studenta su polozila.\n");
                                                return(0);
                                             }
                                             else if (fabs(B - 55) < EPSILON || (B - 55 > 0) && (fabs(M - 55) < EPSILON || (M - 55 > 0)) && (T - 55 < 0))
                                             {
                                                printf(" Dva studenta su polozila.\n");

                                                return(0);
                                             }
                                             else if (fabs(M - 55) < EPSILON || (M - 55 > 0) && (fabs(T - 55) < EPSILON || (T - 55 > 0)) && (B - 55 < 0))
                                             {
                                                printf(" Dva studenta su polozila.\n");

                                                return(0);
                                             }
                                             else
                                             {
                                                printf(" Sva tri studenta su polozila.\n");
                                             }

                                             if (OCJM == OCJB && OCJM == OCJT && OCJB == OCJT)
                                             {
                                                printf("Sva tri studenta imaju istu ocjenu.");
                                             }
                                             else if ((OCJT - OCJB) != 0 && (OCJT - OCJM) != 0 && (OCJB - OCJM) != 0)
                                             {
                                                printf("Svaki student ima razlicitu ocjenu.");
                                             }
                                             else
                                             {
                                                printf("Dva od tri studenta imaju istu ocjenu.");
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
