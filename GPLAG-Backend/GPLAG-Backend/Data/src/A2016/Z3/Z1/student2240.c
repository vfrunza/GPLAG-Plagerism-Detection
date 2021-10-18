#include <stdio.h>
#include <stdlib.h>

int prost(int n){
    int i;
    for(i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int daj_prost(){
    static int var=2;
    while(1){
        if(prost(var)==1) return var++;
        else var++;
    }
}
int main() {
    int A,B,var,suma=0;
    do {
        printf ("Unesite brojeve A i B: ");
        scanf ("%d %d", &A, &B);
        if(A<=0) printf("A nije prirodan broj.\n");
        if(A>=B) printf("A nije manje od B.\n");
    } while(A>=B || A<=0);
     var=daj_prost();
     while(var<B) {
         if(var>A && var<B) suma+=var;
         var=daj_prost();
     }
     printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
     return 0;
    
}
