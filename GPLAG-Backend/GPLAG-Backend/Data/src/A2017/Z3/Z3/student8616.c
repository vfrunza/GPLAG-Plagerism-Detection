#include <stdlib.h>
#include <stdio.h>
int izbaci_cifre (int niz1[], int vel1,int niz2[], int vel2)
{
	int i, j, temp, br,k;
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
			k=1;
			temp =0;
			while (niz1[i]!=0) {
				if (niz2[j]!=abs(niz1[i]%10)) {
					temp=(niz1[i]%10)*k+temp;
					k*=10;
				}
				niz1[i]/=10;
			}
			niz1[i]=temp;
			
		}
		
		
	}
	return 1;
}

int main() {
	int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
int i;
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
