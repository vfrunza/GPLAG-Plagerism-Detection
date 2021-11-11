#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kvadrat(long int n){
    long int t;
    t=sqrt(n);
    if(t*t==n) return 1;
    else return 0;
}
int fibonaci(long int n){
    if(n <= 0) return 0;
    if((kvadrat(5*n*n+4)==1) || (kvadrat(5*n*n-4)==1)) return 1;
    else return 0;
}
int izbaci(int niz[], int duzina) {
    int i=0, d=0, vrati=0;
    while (i<duzina){
        if(fibonaci(niz[i])==1){
            d=i+1;
            while(d<duzina){
                niz[d-1]=niz[d];
                d++;
            }
            d=0;
            i--;
            duzina--;
        }
        i++;
    }
    return duzina;
}
int suma_cifara(int n) {
    int cifra, suma=0;
    
    if(n < 0) n = -n;
    while (n!=0){
        cifra=n%10;
        suma+=cifra;
        n/=10;
    }
    return suma;
}
void ubaci (int niz[], int duzina){
    int d=0, i=0, k=duzina, temp = 0, j = 0;
    
    for(i = 0; i < duzina; i++)
    {
        temp = suma_cifara(niz[i]);
        
        for(j = duzina - 1; j > i; j--)
        {
            niz[j + 1] = niz[j];
        }
        i++;
        niz[i] = temp;
        duzina++;
    }
    
    
}
int main () {
    int niz[30];
    int i, t;
    printf("Unesite niz od 10 brojeva: ");
    
    for (i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz, 10);
    t=izbaci(niz, 20);
    
    printf("Modificirani niz glasi: ");
    for (i=0;i<t-1;i++) {
        printf("%d, ", niz[i]);
    }
    printf("%d.", niz[t-1]);
    return 0;
}