#include <stdio.h>

int prost(int x) {
    int i;
    if(x==1) return 0;
    for(i=2;i<=x/2;i++) {
        if(x%i==0) return 0;
    }
    return 1;
}

int daj_prost() {
    static int n=2,k=0;
    while(2) {
        k=prost(n);
        n++;
        if(k==1) break;
    }
    return n-1;
}

int main() {
    int A,B,suma=0,k;	
    while(2) {
        printf("\nUnesite brojeve A i B:");
        scanf("%d%d", &A,&B);
        if(A<1)  printf(" A nije prirodan broj."); 
        if(A>=B) printf(" A nije manje od B.");
        else if(A>0 && B>0 && A<B) break;
    }

    for(;;) {
        k=daj_prost();
        if (k>A && k<B) {
            suma+=k;
        }
        else if(k>=B) break;
    } 
    printf(" Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
    return 0;
}
