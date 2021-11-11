#include <stdio.h>

int main()
{
   float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, r, s, pa, x, y, w, q;
   int   u, v, z;



   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &a);
   if ((a < 0 || a > 20))
   {
      printf("Neispravan broj bodova");
   }
   else if (a >= 0 && a <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &b);
      if ((b < 0 || b > 20))
      {
         printf("Neispravan broj bodova");
      }
      else if (b >= 0 && b <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &c);
         if ((c < 0 || c > 10))
         {
            printf("Neispravan broj bodova");
         }
         else if (c >= 0 && c <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &d);
            if ((d < 0 || d > 10))
            {
               printf("Neispravan broj bodova");
            }
            else if (d >= 0 && d <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &e);
               if ((e < 0 || e > 40))
               {
                  printf("Neispravan broj bodova");
               }
               else if (e >= 0 && e <= 40)
               {
                  printf("Unesite bodove za Bojana: \n");
                  printf("I parcijalni ispit: ");
                  scanf("%f", &f);
                  if ((f < 0 || f > 20))
                  {
                     printf("Neispravan broj bodova");
                  }
                  else if (f >= 0 && f <= 20)
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%f", &g);
                     if ((g < 0 || g > 20))
                     {
                        printf("Neispravan broj bodova");
                     }
                     else if (g >= 0 && g <= 20)
                     {
                        printf("Prisustvo: ");
                        scanf("%f", &h);
                        if ((h < 0 || h > 10))
                        {
                           printf("Neispravan broj bodova");
                        }
                        else if (h >= 0 && h <= 10)
                        {
                           printf("Zadace: ");
                           scanf("%f", &i);
                           if ((i < 0 || i > 10))
                           {
                              printf("Neispravan broj bodova");
                           }
                           else if (i >= 0 && i <= 10)
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%f", &j);
                              if ((j < 0 || j > 40))
                              {
                                 printf("Neispravan broj bodova");
                              }
                              else if (j >= 0 && j <= 40)
                              {
                                 printf("Unesite bodove za Mirzu: \n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%f", &k);
                                 if ((k < 0 || k > 20))
                                 {
                                    printf("Neispravan broj bodova");
                                 }
                                 else if (k >= 0 && k <= 20)
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%f", &l);
                                    if ((l < 0 || l > 20))
                                    {
                                       printf("Neispravan broj bodova");
                                    }
                                    else if (l >= 0 && l <= 20)
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%f", &m);
                                       if ((m < 0 || m > 10))
                                       {
                                          printf("Neispravan broj bodova");
                                       }
                                       else if (m >= 0 && m <= 10)
                                       {
                                          printf("Zadace: ");
                                          scanf("%f", &n);
                                          if ((n < 0 || n > 10))
                                          {
                                             printf("Neispravan broj bodova");
                                          }
                                          else if (n >= 0 && n <= 10)
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%f", &o);
                                             if ((o < 0 || o > 40))
                                             {
                                                printf("Neispravan broj bodova");
                                             }
                                             else if (o >= 0 && o <= 40)
                                             {
                                                p = a + b + c + d + e;
                                                r = f + g + h + i + j;
                                                s = k + l + m + n + o;

                                                if (p < 55)
                                                {
                                                   u = 5;
                                                }
                                                if (p >= 54.5 && p < 65)
                                                {
                                                   u = 6;
                                                }
                                                if (p >= 65 && p < 75)
                                                {
                                                   u = 7;
                                                }
                                                if (p >= 75 && p < 85)
                                                {
                                                   u = 8;
                                                }
                                                if (p >= 85 && p < 92)
                                                {
                                                   u = 9;
                                                }
                                                if (p >= 92 && p <= 100)
                                                {
                                                   u = 10;
                                                }

                                                if (r < 55)
                                                {
                                                   v = 5;
                                                }
                                                if (r >= 55 && r < 65)
                                                {
                                                   v = 6;
                                                }
                                                if (r >= 65 && r < 75)
                                                {
                                                   v = 7;
                                                }
                                                if (r >= 75 && r < 85)
                                                {
                                                   v = 8;
                                                }
                                                if (r >= 85 && r < 92)
                                                {
                                                   v = 9;
                                                }
                                                if (r >= 92 && r <= 100)
                                                {
                                                   v = 10;
                                                }

                                                if (s < 55)
                                                {
                                                   z = 5;
                                                }
                                                if (s >= 55 && s < 65)
                                                {
                                                   z = 6;
                                                }
                                                if (s >= 65 && s < 75)
                                                {
                                                   z = 7;
                                                }
                                                if (s >= 75 && s < 85)
                                                {
                                                   z = 8;
                                                }
                                                if (s >= 85 && s < 92)
                                                {
                                                   z = 9;
                                                }
                                                if (s >= 92 && s <= 100)
                                                {
                                                   z = 10;
                                                }


                                                if (u <= 5 && v <= 5 && z <= 5)
                                                {
                                                   printf("Nijedan student nije polozio.\n");
                                                }
                                                if (u >= 6 && v >= 6 && z >= 6)
                                                {
                                                   printf("Sva tri studenta su polozila.\n");
                                                }
                                                if (u >= 6 && (v < 6 && z < 6))
                                                {
                                                   printf("Jedan student je polozio.\n");
                                                }
                                                if ((u < 6 && v < 6) && z >= 6)
                                                {
                                                   printf("Jedan student je polozio.\n");
                                                }
                                                if ((u < 6 && z < 6) && v >= 6)
                                                {
                                                   printf("Jedan student je polozio.\n");
                                                }
                                                if ((u >= 6 && v >= 6) && z < 6)
                                                {
                                                   printf("Dva studenta su polozila.\n");
                                                }
                                                if (u < 6 && (v >= 6 && z >= 6))
                                                {
                                                   printf("Dva studenta su polozila.\n");
                                                }
                                                if ((u >= 6 && z >= 6) && v < 6)
                                                {
                                                   printf("Dva studenta su polozila.\n");
                                                }

                                                if (u >= 6 && v >= 6 && z >= 6)
                                                {
                                                   if (u == v && u == z && v == z)
                                                   {
                                                      printf("Sva tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (u == v)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (u != v && u != z && v != z)
                                                   {
                                                      printf("Svaki student ima razlicitu ocjenu.");
                                                   }
                                                   if (u == z)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
                                                   }
                                                   if (v == z)
                                                   {
                                                      printf("Dva od tri studenta imaju istu ocjenu.");
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
