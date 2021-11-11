#include <stdio.h>
#include <math.h>

int main()
{
   double PPIT, DPIT, PT, ZT, ZIT, PPIB, DPIB, PB, ZB, ZIB, PPIM, DPIM, PM, ZM, ZIM;
   int    T, B, M, OT, OB, OM;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &PPIT);
   if (PPIT > 20 || PPIT < 0)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &DPIT);
      if (DPIT > 20 || DPIT < 0)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &PT);
         if (PT > 10 || PT < 0)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &ZT);
            if (ZT > 10 || ZT < 0)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &ZIT);
               if (ZIT > 40 || ZIT < 0)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
                  scanf("%lf", &PPIB);
                  if (PPIB > 20 || PPIB < 0)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &DPIB);
                     if (DPIB > 20 || DPIB < 0)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &PB);
                        if (PB > 10 || PB < 0)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &ZB);
                           if (ZB > 10 || ZB < 0)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &ZIB);
                              if (ZIB > 40 || ZIB < 0)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
                                 scanf("%lf", &PPIM);
                                 if (PPIM > 20 || PPIM < 0)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &DPIM);
                                    if (DPIM > 20 || DPIM < 0)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &PM);
                                       if (PM > 10 || PM < 0)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &ZM);
                                          if (ZM > 10 || ZM < 0)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &ZIM);
                                             if (ZIM > 40 || ZIM < 0)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                T = PPIT + DPIT + PT + ZT + ZIT;
                                                B = PPIB + DPIB + PB + ZB + ZIB;
                                                M = PPIM + DPIM + PM + ZM + ZIM;

                                                if (T < 55)
                                                {
                                                   OT = 5;
                                                }
                                                else if (T >= 55 && T < 65)
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

                                                if (B < 55)
                                                {
                                                   OB = 5;
                                                }
                                                else if (B >= 55 && B < 65)
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

                                                if (M < 55)
                                                {
                                                   OM = 5;
                                                }
                                                else if (M >= 55 && M < 65)
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

                                                if (OT == 5 && OB == 5 && OM == 5)
                                                {
                                                   printf("Nijedan student nije polozio. ");
                                                }
                                                else if (OT != 5 && OB != 5 && OM != 5)
                                                {
                                                   printf("Sva tri studenta su polozila. \n");
                                                   if (OT - OB == 0 && OT - OM == 0)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu. ");
                                                   }
                                                   else if (OT - OB != 0 && OB - OM != 0 && OT - OM != 0)
                                                   {
                                                      printf("Svaki student ima razlicitu ocjenu. ");
                                                   }
                                                   else
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu. ");
                                                   }
                                                }
                                                else if ((OT != 5 && OB == 5 && OM == 5) || (OT == 5 && OB == 5 && OM != 5) || (OT == 5 && OB != 5 && OM == 5))
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                else
                                                {
                                                   printf("Dva studenta su polozila.  ");
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
