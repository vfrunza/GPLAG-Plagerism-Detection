#include <stdio.h>
#include <stdlib.h>

int cifre(int broj)
{
	if(broj<0) broj*=-1;
	int suma=0;
	while(broj!=0) {
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}
void ubaci(int *niz,int vel)
{
	int niz1[10],niz2[10],mjesto1=0,mjesto2=0,i;
	for(i=0; i<vel; i++) {
		niz1[i]=niz[i];
		niz2[i]=cifre(niz[i]);
	}
	for(i=0; i<2*vel; i++) {
		if(i%2==0) {
			niz[i]=niz1[mjesto1];
			mjesto1++;
		} else {
			niz[i]=niz2[mjesto2];
			mjesto2++;
		}
	}
}

int izbaci(int *niz, int vel)
{
	int fibonaci[100];
	int i,j,l;
	fibonaci[0]=1;
	fibonaci[1]=1;
	for(i=2; i<100; i++)
		fibonaci[i]=fibonaci[i-1]+fibonaci[i-2];

	for(i=0; i<vel; i++) {
		for(j=0; j<100; j++) {
			if(niz[i]==fibonaci[j]) {
				for(l=i; l<vel-1; l++) {
					niz[l]=niz[l+1];
				}
				vel--;
				i--;
				break;
			}
		}
	}
	return vel;
}

int main()
{
	int vel=10,i;
	int niz[20];

	printf("Unesite niz od 10 brojeva: ",vel);
	for(i=0; i<10; i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,vel);
	vel=izbaci(niz,2*vel);

	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) {
		if(i+1!=vel) printf("%d, ",niz[i]);
		else printf("%d.",niz[i]);
	}

	return 0;
}
