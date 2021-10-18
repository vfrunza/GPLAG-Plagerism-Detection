#include <stdio.h>

int dva_od_tri( int niz1[], int n1, int niz2[], int n2, int niz3[], int n3)
{
    int i, j, k, l, dupli, nema_3, rezultat;

    rezultat = 0;
    for (i = 0; i < n1; i++)
    {
        dupli = 0;
        for (l = 0; l < i; l++)
            if (niz1[l] == niz1[i])
            {
                dupli = 1;
                break;
            }
        if (dupli == 0)
        {
            for (j = 0; j < n2; j++)
                if (niz1[i] == niz2[j])
                {
                    nema_3 = 1;
                    for (k = 0; k < n3; k++)
                        if (niz1[i] == niz3[k])
                        {
                            nema_3 = 0;
                            break;
                        }
                    
                    if (nema_3 == 1)
                        rezultat++;
                    break;
                }
        }
    }
    
    for (i = 0; i < n1; i++)
    {
        dupli = 0;
        for (l = 0; l < i; l++)
            if (niz1[l] == niz1[i])
            {
                dupli = 1;
                break;
            }
        if (dupli == 0)
        {
            for (k = 0; k < n3; k++)
                if (niz1[i] == niz3[k])
                {
                    nema_3 = 1;
                    for (j = 0; j < n2; j++)
                        if (niz1[i] == niz2[j])
                        {
                            nema_3 = 0;
                            break;
                        }
                    
                    if (nema_3 == 1)
                        rezultat++;
                    break;
                }
        }
    }
    
    for (j = 0; j < n2; j++)
    {
        dupli = 0;
        for (l = 0; l < j; l++)
            if (niz2[l] == niz2[j])
            {
                dupli = 1;
                break;
            }
        if (dupli == 0)
        {
            for (k = 0; k < n3; k++)
                if (niz2[j] == niz3[k])
                {
                    nema_3 = 1;
                    for (i = 0; i < n1; i++)
                        if (niz1[i] == niz2[j])
                        {
                            nema_3 = 0;
                            break;
                        }
                    
                    if (nema_3 == 1)
                        rezultat++;
                    break;
                }
        }
    }
    
    return rezultat;
}

int main() {
    /* AT4: Ponavljanje */
    int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int niz2[] = {3, 3, 3, 2, 2};
    int niz3[] = {1, 3, 4};
    int rez = dva_od_tri(niz1, 11, niz2, 5, niz3, 3);
    printf("%d ", rez);
    rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 3);
    printf("%d ", rez);
    rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 11);
    printf("%d ", rez);
    
    return 0;
}