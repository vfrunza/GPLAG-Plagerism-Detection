#include <stdio.h>
#define EPSILON    0.0001

int main()
{
   float t1, t2, t3, t4, t5, b1, b2, b3, b4, b5, m1, m2, m3, m4, m5;
   float bodovit, bodovim, bodovib;
   int   ocjenat, ocjenab, ocjenam;
   int   broj = 0;

   /*Broj bodova za Tarike*/
   printf("Unesite bodove za Tarika: \n");

   printf("I parcijalni ispit: ");
   scanf("%f", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &t2);
   if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Prisustvo: ");
   scanf("%f", &t3);
   if (t3 < 0 || t3 > 10)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Zadace: ");
   scanf("%f", &t4);
   if (t4 < 0 || t4 > 10)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &t5);
   if (t5 < 0 || t5 > 40)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }


   /*bodovi za Bojana*/

   printf("Unesite bodove za Bojana: \n");

   printf("I parcijalni ispit: ");
   scanf("%f", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Prisustvo: ");
   scanf("%f", &b3);
   if (b3 < 0 || b3 > 10)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Zadace: ");
   scanf("%f", &b4);
   if (b4 < 0 || b4 > 10)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &b5);
   if (b5 < 0 || b5 > 40)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }


   /*Bodovi za Mirzu*/
   printf("Unesite bodove za Mirzu: \n");

   printf("I parcijalni ispit: ");
   scanf("%f", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &m2);
   if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Prisustvo: ");
   scanf("%f", &m3);
   if (m3 < 0 || m3 > 10)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Zadace: ");
   scanf("%f", &m4);
   if (m4 < 0 || m4 > 10)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &m5);
   if (m5 < 0 || m5 > 40)
   {
      printf("Neispravan broj bodova");
      goto kraj;
   }

   bodovit = t1 + t2 + t3 + t4 + t5;
   bodovib = b1 + b2 + b3 + b4 + b5;
   bodovim = m1 + m2 + m3 + m4 + m5;


   if ((55 - bodovim) < EPSILON)
   {
      broj++;
   }
   if ((55 - bodovib) < EPSILON)
   {
      broj++;
   }
   if ((55 - bodovit) < EPSILON)
   {
      broj++;
   }

   if (broj == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (broj == 1)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (broj == 2)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
   }

   /*odredjivanje ocjene za Mirzu*/

   if (bodovim < 55)
   {
      ocjenam = 5;
   }
   else if (bodovim >= 55 && bodovim < 65)
   {
      ocjenam = 6;
   }
   else if (bodovim >= 65 && bodovim < 75)
   {
      ocjenam = 7;
   }
   else if (bodovim >= 75 && bodovim < 85)
   {
      ocjenam = 8;
   }
   else if (bodovim >= 85 && bodovim < 92)
   {
      ocjenam = 9;
   }
   else
   {
      ocjenam = 10;
   }

   /*odredjivanje ocjene za Tarika*/

   if (bodovit < 55)
   {
      ocjenat = 5;
   }
   else if (bodovit >= 55 && bodovit < 65)
   {
      ocjenat = 6;
   }
   else if (bodovit >= 65 && bodovit < 75)
   {
      ocjenat = 7;
   }
   else if (bodovit >= 75 && bodovit < 85)
   {
      ocjenat = 8;
   }
   else if (bodovit >= 85 && bodovit < 92)
   {
      ocjenat = 9;
   }
   else
   {
      ocjenat = 10;
   }


   /*odredjivanje ocjene za Bojana*/

   if (bodovib < 55)
   {
      ocjenab = 5;
   }
   else if (bodovib >= 55 && bodovib < 65)
   {
      ocjenab = 6;
   }
   else if (bodovib >= 65 && bodovib < 75)
   {
      ocjenab = 7;
   }
   else if (bodovib >= 75 && bodovib < 85)
   {
      ocjenab = 8;
   }
   else if (bodovib >= 85 && bodovib < 92)
   {
      ocjenab = 9;
   }
   else
   {
      ocjenab = 10;
   }


   /*Odredjivanje da li studenti imaju iste ili razlicite ocjene*/

   if (ocjenam != 5 && ocjenat != 5 && ocjenab != 5)
   {
      if (ocjenat == ocjenab && ocjenat == ocjenam)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenat == ocjenab)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenat == ocjenam)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenab == ocjenam)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }


kraj:
   return(0);
}
