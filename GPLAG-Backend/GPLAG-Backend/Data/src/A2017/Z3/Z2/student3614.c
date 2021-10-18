#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz, int velicina)
{
    int i;

    for(i=0; i<velicina; i++) {
        niz[i]*=10;
        niz[i]=round(niz[i]);
        niz[i]/=10;
    }
}
void preslozi (float *niz, int velicina, int k)
{
    int i;
    float niz1[100], niz2[100], niz3[100];
    int cifra,suma=0, pom;
    int br1=0, br2=0;
    zaokruzi1(niz,velicina);
    for (i=0; i<velicina; i++) {
        suma=0;
        pom=fabs(niz[i]*10);
        while (pom!=0) {
            cifra=pom%10;
            suma=suma+cifra;
            pom=pom/10;
        }
        if (suma>=k) {
            niz1[br1]=niz[i];
            br1++;
        } else if (suma<k) {
            niz2[br2]=niz[i];
            br2++;
        }
    }
    for (i=0; i<velicina; i++) {
        if (i<br1) {
            niz3[i]=niz1[i];
        } else {
            niz3[i]=niz2[i-br1];
        }
    }
    for (i=0; i<velicina; i++) {
        niz[i]=niz3[i];
    }

}

int main()
{
    int i, velicina;
    int k=14;
    float niz[1000];
    scanf ("%d", &velicina);
    preslozi(niz,velicina,k);
    for (i=0; i<velicina; i++) {
        printf ("%f", niz[i]);
    }


    return 0;
}
