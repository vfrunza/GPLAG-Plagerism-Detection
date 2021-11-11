#include <stdio.h>

int main()
{
   float t1, t2, t3, t4, t5, b1, b2, b3, b4, b5, m1, m2, m3, m4, m5, zt, zb, zm;
   int   tocjena, bocjena, mocjena;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova");
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &t2);
      if (t2 < 0 || t2 > 20)
      {
         printf("Neispravan broj bodova");
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%f", &t3);
         if (t3 < 0 || t3 > 10)
         {
            printf("Neispravan broj bodova");
         }
         else
         {
            printf("Zadace: ");
            scanf("%f", &t4);
            if (t4 < 0 || t4 > 10)
            {
               printf("Neispravan broj bodova");
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &t5);
               if (t5 < 0 || t5 > 40)
               {
                  printf("Neispravan broj bodova");
               }
               else
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");
                  scanf("%f", &b1);
                  if (b1 < 0 || b1 > 20)
                  {
                     printf("Neispravan broj bodova");
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%f", &b2);
                     if (b2 < 0 || b2 > 20)
                     {
                        printf("Neispravan broj bodova");
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%f", &b3);
                        if (b3 < 0 || b3 > 10)
                        {
                           printf("Neispravan broj bodova");
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%f", &b4);
                           if (b4 < 0 || b4 > 10)
                           {
                              printf("Neispravan broj bodova");
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%f", &b5);
                              if (b5 < 0 || b5 > 40)
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else
                              {
                                 printf("Unesite bodove za Mirzu: \n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%f", &m1);
                                 if (m1 < 0 || m1 > 20)
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%f", &m2);
                                    if (m2 < 0 || m2 > 20)
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%f", &m3);
                                       if (m3 < 0 || m3 > 10)
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%f", &m4);
                                          if (m4 < 0 || m4 > 10)
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%f", &m5);
                                             if (m5 < 0 || m5 > 40)
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else
                                             {
                                                zt = t1 + t2 + t3 + t4 + t5;
                                                zb = b1 + b2 + b3 + b4 + b5;
                                                zm = m1 + m2 + m3 + m4 + m5;
                                                if (zt < 54.999996 && zb < 54.999996 && zm < 54.999996)
                                                {
                                                   printf("Nijedan student nije polozio.");
                                                }
                                                else if (((zt >= 54.999996) && (zb < 54.999996) && (zm < 54.999996)) || ((zt < 54.999996) && (zb >= 54.999996) && (zm < 54.999996)) || ((zt < 54.999996) && (zb < 54.999996) && (zm >= 54.999996)))
                                                {
                                                   printf("Jedan student je polozio.");
                                                }
                                                else if (((zt >= 54.999996) && (zb >= 54.999996) && (zm < 54.999996)) || ((zt >= 54.999996) && (zb < 54.999996) && (zm >= 54.999996)) || ((zt < 54.999996) && (zb >= 54.999996) && (zm >= 54.999996)))
                                                {
                                                   printf("Dva studenta su polozila.");
                                                }
                                                else
                                                {
                                                   printf("Sva tri studenta su polozila.\n");
                                                   if (zt >= 55. && zt < 65.)
                                                   {
                                                      tocjena = 1;
                                                   }
                                                   else if (zt >= 65. && zt < 7.5)
                                                   {
                                                      tocjena = 2;
                                                   }
                                                   else if (zt >= 75. && zt < 85.)
                                                   {
                                                      tocjena = 3;
                                                   }
                                                   else if (zt >= 85. && zt < 92.)
                                                   {
                                                      tocjena = 4;
                                                   }
                                                   else
                                                   {
                                                      tocjena = 5;
                                                   }
                                                   if (zb >= 55. && zb < 65.)
                                                   {
                                                      bocjena = 1;
                                                   }
                                                   else if (zb >= 65. && zb < 75.)
                                                   {
                                                      bocjena = 2;
                                                   }
                                                   else if (zb >= 75. && zb < 85.)
                                                   {
                                                      bocjena = 3;
                                                   }
                                                   else if (zb >= 85. && zb < 92.)
                                                   {
                                                      bocjena = 4;
                                                   }
                                                   else
                                                   {
                                                      bocjena = 5;
                                                   }
                                                   if (zm >= 55. && zm < 65.)
                                                   {
                                                      mocjena = 1;
                                                   }
                                                   else if (zm >= 65. && zm < 75.)
                                                   {
                                                      mocjena = 2;
                                                   }
                                                   else if (zm >= 75. && zm < 85.)
                                                   {
                                                      mocjena = 3;
                                                   }
                                                   else if (zm >= 85. && zm < 92.)
                                                   {
                                                      mocjena = 4;
                                                   }
                                                   else
                                                   {
                                                      mocjena = 5;
                                                   }
                                                   if (tocjena == bocjena && bocjena == mocjena)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu.");
                                                   }
                                                   else if (((tocjena == bocjena) && (bocjena != mocjena)) || ((tocjena == mocjena) && (mocjena != bocjena)) || ((bocjena == mocjena) && (mocjena != tocjena)))
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

   return(0);
}
