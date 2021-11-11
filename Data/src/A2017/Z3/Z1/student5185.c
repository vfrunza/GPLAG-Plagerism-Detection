#include <stdio.h>
#include <stdlib.h>

int izbaci_duple(int* niz, int vel)
{
    int i, j, k;

    for(i = 0; i < vel; i++)
    {
        for(j = i+1; j < vel; j++)
        {
            if(niz[i] == niz[j])
            {
                for(k = j; k < vel; k++)
                    niz[k] = niz[k+1];
                vel--;
                j--;
            }
        }
    }

    return vel;
}

int dva_od_tri(int* niz_1, int vel_1, int* niz_2, int vel_2, int* niz_3, int vel_3)
{
    int br_clanova = 0;
    int niz_brojaca[1000];
    int copy_niz_1[100];
    int copy_niz_2[100];
    int copy_niz_3[100];

    int i, j, k = 0;
    for(i = 0; i < vel_1; i++)
        copy_niz_1[i] = niz_1[i];

    for(i = 0; i < vel_2; i++)
        copy_niz_2[i] = niz_2[i];

    for(i = 0; i < vel_3; i++)
        copy_niz_3[i] = niz_3[i];

    vel_1 = izbaci_duple(&copy_niz_1, vel_1);
    vel_2 = izbaci_duple(&copy_niz_2, vel_2);
    vel_3 = izbaci_duple(&copy_niz_3, vel_3);

    for(i = 0; i < vel_1 + vel_2 + vel_3; i++)
    {
        niz_brojaca[i] = 0;
    }

    for(i = 0; i < vel_1; i++)
    {
        niz_brojaca[niz_1[i]]++;
    }

    for(i = 0; i < vel_2; i++)
    {
        niz_brojaca[niz_2[i]]++;
    }

    for(i = 0; i < vel_3; i++)
    {
        niz_brojaca[niz_3[i]]++;
    }

    for(i = 0; i < vel_1+vel_2+vel_3; i++)
    {
        if(niz_brojaca[i] == 2)
            br_clanova++;
    }

    return br_clanova;
}


int main()
{
    int vel_1, vel_2, vel_3, i;
    int niz_1[1000], niz_2[1000], niz_3[1000];
    int br_clanova;
    printf("Unesite broj clanova niza 1: ");
    scanf("%d", &vel_1);
    printf("Unesite broj clanova niza 2: ");
    scanf("%d", &vel_2);
    printf("Unesite broj clanova niza 3: ");
    scanf("%d", &vel_3);

    printf("Unesite clanove niza 1: ");
    for(i = 0; i < vel_1; i++)
        scanf("%d", &niz_1[i]);

    printf("Unesite clanove niza 2: ");
    for(i = 0; i < vel_2; i++)
        scanf("%d", &niz_2[i]);

    printf("Unesite clanove niza 3: ");
    for(i = 0; i < vel_3; i++)
        scanf("%d", &niz_3[i]);

    br_clanova = dva_od_tri(&niz_1, vel_1, &niz_2, vel_2, &niz_3, vel_3);

    printf("Broj vracenih clanova je: %d", br_clanova);

    return 0;
}
1