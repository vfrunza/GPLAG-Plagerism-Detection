#include <stdio.h>

int main()
{
   double pp1, pp2, pp3, dp1, dp2, dp3, p1, p2, p3, z1, z2, z3, zi1, zi2, zi3;
   double bb1, bb2, bb3;
   int    br, o1, o2, o3;

   br = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp1);
   if ((pp1 < 0) || (pp1 > 20))
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &dp1);
      if ((dp1 < 0) || (dp1 > 20))
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &p1);
         if ((p1 < 0) || (p1 > 10))
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &z1);
            if ((z1 < 0) || (z1 > 10))
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &zi1);
               if ((zi1 < 0) || (zi1 > 40))
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");
                  scanf("%lf", &pp2);
                  if ((pp2 < 0) || (pp2 > 20))
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &dp2);
                     if ((dp2 < 0) || (dp2 > 20))
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &p2);
                        if ((p2 < 0) || (p2 > 10))
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &z2);
                           if ((z2 < 0) || (z2 > 10))
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &zi2);
                              if ((zi2 < 0) || (zi2 > 40))
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: \n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%lf", &pp3);
                                 if ((pp3 < 0) || (pp3 > 20))
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &dp3);
                                    if ((dp3 < 0) || (dp3 > 20))
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &p3);
                                       if ((p3 < 0) || (p3 > 10))
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &z3);
                                          if ((z3 < 0) || (z3 > 10))
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &zi3);
                                             if ((zi3 < 0) || (zi3 > 40))
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                if ((pp1 > 20) || (pp2 > 20) || (pp3 > 20) || (dp1 > 20) || (dp2 > 20) || (dp3 > 20) || (p1 > 10) || (p2 > 10) || (p3 > 10) || (z1 > 10) || (z2 > 10) || (z3 > 10) || (zi1 > 40) || (zi2 > 40) || (zi3 > 40) || (pp1 < 0) || (pp2 < 0) || (pp3 < 0) || (dp1 < 0) || (dp2 < 0) || (dp3 < 0) || (p1 < 0) || (p2 < 0) || (p3 < 0) || (z1 < 0) || (z2 < 0) || (z3 < 0) || (zi1 < 0) || (zi2 < 0) || (zi3 < 0))
                                                {
                                                   printf("Neispravan broj bodova");
                                                }
                                                else
                                                {
                                                   bb1 = pp1 + dp1 + p1 + z1 + zi1;
                                                   bb2 = pp2 + dp2 + p2 + z2 + zi2;
                                                   bb3 = pp3 + dp3 + p3 + z3 + zi3;

                                                   if (bb1 < 55)
                                                   {
                                                      o1 = 5;
                                                   }
                                                   else if ((bb1 < 65) && (bb1 >= 55))
                                                   {
                                                      o1 = 6;
                                                      br++;
                                                   }
                                                   else if ((bb1 < 75) && (bb1 >= 65))
                                                   {
                                                      o1 = 7;
                                                      br++;
                                                   }
                                                   else if ((bb1 < 85) && (bb1 >= 75))
                                                   {
                                                      o1 = 8;
                                                      br++;
                                                   }
                                                   else if ((bb1 < 92) && (bb1 >= 85))
                                                   {
                                                      o1 = 9;
                                                      br++;
                                                   }
                                                   else
                                                   {
                                                      o1 = 10;
                                                      br++;
                                                   }



                                                   if (bb2 < 55)
                                                   {
                                                      o2 = 5;
                                                   }
                                                   else if ((bb2 < 65) && (bb2 >= 55))
                                                   {
                                                      o2 = 6;
                                                      br++;
                                                   }
                                                   else if ((bb2 < 75) && (bb2 >= 65))
                                                   {
                                                      o2 = 7;
                                                      br++;
                                                   }
                                                   else if ((bb2 < 85) && (bb2 >= 75))
                                                   {
                                                      o2 = 8;
                                                      br++;
                                                   }
                                                   else if ((bb2 < 92) && (bb2 >= 85))
                                                   {
                                                      o2 = 9;
                                                      br++;
                                                   }
                                                   else
                                                   {
                                                      o2 = 10;
                                                      br++;
                                                   }


                                                   if (bb3 < 55)
                                                   {
                                                      o3 = 5;
                                                   }
                                                   else if ((bb3 < 65) && (bb3 >= 55))
                                                   {
                                                      o3 = 6;
                                                      br++;
                                                   }
                                                   else if ((bb3 < 75) && (bb3 >= 65))
                                                   {
                                                      o3 = 7;
                                                      br++;
                                                   }
                                                   else if ((bb3 < 85) && (bb3 >= 75))
                                                   {
                                                      o3 = 8;
                                                      br++;
                                                   }
                                                   else if ((bb3 < 92) && (bb3 >= 85))
                                                   {
                                                      o3 = 9;
                                                      br++;
                                                   }
                                                   else
                                                   {
                                                      o3 = 10;
                                                      br++;
                                                   }
                                                   if (br == 0)
                                                   {
                                                      printf("Nijedan student nije polozio.\n");
                                                   }
                                                   if (br == 1)
                                                   {
                                                      printf("Jedan student je polozio.\n");
                                                   }
                                                   if (br == 2)
                                                   {
                                                      printf("Dva studenta su polozila.\n");
                                                   }
                                                   if (br == 3)
                                                   {
                                                      printf("Sva tri studenta su polozila.\n");
                                                      if ((o1 == o2) && (o2 == o3))
                                                      {
                                                         printf("Sva tri studenta imaju istu ocjenu.");
                                                      }
                                                      else if ((o1 == o2) || (o2 == o3) || (o1 == o3))
                                                      {
                                                         printf("Dva od tri studenta imaju istu ocjenu.");
                                                      }
                                                      else
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
   }

   return(0);
}
