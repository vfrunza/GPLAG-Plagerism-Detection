#include <stdio.h>
#include <math.h>
#define EPS 0.0001
int main () {

    double niz[1000]; 
    double srvr=0, a;
    int n, i, j, m, p; 
    int brojac[10]= {0};

    do {
        printf("Unesite broj clanova niza: ");
        scanf("%d", &n);
    } while (n<=0 || n>100);

    printf("Unesite niz: ");

    for (i=0; i<n; i++) {
        scanf("%lf", &a);
        niz[i]=a;
    }
    
    for (i=0; i<n-1; i++) {

        if (fabs(niz[i+1]-(2*niz[i]))<EPS) {
            srvr=(niz[i]+niz[i+1])/2;
            m=++n;
            p=i;
        
            for(j=(m-2); j>p; j--) {
              niz[j+1]=niz[j];
            }
            niz[p+1]=srvr;
            i++;
            if(i==n-1) break;
        }

    }
    printf("Nakon ubacivanja niz glasi:\n");

    for (i=0; i<n; i++) {
        printf("%g ", niz[i]);
    }

    for (i=0; i<n; i++) {
        for (j=0; j<10; j++) {
            if (((int)(niz[i]*10))%10==j) {
                brojac[j]++;
            }
        }
    }
    for (j=0; j<10; j++) {
        if (brojac[j]!=0) {
            printf("\nCifra %d se ponavlja %d puta.", j, brojac[j]);
        }
    }
    return 0;
}

/*Potrebno je napraviti sljedeći program: Korisnik najprije unosi niz realnih brojeva (najviše 100)
na način da se prvo unese broj članova niza, a zatim članovi. U ovom nizu treba pronaći parove susjednih
članova takvih da je desni član dvostruko veći od lijevog člana (koristiti ε=0.0001). Između svaka dva takva
člana treba ubaciti broj koji predstavlja srednju vrijednost ta dva člana. Ovako kreiran niz treba ispisati na ekran.

U nastavku programa treba iz svakog člana niza izdvojiti prvu cifru nakon decimalnog zareza, te prebrojati
koliko puta se ponavlja svaka takva cifra.

Primjer ulaza i izlaza:
Unesite broj clanova niza: 5
Unesite niz: 1 2 3 4 5
Nakon ubacivanja niz glasi:
1 1.5 2 3 4 5
Cifra 0 se ponavlja 5 puta.
Cifra 5 se ponavlja 1 puta.
*/
