#include <stdio.h>
#include <math.h>
int main()
{
   float T1, T2, Tp, Tz, B1, B2, Bp, Bz, M1, M2, Mp, Mz, Tukupno, Bukupno, Mukupno, Tza, Bza, Mza;
   int   ocjenaM, ocjenaB, ocjenaT;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &T2);
      if (T2 < 0 || T2 > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%f", &Tp);
         if (Tp < 0 || Tp > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%f", &Tz);
            if (Tz < 0 || Tz > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &Tza);
               if (Tza < 0 || Tza > 40)
               {
                  printf("Neispravan unos");
               }
               else
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");
                  scanf("%f", &B1);
                  if (B1 < 0 || B1 > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%f", &B2);
                     if (B2 < 0 || B2 > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                     }
                     scanf("%f", &Bp);
                     if (Bp < 0 || Bp > 10)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Zadace: ");
                        scanf("%f", &Bz);
                        if (Bz < 0 || Bz > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zavrsni ispit: ");
                           scanf("%f", &Bza);
                           if (Bza < 0 || Bza > 40)
                           {
                              printf("Neispravan unos");
                           }
                           else
                           {
                              printf("Unesite bodove za Mirzu: \n");
                              printf("I parcijalni ispit: ");
                              scanf("%f", &M1);
                              if (M1 < 0 || M1 > 20)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("II parcijalni ispit: ");
                                 scanf("%f", &M2);
                                 if (M2 < 0 || M2 > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("Prisustvo: ");
                                    scanf("%f", &Mp);
                                    if (Mp < 0 || Mp > 10)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Zadace: ");
                                       scanf("%f", &Mz);
                                       if (Mz < 0 || Mz > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zavrsni ispit: ");
                                          scanf("%f", &Mza);
                                          if (Mza < 0 || Mza > 40)
                                          {
                                             printf("Neispravan unos");
                                          }
                                          else
                                          {
                                             Tukupno = T1 + T2 + Tz + Tp + Tza;
                                             Bukupno = B1 + B2 + Bz + Bp + Bza;
                                             Mukupno = M1 + M2 + Mz + Mp + Mza;
                                             if (Tukupno < 55 && Bukupno < 55 && Mukupno < 55)
                                             {
                                                printf("Nijedan student nije polozio.");
                                             }
                                             else
                                             {
                                                if (Tukupno < 55)
                                                {
                                                   ocjenaT = 5;
                                                }
                                                if (Bukupno < 55)
                                                {
                                                   ocjenaB = 5;
                                                }
                                                if (Mukupno < 55)
                                                {
                                                   ocjenaM = 5;
                                                }

                                                if (((fabs(Tukupno - 55) < 0.00001) || Tukupno > 55) && Tukupno < 65)
                                                {
                                                   ocjenaT = 6;
                                                }
                                                if (((fabs(Bukupno - 55) < 0.00001) || Bukupno > 55) && Bukupno < 65)
                                                {
                                                   ocjenaB = 6;
                                                }
                                                if (((fabs(Mukupno - 55) < 0.00001) || Mukupno > 55) && Mukupno < 65)
                                                {
                                                   ocjenaM = 6;
                                                }
                                                if (((fabs(Tukupno - 65) < 0.00001) || Tukupno > 65) && Tukupno < 75)
                                                {
                                                   ocjenaT = 7;
                                                }
                                                if (((fabs(Mukupno - 65) < 0.00001) || Mukupno > 65) && Mukupno < 75)
                                                {
                                                   ocjenaM = 7;
                                                }
                                                if (((fabs(Bukupno - 65) < 0.00001) || Bukupno > 65) && Bukupno < 75)
                                                {
                                                   ocjenaB = 7;
                                                }
                                                if (((fabs(Tukupno - 75) < 0.00001) || Tukupno > 75) && Tukupno < 85)
                                                {
                                                   ocjenaT = 8;
                                                }
                                                if (((fabs(Mukupno - 75) < 0.00001) || Mukupno > 75) && Mukupno < 85)
                                                {
                                                   ocjenaM = 8;
                                                }
                                                if (((fabs(Bukupno - 75) < 0.00001) || Bukupno > 75) && Bukupno < 85)
                                                {
                                                   ocjenaB = 8;
                                                }
                                                if (((fabs(Tukupno - 85) < 0.00001) || Tukupno > 85) && Tukupno < 92)
                                                {
                                                   ocjenaT = 9;
                                                }
                                                if (((fabs(Mukupno - 85) < 0.00001) || Mukupno > 85) && Mukupno < 92)
                                                {
                                                   ocjenaM = 9;
                                                }
                                                if (((fabs(Bukupno - 85) < 0.00001) || Bukupno > 85) && Bukupno < 92)
                                                {
                                                   ocjenaB = 9;
                                                }
                                                if (((fabs(Tukupno - 92) < 0.00001) || Tukupno > 92) && Tukupno < 100)
                                                {
                                                   ocjenaT = 10;
                                                }
                                                if (((fabs(Mukupno - 92) < 0.00001) || Mukupno > 92) && Mukupno < 100)
                                                {
                                                   ocjenaM = 10;
                                                }
                                                if (((fabs(Bukupno - 92) < 0.00001) || Bukupno > 92) && Bukupno < 100)
                                                {
                                                   ocjenaB = 10;
                                                }

                                                if (ocjenaM >= 6 && ocjenaB == 5 && ocjenaT == 5)
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                if (ocjenaT >= 6 && ocjenaB == 5 && ocjenaM == 5)
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                if (ocjenaB >= 6 && ocjenaM == 5 && ocjenaT == 5)
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                if (ocjenaM >= 6 && ocjenaB >= 6 && ocjenaT == 5)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                if (ocjenaM >= 6 && ocjenaB == 5 && ocjenaT >= 6)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                if (ocjenaB >= 6 && ocjenaT >= 6 && ocjenaM == 5)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }

                                                if (((fabs(Tukupno - 55) < 0.00001) || Tukupno > 55) && ((fabs(Mukupno - 55) < 0.00001) || Mukupno > 55) && ((fabs(Bukupno - 55) < 0.00001) || Bukupno > 55))
                                                {
                                                   printf("Sva tri studenta su polozila.\n");
                                                   if (ocjenaT == ocjenaM && ocjenaT == ocjenaB)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (ocjenaT == ocjenaM && ocjenaT != ocjenaB)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (ocjenaT == ocjenaB && ocjenaT != ocjenaM)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (ocjenaB == ocjenaM && ocjenaT != ocjenaB)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (ocjenaB != ocjenaM && ocjenaB != ocjenaT)
                                                   {
                                                      printf("Svaki student ima razlicitu ocjenu.");
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
