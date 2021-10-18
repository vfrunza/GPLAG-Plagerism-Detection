#include <stdio.h>

int main ()
{
    int r, x, s, i, j ,k;    /*r-broj redova, x-broj kolona, s-sirina jedne kolone*/
    do 
    {
        printf ("Unesite broj redova: ");
        scanf ("%d", &r);
    }
    while (r<=0 || r>10);
    do
    {
        printf ("Unesite broj kolona: ");
        scanf ("%d", &x);
    }
    while (x<=0 || x>10);
    do
    {
        printf ("Unesite sirinu jedne kolone: ");
        scanf ("%d", &s);
    }
    while (s<=0 || s>10);
    for (k=1; k<=r; k++)
    {
        printf ("+");
        for (i=1; i<=x; i++)
        {
            for (j=1; j<=s; j++)
                printf ("-");
            printf ("+");
        }
        printf ("\n");
        printf ("|");
        for (i=1; i<=x; i++)
        {
            for (j=1; j<=s; j++)
                printf (" ");
            printf ("|");
        }
        printf ("\n");
    }
    printf ("+");
    for (i=1; i<=x; i++)
        {
            for (j=1; j<=s; j++)
                printf ("-");
            printf ("+");
        }
    return 0;
}