#include <stdio.h>
int prost (int x) {
    int i=0;
    for (i=2;i<=x/2;i++)
    if(x%i==0) return 0;
    return 1;
}
int daj_prost() {
    static int n=2;
    while (!prost(n++));
    return n-1;
}

int main () {
    int A=0,B=0,suma=0,x=0,i=0;
    do {
    printf("Unesite brojeve A i B: ");
    scanf("%d %d",&A,&B);
    if(A<=0) {
        printf("A nije prirodan broj.\n"); 
    }
    else if(A>=B) {
        printf("A nije manje od B.\n");
    }
    else break;
    } while (A<=0 || B<=0 || A>=B);
    for(;;) {
        x=daj_prost();
        if(x>=B) break;
        if(x<B && x>A) {
            suma+=x;
        }
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
    return 0;
}
