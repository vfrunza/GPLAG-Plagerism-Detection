#include <stdio.h>
#include <math.h>
#define EPSILON    0.001

int main()
{
   double tpp, tdp, tp, tz, tzi;
   double bpp, bdp, bp, bz, bzi;
   double mpp, mdp, mp, mz, mzi;
   double OT, OM, OB;
   int    T, M, B;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &tpp); if (tpp < 0 || tpp > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &tdp); if (tdp < 0 || tdp > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &tp); if (tp < 0 || tp > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &tz); if (tz < 0 || tz > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &tzi); if (tzi < 0 || tzi > 40)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana: ");
                  printf("\nI parcijalni ispit: ");
                  scanf("%lf", &bpp); if (bpp < 0 || bpp > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &bdp); if (bdp < 0 || bdp > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &bp); if (bp < 0 || bp > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &bz); if (bz < 0 || bz > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &bzi); if (bzi < 0 || bzi > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: ");
                                 printf("\nI parcijalni ispit: ");
                                 scanf("%lf", &mpp); if (mpp < 0 || mpp > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &mdp); if (mdp < 0 || mdp > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &mp); if (mp < 0 || mp > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &mz); if (mz < 0 || mz > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &mzi); if (mzi < 0 || mzi > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                OT = tpp + tdp + tp + tz + tzi;
                                                OM = mpp + mdp + mp + mz + mzi;
                                                OB = bpp + bdp + bp + bz + bzi;

                                                if (OT < 55 && OM < 55 && OB < 55)
                                                {
                                                   printf("Nijedan student nije polozio.");
                                                }
                                                else if ((OT >= 55 && OM < 55 && OB < 55) || (OT < 55 && OM >= 55 && OB < 55) || (OT < 55 && OM < 55 && OB >= 55))
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                else if ((OT < 55 && OM >= 55 && OB >= 55) || (OT >= 55 && OM < 55 && OB >= 55) || (OT >= 55 && OM >= 55 && OB < 55))
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                else
                                                {
                                                   printf("Sva tri studenta su polozila.");

                                                   if (fabs(OT - 92) < EPSILON || OT > 92)
                                                   {
                                                      T = (OT + 8) / 10;
                                                   }

                                                   else
                                                   {
                                                      T = (OT + 5) / 10;
                                                   }

                                                   if (fabs(OB - 92) < EPSILON || OB > 92)
                                                   {
                                                      B = (OB + 8) / 10;
                                                   }
                                                   else
                                                   {
                                                      B = (OB + 5) / 10;
                                                   }

                                                   if (fabs(OM - 90) < EPSILON || OM > 92)
                                                   {
                                                      M = (OM + 8) / 10;
                                                   }
                                                   else
                                                   {
                                                      M = (OM + 5) / 10;
                                                   }

                                                   if (T == B && B != M)
                                                   {
                                                      printf("\nDva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   else if (T == B && B == M)
                                                   {
                                                      printf("\nSva tri studenta imaju istu ocjenu.");
                                                   }
                                                   else
                                                   {
                                                      printf("\nSvaki student ima razlicitu ocjenu.");
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
   }
   return(0);
}
