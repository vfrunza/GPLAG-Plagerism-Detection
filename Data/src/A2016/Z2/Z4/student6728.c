#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.0000000000001

int main() {
    int m,n,i,j;
    double nizB[100][100];
    
    do{
        printf("Unesite M i N: ");
        
        scanf("%d %d", &m, &n);
        if(m > 100 || m < 1 || n < 1 || n > 100)
        printf("Pogresan unos!\n");
        
    }
    while(m < 1 || m > 100 || n < 1 || n > 100);
    printf("Unesite elemente matrice: ");
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%lf",&nizB[i][j]);
        }
    }
           if(m == 1)
            {
                printf("Matrica je cirkularna");
                return 0;
            }
    
     for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            
            if(n == 1)
            {
                if(fabs(nizB[i+1][0] - nizB[i][0]) < eps) 
                {
                    printf("Matrica je cirkularna");
                    return 0;
                }
                
                else 
                {
                    printf("Matrica je Teplicova");
                    return 0;
                 }
            }
            
            
            
             if((fabs(nizB[i+1][0] - nizB[i][n-1]) < eps)  && (fabs(nizB[i][j] - nizB[i+1][j+1]) < eps))
            {
                printf("Matrica je cirkularna");
                return 0;
            }
                
            else if(fabs(nizB[i][j] - nizB[i+1][j+1]) < eps)
            {
                printf("Matrica je Teplicova");
                return 0;
            }
            else 
            {
                printf("Matrica nije ni cirkularna ni Teplicova");
                return 0;
            }
         }
    }
    return 0;
}