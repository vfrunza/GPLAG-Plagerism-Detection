#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.00001

void zaokruzi1(float *p, int x) {
    int i,broj;
     for (i=0;i<x;i++) {
        p[i]*=10;
        if(p[i]>0)
            p[i]+=0.5;
        else
            p[i]-=0.5;
        broj=p[i];
        p[i]=(float)broj/10;
    }
}
void preslozi(float *pok,int x,int k) {
    float *pokk=pok;
    float temp;
    int i,j,b;
    int indeks=0,suma=0;
    zaokruzi1(pok,x);
    for(i=0;i<x;i++) {
        b=pokk[i]*10;
        suma=0;
        while(b!=0) {
            suma+=abs(b%10);
            b/=10;
        }
        if (suma>=k) {
            temp = pokk[i];
            for(j=i;j>indeks;j--) {
                pokk[j]=pokk[j-1]; 
            }
            pokk[indeks]=temp;  
            indeks++;
        }
    }
}
int main() {
    int i,k,vel;
    double niz[100];
    printf("Unesite niz realnih brojeva: ");
    for (i=0;i<100;i++) {
        scanf("%lf", &niz[i]);
        if (niz[i]==-1) break;
    }
    printf("Unesite broj k: ");
    scanf("%d", &k);
	vel=i;
	zaokruzi1(niz,vel);
	preslozi(niz,vel,k);
	printf("Niz glasi: ");
	for (i=0;i<vel;i++) {
	    printf("%.1f ", niz[i]);
	}
	return 0;
}
