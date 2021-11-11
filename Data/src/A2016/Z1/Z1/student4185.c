#include <stdio.h>

int main()
{
   double ppt, ppb, ppm, dpt, dpb, dpm, pm, pb, pt, zim, zit, zib, zm, zt, zb, a, b, c, d, f, T, M, B;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &ppt);
   if (ppt < 0 || ppt > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &dpt);
      if (dpt < 0 || dpt > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &pt);
         if (pt < 0 || pt > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &zt);
            if (zt < 0 || zt > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &zit);
               if (zit < 0 || zit > 40)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");

                  scanf("%lf", &ppb);
                  if (ppb < 0 || ppb > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &dpb);
                     if (dpb < 0 || dpb > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &pb);
                        if (pb < 0 || pb > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &zb);
                           if (zb < 0 || zb > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &zib);
                              if (zib < 0 || zib > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: \n");
                                 printf("I parcijalni ispit: ");


                                 scanf("%lf", &ppm);
                                 if (ppm < 0 || ppm > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &dpm);
                                    if (dpm < 0 || dpm > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &pm);
                                       if (pm < 0 || pm > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &zm);
                                          if (zm < 0 || zm > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &zim);
                                             if (zim < 0 || zim > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                T = ppt + dpt + zt + pt + zit;
                                                M = ppm + dpm + zm + pm + zim;
                                                B = ppb + dpb + zb + pb + zib;


                                                if (T < 55)
                                                {
                                                   a = 5;
                                                }


                                                if (T >= 55 && T < 65)
                                                {
                                                   a = 6;
                                                }

                                                if (T >= 65 && T < 75)
                                                {
                                                   a = 7;
                                                }


                                                if (T >= 75 && T < 85)
                                                {
                                                   a = 8;
                                                }

                                                if (T >= 85 && T < 92)
                                                {
                                                   a = 9;
                                                }


                                                if (T >= 92 && T <= 100)
                                                {
                                                   a = 10;
                                                }

                                                if (B < 55)
                                                {
                                                   b = 5;
                                                }


                                                if (B >= 55 && B < 65)
                                                {
                                                   b = 6;
                                                }

                                                if (B >= 65 && B < 75)
                                                {
                                                   b = 7;
                                                }


                                                if (B >= 75 && B < 85)
                                                {
                                                   b = 8;
                                                }

                                                if (B >= 85 && B < 92)
                                                {
                                                   b = 9;
                                                }


                                                if (B >= 92 && B <= 100)
                                                {
                                                   b = 10;
                                                }


                                                if (M < 55)
                                                {
                                                   c = 5;
                                                }


                                                if (M >= 55 && M < 65)
                                                {
                                                   c = 6;
                                                }

                                                if (M >= 65 && M < 75)
                                                {
                                                   c = 7;
                                                }


                                                if (M >= 75 && M < 85)
                                                {
                                                   c = 8;
                                                }

                                                if (M >= 85 && M < 92)
                                                {
                                                   c = 9;
                                                }


                                                if (M >= 92 && M <= 100)
                                                {
                                                   c = 10;
                                                }


                                                if (b > 5 && c > 5 && a > 5)
                                                {
                                                   printf("Sva tri studenta su polozila.\n");

                                                   if (a == c && a == b)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (a != b && a != c && b != c)
                                                   {
                                                      printf("Svaki student ima razlicitu ocjenu.");
                                                   }
                                                   if ((a == b || b == c) && a != c)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                }
                                                if (a == 5 && b == 5 && c == 5)
                                                {
                                                   printf("Nijedan student nije polozio.");
                                                }

                                                if (a > 5 && b > 5 && c == 5)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                if (a > 5 && c > 5 && b == 5)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                if (b > 5 && c > 5 && a == 5)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }

                                                if (a == 5 && b == 5 && c > 5)
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                if (a == 5 && c == 5 && b > 5)
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                if (b == 5 && c == 5 && (a == 6 || a == 7 || a == 8 || a == 9 || a == 10))
                                                {
                                                   printf("Jedan student je polozio.");
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
