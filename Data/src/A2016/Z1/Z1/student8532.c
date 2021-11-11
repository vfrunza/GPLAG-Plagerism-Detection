#include <stdio.h>

int main()
{
   double IpTar, IIpTar, PTar, ZTar, ZITar, IpBoj, IIpBoj, PBoj, ZBoj, ZIBoj, IpMir, IIpMir, PMir, ZMir, ZIMir;
   double SumaTar, SumaBoj, SumaMir;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IpTar);
   if (IpTar < 0 || IpTar > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpTar);
   if (IIpTar < 0 || IIpTar > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PTar);
   if (PTar < 0 || PTar > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZTar);
   if (ZTar > 10 || ZTar < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZITar);
   if (ZITar > 40 || ZITar < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IpBoj);
   if (IpBoj < 0 || IpBoj > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpBoj);
   if (IIpBoj < 0 || IIpBoj > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PBoj);
   if (PBoj > 10 || PBoj < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZBoj);
   if (ZBoj > 10 || ZBoj < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIBoj);
   if (ZIBoj < 0 || ZIBoj > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IpMir);
   if (IpMir < 0 || IpMir > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIpMir);
   if (IIpMir < 0 || IpMir > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PMir);
   if (PMir > 10 || PMir < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZMir);
   if (ZMir > 10 || ZMir < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIMir);
   if (ZIMir > 40 || ZIMir < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   SumaTar = (IpTar + IIpTar + PTar + ZTar + ZITar);
   SumaBoj = (IpBoj + IIpBoj + PBoj + ZBoj + ZIBoj);
   SumaMir = (IpMir + IIpMir + PMir + ZMir + ZIMir);

   if (SumaTar < 55 && SumaBoj < 55 && SumaMir < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((SumaTar >= 55 && SumaBoj < 55 && SumaMir < 55) || (SumaTar < 55 && SumaBoj >= 55 && SumaMir < 55) || (SumaTar < 55 && SumaBoj < 55 && SumaMir >= 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((SumaTar >= 55 && SumaBoj >= 55 && SumaMir < 55) || (SumaTar >= 55 && SumaBoj < 55 && SumaMir >= 55) || (SumaTar < 55 && SumaBoj >= 55 && SumaMir >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
      if ((SumaTar >= 55 && SumaTar < 65 && SumaBoj >= 55 && SumaBoj < 65 && SumaMir >= 55 && SumaMir < 65) || (SumaTar >= 65 && SumaTar < 75 && SumaBoj >= 65 && SumaBoj < 75 && SumaMir >= 65 && SumaMir < 75) || (SumaTar >= 75 && SumaTar < 85 && SumaBoj >= 75 && SumaBoj < 85 && SumaMir >= 75 && SumaMir < 85) || (SumaTar >= 85 && SumaTar < 92 && SumaBoj >= 85 && SumaBoj < 92 && SumaMir >= 85 && SumaMir < 92) || (SumaTar >= 92 && SumaTar <= 100 && SumaBoj >= 92 && SumaBoj <= 100 && SumaMir >= 92 && SumaMir <= 100))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((SumaTar >= 55 && SumaTar < 65 && SumaBoj >= 55 && SumaBoj < 65 && SumaMir >= 65 && SumaMir < 100) || (SumaTar >= 65 && SumaTar < 75 && SumaBoj >= 65 && SumaBoj < 75 && ((SumaMir >= 55 && SumaMir < 65) || (SumaMir >= 75 && SumaMir < 100))) || (SumaTar >= 75 && SumaTar < 85 && SumaBoj >= 75 && SumaBoj < 85 && ((SumaMir >= 55 && SumaMir < 75) || (SumaMir >= 85 && SumaMir < 100))) || (SumaTar >= 85 && SumaTar < 92 && SumaBoj >= 85 && SumaBoj < 92 && ((SumaMir >= 55 && SumaMir < 85) || (SumaMir >= 92 && SumaMir < 100))) || (SumaTar >= 92 && SumaTar < 100 && SumaBoj >= 92 && SumaBoj < 100 && SumaMir >= 55 && SumaMir < 92) || (SumaTar >= 55 && SumaTar < 65 && SumaMir >= 55 && SumaMir < 65 && SumaBoj >= 65 && SumaBoj < 100) || (SumaTar >= 65 && SumaTar < 75 && SumaMir >= 65 && SumaMir < 75 && ((SumaBoj >= 55 && SumaBoj < 65) || (SumaBoj >= 75 && SumaBoj < 100))) || (SumaTar >= 75 && SumaTar < 85 && SumaMir >= 75 && SumaMir < 85 && ((SumaBoj >= 55 && SumaBoj < 75) || (SumaBoj >= 85 && SumaBoj < 100))) || (SumaTar >= 85 && SumaTar < 92 && SumaMir >= 85 && SumaMir < 92 && ((SumaBoj >= 55 && SumaBoj < 85) || (SumaBoj >= 92 && SumaBoj < 100))) || (SumaTar >= 92 && SumaTar < 100 && SumaMir >= 92 && SumaMir < 100 && SumaBoj >= 55 && SumaBoj < 92) || (SumaBoj >= 55 && SumaBoj < 65 && SumaMir >= 55 && SumaMir < 65 && SumaTar >= 65 && SumaTar < 100) || (SumaBoj >= 65 && SumaBoj < 75 && SumaMir >= 65 && SumaMir < 75 && ((SumaTar >= 55 && SumaTar < 65) || (SumaTar >= 75 && SumaTar < 100))) || (SumaBoj >= 75 && SumaBoj < 85 && SumaMir >= 75 && SumaMir < 85 && ((SumaTar >= 55 && SumaTar < 75) || (SumaTar >= 85 && SumaTar < 100))) || (SumaBoj >= 85 && SumaBoj < 92 && SumaMir >= 85 && SumaMir < 92 && ((SumaTar >= 55 && SumaTar < 85) || (SumaTar >= 92 && SumaTar < 100))) || (SumaBoj >= 92 && SumaBoj < 100 && SumaMir >= 92 && SumaMir < 100 && SumaTar >= 55 && SumaTar < 92))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
