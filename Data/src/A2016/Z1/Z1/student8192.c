#include <stdio.h>

int main()
{
   int   Mpao = 0, Bpao = 0, Tpao = 0, M6 = 0, M7 = 0, M8 = 0, M9 = 0, M10 = 0, B6 = 0, B7 = 0, B8 = 0, B9 = 0, B10 = 0, T6 = 0, T7 = 0, T8 = 0, T9 = 0, T10 = 0;
   float PT = 0, PB = 0, PM = 0, zt = 0, ZT = 0, zb = 0, ZB = 0, zm = 0, ZM = 0, IB = 0, IIB = 0, IT = 0, IIT = 0, IM = 0, IIM = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");           scanf("%f", &IT);  if (IT < 0 || IT > 20)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("II parcijalni ispit: ");          scanf("%f", &IIT); if (IIT < 0 || IIT > 20)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Prisustvo: ");                            scanf("%f", &PT);  if (PT < 0 || PT > 10)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Zadace: ");                               scanf("%f", &zt);  if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Zavrsni ispit: ");                        scanf("%f", &ZT);  if (ZT < 0 || ZT > 40)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");           scanf("%f", &IB);  if (IB < 0 || IB > 20)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("II parcijalni ispit: ");          scanf("%f", &IIB); if (IIB < 0 || IIB > 20)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Prisustvo: ");                            scanf("%f", &PB);  if (PB < 0 || PB > 10)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Zadace: ");                               scanf("%f", &zb);  if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Zavrsni ispit: ");                        scanf("%f", &ZB);  if (ZB < 0 || ZB > 40)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");           scanf("%f", &IM);  if (IM < 0 || IM > 20)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("II parcijalni ispit: ");          scanf("%f", &IIM); if (IIM < 0 || IIM > 20)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Prisustvo: ");                            scanf("%f", &PM);  if (PM < 0 || PM > 10)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Zadace: ");                               scanf("%f", &zm);  if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova"); goto end;
   }
   printf("Zavrsni ispit: ");                        scanf("%f", &ZM);  if (ZM < 0 || ZM > 40)
   {
      printf("Neispravan broj bodova"); goto end;
   }

   if (IT + IIT + PT + zt + ZT + 0.00001 < 55)
   {
      Tpao = 1;
   }
   else if ((IT + IIT + PT + zt + ZT) >= 55 && (IT + IIT + PT + zt + ZT) < 65)
   {
      T6 = 1;
   }
   else if ((IT + IIT + PT + zt + ZT) >= 65 && (IT + IIT + PT + zt + ZT) < 75)
   {
      T7 = 1;
   }
   else if ((IT + IIT + PT + zt + ZT) >= 75 && (IT + IIT + PT + zt + ZT) < 85)
   {
      T8 = 1;
   }
   else if ((IT + IIT + PT + zt + ZT) >= 85 && (IT + IIT + PT + zt + ZT) < 92)
   {
      T9 = 1;
   }
   else if ((IT + IIT + PT + zt + ZT) >= 92 && (IT + IIT + PT + zt + ZT) <= 100)
   {
      T10 = 1;
   }
   if ((IB + IIB + PB + zb + ZB) + 0.00001 < 55)
   {
      Bpao = 1;
   }
   else if ((IB + IIB + PB + zb + ZB) >= 55 && (IB + IIB + PB + zb + ZB) < 65)
   {
      B6 = 1;
   }
   else if ((IB + IIB + PB + zb + ZB) >= 65 && (IB + IIB + PB + zb + ZB) < 75)
   {
      B7 = 1;
   }
   else if ((IB + IIB + PB + zb + ZB) >= 75 && (IB + IIB + PB + zb + ZB) < 85)
   {
      B8 = 1;
   }
   else if ((IB + IIB + PB + zb + ZB) >= 85 && (IB + IIB + PB + zb + ZB) < 92)
   {
      B9 = 1;
   }
   else if ((IB + IIB + PB + zb + ZB) >= 92 && (IB + IIB + PB + zb + ZB) <= 100)
   {
      B10 = 1;
   }
   if ((IM + IIM + PM + zm + ZM) + 0.00001 < 55)
   {
      Mpao = 1;
   }
   else if ((IM + IIM + PM + zm + ZM) >= 55 && (IM + IIM + PM + zm + ZM) < 65)
   {
      M6 = 1;
   }
   else if ((IM + IIM + PM + zm + ZM) >= 65 && (IM + IIM + PM + zm + ZM) < 75)
   {
      M7 = 1;
   }
   else if ((IM + IIM + PM + zm + ZM) >= 75 && (IM + IIM + PM + zm + ZM) < 85)
   {
      M8 = 1;
   }
   else if ((IM + IIM + PM + zm + ZM) >= 85 && (IM + IIM + PM + zm + ZM) < 92)
   {
      M9 = 1;
   }
   else if ((IM + IIM + PM + zm + ZM) >= 92 && (IM + IIM + PM + zm + ZM) <= 100)
   {
      M10 = 1;
   }

   if (Tpao == 1 && Bpao == 1 && Mpao == 1)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((Tpao == 0 && Bpao == 1 && Mpao == 1) || (Tpao == 1 && Bpao == 0 && Mpao == 1) || (Tpao == 1 && Bpao == 1 && Mpao == 0))
   {
      printf("Jedan student je polozio.");
   }
   else if ((Tpao == 0 && Bpao == 0 && Mpao == 1) || (Tpao == 0 && Bpao == 1 && Mpao == 0) || (Tpao == 1 && Bpao == 0 && Mpao == 0))
   {
      printf("Dva studenta su polozila.");
   }
   else if (Tpao == 0 && Bpao == 0 && Mpao == 0)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((T6 == 1 && B6 == 1 && M6 == 1) || (T7 == 1 && B7 == 1 && M7 == 1) || (T8 == 1 && B8 == 1 && M8 == 1) || (T9 == 1 && B9 == 1 && M9 == 1) || (T10 == 1 && B10 == 1 && M10 == 1))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if ((T6 == 1 && B6 == 1) || (M6 == 1 && B6 == 1) || (T6 == 1 && M6 == 1) || (T7 == 1 && B7 == 1) || (M7 == 1 && B7 == 1) || (T7 == 1 && M7 == 1) || (T8 == 1 && B8 == 1) || (M8 == 1 && B8 == 1) || (T8 == 1 && M8 == 1) || (T9 == 1 && B9 == 1) || (M9 == 1 && B9 == 1) || (T9 == 1 && M9 == 1) || (T10 == 1 && B10 == 1) || (M10 == 1 && B10 == 1) || (T10 == 1 && M10 == 1))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
end: return(0);
}
