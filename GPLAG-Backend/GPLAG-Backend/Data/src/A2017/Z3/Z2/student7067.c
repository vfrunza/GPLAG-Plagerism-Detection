#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int vel) {
    float *p=niz;
    while (p<niz+vel) {
        *p*=10;
        *p=round(*p);
        *p++/=10;
    }
}

int suma_cifara(double broj) {
    int tmp=fabs(broj);
    int suma=0;
    do {
        suma+=tmp%10;
        tmp/=10;
    } while (tmp!=0);
    suma+=(fabs(broj)-(int)(fabs(broj)))*10;
    return suma;
}

void preslozi(float *niz, int vel, int k) {
    int pocetak=0, i;
    float pomocni_niz[1000];
    zaokruzi1(niz,vel);
    for (i=0; i<vel; i++) {
        if (suma_cifara(niz[i])>=k) { 
            pomocni_niz[pocetak]=niz[i]; 
            pocetak++; }
    }
    for (i=0; i<vel; i++) {
        if (suma_cifara(niz[i])<k) { 
            pomocni_niz[pocetak]=niz[i]; 
            pocetak++; }
    }
    for (i=0; i<vel; i++) {
        niz[i]=pomocni_niz[i];
    }
}

int main() {
    int broj=22.3;
    printf ("%d %d", broj, suma_cifara(-122.3));
	return 0;
}