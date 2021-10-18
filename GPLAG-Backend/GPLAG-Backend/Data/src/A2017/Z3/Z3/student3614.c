#include <stdio.h>
#include <stdlib.h>
int izbaci_cifre (int niz[], int velicina1, int nizc[], int velicina2)
{
    int c, n=0, l=0, i, pom, pomc, j;
    for(i=0; i<velicina2; i++) {
        if (nizc[i]<0 || nizc[i]>9) return 0;
    }
    for (i=0; i<velicina2; i++) {
        for (j=i+1; j<velicina2; j++) {
            if (nizc[i]==nizc[j]) return 0;
        }
    }
    for (i=0; i<velicina1; i++) {
            for (j=0; j<velicina2; j++) {
                l=0;
                n=0;
                pomc=nizc[j];
                pom=abs(niz[i]);
                while (pom!=0) {
                    c=pom%10;
                    if (c==pomc) {
                        pom=pom/10;
                    } else {
                        n=n*10+c;
                        pom=pom/10;
                    }
                }
                while(n!=0) {
                    l=l*10+n%10;
                    n=n/10;
                }
                if (niz[i] < 0)
                    niz[i]=-l;
                else
                    niz[i]=l;
            }
        }
    return 1;
}

int main()
{
    int niz[]= {123456, 12789};
    int nizc[]= {1,2,3};
    printf("%d\n", izbaci_cifre(niz,2,nizc,3));
    printf("%d %d\n", niz[0], niz[1]);
    return 0;
}
