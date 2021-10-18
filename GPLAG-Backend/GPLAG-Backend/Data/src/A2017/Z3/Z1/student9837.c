#include <stdio.h>

int dva_od_tri (int [],int, int[],int, int[],int);
int main()
{

    int niz1 []= {1,2,3,5};
    int niz2 []= {1,2,4,6,7};
    int niz3 []= {1,3,4,8,9,10};

    int rez = dva_od_tri(niz1, 4, niz2,5, niz3,6);
    printf ("%d", rez);

    return 0;

}

int dva_od_tri (int niz1[],int brojacn1, int niz2[],int brojacn2, int niz3[],int brojacn3)
{

    int noviNiz[20];
    int brojac=0;
    int index=0;
    int i, j,p,q;
    //provjera za 1 i 2 niz
    for (i=0; i<brojacn1; i++) {
        for (j=0; j<brojacn2; j++) {
            if (niz1[i]==niz2[j]) {
                index=niz2[j];

                noviNiz[brojac]=index;

                brojac++;
            }
        }
    }


    index=0;
    int m,n;
    //provjera za 2 i 3 niz
    for (m=0; m<brojacn2; m++) {
        for (n=0; n<brojacn3; n++) {
            if(niz2[m]==niz3[n]) {
                index=niz3[n];

                noviNiz[brojac]=index;

                brojac++;
            }
        }

    }

    index=0;

    //provjera za 1 i 3 niz
    for (p=0; p<brojacn1; p++) {
        for (q=0; q<brojacn3; q++) {
            if (niz1[p]==niz3[q]) {
                index=niz3[q];

                noviNiz[brojac]=index;

                brojac++;
            }
        }
    }

    int isti = 0;
    int k, s, f;

    //provjera za moj novi niz i izbacivanje nepotrebnih elemenata
    for (k=0; k<brojac; k++) {
        isti=0;
        for (s=0; s<brojac; s++) {
            if (k==s)
                continue;

            if (noviNiz[k]==noviNiz[s]) {
                noviNiz[s]='/0';
                isti=1;
            }

        }

        if (isti==1)
            noviNiz[k]='/0';

    }

    int konBroj=0;
    
    
    
    for (f=0; f<brojac; f++) {

        if (noviNiz[f]!='/0') {
            konBroj++;
        }
    }

    return  konBroj ;

}
