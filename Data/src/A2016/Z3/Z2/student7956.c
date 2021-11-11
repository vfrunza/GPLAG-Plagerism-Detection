#include <stdio.h>

int fibonacci(int broj)
{
    int prv=0, dr=1, poneki=0;

    if(broj<=0) return 0;                        

    poneki=prv+dr;

    while(poneki<=broj) {
        if(broj==poneki || broj==prv || broj==dr) return 1;

        prv=dr;
        dr=poneki;
        poneki=prv+dr;
    }
    return 0;
}

void ubaci(int* niz, int duzina)
{
    int i, sum=0, cifra=0, temp=0, pomocni[100]= {0};

    for(i=0; i<duzina; i++) {
        pomocni[i]=niz[i];             
    }

    for(i=duzina-1; i>=0; i--) {
        niz[2*i]=pomocni[i];
    }

    for(i=0; i<duzina; i++) {
        temp=niz[2*i];
        sum=0;

        if(temp<0) temp=temp*(-1);          

        while(temp!=0) {
            cifra=temp%10;
            sum+=cifra;
            temp=temp/10;
        }

        niz[2*i+1]=sum;
    }
}

int izbaci(int* niz, int duzina)
{
    int i, j;

    for(i=0; i<duzina; i++) {
        if(fibonacci(niz[i])) {
            for(j=i; j<duzina-1; j++) {
                
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

    int niz[20], i, velicina_mod=0;

    printf("Unesite niz od 10 brojeva: ");

    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }

    ubaci(niz, 10);
    velicina_mod=izbaci(niz, 20);

    printf("Modificirani niz glasi: ");
    for(i=0; i<velicina_mod; i++) {
        if(i!=velicina_mod-1) printf("%d, ", niz[i]);
        else {
            printf("%d.", niz[i]);
        }
    }
    return 0;
}