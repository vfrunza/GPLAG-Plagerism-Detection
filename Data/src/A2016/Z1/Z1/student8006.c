#include <stdio.h>

int main()
{
   int    oT, oM, oB;
   double ppT, ppM, ppB, dpT, dpM, dpB, pT, pB, pM, zadT, zadM, zadB, zT, zM, zB, BrBT, BrBM, BrBB;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &ppT);
   if (ppT < 0 || ppT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &dpT);
      if (dpT < 0 || dpT > 20)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &pT);
         if (pT < 0 || pT > 10)
         {
            printf("Neispravan broj bodova");
            return(0);
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &zadT);
            if (zadT < 0 || zadT > 10)
            {
               printf("Neispravan broj bodova");
               return(0);
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &zT);
               if (zT < 0 || zT > 40)
               {
                  printf("Neispravan broj bodova");
                  return(0);
               }
               else
               {
                  printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
                  scanf("%lf", &ppB);
                  if (ppB < 0 || ppB > 20)
                  {
                     printf("Neispravan broj bodova");
                     return(0);
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &dpB);
                     if (dpB < 0 || dpB > 20)
                     {
                        printf("Neispravan broj bodova");
                        return(0);
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &pB);
                        if (pB < 0 || pB > 10)
                        {
                           printf("Neispravan broj bodova");
                           return(0);
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &zadB);
                           if (zadB < 0 || zadB > 10)
                           {
                              printf("Neispravan broj bodova");
                              return(0);
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &zB);
                              if (zB < 0 || zB > 40)
                              {
                                 printf("Neispravan broj bodova");
                                 return(0);
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
                                 scanf("%lf", &ppM);
                                 if (ppM < 0 || ppM > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                    return(0);
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &dpM);
                                    if (dpM < 0 || dpM > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                       return(0);
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &pM);
                                       if (pM < 0 || pM > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                          return(0);
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &zadM);
                                          if (zadM < 0 || zadM > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                             return(0);
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &zM);
                                             if (zM < 0 || zM > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                                return(0);
                                             }
                                             else
                                             {
                                                printf("");
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
   BrBT = ppT + dpT + pT + zadT + zT;
   BrBM = ppM + dpM + pM + zadM + zM;
   BrBB = ppB + dpB + pB + zadB + zB;
   if (BrBT < 55)
   {
      oT = 5;
   }
   else if (BrBT >= 55 && BrBT < 65)
   {
      oT = 6;
   }
   else if (BrBT >= 65 && BrBT < 75)
   {
      oT = 7;
   }
   else if (BrBT >= 75 && BrBT < 85)
   {
      oT = 8;
   }
   else if (BrBT >= 85 && BrBT < 92)
   {
      oT = 9;
   }
   else if (BrBT >= 92 && BrBT <= 100)
   {
      oT = 10;
   }

   if (BrBB < 55)
   {
      oB = 5;
   }
   else if (BrBB >= 55 && BrBB < 65)
   {
      oB = 6;
   }
   else if (BrBB >= 65 && BrBB < 75)
   {
      oB = 7;
   }
   else if (BrBB >= 75 && BrBB < 85)
   {
      oB = 8;
   }
   else if (BrBB >= 85 && BrBB < 92)
   {
      oB = 9;
   }
   else if (BrBB >= 92 && BrBB <= 100)
   {
      oB = 10;
   }

   if (BrBM < 55)
   {
      oM = 5;
   }
   else if (BrBM >= 55 && BrBM < 65)
   {
      oM = 6;
   }
   else if (BrBM >= 65 && BrBM < 75)
   {
      oM = 7;
   }
   else if (BrBM >= 75 && BrBM < 85)
   {
      oM = 8;
   }
   else if (BrBM >= 85 && BrBM < 92)
   {
      oM = 9;
   }
   else if (BrBM >= 92 && BrBM <= 100)
   {
      oM = 10;
   }

   if (oT == 5 && oB == 5 && oM == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((oT != 5 && oB == 5 && oM == 5) || (oT == 5 && oB != 5 && oM == 5) || (oT == 5 && oB == 5 && oM != 5))
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((oT != 5 && oB != 5 && oM == 5) || (oT != 5 && oB == 5 && oM != 5) || (oT == 5 && oB != 5 && oM != 5))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (oT != 5 && oB != 5 && oM != 5)
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if (oT > 5 && oM > 5 && oB > 5)
   {
      if (oT == oB && oT == oM && oB == oM)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((oT == oB && oT != oM) || (oT == oM && oT != oB) || (oM == oB && oM != oT))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if ((oT != oB && oT != oM && oM != oB))
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
