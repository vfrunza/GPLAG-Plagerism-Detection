#include <stdio.h>
#include <stdlib.h>

int da_li_ima_duplih (int *niz, int DUZINA)
{
    int i=0,j=0;
    for (i=0; i<DUZINA-1; i++) {
        for (j=i+1; j<DUZINA; j++) {
            if (niz[i]==niz[j] || niz[i]>9 || niz[i]<0) {
                return 1;
            }
        }
    }
    return 0;
}

int  izbaci_cifre (int *niz1, int vel1, int *niz2, int vel2)
{
    int i=0, j=0, a=0;

    int k=1;

    int suma=0, br=0;

    if (da_li_ima_duplih(niz2, vel2))
        return 0;

    int pronasao=0;
    for (i=0; i<vel1; i++) {
        a=abs(niz1[i]);
        suma=0;
        while (a!=0) {
            br=a%10;
            pronasao=0;
            for(j=0; j<vel2; j++) {
                if (niz2[j]==br) {
                    pronasao=1;
                    br=0;
                    break;
                }
            }
            if(k==1) k=1;
            else if(pronasao)k/=10;
            suma+=k*br;
            k*=10;
            if(pronasao)k/=10;
            a/=10;
        }
        if(niz1[i]<0) suma*=-1;
        niz1[i]=suma;
    }

    return 1;

}

int main ()
{

    int brojevi[] = {1235};
    int cifre[] = {2, 3, 5};
    int i;
    izbaci_cifre(brojevi, 1, cifre, 3);
    for (i=0; i<5; i++)
        printf("%d ", brojevi[i]);
    return 0;
}
