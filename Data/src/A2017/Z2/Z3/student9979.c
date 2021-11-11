#include <stdio.h>
#define MAX 10

int main() 
{

   int N, i, kol, red;
   char ks[20][20];
   
   do {
   	     printf("Unesite broj tacaka: " );
   	     scanf("%d", &N);}
   	    
   	    while(N<1 || N>MAX);
   	    
   	    for( red=0;red<20;red++)
   	        for(kol=0;kol<20;kol++)
   	            ks[red][kol]= ' ';
   	            
   	    for(i=0;i<N;i++)
   	    { 
   	    	do{
   	    		printf ("Unesite %d. tacku: ", i+1 );
   	    		scanf("%d %d", &kol, &red);
   	    		if( red>19 || red<0 || kol>19 || kol<0 )
   	    		  printf("Pogresan unos \n" );
   	    		  
   	    		}
             while(red>19 || red<0 || kol>19 || kol<0 );
            ks[red][kol-1]='*';
   	    }
   	    
   	    for(red=0;red<20;red++)
   	    {
   	    	for(kol=0;kol<20;kol++)
   	    	 	printf ("%c", ks[red][kol]);
   	    printf("  \n ");
   	    
   	    }
	return 0;
}