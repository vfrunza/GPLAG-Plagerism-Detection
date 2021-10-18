#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Prima i-ti element jednog niza i provjerava da li se on javlja u drugom nizu */
int provjera(int a,int niz[],int n)
{
    int i;
    for(i=0; i<n; i++) {
        if(a==niz[i])
            return 1;
        else continue;
    }
    return 0;
}

int dva_od_tri(int niz1[], const int n1,int niz2[],const int n2,int niz3[], const int n3)
{
    int i,j,uracunat=0;
    int brojac=0; /* Brojac koji je ujedno i finalni rezultat */

    for(i=0; i<n1; i++) {
        /* Da li je vec uracunat */
        for(j=0; j<i; j++) {
            if(niz1[i]==niz1[j]) {
                uracunat=1;
                break;
            } else uracunat=0;
        }

        if(!uracunat) {
            /* Da li se i-ti element prvog niza javlja u drugom nizu */
            if (provjera(niz1[i],niz2,n2)) {
                brojac++;
                /* Ako se javlja, da li se javlja i u trecem */
                if(provjera(niz1[i],niz3,n3))
                    brojac--;
            }

            /* Ako se ne javlja u drugom nizu, da li se javlja u trecem */
            else if(provjera(niz1[i],niz3,n3))
                brojac++;
        }

        else continue;
    }

    uracunat=0;

    /* Da li se i-ti element drugog niza javlja u trecem a da pri tome nije uzet u obzir kod prvog ispitivanja */
    for(i=0; i<n2; i++) {
        /* Da li je element vec uracunat */
        for(j=0; j<i; j++) {
            if(niz2[i]==niz2[j]) {
                uracunat=1;
                break;
            } else uracunat=0;
        }

        if(!uracunat) {
            if(provjera(niz2[j],niz3,n3) && !provjera(niz2[j],niz1,n1))
                brojac++;
        }

        else continue;
    }

    return brojac;
}

int main()
{
    int niz1[] = {0,1,3,1,0,0,4,5,6,1,2,255,100,56000,23,10,4,5,1,560341};
    int niz2[] = {1,0,3,4,6,7,8,56000,21,22,2147483647};
    int niz3[] = {3,2,5,9,10,100,99,22,560341,2147483647};

    int n1=sizeof niz1/sizeof niz1[0];
    int n2=sizeof niz2/sizeof niz3[0];
    int n3=sizeof niz3/sizeof niz3[0];

    printf("%d\n", dva_od_tri(niz1, n1, niz2, n2, niz3, n3));
    printf("%d\n", dva_od_tri(niz3, n3, niz1, n1, niz3, n3));
    printf("%d", dva_od_tri(niz2, n2, niz2, n2, niz1, n1)); 
    return 0;
}
