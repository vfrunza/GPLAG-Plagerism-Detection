#include <stdio.h>
#include <math.h>

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
	int i, j;
	for(i=0; i<vel2; i++) {
		if (niz2[i]<0 || niz2[i]>9) return 0;
		for(j=i+1; j<vel2; j++) {
			if (niz2[i]==niz2[j]) return 0;
		}
	}
	for (i=0; i<vel1; i++) {
		int cifra, broj, stepen=0, negativan=0;
		broj=niz1[i];
		if (broj<0) {
			broj*=(-1);
			negativan=1;
		}
		niz1[i]=0;
		do {
			int izbacivanje=0;
			cifra=broj%10;
			broj/=10;
			for (j=0; j<vel2; j++) {
				if (cifra==niz2[j]) {
					izbacivanje++;
				}
			}
			if (izbacivanje==0) {
				niz1[i]+=cifra*pow(10,stepen);
			} else {
				stepen--;
			}
			stepen++;
		} while (broj>0);
		if (negativan==1) niz1[i]*=(-1);
	}
	return 1;
}

int main()
{
	return 0;
}
