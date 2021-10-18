#include <stdio.h>
#define br_el 100

int main()
{

    int NIZ[br_el],i,j,N,brojac[br_el],NIZ2[br_el];

    do {
        printf("Unesite velicinu niza: ");
        scanf("%d", N);
    } while(N<0 || N>=br_el);


    do {
        for(i=0; i<=N; i++) {
            printf("Unesite clanove niza: ");
            scanf("%d", NIZ[i]);
        }
        
    } while(niz[i]<0 || N>br_el);
    
    for(i=0;i<br_el;i++) {
        brojac[i]=0;
    }
    
    for(i=0;i<br_el;i++) {
        brojac(niz[i])++;
    }
    
    for(i=0;i<br_el;i++) {
        NIZ2[i]=i;
    }
    //ispis niza
    for(i=0;i<=N;i++) {
        printf("Finalni niz glasi: ", NIZ[i],NIZ2[i]):
    }
    
    return 0;
}

/* PREBROJAVANJE CLANOVA NIZA
#include <stdio.h>
int main() {
int niz[100], brojaci[101]={0};
int i, n, max, maxi, min, mini;
printf("Unesite clanove niza (-1 za kraj)\n");
for (i=0; i<100; i++) {
scanf("%d", &niz[i]);
if (niz[i]==-1) break;
if (niz[i]<0 || niz[i]>100) {
printf("Broj nije na intervalu [0,100]. Ponovite
unos");
i--;
}
}
n=i;
for (i=0; i<n; i++) {
for (j=0; j<=100; j++) {
if (niz[i] == j) brojaci[j]++;
}
}