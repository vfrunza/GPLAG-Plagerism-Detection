#include <stdio.h>
#include <stdbool.h>

int saberi(int broj)
{
    int x=0, zbir=0;
    while(broj!=0) {
        x=broj%10;
        zbir+=x;
        broj/=10;
    }

    if(zbir<0) zbir*=-1;
    return zbir;
}

void ubaci(int niz[], int vel)
{
    int pomocna[100000];
    int i;
    for(i=0; i<vel; i++) {
        pomocna[i]=niz[i];
    }
    for(i=0; i<2*vel; i+=2) {
        niz[i]=pomocna[i/2];
    }
    for(i=1; i<2*vel; i+=2) {
        niz[i]=saberi(niz[i-1]);
    }
}
int maksimalni (int niz[], int vel)
{
    int i, maks=niz[0];
    for (i=0;i<vel;i++)
    if (niz[i]>maks) maks=niz[i];
    return maks;
}
bool Fibonacijev_niz(int x, int niz[], int vel)
{
    int fib[100000];
    int j;
    int i=2;
    fib[0]=1;
    fib[1]=1;
    while (1) {
        fib[i]=fib[i-1]+fib[i-2];
        if (fib[i]>maksimalni(niz,vel)) break;
        i++;
    }
    for (j=0; j<i; j++) {
        if (x==fib[j]) return true;
    }
    return false;
    
}

int izbaci(int niz[], int vel) {
    int i;
    int j;
    
    for(i=0; i<vel; i++) {
        if(Fibonacijev_niz(niz[i],niz,vel) == true) {
            for(j=i; j<vel-1; j++) {
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
}

int main () {
    int niz[20], vel=10, i, a;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<vel; i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz, vel);
    a=izbaci(niz, vel*2);
    printf("Modificirani niz glasi: ");
    for(i=0; i<a; i++) {
        if(i!=a-1)printf("%d, ", niz[i]);
        else printf("%d.", niz[i]);
    }
    return 0;
}
    
