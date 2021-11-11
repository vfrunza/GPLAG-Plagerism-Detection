#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel)
{
    int i;
    for(i=0; i<vel; i++) {
        niz[i]=round(niz[i]*10)/10;
    }
}
void preslozi(float niz[], int vel, int x)
{
    zaokruzi1(niz, vel);
    int sume[100];
    int suma,i,a;
    for(i=0; i<vel; i++) {
        suma=0;
        if (niz[i]<0) suma=(niz[i]-(int)niz[i])*(-10);
        else suma=(niz[i]-(int)niz[i])*10;
        a=(int)niz[i];
        if (a<0) a=a*(-1);
        do {
            suma=suma+a%10;
            a=a/10;
        } while(a>0);
        sume[i]=suma;
    }
    int brojac1=0;
    float niz1[100];
    for(i=0; i<vel; i++) {
        if(sume[i]>=x) {
            niz1[brojac1]=niz[i];
            brojac1++;
        }
    }
    for(i=0; i<vel; i++) {
        if(sume[i]<x) {
            niz1[brojac1]=niz[i];
            brojac1++;
        }
    }
    for(i=0; i<vel; i++) {
        niz[i]=niz1[i];
    }
}

int main()
{

    return 0;
}
