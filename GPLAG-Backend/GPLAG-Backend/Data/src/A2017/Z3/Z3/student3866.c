#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int izbaci (int br, int cif)
{
    int noviBR=0, dec=10;
    bool neg=false;

    if(br<0) {
        br*=-1;
        neg=true;
    }
    while (br) {
        if(br%10!=cif) {
            noviBR+=br%10*dec;
            dec*=10;
        }
        br/=10;
    }

    if(neg)
        noviBR*=-1;

    return noviBR/10;
}

bool izbaci_cifre(int n1[], int v1, int n2[], int v2)
{
    int i2, i1, j2;
    for (i2=0; i2<v2; i2++) {
        if(n2[i2]<0 || n2[i2]>9)
            return false;

        for (j2=0; j2<v2; j2++) {
            if(j2==i2) continue;
            if(n2[i2]==n2[j2])  return false;
        }
    }

    for(i2=0; i2<v2; i2++)
        for (i1=0; i1<v1; i1++)
            n1[i1]=izbaci(n1[i1], n2[i2]);

    return true;
}
int main ()
{
    return 0;
}