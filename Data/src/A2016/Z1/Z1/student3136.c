#include <stdio.h>

int main()
{
   float Ip, IIp, P, Z, ZI, zbir, zbir1 = 0, zbir2 = 0;
   int   a = 0, b = 0, c = 0, d = 0;


   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Ip);
   if (Ip < 0 || Ip > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIp);
   if (IIp < 0 || IIp > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &P);
   if (P < 0 || P > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   zbir = Ip + IIp + P + Z + ZI;
   if (zbir >= 55)
   {
      a++;
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Ip);
   if (Ip < 0 || Ip > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIp);
   if (IIp < 0 || IIp > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &P);
   if (P < 0 || P > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   zbir1 = Ip + IIp + P + Z + ZI;
   if (zbir1 >= 55)
   {
      a++;
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Ip);
   if (Ip < 0 || Ip > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIp);
   if (IIp < 0 || IIp > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &P);
   if (P < 0 || P > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   zbir2 = Ip + IIp + P + Z + ZI;
   if (zbir2 >= 55)
   {
      a++;
   }


   if (a == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (a == 1)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (a == 2)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (a == 3)
   {
      printf("Sva tri studenta su polozila.\n");
   }



   if (zbir > 0 && zbir < 55)
   {
      b = 5;
   }
   else if (zbir >= 55 && zbir < 65)
   {
      b = 6;
   }
   else if (zbir >= 65 && zbir < 75)
   {
      b = 7;
   }
   else if (zbir >= 75 && zbir < 85)
   {
      b = 8;
   }
   else if (zbir >= 85 && zbir < 92)
   {
      b = 9;
   }
   else if (zbir >= 92 && zbir <= 100)
   {
      b = 10;
   }

   if (zbir1 > 0 && zbir1 < 55)
   {
      c = 5;
   }
   else if (zbir1 >= 55 && zbir1 < 65)
   {
      c = 6;
   }
   else if (zbir1 >= 65 && zbir1 < 75)
   {
      c = 7;
   }
   else if (zbir1 >= 75 && zbir1 < 85)
   {
      c = 8;
   }
   else if (zbir1 >= 85 && zbir1 < 92)
   {
      c = 9;
   }
   else if (zbir1 >= 92 && zbir1 <= 100)
   {
      c = 10;
   }

   if (zbir2 > 0 && zbir2 < 55)
   {
      d = 5;
   }
   else if (zbir2 >= 55 && zbir2 < 65)
   {
      d = 6;
   }
   else if (zbir2 >= 65 && zbir2 < 75)
   {
      d = 7;
   }
   else if (zbir2 >= 75 && zbir2 < 85)
   {
      d = 8;
   }
   else if (zbir2 >= 85 && zbir2 < 92)
   {
      d = 9;
   }
   else if (zbir2 >= 92 && zbir2 <= 100)
   {
      d = 10;
   }



   if (b == 5 && c == 5 && d == 5)
   {
      return(0);
   }
   else if ((b >= 6 && c < 6 && d < 6) || (c >= 6 && b < 6 && d < 6) || (d >= 6 && b < 6 && c < 6))
   {
      return(0);
   }
   if (a == 3)
   {
      if (b == c && c == d && b == d)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((b == c && b != d) || (c == d && b != c) || (d == b && d != c))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (b != c && c != d)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
