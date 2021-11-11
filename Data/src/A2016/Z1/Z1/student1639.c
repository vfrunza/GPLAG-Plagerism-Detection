#include <stdio.h>
#define EPS    0.0000001

int main()
{
   double tpp, tdp, tz, tp, tzi, bpp, bdp, bz, bp, bzi, mpp, mdp, mz, mp, mzi, st, sb, sm;
   int    om, ot, ob;

   /*tarik*/
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &tpp);
   if (tpp < 0 || tpp > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &tdp);
      if (tdp < 0 || tpp > 20)
      {
         printf("Neispravan broj bodova"); return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &tp);
         if (tp < 0 || tp > 10)
         {
            printf("Neispravan broj bodova"); return(0);
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &tz);
            if (tz < 0 || tz > 10)
            {
               printf("Neispravan broj bodova"); return(0);
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &tzi);
               if (tzi < 0 || tzi > 40)
               {
                  printf("Neispravan broj bodova"); return(0);
               }
               else
               {
                  /*bojan*/
                  printf("Unesite bodove za Bojana:\n");
                  printf("I parcijalni ispit: ");
                  scanf("%lf", &bpp);
                  if (bpp < 0 || bpp > 20)
                  {
                     printf("Neispravan broj bodova"); return(0);
                  }
                  else
                  {
                     printf("II parcijalni ispit: ");
                     scanf("%lf", &bdp);
                     if (bdp < 0 || bdp > 20)
                     {
                        printf("Neispravan broj bodova"); return(0);
                     }
                     else
                     {
                        printf("Prisustvo: ");
                        scanf("%lf", &bp);
                        if (bp < 0 || bp > 10)
                        {
                           printf("Neispravan broj bodova"); return(0);
                        }
                        else
                        {
                           printf("Zadace: ");
                           scanf("%lf", &bz);
                           if (bz < 0 || bz > 10)
                           {
                              printf("Neispravan broj bodova"); return(0);
                           }
                           else
                           {
                              printf("Zavrsni ispit: ");
                              scanf("%lf", &bzi);
                              if (bzi < 0 || bzi > 40)
                              {
                                 printf("Neispravan broj bodova"); return(0);
                              }
                              else
                              {
                                 /*mirza*/
                                 printf("Unesite bodove za Mirzu:\n");
                                 printf("I parcijalni ispit: ");
                                 scanf("%lf", &mpp);
                                 if (mpp < 0 || mpp > 20)
                                 {
                                    printf("Neispravan broj bodova"); return(0);
                                 }
                                 else
                                 {
                                    printf("II parcijalni ispit: ");
                                    scanf("%lf", &mdp);
                                    if (mdp < 0 || mdp > 20)
                                    {
                                       printf("Neispravan broj bodova"); return(0);
                                    }
                                    else
                                    {
                                       printf("Prisustvo: ");
                                       scanf("%lf", &mp);
                                       if (mp < 0 || mp > 10)
                                       {
                                          printf("Neispravan broj bodova"); return(0);
                                       }
                                       else
                                       {
                                          printf("Zadace: ");
                                          scanf("%lf", &mz);
                                          if (mz < 0 || mz > 10)
                                          {
                                             printf("Neispravan broj bodova"); return(0);
                                          }
                                          else
                                          {
                                             printf("Zavrsni ispit: ");
                                             scanf("%lf", &mzi);
                                             if (mzi < 0 || mzi > 40)
                                             {
                                                printf("Neispravan broj bodova"); return(0);
                                             }
                                             else
                                             {
                                                st = tpp + tdp + tz + tp + tzi;
                                                sb = bpp + bdp + bz + bp + bzi;
                                                sm = mpp + mdp + mz + mp + mzi;

                                                if (st >= 55 && st < 65)
                                                {
                                                   ot = 6;
                                                }
                                                else if (st >= 65 && st < 75)
                                                {
                                                   ot = 7;
                                                }
                                                else if (st >= 75 && st < 85)
                                                {
                                                   ot = 8;
                                                }
                                                else if (st >= 85 && st < 92)
                                                {
                                                   ot = 9;
                                                }
                                                else
                                                {
                                                   ot = 10;
                                                }

                                                if (sb >= 55 && sb < 65)
                                                {
                                                   ob = 6;
                                                }
                                                else if (sb >= 65 && sb < 75)
                                                {
                                                   ob = 7;
                                                }
                                                else if (sb >= 75 && sb < 85)
                                                {
                                                   ob = 8;
                                                }
                                                else if (sb >= 85 && sb < 92)
                                                {
                                                   ob = 9;
                                                }
                                                else
                                                {
                                                   ob = 10;
                                                }

                                                if (st >= 55 && sm < 65)
                                                {
                                                   om = 6;
                                                }
                                                else if (sm >= 65 && sm < 75)
                                                {
                                                   om = 7;
                                                }
                                                else if (sm >= 75 && sm < 85)
                                                {
                                                   om = 8;
                                                }
                                                else if (sm >= 85 && sm < 92)
                                                {
                                                   om = 9;
                                                }
                                                else
                                                {
                                                   om = 10;
                                                }



                                                if ((st < 55 && sb < 55 && sm >= 55) || (st < 55 && sb >= 55 && sm < 55) || (st >= 55 && sb < 55 && sm < 55))
                                                {
                                                   printf("Jedan student je polozio."); return(0);
                                                }
                                                else if ((st < 55 && sb >= 55 && sm >= 55) || (st >= 55 && sb >= 55 && sm < 55) || (st >= 55 && sb < 55 && sm >= 55))
                                                {
                                                   printf("Dva studenta su polozila."); return(0);
                                                }
                                                else if (st < 55 && sb < 55 && sm < 55)
                                                {
                                                   printf("Nijedan student nije polozio."); return(0);
                                                }
                                                else if (st > 55 && sb > 55 && sm > 55)
                                                {
                                                   printf("Sva tri studenta su polozila.\n");
                                                   { if (ot == ob && ob == om)
                                                     {
                                                        printf("Sva tri studenta imaju istu ocjenu.");
                                                     }
                                                     else if ((ot == ob && ob != om) || (ot == om && om != ob) || (ob == om && om != ot))
                                                     {
                                                        printf("Dva od tri studenta imaju istu ocjenu.");
                                                     }
                                                     else
                                                     {
                                                        printf("Svaki student ima razlicitu ocjenu.");
                                                     } }
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
