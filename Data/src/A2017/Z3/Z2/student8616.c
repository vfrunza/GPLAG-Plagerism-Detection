#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

void zaokruzi1(float *niz, int brojel){
	float *p=niz;
	while (p<niz + brojel){
		*p *=10;
		*p=round(*p);
		*p=(float) *p/10;
		p++;
	}
}
void preslozi(float *niz, int brojel, int k){
	int i,j, Suma=0, l=0, niz2[100];
	float zamjena[100];
	zaokruzi1(niz, brojel);
	for(i=0; i<brojel; i++){
		niz2[i]=fabs( niz[i]*10);
		while(niz2[i]!=0){
			Suma=Suma+niz2[i]%10;
			niz2[i]=niz2[i]/10;
		}
		if(Suma>=k){
			zamjena[l]=niz[l];
			niz[l]=niz[i];
			for(j=l+1; j<=i; j++){
			zamjena[j]=niz[j];
			niz[j]=zamjena[j-1];
			}
			l++;
		}
		Suma=0;
	}
}				
int main() {
	float niz[100];
	int i,k, brojel=0;
	printf("Unesi clanove niza: ");
	for(i=0; i<100; i++){
		scanf("%f", &niz[i]);
		if(fabs(niz[i]+1)<EPSILON) break;
		brojel++;
	}
	printf("Unesite vrijednost k: ");
	scanf("%d", &k);
	preslozi(niz,brojel,k);
	printf("Niz glasi: ");
	for(i=0; i<brojel; i++){
		printf("%g ", niz[i]);
	}
	return 0;
}
