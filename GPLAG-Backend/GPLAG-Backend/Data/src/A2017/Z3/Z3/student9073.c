#include <stdio.h>

int izbaci_cifre(int niz[], int vel1, int cifre[], int vel2)
{
    int i,j,brojac_cifara;
    for(i=0; i<vel2; i++) {
        if (cifre[i]>9 || cifre[i]<0) return 0;
    }
    for(i=0; i<vel2; i++) {
        brojac_cifara=0;
        for(j=0; j<vel2; j++) {
            if (cifre[i]==cifre[j]) brojac_cifara++;
        }
        if(brojac_cifara>1) return 0;
    }
    int novi_broj,ostatak,temp,desetica,brojac;
    for(i=0; i<vel1; i++) {
        novi_broj=0;
        if (niz[i]>=0) temp=niz[i];
        else temp=-niz[i];
        desetica=1;
        do {
            ostatak=temp%10;
            brojac=0;
            for (j=0; j<vel2; j++) {
                if (ostatak!=cifre[j]) brojac++;
            }
            if(brojac==vel2) {
                novi_broj=novi_broj+ostatak*desetica;
                desetica=desetica*10;
            }
            temp=temp/10;
        } while (temp>0);
        if (niz[i]<0) niz[i]=-novi_broj;
        else niz[i]=novi_broj;
    }
    return 1;
}

int main()
{

    return 0;
}
