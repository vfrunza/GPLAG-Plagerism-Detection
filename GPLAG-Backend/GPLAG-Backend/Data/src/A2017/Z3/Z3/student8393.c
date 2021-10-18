#include <stdio.h>
#include <math.h>

int izbaci_cifre(int brojevi[], int vel_1, int cifre[], int vel_2) {
	int i, j, temp, cifra, test, novi_broj, red, predznak;
	int digits[10] = {0};
	if (vel_2 > 10) return 0;
	for (i = 0; i < vel_2; i++) {
		if (cifre[i] < 0 || cifre[i] > 9) return 0;
		digits[cifre[i]]++;
	}
	for (i = 0; i < 10; i++) if (digits[i] > 1) return 0;
	for (i = 0; i < vel_1; i++) {
		novi_broj = 0;
		red = 0;
		if (brojevi[i] < 0) predznak = -1;
		else predznak = 1;
		temp = brojevi[i] * predznak;
		while (temp != 0) {
			test = 0;
			cifra = temp%10;
			for (j = 0; j < vel_2; j++) {
				if (cifra == cifre[j]) test = 1;
				if (test) break;
			}
			if (!test) {
				novi_broj += cifra * pow(10, red);
				red++;
			}
			temp = temp/10;
		}
		brojevi[i] = predznak * novi_broj;
 	}
	return 1;
}



int main() {
	int brojevi[] = {25, 235, 1235, 252, 22552255};
int cifre[] = {2, 3, 5};
int i;

izbaci_cifre(brojevi, 5, cifre, 3);
for (i=0; i<5; i++)
  printf("%d ", brojevi[i]);
  return 0;
}
