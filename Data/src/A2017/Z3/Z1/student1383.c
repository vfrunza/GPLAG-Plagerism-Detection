#include <stdio.h>
#define d 10000

int ima(int *niz, int vel, int broj)
{
    int i;
    int x=0;
    for(i=0; i<vel; i++) {
        if(niz[i]==broj)
            x=1;;
    }
    return x;
}



int dva_od_tri (int *niz1, int n1, int *niz2, int n2, int *niz3, int n3)
{
    int brojac=0;
    int i,j;
    for(i=0; i<n1; i++) {
        if((ima(niz2,n2,niz1[i])==1 && ima(niz3,n3,niz1[i])==0) || (ima(niz2,n2,niz1[i])==0 && ima(niz3,n3,niz1[i])==1))
            brojac++;
        if(ima(niz1,n1,niz1[i])==1)
        brojac++;
    }

    for(j=0; j<n2; j++) {
        if(ima(niz3,n3,niz2[j])==1 && ima(niz1,n1,niz2[j])==0)
            brojac++;
    }

    return brojac;
}


int main()
{

    return 0;
}
