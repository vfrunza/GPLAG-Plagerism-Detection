#include <stdio.h>
int modif(int broj) {
    int suma=0,cifra=0;
    int negativan=0;
    if(broj<0){ negativan=1; broj*=-1; } 
    while(broj!=0) {
        cifra=broj%10;
        suma+=cifra;
        broj/=10;
    }
    if(negativan==1) suma*=1;
    return suma;
}
void ubaci(int* niz, int vel) {
    int i,a=vel;
    vel=vel*2;

    for(i=0;i<a;i++) {
        niz[vel-i*2-2]=niz[vel/2-i-1];
    }
    for(i=0;i<vel;i++) {
        if(i%2!=0) {
            niz[i]=modif(niz[i-1]);
        }
    }
    return;
}

int izbaci(int* niz, int vel) {
    int i=0,j,k;
    int fibonaci[100];
    fibonaci[0]=1;
    fibonaci[1]=1;
    for(i=2;i<100;i++) {
        fibonaci[i]=fibonaci[i-1]+fibonaci[i-2];
    }
    
    for(i=0;i<100;i++) {
            for(j=0;j<vel;j++) {
                 if(fibonaci[i]==niz[j]) {
                        for(k=j;k<vel-1;k++)
                            niz[k]=niz[k+1];
                 vel--;
                 j--;
                 }

            }

    }
   return vel;
}


int main() {
	int niz[20];
	int i,novavelicina=0;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
	    scanf("%d",&niz[i]);
	}

	ubaci(niz,10);
    novavelicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<novavelicina;i++) {
	    if(i==novavelicina-1) printf("%d.",niz[i]);
	    else printf("%d, ",niz[i]);
	}
	return 0;
}
