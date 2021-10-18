#include <stdio.h>
#include <math.h>

int izbaci_iz_broja (int broj, int cifra)
{
	int niz[100]= {0}, vel = 0, i, j, x, imaminus = 0;

	if (broj < 0)
		imaminus = 1;

	while (broj != 0) {
		niz[vel] = fabs(broj%10);
		vel++;
		broj/=10;
	}

	for (i=0; i<vel; i++) {
		if (niz[i] == cifra) {
			for (j=i; j<vel-1; j++) {
				niz[j] = niz[j+1];
			}
			i--;
			vel--;
		}
	}

	x = 0;
	for (i=vel-1; i>=0; i--) {
		x = 10*x + niz[i];
	}

	if (imaminus == 1)
		x *= -1;
	return x;
}
int izbaci_cifre ( int A[], int velA, int B[], int velB)
{
	int i, j, temp;

	for ( i=0; i<velB; i++) {
		if( B[i]<0 || B[i]>9 )
			return 0;
	}

	for (i=0; i<velB-1; i++) {
		for (j=i+1; j<velB; j++) {
			if (B[i] == B[j]) return 0;
		}
	}

	for (i=0; i<velA; i++) {

		temp = A[i];
		for (j=0; j<velB; j++) {
			temp = izbaci_iz_broja(temp, B[j]);
		}

		A[i] = temp;
	}

	return 1;
}
int main(){

	return 0;
}