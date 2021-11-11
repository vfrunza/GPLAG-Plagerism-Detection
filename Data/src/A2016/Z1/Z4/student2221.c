#include <stdio.h>

int main ()
{
    int i,j,n=0;
    for (;;)
    {
        printf ("Unesite broj n: ");
        scanf ("%d", &n);
        if (n <= 0 || n > 50)
        {
            printf ("Pogresan unos\n");
        }
        
        if (n>0 && n<50) break;
    }
    
    if (n==1)
    {
        printf ("***");
    }
    else {
        for (i=0; i<n; i++)
        {
            for (j=0; j<4*n-3; j++)
        {
            if (i==j)
            {
                printf ("*");
        }
        else if (2*(n-1)-j == i)
        {
            printf ("*");
        }
        else if (2*(n-1)+i == j)
        {
            printf ("*");
        }
        else if (4*n-4-j== i)
        {
            printf ("*");
        }
        else
        {
            printf (" ");
        }
            
        
    }
    printf ("\n");
    }
    }
    return 0;
}