#include <stdio.h>

int main()
{
   //unos za tarika
   float IparcT, IIparcT, zadaceT, prisustvoT, zavrsniT;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &IparcT);
   //Provjera ispravnog unosa
   if (IparcT < 0 || IparcT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcT);
   //Provjera ispravnog unosa
   if (IIparcT < 0 || IIparcT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Prisustvo: ");
   scanf("%f", &prisustvoT);
   //Provjera ispravnog unosa
   if (prisustvoT < 0 || prisustvoT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Zadace: ");
   scanf("%f", &zadaceT);
   if (zadaceT < 0 || zadaceT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniT);
   //Provjera ispravnog unosa
   if (zavrsniT < 0 || zavrsniT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");


   //unos za bojana
   float IparcB, IIparcB, zadaceB, prisustvoB, zavrsniB;

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &IparcB);
   //Provjera ispravnog unosa
   if (IparcB < 0 || IparcB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   //printf("\n");
   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcB);
   //Provjera ispravnog unosa
   if (IIparcB < 0 || IIparcB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Prisustvo: ");
   scanf("%f", &prisustvoB);
   //Provjera ispravnog unosa
   if (prisustvoB < 0 || prisustvoB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Zadace: ");
   scanf("%f", &zadaceB);
   if (zadaceB < 0 || zadaceB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniB);
   //Provjera ispravnog unosa
   if (zavrsniB < 0 || zavrsniB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");



   //unos za mirzu
   float IparcM, IIparcM, zadaceM, prisustvoM, zavrsniM;

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &IparcM);
   //Provjera ispravnog unosa
   if (IparcM < 0 || IparcM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("II parcijalni ispit: ");
   scanf("%f", &IIparcM);
   //Provjera ispravnog unosa
   if (IIparcM < 0 || IIparcM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Prisustvo: ");
   scanf("%f", &prisustvoM);
   //Provjera ispravnog unosa
   if (prisustvoM < 0 || prisustvoM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Zadace: ");
   scanf("%f", &zadaceM);
   if (zadaceM < 0 || zadaceM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsniM);
   //Provjera ispravnog unosa
   if (zavrsniM < 0 || zavrsniM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
//	printf("\n");



   //Sabiranje bodova
   float tarik, mirza, bojan;

   tarik = IparcT + IIparcT + zadaceT + prisustvoT + zavrsniT;
   mirza = IparcM + IIparcM + zadaceM + prisustvoM + zavrsniM;
   bojan = IparcB + IIparcB + zadaceB + prisustvoB + zavrsniB;

   int ocjenaT, ocjenaB, ocjenaM;

   //ocjena tarika
   if (tarik < 54.99)
   {
      ocjenaT = 5;
   }
   else if (tarik >= 54.99 && tarik < 65)
   {
      ocjenaT = 6;
   }
   else if (tarik >= 65 && tarik < 75)
   {
      ocjenaT = 7;
   }
   else if (tarik >= 75 && tarik < 85)
   {
      ocjenaT = 8;
   }
   else if (tarik >= 85 && tarik < 92)
   {
      ocjenaT = 9;
   }
   else if (tarik >= 92 && tarik <= 100)
   {
      ocjenaT = 10;
   }
   //ocjena mirze
   if (mirza < 54.99)
   {
      ocjenaM = 5;
   }
   else if (mirza >= 54.99 && mirza < 65)
   {
      ocjenaM = 6;
   }
   else if (mirza >= 65 && mirza < 75)
   {
      ocjenaM = 7;
   }
   else if (mirza >= 75 && mirza < 85)
   {
      ocjenaM = 8;
   }
   else if (mirza >= 85 && mirza < 92)
   {
      ocjenaM = 9;
   }
   else if (mirza >= 92 && mirza <= 100)
   {
      ocjenaM = 10;
   }
   //ocjena bojana
   if (bojan < 54.99)
   {
      ocjenaB = 5;
   }
   else if (bojan >= 54.9 && bojan < 65)
   {
      ocjenaB = 6;
   }
   else if (bojan >= 65 && bojan < 75)
   {
      ocjenaB = 7;
   }
   else if (bojan >= 75 && bojan < 85)
   {
      ocjenaB = 8;
   }
   else if (bojan >= 85 && bojan < 92)
   {
      ocjenaB = 9;
   }
   else if (bojan >= 92 && bojan <= 100)
   {
      ocjenaB = 10;
   }

   //prvi ispis koliko je studenata polozilo potencialni problem u drugom i cetvrtom uslovu
   if (ocjenaB > 5 && ocjenaM > 5 && ocjenaT > 5)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else
   if ((ocjenaB >= 6 && ocjenaM == 5 && ocjenaT == 5) || (ocjenaB == 5 && ocjenaM >= 6 && ocjenaT == 5) || (ocjenaB == 5 && ocjenaM == 5 && ocjenaT >= 6))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   if (ocjenaB == 5 && ocjenaM == 5 && ocjenaT == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else
   if ((ocjenaB > 5 && ocjenaM > 5 && ocjenaT == 5) || (ocjenaB > 5 && ocjenaM == 5 && ocjenaT > 5) || (ocjenaB == 5 && ocjenaM > 5 && ocjenaT > 5))
   {
      printf("Dva studenta su polozila.\n");
   }
   //Uslov za ispit da su sva tri studenta polozila
   if (ocjenaB > 5 && ocjenaM > 5 && ocjenaT > 5)
   {
      //ispis za svaku od kombinacija
      if (ocjenaT == ocjenaM && ocjenaM == ocjenaB)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else
      if ((ocjenaT == ocjenaM && ocjenaM != ocjenaB && ocjenaT != ocjenaB) || (ocjenaB == ocjenaM && ocjenaM != ocjenaT && ocjenaB != ocjenaT) || (ocjenaT == ocjenaB && ocjenaB != ocjenaM && ocjenaT != ocjenaM))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      if (ocjenaT != ocjenaM && ocjenaM != ocjenaB && ocjenaT != ocjenaB)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
