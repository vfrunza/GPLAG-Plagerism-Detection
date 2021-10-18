#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ubaci(int *niz, int vel)
{
    int i, suma=0, temp=2*vel-2, x_razlaganje;
    for(i=vel-1 ; i>=1; i--) {                                          //Pravljenje praznih mjesta poslije svakog clana niza
        niz[temp]=niz[i];
        temp-=2;
    }
    for(i=1; i<2*vel; i+=2) {                                           //Razlaganje broja na cifre i ubacivanje sume cifara u niz
        suma=0;
        x_razlaganje=abs(niz[i-1]);
        do {
            suma+=x_razlaganje%10;
            x_razlaganje/=10;
        } while(x_razlaganje>0);
        niz[i]=suma;
    }
    return;
}

int izbaci(int *niz, int vel)
{
    int i, j, fib1=1, fib2=1, fib_sl, k;
    for(i=0; i<vel; i++) {
        fib1=1;
        fib2=1;
        for(j=0; j<abs(niz[i]); j++) {                                                  //Petlja za fibonacijev niz
            fib_sl=fib1+fib2;
            fib1=fib2;
            fib2=fib_sl;
            if((niz[i])==fib1 || (niz[i])==fib2 || (niz[i])==fib_sl || niz[i]==0) {     //Izbacivanje clanova niza koji su fibonacijevi
                for(k=i; k<vel-1; k++)
                    niz[k]=niz[k+1];
                vel--;
                i--;
                break;
            }
        }
    }

    return vel;
}


int main()
{
    int niz[20]= {0}, i, vel=10;
    printf("Unesite niz od 10 brojeva: ");
    for (i=0; i<10; i++)
        scanf("%d", &niz[i]);
    ubaci(niz, vel);
    vel=2*vel;
    vel=izbaci(niz, vel);

    printf("Modificirani niz glasi: ");
    for(i=0; i<vel; i++) {
        if(i<vel-1)
            printf("%d, ",niz[i]);
        else
            printf("%d.", niz[i]);
    }
    return 0;
}