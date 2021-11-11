#include <stdio.h>

int main()
{
   double p1, p2, p3, z1, z2, z3, pi11, pi12, pi13, pi21, pi22, pi23, u1, u2, u3, b1, b2, b3;
   int    o1, o2, o3;



   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pi11);
   if (pi11 < 0 || pi11 > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &pi21);
      if (pi21 < 0 || pi21 > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &p1);
         if (p1 < 0 || p1 > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &z1);
            if (z1 < 0 || z1 > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &u1);
               if (u1 < 0 || u1 > 40)
               {
                  printf("Neispravan broj bodova");
               }

               else
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");
                  scanf("%lf", &pi12);
                  if (pi12 < 0 || pi12 > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &pi22);
                     if (pi22 < 0 || pi22 > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &p2);
                        if (p2 < 0 || p2 > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &z2);
                           if (z2 < 0 || z2 > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &u2);
                              if (u2 < 0 || u2 > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }

                              else
                              {
                                 printf("Unesite bodove za Mirzu: \n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%lf", &pi13);
                                 if (pi13 < 0 || pi13 > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &pi23);
                                    if (pi23 < 0 || pi23 > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &p3);
                                       if (p3 < 0 || p3 > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &z3);
                                          if (z3 < 0 || z3 > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &u3);
                                             if (u3 < 0 || u3 > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                             }

                                             else
                                             {
                                                b1 = pi11 + pi21 + p1 + z1 + u1;
                                                b2 = pi12 + pi22 + p2 + z2 + u2;
                                                b3 = pi13 + pi23 + p3 + z3 + u3;



                                                if (b1 < 55 && b2 < 55 && b3 < 55)
                                                {
                                                   printf("Nijedan student nije polozio.");
                                                }
                                                else if (b1 >= 55 && b2 < 55 && b3 < 55 || b1 < 55 && b2 >= 55 && b3 < 55 || b1 < 55 && b2 < 55 && b3 >= 55)
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                else if (b1 >= 55 && b2 >= 55 && b3 < 55 || b1 < 55 && b2 >= 55 && b3 >= 55 || b1 >= 55 && b2 < 55 && b3 >= 55)
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                else
                                                {
                                                   printf("Sva tri studenta su polozila.");
                                                }

                                                if (b1 < 55)
                                                {
                                                   o1 = 5;
                                                }
                                                else if (b1 >= 55 && b1 < 65)
                                                {
                                                   o1 = 6;
                                                }
                                                else if (b1 >= 65 && b1 < 75)
                                                {
                                                   o1 = 7;
                                                }
                                                else if (b1 >= 75 && b1 < 85)
                                                {
                                                   o1 = 8;
                                                }
                                                else if (b1 >= 85 && b1 < 92)
                                                {
                                                   o1 = 9;
                                                }
                                                else
                                                {
                                                   o1 = 10;
                                                }

                                                if (b2 < 55)
                                                {
                                                   o2 = 5;
                                                }
                                                else if (b2 >= 55 && b2 < 65)
                                                {
                                                   o2 = 6;
                                                }
                                                else if (b2 >= 65 && b2 < 75)
                                                {
                                                   o2 = 7;
                                                }
                                                else if (b2 >= 75 && b2 < 85)
                                                {
                                                   o2 = 8;
                                                }
                                                else if (b2 >= 85 && b2 < 92)
                                                {
                                                   o2 = 9;
                                                }
                                                else
                                                {
                                                   o2 = 10;
                                                }

                                                if (b3 < 55)
                                                {
                                                   o3 = 5;
                                                }
                                                else if (b3 >= 55 && b3 < 65)
                                                {
                                                   o3 = 6;
                                                }
                                                else if (b3 >= 65 && b3 < 75)
                                                {
                                                   o3 = 7;
                                                }
                                                else if (b3 >= 75 && b3 < 85)
                                                {
                                                   o3 = 8;
                                                }
                                                else if (b3 >= 85 && b3 < 92)
                                                {
                                                   o3 = 9;
                                                }
                                                else
                                                {
                                                   o3 = 10;
                                                }

                                                if (b1 >= 55 && b2 >= 55 && b3 >= 55)
                                                {
                                                   if (o1 == o2 && o2 == o3)
                                                   {
                                                      printf("\nSva tri studenta imaju istu ocjenu.");
                                                   }
                                                   else if (o1 == o2 && o1 != o3 || o1 == o3 && o1 != o2 || o2 == o3 && o1 != o2)
                                                   {
                                                      printf("\nDva od tri studenta imaju istu ocjenu.");
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
