#include<stdio.h>
int daj_prost()
{
    static int i=1;
    int j;
    i++;
    for(j=2; j<i; j++) {
        if(i%j==0) {
            daj_prost();
        }
    }
    return i;
}

int main()
{
    int A,B,i,y,suma=0;
    do {
        printf("Unesite brojeve A i B:");
        scanf("%d %d",&A,&B);
        if(A<=0) {
            printf(" A nije prirodan broj.\n");
        }
        if(A>=B) {
            printf(" A nije manje od B.\n");
        }
    } while (A>=B || A<=0 || B<=0);

    for(i=1; i<B; i++) {
        y=daj_prost();
        if(y>A && y<B) {
            suma=suma +y ;
        }
    }
    printf(" Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
    return 0;
}
