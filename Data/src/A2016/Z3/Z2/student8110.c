#include <stdio.h>
int suma (int n) {
    int s=0;
    if(n<0) n*=-1;
    while(n>0) {
        s+=n%10;
        n/=10;
    }
    return s;
}

void ubaci (int *niz, int vel) {
    int i=0,j=0,n=vel*2;
    for(j=1;j<n;j+=2) {
        for(i=vel++;i>j;i--)
            niz[i]=niz[i-1];
            niz[j]=suma(niz[j-1]);
    }
}

int fibonaci (int n) {
    int prvi=1,drugi=1,trenutni=0;
    while(1) {
        trenutni=prvi+drugi;
        if(trenutni>n) return 0;
        else if(trenutni==n) return 1;
        prvi=drugi;
        drugi=trenutni;
    }
}

int izbaci (int *niz, int vel) {
    int i=0,j=0;
    for(i=0;i<vel;i++)
        if(fibonaci(niz[i]) || niz[i]==1) {
            for(j=i--;j<vel-1;j++)
            niz[j]=niz[j+1];
            vel--;
        }
        return vel;
}

int main() {
    int i=0;
    int niz[20];
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz,10);
    int novavel=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0;i<novavel-1;i++)
    printf("%d, ",niz[i]);
    printf("%d.",niz[novavel-1]);
    return 0;
}