#include <stdio.h>
#include <math.h>

int izbaci_cifre (int* niz, int vel_niz, int* cifre, int vel_cifre)
{

	int i, j, temp1, izbaci=0, mjesto_cifre, negativan;

	for(i=0; i<vel_cifre; i++) {
		if(cifre[i]<0 || cifre[i]>9) return 0;
		for(j=i+1; j<vel_cifre; j++) {
			if(cifre[i]==cifre[j]) return 0;
		}
	}

	for(i=0; i<vel_niz; i++) {
		negativan=0;

		if(niz[i]<0) {
			negativan=1;
		}

		temp1=fabs(niz[i]);
		niz[i]=0;
		mjesto_cifre=0;

		while (temp1>0) {
			for(j=0; j<vel_cifre; j++) {
				izbaci=0;
				if((temp1%10) == cifre[j]) {
					izbaci=1;
					break;
				}
			}

			if(izbaci==0) {
				niz[i]+=(temp1%10)*pow(10, mjesto_cifre);
				mjesto_cifre++;
			}
			temp1/=10;
		}

		if(negativan) {
			niz[i]=0-niz[i];
		}
	}
	return 1;
}

int main()
{
	int brojevi[] = {54321, -54321};
	int cifre[] = {5,1};
	izbaci_cifre(brojevi, 2, cifre, 0);
	printf("%d %d\n", brojevi[0], brojevi[1]);
	izbaci_cifre(brojevi, 2, cifre, 2);
	printf("%d %d", brojevi[0], brojevi[1]);

	return 0;
}
