#include <stdio.h>

int main() {
	
	int n, i, j;
	
	printf("Unesite N: ");
	do{
	    scanf("%d", &n);
	    
	 }while(n>=8 && ((n%4)==0));
	 
	 
	 for(i=0; i<(n/2); i++){
	                                   /*koristit ascii tabelu */
	         if(i==0)
	         printf("\");
	         else if(i==(n/2)-1)
	         printf("/");
	         else 
	         printf(" ");
	         
	         
	     
	     
	     
	 }
	 
	 
	 
	
	
	
	return 0;
}
