#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool DaLiJeProst(int broj)
{
    int i;
    for(i=2;i<broj;i++) {
        if(broj%i==0) { 
            return false; 
    }
    }
    if(broj==i) {
        return true;
    }
    return false;
}
int daj_prost ()
{
    static int prost=1;
    if (prost==1) {
        return ++prost;
    }
    else if (prost==2) {
        return ++prost;
    }
    else {
        prost+=2;
    while(!DaLiJeProst(prost))
    {
        prost +=2; }
        return prost; 
    }
}
int main()
{
    int a,b;
    do
    {
    printf("Unesite brojeve A i B:");
    scanf("%d %d",&a,&b);
    if(a<=0) {
        printf(" A nije prirodan broj.\n"); }
        else if(a>=b) {
            printf(" A nije manje od B.\n");
        }
    }
    while (a>=b || a<=0);
    int suma=0;
    int c=daj_prost();
    while (c<=a)
    {
        c=daj_prost();
    }
    if (c<b) {
        suma +=c;
        int d=daj_prost();
        while (d<b) 
        {
            suma +=d;
            d=daj_prost();
        }
    }
    printf(" Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
    return 0;
}