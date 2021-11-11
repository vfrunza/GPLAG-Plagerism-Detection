#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int n) {
	int i;
	for (i=0; i<n; i++) {
		*(niz+i)=round(*(niz+i)*10)/10;
	}
}

float preslozi(float *niz, int vel, int k) {
	float suma=0, niz2[100], niz3[100];
	int niz1[100], i, brojacA=0, brojacB=0;
	float temp;
	
	zaokruzi1(niz,vel);
	for (i=0; i<vel;i++) {
		niz1[i]=(int)(niz[i]*10);
}
for (i=0; i<vel; i++) {
	temp=niz1[i]/10.;
	suma=0;
	if (niz1[i]<0) 
	niz1[i]*=-1;
	while (niz1[i]>0)
	{
		suma+=niz1[i]%10;
		niz1[i]/=10;
	}
	if (suma>=k) {
		niz2[brojacA]=temp;
		brojacA++;
	}
	else {
		niz3[brojacB]=temp;
		brojacB++;
	}
}
for (i=0; i<brojacA; i++) {
	niz[i]=niz2[i];
}
for (i=brojacA; i<brojacB+brojacA; i++) {
	niz[i]=niz3[i-brojacA];
} 
return suma;
}
int main() {
	return 0;
}
