#include <stdio.h>

int SaberiCifre(int n){
    int cifra, suma=0;
    while(n!=0) {
        cifra=n%10;
        suma+=cifra;
        n/=10;
    }
    return suma;
}

void ubaci(int *niz, int vel){
    int i;
    for(i=vel-1; i>=0; i--) {
        niz[i*2+1]=SaberiCifre(niz[i]);
        niz[i*2]=niz[i];
    }
}

int main(){
    int niz[20], i;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz, 10);
    for(i=0; i<20; i++) printf("%d ", niz[i]);
    
    return 0;
}