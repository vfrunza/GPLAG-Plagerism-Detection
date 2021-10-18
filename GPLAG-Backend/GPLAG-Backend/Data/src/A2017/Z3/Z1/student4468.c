#include <stdio.h>

int pomocna_fja (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
    int i, j, k;
    int brojac = 0;

    for (i=0; i<vel1; i++) 
    {
        for (j=0; j<vel2; j++)
        {
            if (niz1[i] == niz2[j]) 
            {
                brojac++;
                for (k=0; k<vel3; k++)
                {
                    if (niz1[i]==niz3[k]) 
                    {
                        brojac--;
                        k=vel3;
                    }
                }
            }
        }
    }
            return brojac;
        }
  

        int dva_od_tri (int niz1 [], int vel1, int niz2 [], int vel2, int niz3[], int vel3) {
            int brojac=0;
            brojac+=pomocna_fja (niz1, vel1, niz2, vel2, niz3, vel3);
            brojac+=pomocna_fja (niz2, vel2, niz3, vel3, niz1, vel1);
            brojac+=pomocna_fja (niz1, vel1,niz3, vel3, niz2, vel2);
            return brojac;
        }

        int main () {
            int niz1 [] = {1, 2, 3, 4};
            int niz2 [] = {2, 3, 4, 5};
            int niz3 [] = {3, 4, 5, 6};
            int niz4 [1];
            int b = dva_od_tri (niz1, 4, niz2, 4, niz4, 0);
            printf ("%d", b);
            b = dva_od_tri (niz1, 4, niz4, 0, niz3, 4);
            printf ("%d", b);
            b = dva_od_tri (niz4, 0, niz2, 4, niz3, 4);
            printf ("%d", b);
            b = dva_od_tri (niz1, 4, niz2, 4, niz3, 4);
            printf ("%d", b);
            return 0;
    }