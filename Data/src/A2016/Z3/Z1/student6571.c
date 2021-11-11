#include <stdio.h>
#include <stdlib.h>

int daj_prost(){
    static int c=1;
    int i,prost;
   
    
    
    while(1){
        c++;
        prost=1;
    for(i=2; i<c; i++){
       
        if(c%i==0){
            prost=0;
            break;
         }
    }
    if(prost)
        break;
    }
        return c;
    
}



int main()
{

    int a, b, i, k,suma=0;


    do{
    printf("\nUnesite brojeve A i B: ");
    scanf("%d %d", &a, &b);
    
    if(a<=0 && a<b){
        printf("A nije prirodan broj.");
        continue;
    }
   
    if(a>=b){
        printf("A nije manje od B.");
        continue;
    }
        
    } while(a<=0 || a>=b);
    for(i=a+1;i<b;i++){
        k=daj_prost();
        if(k>a && k<b){
            suma=suma+k;

        }

    }

    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b, suma);



    return 0;
}