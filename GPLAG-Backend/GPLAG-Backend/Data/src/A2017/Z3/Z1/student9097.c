#include <stdio.h>

int dva_od_tri (int A[], int a, int B[], int b, int C[], int c)
{
    int i,j;
    int brojac=0,dubl=0,pon=0,rezultat=0;

    for (i=0; i<a; i++) {
        dubl=0;
        brojac=1;
        for (j=0; j<i; j++) {
            if (A[i]==A[j])
                dubl=1;
        }
        if (dubl==0) {
            for (j=0; j<b; j++) {
                if (A[i]==B[j]) {
                    brojac++;
                    break;
                }
            }
            for (j=0; j<c; j++) {
                if (A[i]==C[j]) {
                    brojac++;
                    break;

                }
            }
            if (brojac==2) {
                rezultat++;
            }
        } else continue;
    }
    dubl=0;
    for (i=0; i<b; i++) {
        brojac=1;
        int pon=0;
        for (j=0; j<i; j++) {
            if (B[i]==B[j])
                dubl=1;
        }
        if (dubl==0) {
            for (j=0; j<a; j++) {
                if(B[i]==A[j]) {
                    pon=1;
                }
            }

            if (pon==0) {
                for (j=0; j<c; j++) {
                    if (B[i]==C[j]) {
                        brojac++;
                        break;
                    }
                }
                if (brojac==2) {
                    rezultat++;
                }
            } else continue;
        } else continue;
    }
    return rezultat;

}
int main ()
{
    return 0;

}
