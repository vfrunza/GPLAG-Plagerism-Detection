#include <stdio.h>

int main()
{
   float pt, dt, p, z, zt, pb, db, p2, z2, zb, pm, dm, p3, z3, zm, zbir1, zbir2, zbir3;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &pt);
   if (pt < 0 || pt > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dt);
   if (dt < 0 || dt > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &p);
   if (p < 0 || p > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &z);
   if (z < 0 || z > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%f", &zt);
   if (zt < 0 || zt > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   zbir1 = (double)pt + dt + p + z + zt;
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &pb);
   if (pb < 0 || pb > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &db);
   if (db < 0 || db > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &p2);
   if (p2 < 0 || p2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &z2);
   if (z2 < 0 || z2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zb);
   if (zb < 0 || zb > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   zbir2 = (double)pb + db + p2 + z2 + zb;

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &pm);
   if (pm < 0 || pm > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &dm);
   if (dm < 0 || dm > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &p3);
   if (p3 < 0 || p3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &z3);
   if (z3 < 0 || z3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zm);
   if (zm < 0 || zm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   zbir3 = (double)pm + dm + p3 + z3 + zm;


   if ((zbir1 >= 55 && zbir2 < 55 && zbir3 < 55) || (zbir2 >= 55 && zbir1 < 55 && zbir3 < 55) || (zbir3 >= 55 && zbir1 < 55 && zbir2 < 55))
   {
      printf("Jedan student je polozio.");
   }

   else if (zbir1 < 55 && zbir2 < 55 && zbir3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }

   else if ((zbir1 >= 55 && zbir2 >= 55 && zbir3 < 55) || (zbir1 >= 55 && zbir3 >= 55 && zbir2 < 55) || (zbir2 >= 55 && zbir3 >= 55 && zbir1 < 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if (zbir1 >= 55 && zbir2 >= 55 && zbir3 >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }


   if (zbir1 >= 55 && zbir2 >= 55 && zbir3 >= 55 && zbir1 == zbir2 && zbir2 == zbir3 && zbir3 == zbir1)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else if (((zbir1 >= 55 && zbir1 < 65) && (zbir2 >= 55 && zbir2 < 65)) || ((zbir2 >= 55 && zbir2 < 65) && (zbir3 >= 55 && zbir3 < 65)) || ((zbir3 >= 55 && zbir3 < 65) && (zbir1 >= 55 && zbir1 < 65)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (((zbir1 >= 65 && zbir1 < 75) && (zbir2 >= 65 && zbir2 < 75)) || ((zbir2 >= 65 && zbir2 < 75) && (zbir3 >= 65 && zbir3 < 75)) || ((zbir3 >= 65 && zbir3 < 75) && (zbir1 >= 65 && zbir1 < 75)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (((zbir1 >= 75 && zbir1 < 85) && (zbir2 >= 75 && zbir2 < 85)) || ((zbir2 >= 75 && zbir2 < 85) && (zbir3 >= 75 && zbir3 < 85)) || ((zbir3 >= 75 && zbir3 < 85) && (zbir1 >= 75 && zbir1 < 85)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (((zbir1 >= 85 && zbir1 < 92) && (zbir2 >= 85 && zbir2 < 92)) || ((zbir2 >= 85 && zbir2 < 92) && (zbir3 >= 85 && zbir3 < 92)) || ((zbir3 >= 85 && zbir3 < 92) && (zbir1 >= 85 && zbir1 < 92)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (((zbir1 >= 92 && zbir1 <= 100) && (zbir2 >= 92 && zbir2 <= 100)) || ((zbir2 >= 92 && zbir2 <= 100) && (zbir3 >= 92 && zbir3 <= 100)) || ((zbir3 >= 92 && zbir3 <= 100) && (zbir1 >= 92 && zbir1 <= 100)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else if (zbir1 >= 55 && zbir2 >= 55 && zbir3 >= 55 && zbir1 != zbir2 && zbir2 != zbir3 && zbir3 != zbir1)
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }
   return(0);
}
