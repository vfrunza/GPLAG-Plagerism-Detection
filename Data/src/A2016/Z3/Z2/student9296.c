#include <stdio.h>

int fibonacci(int broj)
{
    int prvi=0, drugi=1, neki=0;

    if(broj<=0) return 0;                        //e hajd sad par komentara :) yaay

    neki=prvi+drugi;

    while(neki<=broj) {
        if(broj==neki || broj==prvi || broj==drugi) return 1;

        prvi=drugi;
        drugi=neki;
        neki=prvi+drugi;
    }
    return 0;
}

void ubaci(int* niz, int duzina)
{
    int i, suma=0, cifra=0, temp=0, pomocni[100]= {0};

    for(i=0; i<duzina; i++) {
        pomocni[i]=niz[i];              //strpamo originalni niz u neki pomocni da nam bude lakse
    }

    for(i=duzina-1; i>=0; i--) {
        niz[2*i]=pomocni[i];
    }

    for(i=0; i<duzina; i++) {
        temp=niz[2*i];
        suma=0;

        if(temp<0) temp=temp*(-1);          //necemo negativnu sumu :D We like positivity

        while(temp!=0) {
            cifra=temp%10;
            suma+=cifra;
            temp=temp/10;
        }

        niz[2*i+1]=suma;
    }
}

int izbaci(int* niz, int duzina)
{
    int i, j;

    for(i=0; i<duzina; i++) {
        if(fibonacci(niz[i])) {
            for(j=i; j<duzina-1; j++) {
                //e ovo me napatilo ko niko, al' sam makar razumjela algoritam
                niz[j]=niz[j+1];
            }
            i--;
            duzina--;
        }
    }

    return duzina;
}

int main()
{

    int niz[20], i, mod_vel=0;

    printf("Unesite niz od 10 brojeva: ");

    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }

    ubaci(niz, 10);
    mod_vel=izbaci(niz, 20);

    printf("Modificirani niz glasi: ");
    for(i=0; i<mod_vel; i++) {
        if(i!=mod_vel-1) printf("%d, ", niz[i]);
        else {
            printf("%d.", niz[i]);
        }
    }
    return 0;
}
