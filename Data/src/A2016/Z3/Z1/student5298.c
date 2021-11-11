#include <stdio.h>
#include <stdlib.h>

int daj_prost ()
{

    int n;
    static int prost=2;
    for(n=2;n<prost;n++){
        if(prost%n==0){
            prost++;
            n=2;
        }
        
    }
    return prost++;
}
    
int main()
{
    int a,b,n,suma=0;
    do{
        printf("Unesite brojeve A i B: ");
        scanf("%d%d",&a,&b);
        if(a<=0) printf("A nije prirodan broj.\n");
        else if (a>=b) printf("A nije manje od B.\n");
        else break;
    } while (a<=0 || a>=b);
    
    n=a+1;
    while (n<b){
        
        int prosti=daj_prost();
        while(prosti>n)
        n++;
        if(n>=b) break;
        if(prosti==n) suma+=prosti;
    }
      printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);

       
	return 0;
}
