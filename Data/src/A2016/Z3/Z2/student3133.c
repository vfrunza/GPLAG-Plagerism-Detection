#include <stdio.h>
#include <stdlib.h>

int suma(int a) //funkcija za racunanje sume
{
    int s=0;
    if(a<0) a=abs(a);
    while(a>0) {
        s+=a%10;
        a/=10;
    }
    return s;
}

int fibonacci(int n) //ova funkcija provjerava da li je dati broj clan fibonaccija ili nije vracajuci 1 odnosno 0
{
    int broj1=1, broj2=1, broj3;
    if(n==1) return 1;
    for(;;) {
        broj3=broj1+broj2;
        if(n==broj3) return 1;
        if(broj3>n) break;
        broj1=broj2;
        broj2=broj3;
    }
    return 0;
}

void ubaci(int *niz, int n) //funkcija za ubacivanje
{
    int i, j, vel=2*n;
    for(i=1; i<vel; i+=2) {
        for(j=n++; j>i; j--) {
            niz[j]=niz[j-1]; //pomicanje elemenata
        }
        niz[i]=suma(niz[i-1]); //ubacivanje sume cifara na neparna mjesta niza
    }
}

int izbaci(int *niz, int n) //funkcija za izbacivanje
{
    int i, j;
    for(i=0; i<n; i++) {
        if(fibonacci(niz[i])) { //izbacivanje ce se desiti samo ako je niz[i] clan fibonaccija sto provjeravamo funkcijom
            for(j=i; j<n-1; j++) {
                niz[j]=niz[j+1];
            }
            n--;
            i--;
        }
    }
    return n;
}

int main()
{
    int niz[20], i, n=0;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
        n++;
    }
    ubaci(niz, n); //pozivanje funkcije ubaci
    n=izbaci(niz, 2*n); //pozivanje funkcije izbaci koja vraca duzinu niza koja se upisuje u n
    printf("Modificirani niz glasi: ");
    if(n==0) {
        printf("Prazan niz.");
        return 0;
    }
    for(i=0; i<n-1; i++) {
        printf("%d, ", niz[i]);
    }
    printf("%d.", niz[n-1]);
    return 0;
}