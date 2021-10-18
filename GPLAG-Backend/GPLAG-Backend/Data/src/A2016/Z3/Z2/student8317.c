#include<stdio.h>
#include<stdlib.h>

int izbaci (int* niz, int duzina){
    int i, fib, fib1, fib0, j;

    for (i=0; i<duzina; i++) {
        
        /*provjera da li je broj Fibonaccijev*/

        fib=1;
        fib1=1;
        fib0=1;
        while (fib<niz[i]) { 
            fib=fib1+fib0;
            fib0=fib1;
            fib1=fib;
        }
        /*izbacivanje Fibonaccijevih brojeva*/
        if (fib==niz[i]) {
            for (j=i; j<duzina-1; j++) {
                niz[j]=niz[j+1];
            }
            duzina--;
            i--;
        }

    }

    return duzina;
}

void ubaci (int* niz, int duzina){

    int i, duzina2=(2*duzina)-2, sum, temp;

    /*ubacivanje praznog mjesta između članova*/
    for (i=duzina-1; i>=0; i--) {

        niz[duzina2]=niz[i];
        duzina2=duzina2-2;
    }

        /*Ubacivanje sume cifara na prazna mjesta*/    
        for (i=0; i<2*duzina; i=i+2) {
        sum=0;
        temp=abs(niz[i]);
        do {
            sum=sum+temp%10;
            temp/=10;
        } while (temp>0);

        niz[i+1]=sum;
    }

}

int main (){

    int i,duzina;
    int niz[20];

    printf("Unesite niz od 10 brojeva: ");

    for (i=0; i<10; i++) {
        scanf ("%d", &niz[i]);
    }

    /*poziv funckije ubaci*/
    ubaci(niz,10);

    /*poziv funkcije izbaci*/
    duzina=izbaci(niz, 20);


    /*ispis modificiranog niza*/
    printf ("Modificirani niz glasi: ");
    if (duzina==0) {
        return 0;
    } else {
        printf ("%d", niz[0]);
        for (i=1; i<duzina; i++) {
            printf (", %d", niz[i]);
        }
        printf (".");
    }

    return 0;
}