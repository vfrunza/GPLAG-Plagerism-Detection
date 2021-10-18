#include <stdio.h>

int dva_od_tri(int prvi[], int vel_1, int drugi[], int vel_2, int treci[], int vel_3) {
   int i = 0, brojac = 0, j, k, temp, z, test;
   int niz[1000];
   for (i = 0; i < 300; i++) niz[i] = -3196;
   for (i = 0; i < vel_1; i++) {
      test = 0;
      for (z = 0; z < brojac; z++) if (niz[z] == prvi[i]) {
         test = 1;
         break;
      }
      if (test == 1) continue;
      temp = 1;
      for (j = 0; j < vel_2; j++) {
         if (prvi[i] == drugi[j]) temp++;
         if (temp == 2) break;
      }
      for (k = 0; k < vel_3; k++) {
         if (prvi[i] == treci[k]) temp++;
         if (temp == 3) break;
      }
      if (temp == 2) niz[brojac++] = prvi[i];
   }
   for (j = 0; j < vel_2; j++) {
      test = 0;
      for (z = 0; z < brojac; z++) if (niz[z] == drugi[j]) {
         test = 1;
         break;
      }
      if (test == 1) continue;
      temp = 1;
      for (i = 0; i < vel_1; i++) {
         if (prvi[i] == drugi[j]) temp++;
         if (temp > 2) break;
      }
      for (k = 0; k < vel_3; k++) {
         if (treci[k] == drugi[j]) temp++;
         if (temp > 2) break;
      }
      if (temp == 2) niz[brojac++] = drugi[j];
   }
   return brojac;
}

int main() {
	int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
int niz2[] = {3, 3, 3, 2, 2};
int niz3[] = {1, 3, 4};
int rez = dva_od_tri(niz1, 11, niz2, 5, niz3, 3);
//printf("%d ", rez);
rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 3);
//printf("%d ", rez);
rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 11);
//printf("%d ", rez);
}
