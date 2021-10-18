#include <stdio.h>
void ubaci (int niz[], int vel)
{
    int i, Broj=0, j;
    for (i=0; i<vel; i++) {
        if (niz[i]<0) {
            niz[i]*=-1;
        }
        Broj=0;
        while (niz[i]>0) {
            Broj+=niz[i]%10;
            niz[i]/=10;
        }
        i++;
        for (j=vel; j>=i; j--) {
            niz[j]=niz[j-1];
        }
        niz[i]=Broj;
        vel++;
    }
}
int izbaci (int niz[], int vel) 
{
    
}


int main() {
    int niz[20], i, vel, j;
    printf ("Unesite niz od 10 brojeva: ");
    for (i=0; i<10; i++) {
        scanf ("%d", &niz[i]);
    }
    ubaci(niz, 10);
    vel=izbaci(niz, 10*2);
    printf ("Modificirani niz glasi: ");
    for (j=i; j<vel; j++) {
        if (i<vel) {
            printf ("%d, ", niz[j]);
        }
        else if (i==vel) {
            printf ("%d.", niz[j]);
        }
    }
    
	return 0;
}
