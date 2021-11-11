#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n, i, j; 
    printf("Unesite broj n: ");
    scanf("%d", &n);
     while ((n>50)||(n<=0))
    {
        printf("Pogresan unos\n");    
        printf("Unesite broj n: ");
        scanf("%d", &n);
    }
    for(i=0; i<n; i++) 
    {
        for(j=0; j<4*n-3; j++)
        {
            
            if ((i==j) || (j == 2*n-i-2) || (j == i+2*n-2) || (j == 4*n-i-4))
            {printf("*");}
            else 
            {printf(" ");}
            if (n==1) printf("**");
        }
        printf("\n");
    }
    

    return 0;
}