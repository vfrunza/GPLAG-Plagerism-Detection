#include <stdio.h>

int main()
{
    int i,j,n;
    do {
        printf("N=");
        scanf("%d", &n);
        
        for(i=0; i<n/2; i++) {
            for(j=0; j<n/2; j++){
                if(i==j || j==n-i-1)
                printf("*");
                else
                printf(" ");
            }
            printf("\n");
            }
         for(i=0;i<=n/2;i++){
             for(j=n/2;j<n;j++){
                 if((i==0 && j==n/2) || (i==0 && j==n-1) || (i==n/2-1 && j==n/2) || (i==n/2-1 && j==n-1))
                 printf("+");
                 else if(j==n/2 || j==n-1)
                 printf("|");
                 else 
                 printf(" ");
             } 
             printf("\n");
         }   
        
        
        
        
        }while(n<8 && n%4==0);

            return 0;
        }
