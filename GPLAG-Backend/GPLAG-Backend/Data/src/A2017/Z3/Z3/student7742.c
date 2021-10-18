#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void izbaci_cifre(int niz1[], int niz2[], int velicinaNiza1, int velicinaNiza2)
{
    int i,j;

    for (i=0; i<velicinaNiza1; i++) {
        int noviBroj=0;
        for(j=0; j<velicinaNiza2; j++) {
            int kopija=niz1[i];
            int brojac=0;
            noviBroj=0;
            int cifraZaIzbaciti=niz2[j];
            do {
                int cifra=kopija%10;
                if(cifraZaIzbaciti!=cifra) {
                    noviBroj+=cifra*pow(10,brojac);
                    brojac++;
                }
                kopija/=10;
            } while(kopija>0);
            niz1[i]=noviBroj;
        }
        niz1[j]=noviBroj;
    }
}

int main()
{

    return 0;
}
