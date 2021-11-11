#include <stdio.h>

int izbaci_cifre(int niz1[], int n, int niz2[], int m)
{
    int p=0, t=1, R,i,j;
    for (j=0; j<m; j++) {
        for (i=0; i<n; i++) {
            while (niz1[n]>0) {
                R=niz1[n]%10;
                niz1[n]=niz1[n]/10;
                if(niz2[m]==R) continue;
                p=p+R*t;
                t=t*10;
            }
        }
    }
    if (niz2[m]>9 || niz2[m]<0)
        return 0;
    else
        return 1;
}

int main(void)
{
    int brojevi[100];
    int cif[100];
    int b,t,s;
    do {
        scanf("%d ", &brojevi[100]);
    } while (brojevi[100] != -1);
    s = sizeof(brojevi);
    do {
        scanf("%d ", &cif[100]);
    } while(cif[100]!=-1);
    t = sizeof(cif);
    printf ("%d " , izbaci_cifre(brojevi, s, cif, t));
    for (b=0; b<s; b++)
        printf("%d ", brojevi[b]);

    return 0;
}
