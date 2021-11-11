#include <stdio.h>
#include <stdlib.h>

int izbaci(int broj, int cifra)
{
    int c;
    int novi = 0;
    int neg = broj;
    if(broj < 0)
    {
        broj = -broj;
        while(broj > 0)
        {
            c = broj%10;
            if(c == cifra)
            {
                broj /= 10;
                continue;
            }
            else
            {
                novi = novi*10 + c;
                broj /= 10;
            }
        }
        broj = 0;
        while(novi > 0)
        {
            c = novi%10;
            broj = broj*10 + c;
            novi /= 10;
        }
        broj = -broj;
        return broj;
    }

    if(broj == 0)
        return broj;
    while(broj > 0)
    {
        c = broj%10;
        if(c == cifra)
        {
            broj /= 10;
            continue;
        }
        else
        {
            novi = novi*10 + c;
            broj /= 10;
        }
    }
    broj = 0;
    while(novi > 0)
    {
        c = novi%10;
        broj = broj*10 + c;
        novi /= 10;
    }

    return broj;
}

int izbaci_cifre(int* niz_1, int vel_1, int* niz_2, int vel_2)
{
    int i, j;
    for(i = 0; i < vel_2; i++)
    {
        if(niz_2[i] < 0 || niz_2[i] > 9)
            return 0;
        for(j = i+1; j < vel_2; j++)
        {
            if(niz_2[i] == niz_2[j])
                return 0;
        }
    }

    for(i = 0; i < vel_1; i++)
    {
        for(j = 0; j < vel_2; j++)
        {
            niz_1[i] = izbaci(niz_1[i], niz_2[j]);
        }
    }

    return 1;
}

int main()
{
    int brojevi[] = {123, 456};
    int cifre[] = {1,2,3,1};
    int i;
    int c = izbaci_cifre(brojevi, 2, cifre, 4);

    return 0;
}
