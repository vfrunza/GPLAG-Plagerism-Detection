#include <stdio.h>

int main() {
	int a, b, c;
	int i, j, k;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d", &a);
	} while (a<=0 || a>=11);
	
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d", &b);
	} while (b<=0 || b>=11);
	
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
	} while (c<=0 || c>=11);
	
	for(i = 0; i < b; i++) 
	{
		printf("+");
		
		for(j = 0; j < c; j++)
		    printf("-");
	}
	printf("+\n");
	
	for(i = 0; i < a; i++)  
	{
	
	    for(j = 0; j < b; j++) 
	    {
		printf("|");
		
        	for(k = 0; k < c; k++)
	    	printf(" ");
	   }
	   printf("|\n");
	
  	    for(j = 0; j < b; j++)
  	    {
	  	printf("+");
		
	    	for(k = 0; k < c; k++)
	     	printf("-");
	}
    printf("+\n");
	}
    return 0;
}
