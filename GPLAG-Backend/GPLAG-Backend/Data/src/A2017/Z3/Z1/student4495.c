#include <stdio.h>

int dva_od_tri (int niz1[100], int v1, int niz2[100], int v2, int niz3[100], int v3)
{
    int brojac1[10000]= {0};
    int brojac2[10000]= {0};
    int brojac3[10000]= {0};
    int i,temp=0;
    /* Petljama postavi na svaki clan niza vrijednost 1*/
    for (i=0; i<v1; i++) {
        brojac1[niz1[i]]=1;
    }

    for (i=0; i<v2; i++) {
        brojac2[niz2[i]]=1;
    }

    for (i=0; i<v3; i++) {
        brojac3[niz3[i]]=1;
    }
    /*Provjeri da li se brojevi (iz intervala) pojavljuju u 2 od 3 niza*/
    for (i=0; i<10000; i++) {
        if (brojac1[i]+brojac2[i]+brojac3[i]==2) {
            temp++;
        }
    }
    return temp;
}

int main ()

{
    return 0;
}
