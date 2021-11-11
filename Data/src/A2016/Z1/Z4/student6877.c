#include <stdio.h>
#define C 3
int main() {
	int i, j, n, k, l, m;
   	
   do
   {
    printf("\nUnesite broj n: ");
    scanf("%d",&n);
    if (n<1||n>50) printf("Pogresan unos ");
   }	
   while (n<1||n>50);
	for (i=0;i<n;i++)
	    {
	     if (n==1) printf("*");
	    	for(j=0;j<n;j++)
	    	     {
	    	     
	    	     if(j==i) printf("*");
	    	     else printf(" ");
	    	     }
	    	     	
	    	for(k=0;k<n-2;k++)
	    	     {
	    	     	if(i+k==n-2) printf("*");
	    	     	else printf(" ");
	    	     	
	    	     }
	    	for(l=0;l<n;l++)
	    	     {
	    	     	if(i==l) printf("*");
	    	     	else printf(" ");
	    	     }
	    	for(m=0;m<n;m++)
	    	     {
	    	     	if(i+m==n-2) printf("*");
	    	     	else printf(" ");
	    	     }
	    	
	    	
	    	
	    	
	    	
	    printf("\n");	
	    }
	return 0;
}
