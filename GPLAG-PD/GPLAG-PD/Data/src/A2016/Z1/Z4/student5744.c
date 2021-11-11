#include <stdio.h>

int main ()
{
    int i,j,n;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    while (n>50 || n<1)
    {
        printf("Pogresan unos\n");
        printf("Unesite broj n: ");
        scanf("%d",&n);
    }
        printf("*");
        for(i=1;i<=(2*n-3);i++)
        {
            printf(" ");
        }
         printf("*");
        for(i=1;i<=(2*n-3);i++)
        {
            printf(" ");
        } 
        printf("*\n");
        if (n>1)
        {
            for(i=1;i<=n-2;i++)
            {
                for(j=1;j<=i;j++)
                {
                    printf(" ");
                }
                printf("*");
                for(j=1;j<=2*n-3-2*i;j++)
                {
                    printf(" ");
                }
                printf("*");
                for(j=1;j<=(2*i)-1;j++)
                {
                    printf(" ");
                }
                printf("*");
                for(j=1;j<=2*n-3-2*i;j++)
                {
                    printf(" ");
                }
                printf("*\n");
            }
            for(i=1;i<=n-1;i++)
            {
                printf(" ");
            }
            printf("*");
            for(i=1;i<=(2*n-3);i++)
            {
                printf(" ");
            } printf("*\n");
        }
    
    return 0;
}