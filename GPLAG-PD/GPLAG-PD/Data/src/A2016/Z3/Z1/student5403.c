#include <stdio.h>

int daj_prost()
{

    int i,tmp;
    static int a=1;
    a++;
    i=2;
    tmp=i;
    /*Petlja koja provjerava da li je broj prost*/
    for(i=2; i<a; i++) {
        if(a%i==0) {
            a++;
            i=tmp;
        }
    }
    return a;
}


int main()
{

    int A,B,prost,i,zbir=0;
    do {
        printf("Unesite brojeve A i B: ");
        scanf("%d %d", &A, &B);
        if(A>B || A==B)
            printf("A nije manje od B.\n");
        else if(A<=0)
            printf("A nije prirodan broj.\n");

    } while(A<=0 || B<=0 || A==B || A>B);

    /*Poziv funkcije i preskakanje broja koji je manji ili jednak unesenom broju A*/
    for(i=1; i<B; i++) {
        prost=daj_prost();
        if(prost<A || prost==A)
            continue;
        else if(prost<B)
            zbir+=prost;
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, zbir);
    return 0;
}
