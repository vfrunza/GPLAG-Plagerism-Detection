#include <stdio.h>


int izbaci_cifru(int broj, int cifra)
{
    int novi_broj=0;
    int k=1;
    int cifra_broja;
    int znak=1;

    if(broj<0) {
        broj*=-1;
        znak=-1;
    }
    while(broj!=0) {
        cifra_broja = broj%10;

        if(cifra_broja!=cifra) {
            novi_broj+=cifra_broja*k;
            k*=10;
        }
        broj/=10;

    }

    return znak*novi_broj;
}

int izbaci_cifre(int niz_brojeva[],int velicina_brojeva, int niz_cifara[],int velicina_cifara)
{
    int i,j;
    for ( i = 0; i < velicina_cifara; i++) {
        if(niz_cifara[i]<0 || niz_cifara[i]>9) return 0;
        for(j=0; j<i; j++) {
            if(niz_cifara[i]==niz_cifara[j]) return 0;
        }
    }


    for ( i = 0; i < velicina_brojeva; i++) {
        for (j= 0; j < velicina_cifara; j++) {
            niz_brojeva[i] = izbaci_cifru(niz_brojeva[i],niz_cifara[j]);
        }
    }
    return 1;
}

int main()
{
    int brojevi[]= {1234,12345,123456,1234567};
    int cifre[]= {2,5,6};
    int i;
    izbaci_cifre(brojevi,4,cifre,3);

    for ( i = 0; i < 4; i++) {
        printf("%d ",brojevi[i]);
    }
    return 0;
}
