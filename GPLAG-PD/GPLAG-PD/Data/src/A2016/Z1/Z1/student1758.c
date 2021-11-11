#include <stdio.h>
#include <math.h>
#define e    0.0001

int main()
{
   float parc1T, parc2T, prisT, zadT, zavT, parc1B, parc2B, prisB, zadB, zavB, parc1M, parc2M, prisM, zadM, zavM, zT, zB, zM;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &parc1T);
   if (parc1T < 0 || parc1T > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &parc2T);
      if (parc2T < 0 || parc2T > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%f", &prisT);
         if (prisT < 0 || prisT > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%f", &zadT);
            if (zadT < 0 || zadT > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zavT);
               if (zavT < 0 || zavT > 40)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana: ");
                  printf("\nI parcijalni ispit: ");
                  scanf("%f", &parc1B);
                  if (parc1B < 0 || parc1B > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%f", &parc2B);
                     if (parc2B < 0 || parc2B > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%f", &prisB);
                        if (prisB < 0 || prisB > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%f", &zadB);
                           if (zadB < 0 || zadB > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%f", &zavB);
                              if (zavB < 0 || zavB > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: ");
                                 printf("\nI parcijalni ispit: ");
                                 scanf("%f", &parc1M);
                                 if (parc1M < 0 || parc1M > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%f", &parc2M);
                                    if (parc2M < 0 || parc2M > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%f", &prisM);
                                       if (prisM < 0 || prisM > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%f", &zadM);
                                          if (zadM < 0 || zadM > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%f", &zavM);
                                             if (zavM < 0 || zavM > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                zT = parc1T + parc2T + prisT + zadT + zavT;
                                                zB = parc1B + parc2B + prisB + zadB + zavB;
                                                zM = parc1M + parc2M + prisM + zadM + zavM;

                                                if (zT <= 54.99)
                                                {
                                                   zT = 5;
                                                }
                                                else if (zT > 54.99 && zT < 65)
                                                {
                                                   zT = 6;
                                                }
                                                else if (zT >= 65 && zT < 75)
                                                {
                                                   zT = 7;
                                                }
                                                else if (zT >= 75 && zT < 85)
                                                {
                                                   zT = 8;
                                                }
                                                else if (zT >= 85 && zT < 92)
                                                {
                                                   zT = 9;
                                                }
                                                else if (zT >= 92 && zT <= 100)
                                                {
                                                   zT = 10;
                                                }

                                                if (zB <= 54.99)
                                                {
                                                   zB = 5;
                                                }
                                                else if (zB > 54.99 && zB < 65)
                                                {
                                                   zB = 6;
                                                }
                                                else if (zB >= 65 && zB < 75)
                                                {
                                                   zB = 7;
                                                }
                                                else if (zB >= 75 && zB < 85)
                                                {
                                                   zB = 8;
                                                }
                                                else if (zB >= 85 && zB < 92)
                                                {
                                                   zB = 9;
                                                }
                                                else if (zB >= 92 && zB <= 100)
                                                {
                                                   zB = 10;
                                                }

                                                if (zM <= 54.99)
                                                {
                                                   zM = 5;
                                                }
                                                else if (zM > 54.99 && zM < 65)
                                                {
                                                   zM = 6;
                                                }
                                                else if (zM >= 65 && zM < 75)
                                                {
                                                   zM = 7;
                                                }
                                                else if (zM >= 75 && zM < 85)
                                                {
                                                   zM = 8;
                                                }
                                                else if (zM >= 85 && zM < 92)
                                                {
                                                   zM = 9;
                                                }
                                                else if (zM >= 92 && zM <= 100)
                                                {
                                                   zM = 10;
                                                }

                                                if (fabs(zT - 5) < e && fabs(zB - 5) < e && fabs(zM - 5) < e)
                                                {
                                                   printf("Nijedan student nije polozio.");
                                                }
                                                else if ((fabs(zT - 5) < e && fabs(zB - 5) < e && zM >= 6) || (zT >= 6 && fabs(zB - 5) < e && fabs(zM - 5) < e) || (fabs(zT - 5) < e && zB >= 6 && fabs(zM - 5) < e))
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                else if ((fabs(zT - 5) < e && zB > 5 && zM > 5) || (zT > 5 && fabs(zB - 5) < e && zM > 5) || (zT > 5 && zB > 5 && fabs(zM - 5) < e))
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                else if (zT > 5 && zB > 5 && zM > 5)
                                                {
                                                   printf("Sva tri studenta su polozila.");

                                                   if (fabs(zT - zB) < e && fabs(zT - zM) < e)
                                                   {
                                                      printf("\nSva tri studenta imaju istu ocjenu.");
                                                   }
                                                   else if ((fabs(zT - zB) < e && fabs(zT - zM) > e) || (fabs(zT - zM) < e && fabs(zT - zB) > e) || (fabs(zM - zB) < e && fabs(zB - zT) > e))
                                                   {
                                                      printf("\nDva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   else if (fabs(zT - zB) > e && fabs(zT - zM) > e && fabs(zB - zM) > e)
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
