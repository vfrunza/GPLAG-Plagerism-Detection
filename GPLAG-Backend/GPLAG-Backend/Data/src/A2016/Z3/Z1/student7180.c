#include <stdio.h>
#include <stdbool.h>

int daj_prost()
{
    static int a=2;
    int i=2;
    bool prost=true;
    for(i; i<a; i++)
    {
        if(a%i==0) 
        {
        prost=false;
        break;
        }
    }
    
    while(!prost)
    {
        a++;
        int j=2;
        for(j;j<a;j++)
        {
            if(a%j==0)
            {
                prost=false;
                break;
            }
            prost=true;
        }
    }
    return a++;
    
}

int main() {
    int a=0;
    int b=0;
    int i;
    int suma=0;
    int x;
    while(a<=0 || b<=0 || a>=b)
    {
        printf("Unesite brojeve A i B: ");
        scanf("%d %d", &a, &b);
        if(a<=0) printf("A nije prirodan broj.\n");
        if(a>=b) printf("A nije manje od B.\n");
    }
    x=daj_prost();
    if(x<a){
    while(x<a)
    {
        x=daj_prost();
    }
    }
    int c=b-a-1;
    if(x>a && x<b)
        suma=suma+x;
    for(i=0; i<c; i++)
    {
        x=daj_prost();
        if(x>a && x<b)
        suma+=x;
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
return 0;
}
