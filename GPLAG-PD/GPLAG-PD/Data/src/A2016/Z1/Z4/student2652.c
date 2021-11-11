#include <stdio.h>
int main ()
{
    int n,i,j,x;
    do  
        {
            printf ("Unesite broj n: ");
            scanf ("%d",&n);
        if (n<=0 || n > 50) {printf ("Pogresan unos\n");}
        }
    while (n<=0 || n > 50);
x = 4*(n-2) + 5;
if (n==1){printf("***"); return 0;}
for (i=0; i<=n; i = i +1)
{
    if (i==0) 
    {
        printf("*");
        for (j = 0; j < (x-3)/2; j++ )
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j < (x-3)/2; j++ )
        {
            printf(" ");
        }
        printf("*");
    }
    if (i == n-1)
    {
        for (j = 0; j < n-1; j = j+1)
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j < (x-3)/2; j = j+1)
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j < n; j = j+1)
        {
            printf(" ");
        }
        return 0;
    }
    if (i != 0)
    {
        for (j = 0; j<i; j++)
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j<(x-3)/2-2*i; j++ )
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j<(x-3)/2-2*(n-1-i); j++ )
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j<(x-3)/2-2*i; j++)
        {
            printf(" ");
        }
        printf("*");
        for (j = 0; j<i; j++)
        {
            printf(" ");
        }
    }
    printf("\n");
}
return 0;
}