#include <stdio.h>

int daj_prost(){
    static int i=1;
    int j, prost=0;
    while(prost != 1){
            
       i++;
       prost=1;
       for(j=2;j<i;j++){
           if( i%j==0){
               prost=0;
           }
       }
    }
    return i;
}

int main() {
    int a,b, suma=0, i,prostBroj;
    
    do{
    printf("Unesite brojeve A i B: ");
    scanf("%d %d", &a, &b);
    if (a<=0) printf("A nije prirodan broj.\n");
    else if (a==b || a>b) printf ("A nije manje od B.\n");
    }
    while(a<=0 || b<=0 || a>b || a==b);
    
    prostBroj=daj_prost();
    while(prostBroj<b){
        
        if(prostBroj>a && prostBroj<b){
        suma=suma+prostBroj;
        }
        prostBroj=daj_prost();
    }
    
    printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
