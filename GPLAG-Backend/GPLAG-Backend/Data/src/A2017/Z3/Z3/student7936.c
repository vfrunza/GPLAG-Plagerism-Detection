#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
    int i,j,k,broj,y;
    int ekv=0,minus=0;
    int niz3[10], vel3;
    for (i=0; i<vel2; i++) {
        if (niz2[i]<0 || niz2[i]>9) return 0;
        for (j=0; j<i; j++) {
            if (niz2[i]==niz2[j]) return 0;
        }
    }

    for (i=0; i<vel1; i++) {
        minus=0;
        broj=niz1[i];
        if (broj<0) {
            broj=-broj;
            minus=1;
        }
        for (j=0; j<10; j++) niz3[j]=0;
        vel3=0;
        while (broj>0) {
            niz3[vel3++]=broj%10;
            broj=broj/10;
        }
        for (j=0; j<vel3; j++) {
            ekv=0;
            for (k=0; k<vel2; k++) {
                if (niz3[j]==niz2[k]) {
                    ekv=1;
                    break;
                }
            }
            if (ekv==1) {
                for (k=j; k<vel3-1; k++) {
                    niz3[k]=niz3[k+1];
                }
                vel3--;
                j--;
            }
        }
        y=0;
        for (j=0; j<vel3; j++) {
            y+= (niz3[j]*pow(10,j));
        }
        if (minus==1) y=-y;
        niz1[i]=y;
    }
    return 1;
}

int main ()
{
    return 0;
}
