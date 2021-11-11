#include <stdio.h>
int main()
{
    int j, i, n;
    
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n < 1 || n > 50){
    printf("Pogresan unos\n");
    printf("Unesite broj n: ");
    scanf("%d", &n);
    }
    
    else{
    for(i=n; i==n ; i++){
    
     
        for(j=i; j<n; j++)
        {
            printf(" ");
        }
    
        
        for(j=1; j<=(4*i-1); j++)
        {
            if(j==1 || j==(2*i-1) || j==(4*i-3))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
          
        }	
    	 
    	  printf("\n");
    }
     for(i=n-1; i>=1 ; i--){
    	 for(j=i; j<n; j++)
        {
            printf(" ");
        }
      
     
        for(j=1; j<=(2*i-1); j++)
        {
            if(j==1 || j==(2*i-1) )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
          
        }
        
        for(j=i; j<n; j++)
        {
            	if (j==n-1){ printf(" ");}
        	else{
        		printf(" ");
        		printf(" ");
        	}
        }
      
       
        for(j=1; j<=(2*i-1); j++)
        {
            if(j==1 || j==(2*i-1) )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
          
        }
        
    	 	
    	
     printf("\n");
    	}
     
    }
    return 0; 
}