#include <stdio.h>
#include <stdlib.h>


int daj_prost ()
{
    int i;
    static int br=1;
    br++;
    for(i=2; i<br; i++) {
        if(br%i==0) {
            br++;
            i=1;
        }
    }
    return br;
}


int main()
{
    int A,B, suma=0, n;
    do {
        printf("Unesite brojeve A i B: ");
        scanf("%d %d", &A, &B);
        if(A<=0) {
            printf("A nije prirodan broj.\n");
        } else if(A>=B) {
            printf("A nije manje od B.\n");
        }
    } while(A<=0 || A>=B);

    do {
        n=daj_prost();
        if(n<=A || n>=B) continue;
        suma+=n;
    } while (n<B);

    printf("Suma prostih brojeva izmedju %d i %d je %d.",A, B, suma);
    return 0;

}
