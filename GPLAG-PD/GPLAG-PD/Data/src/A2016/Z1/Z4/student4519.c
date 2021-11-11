#include <stdio.h>

int main() {
	int n,i,j;
	
	printf("Unesite broj n: ");
	   scanf("%d",&n);
	   
	while(n<1 || n>50){
	   printf("Pogresan unos");
	   printf("\nUnesite broj n: ");
	   scanf("%d",&n);
	} 
	
    if(n>1){
        for(i=n; i>1; i--){
        	for(j=1; j<=(n-i); j++)              /*prazno mjesto sa lijeve strane*/  
    	    printf(" ");
    	    printf("*");   	                     /*prva d*/                          
    	
    	
    	    for(j=1; j<=((2*i)-3); j++)          /*prazno mjesto prije prve dijagonale*/
    	       printf(" "); 
    	
    	    printf("*");	                    /*druga d*/
    	
            if(i!=n){                          	/*je li prvi red?*/   
               for(j=1; j<=(2*(n-i))-1; j++) 
                  printf(" ");                
    	          printf("*");
            }
    	    for(j=1; j<=((2*i)-3); j++)          /*prazno mjesto prije druge dijagonale*/
    	       printf(" ");
    	
            printf("*\n");                      /*zadnja d*/         
        }
                                                /* zadnji red */
        for(j=1; j<=(n-i); j++) printf(" ");    /*prazno mjesto sa lijeve strane*/    
    	    printf("*");                        /*prva zvjezdica*/                          
    	
        for(j=1; j<=((2*n)-3); j++)             /*prazno mjesto ispred 2. zvjezdice*/
    	    printf(" ");                  
    	
        printf("*");                            /*druga zvjezdica*/ 
    } else printf("***");                                        
    
	return 0;
}