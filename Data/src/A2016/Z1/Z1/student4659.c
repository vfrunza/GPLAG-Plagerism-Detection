#include <stdio.h>

int main()
{
   double a1, b1, c1, d1, e1, a2, b2, c2, d2, e2, a3, b3, c3, d3, e3, OT, OB, OM;
   int    T, B, M;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a1);
   if (a1 < 0 || a1 > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &b1);
      if (b1 < 0 || b1 > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &c1);
         if (c1 < 0 || c1 > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &d1);
            if (d1 < 0 || d1 > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &e1);
               if (e1 < 0 || e1 > 40)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");
                  scanf("%lf", &a2);
                  if (a2 < 0 || a2 > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &b2);
                     if (b2 < 0 || b2 > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &c2);
                        if (c2 < 0 || c2 > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &d2);
                           if (d2 < 0 || d2 > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &e2);
                              if (e2 < 0 || e2 > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: \n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%lf", &a3);
                                 if (a3 < 0 || a3 > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &b3);
                                    if (b3 < 0 || b3 > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &c3);
                                       if (c3 < 0 || c3 > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &d3);
                                          if (d3 < 0 || d3 > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &e3);
                                             if (e3 < 0 || e3 > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                OT = a1 + b1 + c1 + d1 + e1;

                                                if (OT >= 55 && OT < 65)
                                                {
                                                   T = 6;
                                                }
                                                if (OT >= 65 && OT < 75)
                                                {
                                                   T = 7;
                                                }
                                                if (OT >= 75 && OT < 85)
                                                {
                                                   T = 8;
                                                }
                                                if (OT >= 85 && OT < 92)
                                                {
                                                   T = 9;
                                                }
                                                if (OT >= 92 && OT <= 100)
                                                {
                                                   T = 10;
                                                }

                                                OB = a2 + b2 + c2 + d2 + e2;
                                                if (OB >= 55 && OB < 65)
                                                {
                                                   B = 6;
                                                }
                                                if (OB >= 65 && OB < 75)
                                                {
                                                   B = 7;
                                                }
                                                if (OB >= 75 && OB < 85)
                                                {
                                                   B = 8;
                                                }
                                                if (OB >= 85 && OB < 92)
                                                {
                                                   B = 9;
                                                }
                                                if (OB >= 92 && OB <= 100)
                                                {
                                                   B = 10;
                                                }

                                                OM = a3 + b3 + c3 + d3 + e3;
                                                if (OM >= 55 && OM < 65)
                                                {
                                                   M = 6;
                                                }
                                                if (OM >= 65 && OM < 75)
                                                {
                                                   M = 7;
                                                }
                                                if (OM >= 75 && OM < 85)
                                                {
                                                   M = 8;
                                                }
                                                if (OM >= 85 && OM < 92)
                                                {
                                                   M = 9;
                                                }
                                                if (OM >= 92 && OM <= 100)
                                                {
                                                   M = 10;
                                                }

                                                if (OT < 55 && OB < 55 && OM < 55)
                                                {
                                                   printf("Nijedan student nije polozio.\n");
                                                }

                                                if (OT >= 55 && OB < 55 && OM < 55)
                                                {
                                                   printf("Jedan student je polozio.\n");
                                                }
                                                if (OT < 55 && OB >= 55 && OM < 55)
                                                {
                                                   printf("Jedan student je polozio.\n");
                                                }
                                                if (OT < 55 && OB < 55 && OM >= 55)
                                                {
                                                   printf("Jedan student je polozio.\n");
                                                }

                                                if (OT >= 55 && OB >= 55 && OM < 55)
                                                {
                                                   printf("Dva studenta su polozila.\n");
                                                }
                                                if (OT < 55 && OB >= 55 && OM >= 55)
                                                {
                                                   printf("Dva studenta su polozila.\n");
                                                }
                                                if (OT >= 55 && OB < 55 && OM >= 55)
                                                {
                                                   printf("Dva studenta su polozila.\n");
                                                }

                                                if (OT >= 55 && OB >= 55 && OM >= 55)
                                                {
                                                   printf("Sva tri studenta su polozila.\n");
                                                   if (T != B && T != M && B != M)
                                                   {
                                                      printf("Svaki student ima razlicitu ocjenu.\n");
                                                   }
                                                   if (T == B && T == M && B == M)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu.\n");
                                                   }
                                                   if (T != B && T != M && B == M)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.\n");
                                                   }
                                                   if (T != B && T == M && B != M)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.\n");
                                                   }
                                                   if (T == B && T != M && B != M)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.\n");
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
