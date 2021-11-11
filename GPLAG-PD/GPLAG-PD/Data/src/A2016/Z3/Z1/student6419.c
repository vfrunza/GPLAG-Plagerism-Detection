#include <stdio.h>
int daj_prost() {
    static int prost=1;
    int i, kontrolna=1;
    while(kontrolna){
        prost++;
        if(prost==2) return prost;
        for(i=2; i<prost; i++) {
            if(prost%i==0){
                break;
                kontrolna=2;
            }
            if(i==prost-1){
                kontrolna = 0;
                return prost;
            }
        }
    }
}
int main() {
    int A, B, i, suma=0, temp=0;
    do {
        printf("Unesite brojeve A i B: ");
        scanf("%d%d", &A, &B);
        if(B<=A)
            printf("A nije manje od B.\n");
        else if(A<=0)
            printf("A nije prirodan broj.\n");
    }while(B<=A || B<=0 || A<=0);
    for(i=0; i<B; i++) {
            temp=daj_prost();
            if(temp>A && temp<B)
                suma+=temp;
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
    return 0;
}