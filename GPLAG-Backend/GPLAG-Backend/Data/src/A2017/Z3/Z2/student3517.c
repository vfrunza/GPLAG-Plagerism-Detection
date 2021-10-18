#include <stdio.h>
#include<math.h>
#define DUZINA 200

float *zaokruzi1(float *niz, int vel)
{

	float *p=niz;
	while(p<niz+vel) {
		*p*=10;
		if(*p>0)
			*p=(int)(*p+0.5);
		if(*p<0)
			*p=(int)(*p-0.5);
		*p++/= 10;
	}
	return niz;
}

void preslozi(float niz[], int vel, int k)
{
	int i, suma=0, j, l, clan, cifra, brojac=0;
	float novi, temp;
	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		novi=niz[i];
		novi=novi*10;
		clan=(int)novi;
		if(clan<0)
			clan=-clan;
		suma=0;
		/*racuna sumu svih cifara u clanu*/
		while(clan!=0) {
			cifra=clan%10;
			suma+=cifra;
			clan/=10;
		}/*sortiranje elemenata gdje brojevi za koje je ispunjen uslov idu naprijed, ali im redosljed ostaje isti*/
		if(suma>=k) {
			for(j=i; j>brojac; j--) {
				for(l=j; l>=j; l--) {
					temp=niz[j-1];
					niz[j-1]=niz[l];
					niz[l]=temp;
				}
			}
			brojac++;
		}
	}
}

int main()
{

	float niz[DUZINA];
	int i, n, k;

	printf("Unesite velicinu: ");
	scanf("%d", &n);

	printf("Niz:");
	for(i=0; i<n; i++)
		scanf("%f", &niz[i]);

	printf("k:");
	scanf("%d", &k);

	preslozi(niz,n,k);

	return 0;
}
