#include <stdio.h>

int main()
{
   double t1, t2, t3, t4, t5, b1, b2, b3, b4, b5, m1, m2, m3, m4, m5, s1 = 0, s2 = 0, s3 = 0;
   int    o1 = 0, o2 = 0, o3 = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &t2);
   if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &t3);
   if (t3 < 0 || t3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &t4);
   if (t4 < 0 || t4 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &t5);
   if (t5 < 0 || t5 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &b3);
   if (b3 < 0 || b3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &b4);
   if (b4 < 0 || b4 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &b5);
   if (b5 < 0 || b5 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &m2);
   if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &m3);
   if (m3 < 0 || m3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &m4);
   if (m4 < 0 || m4 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &m5);
   if (m5 < 0 || m5 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s1 = t1 + t2 + t3 + t4 + t5;
   s2 = b1 + b2 + b3 + b4 + b5;
   s3 = m1 + m2 + m3 + m4 + m5;
   if (s1 < 55)
   {
      o1 = 5;
   }
   else if (s1 >= 55 && s1 < 65)
   {
      o1 = 6;
   }
   else if (s1 >= 65 && s1 < 75)
   {
      o1 = 7;
   }
   else if (s1 >= 75 && s1 < 85)
   {
      o1 = 8;
   }
   else if (s1 >= 85 && s1 < 92)
   {
      o1 = 9;
   }
   else if (s1 >= 92 && s1 <= 100)
   {
      o1 = 10;
   }
   if (s2 < 55)
   {
      o2 = 5;
   }
   else if (s2 >= 55 && s2 < 65)
   {
      o2 = 6;
   }
   else if (s2 >= 65 && s2 < 75)
   {
      o2 = 7;
   }
   else if (s2 >= 75 && s2 < 85)
   {
      o2 = 8;
   }
   else if (s2 >= 85 && s2 < 92)
   {
      o2 = 9;
   }
   else if (s2 >= 92 && s2 <= 100)
   {
      o2 = 10;
   }
   if (s3 < 55)
   {
      o3 = 5;
   }
   else if (s3 >= 55 && s3 < 65)
   {
      o3 = 6;
   }
   else if (s3 >= 65 && s3 < 75)
   {
      o3 = 7;
   }
   else if (s3 >= 75 && s3 < 85)
   {
      o3 = 8;
   }
   else if (s3 >= 85 && s3 < 92)
   {
      o3 = 9;
   }
   else if (s3 >= 92 && s3 <= 100)
   {
      o3 = 10;
   }
   if (o1 == 5 && o2 == 5 && o3 == 5)
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }
   else if ((o1 == 5 && o2 == 5 && o3 != 5) || (o1 != 5 && o2 == 5 && o3 == 5) || (o1 == 5 && o2 != 5 && o3 == 5))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   else if ((o1 == 5 && o2 != 5 && o3 != 5) || (o1 != 5 && o2 == 5 && o3 != 5) || (o1 != 5 && o2 != 5 && o3 == 5))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if (o1 != 5 && o2 != 5 && o3 != 5)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   if (o1 == o2 && o1 == o3)
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if ((o1 == o2 && o1 != o3) || (o1 != o2 && o1 == o3) || (o1 != o2 && o2 == o3))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (o1 != o2 && o1 != o3)
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
   return(0);
}
