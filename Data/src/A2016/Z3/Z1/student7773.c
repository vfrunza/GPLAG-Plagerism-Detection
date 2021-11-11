#include <stdio.h>

int daj_prost()
{
    int static prostibr=1;
    int i;
    int prost;
    prostibr++;
    for(;;prostibr++)
    {
        prost=1;
        for(i=2; i<prostibr; i++)
        {
            if(prostibr%i==0)
            {
                prost=0;
                break;
            }
        }
        if(prost==1)
        {
            return prostibr;
        }
    }
}

int main()
{
    int A,B,suma=0,i;
    int flag,j,tempi=0;

    do
    {
        printf("Unesite brojeve A i B: ");
        scanf("%d %d",&A,&B);
        if(A<1)
        {
            printf("A nije prirodan broj.\n");
            continue;
        }
        else if(A>B || A==B)
        {
            printf("A nije manje od B.\n");
            continue;
        }

    }
    while (A>B || A==B || A<1 || B<1);
    for(i=1; i<B; i++)
    {
        flag=1;
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1 && i!=1)
            tempi=daj_prost();
        if(i>A && flag==1)
        {
            suma=suma+tempi;
        }
    }

    printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
    return 0;
}