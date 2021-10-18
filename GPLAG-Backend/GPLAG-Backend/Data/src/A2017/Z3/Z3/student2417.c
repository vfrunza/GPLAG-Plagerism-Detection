#include <stdio.h>

 int izbaci_cifre(int brojevi[], int vel1, int cifre[], int vel2) {
  int i, j, brojac, broj, broj1, negativan = 0, ponavlja = 0;
  int p, q;
  int pomn[15] = {
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
  };
  for (i = 0; i < vel2; i++) pomn[i] = cifre[i];
  for (i = 0; i < vel2; i++) {
   brojac = 0;
   if (cifre[i] < 0 || cifre[i] > 9) return 0;
   for (j = 0; j < vel2; j++)
    if (cifre[i] == pomn[j]) brojac++;
   if (brojac > 1) return 0;
  }
  for (i = 0; i < vel1; i++) {
   broj1 = 0;
   negativan = 0;
   if (brojevi[i] < 0) negativan = 1;
   broj = brojevi[i];
   if (broj < 0) broj *= -1;
   q = 1;
   while (broj != 0) {
    ponavlja = 0;
    p = broj % 10;
    for (j = 0; j < vel2; j++) {
     if (p == cifre[j]) ponavlja = 1;
    }
    if (ponavlja == 0) {
     broj1 += p * q;
     q *= 10;
    }
    broj /= 10;
   }
   if (negativan) broj1 *= -1; * (brojevi + i) = broj1;
  }
  return 1;
 }

int main() {
 int brojevi[] = {
  12345, -12345
 };
 int cifre[] = {
  3, 5
 };
 izbaci_cifre(brojevi, 2, cifre, 2);
 printf("%d %d", brojevi[0], brojevi[1]);
 return 0;
}