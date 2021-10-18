#include <stdio.h>
#include <stdlib.h>
int suma_cifara (int n)
{
    int suma=0, cifra;
    n=abs(n);
    while(n!=0) {
        cifra=n%10;
        suma=suma+cifra;
        n=n/10;
    }
    return suma;
}
void ubaci (int *niz, int vel)
{
    int i, j;
    for(i=0; i<vel; i++) {
        for (j=vel-1; j>i; j--) {
            niz[j+1]=niz[j];
        }
        niz[i+1]=suma_cifara(niz[i]);
        vel++;
        i++;
    }
}
int fibonaci (int n)
{
    int br1=1, br2=1;
    while (br1 < n && br2 <n) {
        br1=br1+br2;
        br2=br2+br1;
    }
    if (br1==n || br2==n)
        return 1;
    return 0;
}

int izbaci (int *niz, int vel)
{
    int i, j;
    for (i=0; i<vel; i++) {
        if(fibonaci(niz[i])==1) {
            for (j=i; j<vel-1; j++) {
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
}

int main()
{
    int vel=10, niz[20], i;
    printf("Unesite niz od 10 brojeva: ");
    for (i=0; i<vel; i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz, vel);
    vel= vel*2;
    vel=izbaci(niz, vel);
    printf("Modificirani niz glasi: ");
    for (i=0; i<vel; i++) {
        if (i==vel-1)
            printf("%d.", niz[i]);
        else
            printf("%d, ", niz[i]);
    }
    return 0;
}