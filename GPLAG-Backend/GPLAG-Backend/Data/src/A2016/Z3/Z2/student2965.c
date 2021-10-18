#include <stdio.h>
#include <stdlib.h>
void ubaci(int *niz, int vel) {
    int i,m=0,broj=0,suma=0,nizN[20]={0};
    for(i=0; i<vel; i++) {
        nizN[i]=niz[i];
    }
    for(i=0; i<=vel-1; i++) {
        niz[2*i]=nizN[i];
    }
    for(i=0; i<vel; i++) {
        m=niz[2*i];
        suma=0;
        /* Da nam suma ne bi bila negativna, uzimamo apsolutne vrijednosti elemanata niza*/
        if(m<0) {
            m=abs(m);
        }
        while(m!=0) {
            broj=m%10;
            suma=suma+broj;
            m=m/10;
        }
        niz[2*i+1]=suma;
    }
}
int fibonacci(int n) {  
    int x,y,z;
    if(n<0) return 0;
    x=1,y=1,z=0;
    if(n==x|| n==y) return 1;
    z=x+y;
    while(z<=n) {
        if(z==n) return 1;
        x=y;
        y=z;
        z=x+y;
    }
    return 0;
}
int izbaci(int *niz, int vel) {
    /*Ako brojevi jesu Fibonacijevi, onda cemo njih izbaciti*/
    int i,j;
    for(i=0; i<vel; i++) {
        if (fibonacci(niz[i])) {
            for(j=i; j<vel-1; j++) {
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
}
int main() {
    int i,f,niz[20];
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d",&niz[i]);
    }
    ubaci(niz,10);
    f=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<f ;i++) {
        /* f je ova promijenjena velicina niza */
        /*Uslov i<(f-1) da bi se ispisivao zarez do zadnjeg, poslije zadnjeg tacku */
        if(i<(f-1)) {
            printf("%d, ",niz[i]);
        } else {
            printf("%d.",niz[i]);
        }
    }
    return 0;
}
    
    
