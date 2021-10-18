#include <stdio.h>

int main() {
    int n, i, j;
    
    do
    {
        printf("Unesite broj n: ");
        scanf("%d", &n);
        
        if(n<1 || n>50)
        printf("Pogresan unos\n");
    }while(n<1 || n>50);
    
    int brr, br, bu;
    brr=0;
    br=2*n-3;
    bu=1;
    
    
    for(i=1; i<=n; i++)
    {
        
        if(i==1)
        {
            printf("*");
            for(j=1; j<=br; j++)
                printf(" ");
            printf("*");
            for(j=1; j<=br; j++)
                printf(" ");
            printf("*");
            
            
            printf("\n");
            br=br-2;
        }
        
        else if(i==n)
        {
            for(j=1; j<=brr+1; j++)
                printf(" ");
            printf("*");
            for(j=1; j<=bu; j++)
                printf(" ");
            printf("*");
            
        }
        
        else
        {
            for(j=1; j<=brr+1; j++)
                printf(" ");
            printf("*");
            for(j=1; j<=br; j++)
            printf(" ");
            printf("*");
            for(j=1; j<=bu; j++)
                printf(" ");
            printf("*");
             for(j=1; j<=br; j++)
                printf(" ");
            printf("*");
            
            
            
            
            printf("\n");
            
           
            brr++;
            br=br-2;
            bu=bu+2;
            
            
        }
        
        
        
        
    }
    
   
    
	
	return 0;
}
