#include <stdio.h>

int daj_prost(){
    static int n=1;
    int i;
    n++;
     if(n==1)
     return 0;
     if(n==2)
     return n;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return n;
}
int main (){
    int a,b,i,suma=0,prost;
    do{
    printf("Unesite brojeve A i B: ");
    scanf("%d %d",&a,&b);
    if(a<=0){
    printf("A nije prirodan broj.\n");}
    if(a>=b){
    printf("A nije manje od B.\n");}
    }while(a>=b || a<=0);
    for(i=2;i<b;i++)
    {
        prost=daj_prost();
        //printf("%d",prost);
        if(prost>a && prost<b)
        suma=suma+prost;
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
    return 0;
}