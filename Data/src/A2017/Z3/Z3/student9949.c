#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz_brojeva, int vel1, int *niz_cifara, int vel2)
{
	int i, j, cifra, p, novi_broj, k, brojac=0, negativan=1;
	int brojaci[10]= {0};


	for(i=0; i<vel2; i++) {
		if(niz_cifara[i]<0 || niz_cifara[i]>9) return 0;
		brojaci[niz_cifara[i]]++;
		/* provjeravamo da li se neki clan niza javlja 2 ili vise puta */
		if(brojaci[niz_cifara[i]]>1) return 0;
	}

	for(i=0; i<vel1; i++) {
		if(niz_brojeva[i]<0) {
			negativan=1;
		} else {
			negativan=0;
		}
		p=fabs(niz_brojeva[i]);
		novi_broj=0;
		k=1;

		/* izdvajanje cifara clanova niza */
		while(p!=0) {
			brojac=0;
			cifra=p%10;
			p/=10;
			for(j=0; j<vel2; j++) {
				/* cifre nekog clana niza_cijelih koje se nalaze u nizu_cifara se izbacuju */
				if(cifra==niz_cifara[j]) {
					cifra=0;
					novi_broj+=cifra;
					break;
				} else if(cifra!=niz_cifara[j]) {
					brojac++;
				}
			}
			/* cifre nekog clana niza_cijelih koje nisu pronadene u nizu_cifara formiraju novi broj */
			if(brojac==vel2) {
				novi_broj=novi_broj+cifra*k;
				k*=10;
			}
		}
		if(negativan) {
			niz_brojeva[i]=-1*novi_broj;
		} else niz_brojeva[i]=novi_broj;
	}
	return 1;
}

int main()
{

	return 0;
}
