#include <stdio.h>
int suma (int x) {
    int i, s=0, br=0, a, b;
      if (x<0)
        x=-1*x;
    b=x;
    /* Racunanje broja cifara unesenog clana niza */
    while (x>0) {
        x=x/10;
        br++;
    }
    /* Racunanje sume cifara unesenog clana niza */
    for (i=0; i<br; i++) {
        a=b%10;
        b=(b-a)/10;
        s=(s+a);
    }
    return s;
}
void ubaci (int niz[], int n) {
    int i, j;
    for (j=0; j<2*n; j+=2) {
        for (i=2*n-2; i>=j; i--) {
            niz[i+1]=niz[i];
        }
            niz[j+1]=suma(niz[j]);
    }
}

int izbaci (int niz[], int n) {
    int i, j, Fib[46], k;
    /* Izbacivanje brojeva koji su clanovi Fibonaccijevog niza */
    Fib[0]=1;
    Fib[1]=1;
    for (j=2; j<46; j++) {
        Fib[j]=Fib[j-2]+Fib[j-1]; 
            for (i=0; i<n; i++) {
                if (niz[i]==Fib[j] || niz[i]==Fib[0] ) {
                    for (k=i; k<n-1;k++) {
                        niz[k]=niz[k+1];
                    }
                n--;
                i--;
                }
           }
    }
        return n;
}
int main () {
    int niz[20], i, n;
    printf ("Unesite niz od 10 brojeva: ");
        for (i=0; i<10; i++) {
             scanf ("%d", &niz[i]);
        }
    for (i=10; i<20; i++)
        niz[i]=0;
    ubaci (niz, 10);
    n=izbaci (niz, 20);
    printf ("Modificirani niz glasi: ");
    for (i=0; i<n-1; i++)
        printf ("%d, ", niz[i]);
    printf ("%d.", niz[n-1]);
    return 0;
}
