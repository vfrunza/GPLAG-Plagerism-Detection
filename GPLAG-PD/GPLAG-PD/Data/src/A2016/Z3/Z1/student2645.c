#include <stdio.h>

int daj_prost() {
    int i;
    static int a=1;
    a++;
    
    for(i=2; i<a; i++) {
        if(a%i==0) {
            a=a+1;
            i=2;
        }
    }
    if(i==a) return a;
    
}

int main() {
    
    int A, B, suma=0, d;
    for(;;) {
        printf("Unesite brojeve A i B: ");
        scanf("%d %d", &A, &B);
        if(A>=B) {
            printf("A nije manje od B.\n");
            continue;
        }
        else if(A<=0) {
            printf("A nije prirodan broj.\n");
            continue;
        }
        else if(B<=0) {
            printf("B nije prirodan broj.\n");
            continue;
        }
        else {
            for(;;){
               d = daj_prost();
               if(d>A && d<B){
                   suma = suma + d;
               }
               if(d>B)
                break;
            }
            break;
        }
    
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
return 0;
}