#include <stdio.h>

int main()
{
   double b1, c1, d1, e1, f1, b2, c2, d2, e2, f2, b3, c3, d3, e3, f3, s1, s2, s3, ocjena1, ocjena2, ocjena3;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &c1);
   if (c1 < 0 || c1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &d1);
   if (d1 < 0 || d1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &e1);
   if (e1 < 0 || e1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &f1);
   if (f1 < 0 || f1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   if (b1 >= 0 && b1 <= 20 && c1 >= 0 && c1 <= 20 && d1 >= 0 && d1 <= 10 && e1 >= 0 && e1 <= 10 && f1 >= 0 && f1 <= 40)
   {
      s1 = b1 + c1 + d1 + e1 + f1;

      /*
       * if(s1<55){
       *      printf("Student pao");
       * }if  (s1>=55 && s1<65){
       *      printf("Ocjena 6");
       * }if  (s1>=65 && s1<75){
       *      printf("Ocjena 7");
       * }if  (s1>=75 && s1<85){
       *      printf("Ocjena 8");
       * }if  (s1>=85 && s1<92){
       *      printf("Ocjena 9");
       * }if  (s1>=92 && s1<=100){
       *      printf("Ocjena 10");
       * }*/
   }
   else
   {
      printf("Student je pao predmet");
   }

   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &c2);
   if (c2 < 0 || c2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &d2);
   if (d2 < 0 || d2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &e2);
   if (e2 < 0 || e2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &f2);
   if (f2 < 0 || f2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   if (b2 >= 0 && b2 <= 20 && c2 >= 0 && c2 <= 20 && d2 >= 0 && d2 <= 10 && e2 >= 0 && e2 <= 10 && f2 >= 0 && f2 <= 40)
   {
      s2 = b2 + c2 + d2 + e2 + f2;                        /*
                                                           * if(s2<55){
                                                           * printf("Student pao");
                                                           * }if  (s2>=55 && s2<65){
                                                           * printf("Ocjena 6");
                                                           * }if  (s2>=65 && s2<75){
                                                           * printf("Ocjena 7");
                                                           * }if  (s2>=75 && s2<85){
                                                           * printf("Ocjena 8");
                                                           * }if  (s2>=85 && s2<92){
                                                           * printf("Ocjena 9");
                                                           * }if  (s2>=92 && s2<=100){
                                                           * printf("Ocjena 10");
                                                           * }*/
   }

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &b3);
   if (b3 < 0 || b3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &c3);
   if (c3 < 0 || c3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &d3);
   if (d3 < 0 || d3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &e3);
   if (e3 < 0 || e3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &f3);
   if (f3 < 0 || f3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   if (b3 >= 0 && b3 <= 20 && c3 >= 0 && c3 <= 20 && d3 >= 0 && d3 <= 10 && e3 >= 0 && e3 <= 10 && f3 >= 0 && f3 <= 40)
   {
      s3 = b3 + c3 + d3 + e3 + f3;                        /*
                                                           * if(s3<55){
                                                           * printf("Student pao");
                                                           * }if  (s3>=55 && s3<65){
                                                           * printf("Ocjena 6");
                                                           * }if  (s3>=65 && s3<75){
                                                           * printf("Ocjena 7");
                                                           * }if  (s3>=75 && s3<85){
                                                           * printf("Ocjena 8");
                                                           * }if  (s3>=85 && s3<92){
                                                           * printf("Ocjena 9");
                                                           * }if  (s3>=92 && s3<=100){
                                                           * printf("Ocjena 10");
                                                           * }*/
   }
   else
   {
      printf("Neispravan broj bodova");
   }


   if (s1 >= 55 && s1 < 65)
   {
      ocjena1 = 6;
   }
   if (s1 >= 65 && s1 < 75)
   {
      ocjena1 = 7;
   }
   if (s1 >= 75 && s1 < 85)
   {
      ocjena1 = 8;
   }
   if (s1 >= 85 && s1 < 92)
   {
      ocjena1 = 9;
   }
   if (s1 >= 92 && s1 <= 100)
   {
      ocjena1 = 10;
   }


   if (s2 >= 55 && s2 < 65)
   {
      ocjena2 = 6;
   }
   if (s2 >= 65 && s2 < 75)
   {
      ocjena2 = 7;
   }
   if (s2 >= 75 && s2 < 85)
   {
      ocjena2 = 8;
   }
   if (s2 >= 85 && s2 < 92)
   {
      ocjena2 = 9;
   }
   if (s2 >= 92 && s2 <= 100)
   {
      ocjena2 = 10;
   }


   if (s3 >= 55 && s3 < 65)
   {
      ocjena3 = 6;
   }
   if (s3 >= 65 && s3 < 75)
   {
      ocjena3 = 7;
   }
   if (s3 >= 75 && s3 < 85)
   {
      ocjena3 = 8;
   }
   if (s3 >= 85 && s3 < 92)
   {
      ocjena3 = 9;
   }
   if (s3 >= 92 && s3 <= 100)
   {
      ocjena3 = 10;
   }



   s1 = b1 + c1 + d1 + e1 + f1;
   s2 = b2 + c2 + d2 + e2 + f2;
   s3 = b3 + c3 + d3 + e3 + f3;

   if (s1 < 55 && s2 < 55 && s3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((s1 >= 55 && s2 < 55 && s3 < 55) || (s1 < 55 && s2 >= 55 && s3 < 55) || (s1 < 55 && s2 < 55 && s3 >= 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((s1 > 55 && s2 > 55 && s3 < 55) || (s1 < 55 && s2 > 55 && s3 > 55) || (s1 > 55 && s2 < 55 && s3 > 55))
   {
      printf("Dva studenta su polozila.");
   }
   if (s1 > 55 && s2 > 55 && s3 > 55)
   {
      printf("Sva tri studenta su polozila.");
      if (s1 == s2 && s2 == s3 && s1 == s3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjena1 == ocjena2 && ocjena1 != ocjena3) || (ocjena2 == ocjena3 && ocjena2 != ocjena1) || (ocjena1 == ocjena3 && ocjena1 != ocjena2))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (s1 != s2 && s2 != s3 && s1 != s3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }



   return(0);
}
