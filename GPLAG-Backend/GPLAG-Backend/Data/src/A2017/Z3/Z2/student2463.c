#include <stdio.h>
#include <math.h>

void zaokruzi1(double *niz, int vel){
    double *p=niz;
    while(p<niz+vel){
        *p*=10;
        *p=round(*p);
        *p/=10;
        p++;
    }
}
void preslozi(double niz[], int vel, int k){
	int suma_c=0, i, x1, x2;
	
	for(i=0; i<vel; i++){
	x1=niz[i]*10;
	x2=x1%10;
	suma+=x2;
	x3=(int)x1/10;
	}
	
}

int main() {
	
	double niz[100];
	int k, vel=0, i, j;
	
	printf("Koliko realnih brojeva cete unijeti: ");
	do{
		scanf("%d", &vel);
	} while(vel<1 || vel>100);
	
	printf("Unesite elemente niza: ");
	for(i=0, i<vel; i++){
	    scanf("%lf", &niz[i]);
	}
	do{
    printf("Unesite prirodan broj k: ");
    scanf("%d", &k);
	} while(k<1);
	
	printf("Niz glasi: ");
	for(i=0; i<vel; i++){
	    printf("%lf ", preslozi(niz, vel, k));
	}
	
	return 0;
}
