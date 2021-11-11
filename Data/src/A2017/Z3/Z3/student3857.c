#include <stdio.h>
#include <math.h>

int izbaci_cifre (int niz1[], int vel1, int niz2[], int vel2)
{
    int i,j;
    int cifra,temp;
    int brojac1=0, brojac2=0, brojac3=0;


    if (vel2==0) {
        return 0;
    }

    for (i=0; i<vel2; i++) {
        if (niz2[i]<0 ||niz2[i]>9)
            return 0;
        for (j=0; j<i; j++) {
            if (niz2[j]==niz2[i])
                return 0;
        }
    }

    for (i=0; i<vel1; i++) {
        cifra = niz1[i];
        niz1[i] = fabs(niz1[i]); /* Da ne zeza minus */
        brojac1=0;
        brojac2=0;
        while (niz1[i]!=0) {
            for (j=0; j<vel2; j++) {
                if (niz1[i]%10==niz2[j]) {      /* Rastavljanje na cifre i poredjenje sa clanovima drugog niza */
                    temp = 1;
                    brojac1++;
                    break;
                } else temp=0;
            }
            if (temp==0) {
                brojac3 = (brojac3 + (niz1[i]%10)) * 10; 
            }
            niz1[i]=(int)(niz1[i]/10);          
            brojac2++;
        }
        if (brojac1 == brojac2) {
            niz1[i]=0;
        } else {
            brojac3/=10;
            niz1[i]=brojac3;
            brojac3=0;
            while (niz1[i]%10 != 0) {
                brojac3 = (brojac3 + (niz1[i]%10)) * 10;
                niz1[i]/=10;
            }
            brojac3/=10;
            if (cifra<0) {
                niz1[i]= -brojac3;
            } else {
                niz1[i]= brojac3;
            }
            brojac3=0; /*Reset */
        }
    }

    for (i=0; i<vel1; i++) {
        for (j=0; j<i; j++) {
            if (niz1[i]==niz1[j] && niz1[i]!=0) {
                return 0;
            }
        }
    }

    return 1;
}


int main()
{
    printf ("Test");

    return 0;
}