#include <stdio.h>
#include <stdlib.h>
void ubaci(int niz[], int velicina)
{
int j;
int y = (velicina*2)-2;
int suma,x;
for(j=velicina-1; j>=0; j--) {
    niz[y] = niz[j];
    y = y-2;
    }
    for(j=0; j<velicina*2; j=j+2) {
        suma = 0;
        x = abs(niz[j]);
        do {
            suma = suma + x%10;
            x/=10;
        }
        while(x>0);
        niz[j+1] = suma;
    } 
    }
int izbaci(int niz[], int velicina) {
    int k, j, a, b, c;
    for(k=0; k<velicina; k++) {
        a = 1;
        b = 1;
        c = 1;
        while(a<niz[k]) {
            a = b + c;
            c = b;
            b = a;
        }
        if(a==niz[k]) {
            for(j=k; j<velicina-1; j++) {
                niz[j] = niz[j+1];
            }
            velicina--;
            k--;
        }
    }
    return velicina;
}
int main()
{
    int k,l;
    int niz[20];
    printf("Unesite niz od 10 brojeva: ");
    for(k=0; k<10; k++) {
    scanf ("%d",&niz[k]);}
    ubaci(niz,10);
    int kraj;
    kraj = izbaci(niz,20);
    if(kraj==0) {
        printf("Prazan niz");
        return 0;
    }
    printf("Modificirani niz glasi:");
    for(l=0; l<kraj; l++) {
        if(l>=0 && l<kraj-1) {
            printf(" %d,", niz[l]); 
        } else { 
            printf(" %d.", niz[l]);
    }
    }
    return 0;
}
