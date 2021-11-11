#include <stdio.h>
#include <math.h>

int izbaci_cifre (int niz1[], int vel1, int niz2[], int vel2)
{
	int i, j, temp, k;
	for (i=0; i<vel2; i++) {
		if (niz2[i]<0 || niz2[i]>9) {
			return 0;
		}
	}
	for (i=0; i<vel2-1; i++) {
		for (j=i+1; j<vel2; j++) {
			if (niz2[j]==niz2[i]) {
				return 0;
			}
		}
	}
	for (i=0; i<vel1; i++) {
		for (j=0; j<vel2; j++) {
			temp=0;
			k=1;
			while (niz1[i]!=0) {
				if (niz2[j]!=fabs(niz1[i]%10)) {
					temp=temp+(niz1[i]%10)*k;
					k*=10;
				}
				niz1[i]/=10;
			}
			niz1[i]=temp;
		}
	}
	return 1;
}

int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}

