#include <stdio.h>
#define EPS 0.0000001

int main() {
   float PI1,PI2,PI3,P1,P2,P3,ZI1,ZI2,ZI3,Z1,Z2,Z3,PII1,PII2,PII3,UT=0,UB=0,UM=0;
   int O1,O2,O3;
//Tarik
   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%f", &PI1);
   if (PI1 > 20 || PI1 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &PII1);
   if (PII1 > 20 || PII1 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Prisustvo: ");
   scanf("%f", &P1);
   if (P1 > 10 || P1 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Zadace: ");
   scanf("%f", &Z1);
   if (Z1 > 10 || Z1 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZI1);
   if (ZI1 > 40 || ZI1 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
//Bojan   
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%f", &PI2);
    if (PI2 > 20 || PI2 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &PII2);
   if (PII2 > 20 || PII2 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Prisustvo: ");
   scanf("%f", &P2);
   if (P2 > 10 || P2 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Zadace: ");
   scanf("%f", &Z2);
   if (Z2 > 10 || Z2 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZI2);
   if (ZI2 > 40 || ZI2 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   
//Mirza   
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%f", &PI3);
    if (PI3 > 20 || PI3 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &PII3);
   if (PII3 > 20 || PII3 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Prisustvo: ");
   scanf("%f", &P3); 
   if (P3 > 10 || P3 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Zadace: ");
   scanf("%f", &Z3);
   if (Z3 > 10 || Z3 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZI3);
   if (ZI3 > 40 || ZI3 < 0)
   {
       printf("Neispravan broj bodova");
       return 0;
   }
   UT = PI1 + PII1 + P1 + Z1 + ZI1; UT = (UT * 100 +0.5)/100;
   UB = PI2 + PII2 + P2 + Z2 + ZI2; UB = (UB * 100 +0.5)/100;
   UM = PI3 + PII3 + P3 + Z3 + ZI3; UM = (UM * 100 +0.5)/100;
//Ocjene  
if(1)
{
   if(UT>=55.0 && UT < 65)
   O1 = 6;
   else if(UT>=65.0 && UT < 75.0)
   O1 = 7;
   else if(UT>=75.0 && UT < 85.0)
   O1 = 8;
   else if(UT>=85.0 && UT < 95.0)
   O1 = 9;
   else if(UT>=95.0 && UT < 100.0)
   O1 = 10;
}
if(1)
{
   if(UB>=55.0 && UB < 65.0)
   O2 = 6;
   else if(UB>=65.0 && UB < 75.0)
   O2 = 7;
   else if(UB>=75.0 && UB < 85.0)
   O2 = 8;
   else if(UB>=85.0 && UB < 95.0)
   O2 = 9;
   else if(UB>=95.0 && UB < 100.0)
   O2 = 10;
}
if(1)
{
   if(UM >= 55.0 && UM < 65.0)
   O3 = 6;
   else if(UM >= 65.0 && UM < 75.0)
   O3 = 7;
   else if(UM >= 75.0 && UM < 85.0)
   O3 = 8;
   else if(UM >= 85.0 && UM < 95.0)
   O3 = 9;
   else if(UM >= 95.0 && UM < 100.0)
   O3 = 10;
}
//Ocjene   
//Poređenje
if (UT < 55.0 && UM < 55.0 && UB < 55.0)
printf("Nijedan student nije polozio.");
else if (UT >= 55.0 && UM >= 55 && UB >= 55.0)
{
   printf("Sva tri studenta su polozila.");
   if (O1 == O2 && O2 == O3 && O1 == O3)
   printf("\nSva tri studenta imaju istu ocjenu.");
   else if (O1 != O2 && O2 != O3 && O1 != O3)
   printf("\nSvaki student ima razlicitu ocjenu.");
   else
   printf("\nDva od tri studenta imaju istu ocjenu.");
   
}
else if ((UT >= 55.0 && UM >= 55.0 && UB <= 55.0) || (UT <= 55.0 && UM >= 55.0 && UB >= 55.0) || (UT >= 55.0 && UM <= 55.0 && UB >= 55.0) )
{
   printf("Dva studenta su polozila.");
}
else
printf("Jedan student je polozio.");
	return 0;
}
