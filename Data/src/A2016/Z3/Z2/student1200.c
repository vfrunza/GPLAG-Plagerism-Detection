#include <stdio.h>
#include <stdlib.h>
void ubaci(int niz[],int vel)
{
	int i,x,suma=0,pomocna,cifra;
	x=vel-1;
	for(i=2*vel-2; i>=0; i-=2) {
		niz[i]=niz[x];
		pomocna=niz[i];
		pomocna=abs(pomocna);
		suma=0;
		while(pomocna!=0) {
			cifra=pomocna%10;
			suma+=cifra;
			pomocna/=10;
		}
		niz[i+1]=suma;
		x--;
	}
}
int izbaci(int niz[],int vel)
{
	int i,k,max,a,f;
	a=0;
	f=1;
	max=niz[0];
	for(i=0; i<vel; i++) {
		if(niz[i]>=max)max=niz[i];
	}
	while(f<=max) {
		f=a+f;
		a=f-a;
		for(i=0; i<vel; i++) {
			if(niz[i]==f) {
				for(k=i; k<vel-1; k++) {
					niz[k]=niz[k+1];
				}
				vel--;
				i--;
			}
		}
	}
	return vel;
}

int main()
{
	int i,vel=10;
	int niz[100];

	printf("Unesite niz od %d brojeva: ", vel);
	for(i=0; i<vel; i++) scanf("%d", &niz[i]);
	ubaci(niz,vel);
	vel=izbaci(niz,2*vel);
	printf("Modificirani niz glasi:");
	for(i=0; i<vel; i++) {
		if(i+1!=vel) printf(" %d,", niz[i]);
		else printf(" %d.", niz[i]);
	}
	return 0;
}
