#include <stdio.h>
#include <math.h>

int postoji(int niz_cifara[], int vel2, int broj)
{
    int i;
    for(i=0; i<vel2; i++)
        if(niz_cifara[i]==broj) return 1;
    return 0;
}

int obrnut(int n)
{
    int obr=0, pom;
    while(n!=0) {
        pom=n%10;
        n/=10;
        obr+=pom;
        obr*=10;
    }
    return obr/10;
}

int izbaci_cifre(int niz_brojeva[], int vel1, int niz_cifara[], int vel2)
{
    int i, j, tmp1, tmp2, tmp3;
    for(i=0; i<vel2; i++) {
        if(niz_cifara[i]<0 || niz_cifara[i]>9) return 0;
    }
    for(i=0; i<vel2; i++) {
        for(j=i+1; j<vel2; j++) {
            if(niz_cifara[i]==niz_cifara[j]) return 0;
        }
    }
    for(i=0; i<vel1; i++) {
        tmp1=fabs(niz_brojeva[i]);
        tmp3=0;
        while(tmp1!=0) {
            tmp2=tmp1%10;
            tmp1/=10;
            if(postoji(niz_cifara, vel2, tmp2)) continue;
            else {
                tmp3+=tmp2;
                tmp3*=10;
            }
        }
        tmp3=obrnut(tmp3);
        if(niz_brojeva[i]<0) niz_brojeva[i]=tmp3*(-1);
        else niz_brojeva[i]=tmp3;
    }
    return 1;
}

int main()
{
    /*	printf("Zadaća 3, Zadatak 3");*/
    return 0;
}
