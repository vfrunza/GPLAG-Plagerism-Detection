#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int nizA[20][20] = {0}, i,j,n,k=0,a,b;
    
    while(1)
    {
        printf("Unesite broj tacaka: ");
        
        scanf("%d", &n);
        
        if(n >0 && n <= 10) break;
        
        else printf("Pogresan unos\n");
        
    }
    
    while(k < n)
    {
        printf("Unesite %d. tacku: ", k+1);
        scanf("%d %d", &a, &b);
        
        if(a > 19 || a < 0 || b > 19 || b < 0)
        {
            printf("Pogresan unos\n");
            k--;
        }
        
        for(i = 0; i < 20; i++)
        {
            for(j = 0; j < 20; j++)
            {
                if(a == j && b == i) nizA[i][j] = 1;
            }
        }
        k++;
        i = 0;
        j = 0;
    }
    
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(nizA[i][j] == 1) printf("*");
            
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
   