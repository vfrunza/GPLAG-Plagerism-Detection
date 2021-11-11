#include <stdio.h>
#include <math.h>
void zaokruzi1 (float *niz, int n){
int i;
for(i=0;i<n;i++){
niz[i] *= 10;
niz[i] = round(niz[i]);
niz[i] /= 10;

} 
}
void preslozi(float *nizp, int n, int k){
	int cifra,suma,i,broj,m=0,g=0,negativan=0,f=0,w=0;
	float niz2[100],niz1[100];
	zaokruzi1(nizp,n);
	for(i=0;i<n;i++){
		negativan=0;
		if(nizp[i]<0) negativan=1;
		suma=0;
		nizp[i]=fabs(nizp[i]);
		broj=nizp[i]*10;
	while (broj!=0){
		cifra=broj%10;
		suma=suma+cifra;
		broj=broj/10;
	}
	if(suma>=k){
		if(negativan)
			niz1[m++]=(-1)*nizp[i];
		else niz1[m++]=nizp[i];
		
	}
	else {
		if(negativan)
			niz2[g++]=(-1)*nizp[i];
		else niz2[g++]=nizp[i];
	}
		negativan=0;
	}
	for(i=0;i<m;i++){
		nizp[w]=niz1[i];
		w++;	
		}
	
	f=w;
	for(i=0;i<g;i++){
	   	nizp[f]=niz2[i];
	    f++;
	}
	
	

}
int main() {

int i;
float niz[] = { -1.0, -0.1 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<2; i++)
    printf("%g ", niz[i]);

	return 0;
}
